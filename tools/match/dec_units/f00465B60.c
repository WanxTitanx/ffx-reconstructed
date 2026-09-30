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

extern _DWORD Phyre_Shader_CompilePass_C94F00;
extern _DWORD Singleton_C94F00;
extern _DWORD loc_AA93B6;
extern _DWORD Engine_AlignedAllocAlign();
extern _DWORD Engine_AlignedFree();
extern _DWORD ManagedStrIter_Next_1();
extern _DWORD ManagedStrIter_Next_10();
extern _DWORD ManagedStrIter_Next_11();
extern _DWORD ManagedStrIter_Next_13();
extern _DWORD ManagedStrIter_Next_14();
extern _DWORD ManagedStrIter_Next_2();
extern _DWORD ManagedStrIter_Next_3();
extern _DWORD ManagedStrIter_Next_4();
extern _DWORD ManagedStrIter_Next_5();
extern _DWORD ManagedStrIter_Next_7();
extern _DWORD ManagedStrIter_Next_8();
extern _DWORD ManagedStrIter_Next_9();
extern _DWORD ManagedStrIter_Next_WithGuard_B();
extern _DWORD ManagedStrIter_Next_WithGuard_C();
extern _DWORD ManagedStrIter_Next_WithGuard_D();
extern _DWORD ManagedStrIter_Next_WithGuard_E();
extern _DWORD ManagedStrIter_Next_WithGuard_F();
extern _DWORD ManagedStrIter_Next_WithGuard_I();
extern _DWORD NtCurrentTeb();
extern _DWORD PDataBlock_StaticInit();
extern _DWORD PTextureDescription_ValidateAndSetConfig();
extern _DWORD PTextureDescription_ValidateAndSetConfigV2();
extern _DWORD PTextureFormat_SetDimensions();
extern _DWORD PhyreManaged_ContainerCtor_Size65();
extern _DWORD PhyreManaged_StringListIterate_A();
extern _DWORD PhyreManaged_StringListIterate_D();
extern _DWORD Phyre_Cluster_ReadFieldsFromStream();
extern _DWORD Phyre_Cluster_ZeroInitArea();
extern _DWORD Phyre_Input_EventDispatcherAndState();
extern _DWORD Phyre_Managed_GetField1334h();
extern _DWORD Phyre_PArrayPSceneWideParam_BoolReturn();
extern _DWORD Phyre_PIndexDataBlock_StaticInit();
extern _DWORD Phyre_PStreamReader_ReadBytes_Validate();
extern _DWORD Phyre_PTexture3D_HasFlag64();
extern _DWORD Phyre_PTextureCubeMap_HasFlag64();
extern _DWORD Phyre_PVideoTexture_HasTextureFlag70();
extern _DWORD Phyre_Shader_CompileComputePass();
extern _DWORD Phyre_Shader_CompileGeometryPass();
extern _DWORD Phyre_Shader_CompilePixelPass();
extern _DWORD Phyre_Shader_CompileVertexPass();
extern _DWORD Phyre_Shader_ParseCompiledStates();
extern _DWORD Phyre_Texture_Construct();
extern _DWORD Phyre_Texture_DeferredCreateFromFormat();
extern _DWORD Phyre_Texture_LazyConstructFromFormat();
extern _DWORD Phyre_Type_ConstructFromChunk();
extern _DWORD Phyre_Type_ConstructFromChunkVariableSize();
extern _DWORD Phyre_Type_LazyConstructFromChunk();
extern _DWORD Phyre_Type_LazyConstructFromChunkVariableSize();
extern _DWORD atexit();
// Function: Phyre_PTexture2D3D_ReadMipChainFromCluster_StaticInit
// Address: 0x465B60
// Size: 0x12FA
// ManagedCpp: Static init F — C++/CLI static initializer for managed .NET interop
int __fastcall Phyre_PTexture2D3D_ReadMipChainFromCluster_StaticInit(
        int *Size,
        _DWORD *m_pNext,
        int name,
        const char *Src)
{
  int v4; // ebx
  int v5; // esi
  int Bytes_Validate; // esi
  _DWORD *namea_45; // edi
  unsigned int namea_14; // ebx
  char *v9; // esi
  _DWORD *namea_13; // eax
  _DWORD *v11; // edx
  _DWORD *namea_46; // edi
  unsigned int namea_16; // ebx
  char *dsta_13; // esi
  _DWORD *namea_15; // eax
  _DWORD *v16; // edx
  _DWORD *namea_47; // edi
  unsigned int namea_18; // ebx
  char *v19; // esi
  _DWORD *namea_17; // eax
  int Field1334h; // eax
  _DWORD *m_pNexta_3; // esi
  int v23; // ebx
  _DWORD *v24; // ecx
  _DWORD *namea_48; // ecx
  _DWORD *namea_20; // edx
  _DWORD *namea_19; // esi
  _DWORD *v28; // ecx
  _DWORD *namea_49; // ecx
  _DWORD *namea_22; // edx
  _DWORD *namea_21; // esi
  _DWORD *v32; // ecx
  _DWORD *namea_50; // esi
  _DWORD *v34; // ecx
  const char *Field1334h_13; // ebx
  _DWORD *namea_24; // edx
  _DWORD *namea_23; // eax
  PhyrePClassDescriptor *m_pParentCD; // eax
  int v39; // eax
  char v40; // bl
  int *dst_1; // edi
  const char *Src_1; // esi
  int *v43; // eax
  int v44; // ecx
  char v45; // al
  _DWORD *v46; // ecx
  unsigned int namea_27; // ecx
  _DWORD *v48; // ebx
  int *dsta_2; // edi
  unsigned int Field1334h_3; // eax
  unsigned int Srcc_3; // esi
  unsigned int Srca_1; // edx
  char *dst_5; // edi
  char *dst_4; // esi
  int *dst_3; // edi
  unsigned int Field1334h_2; // ecx
  unsigned int n4; // eax
  unsigned int n4_1; // edx
  unsigned int Srca_2; // eax
  unsigned int Srcc_4; // ecx
  int v61; // edi
  unsigned int v62; // edi
  _DWORD *Srcc_11; // esi
  _DWORD *namea_26; // eax
  PhyrePClassDescriptor *m_pParentCD_1; // eax
  int v66; // eax
  _DWORD *Srcc_12; // esi
  unsigned int Field1334h_14; // edx
  _DWORD *namea_29; // eax
  _DWORD *v70; // ecx
  char *dsta_4; // edi
  unsigned int Srcc_6; // ecx
  _DWORD *v73; // ebx
  unsigned int Field1334h_7; // eax
  int v75; // edx
  int namea_31; // esi
  char *Srcb_1; // edi
  int dst_7; // ecx
  int *dsta_6; // eax
  unsigned int v80; // eax
  int namea_32; // edx
  int v82; // edi
  int v83; // edi
  int *Srcb_2; // esi
  _DWORD *namea_33; // edx
  _DWORD *Srcc_5; // eax
  PhyrePClassDescriptor *m_pParentCD_2; // eax
  int v88; // eax
  _DWORD *namea_34; // edx
  unsigned int Field1334h_9; // esi
  _DWORD *Srcc_8; // eax
  _DWORD *v92; // ecx
  int *Srcc_1; // edi
  int dsta_7; // edx
  _DWORD *namea_36; // ecx
  _DWORD *v96; // ebx
  char *Srcd_1; // edx
  unsigned int v98; // esi
  unsigned int v99; // eax
  unsigned int v100; // ecx
  unsigned int v101; // edi
  int Bytes_Validate_1; // eax
  _DWORD *Srcc_9; // esi
  _DWORD *namea_37; // edi
  PhyrePClassDescriptor *m_pParentCD_3; // eax
  int v106; // eax
  _DWORD *Srcc_10; // esi
  unsigned int Field1334h_12; // edx
  int dsta_9; // eax
  _DWORD *namea_38; // edi
  _DWORD *v111; // ecx
  _DWORD *namea_39; // ebx
  HANDLE *dsta_10; // edx
  _DWORD *v114; // esi
  _DWORD *namea_3; // edi
  int result; // eax
  _DWORD *namea_2; // eax
  PhyrePClassDescriptor *m_pParentCD_4; // eax
  int v119; // eax
  const char *Srce_1; // ecx
  _DWORD *namea_4; // eax
  _DWORD *v122; // ecx
  _DWORD *namea_40; // ebx
  HANDLE *dsta_12; // edx
  _DWORD *v125; // esi
  _DWORD *nameb_2; // edi
  _DWORD *nameb_1; // eax
  PhyrePClassDescriptor *m_pParentCD_5; // eax
  int v129; // eax
  const char *Srcf_1; // ecx
  _DWORD *nameb_3; // eax
  _DWORD *m_pNexta_2; // ebx
  _DWORD *v133; // ecx
  _DWORD *namea_41; // esi
  _DWORD *namea_6; // edi
  _DWORD *namea_5; // ebx
  _DWORD *v137; // ecx
  _DWORD *namea_42; // esi
  _DWORD *namea_8; // edi
  _DWORD *namea_7; // ebx
  _DWORD *v141; // ecx
  _DWORD *namea_43; // esi
  unsigned int namea_10; // edi
  _DWORD *namea_9; // ebx
  _DWORD *v145; // ecx
  _DWORD *namea_44; // esi
  _DWORD *namea_12; // edi
  _DWORD *namea_11; // ebx
  int v149; // [esp+0h] [ebp-98h]
  char *dst; // [esp+4h] [ebp-94h]
  int v151; // [esp+8h] [ebp-90h]
  int *Srcc; // [esp+10h] [ebp-88h]
  int v153; // [esp+14h] [ebp-84h]
  int v154; // [esp+18h] [ebp-80h]
  int v155; // [esp+18h] [ebp-80h]
  _DWORD *v156; // [esp+1Ch] [ebp-7Ch]
  char *dsta_5; // [esp+20h] [ebp-78h]
  unsigned int Field1334h_11; // [esp+20h] [ebp-78h]
  int *ptr_1; // [esp+24h] [ebp-74h]
  int v160; // [esp+24h] [ebp-74h]
  char *dsta; // [esp+28h] [ebp-70h]
  int *dstaa; // [esp+28h] [ebp-70h]
  int *Field1334h_10; // [esp+2Ch] [ebp-6Ch]
  int *dst_2; // [esp+30h] [ebp-68h]
  unsigned int v165; // [esp+30h] [ebp-68h]
  int *ptr; // [esp+34h] [ebp-64h]
  int ptra; // [esp+34h] [ebp-64h]
  HANDLE *dsta_11; // [esp+38h] [ebp-60h] BYREF
  unsigned int Field1334h_4; // [esp+3Ch] [ebp-5Ch]
  int *dsta_3; // [esp+40h] [ebp-58h]
  unsigned int Field1334h_8; // [esp+44h] [ebp-54h]
  unsigned int Field1334h_1; // [esp+48h] [ebp-50h]
  unsigned int Field1334h_5; // [esp+4Ch] [ebp-4Ch]
  int *dsta_8; // [esp+50h] [ebp-48h]
  _DWORD *dst_6; // [esp+54h] [ebp-44h]
  _DWORD *Srcc_7; // [esp+58h] [ebp-40h]
  unsigned int Srcc_2; // [esp+5Ch] [ebp-3Ch]
  unsigned int namea_25; // [esp+60h] [ebp-38h]
  _DWORD *namea_28; // [esp+64h] [ebp-34h]
  unsigned int namea_35; // [esp+68h] [ebp-30h] BYREF
  _DWORD *namea_1; // [esp+6Ch] [ebp-2Ch]
  unsigned int Field1334h_6; // [esp+70h] [ebp-28h]
  _DWORD *namea_30; // [esp+74h] [ebp-24h]
  char *dsta_1; // [esp+78h] [ebp-20h]
  _DWORD *m_pNexta_1; // [esp+7Ch] [ebp-1Ch]
  _DWORD *v186; // [esp+80h] [ebp-18h]
  PhyrePClassDescriptor *parentCD; // [esp+84h] [ebp-14h]
  char v188; // [esp+8Bh] [ebp-Dh]
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+8Ch] [ebp-Ch]
  void *v190; // [esp+90h] [ebp-8h]
  int v191; // [esp+94h] [ebp-4h]
  int savedregs; // [esp+98h] [ebp+0h] BYREF
  _DWORD *m_pNexta; // [esp+A0h] [ebp+8h]
  int namea; // [esp+A4h] [ebp+Ch]
  int nameb; // [esp+A4h] [ebp+Ch]
  unsigned int Srca; // [esp+A8h] [ebp+10h]
  char *Srcb; // [esp+A8h] [ebp+10h]
  char *Srcd; // [esp+A8h] [ebp+10h]
  const char *Srce; // [esp+A8h] [ebp+10h]
  const char *Srcf; // [esp+A8h] [ebp+10h]

  savedregs = (int)&savedregs;
  v191 = -1;
  v190 = &loc_AA93B6;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v4 = *(Size + 5);
  v5 = *(Size + 6);
  v151 = *(Size + 7);
  v154 = v4;
  if ( !(v5 | v4 | v151) )
    goto LABEL_243;
  Phyre_Cluster_ZeroInitArea(&dsta_11);
  v191 = 0;
  if ( v5 )
  {
    ptr = Engine_AlignedAllocAlign(v5, 16);
    Bytes_Validate = Phyre_PStreamReader_ReadBytes_Validate(m_pNext, (int)ptr, v5);
    if ( Bytes_Validate )
      goto LABEL_254;
    PhyreManaged_ContainerCtor_Size65(&namea_35, name);
LABEL_5:
    namea_45 = namea_30;
    if ( namea_30 )
    {
      namea_14 = namea_35;
      while ( 1 )
      {
        v9 = &dsta_1[namea_14];
        Phyre_PIndexDataBlock_StaticInit((unsigned int ************)&dsta_1[namea_14], (int)ptr);
        *((_DWORD *)v9 + 11) = 0;
        if ( !namea_45 )
          break;
        namea_13 = namea_1;
        while ( 1 )
        {
          namea_14 += Field1334h_6;
          namea_45 = (_DWORD *)((char *)namea_45 - 1);
          namea_35 = namea_14;
          namea_30 = namea_45;
          if ( namea_13 != (_DWORD *)namea_14 )
            break;
          namea_13 = (_DWORD *)*namea_13;
          namea_1 = namea_13;
          if ( !namea_45 )
            goto LABEL_11;
        }
        if ( !namea_45 )
        {
LABEL_11:
          ManagedStrIter_Next_4(&namea_35);
          goto LABEL_5;
        }
      }
    }
    v11 = name + 28 != *(_DWORD *)(name + 28) ? *(_DWORD **)(name + 28) : 0;
    namea_35 = 0;
    namea_1 = 0;
    Field1334h_6 = 0;
    namea_30 = 0;
    dsta_1 = 0;
    m_pNexta_1 = (_DWORD *)(name + 28);
    v186 = v11;
    parentCD = &parentCD__27;
    ManagedStrIter_Next_WithGuard_B(&namea_35);
LABEL_15:
    namea_46 = namea_30;
    if ( namea_30 )
    {
      namea_16 = namea_35;
      while ( 1 )
      {
        dsta_13 = dsta_1;
        Phyre_PIndexDataBlock_StaticInit((unsigned int ************)&dsta_1[namea_16 + 48], (int)ptr);
        *(_DWORD *)&dsta_13[namea_16 + 92] = 0;
        if ( !namea_46 )
          break;
        namea_15 = namea_1;
        while ( 1 )
        {
          namea_16 += Field1334h_6;
          namea_46 = (_DWORD *)((char *)namea_46 - 1);
          namea_35 = namea_16;
          namea_30 = namea_46;
          if ( namea_15 != (_DWORD *)namea_16 )
            break;
          namea_15 = (_DWORD *)*namea_15;
          namea_1 = namea_15;
          if ( !namea_46 )
            goto LABEL_21;
        }
        if ( !namea_46 )
        {
LABEL_21:
          ManagedStrIter_Next_5(&namea_35);
          goto LABEL_15;
        }
      }
    }
    Engine_AlignedFree(ptr);
    v4 = v154;
  }
  if ( v4 )
  {
    ptr_1 = Engine_AlignedAllocAlign(v4, 16);
    Bytes_Validate = Phyre_PStreamReader_ReadBytes_Validate(m_pNext, (int)ptr_1, v4);
    if ( !Bytes_Validate )
    {
      namea_35 = 0;
      namea_1 = 0;
      Field1334h_6 = 0;
      namea_30 = 0;
      dsta_1 = 0;
      v16 = name + 28 != *(_DWORD *)(name + 28) ? *(_DWORD **)(name + 28) : 0;
      m_pNexta_1 = (_DWORD *)(name + 28);
      v186 = v16;
      parentCD = &parentCD__25;
      PhyreManaged_StringListIterate_A(&namea_35);
LABEL_28:
      namea_47 = namea_30;
      if ( namea_30 )
      {
        namea_18 = namea_35;
        while ( 1 )
        {
          v19 = &dsta_1[namea_18];
          PDataBlock_StaticInit((unsigned int ***********)&dsta_1[namea_18], (int)ptr_1);
          *((_DWORD *)v19 + 12) = 0;
          if ( !namea_47 )
            break;
          namea_17 = namea_1;
          while ( 1 )
          {
            namea_18 += Field1334h_6;
            namea_47 = (_DWORD *)((char *)namea_47 - 1);
            namea_35 = namea_18;
            namea_30 = namea_47;
            if ( namea_17 != (_DWORD *)namea_18 )
              break;
            namea_17 = (_DWORD *)*namea_17;
            namea_1 = namea_17;
            if ( !namea_47 )
              goto LABEL_34;
          }
          if ( !namea_47 )
          {
LABEL_34:
            ManagedStrIter_Next_13(&namea_35);
            goto LABEL_28;
          }
        }
      }
      Engine_AlignedFree(ptr_1);
      goto LABEL_38;
    }
LABEL_254:
    v191 = -1;
    Phyre_Cluster_ReadFieldsFromStream(&dsta_11);
    return Bytes_Validate;
  }
