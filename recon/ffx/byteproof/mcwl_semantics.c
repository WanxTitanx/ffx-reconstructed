/* Freestanding Linux i386 test of the Windows cdecl instruction body. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct { u32 key, length; const u8 *data; } Record;
extern int Phyre_MemCmp_WithLength(const Record *, const Record *);
static u32 checks;
static u32 seed = 0x41719u;
static u8 left_bytes[72], right_bytes[72];

static u32 random_u32(void) {
    seed = seed * 1664525u + 1013904223u;
    return seed;
}

static int expected(const Record *a, const Record *b) {
    u32 i;
    if (a->key != b->key) return a->key > b->key ? 1 : -1;
    if (a->length != b->length) return a->length > b->length ? 1 : -1;
    for (i = 0; i < a->length; ++i)
        if (b->data[i] != a->data[i]) return b->data[i] > a->data[i] ? 1 : -1;
    return 0;
}

static int check(Record a, Record b) {
    ++checks;
    return Phyre_MemCmp_WithLength(&a, &b) == expected(&a, &b);
}

static int run_tests(void) {
    const u32 keys[] = {0, 1, 0x7fffffff, 0x80000000, 0xffffffff};
    u32 a, b, length, x, y, i, round;
    Record left, right;
    /* Null payloads are safe when keys/lengths differ, or length is zero. */
    for (a = 0; a < 5; ++a) for (b = 0; b < 5; ++b) {
        left = (Record){keys[a], 0, 0};
        right = (Record){keys[b], 0, 0};
        if (!check(left, right)) return 1;
        if (a != b) {
            left = (Record){7, keys[a], 0};
            right = (Record){7, keys[b], 0};
            if (!check(left, right)) return 2;
        }
    }
    /* All tail lengths, both payload alignments, every mismatch position. */
    for (length = 0; length <= 64; ++length)
        for (x = 0; x < 4; ++x) for (y = 0; y < 4; ++y) {
            for (i = 0; i < length; ++i)
                left_bytes[x+i] = right_bytes[y+i] = (u8)random_u32();
            left = (Record){0x80000000, length, left_bytes+x};
            right = (Record){0x80000000, length, right_bytes+y};
            if (!check(left, right)) return 3;
            for (i = 0; i < length; ++i) {
                right_bytes[y+i] ^= 0x80;
                if (!check(left, right) || !check(right, left)) return 4;
                right_bytes[y+i] ^= 0x80;
            }
        }
    for (round = 0; round < 20000; ++round) {
        length = random_u32() % 65;
        x = random_u32() % 4; y = random_u32() % 4;
        for (i = 0; i < length; ++i) {
            left_bytes[x+i] = (u8)(random_u32() >> 24);
            right_bytes[y+i] = (u8)(random_u32() >> 24);
        }
        left = (Record){99, length, left_bytes+x};
        right = (Record){99, length, right_bytes+y};
        if (!check(left, right)) return 5;
    }
    return 0;
}

void _start(void) {
    char message[24];
    u32 n = 0, value, first, last;
    int result = run_tests();
    message[n++] = 'c'; message[n++] = 'h'; message[n++] = 'e';
    message[n++] = 'c'; message[n++] = 'k'; message[n++] = 's';
    message[n++] = '='; first = n; value = checks;
    do { message[n++] = (char)('0' + value % 10); value /= 10; } while (value);
    last = n - 1;
    while (first < last) {
        char c = message[first]; message[first++] = message[last]; message[last--] = c;
    }
    message[n++] = 10;
    __asm__ volatile ("int $0x80" : : "a"(4), "b"(1), "c"(message), "d"(n) : "memory");
    __asm__ volatile ("int $0x80" : : "a"(1), "b"(result) : "memory");
    __builtin_unreachable();
}
