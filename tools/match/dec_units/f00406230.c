typedef unsigned char _BYTE;
typedef unsigned short _WORD;
typedef unsigned int _DWORD;
typedef unsigned long long _QWORD;
typedef long long _LONGLONG;
typedef int _BOOL;
typedef void _UNKNOWN;

/* Hex-Rays helper macros and intrinsics the decompiler leaves in the bodies.
   Each is an expression, so it is defined as a cast or a two-argument macro
   exactly as the Hex-Rays C output expects it. */
#define LODWORD(x) (*(_DWORD *)&(x))
#define HIDWORD(x) (*(_DWORD *)((char *)&(x) + 4))
#define SLODWORD(x) (*(int *)&(x))
#define SHIDWORD(x) (*(int *)((char *)&(x) + 4))
#define LOWORD(x) (*(_WORD *)&(x))
#define HIWORD(x) (*(_WORD *)((char *)&(x) + 2))
#define LOBYTE(x) (*(_BYTE *)&(x))
#define HIBYTE(x) (*(_BYTE *)((char *)&(x) + 1))
#define SLOBYTE(x) (*(signed char *)&(x))
#define SHIBYTE(x) (*(signed char *)((char *)&(x) + 1))
#define BYTE1(x) (*(_BYTE *)((char *)&(x) + 1))
#define BYTE2(x) (*(_BYTE *)((char *)&(x) + 2))
#define COERCE_INT(x) ((int)(x))
#define COERCE_FLOAT(x) ((float)(x))
#define COERCE_DOUBLE(x) ((double)(x))
#define MEMORY ((_DWORD *)0)
#define __PAIR64__(hi, lo) (((_QWORD)(_DWORD)(hi) << 32) | (_DWORD)(lo))
#define __SPAIR64__(hi, lo) (((_LONGLONG)(int)(hi) << 32) | (_DWORD)(lo))
#define __ROL4__(x, n) (((_DWORD)(x) << (n)) | ((_DWORD)(x) >> (32 - (n))))
#define __ROL2__(x, n) (((_WORD)(x) << (n)) | ((_WORD)(x) >> (16 - (n))))
#define __ROR4__(x, n) (((_DWORD)(x) >> (n)) | ((_DWORD)(x) << (32 - (n))))
#define __ROR2__(x, n) (((_WORD)(x) >> (n)) | ((_WORD)(x) << (16 - (n))))
#define __CFADD__(a, b) ((_DWORD)(a) + (_DWORD)(b) < (_DWORD)(a))
#define __OFADD__(a, b) (((int)(a) + (int)(b)) < (int)(a))
#define __OFSUB__(a, b) (((int)(a) - (int)(b)) > (int)(a))
#define __SETP__(a, b) 0
union __m64u { unsigned __int64 q; _DWORD d[2]; };
typedef union __m64u __m64;
typedef struct { _QWORD low; _QWORD high; } __m128i;

typedef unsigned int size_t;
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef int BOOL;
typedef unsigned char bool;
typedef void *HANDLE;
typedef void *LPVOID;
typedef const char *LPCSTR;
typedef char *LPSTR;
typedef unsigned int UINT;
typedef unsigned long ULONG;
typedef struct _FILE FILE;
extern FILE *stderr;

