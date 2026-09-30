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

extern _DWORD FFX_Video_ReconstructBorder();
extern _DWORD FFX_VpxThreadWorker_ProcessMBRow();
extern _DWORD ReleaseSemaphore();
extern _DWORD Sleep();
// Function: ThreadPool_WorkerProc
// Address: 0x40B5B0
// Size: 0xD02
// ThreadPool: Worker proc — thread pool worker thread main loop
int __fastcall ThreadPool_WorkerProc(_DWORD *self, _DWORD *a2, int a3)
{
  _DWORD *v3; // esi
  _DWORD *this_1; // ebx
  int v5; // ecx
  _DWORD *v6; // edx
  int v7; // edi
  _DWORD *v8; // ecx
  int v9; // eax
  _DWORD *v10; // ecx
  int v11; // eax
  int v12; // edx
  int v13; // ecx
  int v14; // edi
  int v15; // eax
  int v16; // edx
  int v17; // ecx
  int v18; // edx
  _BYTE *v19; // edi
  int n16; // ecx
  int v21; // eax
  int v22; // edx
  int v23; // edi
  int v24; // edx
  int v25; // ecx
  int v26; // eax
  int v27; // ecx
  int v28; // ecx
  int v29; // eax
  int n32_1; // eax
  BOOL v31; // eax
  unsigned char *v32; // eax
  unsigned char n9; // dl
  _QWORD *v34; // eax
  _QWORD *v35; // eoff
  int v36; // ecx
  int v37; // edx
  int v38; // ecx
  int v39; // edx
  int v40; // ecx
  int n16_2; // edi
  int v42; // edx
  int v43; // ecx
  int v44; // edx
  int v45; // ecx
  int v46; // edi
  int v47; // ecx
  int v48; // ecx
  int v49; // ecx
  int v50; // ecx
  int v51; // ecx
  int v52; // ecx
  int v53; // ecx
  int v54; // ecx
  int v55; // ecx
  int v56; // ecx
  int v57; // ecx
  int v58; // eax
  int result; // eax
  int v60; // [esp+Ch] [ebp-CCh]
  int v61; // [esp+10h] [ebp-C8h]
  int v62; // [esp+14h] [ebp-C4h]
  int v63; // [esp+14h] [ebp-C4h]
  int v64; // [esp+18h] [ebp-C0h]
  int v65; // [esp+1Ch] [ebp-BCh]
  _BYTE *v66; // [esp+20h] [ebp-B8h]
  int v67; // [esp+20h] [ebp-B8h]
  int v68; // [esp+24h] [ebp-B4h]
  int n32; // [esp+24h] [ebp-B4h]
  int n16_1; // [esp+28h] [ebp-B0h]
  int v72; // [esp+30h] [ebp-A8h]
  int v73; // [esp+34h] [ebp-A4h]
  int v74; // [esp+34h] [ebp-A4h]
  _BYTE *v75; // [esp+38h] [ebp-A0h]
  int v76; // [esp+38h] [ebp-A0h]
  int v78; // [esp+40h] [ebp-98h]
  int v79; // [esp+44h] [ebp-94h]
  int v80; // [esp+48h] [ebp-90h]
  int v81; // [esp+4Ch] [ebp-8Ch]
  int v82; // [esp+50h] [ebp-88h]
  int v83; // [esp+54h] [ebp-84h]
  int v84; // [esp+58h] [ebp-80h]
  int *v85; // [esp+5Ch] [ebp-7Ch]
  _DWORD *v86; // [esp+60h] [ebp-78h]
  int v87; // [esp+64h] [ebp-74h]
  int v88; // [esp+68h] [ebp-70h]
  int v89; // [esp+6Ch] [ebp-6Ch]
  int *v90; // [esp+70h] [ebp-68h]
  int v91; // [esp+74h] [ebp-64h]
  int v92; // [esp+78h] [ebp-60h] BYREF
  _DWORD v93[4]; // [esp+7Ch] [ebp-5Ch] BYREF
  int v94; // [esp+8Ch] [ebp-4Ch]
  _DWORD *v95; // [esp+90h] [ebp-48h]
  _DWORD v96[12]; // [esp+94h] [ebp-44h]
  _DWORD v97[4]; // [esp+C4h] [ebp-14h]
  int v98; // [esp+E0h] [ebp+8h]

  v3 = a2;
  this_1 = self;
  v5 = *(self + 3934);
  v92 = v5 + *(self + 1615);
  v6 = (_DWORD *)*(self + 976);
  v80 = v5;
  v64 = v6[4];
  v61 = v6[9];
  v7 = 1 << *(self + 3043);
  v90 = (int *)*(self + 977);
  v96[3] = v90[13];
  v96[4] = v90[14];
  v96[5] = v90[15];
  v8 = (_DWORD *)*(self + 978);
  v97[1] = v90[25];
  v96[6] = v8[13];
  v96[7] = v8[14];
  v96[8] = v8[15];
  v9 = v8[25];
  v10 = (_DWORD *)*(self + 979);
  v97[2] = v9;
  v96[9] = v10[13];
  v96[10] = v10[14];
  v96[11] = v10[15];
  v97[3] = v10[25];
  v87 = v6[13];
  v73 = v6[14];
  v88 = v73;
  v11 = v6[15];
  v95 = v6;
  v12 = a3;
  v62 = v11;
  v89 = v11;
  v94 = v7;
  v97[0] = 0;
  v13 = a3;
  v60 = a3;
  a2[769] = a3 != 0;
  if ( a3 >= this_1[1614] )
    goto LABEL_61;
  do
  {
    v98 = v13;
    v3[798] = &this_1[7 * (v13 % v7) + 3836];
    if ( v13 <= 0 )
      v85 = &v92;
    else
      v85 = (int *)(this_1[3935] + 4 * (v13 - 1));
    v14 = 4 * v13;
    v86 = (_DWORD *)(4 * v13 + this_1[3935]);
    v79 = 16 * v64 * v13;
    v3[779] = this_1[2481];
    v15 = v3[780];
    *(_QWORD *)v15 = 0;
    *(_BYTE *)(v15 + 8) = 0;
    v3[792] = -128 * v13;
    v3[770] = 0;
    v16 = 8 * v61 * v13;
    v3[793] = (this_1[1614] - v13 - 1) << 7;
    v83 = 4 * v13;
    v81 = v16;
    if ( this_1[2468] )
    {
      v3[771] = *(_DWORD *)(this_1[3936] + 4 * v13) + 32;
      v3[772] = *(_DWORD *)(this_1[3937] + 4 * v13) + 16;
      v3[773] = *(_DWORD *)(this_1[3938] + 4 * v13) + 16;
      v3[774] = *(_DWORD *)(v14 + this_1[3939]);
      v3[775] = *(_DWORD *)(v14 + this_1[3940]);
      v3[776] = *(_DWORD *)(v14 + this_1[3941]);
      v3[777] = 1;
      v3[778] = 1;
    }
    else
    {
      v17 = v16 + v73;
      v18 = v62 + v16;
      v3[775] = v17 - 1;
      v3[772] = v17;
      v3[771] = v79 + v87;
      v3[773] = v18;
      v19 = (_BYTE *)(v79 + v87 - 1);
      v3[774] = v19;
      v75 = (_BYTE *)(v17 - 1);
      v3[776] = v18 - 1;
      v66 = (_BYTE *)(v18 - 1);
      v3[771] = v79 + v87 - v3[743];
      v3[772] = v17 - v3[748];
      n16 = 16;
      v3[773] = v18 - v3[748];
      v3[777] = v3[743];
      v3[778] = v3[748];
      v21 = v3[748];
      v22 = v3[743];
      v68 = v21;
      do
      {
        *v19 = -127;
        v19 += v22;
        --n16;
      }
      while ( n16 );
      *v75 = -127;
      v75[v21] = -127;
      v75[2 * v21] = -127;
      v23 = 3 * v21;
      v24 = 5 * v21;
      v75[v23] = -127;
      v75[4 * v21] = -127;
      v75[v24] = -127;
      v25 = 3 * v21;
      v75[2 * v25] = -127;
      v26 = 7 * v21;
      v75[v26] = -127;
      *v66 = -127;
      v66[v68] = -127;
      v66[2 * v68] = -127;
      this_1 = self;
      v66[v23] = -127;
      v66[4 * v68] = -127;
      v14 = v83;
      v66[v24] = -127;
      v66[2 * v25] = -127;
      v66[v26] = -127;
      v3 = a2;
    }
    v27 = 0;
    v65 = 0;
    if ( (int)this_1[1615] > 0 )
    {
      v3 = a2;
      v76 = v62 + v81;
      v67 = 0;
      n16_1 = 16;
      n32 = 32;
      v74 = v73 - v62;
      while ( 1 )
      {
        *v86 = v27 - 1;
        this_1 = self;
        if ( ((v80 - 1) & v27) == 0 && v27 > *v85 - v80 )
        {
          do
          {
            _mm_pause();
            Sleep(0);
          }
          while ( v65 > *v85 - v80 );
          v3 = a2;
          this_1 = self;
          v27 = v65;
        }
        v3[790] = v67;
        v3[791] = (this_1[1615] - v27 - 1) << 7;
        v3[754] = v76;
        v3[752] = v79 + v87;
        v28 = v3[766];
        v3[753] = v76 + v74;
        v3[725] = v79 + v96[3 * *(unsigned char *)(v28 + 2)];
        v3[726] = v81 + v96[3 * *(unsigned char *)(v28 + 2) + 1];
        v3[727] = v81 + v96[3 * *(unsigned char *)(v28 + 2) + 2];
        v3[799] |= v97[*(unsigned char *)(v28 + 2)];
        FFX_VpxThreadWorker_ProcessMBRow(this_1, (int)v3);
        v29 = v3[798];
        v3[770] = 1;
        n32_1 = *(_DWORD *)(v29 + 12);
        v31 = n32_1 > 32 && n32_1 < 0x40000000;
        v3[799] |= v31;
        v3[771] += 16;
        v3[772] += 8;
        v3[773] += 8;
        if ( this_1[2468] || (v3[774] += 16, v3[775] += 8, v3[776] += 8, this_1[2468]) )
        {
          v32 = (unsigned char *)v3[766];
          n9 = *v32;
          if ( *v32 == 4 || n9 == 9 || (v72 = 1, !v32[9]) )
            v72 = 0;
          v63 = *((unsigned char *)&this_1[4 * v32[11] + 2416 + v32[2]] + *((unsigned char *)this_1 + n9 + 9856));
          if ( v60 != this_1[1614] - 1 )
          {
            v34 = (_QWORD *)(n32 + *(_DWORD *)(this_1[3936] + v14 + 4));
            v35 = (_QWORD *)(v3[752] + 15 * v64);
            *v34 = *v35;
            v34[1] = v35[1];
            v36 = v3[753];
            v37 = *(_DWORD *)(this_1[3937] + 4 * v60 + 4);
            *(_DWORD *)(v37 + n16_1) = *(_DWORD *)(7 * v61 + v36);
            this_1 = self;
            *(_DWORD *)(v37 + n16_1 + 4) = *(_DWORD *)(7 * v61 + v36 + 4);
            v38 = v3[754];
            v39 = *(_DWORD *)(*(self + 3938) + 4 * v60 + 4);
            *(_DWORD *)(v39 + n16_1) = *(_DWORD *)(v38 + 7 * v61);
            v3 = a2;
            *(_DWORD *)(v39 + n16_1 + 4) = *(_DWORD *)(v38 + 7 * v61 + 4);
          }
          v40 = v65;
          if ( v65 != this_1[1615] - 1 && !*(_BYTE *)(v3[766] + 78) )
          {
            n16_2 = 0;
            v91 = 4 * v64;
            v78 = 0;
            v84 = 3 * v64;
            v82 = 2 * v64;
            do
            {
              n16_2 += 4;
              *(_BYTE *)(n16_2 + *(_DWORD *)(this_1[3939] + 4 * v60) - 4) = *(_BYTE *)(v3[752] + v78 + 15);
              *(_BYTE *)(*(_DWORD *)(this_1[3939] + 4 * v60) + n16_2 - 3) = *(_BYTE *)(v78 + v3[752] + v64 + 15);
              *(_BYTE *)(*(_DWORD *)(this_1[3939] + 4 * v60) + n16_2 - 2) = *(_BYTE *)(v3[752] + v82 + 15);
              *(_BYTE *)(*(_DWORD *)(this_1[3939] + 4 * v60) + n16_2 - 1) = *(_BYTE *)(v3[752] + v84 + 15);
              v78 += v91;
              v82 += v91;
              v84 += v91;
            }
            while ( n16_2 < 16 );
            **(_BYTE **)(v83 + this_1[3940]) = *(_BYTE *)(v3[753] + 7);
            **(_BYTE **)(v83 + this_1[3941]) = *(_BYTE *)(v3[754] + 7);
            *(_BYTE *)(*(_DWORD *)(this_1[3940] + v83) + 1) = *(_BYTE *)(v61 + v3[753] + 7);
            *(_BYTE *)(*(_DWORD *)(this_1[3941] + v83) + 1) = *(_BYTE *)(v3[754] + v61 + 7);
            *(_BYTE *)(*(_DWORD *)(this_1[3940] + v83) + 2) = *(_BYTE *)(v3[753] + 2 * v61 + 7);
            *(_BYTE *)(*(_DWORD *)(this_1[3941] + v83) + 2) = *(_BYTE *)(v3[754] + 2 * v61 + 7);
            *(_BYTE *)(*(_DWORD *)(this_1[3940] + 4 * v60) + 3) = *(_BYTE *)(3 * v61 + v3[753] + 7);
            *(_BYTE *)(*(_DWORD *)(this_1[3941] + 4 * v60) + 3) = *(_BYTE *)(v3[754] + 3 * v61 + 7);
            *(_BYTE *)(*(_DWORD *)(this_1[3940] + 4 * v60) + 4) = *(_BYTE *)(v3[753] + 4 * v61 + 7);
            *(_BYTE *)(*(_DWORD *)(this_1[3941] + 4 * v60) + 4) = *(_BYTE *)(v3[754] + 4 * v61 + 7);
            *(_BYTE *)(*(_DWORD *)(this_1[3940] + 4 * v60) + 5) = *(_BYTE *)(5 * v61 + v3[753] + 7);
            *(_BYTE *)(*(_DWORD *)(this_1[3941] + 4 * v60) + 5) = *(_BYTE *)(v3[754] + 5 * v61 + 7);
            *(_BYTE *)(*(_DWORD *)(this_1[3940] + 4 * v60) + 6) = *(_BYTE *)(v3[753] + 6 * v61 + 7);
            *(_BYTE *)(*(_DWORD *)(this_1[3941] + 4 * v60) + 6) = *(_BYTE *)(v3[754] + 6 * v61 + 7);
            *(_BYTE *)(*(_DWORD *)(this_1[3940] + 4 * v60) + 7) = *(_BYTE *)(7 * v61 + v3[753] + 7);
            *(_BYTE *)(*(_DWORD *)(this_1[3941] + 4 * v60) + 7) = *(_BYTE *)(v3[754] + 7 * v61 + 7);
            v40 = v65;
          }
          v42 = v63;
          if ( v63 )
          {
            if ( this_1[1630] )
            {
              if ( v40 > 0 )
              {
                (*(void (__cdecl **)(_DWORD, int, _DWORD *))&g_VpxCoeffProbBuf[478])(
                  v3[752],
                  v64,
                  &this_1[4 * v63 + 1632]);
                v42 = v63;
              }
              if ( !v72 )
                (*(void (__cdecl **)(_DWORD, int, _DWORD *))&g_VpxCoeffProbBuf[490])(
                  v3[752],
                  v64,
                  &this_1[4 * v42 + 1888]);
              if ( v60 > 0 )
                (*(void (__cdecl **)(_DWORD, int, _DWORD *))&g_VpxCoeffProbBuf[474])(
                  v3[752],
                  v64,
                  &this_1[4 * v63 + 1632]);
              if ( !v72 )
                (*(void (__cdecl **)(_DWORD, int, _DWORD *))&g_VpxCoeffProbBuf[494])(
                  v3[752],
                  v64,
                  &this_1[4 * v63 + 1888]);
            }
            else
            {
              v93[0] = &this_1[4 * v63 + 1632];
              v93[1] = &this_1[4 * v63 + 1888];
              v93[2] = &this_1[4 * v63 + 2144];
              v93[3] = &this_1[4 * *((unsigned char *)&this_1[16 * this_1[1610] + 2432] + v63) + 2400];
              if ( v40 > 0 )
                (*(void (__cdecl **)(_DWORD, _DWORD, _DWORD, int, int, _DWORD *))&g_VpxCoeffProbBuf[462])(
                  v3[752],
                  v3[753],
                  v3[754],
                  v64,
                  v61,
                  v93);
              if ( !v72 )
                (*(void (__cdecl **)(_DWORD, _DWORD, _DWORD, int, int, _DWORD *))&g_VpxCoeffProbBuf[486])(
                  v3[752],
                  v3[753],
                  v3[754],
                  v64,
                  v61,
                  v93);
              if ( v60 > 0 )
                (*(void (__cdecl **)(_DWORD, _DWORD, _DWORD, int, int, _DWORD *))&g_VpxCoeffProbBuf[470])(
                  v3[752],
                  v3[753],
                  v3[754],
                  v64,
                  v61,
                  v93);
              if ( !v72 )
                (*(void (__cdecl **)(_DWORD, _DWORD, _DWORD, int, int, _DWORD *))&g_VpxCoeffProbBuf[498])(
                  v3[752],
                  v3[753],
                  v3[754],
                  v64,
                  v61,
                  v93);
            }
          }
        }
        v79 += 16;
        v81 += 8;
        v76 += 8;
        v3[766] += 76;
        v3[779] += 9;
        n32 += 16;
        n16_1 += 8;
        v67 -= 128;
        v27 = v65 + 1;
        v65 = v27;
        if ( v27 >= this_1[1615] )
          break;
        v14 = v83;
      }
      v62 = v89;
      v73 = v88;
    }
    if ( this_1[2468] )
    {
      v43 = v60;
      if ( v60 == this_1[1614] - 1 )
        goto LABEL_59;
      v44 = *v90 + 32;
      v45 = *(_DWORD *)(this_1[3936] + 4 * v60 + 4);
      v46 = *v90 >> 1;
      *(_BYTE *)(v45 + v44) = *(_BYTE *)(v45 + v44 - 1);
      v47 = *(_DWORD *)(this_1[3937] + 4 * v60 + 4);
      *(_BYTE *)(v47 + v46 + 16) = *(_BYTE *)(v47 + v46 + 15);
      v48 = *(_DWORD *)(this_1[3938] + 4 * v60 + 4);
      *(_BYTE *)(v48 + v46 + 16) = *(_BYTE *)(v48 + v46 + 15);
      v49 = *(_DWORD *)(this_1[3936] + 4 * v60 + 4);
      *(_BYTE *)(v49 + v44 + 1) = *(_BYTE *)(v49 + v44 - 1);
      v50 = *(_DWORD *)(this_1[3937] + 4 * v60 + 4);
      *(_BYTE *)(v50 + v46 + 17) = *(_BYTE *)(v50 + v46 + 15);
      v51 = *(_DWORD *)(this_1[3938] + 4 * v60 + 4);
      *(_BYTE *)(v51 + v46 + 17) = *(_BYTE *)(v51 + v46 + 15);
      v52 = *(_DWORD *)(this_1[3936] + 4 * v60 + 4);
      *(_BYTE *)(v52 + v44 + 2) = *(_BYTE *)(v52 + v44 - 1);
      v53 = *(_DWORD *)(this_1[3937] + 4 * v60 + 4);
      *(_BYTE *)(v53 + v46 + 18) = *(_BYTE *)(v53 + v46 + 15);
      v54 = *(_DWORD *)(this_1[3938] + 4 * v60 + 4);
      *(_BYTE *)(v54 + v46 + 18) = *(_BYTE *)(v54 + v46 + 15);
      v55 = *(_DWORD *)(this_1[3936] + 4 * v60 + 4);
      *(_BYTE *)(v55 + v44 + 3) = *(_BYTE *)(v55 + v44 - 1);
      v56 = *(_DWORD *)(this_1[3937] + 4 * v60 + 4);
      *(_BYTE *)(v56 + v46 + 19) = *(_BYTE *)(v56 + v46 + 15);
      v57 = *(_DWORD *)(this_1[3938] + 4 * v60 + 4);
      *(_BYTE *)(v57 + v46 + 19) = *(_BYTE *)(v57 + v46 + 15);
    }
    else
    {
      FFX_Video_ReconstructBorder((int)v95, v3[752] + 16, v3[753] + 8, v3[754] + 8);
    }
    v43 = v60;
LABEL_59:
    v7 = v94;
    *v86 = v80 + v65;
    v3[766] += 76;
    v58 = v3[767];
    v3[769] = 1;
    v3[766] += 76 * this_1[3928] * v58;
    v13 = this_1[3928] + v43 + 1;
    v60 = v13;
  }
  while ( v13 < this_1[1614] );
  v12 = v98;
LABEL_61:
  result = this_1[1614] - 1;
  if ( v12 == result )
    return ReleaseSemaphore((HANDLE)this_1[3946], 1, 0);
  return result;
}
