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
extern _DWORD FFX_VpxFrameDecoder_DefaultCoefProbs();
extern _DWORD FFX_VpxFrameDecoder_InitFilterParams();
extern _DWORD FFX_VpxFrameDecoder_InterFrameModeInit();
extern _DWORD FFX_VpxFrameDecoder_IntraFrameModeInit();
extern _DWORD FFX_VpxFrameDecoder_LoopFilterMacroblock();
extern _DWORD FFX_VpxFrameDecoder_ProcessMacroblock();
extern _DWORD FFX_VpxMB_DecodeAndReconstruct();
// Function: FFX_VpxFrameDecoder_InitPicture
// Address: 0x40FBD0
// Size: 0x722
// FFX: VPX frame decoder init picture — initializes VP8 picture frame for decoding
// FFX VPX: Initialize picture for decoding
char *__fastcall FFX_VpxFrameDecoder_InitPicture(_DWORD *self)
{
  _DWORD *v2; // ebx
  int v3; // eax
  _DWORD *v4; // ecx
  _DWORD *v5; // edi
  int v6; // eax
  _DWORD *v7; // ecx
  int v8; // eax
  _DWORD *v9; // ecx
  int n63; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // edi
  int v14; // eax
  unsigned char *v15; // edx
  int v16; // ecx
  int n16; // eax
  char *v18; // ebx
  int v19; // ecx
  int v20; // eax
  int v21; // edi
  _BYTE *v22; // ecx
  int v23; // eax
  int v24; // edx
  unsigned char v25; // al
  int v26; // eax
  int n32; // eax
  BOOL v28; // eax
  _DWORD *v29; // ecx
  int v30; // edx
  int v31; // eax
  int v32; // eax
  int v33; // eax
  unsigned char *p_Val_4; // ebx
  int v35; // esi
  char *v36; // ecx
  char *v38; // [esp+Ch] [ebp-B4h]
  int v39; // [esp+10h] [ebp-B0h]
  unsigned char *p_Val_2; // [esp+14h] [ebp-ACh]
  char *v41; // [esp+18h] [ebp-A8h]
  int v42; // [esp+1Ch] [ebp-A4h]
  _BYTE *v43; // [esp+1Ch] [ebp-A4h]
  int p_Val; // [esp+20h] [ebp-A0h]
  int v45; // [esp+24h] [ebp-9Ch]
  int v46; // [esp+28h] [ebp-98h]
  unsigned char *v47; // [esp+2Ch] [ebp-94h]
  char *v48; // [esp+30h] [ebp-90h]
  int v49; // [esp+34h] [ebp-8Ch]
  int v50; // [esp+38h] [ebp-88h]
  int v51; // [esp+3Ch] [ebp-84h]
  int v52; // [esp+40h] [ebp-80h]
  int v53; // [esp+44h] [ebp-7Ch]
  int v54; // [esp+48h] [ebp-78h]
  int v55; // [esp+4Ch] [ebp-74h]
  int v56; // [esp+50h] [ebp-70h]
  unsigned char *p_Val_3; // [esp+54h] [ebp-6Ch]
  int v58; // [esp+58h] [ebp-68h]
  int v59; // [esp+5Ch] [ebp-64h]
  int v60; // [esp+60h] [ebp-60h]
  int v61; // [esp+64h] [ebp-5Ch]
  unsigned char *p_Val_1; // [esp+68h] [ebp-58h]
  char *v63; // [esp+6Ch] [ebp-54h]
  int v64; // [esp+70h] [ebp-50h]
  _DWORD *v65; // [esp+78h] [ebp-48h]
  _DWORD v66[12]; // [esp+7Ch] [ebp-44h]
  _DWORD v67[4]; // [esp+ACh] [ebp-14h]

  v47 = (unsigned char *)*(self + 766);
  v2 = self + 980;
  v3 = 1 << *(self + 3043);
  v4 = (_DWORD *)*(self + 977);
  v5 = (_DWORD *)*(self + 976);
  v60 = v3;
  v45 = v5[4];
  v55 = v5[9];
  v66[3] = v4[13];
  v66[4] = v4[14];
  v66[5] = v4[15];
  v6 = v4[25];
  v7 = (_DWORD *)*(self + 978);
  v67[1] = v6;
  v66[6] = v7[13];
  v66[7] = v7[14];
  v66[8] = v7[15];
  v8 = v7[25];
  v9 = (_DWORD *)*(self + 979);
  v67[2] = v8;
  v66[9] = v9[13];
  v66[10] = v9[14];
  v66[11] = v9[15];
  v67[3] = v9[25];
  p_Val_1 = (unsigned char *)v5[13];
  p_Val = (int)p_Val_1;
  p_Val_2 = p_Val_1;
  v49 = v5[14];
  v39 = v49;
  v63 = (char *)v5[15];
  v53 = (int)v63;
  v38 = v63;
  *(self + 769) = 0;
  n63 = *(self + 2468);
  v64 = 0;
  v65 = v5;
  v67[0] = 0;
  if ( n63 )
    FFX_VpxFrameDecoder_InitFilterParams((int)(self + 980), self, n63);
  memset((void *)(v5[13] - v5[4] - 1), 127, *v5 + 5);
  memset((void *)(v5[14] - v5[9] - 1), 127, v5[5] + 5);
  memset((void *)(v5[15] - v5[9] - 1), 127, v5[5] + 5);
  v12 = 0;
  v46 = 0;
  if ( (int)*(self + 1614) > 0 )
  {
    v50 = 8 * v55;
    p_Val_3 = p_Val_1;
    v41 = v63 - 1;
    v51 = 16 * v45;
    v54 = v49 - (_DWORD)v63;
    v59 = 0;
    v58 = 0;
    v52 = v49;
    while ( 1 )
    {
      if ( v60 > 1 )
      {
        v13 = v64 + 1;
        *(self + 798) = self + 7 * v64 + 3836;
        if ( v64 + 1 == v60 )
          v13 = 0;
        v64 = v13;
      }
      v56 = v58;
      v48 = &v41[1 - (_DWORD)v63];
      *(self + 779) = v2[1501];
      v14 = *(self + 780);
      *(_QWORD *)v14 = 0;
      *(_BYTE *)(v14 + 8) = 0;
      *(self + 792) = v59;
      *(self + 770) = 0;
      *(self + 793) = (v2[634] - v12 - 1) << 7;
      *(self + 771) = p_Val_3;
      v15 = p_Val_3 - 1;
      *(self + 772) = v52;
      *(self + 775) = &v41[v54];
      *(self + 774) = p_Val_3 - 1;
      *(self + 776) = v41;
      *(self + 773) = v41 + 1;
      *(self + 771) = &p_Val_3[-*(self + 743)];
      *(self + 772) = v52 - *(self + 748);
      *(self + 773) = &v41[-*(self + 748) + 1];
      *(self + 777) = *(self + 743);
      *(self + 778) = *(self + 748);
      v16 = *(self + 743);
      v42 = *(self + 748);
      n16 = 16;
      do
      {
        *v15 = -127;
        v15 += v16;
        --n16;
      }
      while ( n16 );
      v18 = &v41[v54];
      *v18 = -127;
      v18[v42] = -127;
      v18[2 * v42] = -127;
      v18[3 * v42] = -127;
      v18[4 * v42] = -127;
      v19 = 3 * v42;
      v18[5 * v42] = -127;
      v18[2 * v19] = -127;
      v20 = 7 * v42;
      v41[v54 + v20] = -127;
      *v41 = -127;
      v41[v42] = -127;
      v41[2 * v42] = -127;
      v41[3 * v42] = -127;
      v41[4 * v42] = -127;
      v41[5 * v42] = -127;
      v41[2 * v19] = -127;
      v41[v20] = -127;
      v2 = self + 980;
      v21 = 0;
      if ( (int)*(self + 1615) > 0 )
      {
        v22 = v41 + 1;
        v23 = 0;
        v43 = v41 + 1;
        v61 = 0;
        do
        {
          v24 = *(self + 766);
          *(self + 790) = v23;
          *(self + 791) = (*(self + 1615) - v21 - 1) << 7;
          *(self + 754) = v22;
          *(self + 752) = &p_Val_1[v56];
          *(self + 753) = &v22[v54];
          v25 = *(_BYTE *)(v24 + 2);
          if ( v25 )
          {
            *(self + 725) = v56 + v66[3 * v25];
            *(self + 726) = &v48[v66[3 * v25 + 1]];
            *(self + 727) = &v48[v66[3 * v25 + 2]];
          }
          else
          {
            *(self + 725) = 0;
            *(self + 726) = 0;
            *(self + 727) = 0;
          }
          *(self + 799) |= v67[*(unsigned char *)(v24 + 2)];
          FFX_VpxMB_DecodeAndReconstruct(self, self);
          v26 = *(self + 798);
          *(self + 770) = 1;
          n32 = *(_DWORD *)(v26 + 12);
          v28 = n32 > 32 && n32 < 0x40000000;
          *(self + 799) |= v28;
          *(self + 771) += 16;
          *(self + 772) += 8;
          *(self + 773) += 8;
          *(self + 774) += 16;
          *(self + 775) += 8;
          *(self + 776) += 8;
          v56 += 16;
          v48 += 8;
          *(self + 766) += 76;
          *(self + 779) += 9;
          v22 = v43 + 8;
          ++v21;
          v23 = v61 - 128;
          v43 += 8;
          v61 -= 128;
        }
        while ( v21 < *(self + 1615) );
      }
      v5 = v65;
      FFX_Video_ReconstructBorder((int)v65, *(self + 752) + 16, *(self + 753) + 8, *(self + 754) + 8);
      *(self + 766) += 76;
      v30 = v46;
      *(self + 769) = 1;
      if ( *(self + 2468) )
        break;
      if ( v46 <= 0 )
        goto LABEL_32;
      FFX_VpxFrameDecoder_DefaultCoefProbs(v29, p_Val_2, v39, v38);
      p_Val_2 += v51;
      v11 = 8 * v55;
      v39 += v50;
      v30 = v46;
      v38 += v50;
LABEL_33:
      v58 += v51;
      p_Val_3 += v51;
      v52 += v11;
      v41 += v11;
      v59 -= 128;
      v12 = v30 + 1;
      v46 = v12;
      if ( v12 >= v2[634] )
        goto LABEL_34;
    }
    if ( v46 > 0 )
    {
      v31 = v46 - 1;
      if ( *(self + 1630) )
        FFX_VpxFrameDecoder_LoopFilterMacroblock((int)(self + 980), v47, v31, v45, (int)v29, p_Val);
      else
        FFX_VpxFrameDecoder_ProcessMacroblock((int)(self + 980), v47, v31, v45, v55, p_Val, v49, v53);
      v30 = v46;
      if ( v46 <= 1 )
      {
        v11 = 8 * v55;
        v32 = 16 * v45;
      }
      else
      {
        FFX_VpxFrameDecoder_DefaultCoefProbs(v65, p_Val_2, v39, v38);
        v11 = 8 * v55;
        v32 = 16 * v45;
        p_Val_2 += v51;
        v39 += v50;
        v30 = v46;
        v38 += v50;
      }
      p_Val += v32;
      v49 += v11;
      v53 += v11;
      v47 += 76 * *(self + 1615) + 76;
      v2 = self + 980;
      goto LABEL_33;
    }
LABEL_32:
    v11 = 8 * v55;
    goto LABEL_33;
  }
LABEL_34:
  if ( v2[1488] )
  {
    v33 = v12 - 1;
    if ( v2[650] )
      FFX_VpxFrameDecoder_LoopFilterMacroblock((int)v2, v47, v33, v45, v11, p_Val);
    else
      FFX_VpxFrameDecoder_ProcessMacroblock((int)v2, v47, v33, v45, v55, p_Val, v49, v53);
    FFX_VpxFrameDecoder_DefaultCoefProbs(v5, p_Val_2, v39, v38);
    p_Val_4 = &p_Val_2[16 * v45];
    v35 = 8 * v55 + v39;
    v36 = &v38[8 * v55];
  }
  else
  {
    p_Val_4 = p_Val_2;
    v35 = v39;
    v36 = v38;
  }
  FFX_VpxFrameDecoder_DefaultCoefProbs(v5, p_Val_4, v35, v36);
  FFX_VpxFrameDecoder_IntraFrameModeInit(v5);
  return FFX_VpxFrameDecoder_InterFrameModeInit(v5);
}