LABEL_38:
  if ( v151 )
  {
    Field1334h_10 = Engine_AlignedAllocAlign(2 * v151, 16);
    if ( (g_PhyreResSysInitFlag[0] & 1) == 0 )
    {
      g_PhyreResSysInitFlag[0] |= 1u;
      LOBYTE(v191) = 1;
      Phyre_PArrayPSceneWideParam_BoolReturn(Singleton_C94F00);
      atexit(Phyre_Shader_CompilePass_C94F00);
      LOBYTE(v191) = 0;
    }
    Field1334h = Phyre_Managed_GetField1334h(Singleton_C94F00);
    m_pNexta_3 = (_DWORD *)(name + 28);
    v23 = 0;
    v24 = name + 28 != *(_DWORD *)(name + 28) ? *(_DWORD **)(name + 28) : 0;
    Field1334h_1 = Field1334h;
    v186 = v24;
    v149 = m_pNext[3];
    v188 = 0;
    v160 = 0;
    ptra = 0;
    v153 = 0;
    namea_35 = 0;
    namea_1 = 0;
    Field1334h_6 = 0;
    namea_30 = 0;
    dsta_1 = 0;
    v156 = (_DWORD *)(name + 28);
    m_pNexta_1 = (_DWORD *)(name + 28);
    parentCD = &PClassDescriptor_PTexture2D;
    ManagedStrIter_Next_2(&namea_35);
    namea_48 = namea_30;
    if ( namea_30 )
    {
      do
      {
        namea_20 = (_DWORD *)namea_35;
        namea_19 = namea_1;
LABEL_43:
        if ( *(_DWORD *)((char *)namea_20 + (_DWORD)dsta_1 + 12) )
          v188 = 1;
        ++v23;
        if ( !namea_48 )
          break;
        while ( 1 )
        {
          namea_20 = (_DWORD *)((char *)namea_20 + Field1334h_6);
          namea_48 = (_DWORD *)((char *)namea_48 - 1);
          namea_35 = (unsigned int)namea_20;
          namea_30 = namea_48;
          if ( namea_19 != namea_20 )
            break;
          namea_19 = (_DWORD *)*namea_19;
          namea_1 = namea_19;
          if ( !namea_48 )
            goto LABEL_50;
        }
        if ( namea_48 )
          goto LABEL_43;
LABEL_50:
        ManagedStrIter_Next_10(&namea_35);
        namea_48 = namea_30;
      }
      while ( namea_30 );
      m_pNexta_3 = (_DWORD *)(name + 28);
      v160 = v23;
    }
    v28 = m_pNexta_3 != (_DWORD *)*m_pNexta_3 ? (_DWORD *)*m_pNexta_3 : 0;
    namea_35 = 0;
    v186 = v28;
    namea_1 = 0;
    Field1334h_6 = 0;
    namea_30 = 0;
    dsta_1 = 0;
    m_pNexta_1 = m_pNexta_3;
    parentCD = &PClassDescriptor_PTexture3D;
    ManagedStrIter_Next_WithGuard_I(&namea_35);
    namea_49 = namea_30;
    if ( namea_30 )
    {
      do
      {
        namea_22 = (_DWORD *)namea_35;
        namea_21 = namea_1;
LABEL_54:
        if ( *(_DWORD *)((char *)namea_22 + (_DWORD)dsta_1 + 12) )
          v188 = 1;
        ++ptra;
        if ( !namea_49 )
          break;
        while ( 1 )
        {
          namea_22 = (_DWORD *)((char *)namea_22 + Field1334h_6);
          namea_49 = (_DWORD *)((char *)namea_49 - 1);
          namea_35 = (unsigned int)namea_22;
          namea_30 = namea_49;
          if ( namea_21 != namea_22 )
            break;
          namea_21 = (_DWORD *)*namea_21;
          namea_1 = namea_21;
          if ( !namea_49 )
            goto LABEL_61;
        }
        if ( namea_49 )
          goto LABEL_54;
LABEL_61:
        ManagedStrIter_Next_11(&namea_35);
        namea_49 = namea_30;
      }
      while ( namea_30 );
      m_pNexta_3 = (_DWORD *)(name + 28);
    }
    v32 = m_pNexta_3 != (_DWORD *)*m_pNexta_3 ? (_DWORD *)*m_pNexta_3 : 0;
    namea_35 = 0;
    v186 = v32;
    namea_1 = 0;
    Field1334h_6 = 0;
    namea_30 = 0;
    dsta_1 = 0;
    m_pNexta_1 = m_pNexta_3;
    parentCD = &PClassDescriptor_PTextureCubeMap;
    ManagedStrIter_Next_3(&namea_35);
    namea_50 = namea_30;
    if ( namea_30 )
    {
      v34 = v186;
      Field1334h_13 = (const char *)Field1334h_6;
      namea_24 = (_DWORD *)namea_35;
      dsta = dsta_1;
      namea_23 = namea_1;
      while ( 1 )
      {
LABEL_65:
        if ( *(_DWORD *)((char *)namea_24 + (_DWORD)dsta + 12) )
          v188 = 1;
        ++v153;
        if ( !namea_50 )
          break;
        while ( 1 )
        {
          namea_24 = (_DWORD *)((char *)namea_24 + (_DWORD)Field1334h_13);
          namea_50 = (_DWORD *)((char *)namea_50 - 1);
          if ( namea_23 != namea_24 )
            break;
          namea_23 = (_DWORD *)*namea_23;
          if ( !namea_50 )
            goto LABEL_72;
        }
        if ( !namea_50 )
        {
LABEL_72:
          while ( v34 )
          {
            v34 = m_pNexta_1 != (_DWORD *)*v34 ? (_DWORD *)*v34 : 0;
            if ( !v34 )
              break;
            m_pParentCD = (PhyrePClassDescriptor *)v34[11];
            if ( m_pParentCD )
            {
              while ( m_pParentCD != parentCD )
              {
                m_pParentCD = (PhyrePClassDescriptor *)m_pParentCD->m_pParentCD;
                if ( !m_pParentCD )
                  goto LABEL_72;
              }
              if ( v34[16] )
              {
                v39 = v34[11];
                namea_50 = (_DWORD *)v34[15];
                Field1334h_13 = *(const char **)(v39 + 28);
                namea_24 = (_DWORD *)v34[13];
                dsta = *(char **)(v39 + 140);
                namea_23 = (_DWORD *)v34[2];
                if ( !namea_50 )
                  goto LABEL_82;
                while ( namea_23 == namea_24 )
                {
                  namea_23 = (_DWORD *)*namea_23;
                  namea_24 = (_DWORD *)((char *)namea_24 + (_DWORD)Field1334h_13);
                  namea_50 = (_DWORD *)((char *)namea_50 - 1);
                  if ( !namea_50 )
                    goto LABEL_82;
                }
                goto LABEL_65;
              }
            }
          }
          break;
        }
      }
    }
LABEL_82:
    v40 = v188;
    if ( v188 && v160 )
    {
      dst_1 = Engine_AlignedAllocAlign(116 * v160, 16);
      dst = (char *)dst_1;
    }
    else
    {
      dst_1 = 0;
      dst = 0;
    }
    if ( v40 && ptra )
      dstaa = Engine_AlignedAllocAlign(104 * ptra, 16);
    else
      dstaa = 0;
    if ( v40 && v153 )
      Srcc = Engine_AlignedAllocAlign(104 * v153, 16);
    else
      Srcc = 0;
    if ( v40 )
    {
      Src_1 = Src;
      v43 = Engine_AlignedAllocAlign(strlen(Src) + 1, 16);
      v155 = (int)v43;
      if ( v43 )
      {
        v44 = (char *)v43 - Src;
        do
        {
          v45 = *Src_1;
          Src_1[v44] = *Src_1;
          ++Src_1;
        }
        while ( v45 );
      }
    }
    else
    {
      v155 = 0;
    }
    namea_35 = 0;
    v46 = v156 != (_DWORD *)*v156 ? (_DWORD *)*v156 : 0;
    namea_1 = 0;
    v186 = v46;
    Field1334h_6 = 0;
    namea_30 = 0;
    dsta_1 = 0;
    m_pNexta_1 = (_DWORD *)(name + 28);
    parentCD = &PClassDescriptor_PTexture2D;
    ManagedStrIter_Next_2(&namea_35);
    Srcc_7 = namea_30;
    if ( namea_30 )
    {
      namea_27 = namea_35;
      v48 = v186;
      dst_2 = dst_1;
      dsta_2 = (int *)dsta_1;
      Field1334h_8 = Field1334h_6;
      dsta_3 = (int *)dsta_1;
      namea_25 = (unsigned int)namea_1;
      namea_28 = (_DWORD *)namea_35;
LABEL_102:
      Field1334h_3 = *(int *)((char *)dsta_2 + namea_27 + 12);
      Srcc_3 = *(int *)((char *)dsta_2 + namea_27 + 28);
      Srca_1 = *(int *)((char *)dsta_2 + namea_27 + 32);
      dst_5 = (char *)dsta_2 + namea_27;
      dst_6 = dst_5;
      Field1334h_5 = Field1334h_3;
      Srcc_2 = Srcc_3;
      Srca = Srca_1;
      if ( v188 )
      {
        dst_4 = dst_5;
        dst_3 = dst_2;
        dst_2 += 29;
        qmemcpy(dst_3, dst_4, 0x74u);
        Srcc_3 = Srcc_2;
        dst_5 = (char *)dst_6;
      }
      Field1334h_2 = Field1334h_1;
      if ( Field1334h_3 >= Field1334h_1 )
      {
        n4 = Srcc_3 >> Field1334h_1;
        n4_1 = Srca_1 >> Field1334h_1;
        if ( Field1334h_1 )
        {
          do
          {
            if ( n4 >= 4 && n4_1 >= 4 )
              break;
            n4 *= 2;
            n4_1 *= 2;
            --Field1334h_2;
          }
          while ( Field1334h_2 );
          Field1334h_1 = Field1334h_2;
        }
        Srca_1 = Srca;
      }
      dsta_8 = Field1334h_10;
      Field1334h_4 = 0;
      while ( 1 )
      {
        Srca_2 = Srca_1;
        Srcc_4 = Srcc_3;
        if ( !Srcc_3 )
          Srcc_4 = *((_DWORD *)dst_5 + 7);
        if ( !Srca_1 )
          Srca_2 = *((_DWORD *)dst_5 + 8);
        v61 = *(_DWORD *)dst_5;
        if ( (*(_BYTE *)(v61 + 16) & 1) != 0 )
        {
          Srcc_4 = (Srcc_4 + 3) & 0xFFFFFFFC;
          Srca_2 = (Srca_2 + 3) & 0xFFFFFFFC;
        }
        v62 = (Srca_2 * Srcc_4 * *(_DWORD *)(v61 + 12)) >> 3;
        Bytes_Validate = Phyre_PStreamReader_ReadBytes_Validate(m_pNext, (int)dsta_8, v62);
        if ( Bytes_Validate )
          goto LABEL_254;
        if ( Field1334h_4 >= Field1334h_1 || Field1334h_5 < Field1334h_1 )
          dsta_8 = (int *)((char *)dsta_8 + v62);
        Srcc_3 = Srcc_2 >> 1;
        Srcc_2 = Srcc_3;
        if ( !Srcc_3 )
        {
          Srcc_3 = 1;
          Srcc_2 = 1;
        }
        Srca_1 = Srca >> 1;
        Srca = Srca_1;
        if ( !Srca_1 )
        {
          Srca_1 = 1;
          Srca = 1;
        }
        dst_5 = (char *)dst_6;
        if ( ++Field1334h_4 > Field1334h_5 )
        {
          if ( Field1334h_1 && Field1334h_5 >= Field1334h_1 )
            PTextureDescription_ValidateAndSetConfig(
              dst_6,
              dst_6[7] >> Field1334h_1,
              dst_6[8] >> Field1334h_1,
              *dst_6,
              dst_6[3] - Field1334h_1);
          Bytes_Validate = Phyre_Texture_Construct((int *)dst_5, (char *)Field1334h_10, 1, 0, 0);
          if ( Bytes_Validate )
            goto LABEL_254;
          if ( *(_DWORD **)dst_5 == g_ResStreamHandlerPtr )
          {
LABEL_252:
            Bytes_Validate = 7;
            goto LABEL_254;
          }
          if ( !Phyre_PVideoTexture_HasTextureFlag70(dst_5) )
          {
            Bytes_Validate = Phyre_Texture_LazyConstructFromFormat((int *)dst_5);
            if ( Bytes_Validate )
              goto LABEL_254;
          }
          Srcc_11 = Srcc_7;
          if ( !Srcc_7 )
            break;
          namea_27 = (unsigned int)namea_28;
          namea_26 = (_DWORD *)namea_25;
          while ( 1 )
          {
            namea_27 += Field1334h_8;
            Srcc_11 = (_DWORD *)((char *)Srcc_11 - 1);
            namea_28 = (_DWORD *)namea_27;
            Srcc_7 = Srcc_11;
            if ( namea_26 != (_DWORD *)namea_27 )
              break;
            namea_26 = (_DWORD *)*namea_26;
            namea_25 = (unsigned int)namea_26;
            if ( !Srcc_11 )
              goto LABEL_140;
          }
          dsta_2 = dsta_3;
          if ( !Srcc_11 )
          {
LABEL_140:
            while ( v48 )
            {
              v48 = m_pNexta_1 != (_DWORD *)*v48 ? (_DWORD *)*v48 : 0;
              if ( !v48 )
                break;
              m_pParentCD_1 = (PhyrePClassDescriptor *)v48[11];
              if ( m_pParentCD_1 )
              {
                while ( m_pParentCD_1 != parentCD )
                {
                  m_pParentCD_1 = (PhyrePClassDescriptor *)m_pParentCD_1->m_pParentCD;
                  if ( !m_pParentCD_1 )
                    goto LABEL_140;
                }
                if ( v48[16] )
                {
                  v66 = v48[11];
                  Srcc_12 = (_DWORD *)v48[15];
                  Field1334h_14 = *(_DWORD *)(v66 + 28);
                  dsta_2 = *(int **)(v66 + 140);
                  namea_27 = v48[13];
                  namea_29 = (_DWORD *)v48[2];
                  Field1334h_8 = Field1334h_14;
                  namea_28 = (_DWORD *)namea_27;
                  Srcc_7 = Srcc_12;
                  dsta_3 = dsta_2;
                  namea_25 = (unsigned int)namea_29;
                  if ( !Srcc_12 )
                    goto LABEL_150;
                  while ( namea_29 == (_DWORD *)namea_27 )
                  {
                    namea_29 = (_DWORD *)*namea_29;
                    namea_27 += Field1334h_14;
                    Srcc_12 = (_DWORD *)((char *)Srcc_12 - 1);
                    namea_28 = (_DWORD *)namea_27;
                    Srcc_7 = Srcc_12;
                    namea_25 = (unsigned int)namea_29;
                    if ( !Srcc_12 )
                      goto LABEL_150;
                  }
                  goto LABEL_102;
                }
              }
            }
            break;
          }
          goto LABEL_102;
        }
      }
    }
LABEL_150:
    namea_35 = 0;
    v70 = v156 != (_DWORD *)*v156 ? (_DWORD *)*v156 : 0;
    namea_1 = 0;
    v186 = v70;
    Field1334h_6 = 0;
    namea_30 = 0;
    dsta_1 = 0;
    m_pNexta_1 = (_DWORD *)(name + 28);
    parentCD = &PClassDescriptor_PTexture3D;
    ManagedStrIter_Next_WithGuard_I(&namea_35);
    namea_28 = namea_30;
    if ( namea_30 )
    {
      dsta_4 = dsta_1;
      Srcc_6 = namea_35;
      v73 = v186;
      dsta_3 = dstaa;
      Field1334h_4 = Field1334h_6;
      dsta_5 = dsta_1;
      Srcc_2 = (unsigned int)namea_1;
      Srcc_7 = (_DWORD *)namea_35;
LABEL_152:
      Field1334h_7 = *(_DWORD *)&dsta_4[Srcc_6 + 12];
      v75 = *(_DWORD *)&dsta_4[Srcc_6 + 32];
      namea_31 = *(_DWORD *)&dsta_4[Srcc_6 + 36];
      Srcb_1 = &dsta_4[Srcc_6];
      dst_7 = *((_DWORD *)Srcb_1 + 7);
      Srcb = Srcb_1;
      Field1334h_5 = Field1334h_7;
      dst_6 = (_DWORD *)dst_7;
      v165 = v75;
      namea_25 = namea_31;
      if ( v188 )
      {
        dsta_6 = dsta_3;
        qmemcpy(dsta_3, Srcb_1, 0x68u);
        namea_31 = namea_25;
        dst_7 = (int)dst_6;
        dsta_3 = dsta_6 + 26;
      }
      dsta_8 = Field1334h_10;
      Field1334h_8 = 0;
      while ( 1 )
      {
        v80 = v75;
        if ( !dst_6 )
          dst_7 = *((_DWORD *)Srcb_1 + 7);
        if ( !v75 )
          v80 = *((_DWORD *)Srcb_1 + 8);
        if ( namea_31 )
          namea_32 = namea_31;
        else
          namea_32 = *((_DWORD *)Srcb_1 + 9);
        v82 = *(_DWORD *)Srcb_1;
        if ( (*(_BYTE *)(v82 + 16) & 1) != 0 )
        {
          dst_7 = (dst_7 + 3) & 0xFFFFFFFC;
          v80 = (v80 + 3) & 0xFFFFFFFC;
        }
        v83 = namea_32 * ((v80 * dst_7 * *(_DWORD *)(v82 + 12)) >> 3);
        Bytes_Validate = Phyre_PStreamReader_ReadBytes_Validate(m_pNext, (int)dsta_8, v83);
        if ( Bytes_Validate )
          goto LABEL_254;
        if ( Field1334h_8 >= Field1334h_1 || Field1334h_5 < Field1334h_1 )
          dsta_8 = (int *)((char *)dsta_8 + v83);
        dst_7 = (unsigned int)dst_6 >> 1;
        dst_6 = (_DWORD *)dst_7;
        if ( !dst_7 )
        {
          dst_7 = 1;
          dst_6 = (_DWORD *)1;
        }
        v75 = v165 >> 1;
        v165 = v75;
        if ( !v75 )
        {
          v75 = 1;
          v165 = 1;
        }
        namea_31 = namea_25 >> 1;
        namea_25 = namea_31;
        if ( !namea_31 )
        {
          namea_31 = 1;
          namea_25 = 1;
        }
        Srcb_1 = Srcb;
        if ( ++Field1334h_8 > Field1334h_5 )
        {
          if ( Field1334h_1 && Field1334h_5 >= Field1334h_1 )
          {
            Srcb_2 = (int *)Srcb;
            PTextureDescription_ValidateAndSetConfigV2(
              Srcb,
              *((_DWORD *)Srcb + 7) >> Field1334h_1,
              *((_DWORD *)Srcb + 8) >> Field1334h_1,
              *((_DWORD *)Srcb + 9) >> Field1334h_1,
              *(_DWORD *)Srcb,
              *((_DWORD *)Srcb + 3) - Field1334h_1);
          }
          else
          {
            Srcb_2 = (int *)Srcb;
          }
          Bytes_Validate = Phyre_Type_ConstructFromChunk(Srcb_2, (unsigned int)Field1334h_10, 1, 0, 0);
          if ( Bytes_Validate )
            goto LABEL_254;
          if ( *(_DWORD **)Srcb == g_ResStreamHandlerPtr )
            goto LABEL_252;
          if ( !Phyre_PTexture3D_HasFlag64(Srcb) )
          {
            Bytes_Validate = Phyre_Type_LazyConstructFromChunk((int *)Srcb);
            if ( Bytes_Validate )
              goto LABEL_254;
          }
          namea_33 = namea_28;
          if ( !namea_28 )
            break;
          Srcc_6 = (unsigned int)Srcc_7;
          Srcc_5 = (_DWORD *)Srcc_2;
          while ( 1 )
          {
            Srcc_6 += Field1334h_4;
            namea_33 = (_DWORD *)((char *)namea_33 - 1);
            Srcc_7 = (_DWORD *)Srcc_6;
            namea_28 = namea_33;
            if ( Srcc_5 != (_DWORD *)Srcc_6 )
              break;
            Srcc_5 = (_DWORD *)*Srcc_5;
            Srcc_2 = (unsigned int)Srcc_5;
            if ( !namea_33 )
              goto LABEL_189;
          }
          dsta_4 = dsta_5;
          if ( !namea_33 )
          {
LABEL_189:
            while ( v73 )
            {
              v73 = m_pNexta_1 != (_DWORD *)*v73 ? (_DWORD *)*v73 : 0;
              if ( !v73 )
                break;
              m_pParentCD_2 = (PhyrePClassDescriptor *)v73[11];
              if ( m_pParentCD_2 )
              {
                while ( m_pParentCD_2 != parentCD )
                {
                  m_pParentCD_2 = (PhyrePClassDescriptor *)m_pParentCD_2->m_pParentCD;
                  if ( !m_pParentCD_2 )
                    goto LABEL_189;
                }
                if ( v73[16] )
                {
                  v88 = v73[11];
                  namea_34 = (_DWORD *)v73[15];
                  Field1334h_9 = *(_DWORD *)(v88 + 28);
                  dsta_4 = *(char **)(v88 + 140);
                  Srcc_6 = v73[13];
                  Srcc_8 = (_DWORD *)v73[2];
                  Field1334h_4 = Field1334h_9;
                  Srcc_7 = (_DWORD *)Srcc_6;
                  namea_28 = namea_34;
                  dsta_5 = dsta_4;
                  Srcc_2 = (unsigned int)Srcc_8;
                  if ( !namea_34 )
                    goto LABEL_199;
                  while ( Srcc_8 == (_DWORD *)Srcc_6 )
                  {
                    Srcc_8 = (_DWORD *)*Srcc_8;
                    Srcc_6 += Field1334h_9;
                    namea_34 = (_DWORD *)((char *)namea_34 - 1);
                    Srcc_7 = (_DWORD *)Srcc_6;
                    namea_28 = namea_34;
                    Srcc_2 = (unsigned int)Srcc_8;
                    if ( !namea_34 )
                      goto LABEL_199;
                  }
                  goto LABEL_152;
                }
              }
            }
            break;
          }
          goto LABEL_152;
        }
      }
    }
LABEL_199:
    namea_35 = 0;
    v92 = v156 != (_DWORD *)*v156 ? (_DWORD *)*v156 : 0;
    namea_1 = 0;
    v186 = v92;
    Field1334h_6 = 0;
    namea_30 = 0;
    dsta_1 = 0;
    m_pNexta_1 = (_DWORD *)(name + 28);
    parentCD = &PClassDescriptor_PTextureCubeMap;
    ManagedStrIter_Next_3(&namea_35);
    Srcc_7 = namea_30;
    if ( namea_30 )
    {
      Srcc_1 = Srcc;
      dsta_7 = (int)dsta_1;
      namea_36 = (_DWORD *)namea_35;
      v96 = v186;
      Field1334h_4 = Field1334h_6;
      Srcc_2 = (unsigned int)Srcc;
      dsta_8 = (int *)dsta_1;
      namea_28 = namea_1;
      namea_25 = namea_35;
      while ( 1 )
      {
LABEL_201:
        Srcd_1 = (char *)namea_36 + dsta_7;
        Field1334h_5 = (unsigned int)Field1334h_10;
        Srcd = Srcd_1;
        Field1334h_11 = *((_DWORD *)Srcd_1 + 3);
        if ( v188 )
        {
          Srcc_2 += 104;
          qmemcpy(Srcc_1, Srcd_1, 0x68u);
        }
        Field1334h_8 = 0;
        while ( 2 )
        {
          v98 = *((_DWORD *)Srcd_1 + 7);
          dsta_3 = 0;
          do
          {
            v99 = v98;
            if ( !v98 )
              v99 = *((_DWORD *)Srcd_1 + 7);
            v100 = v99;
            if ( (*(_BYTE *)(*(_DWORD *)Srcd_1 + 16) & 1) != 0 )
            {
              v99 = (v99 + 3) & 0xFFFFFFFC;
              v100 = v99;
            }
            v101 = (v99 * v100 * *(_DWORD *)(*(_DWORD *)Srcd_1 + 12)) >> 3;
            Bytes_Validate_1 = Phyre_PStreamReader_ReadBytes_Validate(m_pNext, Field1334h_5, v101);
            if ( Bytes_Validate_1 )
            {
              Bytes_Validate = Bytes_Validate_1;
              goto LABEL_254;
            }
            v98 >>= 1;
            if ( !v98 )
              v98 = 1;
            if ( (unsigned int)dsta_3 >= Field1334h_1 || Field1334h_11 < Field1334h_1 )
              Field1334h_5 += v101;
            Srcd_1 = Srcd;
            dsta_3 = (int *)((char *)dsta_3 + 1);
          }
          while ( (unsigned int)dsta_3 <= Field1334h_11 );
          if ( ++Field1334h_8 < 6 )
            continue;
          break;
        }
        if ( Field1334h_1 && Field1334h_11 >= Field1334h_1 )
          PTextureFormat_SetDimensions(
            Srcd,
            *((_DWORD *)Srcd + 7) >> Field1334h_1,
            *(_DWORD *)Srcd,
            *((_DWORD *)Srcd + 3) - Field1334h_1);
        Bytes_Validate = Phyre_Type_ConstructFromChunkVariableSize((int *)Srcd, (unsigned int)Field1334h_10, 1, 0, 0);
        if ( Bytes_Validate )
          goto LABEL_254;
        if ( *(_DWORD **)Srcd == g_ResStreamHandlerPtr )
          goto LABEL_252;
        if ( !Phyre_PTextureCubeMap_HasFlag64(Srcd) )
        {
          Bytes_Validate = Phyre_Type_LazyConstructFromChunkVariableSize((int *)Srcd);
          if ( Bytes_Validate )
            goto LABEL_254;
        }
        Srcc_9 = Srcc_7;
        if ( !Srcc_7 )
          break;
        namea_36 = (_DWORD *)namea_25;
        namea_37 = namea_28;
        while ( 1 )
        {
          namea_36 = (_DWORD *)((char *)namea_36 + Field1334h_4);
          Srcc_9 = (_DWORD *)((char *)Srcc_9 - 1);
          namea_25 = (unsigned int)namea_36;
          Srcc_7 = Srcc_9;
          if ( namea_37 != namea_36 )
            break;
          namea_37 = (_DWORD *)*namea_37;
          namea_28 = namea_37;
          if ( !Srcc_9 )
            goto LABEL_230;
        }
        dsta_7 = (int)dsta_8;
        Srcc_1 = (int *)Srcc_2;
        if ( !Srcc_9 )
        {
LABEL_230:
          while ( v96 )
          {
            v96 = m_pNexta_1 != (_DWORD *)*v96 ? (_DWORD *)*v96 : 0;
            if ( !v96 )
              break;
            m_pParentCD_3 = (PhyrePClassDescriptor *)v96[11];
            if ( m_pParentCD_3 )
            {
              while ( m_pParentCD_3 != parentCD )
              {
                m_pParentCD_3 = (PhyrePClassDescriptor *)m_pParentCD_3->m_pParentCD;
                if ( !m_pParentCD_3 )
                  goto LABEL_230;
              }
              if ( v96[16] )
              {
                v106 = v96[11];
                Srcc_10 = (_DWORD *)v96[15];
                Field1334h_12 = *(_DWORD *)(v106 + 28);
                namea_36 = (_DWORD *)v96[13];
                dsta_9 = *(_DWORD *)(v106 + 140);
                namea_38 = (_DWORD *)v96[2];
                Field1334h_4 = Field1334h_12;
                namea_25 = (unsigned int)namea_36;
                Srcc_7 = Srcc_10;
                dsta_8 = (int *)dsta_9;
                namea_28 = namea_38;
                if ( !Srcc_10 )
                  goto LABEL_240;
                while ( namea_38 == namea_36 )
                {
                  namea_38 = (_DWORD *)*namea_38;
                  namea_36 = (_DWORD *)((char *)namea_36 + Field1334h_12);
                  Srcc_10 = (_DWORD *)((char *)Srcc_10 - 1);
                  namea_25 = (unsigned int)namea_36;
                  Srcc_7 = Srcc_10;
                  namea_28 = namea_38;
                  if ( !Srcc_10 )
                    goto LABEL_240;
                }
                dsta_7 = (int)dsta_8;
                Srcc_1 = (int *)Srcc_2;
                goto LABEL_201;
              }
            }
          }
          break;
        }
      }
    }
LABEL_240:
    Engine_AlignedFree(Field1334h_10);
    if ( v188 )
      Phyre_Input_EventDispatcherAndState(
        Singleton_C94F00,
        v155,
        name,
        v149,
        v160,
        dst,
        ptra,
        (char *)dstaa,
        v153,
        Srcc,
        v151);
  }
  v191 = -1;
  Phyre_Cluster_ReadFieldsFromStream(&dsta_11);
