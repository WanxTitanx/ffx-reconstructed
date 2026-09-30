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

extern _DWORD mkvparser_Cluster_GetEntryCount();
extern _DWORD mkvparser_ReadUInt_Fast();
extern _DWORD mkvparser_ReadUInt_Slow();
extern _DWORD mkvparser_Reader_ReadID();
extern _DWORD mkvparser_Reader_ReadSize();
extern _DWORD mkvparser_Segment_GetNextCluster();
// Function: mkvparser_Segment_ParseClusterExtended
// Address: 0x424490
// Size: 0xB04
// mkvparser: Segment parse cluster extended — parses extended MKV cluster data
int __fastcall mkvparser_Segment_ParseClusterExtended(int **self, __int64 UInt_Slow, int *a3)
{
  int *v4; // ecx
  int v5; // eax
  __int64 UInt_Fast; // rax
  int v7; // ebx
  int v8; // edi
  __int64 v9; // kr10_8
  unsigned int *v10; // esi
  int v11; // eax
  unsigned int UInt_Slow_19; // ecx
  int v13; // ebx
  int *v14; // ecx
  int *v15; // ecx
  int UInt_Slow_3; // ecx
  int v17; // edx
  __int64 UInt_Slow_16; // rax
  bool v19; // cf
  int v20; // edx
  int v21; // eax
  int v22; // esi
  int v23; // edx
  int UInt_Slow_6; // eax
  int v25; // esi
  int UInt_Slow_5; // kr20_4
  unsigned int v27; // eax
  int UInt_Slow_17; // eax
  int UInt_Slow_7; // ecx
  int *v30; // eax
  int v31; // ecx
  int v32; // edx
  int v33; // ebx
  int v34; // esi
  int *UInt_Slow_9; // ecx
  int *v36; // eax
  int *UInt_Slow_10; // eax
  int *UInt_Slow_14; // eax
  int v39; // eax
  __int64 EntryCount; // rax
  int v41; // ecx
  unsigned int v42; // eax
  unsigned int v43; // edx
  int **this_2; // ebx
  int ID; // eax
  int ID_1; // edi
  int v47; // esi
  int v48; // edx
  int UInt_Slow_11; // ecx
  __int64 UInt_Slow_1; // rax
  __int64 v51; // rax
  int v52; // edx
  unsigned int n0x20; // eax
  int v54; // ecx
  unsigned int UInt_Slow_2; // eax
  __int64 v57; // [esp-10h] [ebp-64h]
  __int64 v58; // [esp+4h] [ebp-50h] BYREF
  __int64 v59; // [esp+Ch] [ebp-48h] BYREF
  unsigned int v60; // [esp+14h] [ebp-40h] BYREF
  unsigned int UInt_Slow_13; // [esp+18h] [ebp-3Ch]
  unsigned __int64 UInt_Slow_15; // [esp+1Ch] [ebp-38h]
  unsigned int UInt_Slow_18; // [esp+24h] [ebp-30h]
  int v64; // [esp+28h] [ebp-2Ch]
  int v65; // [esp+2Ch] [ebp-28h]
  int UInt_Slow_4; // [esp+30h] [ebp-24h]
  int v67; // [esp+34h] [ebp-20h]
  int UInt_Slow_12; // [esp+38h] [ebp-1Ch]
  int UInt_Slow_8; // [esp+3Ch] [ebp-18h]
  __int64 v70; // [esp+40h] [ebp-14h]
  int v71; // [esp+48h] [ebp-Ch]
  int v72; // [esp+4Ch] [ebp-8h]
  int **this_1; // [esp+50h] [ebp-4h]

  v4 = *self;
  v5 = *v4;
  this_1 = self;
  LODWORD(UInt_Fast) = (*(int (__fastcall **)(int *, __int64 *, __int64 *))(v5 + 4))(v4, &v58, &v59);
  if ( (int)UInt_Fast >= 0 )
  {
    if ( v58 >= 0 && v59 > v58 )
      _wassert(L"(total < 0) || (avail <= total)", L"..\\third_party\\libwebm\\mkvparser.cpp", 0xCD0u);
    if ( (int)*(self + 7) < 0 )
    {
      v8 = -1;
      v7 = -1;
    }
    else
    {
      v9 = *((_QWORD *)self + 3) + *((_QWORD *)self + 2);
      v7 = HIDWORD(v9);
      v8 = v9;
    }
    v10 = (unsigned int *)HIDWORD(UInt_Slow);
    v64 = v7;
    UInt_Slow_8 = -1;
    v65 = -1;
    while ( 1 )
    {
      while ( 1 )
      {
        do
        {
          if ( v58 >= 0 && *(_QWORD *)v10 >= v58 || v7 >= 0 && *(_QWORD *)v10 >= __SPAIR64__(v7, v8) )
          {
            LODWORD(UInt_Fast) = 1;
            return UInt_Fast;
          }
          if ( *(_QWORD *)v10 + 1LL > v59 )
          {
LABEL_147:
            *a3 = 1;
LABEL_148:
            LODWORD(UInt_Fast) = -3;
            return UInt_Fast;
          }
          UInt_Fast = mkvparser_ReadUInt_Fast((int)*this_1, a3, *(_QWORD *)v10);
          if ( UInt_Fast < 0 )
            return UInt_Fast;
          if ( UInt_Fast > 0 )
            goto LABEL_148;
          if ( v7 >= 0 && *(_QWORD *)v10 + *a3 > __SPAIR64__(v7, v8) )
            goto LABEL_144;
          v11 = v10[1];
          UInt_Slow_19 = *v10;
          v10 = (unsigned int *)HIDWORD(UInt_Slow);
          v67 = v11;
          UInt_Slow_18 = UInt_Slow_19;
          if ( (__int64)(__PAIR64__(v11, UInt_Slow_19) + *a3) > v59 )
            goto LABEL_148;
          LODWORD(v70) = UInt_Slow_19 - (_DWORD)this_1[4];
          v13 = (__PAIR64__(v67, UInt_Slow_19) - *((_QWORD *)this_1 + 2)) >> 32;
          LODWORD(v70) = UInt_Slow_19 - (_DWORD)this_1[4];
          v57 = __PAIR64__(v67, UInt_Slow_19);
          v14 = *this_1;
          HIDWORD(v70) = v13;
          LODWORD(UInt_Fast) = mkvparser_ReadUInt_Slow(
                                 (int (__fastcall ***)(_DWORD, _DWORD, _DWORD, int, char *))v14,
                                 a3,
                                 v57);
          v7 = v64;
          UInt_Slow_15 = __PAIR64__(UInt_Fast, HIDWORD(UInt_Fast));
          if ( UInt_Fast < 0 )
            return UInt_Fast;
          if ( !UInt_Fast )
          {
            LODWORD(UInt_Fast) = -1;
            return UInt_Fast;
          }
          v15 = a3;
          *(_QWORD *)v10 += *a3;
          if ( *(_QWORD *)v10 + 1LL > v59 )
          {
LABEL_138:
            *v15 = 1;
            LODWORD(UInt_Fast) = -3;
            return UInt_Fast;
          }
          UInt_Fast = mkvparser_ReadUInt_Fast((int)*this_1, v15, *(_QWORD *)v10);
          if ( UInt_Fast < 0 )
            return UInt_Fast;
          if ( UInt_Fast > 0 )
            goto LABEL_148;
          if ( v7 >= 0 && *(_QWORD *)v10 + *a3 > __SPAIR64__(v7, v8) )
          {
LABEL_144:
            LODWORD(UInt_Fast) = -2;
            return UInt_Fast;
          }
          if ( *(_QWORD *)v10 + *a3 > v59 )
            goto LABEL_148;
          UInt_Slow_3 = mkvparser_ReadUInt_Slow(
                          (int (__fastcall ***)(_DWORD, _DWORD, _DWORD, int, char *))*this_1,
                          a3,
                          *(_QWORD *)v10);
          UInt_Slow_4 = UInt_Slow_3;
          v71 = v17;
          if ( v17 < 0 )
          {
LABEL_145:
            LODWORD(UInt_Fast) = UInt_Slow_3;
            return UInt_Fast;
          }
          UInt_Slow_12 = *a3;
          UInt_Slow_16 = UInt_Slow_12;
          v19 = __CFADD__(UInt_Slow_12, *v10);
          *v10 += UInt_Slow_12;
          v10[1] += HIDWORD(UInt_Slow_16) + v19;
        }
        while ( !(v71 | UInt_Slow_3) );
        v20 = 0;
        if ( (unsigned int)(7 * UInt_Slow_12) >= 0x20 )
          v20 = 1 << (7 * UInt_Slow_12);
        v21 = v20 ^ (1 << (7 * UInt_Slow_12));
        v22 = v20;
        v23 = v71;
        if ( (unsigned int)(7 * UInt_Slow_12) >= 0x40 )
          v22 = v21;
        UInt_Slow_5 = v21 - 1;
        v25 = (__PAIR64__(v22, v21) - 1) >> 32;
        UInt_Slow_6 = UInt_Slow_5;
        v72 = v25;
        v10 = (unsigned int *)HIDWORD(UInt_Slow);
        UInt_Slow_12 = UInt_Slow_5;
        if ( v7 >= 0 && (UInt_Slow_3 != UInt_Slow_5 || v71 != v72) )
        {
          v27 = (__PAIR64__(v71, UInt_Slow_3) + *(_QWORD *)HIDWORD(UInt_Slow)) >> 32;
          UInt_Slow_13 = UInt_Slow_3 + *(_DWORD *)HIDWORD(UInt_Slow);
          if ( __SPAIR64__(v27, UInt_Slow_13) > __SPAIR64__(v7, v8) )
            goto LABEL_144;
          UInt_Slow_6 = UInt_Slow_12;
        }
        if ( UInt_Slow_15 != 0xC53BB6B00000000LL )
          break;
        if ( UInt_Slow_3 == UInt_Slow_6 && v71 == v72 )
          goto LABEL_144;
        UInt_Slow_17 = UInt_Slow_3 + *(_DWORD *)HIDWORD(UInt_Slow);
        UInt_Slow_12 = (__PAIR64__(v71, UInt_Slow_3) + *(_QWORD *)HIDWORD(UInt_Slow)) >> 32;
        UInt_Slow_7 = UInt_Slow_4;
        UInt_Slow_13 = UInt_Slow_17;
        if ( v7 >= 0 && __SPAIR64__(UInt_Slow_12, UInt_Slow_17) > __SPAIR64__(v7, v8) )
          goto LABEL_144;
        if ( !this_1[30] )
        {
          v30 = (int *)MEMORY[0x22FB510](64);
          if ( v30 )
          {
            v31 = *v10;
            v32 = v10[1];
            v33 = v67;
            *v30 = (int)this_1;
            v30[4] = UInt_Slow_4;
            v30[5] = v71;
            v30[6] = UInt_Slow_18;
            v30[7] = v67;
            v19 = UInt_Slow_13 < UInt_Slow_18;
            v34 = UInt_Slow_13 - UInt_Slow_18;
            v30[2] = v31;
            UInt_Slow_12 -= v19 + v33;
            v7 = v64;
            v30[8] = v34;
            v30[9] = UInt_Slow_12;
            v10 = (unsigned int *)HIDWORD(UInt_Slow);
            v30[3] = v32;
            v30[10] = 0;
            v30[11] = 0;
            v30[12] = 0;
            v30[14] = v31;
            v30[15] = v32;
          }
          else
          {
            v30 = 0;
          }
          this_1[30] = v30;
          if ( !v30 )
            _wassert(L"m_pCues", L"..\\third_party\\libwebm\\mkvparser.cpp", 0xD38u);
          v23 = v71;
          UInt_Slow_7 = UInt_Slow_4;
        }
        *(_QWORD *)v10 += __PAIR64__(v23, UInt_Slow_7);
        if ( v7 >= 0 && *(_QWORD *)v10 > __SPAIR64__(v7, v8) )
          _wassert(L"(segment_stop < 0) || (pos <= segment_stop)", L"..\\third_party\\libwebm\\mkvparser.cpp", 0xD3Cu);
      }
      if ( UInt_Slow_15 == 0xF43B67500000000LL )
        break;
      if ( UInt_Slow_3 == UInt_Slow_6 && v71 == v72 )
        goto LABEL_144;
      *(_QWORD *)HIDWORD(UInt_Slow) += __PAIR64__(v71, UInt_Slow_3);
      if ( v7 >= 0 && *(_QWORD *)v10 > __SPAIR64__(v7, v8) )
        _wassert(L"(segment_stop < 0) || (pos <= segment_stop)", L"..\\third_party\\libwebm\\mkvparser.cpp", 0xD46u);
    }
    if ( UInt_Slow_3 != UInt_Slow_6 || v71 != v72 )
    {
      UInt_Slow_8 = UInt_Slow_3;
      v65 = v71;
    }
    if ( v70 <= 0 )
      _wassert(L"off_next > 0", L"..\\third_party\\libwebm\\mkvparser.cpp", 0xD5Cu);
    UInt_Slow_9 = &this_1[32][(_DWORD)this_1[33]];
    v36 = this_1[34];
    UInt_Slow_4 = (int)UInt_Slow_9;
    UInt_Slow_10 = &UInt_Slow_9[(_DWORD)v36];
    UInt_Slow_13 = (unsigned int)UInt_Slow_10;
    LODWORD(UInt_Slow_15) = UInt_Slow_10;
    while ( UInt_Slow_9 < UInt_Slow_10 )
    {
      UInt_Slow_14 = &UInt_Slow_9[(UInt_Slow_10 - UInt_Slow_9) / 2];
      HIDWORD(UInt_Slow) = UInt_Slow_14;
      if ( (unsigned int)UInt_Slow_14 >= UInt_Slow_13 )
        _wassert(L"k < jj", L"..\\third_party\\libwebm\\mkvparser.cpp", 0xD71u);
      v39 = *UInt_Slow_14;
      v64 = v39;
      if ( !v39 )
        _wassert(L"pNext", L"..\\third_party\\libwebm\\mkvparser.cpp", 0xD74u);
      if ( *(int *)(v39 + 16) >= 0 )
        _wassert(L"pNext->m_index < 0", L"..\\third_party\\libwebm\\mkvparser.cpp", 0xD75u);
      EntryCount = mkvparser_Cluster_GetEntryCount((_QWORD *)v39);
      *(_QWORD *)v10 = EntryCount;
      if ( EntryCount < 0 )
        _wassert(L"pos >= 0", L"..\\third_party\\libwebm\\mkvparser.cpp", 0xD78u);
      v41 = v10[1];
      v42 = *v10;
      if ( v41 > SHIDWORD(v70) )
      {
        v43 = v70;
      }
      else if ( v41 < SHIDWORD(v70) || (v43 = v70, v42 < (unsigned int)v70) )
      {
        UInt_Slow_10 = (int *)UInt_Slow_15;
        UInt_Slow_9 = (int *)(HIDWORD(UInt_Slow) + 4);
        UInt_Slow_4 = HIDWORD(UInt_Slow) + 4;
        continue;
      }
      if ( v41 < SHIDWORD(v70) || v41 <= SHIDWORD(v70) && v42 <= v43 )
      {
        *(_DWORD *)UInt_Slow = v64;
        LODWORD(UInt_Fast) = 0;
        return UInt_Fast;
      }
      UInt_Slow_10 = (int *)HIDWORD(UInt_Slow);
      UInt_Slow_9 = (int *)UInt_Slow_4;
      LODWORD(UInt_Slow_15) = HIDWORD(UInt_Slow);
    }
    if ( UInt_Slow_9 != UInt_Slow_10 )
      _wassert(L"i == j", L"..\\third_party\\libwebm\\mkvparser.cpp", 0xD84u);
    LODWORD(UInt_Fast) = mkvparser_Reader_ReadSize(this_1, &v60, v70, (int *)&UInt_Slow + 1);
    HIDWORD(UInt_Fast) = UInt_Fast;
    if ( (int)UInt_Fast >= 0 )
    {
      if ( (int)UInt_Fast <= 0 )
      {
        v48 = v65;
        if ( v65 > 0 )
        {
          UInt_Slow_11 = UInt_Slow_8;
        }
        else if ( v65 < 0 )
        {
          UInt_Slow_15 = *(_QWORD *)v10;
          while ( (v58 < 0 || *(_QWORD *)v10 < v58) && (v7 < 0 || *(_QWORD *)v10 < __SPAIR64__(v7, v8)) )
          {
            if ( *(_QWORD *)v10 + 1LL > v59 )
              goto LABEL_147;
            UInt_Fast = mkvparser_ReadUInt_Fast((int)*this_1, a3, *(_QWORD *)v10);
            if ( UInt_Fast < 0 )
              return UInt_Fast;
            if ( UInt_Fast > 0 )
              goto LABEL_148;
            if ( v7 >= 0 && *(_QWORD *)v10 + *a3 > __SPAIR64__(v7, v8) )
              goto LABEL_144;
            if ( *(_QWORD *)v10 + *a3 > v59 )
              goto LABEL_148;
            LODWORD(UInt_Fast) = mkvparser_ReadUInt_Slow(
                                   (int (__fastcall ***)(_DWORD, _DWORD, _DWORD, int, char *))*this_1,
                                   a3,
                                   *(_QWORD *)v10);
            if ( UInt_Fast < 0 )
              return UInt_Fast;
            if ( UInt_Fast == 256095861 || UInt_Fast == 206814059 )
              break;
            v15 = a3;
            *(_QWORD *)v10 += *a3;
            if ( *(_QWORD *)v10 + 1LL > v59 )
              goto LABEL_138;
            UInt_Fast = mkvparser_ReadUInt_Fast((int)*this_1, v15, *(_QWORD *)v10);
            if ( UInt_Fast < 0 )
              return UInt_Fast;
            if ( UInt_Fast > 0 )
              goto LABEL_148;
            if ( v7 >= 0 && *(_QWORD *)v10 + *a3 > __SPAIR64__(v7, v8) )
              goto LABEL_144;
            if ( *(_QWORD *)v10 + *a3 > v59 )
              goto LABEL_148;
            LODWORD(UInt_Slow_1) = mkvparser_ReadUInt_Slow(
                                     (int (__fastcall ***)(_DWORD, _DWORD, _DWORD, int, char *))*this_1,
                                     a3,
                                     *(_QWORD *)v10);
            UInt_Slow_3 = UInt_Slow_1;
            UInt_Slow = UInt_Slow_1;
            if ( UInt_Slow_1 < 0 )
              goto LABEL_145;
            v51 = *a3;
            v19 = __CFADD__((_DWORD)v51, *v10);
            *v10 += v51;
            v10[1] += HIDWORD(v51) + v19;
            if ( HIDWORD(UInt_Slow) | UInt_Slow_3 )
            {
              v52 = 0;
              n0x20 = 7 * *a3;
              if ( n0x20 >= 0x20 )
                v52 = 1 << n0x20;
              v54 = v52 ^ (1 << n0x20);
              v19 = n0x20 < 0x40;
              UInt_Slow_2 = UInt_Slow;
              if ( !v19 )
                v52 = v54;
              if ( UInt_Slow == __PAIR64__(v52, v54) - 1 )
                goto LABEL_144;
              if ( v7 >= 0 )
              {
                if ( UInt_Slow + *(_QWORD *)v10 > __SPAIR64__(v7, v8) )
                  goto LABEL_144;
                UInt_Slow_2 = UInt_Slow;
              }
              *(_QWORD *)v10 += __PAIR64__(HIDWORD(UInt_Slow), UInt_Slow_2);
              if ( v7 >= 0 && *(_QWORD *)v10 > __SPAIR64__(v7, v8) )
                _wassert(
                  L"(segment_stop < 0) || (pos <= segment_stop)",
                  L"..\\third_party\\libwebm\\mkvparser.cpp",
                  0xE01u);
            }
          }
          v48 = (*(_QWORD *)v10 - UInt_Slow_15) >> 32;
          UInt_Slow_11 = *v10 - UInt_Slow_15;
          UInt_Slow_8 = UInt_Slow_11;
          v65 = v48;
          if ( v48 < 0 )
            _wassert(L"cluster_size >= 0", L"..\\third_party\\libwebm\\mkvparser.cpp", 0xE05u);
          *(_QWORD *)v10 = UInt_Slow_15;
        }
        else
        {
          UInt_Slow_11 = UInt_Slow_8;
        }
        *(_QWORD *)v10 += __PAIR64__(v48, UInt_Slow_11);
        if ( v7 >= 0 && *(_QWORD *)v10 > __SPAIR64__(v7, v8) )
          _wassert(L"(segment_stop < 0) || (pos <= segment_stop)", L"..\\third_party\\libwebm\\mkvparser.cpp", 0xE0Bu);
        LODWORD(UInt_Fast) = 2;
      }
      else
      {
        this_2 = this_1;
        ID = mkvparser_Reader_ReadID((int)this_1, -1, v70);
        ID_1 = ID;
        if ( !ID )
          _wassert(L"pNext", L"..\\third_party\\libwebm\\mkvparser.cpp", 0xD97u);
        v47 = (UInt_Slow_4 - (int)this_2[32]) >> 2;
        mkvparser_Segment_GetNextCluster(this_2, ID, v47);
        if ( !this_2[32] )
          _wassert(L"m_clusters", L"..\\third_party\\libwebm\\mkvparser.cpp", 0xD9Cu);
        if ( v47 >= (int)this_2[35] )
          _wassert(L"idx_next < m_clusterSize", L"..\\third_party\\libwebm\\mkvparser.cpp", 0xD9Du);
        if ( this_2[32][v47] != ID_1 )
          _wassert(L"m_clusters[idx_next] == pNext", L"..\\third_party\\libwebm\\mkvparser.cpp", 0xD9Eu);
        *(_DWORD *)UInt_Slow = ID_1;
        LODWORD(UInt_Fast) = 0;
      }
    }
    else
    {
      LODWORD(UInt_Fast) = a3;
      *v10 = v60;
      v10[1] = UInt_Slow_13;
      *(_DWORD *)UInt_Fast = HIDWORD(UInt_Slow);
      LODWORD(UInt_Fast) = HIDWORD(UInt_Fast);
    }
  }
  return UInt_Fast;
}
