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

extern _DWORD FFX_Vpx_Const_B80700;
extern _DWORD FFX_Vpx_Const_B80C20;
extern _DWORD unk_B806F8;
extern _DWORD unk_B80800;
extern _DWORD FFX_VpxBoolDecoder_DecodeAllMacroblocks();
extern _DWORD FFX_VpxBoolDecoder_Fill();
extern _DWORD FFX_VpxBoolDecoder_Init();
extern _DWORD FFX_VpxBoolDecoder_ReadBool();
extern _DWORD FFX_VpxBoolDecoder_ReadLit();
extern _DWORD FFX_VpxDecoder_InitCoeffProbs();
extern _DWORD FFX_VpxError_Raise();
extern _DWORD FFX_VpxFrameDecoder_FilterAndRecon();
extern _DWORD FFX_VpxFrameDecoder_InitMotionVectorProbs();
extern _DWORD FFX_VpxFrameDecoder_InitPicture();
extern _DWORD FFX_VpxFrameDecoder_InitTokenProbs();
extern _DWORD FFX_VpxFrameDecoder_SetRefFrameConfig();
extern _DWORD FFX_VpxRefFrame_Recon();
extern _DWORD FFX_VpxToken_DecodeCoeff();
extern _DWORD frame();
extern _DWORD v7();
// Function: FFX_VpxFrameDecoder_DecodeFrame
// Address: 0x410830
// Size: 0xEA5
// FFX: VPX frame decoder decode frame — decodes a VP8 video frame (libvpx port)
// FFX VPX: Decode complete frame
int __fastcall FFX_VpxFrameDecoder_DecodeFrame(_DWORD *self)
{
  _DWORD *this_1; // edx
  unsigned char *p_n8_1; // esi
  unsigned int v3; // edi
  unsigned int n10; // eax
  unsigned int *v5; // ebx
  _DWORD *v6; // ecx
  void (__cdecl *v7)(_DWORD, unsigned int, _BYTE *, unsigned int); // ecx
  unsigned int v9; // edi
  unsigned int v10; // edx
  unsigned int v11; // ecx
  _DWORD *v12; // esi
  char v13; // al
  unsigned int v14; // esi
  unsigned int v15; // edx
  unsigned int v16; // ecx
  int v17; // ecx
  _DWORD *this_3; // esi
  char Bool; // al
  int i; // edi
  unsigned int v21; // esi
  bool v22; // sf
  unsigned int v23; // edx
  unsigned int v24; // eax
  unsigned int v25; // ecx
  int v26; // ecx
  bool v27; // zf
  char Lit; // al
  unsigned int v29; // esi
  unsigned int v30; // edx
  unsigned int v31; // eax
  unsigned int v32; // ecx
  int v33; // ecx
  unsigned int v34; // edx
  unsigned int v35; // esi
  unsigned int v36; // eax
  char *v37; // ecx
  int j; // edi
  unsigned int v39; // esi
  unsigned int v40; // edx
  unsigned int v41; // eax
  unsigned int v42; // ecx
  int v43; // ecx
  int v44; // edi
  unsigned int v45; // esi
  unsigned int v46; // edx
  unsigned int v47; // eax
  unsigned int v48; // ecx
  int v49; // ecx
  char v50; // al
  unsigned int v51; // esi
  unsigned int v52; // edx
  unsigned int v53; // ecx
  int v54; // ecx
  _DWORD *this_4; // esi
  char v56; // al
  unsigned int v57; // esi
  unsigned int v58; // edx
  unsigned int v59; // ecx
  int v60; // ecx
  int k; // edi
  unsigned int v62; // esi
  unsigned int v63; // edx
  unsigned int v64; // eax
  unsigned int v65; // ecx
  int v66; // ecx
  unsigned int v67; // esi
  unsigned int v68; // edx
  unsigned int v69; // eax
  unsigned int v70; // ecx
  int v71; // ecx
  int m; // edi
  unsigned int v73; // esi
  unsigned int v74; // edx
  unsigned int v75; // eax
  unsigned int v76; // ecx
  int v77; // ecx
  unsigned int v78; // esi
  unsigned int v79; // edx
  unsigned int v80; // eax
  unsigned int v81; // ecx
  int v82; // ecx
  int v83; // eax
  int Lit_1; // edx
  int v85; // eax
  int Lit_2; // edx
  int v87; // eax
  int Lit_3; // edx
  int v89; // eax
  int Lit_4; // edx
  int v91; // eax
  int Lit_5; // edx
  int v93; // eax
  int v94; // eax
  unsigned int v95; // esi
  unsigned int v96; // edx
  unsigned int v97; // ecx
  int v98; // ecx
  int v99; // eax
  unsigned int v100; // esi
  unsigned int v101; // edx
  unsigned int v102; // ecx
  int v103; // ecx
  int v104; // eax
  unsigned int v105; // esi
  unsigned int v106; // edx
  unsigned int v107; // ecx
  int v108; // ecx
  int v109; // eax
  unsigned int v110; // esi
  unsigned int v111; // edx
  unsigned int v112; // ecx
  int v113; // ecx
  int v114; // edi
  unsigned int v115; // esi
  unsigned int v116; // edx
  unsigned int v117; // eax
  unsigned int v118; // ecx
  int v119; // ecx
  int v120; // eax
  unsigned int v121; // esi
  unsigned int v122; // edx
  unsigned int v123; // ecx
  int v124; // ecx
  unsigned char *FFX_Vpx_Const_B80C20; // edx
  char *v126; // ecx
  int n; // edi
  unsigned int v128; // esi
  unsigned int v129; // edx
  unsigned int v130; // eax
  unsigned int v131; // ecx
  int v132; // ecx
  char v133; // al
  char *v134; // ecx
  int v135; // eax
  int *this_5; // esi
  _DWORD *v137; // edi
  int Size; // ebx
  _DWORD *src_1; // esi
  int v140; // ecx
  _DWORD *v141; // eax
  int v142; // edx
  int n32; // eax
  BOOL v144; // eax
  int v145; // eax
  _DWORD *this_6; // eax
  int v147; // [esp+Ch] [ebp-3Ch]
  unsigned int *v148; // [esp+10h] [ebp-38h]
  _DWORD *src; // [esp+14h] [ebp-34h]
  int v150; // [esp+18h] [ebp-30h]
  char *v151; // [esp+18h] [ebp-30h]
  int *FFX_Vpx_Const_B80700; // [esp+1Ch] [ebp-2Ch]
  unsigned char *FFX_Vpx_Const_B80C20_1; // [esp+1Ch] [ebp-2Ch]
  char *v154; // [esp+20h] [ebp-28h]
  int v155; // [esp+20h] [ebp-28h]
  _DWORD *v156; // [esp+24h] [ebp-24h]
  unsigned int p_n8; // [esp+2Ch] [ebp-1Ch] BYREF
  _DWORD *this_2; // [esp+30h] [ebp-18h]
  int v159; // [esp+34h] [ebp-14h]
  _BYTE p_n8_2[12]; // [esp+38h] [ebp-10h] BYREF

  this_1 = self;
  p_n8_1 = (unsigned char *)*(self + 3907);
  v147 = *(self + 3955);
  v3 = (unsigned int)&p_n8_1[*(self + 3916)];
  src = (_DWORD *)*(self + 976);
  *(self + 799) = 0;
  src[25] = 0;
  n10 = v3 - (_DWORD)p_n8_1;
  v5 = self + 3892;
  v6 = self + 980;
  this_2 = this_1;
  v148 = v5;
  v156 = v6;
  p_n8 = (unsigned int)p_n8_1;
  v159 = v3;
  if ( (int)(v3 - (_DWORD)p_n8_1) >= 3 )
  {
    v7 = (void (__cdecl *)(_DWORD, unsigned int, _BYTE *, unsigned int))this_1[3957];
    if ( v7 )
    {
      if ( n10 > 0xA )
        n10 = 10;
      v7(this_1[3958], p_n8, p_n8_2, n10);
      this_1 = this_2;
      p_n8_1 = p_n8_2;
    }
    this_1[1610] = *p_n8_1 & 1;
    this_1[3042] = (*p_n8_1 >> 1) & 7;
    this_1[1611] = (*p_n8_1 >> 4) & 1;
    v150 = (*p_n8_1 >> 5) | (*(unsigned short *)(p_n8_1 + 1) << 8 >> 5);
    if ( !this_1[3953] && (p_n8 + v150 > v3 || p_n8 + v150 < p_n8) )
    {
      FFX_VpxError_Raise((int)v156, 7, "Truncated packet or corrupt partition 0 length");
      this_1 = this_2;
    }
    p_n8 += 3;
    FFX_VpxFrameDecoder_SetRefFrameConfig(this_1 + 980);
    if ( v6[630] )
    {
      qmemcpy(this_1 + 712, src, 0x6Cu);
      qmemcpy(this_1 + 739, src, 0x6Cu);
      v3 = v159;
      p_n8_1 = (unsigned char *)p_n8;
      v6 = this_1 + 980;
    }
    else
    {
      if ( (!this_1[3953] || p_n8 + 3 < v3) && (p_n8_1[3] != 0x9D || p_n8_1[4] != 1 || p_n8_1[5] != 42) )
      {
        FFX_VpxError_Raise((int)v6, 5, "Invalid frame sync code");
        this_1 = this_2;
        v6 = v156;
      }
      if ( !this_1[3953] || p_n8 + 6 < v3 )
      {
        this_1[1404] = *((_WORD *)p_n8_1 + 3) & 0x3FFF;
        this_1[1406] = p_n8_1[7] >> 6;
        this_1[1405] = *((_WORD *)p_n8_1 + 4) & 0x3FFF;
        v6 = this_1 + 980;
        this_1[1407] = p_n8_1[9] >> 6;
      }
      p_n8_1 = (unsigned char *)(p_n8 + 7);
      p_n8 += 7;
    }
  }
  else
  {
    if ( !this_1[3953] )
    {
      FFX_VpxError_Raise((int)v6, 7, "Truncated packet");
      this_1 = this_2;
      v6 = v156;
    }
    v6[630] = 1;
    v6[2062] = 0;
    v6[631] = 1;
    v150 = 0;
  }
  if ( !this_1[3954] && v6[630] )
    return -1;
  FFX_VpxDecoder_InitCoeffProbs((int)this_1);
  v9 = v3 - (_DWORD)p_n8_1;
  v10 = this_2[3958];
  v11 = this_2[3957];
  *v5 = (unsigned int)&p_n8_1[v9];
  v5[1] = (unsigned int)p_n8_1;
  v5[2] = 0;
  v5[3] = -8;
  v5[4] = 255;
  v5[5] = v11;
  v5[6] = v10;
  if ( !v9 || p_n8_1 )
  {
    FFX_VpxBoolDecoder_Fill(v5);
    v12 = v156;
  }
  else
  {
    v12 = v156;
    FFX_VpxError_Raise((int)v156, 2, "Failed to allocate bool decoder 0");
  }
  if ( !v12[630] )
  {
    FFX_VpxBoolDecoder_ReadBool(v5, 128);
    v12[428] = FFX_VpxBoolDecoder_ReadBool(v5, 128);
  }
  v13 = 0;
  v14 = ((v5[4] - 1) << 7 >> 8) + 1;
  if ( (v5[3] & 0x80000000) != 0 )
  {
    FFX_VpxBoolDecoder_Fill(v5);
    v13 = 0;
  }
  v15 = v5[2];
  v16 = v14 << 24;
  if ( v15 >= v14 << 24 )
  {
    v14 = v5[4] - v14;
    v15 -= v16;
    v13 = 1;
  }
  v17 = (unsigned char)FFX_Vpx_Const_B80700[v14];
  v5[3] -= v17;
  v5[4] = v14 << v17;
  this_3 = this_2;
  v5[2] = v15 << v17;
  *((_BYTE *)this_3 + 3124) = v13;
  if ( v13 )
  {
    *((_BYTE *)this_3 + 3125) = FFX_VpxBoolDecoder_ReadBool(v5, 128);
    Bool = FFX_VpxBoolDecoder_ReadBool(v5, 128);
    *((_BYTE *)this_3 + 3126) = Bool;
    if ( Bool )
    {
      *((_BYTE *)this_3 + 3127) = FFX_VpxBoolDecoder_ReadBool(v5, 128);
      v154 = (char *)this_3 + 3131;
      *(_QWORD *)((char *)this_3 + 3131) = 0;
      FFX_Vpx_Const_B80700 = (int *)&unk_B806F8;
      do
      {
        for ( i = 0; i < 4; ++i )
        {
          v21 = ((v5[4] - 1) << 7 >> 8) + 1;
          v22 = (v5[3] & 0x80000000) != 0;
          v159 = 0;
          if ( v22 )
            FFX_VpxBoolDecoder_Fill(v5);
          v23 = v5[2];
          v24 = v5[3];
          v25 = v21 << 24;
          if ( v23 >= v21 << 24 )
          {
            v21 = v5[4] - v21;
            v24 = v5[3];
            v23 -= v25;
            v159 = 1;
          }
          v26 = (unsigned char)FFX_Vpx_Const_B80700[v21];
          v27 = v159 == 0;
          v5[2] = v23 << v26;
          v5[3] = v24 - v26;
          v5[4] = v21 << v26;
          if ( v27 )
          {
            v37 = v154;
            v154[i] = 0;
          }
          else
          {
            Lit = FFX_VpxBoolDecoder_ReadLit(v5, *FFX_Vpx_Const_B80700);
            v159 = 0;
            v154[i] = Lit;
            v29 = ((v5[4] - 1) << 7 >> 8) + 1;
            if ( (v5[3] & 0x80000000) != 0 )
              FFX_VpxBoolDecoder_Fill(v5);
            v30 = v5[2];
            v31 = v5[3];
            v32 = v29 << 24;
            if ( v30 >= v29 << 24 )
            {
              v29 = v5[4] - v29;
              v31 = v5[3];
              v30 -= v32;
              v159 = 1;
            }
            v33 = (unsigned char)FFX_Vpx_Const_B80700[v29];
            v34 = v30 << v33;
            v35 = v29 << v33;
            v36 = v31 - v33;
            v27 = v159 == 0;
            v37 = v154;
            v5[2] = v34;
            v5[3] = v36;
            v5[4] = v35;
            if ( !v27 )
              v154[i] = -v154[i];
          }
        }
        v154 = v37 + 4;
        ++FFX_Vpx_Const_B80700;
      }
      while ( (int)FFX_Vpx_Const_B80700 < (int)FFX_Vpx_Const_B80700 );
      this_3 = this_2;
    }
    if ( *((_BYTE *)this_3 + 3125) )
    {
      *((_WORD *)this_3 + 1564) = -1;
      *((_BYTE *)this_3 + 3130) = -1;
      for ( j = 0; j < 3; ++j )
      {
        v39 = ((v5[4] - 1) << 7 >> 8) + 1;
        v22 = (v5[3] & 0x80000000) != 0;
        v159 = 0;
        if ( v22 )
          FFX_VpxBoolDecoder_Fill(v5);
        v40 = v5[2];
        v41 = v5[3];
        v42 = v39 << 24;
        if ( v40 >= v39 << 24 )
        {
          v39 = v5[4] - v39;
          v41 = v5[3];
          v40 -= v42;
          v159 = 1;
        }
        v43 = (unsigned char)FFX_Vpx_Const_B80700[v39];
        v27 = v159 == 0;
        v5[2] = v40 << v43;
        v5[3] = v41 - v43;
        v5[4] = v39 << v43;
        if ( !v27 )
          *((_BYTE *)this_2 + j + 3128) = FFX_VpxBoolDecoder_ReadLit(v5, 8);
      }
    }
  }
  else
  {
    *(_WORD *)((char *)this_3 + 3125) = 0;
  }
  v44 = 0;
  v45 = ((v5[4] - 1) << 7 >> 8) + 1;
  if ( (v5[3] & 0x80000000) != 0 )
    FFX_VpxBoolDecoder_Fill(v5);
  v46 = v5[2];
  v47 = v5[3];
  v48 = v45 << 24;
  if ( v46 >= v45 << 24 )
  {
    v45 = v5[4] - v45;
    v47 = v5[3];
    v46 -= v48;
    v44 = 1;
  }
  v49 = (unsigned char)FFX_Vpx_Const_B80700[v45];
  v5[3] = v47 - v49;
  v5[4] = v45 << v49;
  v5[2] = v46 << v49;
  v156[650] = v44;
  v156[1488] = FFX_VpxBoolDecoder_ReadLit(v5, 6);
  v156[1490] = FFX_VpxBoolDecoder_ReadLit(v5, 3);
  *((_BYTE *)this_2 + 3140) = 0;
  v50 = 0;
  v51 = ((v5[4] - 1) << 7 >> 8) + 1;
  if ( (v5[3] & 0x80000000) != 0 )
  {
    FFX_VpxBoolDecoder_Fill(v5);
    v50 = 0;
  }
  v52 = v5[2];
  v53 = v51 << 24;
  if ( v52 >= v51 << 24 )
  {
    v51 = v5[4] - v51;
    v52 -= v53;
    v50 = 1;
  }
  v54 = (unsigned char)FFX_Vpx_Const_B80700[v51];
  v5[3] -= v54;
  v5[4] = v51 << v54;
  this_4 = this_2;
  v5[2] = v52 << v54;
  *((_BYTE *)this_4 + 3139) = v50;
  if ( v50 )
  {
    v56 = 0;
    v57 = ((v5[4] - 1) << 7 >> 8) + 1;
    if ( (v5[3] & 0x80000000) != 0 )
    {
      FFX_VpxBoolDecoder_Fill(v5);
      v56 = 0;
    }
    v58 = v5[2];
    v59 = v57 << 24;
    if ( v58 >= v57 << 24 )
    {
      v57 = v5[4] - v57;
      v58 -= v59;
      v56 = 1;
    }
    v60 = (unsigned char)FFX_Vpx_Const_B80700[v57];
    v5[3] -= v60;
    v5[4] = v57 << v60;
    this_4 = this_2;
    v5[2] = v58 << v60;
    *((_BYTE *)this_4 + 3140) = v56;
    if ( v56 )
    {
      for ( k = 0; k < 4; ++k )
      {
        v62 = ((v5[4] - 1) << 7 >> 8) + 1;
        v22 = (v5[3] & 0x80000000) != 0;
        v159 = 0;
        if ( v22 )
          FFX_VpxBoolDecoder_Fill(v5);
        v63 = v5[2];
        v64 = v5[3];
        v65 = v62 << 24;
        if ( v63 >= v62 << 24 )
        {
          v62 = v5[4] - v62;
          v64 = v5[3];
          v63 -= v65;
          v159 = 1;
        }
        v66 = (unsigned char)FFX_Vpx_Const_B80700[v62];
        v27 = v159 == 0;
        v5[2] = v63 << v66;
        v5[3] = v64 - v66;
        v5[4] = v62 << v66;
        if ( !v27 )
        {
          v159 = 0;
          *((_BYTE *)this_2 + k + 3145) = FFX_VpxBoolDecoder_ReadLit(v5, 6);
          v67 = ((v5[4] - 1) << 7 >> 8) + 1;
          if ( (v5[3] & 0x80000000) != 0 )
            FFX_VpxBoolDecoder_Fill(v5);
          v68 = v5[2];
          v69 = v5[3];
          v70 = v67 << 24;
          if ( v68 >= v67 << 24 )
          {
            v67 = v5[4] - v67;
            v69 = v5[3];
            v68 -= v70;
            v159 = 1;
          }
          v71 = (unsigned char)FFX_Vpx_Const_B80700[v67];
          v27 = v159 == 0;
          v5[2] = v68 << v71;
          v5[3] = v69 - v71;
          v5[4] = v67 << v71;
          if ( !v27 )
            *((_BYTE *)this_2 + k + 3145) = -*((_BYTE *)this_2 + k + 3145);
        }
      }
      for ( m = 0; m < 4; ++m )
      {
        v73 = ((v5[4] - 1) << 7 >> 8) + 1;
        v22 = (v5[3] & 0x80000000) != 0;
        v159 = 0;
        if ( v22 )
          FFX_VpxBoolDecoder_Fill(v5);
        v74 = v5[2];
        v75 = v5[3];
        v76 = v73 << 24;
        if ( v74 >= v73 << 24 )
        {
          v73 = v5[4] - v73;
          v75 = v5[3];
          v74 -= v76;
          v159 = 1;
        }
        v77 = (unsigned char)FFX_Vpx_Const_B80700[v73];
        v27 = v159 == 0;
        v5[2] = v74 << v77;
        v5[3] = v75 - v77;
        v5[4] = v73 << v77;
        if ( v27 )
        {
          this_4 = this_2;
        }
        else
        {
          v159 = 0;
          *((_BYTE *)this_2 + m + 3153) = FFX_VpxBoolDecoder_ReadLit(v5, 6);
          v78 = ((v5[4] - 1) << 7 >> 8) + 1;
          if ( (v5[3] & 0x80000000) != 0 )
            FFX_VpxBoolDecoder_Fill(v5);
          v79 = v5[2];
          v80 = v5[3];
          v81 = v78 << 24;
          if ( v79 >= v78 << 24 )
          {
            v78 = v5[4] - v78;
            v80 = v5[3];
            v79 -= v81;
            v159 = 1;
          }
          v82 = (unsigned char)FFX_Vpx_Const_B80700[v78];
          v27 = v159 == 0;
          v5[4] = v78 << v82;
          this_4 = this_2;
          v5[2] = v79 << v82;
          v5[3] = v80 - v82;
          if ( !v27 )
            *((_BYTE *)this_4 + m + 3153) = -*((_BYTE *)this_4 + m + 3153);
        }
      }
    }
  }
  FFX_VpxBoolDecoder_Init(this_4, v150 + p_n8);
  this_4[798] = this_4 + 3836;
  v83 = FFX_VpxBoolDecoder_ReadLit(v5, 7);
  Lit_1 = this_4[1622];
  this_4[1621] = v83;
  p_n8 = 0;
  v85 = FFX_VpxToken_DecodeCoeff(v5, Lit_1, &p_n8);
  Lit_2 = this_4[1623];
  this_4[1622] = v85;
  v87 = FFX_VpxToken_DecodeCoeff(v5, Lit_2, &p_n8);
  Lit_3 = this_4[1624];
  this_4[1623] = v87;
  v89 = FFX_VpxToken_DecodeCoeff(v5, Lit_3, &p_n8);
  Lit_4 = this_4[1625];
  this_4[1624] = v89;
  v91 = FFX_VpxToken_DecodeCoeff(v5, Lit_4, &p_n8);
  Lit_5 = this_4[1626];
  this_4[1625] = v91;
  v93 = FFX_VpxToken_DecodeCoeff(v5, Lit_5, &p_n8);
  v27 = p_n8 == 0;
  this_4[1626] = v93;
  if ( !v27 )
    FFX_VpxFrameDecoder_InitTokenProbs(this_4);
  FFX_VpxFrameDecoder_InitMotionVectorProbs(this_4, this_4);
  if ( this_4[1610] )
  {
    v94 = 0;
    v95 = ((v5[4] - 1) << 7 >> 8) + 1;
    if ( (v5[3] & 0x80000000) != 0 )
    {
      FFX_VpxBoolDecoder_Fill(v5);
      v94 = 0;
    }
    v96 = v5[2];
    v97 = v95 << 24;
    if ( v96 >= v95 << 24 )
    {
      v95 = v5[4] - v95;
      v96 -= v97;
      v94 = 1;
    }
    v98 = (unsigned char)FFX_Vpx_Const_B80700[v95];
    v5[3] -= v98;
    v5[4] = v95 << v98;
    v5[2] = v96 << v98;
    v156[1492] = v94;
    v99 = 0;
    v100 = ((v5[4] - 1) << 7 >> 8) + 1;
    if ( (v5[3] & 0x80000000) != 0 )
    {
      FFX_VpxBoolDecoder_Fill(v5);
      v99 = 0;
    }
    v101 = v5[2];
    v102 = v100 << 24;
    if ( v101 >= v100 << 24 )
    {
      v100 = v5[4] - v100;
      v101 -= v102;
      v99 = 1;
    }
    v103 = (unsigned char)FFX_Vpx_Const_B80700[v100];
    v5[3] -= v103;
    v5[4] = v100 << v103;
    v5[2] = v101 << v103;
    v27 = v156[1492] == 0;
    v156[1493] = v99;
    v156[1494] = 0;
    if ( v27 )
      v156[1494] = FFX_VpxBoolDecoder_ReadLit(v5, 2);
    v27 = v156[1493] == 0;
    v156[1495] = 0;
    if ( v27 )
      v156[1495] = FFX_VpxBoolDecoder_ReadLit(v5, 2);
    v104 = 0;
    v105 = ((v5[4] - 1) << 7 >> 8) + 1;
    if ( (v5[3] & 0x80000000) != 0 )
    {
      FFX_VpxBoolDecoder_Fill(v5);
      v104 = 0;
    }
    v106 = v5[2];
    v107 = v105 << 24;
    if ( v106 >= v105 << 24 )
    {
      v105 = v5[4] - v105;
      v106 -= v107;
      v104 = 1;
    }
    v108 = (unsigned char)FFX_Vpx_Const_B80700[v105];
    v5[3] -= v108;
    v5[4] = v105 << v108;
    v5[2] = v106 << v108;
    v156[1499] = v104;
    v109 = 0;
    v110 = ((v5[4] - 1) << 7 >> 8) + 1;
    if ( (v5[3] & 0x80000000) != 0 )
    {
      FFX_VpxBoolDecoder_Fill(v5);
      v109 = 0;
    }
    v111 = v5[2];
    v112 = v110 << 24;
    if ( v111 >= v110 << 24 )
    {
      v110 = v5[4] - v110;
      v111 -= v112;
      v109 = 1;
    }
    v113 = (unsigned char)FFX_Vpx_Const_B80700[v110];
    v5[3] -= v113;
    v5[2] = v111 << v113;
    v5[4] = v110 << v113;
    v156[1500] = v109;
  }
  v114 = 0;
  v115 = ((v5[4] - 1) << 7 >> 8) + 1;
  if ( (v5[3] & 0x80000000) != 0 )
    FFX_VpxBoolDecoder_Fill(v5);
  v116 = v5[2];
  v117 = v5[3];
  v118 = v115 << 24;
  if ( v116 >= v115 << 24 )
  {
    v115 = v5[4] - v115;
    v117 = v5[3];
    v116 -= v118;
    v114 = 1;
  }
  v119 = (unsigned char)FFX_Vpx_Const_B80700[v115];
  v5[3] = v117 - v119;
  v5[2] = v116 << v119;
  v5[4] = v115 << v119;
  v156[1496] = v114;
  if ( !v114 )
    qmemcpy((char *)v156 + 6017, (char *)v156 + 7130, 0x459u);
  if ( !v156[630] )
    goto LABEL_145;
  v120 = 0;
  v121 = ((v5[4] - 1) << 7 >> 8) + 1;
  if ( (v5[3] & 0x80000000) != 0 )
  {
    FFX_VpxBoolDecoder_Fill(v5);
    v120 = 0;
  }
  v122 = v5[2];
  v123 = v121 << 24;
  if ( v122 >= v121 << 24 )
  {
    v121 = v5[4] - v121;
    v122 -= v123;
    v120 = 1;
  }
  v124 = (unsigned char)FFX_Vpx_Const_B80700[v121];
  v5[3] -= v124;
  v5[2] = v122 << v124;
  v5[4] = v121 << v124;
  if ( v120 )
LABEL_145:
    v120 = 1;
  FFX_Vpx_Const_B80C20 = (unsigned char *)&unk_B80800;
  v156[1491] = v120;
  v126 = (char *)v156 + 7149;
  this_2[3955] = 1;
  do
  {
    p_n8 = 8;
    do
    {
      v155 = 0;
      FFX_Vpx_Const_B80C20_1 = FFX_Vpx_Const_B80C20;
      v151 = v126;
      do
      {
        for ( n = 0; n < 11; ++n )
        {
          v128 = (((v5[4] - 1) * FFX_Vpx_Const_B80C20[n]) >> 8) + 1;
          v22 = (v5[3] & 0x80000000) != 0;
          v159 = 0;
          if ( v22 )
            FFX_VpxBoolDecoder_Fill(v5);
          v129 = v5[2];
          v130 = v5[3];
          v131 = v128 << 24;
          if ( v129 >= v128 << 24 )
          {
            v128 = v5[4] - v128;
            v130 = v5[3];
            v129 -= v131;
            v159 = 1;
          }
          v132 = (unsigned char)FFX_Vpx_Const_B80700[v128];
          v27 = v159 == 0;
          v5[2] = v129 << v132;
          v5[3] = v130 - v132;
          v5[4] = v128 << v132;
          if ( v27 )
          {
            v134 = v151;
          }
          else
          {
            v133 = FFX_VpxBoolDecoder_ReadLit(v5, 8);
            v134 = v151;
            v151[n] = v133;
          }
          v135 = v155;
          this_5 = this_2;
          if ( v155 > 0 )
          {
            v135 = v155;
            if ( v134[n] != v134[n - 11] )
              this_2[3955] = 0;
          }
          FFX_Vpx_Const_B80C20 = FFX_Vpx_Const_B80C20_1;
        }
        v126 = v134 + 11;
        FFX_Vpx_Const_B80C20 = FFX_Vpx_Const_B80C20_1 + 11;
        v155 = v135 + 1;
        v151 = v126;
        FFX_Vpx_Const_B80C20_1 += 11;
      }
      while ( v135 + 1 < 3 );
      --p_n8;
    }
    while ( p_n8 );
  }
  while ( (int)FFX_Vpx_Const_B80C20 < (int)FFX_Vpx_Const_B80C20 );
  memset(this_5 + 96, 0, 0x320u);
  FFX_VpxBoolDecoder_DecodeAllMacroblocks(this_5);
  v137 = this_5 + 980;
  memset((void *)this_5[2481], 0, 9 * this_5[1615]);
  v27 = this_5[3925] == 0;
  this_5[3956] = 0;
  if ( v27 || !this_5[3043] )
  {
    FFX_VpxFrameDecoder_InitPicture(this_5);
    v142 = this_5[799];
  }
  else
  {
    FFX_VpxFrameDecoder_FilterAndRecon(this_5, this_5);
    Size = src[19] / 2;
    src_1 = src;
    FFX_VpxRefFrame_Recon(
      src[13],
      src[4],
      src[2],
      src[3],
      src[19],
      src[19],
      src[19] + src[1] - src[3],
      src[19] + *src - src[2]);
    FFX_VpxRefFrame_Recon(
      src_1[14],
      src_1[9],
      src_1[7],
      src_1[8],
      Size,
      Size,
      src_1[6] + Size - src_1[8],
      src_1[5] + Size - src_1[7]);
    FFX_VpxRefFrame_Recon(
      src_1[15],
      src_1[9],
      src_1[7],
      src_1[8],
      Size,
      Size,
      src_1[6] + Size - src_1[8],
      src_1[5] + Size - src_1[7]);
    this_5 = this_2;
    v140 = this_2[3928];
    if ( v140 )
    {
      v141 = (_DWORD *)(this_2[3942] + 3196);
      v142 = 0;
      do
      {
        v142 |= *v141;
        v141 += 976;
        --v140;
      }
      while ( v140 );
    }
    else
    {
      v142 = 0;
    }
    v5 = v148;
    v137 = this_2 + 980;
  }
  n32 = v5[3];
  v144 = n32 > 32 && n32 < 0x40000000;
  v145 = v142 | v144;
  src[25] = v145;
  if ( !this_5[3954] )
  {
    if ( v137[630] || v145 )
      FFX_VpxError_Raise((int)v137, 7, "A stream must start with a complete key frame");
    else
      this_5[3954] = 1;
  }
  if ( !v137[1496] )
  {
    this_6 = this_2;
    qmemcpy((char *)v137 + 7130, (char *)v137 + 6017, 0x459u);
    this_6[3955] = v147;
  }
  return 0;
}
