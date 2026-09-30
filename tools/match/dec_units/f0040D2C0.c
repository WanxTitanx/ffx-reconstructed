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

extern _DWORD FFX_Thunk_800000;
extern _DWORD g_UnkVar_2000000;
extern _DWORD getenv();
extern _DWORD support();
// Function: VPX_DetectSIMDCaps
// Address: 0x40D2C0
// Size: 0x8B0
// VPX: Detect SIMD capabilities — detects CPU SIMD support (SSE2/SSE3/SSSE3/SSE4.1)
int (__cdecl *VPX_DetectSIMDCaps())(int, int, int, int, int)
{
  char v0; // si
  char *env; // eax
  char v2; // bl
  char *env_1; // eax
  int v14; // edi
  void *FFX_Vpx_McCompensate16x16_1; // eax
  int v16; // esi
  int v17; // edx
  void *FFX_Vpx_McCompensate4x4_1; // eax
  void *FFX_Vpx_McCompensate8x4_1; // eax
  void *FFX_Vpx_McCompensate8x8_1; // eax
  void *FFX_VpxLoopFilter_Smooth_1; // eax
  void *FFX_VpxCoeff_ProcessBlock_1; // eax
  void (*nullsub)(); // eax
  void *FFX_VpxBlock_Copy16x4B_1; // eax
  void *FFX_VpxBlock_Copy2x2B_1; // eax
  void *FFX_VpxBlock_Copy4x4B_1; // eax
  void *FFX_Vpx_TransformAddPrediction_1; // eax
  __m64 *(__cdecl *FFX_Vpx_Transform4x4_Dequant_1)(__m64 *, __m64 *, unsigned int *, int); // eax
  void *FFX_Vpx_TransformReconstruct_4x4_1; // eax
  void *FFX_Vpx_TransformReconstruct_16x16_1; // eax
  void *PhyreVideo_DequantScale_SSE_1; // eax
  void *PhyreImage_BilinearBlend_Weighted16_1; // eax
  void *PhyreImage_BilinearBlend_Weighted8_1; // eax
  void *FFX_VpxLoopFilter_MbEdge_Dispatch_1; // eax
  void *FFX_VpxLoopFilter_Subblock_Dispatch_1; // eax
  void *FFX_VpxLoopFilter_Mb_1; // eax
  int (__cdecl *FFX_VpxLoopFilter_Mb_Intra_1)(int, int, int, int, int, int); // eax
  void *FFX_VpxLoopFilter_HEdgeLuma_Dispatch_1; // eax
  void *FFX_VpxLoopFilter_VEdgeLuma_Dispatch_1; // eax
  void *FFX_VpxLoopFilter_HEdge_Luma_1; // eax
  void *FFX_VpxLoopFilter_VEdge_1; // eax
  void *FFX_Video_PlaneTranspose_1; // eax
  void *FFX_VpxLoopFilter_SelfGuided_1; // eax
  void *FFX_VpxPostProc_AddNoise_1; // eax
  int (__cdecl *FFX_VpxBlock_Reconstruct_1)(const __m128i *, __m128i *, int, int, int, const __m128i *, int); // eax
  void *FFX_Vpx_Sad16x16_Wrapper_1; // eax
  int v47; // ecx
  void *FFX_Vpx_Sad16x16_Subpel_H_1; // eax
  void *FFX_Vpx_Sad16x16_Subpel_H_4ref_1; // eax
  int v50; // ebx
  void *FFX_Vpx_SubPixelVarSearch_1; // eax
  void *FFX_Vpx_Sad16x8_Wrapper_1; // eax
  void *FFX_Vpx_Sad16x8_Subpel_H_1; // eax
  void *FFX_Vpx_Sad16x16_Compute4x16x8_1; // eax
  void *FFX_Vpx_Sad16x8_Subpel_H_2; // eax
  void *FFX_Vpx_Sad4x4_Wrapper_1; // eax
  void *FFX_Vpx_Sad4x4_Subpel_H_1; // eax
  void *FFX_Vpx_Sad16x16_Compute4x4x4_1; // eax
  void *FFX_Vpx_Sad4x4_Subpel_H_2; // eax
  void *FFX_Vpx_Sad8x16_Wrapper_1; // eax
  void *FFX_Vpx_Sad8x16_Subpel_H_1; // eax
  void *FFX_Vpx_Sad16x16_Compute4x8x16_1; // eax
  void *FFX_Vpx_Sad8x16_Subpel_H_2; // eax
  void *FFX_Vpx_Sad8x8_Wrapper_1; // eax
  void *FFX_Vpx_Sad8x8_Subpel_H_1; // eax
  void *FFX_Vpx_Sad16x16_Compute4x8x8_1; // eax
  void *FFX_Vpx_Sad8x8_Subpel_H_2; // eax
  void *FFX_VpxBoolDecoder_ReadTree_1; // eax
  void *FFX_Vpx_IDCT4x4_1; // eax
  int (__cdecl *FFX_Vpx_SmoothInterp16x16_1)(int, int, int, int, int, int); // eax
  int (__cdecl *FFX_Vpx_SmoothInterp4x4_1)(int, int, int, int, int, int); // eax
  int (__cdecl *FFX_Vpx_SmoothInterp8x4_1)(int, int, int, int, int, int); // eax
  int (__cdecl *FFX_Vpx_SmoothInterp8x8_1)(int, int, int, int, int, int); // eax
  unsigned int (__cdecl *FFX_Vpx_ResizePlane_17to16_1)(const __m128i *, __m128i *, int, int, int, int, int *); // eax
  unsigned int (__cdecl *FFX_Vpx_ResizePlane_9to8_1)(const __m128i *, __m128i *, int, int, int, int, int *); // eax
  void *FFX_Video_ColorTransformBlock_1; // eax
  unsigned int (__cdecl *FFX_VpxCoeff_DecodeChroma_1)(const __m128i *, __m128i *, int, int, const __m128i *, int, int *); // eax
  unsigned int (__cdecl *FFX_VpxCoeff_DecodeLuma_1)(const __m128i *, __m128i *, int, int, const __m128i *, int, int *); // eax
  void *FFX_Vpx_Sad16x16_Variance_1; // eax
  void *FFX_Vpx_Sad8x8_Variance_1; // eax
  void *FFX_Vpx_SadOne4x4_SIMD_1; // eax
  void *FFX_VpxCoeff_Sad8x8_Chroma_1; // eax
  void *FFX_VpxCoeff_Sad8x8_Luma_1; // eax
  void *FFX_Vpx_ResizePlane_17to16_4; // eax
  void *FFX_Vpx_ResizePlane_17to16_4_1; // eax
  int (__cdecl *FFX_Vpx_ResizePlane_17to16_0)(int, int, int, int, int); // eax
  char v87; // [esp+Ch] [ebp-14h]

  v0 = 0;
  v87 = -1;
  env = getenv("VPX_SIMD_CAPS");
  if ( env && *env )
  {
    v2 = strtol(env, 0, 0);
  }
  else
  {
    env_1 = getenv("VPX_SIMD_CAPS_MASK");
    if ( env_1 && *env_1 )
      v87 = strtol(env_1, 0, 0);
    _EAX = 0;
    __asm { cpuid }
    if ( _EAX )
    {
      _EAX = 1;
      __asm { cpuid }
      if ( ((unsigned int)FFX_Thunk_800000 & _EDX) != 0 )
        v0 = 1;
      if ( ((unsigned int)&g_UnkVar_2000000 & _EDX) != 0 )
        v0 |= 2u;
      if ( (_EDX & 0x4000000) != 0 )
        v0 |= 4u;
      if ( (_ECX & 1) != 0 )
        v0 |= 8u;
      if ( (_ECX & 0x200) != 0 )
        v0 |= 0x10u;
      if ( (_ECX & 0x80000) != 0 )
        v0 |= 0x20u;
      if ( (_ECX & 0x18000000) == 0x18000000 )
        __asm { xgetbv }
      v2 = v0 & v87;
    }
    else
    {
      v2 = 0;
    }
  }
  v14 = v2 & 1;
  FFX_Vpx_McCompensate16x16_1 = FFX_Vpx_McCompensate16x16;
  if ( (v2 & 1) != 0 )
    FFX_Vpx_McCompensate16x16_1 = FFX_Vpx_BlockOp_Split4x4Partition;
  v16 = v2 & 4;
  if ( (v2 & 4) != 0 )
    FFX_Vpx_McCompensate16x16_1 = PhyreVideo_CopyBlock;
  v17 = v2 & 0x10;
  if ( (v2 & 0x10) != 0 )
    FFX_Vpx_McCompensate16x16_1 = PhyreVideo_VLCCode;
  *(_DWORD *)&g_VpxCoeffProbBuf[266] = FFX_Vpx_McCompensate16x16_1;
  FFX_Vpx_McCompensate4x4_1 = FFX_Vpx_McCompensate4x4;
  if ( (v2 & 1) != 0 )
    FFX_Vpx_McCompensate4x4_1 = FFX_Video_SubPixel_8tap_horiz_MMX;
  *(_DWORD *)&g_VpxCoeffProbBuf[426] = FFX_Vpx_McCompensate4x4_1;
  FFX_Vpx_McCompensate8x4_1 = FFX_Vpx_McCompensate8x4;
  if ( (v2 & 1) != 0 )
    FFX_Vpx_McCompensate8x4_1 = FFX_Video_SubPixel_8tap_vert_bilin_MMX;
  *(_DWORD *)&g_VpxCoeffProbBuf[394] = FFX_Vpx_McCompensate8x4_1;
  FFX_Vpx_McCompensate8x8_1 = FFX_Vpx_McCompensate8x8;
  if ( (v2 & 1) != 0 )
    FFX_Vpx_McCompensate8x8_1 = FFX_Video_SubPixel_8tap_vert_SSE2;
  if ( (v2 & 4) != 0 )
    FFX_Vpx_McCompensate8x8_1 = PhyreVideo_BlockDctTransform;
  if ( (v2 & 0x10) != 0 )
    FFX_Vpx_McCompensate8x8_1 = PhyreVideo_SubPixelInterpolate;
  *(_DWORD *)&g_VpxCoeffProbBuf[262] = FFX_Vpx_McCompensate8x8_1;
  FFX_VpxLoopFilter_Smooth_1 = FFX_VpxLoopFilter_Smooth;
  if ( (v2 & 4) != 0 )
    FFX_VpxLoopFilter_Smooth_1 = FFX_Vpx_ChromaUpsample_V1_SSE;
  if ( (v2 & 0x10) != 0 )
    FFX_VpxLoopFilter_Smooth_1 = FFX_Vpx_ChromaUpsample_V2_SSE;
  *(_DWORD *)&g_VpxCoeffProbBuf[510] = FFX_VpxLoopFilter_Smooth_1;
  FFX_VpxCoeff_ProcessBlock_1 = FFX_VpxCoeff_ProcessBlock;
  if ( (v2 & 4) != 0 )
    FFX_VpxCoeff_ProcessBlock_1 = FFX_Video_McCompensate_DualSSE;
  if ( (v2 & 0x10) != 0 )
    FFX_VpxCoeff_ProcessBlock_1 = FFX_Video_McCompensate_ShuffleSSE;
  *(_DWORD *)&g_VpxCoeffProbBuf[482] = FFX_VpxCoeff_ProcessBlock_1;
  nullsub = nullsub_2;
  if ( (v2 & 1) != 0 )
    nullsub = Phyre_MMX_Empty;
  *(_DWORD *)&g_VpxCoeffProbBuf[522] = nullsub;
  FFX_VpxBlock_Copy16x4B_1 = FFX_VpxBlock_Copy16x4B;
  if ( (v2 & 1) != 0 )
    FFX_VpxBlock_Copy16x4B_1 = PhyreVideo_BlockStridedTranspose;
  if ( (v2 & 4) != 0 )
    FFX_VpxBlock_Copy16x4B_1 = PhyreImage_CopyBlock_5x5_SSE;
  *(_DWORD *)&g_VpxCoeffProbBuf[302] = FFX_VpxBlock_Copy16x4B_1;
  FFX_VpxBlock_Copy2x2B_1 = FFX_VpxBlock_Copy2x2B;
  if ( (v2 & 1) != 0 )
    FFX_VpxBlock_Copy2x2B_1 = PhyreImage_CopyBlock_2x2_MMX;
  *(_DWORD *)&g_VpxCoeffProbBuf[338] = FFX_VpxBlock_Copy2x2B_1;
  FFX_VpxBlock_Copy4x4B_1 = FFX_VpxBlock_Copy4x4B;
  if ( (v2 & 1) != 0 )
    FFX_VpxBlock_Copy4x4B_1 = PhyreImage_CopyBlock_4x4_MMX;
  *(_DWORD *)&g_VpxCoeffProbBuf[270] = FFX_VpxBlock_Copy4x4B_1;
  FFX_Vpx_TransformAddPrediction_1 = FFX_Vpx_TransformAddPrediction;
  if ( (v2 & 1) != 0 )
    FFX_Vpx_TransformAddPrediction_1 = PhyreImage_AverageFill_4x4_MMX;
  *(_DWORD *)&g_VpxCoeffProbBuf[466] = FFX_Vpx_TransformAddPrediction_1;
  FFX_Vpx_Transform4x4_Dequant_1 = (__m64 *(__cdecl *)(__m64 *, __m64 *, unsigned int *, int))FFX_Vpx_Transform4x4_Dequant;
  if ( (v2 & 1) != 0 )
    FFX_Vpx_Transform4x4_Dequant_1 = PhyreVideo_Transform8;
  *(_DWORD *)&g_VpxCoeffProbBuf[506] = FFX_Vpx_Transform4x4_Dequant_1;
  FFX_Vpx_TransformReconstruct_4x4_1 = FFX_Vpx_TransformReconstruct_4x4;
  if ( (v2 & 1) != 0 )
    FFX_Vpx_TransformReconstruct_4x4_1 = FFX_Vpx_TransformReconstruct4x4;
  if ( (v2 & 4) != 0 )
    FFX_Vpx_TransformReconstruct_4x4_1 = PhyreVideo_MbReconstruct_Dispatch;
  *(_DWORD *)&g_VpxCoeffProbBuf[514] = FFX_Vpx_TransformReconstruct_4x4_1;
  FFX_Vpx_TransformReconstruct_16x16_1 = FFX_Vpx_TransformReconstruct_16x16;
  if ( (v2 & 1) != 0 )
    FFX_Vpx_TransformReconstruct_16x16_1 = FFX_Vpx_TransformReconstruct4x4_Chroma;
  if ( (v2 & 4) != 0 )
    FFX_Vpx_TransformReconstruct_16x16_1 = PhyreVideo_BlockReconstruct_Dispatch;
  *(_DWORD *)&g_VpxCoeffProbBuf[502] = FFX_Vpx_TransformReconstruct_16x16_1;
  PhyreVideo_DequantScale_SSE_1 = PhyreVideo_DequantScale_SSE;
  if ( (v2 & 1) != 0 )
    PhyreVideo_DequantScale_SSE_1 = PhyreImage_MultiplyPixel_MMX_wrapper;
  *(_DWORD *)&g_VpxCoeffProbBuf[518] = PhyreVideo_DequantScale_SSE_1;
  PhyreImage_BilinearBlend_Weighted16_1 = PhyreImage_BilinearBlend_Weighted16;
  if ( (v2 & 4) != 0 )
    PhyreImage_BilinearBlend_Weighted16_1 = PhyreImage_AlphaBlend_16x_SSE;
  *(_DWORD *)&g_VpxCoeffProbBuf[362] = PhyreImage_BilinearBlend_Weighted16_1;
  PhyreImage_BilinearBlend_Weighted8_1 = PhyreImage_BilinearBlend_Weighted8;
  if ( (v2 & 4) != 0 )
    PhyreImage_BilinearBlend_Weighted8_1 = PhyreImage_AlphaBlend_8x_SSE;
  *(_DWORD *)&g_VpxCoeffProbBuf[290] = PhyreImage_BilinearBlend_Weighted8_1;
  FFX_VpxLoopFilter_MbEdge_Dispatch_1 = FFX_VpxLoopFilter_MbEdge_Dispatch;
  if ( (v2 & 1) != 0 )
    FFX_VpxLoopFilter_MbEdge_Dispatch_1 = FFX_Video_HalfPelInterpolate;
  if ( (v2 & 4) != 0 )
    FFX_VpxLoopFilter_MbEdge_Dispatch_1 = FFX_Video_SmoothInterpolate;
  *(_DWORD *)&g_VpxCoeffProbBuf[498] = FFX_VpxLoopFilter_MbEdge_Dispatch_1;
  FFX_VpxLoopFilter_Subblock_Dispatch_1 = FFX_VpxLoopFilter_Subblock_Dispatch;
  if ( (v2 & 1) != 0 )
    FFX_VpxLoopFilter_Subblock_Dispatch_1 = FFX_Video_QuantizeBlock;
  if ( (v2 & 4) != 0 )
    FFX_VpxLoopFilter_Subblock_Dispatch_1 = FFX_Video_ChromaInterpolate;
  *(_DWORD *)&g_VpxCoeffProbBuf[486] = FFX_VpxLoopFilter_Subblock_Dispatch_1;
  FFX_VpxLoopFilter_Mb_1 = FFX_VpxLoopFilter_Mb;
  if ( (v2 & 1) != 0 )
    FFX_VpxLoopFilter_Mb_1 = FFX_Video_DeblockFilter_MMX_3plane;
  if ( (v2 & 4) != 0 )
    FFX_VpxLoopFilter_Mb_1 = FFX_Video_DeblockFilter_3plane;
  *(_DWORD *)&g_VpxCoeffProbBuf[470] = FFX_VpxLoopFilter_Mb_1;
  FFX_VpxLoopFilter_Mb_Intra_1 = (int (__cdecl *)(int, int, int, int, int, int))FFX_VpxLoopFilter_Mb_Intra;
  if ( (v2 & 1) != 0 )
    FFX_VpxLoopFilter_Mb_Intra_1 = (int (__cdecl *)(int, int, int, int, int, int))FFX_Video_DeblockFilter_SSE2_3plane;
  if ( (v2 & 4) != 0 )
    FFX_VpxLoopFilter_Mb_Intra_1 = FFX_Video_TransformBlock_DCT;
  *(_DWORD *)&g_VpxCoeffProbBuf[462] = FFX_VpxLoopFilter_Mb_Intra_1;
  FFX_VpxLoopFilter_HEdgeLuma_Dispatch_1 = FFX_VpxLoopFilter_HEdgeLuma_Dispatch;
  if ( (v2 & 1) != 0 )
    FFX_VpxLoopFilter_HEdgeLuma_Dispatch_1 = FFX_Video_EntropyDecode_3plane;
  if ( (v2 & 4) != 0 )
    FFX_VpxLoopFilter_HEdgeLuma_Dispatch_1 = FFX_Video_EntropyDecode_3plane2;
  *(_DWORD *)&g_VpxCoeffProbBuf[494] = FFX_VpxLoopFilter_HEdgeLuma_Dispatch_1;
  FFX_VpxLoopFilter_VEdgeLuma_Dispatch_1 = FFX_VpxLoopFilter_VEdgeLuma_Dispatch;
  if ( (v2 & 1) != 0 )
    FFX_VpxLoopFilter_VEdgeLuma_Dispatch_1 = FFX_Video_SubBlock_3plane;
  if ( (v2 & 4) != 0 )
    FFX_VpxLoopFilter_VEdgeLuma_Dispatch_1 = FFX_Video_SubBlock_3plane2;
  *(_DWORD *)&g_VpxCoeffProbBuf[490] = FFX_VpxLoopFilter_VEdgeLuma_Dispatch_1;
  FFX_VpxLoopFilter_HEdge_Luma_1 = FFX_VpxLoopFilter_HEdge_Luma;
  if ( (v2 & 1) != 0 )
    FFX_VpxLoopFilter_HEdge_Luma_1 = PhyreVideo_EntropyDecode;
  if ( (v2 & 4) != 0 )
    FFX_VpxLoopFilter_HEdge_Luma_1 = FFX_Video_SubPixel_2tap_SSE2;
  *(_DWORD *)&g_VpxCoeffProbBuf[474] = FFX_VpxLoopFilter_HEdge_Luma_1;
  FFX_VpxLoopFilter_VEdge_1 = FFX_VpxLoopFilter_VEdge;
  if ( (v2 & 1) != 0 )
    FFX_VpxLoopFilter_VEdge_1 = PhyreVideo_SubBlock;
  if ( (v2 & 4) != 0 )
    FFX_VpxLoopFilter_VEdge_1 = FFX_Video_SubBlock_RowFilter_SSE;
  *(_DWORD *)&g_VpxCoeffProbBuf[478] = FFX_VpxLoopFilter_VEdge_1;
  FFX_Video_PlaneTranspose_1 = FFX_Video_PlaneTranspose;
  if ( (v2 & 4) != 0 )
    FFX_Video_PlaneTranspose_1 = FFX_Video_LoopFilter_SSE2;
  *(_DWORD *)&g_VpxCoeffProbBuf[306] = FFX_Video_PlaneTranspose_1;
  FFX_VpxLoopFilter_SelfGuided_1 = FFX_VpxLoopFilter_SelfGuided;
  if ( (v2 & 1) != 0 )
    FFX_VpxLoopFilter_SelfGuided_1 = PhyreVideo_BlockCopy;
  if ( (v2 & 4) != 0 )
    FFX_VpxLoopFilter_SelfGuided_1 = FFX_Video_SSE_PixelTransform2;
  *(_DWORD *)&g_VpxCoeffProbBuf[450] = FFX_VpxLoopFilter_SelfGuided_1;
  FFX_VpxPostProc_AddNoise_1 = FFX_VpxPostProc_AddNoise;
  if ( (v2 & 1) != 0 )
    FFX_VpxPostProc_AddNoise_1 = PhyreImage_DitherAdd_MMX;
  if ( (v2 & 4) != 0 )
    FFX_VpxPostProc_AddNoise_1 = FFX_Video_NoiseAddition_SSE2;
  *(_DWORD *)&g_VpxCoeffProbBuf[370] = FFX_VpxPostProc_AddNoise_1;
  FFX_VpxBlock_Reconstruct_1 = (int (__cdecl *)(const __m128i *, __m128i *, int, int, int, const __m128i *, int))FFX_VpxBlock_Reconstruct;
  if ( (v2 & 4) != 0 )
    FFX_VpxBlock_Reconstruct_1 = FFX_Video_SSE_MMX_PixelTransform;
  *(_DWORD *)&g_VpxCoeffProbBuf[334] = FFX_VpxBlock_Reconstruct_1;
  FFX_Vpx_Sad16x16_Wrapper_1 = FFX_Vpx_Sad16x16_Wrapper;
  if ( (v2 & 1) != 0 )
    FFX_Vpx_Sad16x16_Wrapper_1 = PhyreImage_SAD_8Stride_MMX;
  if ( (v2 & 4) != 0 )
    FFX_Vpx_Sad16x16_Wrapper_1 = FFX_Video_SAD_8x16_MMX;
  v47 = v2 & 8;
  if ( (v2 & 8) != 0 )
    FFX_Vpx_Sad16x16_Wrapper_1 = PhyreImage_SAD_4x4_SSE;
  *(_DWORD *)&g_VpxCoeffProbBuf[366] = FFX_Vpx_Sad16x16_Wrapper_1;
  FFX_Vpx_Sad16x16_Subpel_H_1 = FFX_Vpx_Sad16x16_Subpel_H;
  if ( (v2 & 8) != 0 )
    FFX_Vpx_Sad16x16_Subpel_H_1 = FFX_Video_SSE_PixelBlockTransform;
  if ( (v2 & 0x10) != 0 )
    FFX_Vpx_Sad16x16_Subpel_H_1 = PhyreImage_ChromaSubsample_Trampoline;
  *(_DWORD *)&g_VpxCoeffProbBuf[410] = FFX_Vpx_Sad16x16_Subpel_H_1;
  FFX_Vpx_Sad16x16_Subpel_H_4ref_1 = FFX_Vpx_Sad16x16_Subpel_H_4ref;
  if ( (v2 & 8) != 0 )
    FFX_Vpx_Sad16x16_Subpel_H_4ref_1 = PhyreVideo_BlockMatchSAD_MultiRef;
  *(_DWORD *)&g_VpxCoeffProbBuf[330] = FFX_Vpx_Sad16x16_Subpel_H_4ref_1;
  v50 = v2 & 0x20;
  FFX_Vpx_SubPixelVarSearch_1 = FFX_Vpx_SubPixelVarSearch;
  if ( v50 )
    FFX_Vpx_SubPixelVarSearch_1 = PhyreVideo_BlockMatchSAD_16x16;
  *(_DWORD *)&g_VpxCoeffProbBuf[398] = FFX_Vpx_SubPixelVarSearch_1;
  FFX_Vpx_Sad16x8_Wrapper_1 = FFX_Vpx_Sad16x8_Wrapper;
  if ( v14 )
    FFX_Vpx_Sad16x8_Wrapper_1 = PhyreImage_SAD_DualQWORD_MMX;
  if ( v16 )
    FFX_Vpx_Sad16x8_Wrapper_1 = FFX_Video_SAD_8x8_MMX;
  *(_DWORD *)&g_VpxCoeffProbBuf[438] = FFX_Vpx_Sad16x8_Wrapper_1;
  FFX_Vpx_Sad16x8_Subpel_H_1 = FFX_Vpx_Sad16x8_Subpel_H;
  if ( v47 )
    FFX_Vpx_Sad16x8_Subpel_H_1 = FFX_Video_SAD_16x16_3pel_SSE2;
  if ( v17 )
    FFX_Vpx_Sad16x8_Subpel_H_1 = PhyreImage_ChromaSubsample_Trampoline8;
  *(_DWORD *)&g_VpxCoeffProbBuf[414] = FFX_Vpx_Sad16x8_Subpel_H_1;
  FFX_Vpx_Sad16x16_Compute4x16x8_1 = FFX_Vpx_Sad16x16_Compute4x16x8;
  if ( v47 )
    FFX_Vpx_Sad16x16_Compute4x16x8_1 = PhyreVideo_SAD8;
  *(_DWORD *)&g_VpxCoeffProbBuf[406] = FFX_Vpx_Sad16x16_Compute4x16x8_1;
  FFX_Vpx_Sad16x8_Subpel_H_2 = FFX_Vpx_Sad16x8_Subpel_H_8;
  if ( v50 )
    FFX_Vpx_Sad16x8_Subpel_H_2 = PhyreVideo_MotionVectorDecode;
  *(_DWORD *)&g_VpxCoeffProbBuf[274] = FFX_Vpx_Sad16x8_Subpel_H_2;
  FFX_Vpx_Sad4x4_Wrapper_1 = FFX_Vpx_Sad4x4_Wrapper;
  if ( v14 )
    FFX_Vpx_Sad4x4_Wrapper_1 = PhyreImage_SAD_2x2_MMX;
  if ( v16 )
    FFX_Vpx_Sad4x4_Wrapper_1 = FFX_Video_SAD_4x4_MMX;
  *(_DWORD *)&g_VpxCoeffProbBuf[430] = FFX_Vpx_Sad4x4_Wrapper_1;
  FFX_Vpx_Sad4x4_Subpel_H_1 = FFX_Vpx_Sad4x4_Subpel_H;
  if ( v47 )
    FFX_Vpx_Sad4x4_Subpel_H_1 = FFX_Video_SAD_4x8_3pel_MMX;
  *(_DWORD *)&g_VpxCoeffProbBuf[442] = FFX_Vpx_Sad4x4_Subpel_H_1;
  FFX_Vpx_Sad16x16_Compute4x4x4_1 = FFX_Vpx_Sad16x16_Compute4x4x4;
  if ( v47 )
    FFX_Vpx_Sad16x16_Compute4x4x4_1 = PhyreVideo_DcPrediction;
  *(_DWORD *)&g_VpxCoeffProbBuf[254] = FFX_Vpx_Sad16x16_Compute4x4x4_1;
  FFX_Vpx_Sad4x4_Subpel_H_2 = FFX_Vpx_Sad4x4_Subpel_H_8;
  if ( v50 )
    FFX_Vpx_Sad4x4_Subpel_H_2 = PhyreImage_SAD_BlockMatch_SSE;
  *(_DWORD *)&g_VpxCoeffProbBuf[326] = FFX_Vpx_Sad4x4_Subpel_H_2;
  FFX_Vpx_Sad8x16_Wrapper_1 = FFX_Vpx_Sad8x16_Wrapper;
  if ( v14 )
    FFX_Vpx_Sad8x16_Wrapper_1 = PhyreImage_SAD_Simple_MMX;
  if ( v16 )
    FFX_Vpx_Sad8x16_Wrapper_1 = FFX_Video_SAD_16x16_MMX;
  *(_DWORD *)&g_VpxCoeffProbBuf[386] = FFX_Vpx_Sad8x16_Wrapper_1;
  FFX_Vpx_Sad8x16_Subpel_H_1 = FFX_Vpx_Sad8x16_Subpel_H;
  if ( v47 )
    FFX_Vpx_Sad8x16_Subpel_H_1 = FFX_Video_MMX_PixelBlockTransform;
  *(_DWORD *)&g_VpxCoeffProbBuf[278] = FFX_Vpx_Sad8x16_Subpel_H_1;
  FFX_Vpx_Sad16x16_Compute4x8x16_1 = FFX_Vpx_Sad16x16_Compute4x8x16;
  if ( v47 )
    FFX_Vpx_Sad16x16_Compute4x8x16_1 = PhyreVideo_IDCT;
  *(_DWORD *)&g_VpxCoeffProbBuf[454] = FFX_Vpx_Sad16x16_Compute4x8x16_1;
  FFX_Vpx_Sad8x16_Subpel_H_2 = FFX_Vpx_Sad8x16_Subpel_H_8;
  if ( v50 )
    FFX_Vpx_Sad8x16_Subpel_H_2 = PhyreVideo_MotionCompensate;
  *(_DWORD *)&g_VpxCoeffProbBuf[374] = FFX_Vpx_Sad8x16_Subpel_H_2;
  FFX_Vpx_Sad8x8_Wrapper_1 = FFX_Vpx_Sad8x8_Wrapper;
  if ( v14 )
    FFX_Vpx_Sad8x8_Wrapper_1 = PhyreImage_SAD_SingleRow_MMX;
  if ( v16 )
    FFX_Vpx_Sad8x8_Wrapper_1 = FFX_Video_SAD_16x8_MMX;
  *(_DWORD *)&g_VpxCoeffProbBuf[418] = FFX_Vpx_Sad8x8_Wrapper_1;
  FFX_Vpx_Sad8x8_Subpel_H_1 = FFX_Vpx_Sad8x8_Subpel_H;
  if ( v47 )
    FFX_Vpx_Sad8x8_Subpel_H_1 = FFX_Video_SAD_16x16_3pel_MMX;
  *(_DWORD *)&g_VpxCoeffProbBuf[382] = FFX_Vpx_Sad8x8_Subpel_H_1;
  FFX_Vpx_Sad16x16_Compute4x8x8_1 = FFX_Vpx_Sad16x16_Compute4x8x8;
  if ( v47 )
    FFX_Vpx_Sad16x16_Compute4x8x8_1 = PhyreVideo_SAD4;
  *(_DWORD *)&g_VpxCoeffProbBuf[402] = FFX_Vpx_Sad16x16_Compute4x8x8_1;
  FFX_Vpx_Sad8x8_Subpel_H_2 = FFX_Vpx_Sad8x8_Subpel_H_8;
  if ( v50 )
    FFX_Vpx_Sad8x8_Subpel_H_2 = PhyreVideo_MotionEstimate;
  *(_DWORD *)&g_VpxCoeffProbBuf[378] = FFX_Vpx_Sad8x8_Subpel_H_2;
  FFX_VpxBoolDecoder_ReadTree_1 = FFX_VpxBoolDecoder_ReadTree;
  if ( v14 )
    FFX_VpxBoolDecoder_ReadTree_1 = PhyreVideo_IDCT_Stage_Mmx;
  *(_DWORD *)&g_VpxCoeffProbBuf[282] = FFX_VpxBoolDecoder_ReadTree_1;
  FFX_Vpx_IDCT4x4_1 = FFX_Vpx_IDCT4x4;
  if ( v14 )
    FFX_Vpx_IDCT4x4_1 = PhyreVideo_IDCT_MMX_256Out;
  if ( v16 )
    FFX_Vpx_IDCT4x4_1 = PhyreVideo_IDCT_2D_Sse2;
  *(_DWORD *)&g_VpxCoeffProbBuf[458] = FFX_Vpx_IDCT4x4_1;
  FFX_Vpx_SmoothInterp16x16_1 = FFX_Vpx_SmoothInterp16x16;
  if ( v14 )
    FFX_Vpx_SmoothInterp16x16_1 = (int (__cdecl *)(int, int, int, int, int, int))FFX_Video_FilterConvolveBlock;
  if ( v16 )
    FFX_Vpx_SmoothInterp16x16_1 = (int (__cdecl *)(int, int, int, int, int, int))FFX_Video_BilinearInterpolateBlock;
  if ( v17 )
    FFX_Vpx_SmoothInterp16x16_1 = (int (__cdecl *)(int, int, int, int, int, int))PhyreVideo_ReconstructBlock_16_Wide;
  *(_DWORD *)&g_VpxCoeffProbBuf[318] = FFX_Vpx_SmoothInterp16x16_1;
  FFX_Vpx_SmoothInterp4x4_1 = FFX_Vpx_SmoothInterp4x4;
  if ( v14 )
    FFX_Vpx_SmoothInterp4x4_1 = (int (__cdecl *)(int, int, int, int, int, int))FFX_Video_SubPixelFilter_8tap_horiz;
  if ( v17 )
    FFX_Vpx_SmoothInterp4x4_1 = (int (__cdecl *)(int, int, int, int, int, int))FFX_Video_UpsampleFilterBlock;
  *(_DWORD *)&g_VpxCoeffProbBuf[346] = FFX_Vpx_SmoothInterp4x4_1;
  FFX_Vpx_SmoothInterp8x4_1 = FFX_Vpx_SmoothInterp8x4;
  if ( v14 )
    FFX_Vpx_SmoothInterp8x4_1 = (int (__cdecl *)(int, int, int, int, int, int))FFX_Video_SubPixelFilter_16tap_vert2;
  if ( v16 )
    FFX_Vpx_SmoothInterp8x4_1 = (int (__cdecl *)(int, int, int, int, int, int))PhyreImage_BilinearScale_4tap_Dispatch;
  if ( v17 )
    FFX_Vpx_SmoothInterp8x4_1 = (int (__cdecl *)(int, int, int, int, int, int))PhyreVideo_ReconstructBlock_4_Wide;
  *(_DWORD *)&g_VpxCoeffProbBuf[310] = FFX_Vpx_SmoothInterp8x4_1;
  FFX_Vpx_SmoothInterp8x8_1 = FFX_Vpx_SmoothInterp8x8;
  if ( v14 )
    FFX_Vpx_SmoothInterp8x8_1 = (int (__cdecl *)(int, int, int, int, int, int))FFX_Video_SubPixelFilter_16tap_vert;
  if ( v16 )
    FFX_Vpx_SmoothInterp8x8_1 = (int (__cdecl *)(int, int, int, int, int, int))PhyreImage_BilinearScale_8tap_Dispatch;
  if ( v17 )
    FFX_Vpx_SmoothInterp8x8_1 = (int (__cdecl *)(int, int, int, int, int, int))PhyreVideo_ReconstructBlock_8_Wide;
  *(_DWORD *)&g_VpxCoeffProbBuf[294] = FFX_Vpx_SmoothInterp8x8_1;
  FFX_Vpx_ResizePlane_17to16_1 = (unsigned int (__cdecl *)(const __m128i *, __m128i *, int, int, int, int, int *))FFX_Vpx_ResizePlane_17to16;
  if ( v14 )
    FFX_Vpx_ResizePlane_17to16_1 = (unsigned int (__cdecl *)(const __m128i *, __m128i *, int, int, int, int, int *))FFX_Video_ME_SAD_16px_MMX_2tap;
  if ( v16 )
    FFX_Vpx_ResizePlane_17to16_1 = (unsigned int (__cdecl *)(const __m128i *, __m128i *, int, int, int, int, int *))FFX_Vpx_SAD_Bilinear_16x16;
  if ( v17 )
    FFX_Vpx_ResizePlane_17to16_1 = PhyreVideo_SAD16_MotionSearch_Dispatch;
  *(_DWORD *)&g_VpxCoeffProbBuf[314] = FFX_Vpx_ResizePlane_17to16_1;
  FFX_Vpx_ResizePlane_9to8_1 = (unsigned int (__cdecl *)(const __m128i *, __m128i *, int, int, int, int, int *))FFX_Vpx_ResizePlane_9to8;
  if ( v14 )
    FFX_Vpx_ResizePlane_9to8_1 = (unsigned int (__cdecl *)(const __m128i *, __m128i *, int, int, int, int, int *))FFX_Video_ME_SAD_8px_MMX_2tap;
  if ( v16 )
    FFX_Vpx_ResizePlane_9to8_1 = (unsigned int (__cdecl *)(const __m128i *, __m128i *, int, int, int, int, int *))FFX_Vpx_SAD_Bilinear_16x8;
  if ( v17 )
    FFX_Vpx_ResizePlane_9to8_1 = PhyreVideo_SAD8_MotionSearch_Dispatch;
  *(_DWORD *)&g_VpxCoeffProbBuf[390] = FFX_Vpx_ResizePlane_9to8_1;
  FFX_Video_ColorTransformBlock_1 = FFX_Video_ColorTransformBlock;
  if ( v14 )
    FFX_Video_ColorTransformBlock_1 = FFX_Video_SAD_Weighted_MMX_wrapper;
  if ( v16 )
    FFX_Video_ColorTransformBlock_1 = PhyreVideo_WeightedSAD_MMX_Dispatch;
  *(_DWORD *)&g_VpxCoeffProbBuf[446] = FFX_Video_ColorTransformBlock_1;
  FFX_VpxCoeff_DecodeChroma_1 = (unsigned int (__cdecl *)(const __m128i *, __m128i *, int, int, const __m128i *, int, int *))FFX_VpxCoeff_DecodeChroma;
  if ( v14 )
    FFX_VpxCoeff_DecodeChroma_1 = (unsigned int (__cdecl *)(const __m128i *, __m128i *, int, int, const __m128i *, int, int *))FFX_Video_ME_SAD_16px_MMX;
  if ( v16 )
    FFX_VpxCoeff_DecodeChroma_1 = FFX_Vpx_SAD_Bilinear_8x16;
  *(_DWORD *)&g_VpxCoeffProbBuf[358] = FFX_VpxCoeff_DecodeChroma_1;
  FFX_VpxCoeff_DecodeLuma_1 = (unsigned int (__cdecl *)(const __m128i *, __m128i *, int, int, const __m128i *, int, int *))FFX_VpxCoeff_DecodeLuma;
  if ( v14 )
    FFX_VpxCoeff_DecodeLuma_1 = (unsigned int (__cdecl *)(const __m128i *, __m128i *, int, int, const __m128i *, int, int *))FFX_Video_ME_SAD_8px_MMX;
  if ( v16 )
    FFX_VpxCoeff_DecodeLuma_1 = FFX_Vpx_SAD_Bilinear_8x8;
  *(_DWORD *)&g_VpxCoeffProbBuf[422] = FFX_VpxCoeff_DecodeLuma_1;
  FFX_Vpx_Sad16x16_Variance_1 = FFX_Vpx_Sad16x16_Variance;
  if ( v14 )
    FFX_Vpx_Sad16x16_Variance_1 = FFX_Video_QuarterPelSearch;
  if ( v16 )
    FFX_Vpx_Sad16x16_Variance_1 = FFX_Vpx_BlockMatch_SAD16x16;
  *(_DWORD *)&g_VpxCoeffProbBuf[342] = FFX_Vpx_Sad16x16_Variance_1;
  FFX_Vpx_Sad8x8_Variance_1 = FFX_Vpx_Sad8x8_Variance;
  if ( v14 )
    FFX_Vpx_Sad8x8_Variance_1 = FFX_Video_SAD_HalfPel_H_MMX;
  if ( v16 )
    FFX_Vpx_Sad8x8_Variance_1 = FFX_Vpx_BlockMatch_SAD8x8_Var;
  *(_DWORD *)&g_VpxCoeffProbBuf[354] = FFX_Vpx_Sad8x8_Variance_1;
  FFX_Vpx_SadOne4x4_SIMD_1 = FFX_Vpx_SadOne4x4_SIMD;
  if ( v14 )
    FFX_Vpx_SadOne4x4_SIMD_1 = FFX_Video_SAD_BlockDiff_MMX_wrapper;
  if ( v16 )
    FFX_Vpx_SadOne4x4_SIMD_1 = FFX_Vpx_BlockMatch_SAD4x4;
  *(_DWORD *)&g_VpxCoeffProbBuf[258] = FFX_Vpx_SadOne4x4_SIMD_1;
  FFX_VpxCoeff_Sad8x8_Chroma_1 = FFX_VpxCoeff_Sad8x8_Chroma;
  if ( v14 )
    FFX_VpxCoeff_Sad8x8_Chroma_1 = FFX_Video_SAD_HalfPel_V_MMX;
  if ( v16 )
    FFX_VpxCoeff_Sad8x8_Chroma_1 = FFX_Vpx_BlockMatch_SAD16x16_Var;
  *(_DWORD *)&g_VpxCoeffProbBuf[350] = FFX_VpxCoeff_Sad8x8_Chroma_1;
  FFX_VpxCoeff_Sad8x8_Luma_1 = FFX_VpxCoeff_Sad8x8_Luma;
  if ( v14 )
    FFX_VpxCoeff_Sad8x8_Luma_1 = FFX_Video_SAD_QuarterPel_MMX_wrapper;
  if ( v16 )
    FFX_VpxCoeff_Sad8x8_Luma_1 = FFX_Vpx_BlockMatch_SAD8x8;
  *(_DWORD *)&g_VpxCoeffProbBuf[322] = FFX_VpxCoeff_Sad8x8_Luma_1;
  FFX_Vpx_ResizePlane_17to16_4 = FFX_Vpx_ResizePlane_17to16_4_0;
  if ( v14 )
    FFX_Vpx_ResizePlane_17to16_4 = FFX_Video_ME_SAD_16px_2tap_4_0;
  if ( v16 )
    FFX_Vpx_ResizePlane_17to16_4 = PhyreVideo_SAD16_Unaligned2_Wrapper;
  *(_DWORD *)&g_VpxCoeffProbBuf[434] = FFX_Vpx_ResizePlane_17to16_4;
  FFX_Vpx_ResizePlane_17to16_4_1 = FFX_Vpx_ResizePlane_17to16_4_4;
  if ( v14 )
    FFX_Vpx_ResizePlane_17to16_4_1 = FFX_Video_ME_SAD_16px_2tap_4_4;
  if ( v16 )
    FFX_Vpx_ResizePlane_17to16_4_1 = PhyreVideo_SAD16_Dual128_Wrapper;
  *(_DWORD *)&g_VpxCoeffProbBuf[286] = FFX_Vpx_ResizePlane_17to16_4_1;
  FFX_Vpx_ResizePlane_17to16_0 = (int (__cdecl *)(int, int, int, int, int))FFX_Vpx_ResizePlane_17to16_0_4;
  if ( v14 )
    FFX_Vpx_ResizePlane_17to16_0 = (int (__cdecl *)(int, int, int, int, int))FFX_Video_ME_SAD_16px_2tap_0_4;
  if ( v16 )
    FFX_Vpx_ResizePlane_17to16_0 = (int (__cdecl *)(int, int, int, int, int))PhyreVideo_SAD16_Unaligned_Wrapper;
  *(_DWORD *)&g_VpxCoeffProbBuf[298] = FFX_Vpx_ResizePlane_17to16_0;
  return FFX_Vpx_ResizePlane_17to16_0;
}
