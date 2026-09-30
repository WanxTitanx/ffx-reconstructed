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

// Function: FFX_VpxResidual_IDCT
// Address: 0x414830
// Size: 0x7BF
// FFX: VPX residual IDCT — inverse DCT for VP8 residual coefficients
// FFX VPX: Inverse DCT transform for residual
char __fastcall FFX_VpxResidual_IDCT(
        unsigned char *a1,
        unsigned char *a2,
        int n255,
        int a4,
        _BYTE *n255a,
        int n255_13,
        unsigned char a7)
{
  int n255a_1; // eax
  unsigned char v9; // dl
  int n4; // esi
  int v11; // ecx
  unsigned char v12; // dl
  int n4_1; // esi
  _BYTE *v14; // ecx
  int v15; // edx
  int n255_2; // eax
  int n255_3; // eax
  int n255_4; // eax
  int v19; // ebx
  int v20; // edi
  int v21; // edx
  int v22; // esi
  int v23; // ecx
  int v24; // edx
  int v25; // ecx
  char v26; // bl
  int n4_2; // edx
  int n4_3; // edx
  _BYTE *v29; // ecx
  _BYTE *v30; // ebx
  unsigned char *v31; // esi
  int v32; // edx
  int v33; // edx
  _BYTE *v34; // edi
  int v35; // edx
  int v36; // ecx
  _BYTE *v37; // esi
  int v38; // edx
  unsigned char *v39; // edx
  int v40; // ecx
  int v41; // ecx
  unsigned char v42; // bl
  int v43; // esi
  int v44; // edx
  int v45; // edi
  int v46; // ecx
  int v47; // ecx
  int n255_5; // esi
  int v49; // ecx
  int v50; // esi
  int v51; // ecx
  int n255_6; // edi
  int v53; // esi
  int v54; // edx
  int v55; // ecx
  int v56; // ecx
  unsigned char v57; // bl
  unsigned char v58; // bh
  int v59; // esi
  int v60; // edx
  int v61; // edx
  int v62; // ecx
  int v63; // ebx
  int n255_7; // esi
  int v65; // ecx
  int v66; // ecx
  int n255_8; // edi
  int v68; // esi
  int v69; // esi
  int v70; // ecx
  int v71; // ecx
  int v72; // edx
  int v73; // edx
  int v74; // ecx
  unsigned char *v75; // esi
  _BYTE *v76; // ebx
  int n255_9; // edx
  int v78; // ecx
  _BYTE *v79; // edi
  int v80; // edx
  _BYTE *v81; // esi
  int v82; // ecx
  int v83; // ecx
  int v84; // ecx
  int v85; // edx
  unsigned char *v86; // edx
  int v87; // ecx
  int v88; // ecx
  int v89; // esi
  _BYTE *v90; // edi
  int v91; // ebx
  int n255_10; // edx
  int v93; // ecx
  int v94; // edx
  int v95; // ecx
  int n255_11; // esi
  int v97; // ecx
  int v98; // ecx
  int v99; // ecx
  int v100; // ecx
  int v101; // esi
  int v102; // ecx
  int n255_12; // edx
  int v104; // edx
  int v105; // edx
  int v106; // esi
  int v107; // edi
  int v108; // ecx
  int v109; // edx
  int v110; // ecx
  int v111; // ecx
  _BYTE *v112; // esi
  int v113; // ecx
  int v114; // ecx
  int v116; // [esp+Ch] [ebp-34h]
  int v117; // [esp+10h] [ebp-30h]
  int v118; // [esp+14h] [ebp-2Ch]
  unsigned char v119; // [esp+1Bh] [ebp-25h]
  int v120; // [esp+1Ch] [ebp-24h]
  int n255_1; // [esp+20h] [ebp-20h]
  unsigned char v122; // [esp+26h] [ebp-1Ah]
  unsigned char v123; // [esp+27h] [ebp-19h]
  unsigned char v124; // [esp+28h] [ebp-18h]
  unsigned char v125; // [esp+29h] [ebp-17h]
  unsigned char v126; // [esp+2Ah] [ebp-16h]
  unsigned char v127; // [esp+2Bh] [ebp-15h]
  _DWORD v128[4]; // [esp+2Ch] [ebp-14h]

  n255a_1 = (int)n255a;
  v127 = *a2;
  LOBYTE(v118) = v127;
  v125 = a2[n255];
  BYTE1(v118) = v125;
  v126 = a2[2 * n255];
  BYTE2(v118) = v126;
  v120 = (int)a1;
  v9 = a2[2 * n255 + n255];
  n255_1 = n255_13;
  v123 = v9;
  HIBYTE(v118) = v9;
  switch ( a4 )
  {
    case 0:
      n4 = 4;
      v11 = (*a1 + 4 + v127 + v125 + v126 + v123 + a1[1] + a1[2] + a1[3]) >> 3;
      v118 = (*a1 + 4 + v127 + v125 + v126 + v123 + a1[1] + a1[2] + a1[3]) >> 3;
      do
      {
        v12 = v11;
        LOBYTE(v11) = v118;
        *(_DWORD *)n255a_1 = 16843009 * v12;
        n255a_1 += n255_13;
        --n4;
      }
      while ( n4 );
      break;
    case 1:
      v120 = a7;
      n4_1 = 0;
      v14 = n255a + 2;
      n255_1 = 255;
      do
      {
        v15 = *((unsigned char *)&v118 + n4_1);
        n255_2 = v15 + *a1 - v120;
        if ( n255_2 >= 0 )
        {
          if ( n255_2 > 255 )
            LOBYTE(n255_2) = n255_1;
        }
        else
        {
          LOBYTE(n255_2) = 0;
        }
        *(v14 - 2) = n255_2;
        n255_3 = v15 + a1[1] - v120;
        if ( n255_3 >= 0 )
        {
          if ( n255_3 > 255 )
            LOBYTE(n255_3) = n255_1;
        }
        else
        {
          LOBYTE(n255_3) = 0;
        }
        *(v14 - 1) = n255_3;
        n255_4 = v15 + a1[2] - v120;
        if ( n255_4 >= 0 )
        {
          if ( n255_4 > 255 )
            LOBYTE(n255_4) = n255_1;
        }
        else
        {
          LOBYTE(n255_4) = 0;
        }
        *v14 = n255_4;
        n255a_1 = v15 + a1[3] - v120;
        if ( n255a_1 >= 0 )
        {
          if ( n255a_1 > 255 )
            LOBYTE(n255a_1) = -1;
        }
        else
        {
          LOBYTE(n255a_1) = 0;
        }
        v14[1] = n255a_1;
        ++n4_1;
        v14 += n255_13;
      }
      while ( n4_1 < 4 );
      break;
    case 2:
      v19 = v120;
      v20 = a1[1];
      v21 = *(unsigned char *)v120;
      v22 = *(unsigned char *)(v120 + 2);
      v120 = (v20 + a7 + 2 * v21 + 2) >> 2;
      v23 = v21 + 2 + v22 + 2 * v20;
      v24 = *(unsigned char *)(v19 + 3);
      v118 = v23 >> 2;
      v117 = (v20 + v24 + 2 * (v22 + 1)) >> 2;
      v25 = *(unsigned char *)(v19 + 4);
      v26 = v118;
      v116 = (v22 + v25 + 2 * v24 + 2) >> 2;
      n4_2 = 4;
      do
      {
        *(_BYTE *)n255a_1 = v120;
        *(_BYTE *)(n255a_1 + 2) = v117;
        *(_BYTE *)(n255a_1 + 1) = v26;
        *(_BYTE *)(n255a_1 + 3) = v116;
        n255a_1 += n255_1;
        --n4_2;
      }
      while ( n4_2 );
      break;
    case 3:
      v128[0] = (v125 + a7 + 2 * v127 + 2) >> 2;
      v128[1] = (v127 + 2 + v126 + 2 * v125) >> 2;
      v128[2] = (v125 + v123 + 2 * (v126 + 1)) >> 2;
      v128[3] = (v123 + v126 + 2 * (v123 + 1)) >> 2;
      n4_3 = 0;
      v29 = n255a + 2;
      do
      {
        LOBYTE(n255a_1) = v128[n4_3];
        *(v29 - 2) = n255a_1;
        *(v29 - 1) = n255a_1;
        *v29 = n255a_1;
        v29[1] = n255a_1;
        ++n4_3;
        v29 += n255_13;
      }
      while ( n4_3 < 4 );
      break;
    case 4:
      v30 = &n255a[n255_13];
      *n255a = (*a1 + a1[2] + 2 + 2 * a1[1]) >> 2;
      v31 = (unsigned char *)v120;
      v32 = (a1[1] + a1[3] + 2 + 2 * a1[2]) >> 2;
      *v30 = v32;
      n255a[1] = v32;
      v33 = (a1[2] + a1[4] + 2 + 2 * a1[3]) >> 2;
      v34 = &n255a[2 * n255_1];
      *v34 = v33;
      v30[1] = v33;
      n255a[2] = v33;
      v35 = v31[3] + 2 + 2 * v31[4];
      v36 = v31[5];
      v37 = &n255a[2 * n255_1 + n255_1];
      v38 = (v36 + v35) >> 2;
      *v37 = v38;
      v34[1] = v38;
      v30[2] = v38;
      n255a[3] = v38;
      v39 = (unsigned char *)v120;
      v40 = (*(unsigned char *)(v120 + 6) + *(unsigned char *)(v120 + 4) + 2 + 2 * *(unsigned char *)(v120 + 5)) >> 2;
      v37[1] = v40;
      v34[2] = v40;
      v30[3] = v40;
      v41 = (v39[5] + v39[7] + 2 + 2 * v39[6]) >> 2;
      v37[2] = v41;
      v34[3] = v41;
      n255a_1 = (3 * v39[7] + v39[6] + 2) >> 2;
      v37[3] = n255a_1;
      break;
    case 5:
      v42 = *a1;
      v119 = a1[1];
      v122 = a1[2];
      v43 = v125;
      v124 = a1[3];
      v44 = v126;
      v118 = (int)&n255a[2 * n255_1 + n255_1];
      *(_BYTE *)v118 = (v125 + v123 + 2 * v126 + 2) >> 2;
      v45 = v127;
      v46 = (v127 + v44 + 2 + 2 * v43) >> 2;
      n255a[2 * n255_1] = v46;
      *(_BYTE *)(v118 + 1) = v46;
      v47 = v43 + 2;
      n255_5 = n255_1;
      v49 = (a7 + v47 + 2 * v45) >> 2;
      n255a[n255_1] = v49;
      n255a[2 * n255_5 + 1] = v49;
      v50 = v118;
      *(_BYTE *)(v118 + 2) = v49;
      v51 = v45 + 2 + v42 + 2 * a7;
      n255_6 = n255_1;
      v51 >>= 2;
      *n255a = v51;
      n255a[n255_6 + 1] = v51;
      n255a[2 * n255_6 + 2] = v51;
      *(_BYTE *)(v50 + 3) = v51;
      v53 = v119;
      v54 = v122;
      v55 = (a7 + 2 + v119 + 2 * v42) >> 2;
      n255a[1] = v55;
      n255a[n255_6 + 2] = v55;
      n255a[2 * n255_6 + 3] = v55;
      v56 = (v42 + v54 + 2 * (v53 + 1)) >> 2;
      n255a[2] = v56;
      n255a[n255_6 + 3] = v56;
      n255a[3] = (v53 + v124 + 2 * v54 + 2) >> 2;
      break;
    case 6:
      v57 = *a1;
      v58 = a1[1];
      v124 = a1[2];
      v122 = a1[3];
      v59 = v127;
      v60 = v125;
      v118 = (int)&n255a[2 * n255_1 + n255_1];
      *(_BYTE *)v118 = (v127 + v126 + 2 * v125 + 2) >> 2;
      n255a[2 * n255_1] = (a7 + v60 + 2 + 2 * v59) >> 2;
      v61 = v57;
      v62 = (v59 + 2 + v57 + 2 * a7) >> 2;
      n255a[n255_1] = v62;
      v63 = v58;
      *(_BYTE *)(v118 + 1) = v62;
      n255_7 = n255_1;
      v65 = (v61 + a7 + 1) >> 1;
      *n255a = v65;
      n255a[2 * n255_7 + 1] = v65;
      v66 = (a7 + 2 + v63 + 2 * v61) >> 2;
      n255_8 = n255_7;
      v68 = v118;
      n255a[n255_8 + 1] = v66;
      *(_BYTE *)(v68 + 2) = v66;
      v69 = v124;
      v70 = (v63 + v61 + 1) >> 1;
      n255a[1] = v70;
      n255a[2 * n255_8 + 2] = v70;
      v71 = v61 + 2 + v69 + 2 * v63;
      v72 = v118;
      v71 >>= 2;
      n255a[n255_8 + 2] = v71;
      *(_BYTE *)(v72 + 3) = v71;
      v73 = v122;
      v74 = (v63 + v69 + 1) >> 1;
      n255a[2] = v74;
      n255a[2 * n255_8 + 3] = v74;
      n255a[n255_8 + 3] = (v63 + v73 + 2 * (v69 + 1)) >> 2;
      n255a[3] = (v73 + v69 + 1) >> 1;
      break;
    case 7:
      *n255a = (a1[1] + 1 + *a1) >> 1;
      v75 = (unsigned char *)v120;
      n255a[n255_13] = (*a1 + a1[2] + 2 + 2 * a1[1]) >> 2;
      v76 = &n255a[n255_13];
      n255_9 = n255_1;
      v78 = (a1[2] + 1 + a1[1]) >> 1;
      n255a[1] = v78;
      n255a[2 * n255_9] = v78;
      v79 = &n255a[2 * n255_9];
      v80 = (v75[1] + v75[3] + 2 + 2 * v75[2]) >> 2;
      v81 = &n255a[2 * n255_1 + n255_1];
      v82 = v120;
      *v81 = v80;
      v76[1] = v80;
      v83 = (*(unsigned char *)(v82 + 3) + 1 + *(unsigned char *)(v82 + 2)) >> 1;
      n255a[2] = v83;
      v79[1] = v83;
      v84 = v120;
      v85 = (*(unsigned char *)(v120 + 2) + *(unsigned char *)(v120 + 4) + 2 + 2 * *(unsigned char *)(v120 + 3)) >> 2;
      v76[2] = v85;
      v81[1] = v85;
      v86 = (unsigned char *)v120;
      v87 = (*(unsigned char *)(v84 + 4) + 1 + *(unsigned char *)(v84 + 3)) >> 1;
      v79[2] = v87;
      n255a[3] = v87;
      v88 = (v86[5] + v86[3] + 2 + 2 * v86[4]) >> 2;
      v81[2] = v88;
      v76[3] = v88;
      v79[3] = (v86[6] + v86[4] + 2 + 2 * v86[5]) >> 2;
      n255a_1 = v86[5];
      v81[3] = (n255a_1 + v86[7] + 2 + 2 * v86[6]) >> 2;
      break;
    case 8:
      v124 = *a1;
      v122 = a1[1];
      v89 = v126;
      v119 = a1[2];
      v90 = &n255a[2 * n255_13 + n255_13];
      v91 = v125;
      *v90 = (v9 + v126 + 1) >> 1;
      v90[1] = (v91 + v9 + 2 * (v89 + 1)) >> 2;
      n255_10 = n255_1;
      v93 = (v89 + v91 + 1) >> 1;
      v90[2] = v93;
      n255a[2 * n255_10] = v93;
      v94 = v127;
      v95 = v89 + 2;
      n255_11 = n255_1;
      v97 = (v127 + v95 + 2 * v91) >> 2;
      v90[3] = v97;
      n255a[2 * n255_11 + 1] = v97;
      v98 = (v91 + v94 + 1) >> 1;
      n255a[n255_11] = v98;
      n255a[2 * n255_11 + 2] = v98;
      v99 = (a7 + v91 + 2 * (v94 + 1)) >> 2;
      n255a[n255_11 + 1] = v99;
      n255a[2 * n255_11 + 3] = v99;
      v100 = (v94 + a7 + 1) >> 1;
      *n255a = v100;
      n255a[n255_11 + 2] = v100;
      v101 = v124;
      v102 = v94 + 2 + v124 + 2 * a7;
      n255_12 = n255_1;
      v102 >>= 2;
      n255a[1] = v102;
      n255a[n255_12 + 3] = v102;
      v104 = v122;
      n255a[2] = (a7 + v122 + 2 * (v101 + 1)) >> 2;
      n255a[3] = (v101 + v119 + 2 * v104 + 2) >> 2;
      break;
    case 9:
      v105 = v127;
      v106 = v125;
      v107 = v126;
      *n255a = (v125 + v127 + 1) >> 1;
      v108 = v105 + 2 + v107 + 2 * v106;
      v109 = v123;
      n255a[1] = v108 >> 2;
      v110 = (v107 + v106 + 1) >> 1;
      n255a[n255_13] = v110;
      n255a[2] = v110;
      v111 = (v106 + 2 + v109 + 2 * v107) >> 2;
      n255a[n255_13 + 1] = v111;
      n255a[3] = v111;
      v112 = &n255a[2 * n255_13];
      v113 = (v109 + v107 + 1) >> 1;
      *v112 = v113;
      n255a[n255_13 + 2] = v113;
      v114 = (v109 + v107 + 2 * (v109 + 1)) >> 2;
      v112[1] = v114;
      n255a[n255_13 + 3] = v114;
      LOBYTE(v114) = v123;
      v112[n255_13 + 3] = v123;
      v112[n255_13 + 2] = v114;
      v112[n255_13 + 1] = v114;
      v112[n255_13] = v114;
      v112[2] = v114;
      v112[3] = v114;
      LOBYTE(n255a_1) = (_BYTE)v112;
      break;
    default:
      return n255a_1;
  }
  return n255a_1;
}