extern char asc_25D7830[];
extern _BYTE byte_119FE7C[];
extern _BYTE byte_119FEDC[];
extern _BYTE byte_12A1350[];
extern _BYTE byte_12A8480[];
extern _BYTE byte_1325B63[];
extern _BYTE byte_133D6B2[];
extern _BYTE byte_133F0DF[];
extern _BYTE byte_133F580[];
extern _BYTE byte_133FA70[];
extern _BYTE byte_2321640[];
extern _BYTE byte_2321740[];
extern _BYTE byte_2321840[];
extern _BYTE byte_2321940[];
extern _BYTE byte_2321A40[];
extern _BYTE byte_2321B40[];
extern _BYTE byte_2321C40[];
extern _BYTE byte_2321E40[];
extern _BYTE byte_2321F40[];
extern _BYTE byte_2322040[];
extern _BYTE byte_2322140[];
extern _BYTE byte_2322668[];
extern _BYTE byte_25D60B6[];
extern _BYTE byte_C48E10[];
extern _BYTE byte_C48E11[];
extern _BYTE byte_C48E12[];
extern _BYTE byte_C48E60[];
extern _BYTE byte_C533E0[];
extern _BYTE byte_C53408[];
extern _BYTE byte_C58F00[];
extern _BYTE byte_C58F01[];
extern _BYTE byte_C58F02[];
extern _BYTE byte_C58F03[];
extern _BYTE byte_C5B2D4[];
extern _BYTE byte_C86008[];
extern _BYTE byte_C89C40[];
extern _BYTE byte_C94F00[];
extern _BYTE byte_C96298[];
extern _BYTE byte_CB3C94[];
extern double dbl_25D8400[];
extern double dbl_25D8408[];
extern double dbl_25D8410[];
extern double dbl_25D8418[];
extern double dbl_25D8420[];
extern double dbl_25D8428[];
extern double dbl_25D8430[];
extern double dbl_25D8438[];
extern double dbl_25D85A0[];
extern double dbl_25D85A8[];
extern double dbl_25D85B0[];
extern double dbl_25D85B8[];
extern double dbl_25D85C0[];
extern double dbl_25D85C8[];
extern double dbl_25D85D0[];
extern double dbl_25D85D8[];
extern _DWORD dword_119FDEC[];
extern _DWORD dword_119FDF0[];
extern _DWORD dword_119FE80[];
extern _DWORD dword_119FEB0[];
extern _DWORD dword_119FEF0[];
extern _DWORD dword_119FEF4[];
extern _DWORD dword_119FF30[];
extern _DWORD dword_119FF34[];
extern _DWORD dword_11A0050[];
extern _DWORD dword_12A4080[];
extern _DWORD dword_12F40B8[];
extern _DWORD dword_12F40C4[];
extern _DWORD dword_12FB380[];
extern _DWORD dword_1328AC0[];
extern _DWORD dword_1328B08[];
extern _DWORD dword_133C88C[];
extern _DWORD dword_133C8A4[];
extern _DWORD dword_1340280[];
extern _DWORD dword_1340434[];
extern _DWORD dword_1865AFC[];
extern _DWORD dword_186A6E0[];
extern _DWORD dword_186A720[];
extern _DWORD dword_186A760[];
extern _DWORD dword_186A7A0[];
extern _DWORD dword_193F940[];
extern _DWORD dword_193F980[];
extern _DWORD dword_19449F4[];
extern _DWORD dword_1944A24[];
extern _DWORD dword_1944A50[];
extern _DWORD dword_1944A80[];
extern _DWORD dword_1944C5C[];
extern _DWORD dword_1944C8C[];
extern _DWORD dword_1944D54[];
extern _DWORD dword_1944DC4[];
extern _DWORD dword_1944DF4[];
extern _DWORD dword_1944EAC[];
extern _DWORD dword_1944EDC[];
extern _DWORD dword_19450A8[];
extern _DWORD dword_1984C30[];
extern _DWORD dword_1A84DB4[];
extern _DWORD dword_1A84DE4[];
extern _DWORD dword_1A84F68[];
extern _DWORD dword_1A84F98[];
extern _DWORD dword_1A85148[];
extern _DWORD dword_1A85404[];
extern _DWORD dword_1A854B4[];
extern _DWORD dword_1A854E4[];
extern _DWORD dword_1A85540[];
extern _DWORD dword_1A855B0[];
extern _DWORD dword_1A855B8[];
extern _DWORD dword_1A8564C[];
extern _DWORD dword_1A85748[];
extern _DWORD dword_1A858F4[];
extern _DWORD dword_1A85A2C[];
extern _DWORD dword_1A85A5C[];
extern _DWORD dword_1A85A88[];
extern _DWORD dword_1A85AB4[];
extern _DWORD dword_1A85AE0[];
extern _DWORD dword_1A85BB0[];
extern _DWORD dword_1A85BB4[];
extern _DWORD dword_1A85BB8[];
extern _DWORD dword_1A85BBC[];
extern _DWORD dword_1A85BF0[];
extern _DWORD dword_1A85F78[];
extern _DWORD dword_1A85F98[];
extern _DWORD dword_1A85FE8[];
extern _DWORD dword_22FB3C8[];
extern _DWORD dword_22FB3E0[];
extern _DWORD dword_2305834[];
extern _DWORD dword_23C3648[];
extern _DWORD dword_25D5F44[];
extern _DWORD dword_25D5F54[];
extern _DWORD dword_25D5F5C[];
extern _DWORD dword_25D5F64[];
extern _DWORD dword_25D5F74[];
extern _DWORD dword_B6FE9C[];
extern _DWORD dword_B6FEA8[];
extern _DWORD dword_B6FEB4[];
extern _DWORD dword_B6FEC0[];
extern _DWORD dword_B81508[];
extern _DWORD dword_B8150C[];
extern _DWORD dword_B8F068[];
extern _DWORD dword_C48E28[];
extern _DWORD dword_C49470[];
extern _DWORD dword_C49474[];
extern _DWORD dword_C52704[];
extern _DWORD dword_C52714[];
extern _DWORD dword_C5363C[];
extern _DWORD dword_C5C2C8[];
extern _DWORD dword_C60A78[];
extern _DWORD dword_C60DC0[];
extern _DWORD dword_C60DC4[];
extern _DWORD dword_C6D4F8[];
extern _DWORD dword_C6D50C[];
extern _DWORD dword_C85A9C[];
extern _DWORD dword_C86580[];
extern _DWORD dword_C86660[];
extern _DWORD dword_C879B0[];
extern _DWORD dword_C87C90[];
extern _DWORD dword_C87C94[];
extern _DWORD dword_C87C98[];
extern _DWORD dword_C87C9C[];
extern _DWORD dword_C87D10[];
extern _DWORD dword_C87D14[];
extern _DWORD dword_C87D18[];
extern _DWORD dword_C87D1C[];
extern _DWORD dword_C88690[];
extern _DWORD dword_C88AA8[];
extern _DWORD dword_C8AE20[];
extern _DWORD dword_C8B220[];
extern _DWORD dword_C8FAC4[];
extern _DWORD dword_C940C4[];
extern _DWORD dword_C94168[];
extern _DWORD dword_C9AF00[];
extern _DWORD dword_CA43B0[];
extern _DWORD dword_CA4EC4[];
extern _DWORD dword_CA852C[];
extern _DWORD dword_CA8998[];
extern _DWORD dword_CA89A8[];
extern _DWORD dword_CB3428[];
extern _DWORD dword_CC96E4[];
extern _DWORD dword_CC9EE4[];
extern _DWORD dword_CCB214[];
extern _DWORD dword_CDEE10[];
extern _DWORD dword_CE6D60[];
extern _DWORD dword_CE6EA0[];
extern float flt_133F658[];
extern float flt_C43BE0[];
extern float flt_C44BE0[];
extern float flt_C86B60[];
extern float flt_C86BF0[];
extern float flt_C8F514[];
extern float flt_C8F734[];
extern _DWORD funcs_8126C9[];
extern _DWORD funcs_A43DF8[];
extern void * off_C5343C[];
extern void * off_C5997C[];
extern void * off_C59D58[];
extern void * off_C59D60[];
extern void * off_C59E4C[];
extern void * off_C59E50[];
extern void * off_C59E54[];
extern void * off_C59E58[];
extern void * off_C59E5C[];
extern void * off_C59E60[];
extern void * off_C59E64[];
extern void * off_C59E68[];
extern void * off_C59E6C[];
extern void * off_C59E70[];
extern void * off_C59E74[];
extern void * off_C59E78[];
extern void * off_C59E7C[];
extern void * off_C59E80[];
extern void * off_C59E84[];
extern void * off_C59E88[];
extern void * off_C59E8C[];
extern void * off_C59E90[];
extern void * off_C59E94[];
extern void * off_C59E98[];
extern void * off_C59E9C[];
extern void * off_C59EA0[];
extern void * off_C59EA4[];
extern void * off_C59EA8[];
extern void * off_C59EAC[];
extern void * off_C59EB0[];
extern void * off_C59EB4[];
extern void * off_C59EB8[];
extern void * off_C5E8A8[];
extern void * off_C5E8B4[];
extern void * off_C60E30[];
extern void * off_C684A4[];
extern void * off_C6B274[];
extern void * off_C6B278[];
extern void * off_C6B280[];
extern void * off_C6B284[];
extern void * off_C6B288[];
extern void * off_C6B28C[];
extern void * off_C6B290[];
extern void * off_C6B298[];
extern void * off_C6B29C[];
extern void * off_C6D25C[];
extern void * off_C85EF0[];
extern void * off_C88A90[];
extern void * off_C88AA4[];
extern void * off_C8B438[];
extern void * off_C8B43C[];
extern _QWORD qword_B86FA8[];
extern _QWORD qword_B86FF0[];
extern _QWORD qword_C8F8D0[];
extern _BYTE unk_119FE70[];
extern _BYTE unk_1328A34[];
extern _BYTE unk_133C912[];
extern _BYTE unk_133C91C[];
extern _BYTE unk_133D124[];
extern _BYTE unk_133D1B4[];
extern _BYTE unk_133D6BC[];
extern _BYTE unk_133D6E1[];
extern _BYTE unk_133D6F1[];
extern _BYTE unk_133D730[];
extern _BYTE unk_133F09C[];
extern _BYTE unk_133F0B0[];
extern _BYTE unk_133F588[];
extern _BYTE unk_133F5EC[];
extern _BYTE unk_133F608[];
extern _BYTE unk_133F624[];
extern _BYTE unk_133F640[];
extern _BYTE unk_133F758[];
extern _BYTE unk_133F7DA[];
extern _BYTE unk_1340406[];
extern _BYTE unk_13404CC[];
extern _BYTE unk_1841CE8[];
extern _BYTE unk_1841CF4[];
extern _BYTE unk_1941C98[];
extern _BYTE unk_1941CC0[];
extern _BYTE unk_1944F7C[];
extern _BYTE unk_1944FA4[];
extern _BYTE unk_1944FCC[];
extern _BYTE unk_1944FF4[];
extern _BYTE unk_22FB4DC[];
extern _BYTE unk_23328E0[];
extern _BYTE unk_23CBC60[];
extern _BYTE unk_23CC040[];
extern _BYTE unk_23CC048[];
extern _BYTE unk_23CC058[];
extern _BYTE unk_23CC088[];
extern _BYTE unk_23CC092[];
extern _BYTE unk_25D0A8A[];
extern _BYTE unk_25D5A24[];
extern _BYTE unk_C8F508[];
extern _BYTE unk_C8F75C[];
extern _BYTE unk_C8F78C[];
extern _BYTE unk_C8F8D0[];
extern _BYTE unk_C8F8DC[];
extern _BYTE unk_C8F8F0[];
extern _BYTE unk_C90258[];
extern _BYTE unk_C90380[];
extern _BYTE unk_C903B0[];
extern _BYTE unk_C903E0[];
extern _BYTE unk_C90410[];
extern _BYTE unk_C90440[];
extern _BYTE unk_C90470[];
extern _BYTE unk_C904A0[];
extern _BYTE unk_C904D0[];
extern _BYTE unk_C90500[];
extern _BYTE unk_C90530[];
extern _BYTE unk_C90560[];
extern _BYTE unk_C90590[];
extern _BYTE unk_C905C0[];
extern _BYTE unk_C90808[];
extern _BYTE unk_C90AB8[];
extern _BYTE unk_C90AE4[];
extern _BYTE unk_C90B00[];
extern _BYTE unk_C90C60[];
extern _BYTE unk_C90C8C[];
extern _BYTE unk_C90CB4[];
extern _BYTE unk_C90CDC[];
extern _BYTE unk_C90ED0[];
extern _BYTE unk_C91130[];
extern _BYTE unk_C91CB8[];
extern _BYTE unk_C91CE4[];
extern _BYTE unk_C91E78[];
extern _BYTE unk_C91EFC[];
extern _BYTE unk_C91F24[];
extern _BYTE unk_C91F4C[];
extern _BYTE unk_C91F74[];
extern _BYTE unk_C91F9C[];
extern _BYTE unk_C91FC4[];
extern _BYTE unk_C92130[];
extern _BYTE unk_C9215C[];
extern _BYTE unk_C92184[];
extern _BYTE unk_C921D8[];
extern _BYTE unk_C9281C[];
extern _BYTE unk_C92874[];
extern _BYTE unk_C9289C[];
extern _BYTE unk_C931B8[];
extern _BYTE unk_C93B88[];
extern _BYTE unk_C93BB4[];
extern _BYTE unk_C93BDC[];
extern _BYTE unk_C93C04[];
extern _BYTE unk_C93F08[];
extern _BYTE unk_C94184[];
extern _BYTE unk_C941AC[];
extern _BYTE unk_C941D4[];
extern _BYTE unk_C943F4[];
extern _BYTE unk_C94528[];
extern _BYTE unk_C94550[];
extern _BYTE unk_C94650[];
extern _BYTE unk_C94678[];
extern _BYTE unk_C946A0[];
extern _BYTE unk_C947A0[];
extern _BYTE unk_C947C8[];
extern _BYTE unk_C947F0[];
extern _BYTE unk_C948F0[];
extern _BYTE unk_C94918[];
extern _BYTE unk_C94940[];
extern _BYTE unk_C94968[];
extern _BYTE unk_C94A68[];
extern _BYTE unk_C94A90[];
extern _BYTE unk_C94AB8[];
extern _BYTE unk_C94AE0[];
extern _BYTE unk_C94EB8[];
extern _BYTE unk_C94EE4[];
extern _BYTE unk_C9628C[];
extern _BYTE unk_C999C0[];
extern _BYTE unk_C999E8[];
extern _BYTE unk_C99A10[];
extern _BYTE unk_C99F54[];
extern _BYTE unk_C9B214[];
extern _BYTE unk_C9B23C[];
extern _BYTE unk_C9B264[];
extern _BYTE unk_C9B28C[];
extern _BYTE unk_C9B2B4[];
extern _BYTE unk_C9B2DC[];
extern _BYTE unk_C9B304[];
extern _BYTE unk_C9B32C[];
extern _BYTE unk_C9B354[];
extern _BYTE unk_C9B37C[];
extern _BYTE unk_CA2C18[];
extern _BYTE unk_CA2C40[];
extern _BYTE unk_CA2C68[];
extern _BYTE unk_CA2C90[];
extern _BYTE unk_CA2CB8[];
extern _BYTE unk_CA2CE0[];
extern _BYTE unk_CA2D08[];
extern _BYTE unk_CA2D30[];
extern _BYTE unk_CA2D58[];
extern _BYTE unk_CA2D80[];
extern _BYTE unk_CA2DA8[];
extern _BYTE unk_CA36B0[];
extern _BYTE unk_CA786C[];
extern _BYTE unk_CA7894[];
extern _BYTE unk_CA78BC[];
extern _BYTE unk_CA78E4[];
extern _BYTE unk_CA790C[];
extern _BYTE unk_CA7934[];
extern _BYTE unk_CA795C[];
extern _BYTE unk_CA7988[];
extern _BYTE unk_CA9298[];
extern _BYTE unk_CA92C4[];
extern _BYTE unk_CA92EC[];
extern _BYTE unk_CA9314[];
extern _BYTE unk_CA933C[];
extern _BYTE unk_CA9364[];
extern _BYTE unk_CA938C[];
extern _BYTE unk_CA93B4[];
extern _BYTE unk_CA93DC[];
extern _BYTE unk_CA9404[];
extern _BYTE unk_CA942C[];
extern _BYTE unk_CA9454[];
extern _BYTE unk_CA947C[];
extern _BYTE unk_CA9CC8[];
extern _BYTE unk_CA9CF4[];
extern _BYTE unk_CA9D1C[];
extern _BYTE unk_CA9D44[];
extern _BYTE unk_CAA888[];
extern _BYTE unk_CAA8B4[];
extern _BYTE unk_CAA8DC[];
extern _BYTE unk_CAA904[];
extern _BYTE unk_CAA92C[];
extern _BYTE unk_CAA954[];
extern _BYTE unk_CAA97C[];
extern _BYTE unk_CAA9A4[];
extern _BYTE unk_CAA9CC[];
extern _BYTE unk_CAA9F4[];
extern _BYTE unk_CAAFE8[];
extern _BYTE unk_CAB010[];
extern _BYTE unk_CAB038[];
extern _BYTE unk_CAB9C0[];
extern _BYTE unk_CADCD4[];
extern _BYTE unk_CADCFC[];
extern _BYTE unk_CADD24[];
extern _BYTE unk_CADD4C[];
extern _BYTE unk_CADD74[];
extern _BYTE unk_CADD9C[];
extern _BYTE unk_CADDC4[];
extern _BYTE unk_CADDEC[];
extern _BYTE unk_CADE14[];
extern _BYTE unk_CADE3C[];
extern _BYTE unk_CADE64[];
extern _BYTE unk_CADE8C[];
extern _BYTE unk_CADEB4[];
extern _BYTE unk_CADEDC[];
extern _BYTE unk_CADF04[];
extern _BYTE unk_CADF2C[];
extern _BYTE unk_CADF54[];
extern _BYTE unk_CADF7C[];
extern _BYTE unk_CADFA4[];
extern _BYTE unk_CADFCC[];
extern _BYTE unk_CADFF4[];
extern _BYTE unk_CAE01C[];
extern _BYTE unk_CAE044[];
extern _BYTE unk_CAE6B0[];
extern _BYTE unk_CAE6D8[];
extern _BYTE unk_CAE700[];
extern _BYTE unk_CAE728[];
extern _BYTE unk_CAE948[];
extern _BYTE unk_CAE970[];
extern _BYTE unk_CAE998[];
extern _BYTE unk_CAE9C0[];
extern _BYTE unk_CAE9E8[];
extern _BYTE unk_CAEA10[];
extern _BYTE unk_CAEA38[];
extern _BYTE unk_CAEA60[];
extern _BYTE unk_CAEA88[];
extern _BYTE unk_CAEEE0[];
extern _BYTE unk_CAEF08[];
extern _BYTE unk_CAEF30[];
extern _BYTE unk_CAEF58[];
extern _BYTE unk_CAFA24[];
extern _BYTE unk_CAFA4C[];
extern _BYTE unk_CAFA74[];
extern _BYTE unk_CAFA9C[];
extern _BYTE unk_CAFC10[];
extern _BYTE unk_CAFC3C[];
extern _BYTE unk_CAFC64[];
extern _BYTE unk_CB00BC[];
extern _BYTE unk_CB00E4[];
extern _BYTE unk_CB010C[];
extern _BYTE unk_CB0134[];
extern _BYTE unk_CB015C[];
extern _BYTE unk_CB0184[];
extern _BYTE unk_CB01AC[];
extern _BYTE unk_CB01D4[];
extern _BYTE unk_CB01FC[];
extern _BYTE unk_CB0C98[];
extern _BYTE unk_CB0CC0[];
extern _BYTE unk_CB0CE8[];
extern _BYTE unk_CB0D10[];
extern _BYTE unk_CB0D38[];
extern _BYTE unk_CB0D60[];
extern _BYTE unk_CB0D88[];
extern _BYTE unk_CB0DB0[];
extern _BYTE unk_CB0DD8[];
extern _BYTE unk_CB0E00[];
extern _BYTE unk_CB23F4[];
extern _BYTE unk_CB241C[];
extern _BYTE unk_CB2444[];
extern _BYTE unk_CB246C[];
extern _BYTE unk_CB2494[];
extern _BYTE unk_CB24BC[];
extern _BYTE unk_CB24E4[];
extern _BYTE unk_CB250C[];
extern _BYTE unk_CB2534[];
extern _BYTE unk_CB255C[];
extern _BYTE unk_CB2584[];
extern _BYTE unk_CB25AC[];
extern _BYTE unk_CB25D4[];
extern _BYTE unk_CB25FC[];
extern _BYTE unk_CB2624[];
extern _BYTE unk_CB264C[];
extern _BYTE unk_CB2674[];
extern _BYTE unk_CB269C[];
extern _BYTE unk_CB28C4[];
extern _BYTE unk_CB28EC[];
extern _BYTE unk_CB2914[];
extern _BYTE unk_CB2A1C[];
extern _BYTE unk_CB2A44[];
extern _BYTE unk_CBADE8[];
extern _BYTE unk_CBAE10[];
extern _BYTE unk_CBDA68[];
extern _BYTE unk_CBDA94[];
extern _BYTE unk_CBDABC[];
extern _BYTE unk_CBDAE4[];
extern _BYTE unk_CC00D4[];
extern _BYTE unk_CC00FC[];
extern _BYTE unk_CC0124[];
extern _BYTE unk_CC014C[];
extern _BYTE unk_CC04E8[];
extern _BYTE unk_CC0510[];
extern _BYTE unk_CC0B0C[];
extern _BYTE unk_CC0B34[];
extern _BYTE unk_CC0B5C[];
extern _BYTE unk_CC0B84[];
extern _BYTE unk_CC0BAC[];
extern _BYTE unk_CC0C84[];
extern _BYTE unk_CC0CB0[];
extern _BYTE unk_CC0CD8[];
extern _BYTE unk_CC0D00[];
extern _BYTE unk_CC0D28[];
extern _BYTE unk_CC0D50[];
extern _BYTE unk_CC0D78[];
extern _BYTE unk_CC0DA0[];
extern _BYTE unk_CC0DC8[];
extern _BYTE unk_CC0DF0[];
extern _BYTE unk_CC12B0[];
extern _BYTE unk_CC12DC[];
extern _BYTE unk_CC1304[];
extern _BYTE unk_CC132C[];
extern _BYTE unk_CC1354[];
extern _BYTE unk_CC137C[];
extern _BYTE unk_CC13A4[];
extern _BYTE unk_CC13CC[];
extern _BYTE unk_CC99B0[];
extern _BYTE unk_CC9EFC[];
extern _BYTE unk_CCA2C0[];
extern _BYTE unk_CCA2E8[];
extern _BYTE unk_CDEDD4[];
extern _WORD word_133C91E[];
extern _WORD word_133D13C[];
extern _WORD word_133D190[];
extern _WORD word_133F0C8[];
extern _WORD word_133F650[];
extern _WORD word_133F66A[];
extern _WORD word_133F672[];
extern _WORD word_133FA60[];
extern _WORD word_1340278[];
extern _WORD word_1340408[];
extern _WORD word_1871504[];
extern _WORD word_187152E[];
extern _WORD word_1871628[];
extern _WORD word_1871638[];
extern _WORD word_18762A0[];
extern _WORD word_18762AE[];
extern _WORD word_22D9870[];
extern _WORD word_B587E0[];
extern _WORD word_C49300[];
extern _WORD word_C4930C[];
extern _WORD word_C49388[];
extern _WORD word_C53414[];
extern _WORD word_C86C00[];
extern _WORD word_C86C10[];
extern _WORD word_C86C20[];
extern _DWORD xmmword_25D7010[];
extern _DWORD xmmword_25D75E0[];
extern _DWORD xmmword_25D7840[];
extern _DWORD xmmword_B81350[];

