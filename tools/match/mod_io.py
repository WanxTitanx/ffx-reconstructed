"""Output files must be owned regular files, never aliases of input artifacts."""
import os
from pathlib import Path
import stat


def validate_directory(path):
    path = Path(path).absolute()
    for part in (path, *path.parents):
        if part.is_symlink():
            raise ValueError('output path contains a symlink: ' + str(part))
    if path.exists():
        if not path.is_dir():
            raise ValueError('output is not a directory')
        for item in path.rglob('*'):
            details = item.lstat()
            if stat.S_ISLNK(details.st_mode):
                raise ValueError('output tree contains a symlink: ' + str(item))
            if stat.S_ISREG(details.st_mode):
                if details.st_nlink != 1:
                    raise ValueError('output file has external hardlinks: ' + str(item))
            elif not stat.S_ISDIR(details.st_mode):
                raise ValueError('output tree contains a nonregular file: ' + str(item))
    return path.resolve()


def _parent_descriptor(path):
    path = Path(path).absolute()
    descriptor = os.open('/', os.O_RDONLY | os.O_DIRECTORY | os.O_CLOEXEC)
    try:
        for part in path.parent.parts[1:]:
            next_descriptor = os.open(part, os.O_RDONLY | os.O_DIRECTORY | os.O_NOFOLLOW | os.O_CLOEXEC,
                                      dir_fd=descriptor)
            os.close(descriptor)
            descriptor = next_descriptor
        return descriptor
    except BaseException:
        os.close(descriptor)
        raise


def write(path, data):
    """Open every parent without following symlinks; inspect before truncating."""
    path = Path(path)
    if isinstance(data, str):
        data = data.encode('utf-8')
    parent = _parent_descriptor(path)
    descriptor = None
    try:
        descriptor = os.open(path.name, os.O_WRONLY | os.O_CREAT | os.O_NOFOLLOW | os.O_CLOEXEC,
                             0o644, dir_fd=parent)
        details = os.fstat(descriptor)
        if not stat.S_ISREG(details.st_mode) or details.st_nlink != 1:
            raise ValueError('refusing to overwrite an aliased or nonregular output')
        os.ftruncate(descriptor, 0)
        view = memoryview(data)
        while view:
            count = os.write(descriptor, view)
            if count <= 0:
                raise OSError('output write made no progress')
            view = view[count:]
    finally:
        if descriptor is not None:
            os.close(descriptor)
        os.close(parent)


def _owned_entry(parent, name, *, missing_ok=False):
    try:
        details = os.stat(name, dir_fd=parent, follow_symlinks=False)
    except FileNotFoundError:
        if missing_ok:
            return False
        raise
    if not stat.S_ISREG(details.st_mode) or details.st_nlink != 1:
        raise ValueError('refusing to change an aliased or nonregular output entry')
    return True


def unlink(path, *, missing_ok=False):
    """Invalidate a receipt relative to its opened parent, never a new pathname."""
    path = Path(path)
    parent = _parent_descriptor(path)
    try:
        if _owned_entry(parent, path.name, missing_ok=missing_ok):
            try:
                os.unlink(path.name, dir_fd=parent)
            except FileNotFoundError:
                if not missing_ok:
                    raise
    finally:
        os.close(parent)


def replace(source, destination):
    """Publish within one held directory descriptor without resolving parents again."""
    source, destination = Path(source).absolute(), Path(destination).absolute()
    if source.parent != destination.parent:
        raise ValueError('publication must stay within the same output directory')
    parent = _parent_descriptor(source)
    try:
        _owned_entry(parent, source.name)
        _owned_entry(parent, destination.name, missing_ok=True)
        os.replace(source.name, destination.name, src_dir_fd=parent, dst_dir_fd=parent)
    finally:
        os.close(parent)
