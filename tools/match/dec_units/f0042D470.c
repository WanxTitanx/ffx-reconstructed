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

extern _DWORD mkvparser_ReadUInt_BigEndian();
extern _DWORD mkvparser_ReadUInt_Slow();
// Function: mkvparser_Segment_ParseCuesEntry
// Address: 0x42D470
// Size: 0xA7B
// mkvparser: Segment parse cues entry — parses MKV Cues table entry
int __fastcall mkvparser_Segment_ParseCuesEntry(int *self, int **a2)
{
  unsigned int v4; // edx
  int v5; // ecx
  int *this_2; // ebx
  _DWORD *UInt_Slow_13; // eax
  unsigned __int64 UInt_Slow_2; // rdi
  int (__fastcall ***v9)(_DWORD, unsigned int, int, int, char *); // eax
  __int64 v10; // rax
  __int64 v11; // kr10_8
  int *this_3; // edx
  int (__fastcall **v13)(_DWORD, _DWORD, _DWORD, int, int); // eax
  __int64 v14; // kr20_8
  int v15; // ecx
  bool v16; // of
  signed __int64 n0x7FFFFFFF; // kr28_8
  int UInt_Slow_10; // ebx
  int v19; // eax
  int v20; // eax
  int *this_4; // edx
  int n3_2; // eax
  int (__fastcall ***UInt_Slow_9)(_DWORD, unsigned int, int, int, char *); // ecx
  int (__fastcall ***UInt_Slow_8)(_DWORD, unsigned int, int, int, char *); // edx
  int (__fastcall ***v25)(_DWORD, unsigned int, int, int, char *); // eax
  _DWORD *UInt_Slow_11; // ecx
  int (__fastcall ***v27)(_DWORD, unsigned int, int, int, char *); // edx
  unsigned int n3_3; // edx
  unsigned __int64 n0x7FFFFFFF_3; // kr48_8
  int UInt_Slow_12; // edx
  int v31; // eax
  int n3_4; // eax
  __int64 v33; // rax
  int (__fastcall ***v34)(_DWORD, unsigned int, int, int, char *); // ecx
  int n3_5; // edx
  _DWORD *UInt_Slow_14; // ebx
  int (__fastcall ***UInt_Slow_15)(_DWORD, unsigned int, int, int, char *); // ecx
  char *v38; // kr60_4
  int n3_6; // eax
  unsigned __int64 n0x7FFFFFFF_2; // rax
  __int64 v41; // kr68_8
  _DWORD *UInt_Slow_3; // eax
  int v43; // esi
  int v44; // ebx
  _DWORD *UInt_Slow_1; // ecx
  int v46; // eax
  _DWORD *UInt_Slow_16; // eax
  int (__fastcall ***v48)(_DWORD, unsigned int, int, int, char *); // ecx
  int v49; // edx
  unsigned int n0x20; // edx
  int v51; // ecx
  int v52; // eax
  unsigned __int64 v53; // rcx
  int v54; // kr70_4
  __int64 v55; // kr78_8
  __int64 v56; // rax
  _DWORD *UInt_Slow_6; // ecx
  unsigned int v58; // ecx
  unsigned int v59; // eax
  unsigned int v60; // edx
  unsigned __int64 n0x7FFFFFFF_1; // kr88_8
  int UInt_Slow_7; // edx
  int v63; // eax
  unsigned int *n3_1; // edx
  unsigned int v65; // eax
  unsigned int v66; // eax
  unsigned int v67; // kr90_4
  __int64 v68; // [esp-8h] [ebp-54h]
  __int64 p_n0x7FFF; // [esp+Ch] [ebp-40h] BYREF
  unsigned __int64 n3; // [esp+18h] [ebp-34h]
  int UInt_Slow; // [esp+20h] [ebp-2Ch]
  int (__fastcall ***v72[2])(_DWORD, unsigned int, int, int, char *); // [esp+24h] [ebp-28h] BYREF
  int (__fastcall ***UInt_Slow_5)(_DWORD, unsigned int, int, int, char *); // [esp+2Ch] [ebp-20h]
  unsigned __int64 v74; // [esp+30h] [ebp-1Ch]
  __int64 v75; // [esp+38h] [ebp-14h]
  int *this_1; // [esp+40h] [ebp-Ch]
  _DWORD *UInt_Slow_4; // [esp+44h] [ebp-8h]
  unsigned char v78; // [esp+4Bh] [ebp-1h] BYREF

  this_1 = self;
  if ( !a2 || !*a2 )
    return -1;
  if ( *(self + 1) < 0 )
    _wassert(L"m_start >= 0", L"..\\third_party\\libwebm\\mkvparser.cpp", 0x1F20u);
  if ( *(self + 3) < 0 )
    _wassert(L"m_size >= 0", L"..\\third_party\\libwebm\\mkvparser.cpp", 0x1F21u);
  if ( *((__int64 *)self + 2) > 0 )
    _wassert(L"m_track <= 0", L"..\\third_party\\libwebm\\mkvparser.cpp", 0x1F22u);
  if ( *(self + 7) )
    _wassert(L"m_frames == NULL", L"..\\third_party\\libwebm\\mkvparser.cpp", 0x1F23u);
  if ( *(self + 8) > 0 )
    _wassert(L"m_frame_count <= 0", L"..\\third_party\\libwebm\\mkvparser.cpp", 0x1F24u);
  v4 = *(self + 1);
  v5 = *self;
  this_2 = this_1;
  UInt_Slow_13 = (_DWORD *)((__PAIR64__(v4, v5) + __PAIR64__(this_1[3], *(self + 2))) >> 32);
  HIDWORD(UInt_Slow_2) = v5 + *(self + 2);
  UInt_Slow_4 = UInt_Slow_13;
  v9 = (int (__fastcall ***)(_DWORD, unsigned int, int, int, char *))**a2;
  n3 = __PAIR64__(v4, v5);
  UInt_Slow = HIDWORD(UInt_Slow_2);
  v72[1] = v9;
  LODWORD(v10) = mkvparser_ReadUInt_Slow(v9, (int *)v72, __SPAIR64__(v4, v5));
  *((_QWORD *)this_2 + 2) = v10;
  if ( v10 <= 0 )
    return -2;
  v11 = (__int64)v72[0] + n3;
  if ( v11 > __SPAIR64__((unsigned int)UInt_Slow_4, HIDWORD(UInt_Slow_2)) )
    return -2;
  if ( (__int64)(__PAIR64__((unsigned int)UInt_Slow_4, HIDWORD(UInt_Slow_2)) - v11) < 2 )
    return -2;
  if ( mkvparser_ReadUInt_BigEndian(v72[1], 2, v11, SHIDWORD(v11), &p_n0x7FFF) )
    return -2;
  if ( p_n0x7FFF < -32768 )
    return -2;
  if ( p_n0x7FFF > 0x7FFF )
    return -2;
  this_3 = this_1;
  *((_WORD *)this_1 + 12) = p_n0x7FFF;
  if ( (__int64)(__PAIR64__((unsigned int)UInt_Slow_4, HIDWORD(UInt_Slow_2)) - (v11 + 2)) <= 0 )
    return -2;
  v13 = (int (__fastcall **)(_DWORD, _DWORD, _DWORD, int, int))*v72[1];
  LODWORD(n3) = (char *)this_3 + 26;
  if ( (*v13)(v72[1], v11 + 2, (unsigned __int64)(v11 + 2) >> 32, 1, (int)this_3 + 26) )
    return -2;
  v14 = v11 + 3;
  LODWORD(n3) = (*(unsigned char *)n3 >> 1) & 3;
  if ( !(_DWORD)n3 )
  {
    if ( v14 <= __SPAIR64__((unsigned int)UInt_Slow_4, HIDWORD(UInt_Slow_2)) )
    {
      this_1[8] = 1;
      v15 = MEMORY[0x22FB510](16);
      this_1[7] = v15;
      v16 = __OFSUB__(__PAIR64__((unsigned int)UInt_Slow_4, HIDWORD(UInt_Slow_2)), v14);
      n0x7FFFFFFF = __PAIR64__((unsigned int)UInt_Slow_4, HIDWORD(UInt_Slow_2)) - v14;
      *(_QWORD *)v15 = v14;
      HIDWORD(p_n0x7FFF) = HIDWORD(n0x7FFFFFFF);
      if ( n0x7FFFFFFF < 0
        || (n0x7FFFFFFF < 0) ^ v16 | (HIDWORD(n0x7FFFFFFF) == 0) && (unsigned int)n0x7FFFFFFF <= 0x7FFFFFFF )
      {
        *(_DWORD *)(v15 + 8) = n0x7FFFFFFF;
        return 0;
      }
    }
    return -2;
  }
  if ( v14 >= __SPAIR64__((unsigned int)UInt_Slow_4, HIDWORD(UInt_Slow_2))
    || (**v72[1])(v72[1], v14, HIDWORD(v14), 1, (char *)&a2 + 3) )
  {
    return -2;
  }
  UInt_Slow_10 = (unsigned __int64)(v11 + 4) >> 32;
  LODWORD(UInt_Slow_2) = v11 + 4;
  UInt_Slow_5 = (int (__fastcall ***)(_DWORD, unsigned int, int, int, char *))UInt_Slow_10;
  if ( v11 + 4 > __SPAIR64__((unsigned int)UInt_Slow_4, HIDWORD(UInt_Slow_2)) )
    _wassert(L"pos <= stop", L"..\\third_party\\libwebm\\mkvparser.cpp", 0x1F77u);
  v19 = HIBYTE(a2) + 1;
  this_1[8] = v19;
  v20 = MEMORY[0x22FB510]((unsigned __int64)(unsigned int)v19 >> 28 != 0 ? -1 : 16 * v19);
  this_4 = this_1;
  this_1[7] = v20;
  if ( !v20 )
    _wassert(L"m_frames", L"..\\third_party\\libwebm\\mkvparser.cpp", 0x1F7Cu);
  if ( (_DWORD)n3 != 1 )
  {
    if ( (_DWORD)n3 == 2 )
    {
      HIDWORD(n3) = this_4[8];
      v33 = (__int64)(__PAIR64__((unsigned int)UInt_Slow_4, HIDWORD(UInt_Slow_2)) - __PAIR64__(
                                                                                      UInt_Slow_10,
                                                                                      UInt_Slow_2))
          / SHIDWORD(n3);
      *(_QWORD *)v72 = v33;
      if ( !((__int64)(__PAIR64__((unsigned int)UInt_Slow_4, HIDWORD(UInt_Slow_2))
                     - __PAIR64__(UInt_Slow_10, UInt_Slow_2))
           % SHIDWORD(n3)) )
      {
        if ( v33 < 0 )
        {
          v34 = v72[0];
        }
        else
        {
          if ( (int)((unsigned __int64)((__int64)(__PAIR64__((unsigned int)UInt_Slow_4, HIDWORD(UInt_Slow_2))
                                                - __PAIR64__(UInt_Slow_10, UInt_Slow_2))
                                      / SHIDWORD(n3)) >> 32) > 0 )
            return -2;
          v34 = v72[0];
          if ( v72[0] > (int (__fastcall ***)(_DWORD, unsigned int, int, int, char *))0x7FFFFFFF )
            return -2;
        }
        HIDWORD(UInt_Slow_2) = UInt_Slow_5;
        UInt_Slow_14 = UInt_Slow_4;
        LODWORD(n3) = this_1[7];
        n3_5 = n3;
        HIDWORD(n3) = n3 + 16 * HIDWORD(n3);
        if ( (_DWORD)n3 != HIDWORD(n3) )
        {
          do
          {
            v38 = (char *)v34 + UInt_Slow_2;
            UInt_Slow_15 = (int (__fastcall ***)(_DWORD, unsigned int, int, int, char *))((UInt_Slow_2
                                                                                         + __PAIR64__(
                                                                                             (unsigned int)v72[1],
                                                                                             (unsigned int)v34)) >> 32);
            LODWORD(v74) = v38;
            UInt_Slow_5 = UInt_Slow_15;
            if ( __SPAIR64__((unsigned int)UInt_Slow_15, (unsigned int)v38) > __SPAIR64__(
                                                                                (unsigned int)UInt_Slow_14,
                                                                                UInt_Slow) )
              _wassert(L"(pos + frame_size) <= stop", L"..\\third_party\\libwebm\\mkvparser.cpp", 0x1FD7u);
            n3_6 = n3_5;
            n3_5 += 16;
            *(_DWORD *)(n3_6 + 4) = HIDWORD(UInt_Slow_2);
            *(int (__fastcall ****)(_DWORD, unsigned int, int, int, char *))(n3_6 + 8) = v72[0];
            *(_DWORD *)n3_6 = UInt_Slow_2;
            UInt_Slow_2 = __PAIR64__((unsigned int)UInt_Slow_15, v74);
            v34 = v72[0];
            LODWORD(n3) = n3_5;
          }
          while ( n3_5 != HIDWORD(n3) );
        }
        if ( UInt_Slow_2 != __PAIR64__((unsigned int)UInt_Slow_14, UInt_Slow) )
          _wassert(L"pos == stop", L"..\\third_party\\libwebm\\mkvparser.cpp", 0x1FE1u);
        return 0;
      }
    }
    else
    {
      if ( (_DWORD)n3 != 3 )
        _wassert(L"lacing == 3", L"..\\third_party\\libwebm\\mkvparser.cpp", 0x1FE3u);
      if ( __SPAIR64__(UInt_Slow_10, UInt_Slow_2) < __SPAIR64__((unsigned int)UInt_Slow_4, HIDWORD(UInt_Slow_2)) )
      {
        HIDWORD(n3) = this_1[8];
        LODWORD(n0x7FFFFFFF_2) = mkvparser_ReadUInt_Slow(v72[1], (int *)v72, __SPAIR64__(UInt_Slow_10, UInt_Slow_2));
        v74 = __PAIR64__(n0x7FFFFFFF_2, HIDWORD(n0x7FFFFFFF_2));
        if ( n0x7FFFFFFF_2 <= 0x7FFFFFFF )
        {
          LODWORD(UInt_Slow_2) = UInt_Slow_4;
          v41 = (__int64)v72[0] + v11 + 4;
          v75 = v41;
          if ( v41 <= __SPAIR64__((unsigned int)UInt_Slow_4, HIDWORD(UInt_Slow_2)) )
          {
            LODWORD(n3) = v41 + HIDWORD(v74);
            if ( (__int64)(v41 + __PAIR64__(v74, HIDWORD(v74))) <= __SPAIR64__(
                                                                     (unsigned int)UInt_Slow_4,
                                                                     HIDWORD(UInt_Slow_2)) )
            {
              LODWORD(n3) = HIDWORD(v74);
              UInt_Slow_3 = (_DWORD *)this_1[7];
              v43 = 4 * this_1[8];
              UInt_Slow_3[2] = HIDWORD(v74);
              v44 = HIDWORD(n3) - 1;
              UInt_Slow_5 = (int (__fastcall ***)(_DWORD, unsigned int, int, int, char *))&UInt_Slow_3[v43];
              HIDWORD(UInt_Slow_2) = UInt_Slow;
              UInt_Slow_4 = UInt_Slow_3;
              *UInt_Slow_3 = 0;
              UInt_Slow_3[1] = 0;
              HIDWORD(n3) = v44;
              if ( v44 > 1 )
              {
                while ( v41 < __SPAIR64__(UInt_Slow_2, HIDWORD(UInt_Slow_2)) )
                {
                  if ( UInt_Slow_3 >= UInt_Slow_5 )
                    _wassert(L"pf < pf_end", L"..\\third_party\\libwebm\\mkvparser.cpp", 0x200Du);
                  UInt_Slow_1 = UInt_Slow_3;
                  UInt_Slow_4 = UInt_Slow_3 + 4;
                  v46 = UInt_Slow_3[2];
                  UInt_Slow = (int)UInt_Slow_1;
                  if ( __PAIR64__(v46, v46 >> 31) != v74 )
                    _wassert(L"prev.len == frame_size", L"..\\third_party\\libwebm\\mkvparser.cpp", 0x2010u);
                  if ( __PAIR64__(*(_DWORD *)(UInt_Slow + 8), *(int *)(UInt_Slow + 8) >> 31) != v74 )
                    break;
                  UInt_Slow_16 = UInt_Slow_4;
                  if ( UInt_Slow_4 >= UInt_Slow_5 )
                    _wassert(L"pf < pf_end", L"..\\third_party\\libwebm\\mkvparser.cpp", 0x2014u);
                  v48 = v72[1];
                  v68 = v75;
                  *UInt_Slow_4 = 0;
                  UInt_Slow_16[1] = 0;
                  UInt_Slow = mkvparser_ReadUInt_Slow(v48, (int *)v72, v68);
                  HIDWORD(p_n0x7FFF) = v49;
                  if ( v49 < 0 )
                    break;
                  v75 += (int)v72[0];
                  if ( SHIDWORD(v75) > (int)UInt_Slow_2 )
                    break;
                  if ( SHIDWORD(v75) >= (int)UInt_Slow_2 )
                  {
                    if ( (unsigned int)v75 > HIDWORD(UInt_Slow_2) )
                      return -2;
                    if ( v75 > __SPAIR64__(UInt_Slow_2, HIDWORD(UInt_Slow_2)) )
                      _wassert(L"pos <= stop", L"..\\third_party\\libwebm\\mkvparser.cpp", 0x2023u);
                  }
                  n0x20 = 7 * (int)v72[0] - 1;
                  v51 = 0;
                  if ( n0x20 >= 0x20 )
                    v51 = 1 << n0x20;
                  v52 = v51 ^ (1 << n0x20);
                  if ( n0x20 >= 0x40 )
                    v51 ^= 1 << n0x20;
                  v54 = UInt_Slow - v52 + 1 + HIDWORD(v74);
                  LODWORD(v53) = (__PAIR64__(HIDWORD(p_n0x7FFF), UInt_Slow)
                                - __PAIR64__(v51, v52)
                                + 1
                                + __PAIR64__(v74, HIDWORD(v74))) >> 32;
                  HIDWORD(v53) = v54;
                  v74 = v53;
                  if ( __PAIR64__(v53, v54) > 0x7FFFFFFF )
                    break;
                  UInt_Slow_3 = UInt_Slow_4;
                  LODWORD(n3) = v54 + n3;
                  v55 = v75;
                  UInt_Slow_4[2] = v54;
                  --HIDWORD(n3);
                  v41 = v55;
                  if ( SHIDWORD(n3) <= 1 )
                    goto LABEL_108;
                }
                return -2;
              }
LABEL_108:
              if ( v41 > __SPAIR64__(UInt_Slow_2, HIDWORD(UInt_Slow_2)) )
                _wassert(L"pos <= stop", L"..\\third_party\\libwebm\\mkvparser.cpp", 0x2038u);
              if ( UInt_Slow_4 >= UInt_Slow_5 )
                _wassert(L"pf < pf_end", L"..\\third_party\\libwebm\\mkvparser.cpp", 0x2039u);
              HIDWORD(p_n0x7FFF) = UInt_Slow_4;
              v56 = (int)UInt_Slow_4[2];
              UInt_Slow_6 = UInt_Slow_4 + 4;
              UInt_Slow_4 += 4;
              if ( __PAIR64__(v56, HIDWORD(v56)) != v74 )
                _wassert(L"prev.len == frame_size", L"..\\third_party\\libwebm\\mkvparser.cpp", 0x203Cu);
              if ( __PAIR64__(*(_DWORD *)(HIDWORD(p_n0x7FFF) + 8), *(int *)(HIDWORD(p_n0x7FFF) + 8) >> 31) == v74 )
              {
                if ( UInt_Slow_6 >= UInt_Slow_5 )
                  _wassert(L"pf < pf_end", L"..\\third_party\\libwebm\\mkvparser.cpp", 0x2040u);
                if ( UInt_Slow_6 + 4 != UInt_Slow_5 )
                  _wassert(L"pf == pf_end", L"..\\third_party\\libwebm\\mkvparser.cpp", 0x2043u);
                *UInt_Slow_6 = 0;
                UInt_Slow_6[1] = 0;
                v58 = v75;
                HIDWORD(p_n0x7FFF) = (__PAIR64__(UInt_Slow_2, HIDWORD(UInt_Slow_2)) - v75) >> 32;
                HIDWORD(n3) = HIDWORD(UInt_Slow_2) - v75;
                v59 = HIDWORD(p_n0x7FFF);
                UInt_Slow = (int)n3 >> 31;
                if ( SHIDWORD(p_n0x7FFF) > UInt_Slow )
                {
                  v60 = HIDWORD(n3);
                }
                else
                {
                  if ( SHIDWORD(p_n0x7FFF) < (int)n3 >> 31 )
                    return -2;
                  v60 = HIDWORD(n3);
                  if ( HIDWORD(n3) < (unsigned int)n3 )
                    return -2;
                }
                n0x7FFFFFFF_1 = __PAIR64__(HIDWORD(p_n0x7FFF), v60) - __PAIR64__(UInt_Slow, n3);
                HIDWORD(p_n0x7FFF) = (__PAIR64__(HIDWORD(p_n0x7FFF), v60) - __PAIR64__(UInt_Slow, n3)) >> 32;
                if ( p_n0x7FFF >= 0
                  && (__SPAIR64__(v59, v60) >= __SPAIR64__(UInt_Slow, n3) && HIDWORD(n0x7FFFFFFF_1) != 0
                   || (unsigned int)n0x7FFFFFFF_1 > 0x7FFFFFFF) )
                {
                  return -2;
                }
                UInt_Slow_4[2] = n0x7FFFFFFF_1;
                UInt_Slow_7 = this_1[7];
                if ( (int (__fastcall ***)(_DWORD, unsigned int, int, int, char *))UInt_Slow_7 == UInt_Slow_5 )
                {
                  v66 = HIDWORD(v75);
                }
                else
                {
                  do
                  {
                    LODWORD(n3) = UInt_Slow_7;
                    v63 = *(_DWORD *)(UInt_Slow_7 + 8);
                    HIDWORD(n3) = UInt_Slow_7 + 16;
                    HIDWORD(p_n0x7FFF) = v58 + v63;
                    if ( (__int64)(__PAIR64__(HIDWORD(v75), v58) + v63) > __SPAIR64__(UInt_Slow_2, HIDWORD(UInt_Slow_2)) )
                      _wassert(L"(pos + f.len) <= stop", L"..\\third_party\\libwebm\\mkvparser.cpp", 0x2057u);
                    n3_1 = (unsigned int *)n3;
                    *(_DWORD *)(n3 + 4) = HIDWORD(v75);
                    v65 = n3_1[2];
                    *n3_1 = v58;
                    v67 = v65 + v58;
                    v66 = ((int)v65 + __PAIR64__(HIDWORD(v75), v58)) >> 32;
                    v58 = v67;
                    UInt_Slow_7 = HIDWORD(n3);
                    v75 = __PAIR64__(v66, v67);
                  }
                  while ( (int (__fastcall ***)(_DWORD, unsigned int, int, int, char *))HIDWORD(n3) != UInt_Slow_5 );
                }
                if ( __PAIR64__(v58, v66) != UInt_Slow_2 )
                  _wassert(L"pos == stop", L"..\\third_party\\libwebm\\mkvparser.cpp", 0x205Du);
                return 0;
              }
            }
          }
        }
      }
    }
    return -2;
  }
  n3_2 = this_4[8];
  UInt_Slow_9 = (int (__fastcall ***)(_DWORD, unsigned int, int, int, char *))this_4[7];
  UInt_Slow_8 = &UInt_Slow_9[4 * n3_2];
  v72[0] = UInt_Slow_9;
  n3 = (unsigned int)n3_2;
  UInt_Slow_5 = UInt_Slow_8;
  if ( n3_2 > 1 )
  {
LABEL_36:
    HIDWORD(UInt_Slow_2) = 0;
    while ( UInt_Slow_10 <= (int)UInt_Slow_4
         && (UInt_Slow_10 < (int)UInt_Slow_4 || (unsigned int)UInt_Slow_2 < UInt_Slow)
         && !(**v72[1])(v72[1], UInt_Slow_2, UInt_Slow_10, 1, (char *)&v78) )
    {
      UInt_Slow_10 = (__PAIR64__(UInt_Slow_10, UInt_Slow_2) + 1) >> 32;
      LODWORD(UInt_Slow_2) = UInt_Slow_2 + 1;
      HIDWORD(UInt_Slow_2) += v78;
      if ( v78 != 0xFF )
      {
        UInt_Slow_8 = UInt_Slow_5;
        v25 = v72[0];
        UInt_Slow_9 = v72[0] + 4;
        *(int (__fastcall ****)(_DWORD, unsigned int, int, int, char *))&v74 = v72[0];
        v72[0] = UInt_Slow_9;
        if ( UInt_Slow_9 >= UInt_Slow_5 )
          _wassert(L"pf < pf_end", L"..\\third_party\\libwebm\\mkvparser.cpp", 0x1F9Cu);
        HIDWORD(n3) += HIDWORD(UInt_Slow_2);
        *v25 = 0;
        v25[1] = 0;
        v25[2] = (int (__fastcall **)(_DWORD, unsigned int, int, int, char *))HIDWORD(UInt_Slow_2);
        LODWORD(n3) = n3 - 1;
        if ( (int)n3 <= 1 )
        {
          HIDWORD(UInt_Slow_2) = UInt_Slow;
          goto LABEL_46;
        }
        goto LABEL_36;
      }
    }
    return -2;
  }
LABEL_46:
  if ( UInt_Slow_9 >= UInt_Slow_8 )
    _wassert(L"pf < pf_end", L"..\\third_party\\libwebm\\mkvparser.cpp", 0x1FA6u);
  UInt_Slow_11 = UInt_Slow_4;
  if ( UInt_Slow_10 >= (int)UInt_Slow_4
    && (UInt_Slow_10 > (int)UInt_Slow_4 || (unsigned int)UInt_Slow_2 > HIDWORD(UInt_Slow_2)) )
  {
    _wassert(L"pos <= stop", L"..\\third_party\\libwebm\\mkvparser.cpp", 0x1FA7u);
  }
  v27 = v72[0];
  if ( v72[0] + 4 != UInt_Slow_5 )
    return -2;
  *v72[0] = 0;
  v27[1] = 0;
  UInt_Slow = (__PAIR64__((unsigned int)UInt_Slow_11, HIDWORD(UInt_Slow_2)) - __PAIR64__(UInt_Slow_10, UInt_Slow_2)) >> 32;
  LODWORD(n3) = HIDWORD(UInt_Slow_2) - UInt_Slow_2;
  v72[1] = (int (__fastcall ***)(_DWORD, unsigned int, int, int, char *))(SHIDWORD(n3) >> 31);
  if ( UInt_Slow > (int)v72[1] )
  {
    n3_3 = n3;
  }
  else
  {
    if ( UInt_Slow < SHIDWORD(n3) >> 31 )
      return -2;
    n3_3 = n3;
    if ( (unsigned int)n3 < HIDWORD(n3) )
      return -2;
  }
  n0x7FFFFFFF_3 = __PAIR64__(UInt_Slow, n3_3) - __PAIR64__((unsigned int)v72[1], HIDWORD(n3));
  HIDWORD(p_n0x7FFF) = (__PAIR64__(UInt_Slow, n3_3) - __PAIR64__((unsigned int)v72[1], HIDWORD(n3))) >> 32;
  if ( p_n0x7FFF >= 0
    && (__SPAIR64__(UInt_Slow, n3_3) >= __SPAIR64__((unsigned int)v72[1], HIDWORD(n3)) && HIDWORD(n0x7FFFFFFF_3) != 0
     || (unsigned int)n0x7FFFFFFF_3 > 0x7FFFFFFF) )
  {
    return -2;
  }
  v72[0][2] = (int (__fastcall **)(_DWORD, unsigned int, int, int, char *))n0x7FFFFFFF_3;
  UInt_Slow_12 = this_1[7];
  if ( (int (__fastcall ***)(_DWORD, unsigned int, int, int, char *))UInt_Slow_12 != UInt_Slow_5 )
  {
    do
    {
      LODWORD(n3) = UInt_Slow_12;
      v31 = *(_DWORD *)(UInt_Slow_12 + 8);
      HIDWORD(n3) = UInt_Slow_12 + 16;
      if ( (__int64)(__PAIR64__(UInt_Slow_10, UInt_Slow_2) + v31) > __SPAIR64__(
                                                                      (unsigned int)UInt_Slow_11,
                                                                      HIDWORD(UInt_Slow_2)) )
        _wassert(L"(pos + f.len) <= stop", L"..\\third_party\\libwebm\\mkvparser.cpp", 0x1FC1u);
      n3_4 = n3;
      *(_DWORD *)n3 = UInt_Slow_2;
      *(_DWORD *)(n3_4 + 4) = UInt_Slow_10;
      UInt_Slow_10 = (*(int *)(n3_4 + 8) + __PAIR64__(UInt_Slow_10, UInt_Slow_2)) >> 32;
      LODWORD(UInt_Slow_2) = *(_DWORD *)(n3_4 + 8) + UInt_Slow_2;
      UInt_Slow_12 = HIDWORD(n3);
    }
    while ( (int (__fastcall ***)(_DWORD, unsigned int, int, int, char *))HIDWORD(n3) != UInt_Slow_5 );
  }
  if ( (_DWORD)UInt_Slow_2 != HIDWORD(UInt_Slow_2) || (_DWORD *)UInt_Slow_10 != UInt_Slow_11 )
    _wassert(L"pos == stop", L"..\\third_party\\libwebm\\mkvparser.cpp", 0x1FC7u);
  return 0;
}