extern _DWORD FFX_Phyre_Const_B7D518;
extern _DWORD Phyre_ZlibCRC32();
extern _DWORD Phyre_ZlibCRC32_Safe();
extern _DWORD Phyre_ZlibInflate_Adler32();
extern _DWORD Phyre_ZlibInflate_BuildHuffmanTables();
extern _DWORD Phyre_ZlibInflate_InflateBlock();
extern _DWORD Phyre_ZlibInflate_InitFixedTables();
extern _DWORD Phyre_ZlibInflate_ProcessBlock();
extern _DWORD SBYTE1();
extern _DWORD data();
// Function: Phyre_ZlibInflate
// Address: 0x406230
// Size: 0x15ED
// Phyre: Zlib inflate — decompresses zlib-compressed data (5.5KB, Phyre's built-in zlib 1.2.8)
// Phyre: Zlib inflate
// zlib 1.2.8 inflate. Decompresses .phyre asset files. Standard zlib implementation embedded in the binary.
int __fastcall Phyre_ZlibInflate(PhyreZlibState *self)
{
  int flags; // ecx
  unsigned char *next_in; // edi
  unsigned int avail_in; // ebx
  unsigned int n35615; // edx
  int v6; // eax
  unsigned int n0x10; // esi
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  bool v13; // zf
  unsigned int v14; // eax
  unsigned int v15; // eax
  int v16; // eax
  int *v17; // esi
  int v18; // ecx
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  int v24; // eax
  int v25; // esi
  int v26; // ecx
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // ecx
  int v31; // eax
  int v32; // eax
  unsigned int avail_in_3; // edx
  _DWORD *v34; // eax
  unsigned int v35; // ecx
  size_t avail_in_5; // ecx
  int v37; // eax
  unsigned int avail_in_6; // edx
  int v39; // eax
  unsigned int v40; // esi
  int *v41; // eax
  int v42; // eax
  int v43; // eax
  unsigned int avail_in_8; // edx
  int v45; // eax
  unsigned int v46; // esi
  int *v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // edx
  int v52; // eax
  int v53; // eax
  int v54; // eax
  int this_2; // edx
  unsigned int v56; // eax
  int v57; // ecx
  int v58; // eax
  int v59; // eax
  unsigned int v60; // edx
  unsigned int v61; // edx
  int this_4; // eax
  int v63; // ecx
  int v64; // eax
  size_t avail_in_10; // eax
  int v66; // eax
  unsigned int v67; // edx
  int v68; // eax
  int v69; // eax
  bool v70; // cc
  int v71; // eax
  _DWORD *flags_3; // edi
  unsigned int v73; // eax
  _DWORD *flags_4; // edx
  int v75; // eax
  int v76; // eax
  int v77; // eax
  int v78; // edx
  int v79; // ecx
  char n0x10_7; // cl
  int v81; // eax
  unsigned int v82; // edx
  int v83; // eax
  int v84; // eax
  unsigned int v85; // edx
  unsigned int v86; // eax
  int *v87; // ebx
  int v88; // eax
  int v89; // eax
  int this_5; // eax
  void *Src_1; // edi
  unsigned int v92; // eax
  int v93; // eax
  unsigned int v94; // kr00_4
  unsigned int avail_in_12; // eax
  int v96; // eax
  _DWORD *flags_5; // edi
  int *n0x10_3; // eax
  int v99; // eax
  unsigned int v100; // eax
  int v101; // eax
  short v102; // dx
  int v103; // eax
  _DWORD *flags_6; // ebx
  int v105; // ecx
  int *n0x10_5; // eax
  int v107; // eax
  unsigned int v108; // eax
  size_t Size_2; // eax
  size_t Size_4; // edi
  int v111; // edx
  int v112; // edx
  size_t Size_1; // edx
  unsigned char *next_out_2; // edx
  size_t Size_3; // edi
  unsigned char *next_out_3; // edx
  unsigned char v117; // al
  int v118; // eax
  int v119; // eax
  int this_7; // ebx
  int n35615_4; // eax
  int v122; // eax
  int result; // eax
  unsigned char **this_3; // eax
  _DWORD *flags_2; // ecx
  _DWORD *this_6; // edi
  int *flags_7; // ebx
  void *Src_2; // ecx
  int n35615_3; // eax
  unsigned int n0x20; // esi
  unsigned int v131; // eax
  int v132; // edx
  _DWORD *v133; // edx
  int v134; // eax
  int n14; // eax
  int n256; // esi
  int n128; // ecx
  unsigned int n19; // [esp-18h] [ebp-5Ch]
  unsigned int n19_1; // [esp-18h] [ebp-5Ch]
  int *v140; // [esp-Ch] [ebp-50h]
  unsigned int avail_in_2; // [esp+4h] [ebp-40h]
  char v142; // [esp+Ch] [ebp-38h]
  unsigned int avail_in_4; // [esp+Ch] [ebp-38h]
  int *avail_in_7; // [esp+Ch] [ebp-38h]
  int *avail_in_9; // [esp+Ch] [ebp-38h]
  int *v146; // [esp+Ch] [ebp-38h]
  size_t avail_in_11; // [esp+Ch] [ebp-38h]
  int *v148; // [esp+Ch] [ebp-38h]
  int *n0x10_6; // [esp+Ch] [ebp-38h]
  short v150; // [esp+Ch] [ebp-38h]
  int *v151; // [esp+Ch] [ebp-38h]
  int *v152; // [esp+Ch] [ebp-38h]
  int *n0x10_2; // [esp+Ch] [ebp-38h]
  int *v154; // [esp+Ch] [ebp-38h]
  int *n0x10_4; // [esp+Ch] [ebp-38h]
  int *Size_5; // [esp+Ch] [ebp-38h]
  int *v157; // [esp+10h] [ebp-34h]
  int *v158; // [esp+10h] [ebp-34h]
  int *v159; // [esp+10h] [ebp-34h]
  int *v160; // [esp+10h] [ebp-34h]
  int *v161; // [esp+10h] [ebp-34h]
  int v162; // [esp+10h] [ebp-34h]
  int v163; // [esp+10h] [ebp-34h]
  short n17; // [esp+12h] [ebp-32h]
  unsigned short v165; // [esp+12h] [ebp-32h]
  int v166; // [esp+14h] [ebp-30h]
  int v167; // [esp+18h] [ebp-2Ch]
  int v168; // [esp+18h] [ebp-2Ch]
  int v169; // [esp+18h] [ebp-2Ch]
  unsigned int v170; // [esp+18h] [ebp-2Ch]
  int v171; // [esp+18h] [ebp-2Ch]
  int v172; // [esp+18h] [ebp-2Ch]
  int v173; // [esp+18h] [ebp-2Ch]
  unsigned int next_out; // [esp+1Ch] [ebp-28h]
  unsigned int next_outa; // [esp+1Ch] [ebp-28h]
  unsigned char *next_out_1; // [esp+20h] [ebp-24h]
  unsigned int n35615_2; // [esp+24h] [ebp-20h] BYREF
  size_t Size; // [esp+28h] [ebp-1Ch]
  int this_1; // [esp+2Ch] [ebp-18h]
  int n0x10_1; // [esp+30h] [ebp-14h]
  void *Src; // [esp+34h] [ebp-10h]
  unsigned int avail_in_1; // [esp+38h] [ebp-Ch]
  _DWORD *flags_1; // [esp+3Ch] [ebp-8h]
  unsigned int n35615_1; // [esp+40h] [ebp-4h]

  this_1 = (int)self;
  if ( !self )
    return -2;
  flags = self->flags;
  flags_1 = (_DWORD *)flags;
  if ( !flags )
    return -2;
  next_out_1 = self->next_out;
  if ( !next_out_1 )
    return -2;
  next_in = self->next_in;
  Src = next_in;
  if ( !next_in )
  {
    if ( self->avail_in )
      return -2;
  }
  if ( *(_DWORD *)flags == 11 )
    *(_DWORD *)flags = 12;
  avail_in = self->avail_in;
  Size = self->avail_out;
  n35615 = *(_DWORD *)(flags + 56);
  next_out = Size;
  v166 = 0;
  v6 = *(_DWORD *)flags;
  n0x10 = *(_DWORD *)(flags + 60);
  avail_in_1 = avail_in;
  n35615_1 = n35615;
  n0x10_1 = n0x10;
  avail_in_2 = avail_in;
  while ( 2 )
  {
    switch ( v6 )
    {
      case 0:
        v8 = *(_DWORD *)(flags + 8);
        v142 = v8;
        if ( !v8 )
        {
          *(_DWORD *)flags = 12;
          goto LABEL_324;
        }
        if ( n0x10 < 0x10 )
        {
          do
          {
            if ( !avail_in )
              goto LABEL_331;
            v9 = *next_in << n0x10;
            n0x10 += 8;
            --avail_in;
            ++next_in;
            n35615 += v9;
            avail_in_1 = avail_in;
            n35615_1 = n35615;
            Src = next_in;
            n0x10_1 = n0x10;
          }
          while ( n0x10 < 0x10 );
          flags = (int)flags_1;
          LOBYTE(v8) = v142;
        }
        if ( (v8 & 2) != 0 && n35615 == 35615 )
        {
          v10 = Phyre_ZlibCRC32_Safe(0, 0, 0);
          flags_1[6] = v10;
          LOWORD(n35615_2) = -29921;
          v11 = Phyre_ZlibCRC32(v10, &n35615_2, 2u);
          flags = (int)flags_1;
          n35615 = 0;
          n0x10 = 0;
          flags_1[6] = v11;
          n35615_1 = 0;
          n0x10_1 = 0;
          *(_DWORD *)flags = 1;
          goto LABEL_324;
        }
        v12 = *(_DWORD *)(flags + 32);
        *(_DWORD *)(flags + 16) = 0;
        if ( v12 )
          *(_DWORD *)(v12 + 48) = -1;
        if ( (*(_BYTE *)(flags + 8) & 1) != 0 )
        {
          flags = (int)flags_1;
          v13 = (((unsigned char)n35615 << 8) + (n35615 >> 8)) % 0x1F == 0;
          n35615 = n35615_1;
          if ( v13 )
          {
            if ( (n35615_1 & 0xF) != 8 )
            {
              *(_DWORD *)(this_1 + 24) = "unknown compression method";
              goto LABEL_323;
            }
            n35615 = n35615_1 >> 4;
            n0x10 -= 4;
            v14 = ((unsigned char)n35615_1 >> 4) + 8;
            v13 = flags_1[9] == 0;
            n35615_1 >>= 4;
            n0x10_1 = n0x10;
            if ( v13 )
            {
              flags_1[9] = v14;
            }
            else if ( v14 > flags_1[9] )
            {
              *(_DWORD *)(this_1 + 24) = "invalid window size";
              goto LABEL_323;
            }
            flags_1[5] = 1 << ((n35615 & 0xF) + 8);
            v15 = Phyre_ZlibInflate_Adler32(0, 0, 0);
            flags = (int)flags_1;
            *(_DWORD *)(this_1 + 48) = v15;
            *(_DWORD *)flags = ~BYTE1(n35615_1) & 2 | 9;
            n35615 = 0;
            n0x10 = 0;
            *(_DWORD *)(flags + 24) = v15;
            n35615_1 = 0;
            n0x10_1 = 0;
            goto LABEL_324;
          }
        }
        *(_DWORD *)(this_1 + 24) = "incorrect header check";
        goto LABEL_323;
      case 1:
        if ( n0x10 >= 0x10 )
          goto LABEL_35;
        do
        {
          if ( !avail_in )
            goto LABEL_331;
          v16 = *next_in << n0x10;
          n0x10 += 8;
          --avail_in;
          ++next_in;
          n35615 += v16;
          avail_in_1 = avail_in;
          n35615_1 = n35615;
          Src = next_in;
          n0x10_1 = n0x10;
        }
        while ( n0x10 < 0x10 );
        flags = (int)flags_1;
LABEL_35:
        *(_DWORD *)(flags + 16) = n35615;
        if ( (_BYTE)n35615 != 8 )
        {
          *(_DWORD *)(this_1 + 24) = "unknown compression method";
          goto LABEL_323;
        }
        if ( (n35615 & 0xE000) != 0 )
        {
          *(_DWORD *)(this_1 + 24) = "unknown header flags set";
          goto LABEL_323;
        }
        v17 = *(int **)(flags + 32);
        if ( v17 )
          *v17 = (n35615 >> 8) & 1;
        if ( (*(_DWORD *)(flags + 16) & 0x200) != 0 )
        {
          v18 = *(_DWORD *)(flags + 24);
          LOWORD(n35615_2) = n35615;
          v19 = Phyre_ZlibCRC32(v18, &n35615_2, 2u);
          flags = (int)flags_1;
          flags_1[6] = v19;
        }
        n35615 = 0;
        n35615_1 = 0;
        n0x10 = 0;
        *(_DWORD *)flags = 2;
        do
        {
LABEL_45:
          if ( !avail_in )
            goto LABEL_331;
          v20 = *next_in << n0x10;
          --avail_in;
          ++next_in;
          n0x10 += 8;
          n35615 += v20;
          avail_in_1 = avail_in;
          n35615_1 = n35615;
          Src = next_in;
        }
        while ( n0x10 < 0x20 );
        flags = (int)flags_1;
LABEL_48:
        v21 = *(_DWORD *)(flags + 32);
        if ( v21 )
          *(_DWORD *)(v21 + 4) = n35615;
        if ( (*(_DWORD *)(flags + 16) & 0x200) != 0 )
        {
          v22 = *(_DWORD *)(flags + 24);
          n35615_2 = n35615;
          v23 = Phyre_ZlibCRC32(v22, &n35615_2, 4u);
          flags = (int)flags_1;
          flags_1[6] = v23;
        }
        n35615 = 0;
        n35615_1 = 0;
        n0x10 = 0;
        *(_DWORD *)flags = 3;
        do
        {
LABEL_54:
          if ( !avail_in )
            goto LABEL_331;
          v24 = *next_in << n0x10;
          --avail_in;
          ++next_in;
          n0x10 += 8;
          n35615 += v24;
          avail_in_1 = avail_in;
          n35615_1 = n35615;
          Src = next_in;
        }
        while ( n0x10 < 0x10 );
        flags = (int)flags_1;
LABEL_57:
        v25 = *(_DWORD *)(flags + 32);
        if ( v25 )
        {
          *(_DWORD *)(v25 + 8) = (unsigned char)n35615;
          *(_DWORD *)(flags_1[8] + 12) = n35615 >> 8;
          flags = (int)flags_1;
        }
        if ( (*(_DWORD *)(flags + 16) & 0x200) != 0 )
        {
          v26 = *(_DWORD *)(flags + 24);
          LOWORD(n35615_2) = n35615;
          v27 = Phyre_ZlibCRC32(v26, &n35615_2, 2u);
          flags = (int)flags_1;
          flags_1[6] = v27;
        }
        n35615 = 0;
        n0x10 = 0;
        n35615_1 = 0;
        n0x10_1 = 0;
        *(_DWORD *)flags = 4;
LABEL_62:
        if ( (*(_DWORD *)(flags + 16) & 0x400) != 0 )
        {
          if ( n0x10 < 0x10 )
          {
            do
            {
              if ( !avail_in )
                goto LABEL_331;
              v28 = *next_in << n0x10;
              --avail_in;
              ++next_in;
              n0x10 += 8;
              n35615 += v28;
              avail_in_1 = avail_in;
              n35615_1 = n35615;
              Src = next_in;
            }
            while ( n0x10 < 0x10 );
            flags = (int)flags_1;
          }
          v29 = *(_DWORD *)(flags + 32);
          *(_DWORD *)(flags + 64) = n35615;
          if ( v29 )
            *(_DWORD *)(v29 + 20) = n35615;
          if ( (*(_DWORD *)(flags + 16) & 0x200) != 0 )
          {
            v30 = *(_DWORD *)(flags + 24);
            LOWORD(n35615_2) = n35615;
            v31 = Phyre_ZlibCRC32(v30, &n35615_2, 2u);
            flags = (int)flags_1;
            flags_1[6] = v31;
          }
          n0x10 = 0;
          n35615_1 = 0;
          n0x10_1 = 0;
        }
        else
        {
          v32 = *(_DWORD *)(flags + 32);
          if ( v32 )
            *(_DWORD *)(v32 + 16) = 0;
        }
        *(_DWORD *)flags = 5;
LABEL_75:
        if ( (*(_DWORD *)(flags + 16) & 0x400) != 0 )
        {
          avail_in_3 = *(_DWORD *)(flags + 64);
          if ( avail_in_3 > avail_in )
            avail_in_3 = avail_in;
          avail_in_4 = avail_in_3;
          if ( avail_in_3 )
          {
            v34 = *(_DWORD **)(flags + 32);
            if ( v34 )
            {
              v167 = v34[4];
              next_in = (unsigned char *)Src;
              if ( v167 )
              {
                v157 = (int *)(v34[5] - *(_DWORD *)(flags + 64));
                v35 = v34[6];
                if ( (unsigned int)v157 + avail_in_3 <= v35 )
                  avail_in_5 = avail_in_3;
                else
                  avail_in_5 = v35 - (_DWORD)v157;
                memcpy((char *)v157 + v167, Src, avail_in_5);
                flags = (int)flags_1;
                avail_in_3 = avail_in_4;
              }
            }
            if ( (*(_DWORD *)(flags + 16) & 0x200) != 0 )
            {
              if ( next_in )
              {
                v37 = Phyre_ZlibCRC32(*(_DWORD *)(flags + 24), next_in, avail_in_3);
                flags = (int)flags_1;
              }
              else
              {
                v37 = 0;
              }
              *(_DWORD *)(flags + 24) = v37;
            }
            avail_in -= avail_in_4;
            next_in += avail_in_4;
            *(_DWORD *)(flags + 64) -= avail_in_4;
            avail_in_1 = avail_in;
            Src = next_in;
          }
          if ( *(_DWORD *)(flags + 64) )
            goto LABEL_331;
        }
        *(_DWORD *)(flags + 64) = 0;
        *(_DWORD *)flags = 6;
LABEL_93:
        if ( (*(_DWORD *)(flags + 16) & 0x800) != 0 )
        {
          if ( !avail_in )
            goto LABEL_331;
          avail_in_6 = 0;
          do
          {
            v158 = (int *)next_in[avail_in_6];
            v39 = *(_DWORD *)(flags + 32);
            ++avail_in_6;
            if ( v39 )
            {
              if ( *(_DWORD *)(v39 + 28) )
              {
                v40 = *(_DWORD *)(flags + 64);
                if ( v40 < *(_DWORD *)(v39 + 32) )
                {
                  *(_BYTE *)(*(_DWORD *)(v39 + 28) + v40) = (_BYTE)v158;
                  ++*(_DWORD *)(flags + 64);
                  avail_in = avail_in_1;
                }
              }
            }
            v41 = v158;
          }
          while ( v158 && avail_in_6 < avail_in );
          n0x10 = n0x10_1;
          avail_in_7 = (int *)avail_in_6;
          if ( (*(_DWORD *)(flags + 16) & 0x200) != 0 )
          {
            if ( next_in )
            {
              v42 = Phyre_ZlibCRC32(*(_DWORD *)(flags + 24), next_in, avail_in_6);
              flags = (int)flags_1;
              avail_in_6 = (unsigned int)avail_in_7;
              v168 = v42;
              v41 = v158;
            }
            else
            {
              v168 = 0;
            }
            *(_DWORD *)(flags + 24) = v168;
            avail_in = avail_in_1;
          }
          avail_in -= avail_in_6;
          next_in += avail_in_6;
          avail_in_1 = avail_in;
          Src = next_in;
          if ( v41 )
            goto LABEL_331;
        }
        else
        {
          v43 = *(_DWORD *)(flags + 32);
          if ( v43 )
            *(_DWORD *)(v43 + 28) = 0;
        }
        *(_DWORD *)(flags + 64) = 0;
        *(_DWORD *)flags = 7;
LABEL_112:
        if ( (*(_DWORD *)(flags + 16) & 0x1000) != 0 )
        {
          if ( !avail_in )
            goto LABEL_331;
          avail_in_8 = 0;
          do
          {
            v159 = (int *)next_in[avail_in_8];
            v45 = *(_DWORD *)(flags + 32);
            ++avail_in_8;
            if ( v45 )
            {
              if ( *(_DWORD *)(v45 + 36) )
              {
                v46 = *(_DWORD *)(flags + 64);
                if ( v46 < *(_DWORD *)(v45 + 40) )
                {
                  *(_BYTE *)(*(_DWORD *)(v45 + 36) + v46) = (_BYTE)v159;
                  ++*(_DWORD *)(flags + 64);
                  avail_in = avail_in_1;
                }
              }
            }
            v47 = v159;
          }
          while ( v159 && avail_in_8 < avail_in );
          n0x10 = n0x10_1;
          avail_in_9 = (int *)avail_in_8;
          if ( (*(_DWORD *)(flags + 16) & 0x200) != 0 )
          {
            if ( next_in )
            {
              v48 = Phyre_ZlibCRC32(*(_DWORD *)(flags + 24), next_in, avail_in_8);
              flags = (int)flags_1;
              avail_in_8 = (unsigned int)avail_in_9;
              v169 = v48;
              v47 = v159;
            }
            else
            {
              v169 = 0;
            }
            *(_DWORD *)(flags + 24) = v169;
            avail_in = avail_in_1;
          }
          avail_in -= avail_in_8;
          next_in += avail_in_8;
          avail_in_1 = avail_in;
          Src = next_in;
          if ( v47 )
            goto LABEL_331;
        }
        else
        {
          v49 = *(_DWORD *)(flags + 32);
          if ( v49 )
            *(_DWORD *)(v49 + 36) = 0;
        }
        n35615 = n35615_1;
        *(_DWORD *)flags = 8;
LABEL_131:
        if ( (*(_DWORD *)(flags + 16) & 0x200) != 0 )
        {
          if ( n0x10 < 0x10 )
          {
            do
            {
              if ( !avail_in )
                goto LABEL_331;
              v50 = *next_in << n0x10;
              n0x10 += 8;
              --avail_in;
              ++next_in;
              n35615 += v50;
              avail_in_1 = avail_in;
              n35615_1 = n35615;
              Src = next_in;
              n0x10_1 = n0x10;
            }
            while ( n0x10 < 0x10 );
            flags = (int)flags_1;
          }
          if ( n35615 != *(unsigned short *)(flags + 24) )
          {
            *(_DWORD *)(this_1 + 24) = "header crc mismatch";
            goto LABEL_323;
          }
          n0x10 = 0;
          n35615_1 = 0;
          n0x10_1 = 0;
        }
        v51 = *(_DWORD *)(flags + 32);
        if ( v51 )
        {
          *(_DWORD *)(v51 + 44) = (*(int *)(flags + 16) >> 9) & 1;
          *(_DWORD *)(*(_DWORD *)(flags + 32) + 48) = 1;
        }
        v52 = Phyre_ZlibCRC32_Safe(0, 0, 0);
        flags = (int)flags_1;
        *(_DWORD *)(this_1 + 48) = v52;
        n35615 = n35615_1;
        *(_DWORD *)(flags + 24) = v52;
        *(_DWORD *)flags = 11;
        goto LABEL_324;
      case 2:
        if ( n0x10 < 0x20 )
          goto LABEL_45;
        goto LABEL_48;
      case 3:
        if ( n0x10 < 0x10 )
          goto LABEL_54;
        goto LABEL_57;
      case 4:
        goto LABEL_62;
      case 5:
        goto LABEL_75;
      case 6:
        goto LABEL_93;
      case 7:
        goto LABEL_112;
      case 8:
        goto LABEL_131;
      case 9:
        if ( n0x10 >= 0x20 )
          goto LABEL_145;
        do
        {
          if ( !avail_in )
            goto LABEL_331;
          v53 = *next_in << n0x10;
          --avail_in;
          ++next_in;
          n0x10 += 8;
          n35615 += v53;
          avail_in_1 = avail_in;
          n35615_1 = n35615;
          Src = next_in;
        }
        while ( n0x10 < 0x20 );
LABEL_145:
        flags = (int)flags_1;
        v54 = HIBYTE(n35615) + (((n35615 << 16) + (n35615 & 0xFF00)) << 8) + ((n35615 >> 8) & 0xFF00);
        this_2 = this_1;
        flags_1[6] = v54;
        *(_DWORD *)(this_2 + 48) = v54;
        n35615 = 0;
        n35615_1 = 0;
        n0x10 = 0;
        *(_DWORD *)flags = 10;
LABEL_146:
        if ( !*(_DWORD *)(flags + 12) )
        {
          this_3 = (unsigned char **)this_1;
          *(_DWORD *)(this_1 + 12) = next_out_1;
          this_3[4] = (unsigned char *)Size;
          flags_2 = flags_1;
          this_3[1] = (unsigned char *)avail_in;
          flags_2[15] = n0x10;
          *this_3 = next_in;
          flags_2[14] = n35615;
          return 2;
        }
        v56 = Phyre_ZlibInflate_Adler32(0, 0, 0);
        flags = (int)flags_1;
        *(_DWORD *)(this_1 + 48) = v56;
        n35615 = n35615_1;
        *(_DWORD *)(flags + 24) = v56;
        *(_DWORD *)flags = 11;
LABEL_148:
        if ( *(_DWORD *)(flags + 4) )
        {
          v57 = n0x10 & 7;
          n35615 >>= v57;
          n0x10 -= v57;
          flags = (int)flags_1;
          n0x10_1 = n0x10;
          n35615_1 = n35615;
          *flags_1 = 26;
        }
        else
        {
          if ( n0x10 < 3 )
          {
            do
            {
              if ( !avail_in )
                goto LABEL_331;
              v58 = *next_in << n0x10;
              --avail_in;
              ++next_in;
              n0x10 += 8;
              n35615 += v58;
              avail_in_1 = avail_in;
              n35615_1 = n35615;
              Src = next_in;
            }
            while ( n0x10 < 3 );
            flags = (int)flags_1;
          }
          v59 = n35615 & 1;
          v60 = n35615 >> 1;
          *(_DWORD *)(flags + 4) = v59;
          switch ( v60 & 3 )
          {
            case 0u:
              n35615 = v60 >> 2;
              n0x10 -= 3;
              *(_DWORD *)flags = 13;
              n35615_1 = n35615;
              n0x10_1 = n0x10;
              break;
            case 1u:
              Phyre_ZlibInflate_InitFixedTables((_DWORD *)flags);
              n35615 = v61 >> 2;
              n0x10 -= 3;
              *(_DWORD *)flags = 19;
              n35615_1 = n35615;
              n0x10_1 = n0x10;
              break;
            case 2u:
              n35615 = v60 >> 2;
              n0x10 -= 3;
              *(_DWORD *)flags = 16;
              n35615_1 = n35615;
              n0x10_1 = n0x10;
              break;
            case 3u:
              this_4 = this_1;
              *(_DWORD *)flags = 29;
              *(_DWORD *)(this_4 + 24) = "invalid block type";
              goto LABEL_159;
            default:
LABEL_159:
              n35615 = v60 >> 2;
              n0x10 -= 3;
              n35615_1 = n35615;
              n0x10_1 = n0x10;
              break;
          }
        }
        goto LABEL_324;
      case 10:
        goto LABEL_146;
      case 11:
      case 12:
        goto LABEL_148;
      case 13:
        v63 = n0x10 & 7;
        n35615 >>= v63;
        n0x10 -= v63;
        n0x10_1 = n0x10;
        n35615_1 = n35615;
        if ( n0x10 >= 0x20 )
          goto LABEL_163;
        do
        {
          if ( !avail_in )
            goto LABEL_331;
          v64 = *next_in << n0x10;
          n0x10 += 8;
          --avail_in;
          ++next_in;
          n35615 += v64;
          avail_in_1 = avail_in;
          n35615_1 = n35615;
          Src = next_in;
          n0x10_1 = n0x10;
        }
        while ( n0x10 < 0x20 );
LABEL_163:
        v146 = (int *)(unsigned short)n35615;
        flags = (int)flags_1;
        if ( (unsigned short)n35615 != ~n35615 >> 16 )
        {
          *(_DWORD *)(this_1 + 24) = "invalid stored block lengths";
          goto LABEL_323;
        }
        n35615 = 0;
        n0x10 = 0;
        flags_1[16] = v146;
        n35615_1 = 0;
        n0x10_1 = 0;
        *(_DWORD *)flags = 14;
LABEL_166:
        *(_DWORD *)flags = 15;
LABEL_167:
        avail_in_10 = *(_DWORD *)(flags + 64);
        if ( !avail_in_10 )
          goto LABEL_249;
        if ( avail_in_10 > avail_in )
          avail_in_10 = avail_in;
        if ( avail_in_10 > Size )
          avail_in_10 = Size;
        avail_in_11 = avail_in_10;
        if ( !avail_in_10 )
          goto LABEL_331;
        memcpy(next_out_1, next_in, avail_in_10);
        flags = (int)flags_1;
        Size -= avail_in_11;
        next_out_1 += avail_in_11;
        n35615 = n35615_1;
        avail_in -= avail_in_11;
        next_in += avail_in_11;
        flags_1[16] -= avail_in_11;
        avail_in_1 = avail_in;
        Src = next_in;
        goto LABEL_324;
      case 14:
        goto LABEL_166;
      case 15:
        goto LABEL_167;
      case 16:
        if ( n0x10 >= 0xE )
          goto LABEL_178;
        do
        {
          if ( !avail_in )
            goto LABEL_331;
          v66 = *next_in << n0x10;
          --avail_in;
          ++next_in;
          n0x10 += 8;
          n35615 += v66;
          avail_in_1 = avail_in;
          n35615_1 = n35615;
          Src = next_in;
        }
        while ( n0x10 < 0xE );
        flags = (int)flags_1;
LABEL_178:
        *(_DWORD *)(flags + 96) = (n35615 & 0x1F) + 257;
        v67 = n35615 >> 5;
        v68 = (v67 & 0x1F) + 1;
        v67 >>= 5;
        *(_DWORD *)(flags + 100) = v68;
        v69 = (v67 & 0xF) + 4;
        n35615 = v67 >> 4;
        n0x10 -= 14;
        v70 = *(_DWORD *)(flags + 96) <= 0x11Eu;
        *(_DWORD *)(flags + 92) = v69;
        n35615_1 = n35615;
        n0x10_1 = n0x10;
        if ( !v70 || *(_DWORD *)(flags + 100) > 0x1Eu )
        {
          *(_DWORD *)(this_1 + 24) = "too many length or distance symbols";
          goto LABEL_323;
        }
        *(_DWORD *)(flags + 104) = 0;
        *(_DWORD *)flags = 17;
LABEL_181:
        if ( *(_DWORD *)(flags + 104) >= *(_DWORD *)(flags + 92) )
          goto LABEL_186;
        do
        {
          for ( ; n0x10 < 3; Src = next_in )
          {
            if ( !avail_in )
              goto LABEL_331;
            v71 = *next_in << n0x10;
            --avail_in;
            ++next_in;
            n0x10 += 8;
            n35615 += v71;
            avail_in_1 = avail_in;
            n35615_1 = n35615;
          }
          flags_3 = flags_1;
          *((_WORD *)flags_1 + (unsigned short)FFX_Phyre_Const_B7D518[flags_1[26]] + 56) = n35615 & 7;
          flags = (int)flags_3;
          next_in = (unsigned char *)Src;
          v73 = ++*(_DWORD *)(flags + 104);
          n35615 >>= 3;
          n0x10 -= 3;
          n35615_1 = n35615;
          n0x10_1 = n0x10;
        }
        while ( v73 < *(_DWORD *)(flags + 92) );
LABEL_186:
        while ( *(_DWORD *)(flags + 104) < 0x13u )
          *(_WORD *)(flags + 2 * (unsigned short)FFX_Phyre_Const_B7D518[(*(_DWORD *)(flags + 104))++] + 112) = 0;
        *(_DWORD *)(flags + 108) = flags + 1328;
        *(_DWORD *)(flags + 76) = flags + 1328;
        v140 = flags_1 + 188;
        flags_4 = flags_1;
        *(_DWORD *)(flags + 84) = 7;
        v75 = Phyre_ZlibInflate_BuildHuffmanTables(
                0,
                (int)(flags_4 + 28),
                0x13u,
                (int *)(flags + 108),
                (unsigned int *)(flags + 84),
                v140);
        flags = (int)flags_1;
        n35615 = n35615_1;
        v166 = v75;
        if ( v75 )
        {
          *(_DWORD *)(this_1 + 24) = "invalid code lengths set";
          goto LABEL_323;
        }
        flags_1[26] = 0;
        *(_DWORD *)flags = 18;
LABEL_192:
        next_in = (unsigned char *)Src;
        v170 = *(_DWORD *)(flags + 104);
        if ( v170 >= *(_DWORD *)(flags + 96) + *(_DWORD *)(flags + 100) )
        {
LABEL_222:
          if ( *(_DWORD *)flags != 29 )
          {
            if ( !*(_WORD *)(flags + 624) )
            {
              *(_DWORD *)(this_1 + 24) = "invalid code -- missing end-of-block";
              goto LABEL_323;
            }
            *(_DWORD *)(flags + 108) = flags + 1328;
            *(_DWORD *)(flags + 76) = flags + 1328;
            n19 = *(_DWORD *)(flags + 96);
            v151 = (int *)(flags + 108);
            *(_DWORD *)(flags + 84) = 9;
            v161 = (int *)(flags + 752);
            v88 = Phyre_ZlibInflate_BuildHuffmanTables(
                    1,
                    flags + 112,
                    n19,
                    (int *)(flags + 108),
                    (unsigned int *)(flags + 84),
                    (int *)(flags + 752));
            next_in = (unsigned char *)Src;
            flags = (int)flags_1;
            v166 = v88;
            if ( v88 )
            {
              n35615 = n35615_1;
              *(_DWORD *)(this_1 + 24) = "invalid literal/lengths set";
LABEL_323:
              *(_DWORD *)flags = 29;
              goto LABEL_324;
            }
            flags_1[20] = *v151;
            n19_1 = *(_DWORD *)(flags + 100);
            *(_DWORD *)(flags + 88) = 6;
            v89 = Phyre_ZlibInflate_BuildHuffmanTables(
                    2,
                    flags + 112 + 2 * *(_DWORD *)(flags + 96),
                    n19_1,
                    v151,
                    (unsigned int *)(flags + 88),
                    v161);
            flags = (int)flags_1;
            n35615 = n35615_1;
            v166 = v89;
            if ( v89 )
            {
              *(_DWORD *)(this_1 + 24) = "invalid distances set";
              goto LABEL_323;
            }
            *flags_1 = 19;
ImpAkagiSphere09:
            *(_DWORD *)flags = 20;
AlbhedDic05:
            if ( avail_in >= 6 && Size >= 0x102 )
            {
              this_5 = this_1;
              *(_DWORD *)(this_1 + 12) = next_out_1;
              *(_DWORD *)(this_5 + 16) = Size;
              Src_1 = Src;
              *(_DWORD *)(flags + 56) = n35615;
              *(_DWORD *)(flags + 60) = n0x10;
              *(_DWORD *)this_5 = Src_1;
              *(_DWORD *)(this_5 + 4) = avail_in;
              Phyre_ZlibInflate_InflateBlock((unsigned char **)this_5, next_out);
              next_in = *(unsigned char **)this_1;
              avail_in = *(_DWORD *)(this_1 + 4);
              next_out_1 = *(unsigned char **)(this_1 + 12);
              Size = *(_DWORD *)(this_1 + 16);
              flags = (int)flags_1;
              Src = next_in;
              v13 = *flags_1 == 11;
              n35615 = flags_1[14];
              n0x10 = flags_1[15];
              avail_in_1 = avail_in;
              n35615_1 = n35615;
              n0x10_1 = n0x10;
              if ( v13 )
                flags_1[1777] = -1;
              goto LABEL_324;
            }
            *(_DWORD *)(flags + 7108) = 0;
            v162 = (1 << *(_DWORD *)(flags + 84)) - 1;
            v152 = (int *)flags_1[19];
            v92 = v152[n35615 & v162];
            if ( BYTE1(v92) > n0x10 )
            {
              while ( avail_in )
              {
                v93 = *next_in << n0x10;
                --avail_in;
                ++next_in;
                n35615 += v93;
                n0x10 += 8;
                v92 = v152[n35615 & v162];
                avail_in_1 = avail_in;
                n35615_1 = n35615;
                Src = next_in;
                if ( BYTE1(v92) <= n0x10 )
                  goto LABEL_239;
              }
              goto LABEL_331;
            }
LABEL_239:
            if ( (_BYTE)v92 && (v92 & 0xF0) == 0 )
            {
              v171 = v92 >> 8;
              v94 = v92;
              v92 = v152[HIWORD(v92) + ((n35615_1 & ((1 << (BYTE1(v92) + v92)) - 1)) >> SBYTE1(v92))];
              if ( (unsigned char)v171 + (unsigned int)BYTE1(v92) > n0x10 )
              {
                do
                {
                  avail_in_12 = avail_in_1;
                  if ( !avail_in_1 )
                    goto LABEL_332;
                  --avail_in_1;
                  v96 = *(unsigned char *)Src << n0x10;
                  Src = (char *)Src + 1;
                  n35615_1 += v96;
                  n0x10 += 8;
                  v92 = v152[HIWORD(v94) + ((n35615_1 & ((1 << (BYTE1(v94) + v94)) - 1)) >> SBYTE1(v94))];
                }
                while ( BYTE1(v94) + (unsigned int)BYTE1(v92) > n0x10 );
              }
              n35615 = n35615_1 >> SBYTE1(v94);
              flags_1[1777] = BYTE1(v94);
              avail_in = avail_in_1;
              n0x10 -= BYTE1(v94);
            }
            flags_5 = flags_1;
            flags_1[1777] += BYTE1(v92);
            n35615 >>= SBYTE1(v92);
            n0x10 -= BYTE1(v92);
            flags_5[16] = HIWORD(v92);
            next_in = (unsigned char *)Src;
            flags = (int)flags_1;
            n35615_1 = n35615;
            n0x10_1 = n0x10;
            if ( (_BYTE)v92 )
            {
              if ( (v92 & 0x20) != 0 )
              {
                flags_1[1777] = -1;
LABEL_249:
                *(_DWORD *)flags = 11;
                goto LABEL_324;
              }
              if ( (v92 & 0x40) != 0 )
              {
                *(_DWORD *)(this_1 + 24) = "invalid literal/length code";
              }
              else
              {
                flags_1[18] = v92 & 0xF;
                *(_DWORD *)flags = 21;
LABEL_253:
                n0x10_3 = *(int **)(flags + 72);
                n0x10_2 = n0x10_3;
                if ( n0x10_3 )
                {
                  if ( n0x10 < (unsigned int)n0x10_3 )
                  {
                    while ( avail_in )
                    {
                      v99 = *next_in << n0x10;
                      --avail_in;
                      ++next_in;
                      n0x10 += 8;
                      n35615 += v99;
                      avail_in_1 = avail_in;
                      n35615_1 = n35615;
                      Src = next_in;
                      if ( n0x10 >= (unsigned int)n0x10_2 )
                        goto LABEL_257;
                    }
                    goto LABEL_331;
                  }
LABEL_257:
                  flags_1[16] += n35615 & ((1 << (char)n0x10_2) - 1);
                  n35615 >>= (char)n0x10_2;
                  flags = (int)flags_1;
                  n0x10 -= (unsigned int)n0x10_2;
                  flags_1[1777] += n0x10_2;
                  n35615_1 = n35615;
                }
                *(_DWORD *)(flags + 7112) = *(_DWORD *)(flags + 64);
                *(_DWORD *)flags = 22;
LABEL_259:
                v163 = (1 << *(_DWORD *)(flags + 88)) - 1;
                v154 = (int *)flags_1[20];
                v100 = v154[n35615 & v163];
                if ( BYTE1(v100) > n0x10 )
                {
                  while ( avail_in )
                  {
                    v101 = *next_in << n0x10;
                    --avail_in;
                    ++next_in;
                    n35615 += v101;
                    n0x10 += 8;
                    v100 = v154[n35615 & v163];
                    avail_in_1 = avail_in;
                    n35615_1 = n35615;
                    Src = next_in;
                    if ( BYTE1(v100) <= n0x10 )
                      goto LABEL_262;
                  }
                  goto LABEL_331;
                }
LABEL_262:
                if ( (v100 & 0xF0) != 0 )
                {
                  flags_6 = flags_1;
                }
                else
                {
                  v172 = v100 >> 8;
                  v165 = HIWORD(v100);
                  v102 = v100;
                  v100 = v154[HIWORD(v100) + ((n35615_1 & ((1 << (BYTE1(v100) + v100)) - 1)) >> SBYTE1(v100))];
                  if ( (unsigned char)v172 + (unsigned int)BYTE1(v100) > n0x10 )
                  {
                    do
                    {
                      avail_in_12 = avail_in_1;
                      if ( !avail_in_1 )
                        goto LABEL_332;
                      --avail_in_1;
                      v103 = *(unsigned char *)Src << n0x10;
                      Src = (char *)Src + 1;
                      n35615_1 += v103;
                      n0x10 += 8;
                      v100 = v154[v165 + ((n35615_1 & ((1 << (HIBYTE(v102) + v102)) - 1)) >> SHIBYTE(v102))];
                    }
                    while ( HIBYTE(v102) + (unsigned int)BYTE1(v100) > n0x10 );
                  }
                  flags_6 = flags_1;
                  v105 = HIBYTE(v102);
                  n35615 = n35615_1 >> SHIBYTE(v102);
                  n0x10 -= v105;
                  flags_1[1777] += v105;
                }
                next_in = (unsigned char *)Src;
                flags_6[1777] += BYTE1(v100);
                n35615 >>= SBYTE1(v100);
                n0x10 -= BYTE1(v100);
                n0x10_1 = n0x10;
                n35615_1 = n35615;
                if ( (v100 & 0x40) != 0 )
                {
                  flags = (int)flags_1;
                  avail_in = avail_in_1;
                  *(_DWORD *)(this_1 + 24) = "invalid distance code";
                }
                else
                {
                  flags_6[17] = HIWORD(v100);
                  flags = (int)flags_1;
                  avail_in = avail_in_1;
                  flags_1[18] = v100 & 0xF;
                  *(_DWORD *)flags = 23;
LABEL_271:
                  n0x10_5 = *(int **)(flags + 72);
                  n0x10_4 = n0x10_5;
                  if ( n0x10_5 )
                  {
                    if ( n0x10 < (unsigned int)n0x10_5 )
                    {
                      while ( avail_in )
                      {
                        v107 = *next_in << n0x10;
                        --avail_in;
                        ++next_in;
                        n0x10 += 8;
                        n35615 += v107;
                        avail_in_1 = avail_in;
                        n35615_1 = n35615;
                        Src = next_in;
                        if ( n0x10 >= (unsigned int)n0x10_4 )
                          goto LABEL_275;
                      }
                      goto LABEL_331;
                    }
LABEL_275:
                    flags_1[17] += n35615 & ((1 << (char)n0x10_4) - 1);
                    n35615 >>= (char)n0x10_4;
                    flags = (int)flags_1;
                    n0x10 -= (unsigned int)n0x10_4;
                    flags_1[1777] += n0x10_4;
                    n35615_1 = n35615;
                    n0x10_1 = n0x10;
                  }
                  *(_DWORD *)flags = 24;
LABEL_277:
                  if ( !Size )
                    goto LABEL_331;
                  v108 = *(_DWORD *)(flags + 68);
                  if ( v108 <= next_out - Size )
                  {
                    v173 = (int)&next_out_1[-v108];
                    Size_2 = *(_DWORD *)(flags + 64);
                    Size_5 = (int *)Size_2;
LABEL_288:
                    Size_1 = Size;
                    if ( Size_2 > Size )
                      Size_2 = Size;
                    *(_DWORD *)(flags + 64) = (char *)Size_5 - Size_2;
                    Size = Size_1 - Size_2;
                    next_out_2 = next_out_1;
                    Size_3 = Size_2;
                    do
                    {
                      *next_out_2 = next_out_2[v173 - (_DWORD)next_out_1];
                      ++next_out_2;
                      --Size_3;
                    }
                    while ( Size_3 );
                    avail_in = avail_in_1;
                    next_in = (unsigned char *)Src;
                    next_out_1 = next_out_2;
                    n35615 = n35615_1;
                    if ( !*(_DWORD *)(flags + 64) )
                      *(_DWORD *)flags = 20;
                    goto LABEL_324;
                  }
                  Size_2 = v108 - (next_out - Size);
                  if ( Size_2 <= *(_DWORD *)(flags + 44) || !*(_DWORD *)(flags + 7104) )
                  {
                    Size_4 = *(_DWORD *)(flags + 48);
                    v111 = *(_DWORD *)(flags + 52);
                    if ( Size_2 <= Size_4 )
                    {
                      v112 = Size_4 + v111 - Size_2;
                    }
                    else
                    {
                      Size_2 -= Size_4;
                      v112 = *(_DWORD *)(flags + 40) + v111 - Size_2;
                    }
                    v173 = v112;
                    Size_5 = *(int **)(flags + 64);
                    if ( Size_2 > (unsigned int)Size_5 )
                      Size_2 = *(_DWORD *)(flags + 64);
                    goto LABEL_288;
                  }
                  *(_DWORD *)(this_1 + 24) = "invalid distance too far back";
                }
              }
              goto LABEL_323;
            }
            *flags_1 = 25;
          }
LABEL_324:
          v6 = *(_DWORD *)flags;
          if ( *(_DWORD *)flags > 0x1Eu )
            return -2;
          continue;
        }
        while ( 1 )
        {
          n0x10_1 = (1 << *(_DWORD *)(flags + 84)) - 1;
          v148 = (int *)flags_1[19];
          v76 = v148[n35615 & n0x10_1];
          n17 = HIWORD(v76);
          if ( BYTE1(v76) > n0x10 )
            break;
LABEL_196:
          if ( HIWORD(v76) < 0x10u )
          {
            n35615 >>= SBYTE1(v76);
            n0x10 -= BYTE1(v76);
            flags = (int)flags_1;
            n0x10_1 = n0x10;
            *((_WORD *)flags_1 + v170 + 56) = HIWORD(v76);
            ++*(_DWORD *)(flags + 104);
            n35615_1 = n35615;
LABEL_220:
            next_in = (unsigned char *)Src;
            goto LABEL_221;
          }
          if ( HIWORD(v76) == 16 )
          {
            n0x10_6 = (int *)(BYTE1(v76) + 2);
            if ( n0x10 < (unsigned int)n0x10_6 )
            {
              do
              {
                if ( !avail_in )
                  goto LABEL_331;
                v78 = *next_in << n0x10;
                --avail_in;
                ++next_in;
                n0x10 += 8;
                n35615_1 += v78;
                avail_in_1 = avail_in;
                Src = next_in;
              }
              while ( n0x10 < (unsigned int)n0x10_6 );
              n35615 = n35615_1;
            }
            n35615 >>= SBYTE1(v76);
            n0x10 -= BYTE1(v76);
            flags = (int)flags_1;
            n0x10_1 = n0x10;
            n35615_1 = n35615;
            if ( !v170 )
            {
LABEL_225:
              *(_DWORD *)(this_1 + 24) = "invalid bit length repeat";
              goto LABEL_323;
            }
            v79 = (n35615 & 3) + 3;
            n35615 >>= 2;
            v150 = *((_WORD *)flags_1 + v170 + 55);
            n0x10 -= 2;
          }
          else
          {
            n0x10_7 = BYTE1(v76);
            if ( n17 == 17 )
            {
              n0x10_1 = BYTE1(v76);
              if ( n0x10 < (unsigned int)BYTE1(v76) + 3 )
              {
                while ( avail_in )
                {
                  v81 = *next_in << n0x10;
                  n0x10_7 = n0x10_1;
                  --avail_in;
                  ++next_in;
                  n35615 += v81;
                  n0x10 += 8;
                  avail_in_1 = avail_in;
                  n35615_1 = n35615;
                  Src = next_in;
                  if ( n0x10 >= n0x10_1 + 3 )
                    goto LABEL_209;
                }
                goto LABEL_331;
              }
LABEL_209:
              v82 = n35615 >> n0x10_7;
              v79 = (v82 & 7) + 3;
              n35615 = v82 >> 3;
              v83 = -3 - n0x10_1;
            }
            else
            {
              n0x10_1 = BYTE1(v76);
              if ( n0x10 < (unsigned int)BYTE1(v76) + 7 )
              {
                while ( avail_in )
                {
                  v84 = *next_in << n0x10;
                  n0x10_7 = n0x10_1;
                  --avail_in;
                  ++next_in;
                  n35615 += v84;
                  n0x10 += 8;
                  avail_in_1 = avail_in;
                  n35615_1 = n35615;
                  Src = next_in;
                  if ( n0x10 >= n0x10_1 + 7 )
                    goto LABEL_213;
                }
                goto LABEL_331;
              }
LABEL_213:
              v85 = n35615 >> n0x10_7;
              v79 = (v85 & 0x7F) + 11;
              n35615 = v85 >> 7;
              v83 = -7 - n0x10_1;
            }
            n0x10 += v83;
            v150 = 0;
          }
          v86 = flags_1[24] + flags_1[25];
          next_in = (unsigned char *)Src;
          v160 = (int *)v79;
          n35615_1 = n35615;
          v70 = v170 + v79 <= v86;
          flags = (int)flags_1;
          n0x10_1 = n0x10;
          if ( !v70 )
            goto LABEL_225;
          if ( v160 )
          {
            v87 = v160;
            do
            {
              *(_WORD *)(flags + 2 * (*(_DWORD *)(flags + 104))++ + 112) = v150;
              v87 = (int *)((char *)v87 - 1);
            }
            while ( v87 );
            avail_in = avail_in_1;
            goto LABEL_220;
          }
LABEL_221:
          v170 = *(_DWORD *)(flags + 104);
          if ( v170 >= *(_DWORD *)(flags + 96) + *(_DWORD *)(flags + 100) )
            goto LABEL_222;
        }
        while ( avail_in )
        {
          v77 = *next_in << n0x10;
          --avail_in;
          ++next_in;
          n35615 += v77;
          n0x10 += 8;
          v76 = v148[n35615 & n0x10_1];
          avail_in_1 = avail_in;
          n35615_1 = n35615;
          Src = next_in;
          n17 = HIWORD(v76);
          if ( BYTE1(v76) <= n0x10 )
            goto LABEL_196;
        }
LABEL_331:
        avail_in_12 = avail_in_1;
LABEL_332:
        this_6 = (_DWORD *)this_1;
        flags_7 = flags_1;
        v13 = flags_1[10] == 0;
        *(_DWORD *)(this_1 + 16) = Size;
        Src_2 = Src;
        this_6[1] = avail_in_12;
        n35615_3 = n35615_1;
        flags_7[15] = n0x10;
        this_6[3] = next_out_1;
        *this_6 = Src_2;
        flags_7[14] = n35615_3;
        if ( v13 && (next_out == Size || *flags_7 > 25)
          || !Phyre_ZlibInflate_ProcessBlock((int)this_6, (int)next_out_1, next_out - Size) )
        {
          n0x20 = next_out - this_6[4];
          v131 = avail_in_2 - this_6[1];
          this_6[5] += n0x20;
          this_6[2] += v131;
          flags_7[7] += n0x20;
          if ( flags_7[2] && n0x20 )
          {
            v132 = this_6[3];
            if ( flags_7[4] )
            {
              v133 = (_DWORD *)(v132 - n0x20);
              if ( v133 )
                v134 = Phyre_ZlibCRC32(flags_7[6], v133, n0x20);
              else
                v134 = 0;
            }
            else
            {
              v134 = Phyre_ZlibInflate_Adler32(flags_7[6], (unsigned char *)(v132 - n0x20), n0x20);
            }
            flags_7[6] = v134;
            this_6[12] = v134;
          }
          n14 = *flags_7;
          if ( *flags_7 == 19 || n14 == 14 )
            n256 = 256;
          else
            n256 = 0;
          n128 = 0;
          v13 = n14 == 11;
          result = v166;
          if ( v13 )
            n128 = 128;
          this_6[11] = flags_7[15] + n256 + (flags_7[1] != 0 ? 0x40 : 0) + n128;
          if ( !v166 )
            return -5;
        }
        else
        {
          *flags_7 = 30;
          return -4;
        }
        return result;
      case 17:
        goto LABEL_181;
      case 18:
        goto LABEL_192;
      case 19:
        goto ImpAkagiSphere09;
      case 20:
        goto AlbhedDic05;
      case 21:
        goto LABEL_253;
      case 22:
        goto LABEL_259;
      case 23:
        goto LABEL_271;
      case 24:
        goto LABEL_277;
      case 25:
        if ( !Size )
          goto LABEL_331;
        next_out_3 = next_out_1;
        v117 = *(_BYTE *)(flags + 64);
        ++next_out_1;
        --Size;
        *next_out_3 = v117;
        n35615 = n35615_1;
        *(_DWORD *)flags = 20;
        goto LABEL_324;
      case 26:
        if ( !*(_DWORD *)(flags + 8) )
          goto LABEL_314;
        if ( n0x10 >= 0x20 )
          goto LABEL_301;
        do
        {
          if ( !avail_in )
            goto LABEL_331;
          v118 = *next_in << n0x10;
          n0x10 += 8;
          --avail_in;
          ++next_in;
          n35615 += v118;
          avail_in_1 = avail_in;
          n35615_1 = n35615;
          Src = next_in;
          n0x10_1 = n0x10;
        }
        while ( n0x10 < 0x20 );
        flags = (int)flags_1;
LABEL_301:
        next_outa = next_out - Size;
        *(_DWORD *)(this_1 + 20) += next_outa;
        *(_DWORD *)(flags + 28) += next_outa;
        n35615 = n35615_1;
        if ( !next_outa )
          goto LABEL_309;
        if ( *(_DWORD *)(flags + 16) )
        {
          next_in = (unsigned char *)Src;
          if ( next_out_1 == (unsigned char *)next_outa )
          {
            v119 = 0;
            goto LABEL_308;
          }
          v119 = Phyre_ZlibCRC32(*(_DWORD *)(flags + 24), &next_out_1[-next_outa], next_outa);
        }
        else
        {
          v119 = Phyre_ZlibInflate_Adler32(*(_DWORD *)(flags + 24), &next_out_1[-next_outa], next_outa);
        }
        flags = (int)flags_1;
        n35615 = n35615_1;
LABEL_308:
        this_7 = this_1;
        *(_DWORD *)(flags + 24) = v119;
        *(_DWORD *)(this_7 + 48) = v119;
        avail_in = avail_in_1;
LABEL_309:
        next_out = Size;
        n35615_4 = n35615;
        if ( !*(_DWORD *)(flags + 16) )
          n35615_4 = HIBYTE(n35615) + ((n35615 >> 8) & 0xFF00) + (((n35615 << 16) + (n35615 & 0xFF00)) << 8);
        if ( n35615_4 == *(_DWORD *)(flags + 24) )
        {
          n35615 = 0;
          n0x10 = 0;
          n35615_1 = 0;
          n0x10_1 = 0;
LABEL_314:
          *(_DWORD *)flags = 27;
LABEL_315:
          if ( !*(_DWORD *)(flags + 8) || !*(_DWORD *)(flags + 16) )
            goto LABEL_328;
          if ( n0x10 < 0x20 )
          {
            do
            {
              if ( !avail_in )
                goto LABEL_331;
              v122 = *next_in << n0x10;
              n0x10 += 8;
              --avail_in;
              ++next_in;
              n35615 += v122;
              avail_in_1 = avail_in;
              n35615_1 = n35615;
              Src = next_in;
              n0x10_1 = n0x10;
            }
            while ( n0x10 < 0x20 );
            flags = (int)flags_1;
          }
          if ( n35615 == *(_DWORD *)(flags + 28) )
          {
            n35615_1 = 0;
            n0x10 = 0;
LABEL_328:
            *(_DWORD *)flags = 28;
LABEL_329:
            v166 = 1;
            goto LABEL_331;
          }
          *(_DWORD *)(this_1 + 24) = "incorrect length check";
        }
        else
        {
          *(_DWORD *)(this_1 + 24) = "incorrect data check";
        }
        goto LABEL_323;
      case 27:
        goto LABEL_315;
      case 28:
        goto LABEL_329;
      case 29:
        v166 = -3;
        goto LABEL_331;
      case 30:
        return -4;
      default:
        return -2;
    }
  }
}