LABEL_243:
  namea_35 = 0;
  v111 = name + 28 != *(_DWORD *)(name + 28) ? *(_DWORD **)(name + 28) : 0;
  namea_1 = 0;
  v186 = v111;
  Field1334h_6 = 0;
  namea_30 = 0;
  dsta_1 = 0;
  m_pNexta = (_DWORD *)(name + 28);
  m_pNexta_1 = (_DWORD *)(name + 28);
  parentCD = &typeInfo__48;
  ManagedStrIter_Next_WithGuard_C(&namea_35);
  namea_39 = namea_30;
  if ( namea_30 )
  {
    dsta_10 = (HANDLE *)dsta_1;
    v114 = v186;
    namea_3 = (_DWORD *)namea_35;
    Srce = (const char *)Field1334h_6;
    dsta_11 = (HANDLE *)dsta_1;
    namea = (int)namea_1;
LABEL_245:
    while ( 1 )
    {
      result = Phyre_Texture_DeferredCreateFromFormat((int)namea_3 + (_DWORD)dsta_10);
      if ( result )
        break;
      if ( !namea_39 )
        goto LABEL_266;
      namea_2 = (_DWORD *)namea;
      while ( 1 )
      {
        namea_3 = (_DWORD *)((char *)namea_3 + (_DWORD)Srce);
        namea_39 = (_DWORD *)((char *)namea_39 - 1);
        if ( namea_2 != namea_3 )
          break;
        namea_2 = (_DWORD *)*namea_2;
        namea = (int)namea_2;
        if ( !namea_39 )
          goto LABEL_256;
      }
      dsta_10 = dsta_11;
      if ( !namea_39 )
      {
LABEL_256:
        while ( v114 )
        {
          v114 = m_pNexta_1 != (_DWORD *)*v114 ? (_DWORD *)*v114 : 0;
          if ( !v114 )
            break;
          m_pParentCD_4 = (PhyrePClassDescriptor *)v114[11];
          if ( m_pParentCD_4 )
          {
            while ( m_pParentCD_4 != parentCD )
            {
              m_pParentCD_4 = (PhyrePClassDescriptor *)m_pParentCD_4->m_pParentCD;
              if ( !m_pParentCD_4 )
                goto LABEL_256;
            }
            if ( v114[16] )
            {
              v119 = v114[11];
              namea_39 = (_DWORD *)v114[15];
              Srce_1 = *(const char **)(v119 + 28);
              dsta_10 = *(HANDLE **)(v119 + 140);
              namea_4 = (_DWORD *)v114[2];
              namea_3 = (_DWORD *)v114[13];
              Srce = Srce_1;
              dsta_11 = dsta_10;
              namea = (int)namea_4;
              if ( !namea_39 )
                goto LABEL_266;
              while ( namea_4 == namea_3 )
              {
                namea_4 = (_DWORD *)*namea_4;
                namea_3 = (_DWORD *)((char *)namea_3 + (_DWORD)Srce_1);
                namea = (int)namea_4;
                namea_39 = (_DWORD *)((char *)namea_39 - 1);
                if ( !namea_39 )
                  goto LABEL_266;
              }
              goto LABEL_245;
            }
          }
        }
        goto LABEL_266;
      }
    }
  }
  else
  {
LABEL_266:
    namea_35 = 0;
    v122 = m_pNexta != (_DWORD *)*m_pNexta ? (_DWORD *)*m_pNexta : 0;
    namea_1 = 0;
    v186 = v122;
    Field1334h_6 = 0;
    namea_30 = 0;
    dsta_1 = 0;
    m_pNexta_1 = m_pNexta;
    parentCD = &Size__107;
    ManagedStrIter_Next_WithGuard_F(&namea_35);
    namea_40 = namea_30;
    if ( namea_30 )
    {
      dsta_12 = (HANDLE *)dsta_1;
      v125 = v186;
      nameb_2 = (_DWORD *)namea_35;
      Srcf = (const char *)Field1334h_6;
      dsta_11 = (HANDLE *)dsta_1;
      nameb = (int)namea_1;
LABEL_268:
      while ( 1 )
      {
        result = Phyre_Shader_ParseCompiledStates((_DWORD *)((char *)nameb_2 + (_DWORD)dsta_12));
        if ( result )
          break;
        if ( !namea_40 )
          goto LABEL_285;
        nameb_1 = (_DWORD *)nameb;
        while ( 1 )
        {
          nameb_2 = (_DWORD *)((char *)nameb_2 + (_DWORD)Srcf);
          namea_40 = (_DWORD *)((char *)namea_40 - 1);
          if ( nameb_1 != nameb_2 )
            break;
          nameb_1 = (_DWORD *)*nameb_1;
          nameb = (int)nameb_1;
          if ( !namea_40 )
            goto LABEL_275;
        }
        dsta_12 = dsta_11;
        if ( !namea_40 )
        {
LABEL_275:
          while ( v125 )
          {
            v125 = m_pNexta_1 != (_DWORD *)*v125 ? (_DWORD *)*v125 : 0;
            if ( !v125 )
              break;
            m_pParentCD_5 = (PhyrePClassDescriptor *)v125[11];
            if ( m_pParentCD_5 )
            {
              while ( m_pParentCD_5 != parentCD )
              {
                m_pParentCD_5 = (PhyrePClassDescriptor *)m_pParentCD_5->m_pParentCD;
                if ( !m_pParentCD_5 )
                  goto LABEL_275;
              }
              if ( v125[16] )
              {
                v129 = v125[11];
                namea_40 = (_DWORD *)v125[15];
                Srcf_1 = *(const char **)(v129 + 28);
                dsta_12 = *(HANDLE **)(v129 + 140);
                nameb_3 = (_DWORD *)v125[2];
                nameb_2 = (_DWORD *)v125[13];
                Srcf = Srcf_1;
                dsta_11 = dsta_12;
                nameb = (int)nameb_3;
                if ( !namea_40 )
                  goto LABEL_285;
                while ( nameb_3 == nameb_2 )
                {
                  nameb_3 = (_DWORD *)*nameb_3;
                  nameb_2 = (_DWORD *)((char *)nameb_2 + (_DWORD)Srcf_1);
                  nameb = (int)nameb_3;
                  namea_40 = (_DWORD *)((char *)namea_40 - 1);
                  if ( !namea_40 )
                    goto LABEL_285;
                }
                goto LABEL_268;
              }
            }
          }
          goto LABEL_285;
        }
      }
    }
    else
    {
LABEL_285:
      m_pNexta_2 = m_pNexta;
      namea_35 = 0;
      v133 = m_pNexta != (_DWORD *)*m_pNexta ? (_DWORD *)*m_pNexta : 0;
      namea_1 = 0;
      v186 = v133;
      Field1334h_6 = 0;
      namea_30 = 0;
      dsta_1 = 0;
      m_pNexta_1 = m_pNexta;
      parentCD = &parentCD__34;
      ManagedStrIter_Next_1(&namea_35);
      namea_41 = namea_30;
      if ( namea_30 )
      {
        while ( 1 )
        {
          namea_6 = (_DWORD *)namea_35;
          namea_5 = namea_1;
LABEL_287:
          result = Phyre_Shader_CompileVertexPass((int *)((char *)namea_6 + (_DWORD)dsta_1));
          if ( result )
            break;
          if ( namea_41 )
          {
            while ( 1 )
            {
              namea_6 = (_DWORD *)((char *)namea_6 + Field1334h_6);
              namea_41 = (_DWORD *)((char *)namea_41 - 1);
              namea_35 = (unsigned int)namea_6;
              namea_30 = namea_41;
              if ( namea_5 != namea_6 )
                break;
              namea_5 = (_DWORD *)*namea_5;
              namea_1 = namea_5;
              if ( !namea_41 )
                goto LABEL_293;
            }
            if ( namea_41 )
              goto LABEL_287;
LABEL_293:
            ManagedStrIter_Next_9(&namea_35);
            namea_41 = namea_30;
            if ( namea_30 )
              continue;
          }
          m_pNexta_2 = m_pNexta;
          goto LABEL_295;
        }
      }
      else
      {
LABEL_295:
        v137 = m_pNexta_2 != (_DWORD *)*m_pNexta_2 ? (_DWORD *)*m_pNexta_2 : 0;
        namea_35 = 0;
        v186 = v137;
        namea_1 = 0;
        Field1334h_6 = 0;
        namea_30 = 0;
        dsta_1 = 0;
        m_pNexta_1 = m_pNexta_2;
        parentCD = &parentCD__31;
        ManagedStrIter_Next_WithGuard_D(&namea_35);
        namea_42 = namea_30;
        if ( namea_30 )
        {
          while ( 1 )
          {
            namea_8 = (_DWORD *)namea_35;
            namea_7 = namea_1;
LABEL_297:
            result = Phyre_Shader_CompilePixelPass((int **)((char *)namea_8 + (_DWORD)dsta_1));
            if ( result )
              break;
            if ( namea_42 )
            {
              while ( 1 )
              {
                namea_8 = (_DWORD *)((char *)namea_8 + Field1334h_6);
                namea_42 = (_DWORD *)((char *)namea_42 - 1);
                namea_35 = (unsigned int)namea_8;
                namea_30 = namea_42;
                if ( namea_7 != namea_8 )
                  break;
                namea_7 = (_DWORD *)*namea_7;
                namea_1 = namea_7;
                if ( !namea_42 )
                  goto LABEL_303;
              }
              if ( namea_42 )
                goto LABEL_297;
LABEL_303:
              ManagedStrIter_Next_7(&namea_35);
              namea_42 = namea_30;
              if ( namea_30 )
                continue;
            }
            m_pNexta_2 = m_pNexta;
            goto LABEL_305;
          }
        }
        else
        {
LABEL_305:
          v141 = m_pNexta_2 != (_DWORD *)*m_pNexta_2 ? (_DWORD *)*m_pNexta_2 : 0;
          namea_35 = 0;
          v186 = v141;
          namea_1 = 0;
          Field1334h_6 = 0;
          namea_30 = 0;
          dsta_1 = 0;
          m_pNexta_1 = m_pNexta_2;
          parentCD = &parentCD__32;
          ManagedStrIter_Next_WithGuard_E(&namea_35);
          namea_43 = namea_30;
          if ( namea_30 )
          {
            while ( 1 )
            {
              namea_10 = namea_35;
              namea_9 = namea_1;
LABEL_307:
              result = Phyre_Shader_CompileGeometryPass((int **)&dsta_1[namea_10]);
              if ( result )
                break;
              if ( namea_43 )
              {
                while ( 1 )
                {
                  namea_10 += Field1334h_6;
                  namea_43 = (_DWORD *)((char *)namea_43 - 1);
                  namea_35 = namea_10;
                  namea_30 = namea_43;
                  if ( namea_9 != (_DWORD *)namea_10 )
                    break;
                  namea_9 = (_DWORD *)*namea_9;
                  namea_1 = namea_9;
                  if ( !namea_43 )
                    goto LABEL_313;
                }
                if ( namea_43 )
                  goto LABEL_307;
LABEL_313:
                ManagedStrIter_Next_8(&namea_35);
                namea_43 = namea_30;
                if ( namea_30 )
                  continue;
              }
              m_pNexta_2 = m_pNexta;
              goto LABEL_315;
            }
          }
          else
          {
LABEL_315:
            v145 = m_pNexta_2 != (_DWORD *)*m_pNexta_2 ? (_DWORD *)*m_pNexta_2 : 0;
            namea_35 = 0;
            v186 = v145;
            namea_1 = 0;
            Field1334h_6 = 0;
            namea_30 = 0;
            dsta_1 = 0;
            m_pNexta_1 = m_pNexta_2;
            parentCD = &parentCD__30;
            PhyreManaged_StringListIterate_D(&namea_35);
LABEL_316:
            namea_44 = namea_30;
            if ( namea_30 )
            {
              namea_12 = (_DWORD *)namea_35;
              namea_11 = namea_1;
              while ( 1 )
              {
                result = Phyre_Shader_CompileComputePass((int **)((char *)namea_12 + (_DWORD)dsta_1));
                if ( result )
                  break;
                if ( !namea_44 )
                  return 0;
                while ( 1 )
                {
                  namea_12 = (_DWORD *)((char *)namea_12 + Field1334h_6);
                  namea_44 = (_DWORD *)((char *)namea_44 - 1);
                  namea_35 = (unsigned int)namea_12;
                  namea_30 = namea_44;
                  if ( namea_11 != namea_12 )
                    break;
                  namea_11 = (_DWORD *)*namea_11;
                  namea_1 = namea_11;
                  if ( !namea_44 )
                    goto LABEL_322;
                }
                if ( !namea_44 )
                {
LABEL_322:
                  ManagedStrIter_Next_14(&namea_35);
                  goto LABEL_316;
                }
              }
            }
            else
            {
              return 0;
            }
          }
        }
      }
    }
  }
  return result;
}
