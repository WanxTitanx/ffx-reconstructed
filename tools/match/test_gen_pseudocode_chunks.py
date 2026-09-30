import importlib.util
import subprocess
import sys
from pathlib import Path
from unittest import TestCase
from unittest.mock import patch


SCRIPT = Path(__file__).with_name("gen_pseudocode_chunks.py")
SPEC = importlib.util.spec_from_file_location("gen_pseudocode_chunks_under_test", SCRIPT)
MODULE = importlib.util.module_from_spec(SPEC)
with patch.object(sys, "argv", [str(SCRIPT)]):
    SPEC.loader.exec_module(MODULE)
import definitive_match as MATCH


class FunctionCallingConventionTests(TestCase):
    def test_rel32_resolver_reconstructs_exact_call_bytes(self):
        resolver = getattr(MATCH, "resolve_rel32_relocations", None)
        self.assertIsNotNone(resolver)
        if resolver is None:
            return

        code = bytes.fromhex("e800000000c3")
        resolved = resolver(
            code,
            0x00401000,
            [(1, "REL32", "@Target@4")],
            {"Target": 0x00402000},
        )

        self.assertEqual(resolved, bytes.fromhex("e8fb0f0000c3"))

    def test_dumpbin_relocation_parser_uses_only_text_section(self):
        parser = getattr(MATCH, "parse_dumpbin_relocations", None)
        self.assertIsNotNone(parser)
        if parser is None:
            return

        dump = """RELOCATIONS #3
00000007 REL32 00000000 8 @Target@4
RELOCATIONS #4
00000000 DIR32NB 00000000 C @Caller@4
"""
        self.assertEqual(
            parser(dump),
            [(7, "REL32", "@Target@4")],
        )

    def test_generator_import_does_not_parse_wrapper_arguments(self):
        probe = (
            "import sys; "
            "sys.argv = ['emit_real_units.py', '/tmp/units', '/tmp/conventions.json']; "
            "import gen_pseudocode_chunks"
        )
        result = subprocess.run(
            [sys.executable, "-c", probe],
            cwd=SCRIPT.parent,
            capture_output=True,
            text=True,
        )

        self.assertEqual(result.returncode, 0, result.stderr)

    def test_transform_rewrites_existing_single_argument_thiscall_headers(self):
        source = """extern _DWORD SingleThiscall();
extern int MultiThiscall();
extern _DWORD PlainCdecl();
// Function: Caller
void Caller(void *self, int mode)
{
  SingleThiscall(self);
  MultiThiscall(self, mode);
  PlainCdecl(self);
}
"""
        conventions = {
            "SingleThiscall": "__thiscall",
            "MultiThiscall": "__thiscall",
            "PlainCdecl": "__cdecl",
        }
        with patch.object(MODULE, "FUNCTION_CONVENTIONS", conventions):
            transformed = MODULE.transform(source)

        self.assertIn(
            "extern _DWORD __fastcall SingleThiscall(void *);",
            transformed,
        )
        self.assertNotIn("extern _DWORD SingleThiscall();", transformed)
        self.assertIn("extern int MultiThiscall();", transformed)
        self.assertIn("extern _DWORD PlainCdecl();", transformed)

    def test_single_argument_thiscall_callees_use_ecx_declarations(self):
        source = """// Function: Caller
void Caller(_DWORD *self)
{
  FFEscMenu_SetupConfigPages(self);
  FFX_Save_RebuildSlotList_6FF100(self);
}
"""
        conventions = {
            "FFEscMenu_SetupConfigPages": "__thiscall",
            "FFX_Save_RebuildSlotList_6FF100": "__thiscall",
        }

        with patch.object(MODULE, "FUNCTION_CONVENTIONS", conventions, create=True):
            transformed = MODULE.transform(source)

        self.assertIn(
            "extern _DWORD __fastcall FFEscMenu_SetupConfigPages(void *);",
            transformed,
        )
        self.assertIn(
            "extern int __fastcall FFX_Save_RebuildSlotList_6FF100(void *);",
            transformed,
        )

    def test_multi_argument_thiscall_keeps_existing_fallback(self):
        source = """// Function: Caller
void Caller(_DWORD *self, int mode)
{
  FFX_Target_123456(self, mode);
}
"""
        with patch.object(
            MODULE,
            "FUNCTION_CONVENTIONS",
            {"FFX_Target_123456": "__thiscall"},
            create=True,
        ):
            transformed = MODULE.transform(source)

        self.assertIn("extern int FFX_Target_123456();", transformed)
