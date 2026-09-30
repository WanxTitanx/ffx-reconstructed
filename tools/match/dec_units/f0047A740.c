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

extern _DWORD g_PhyreUnkVar_1020304;
extern _DWORD AlignedLinkedListBlock_FreeAll();
extern _DWORD AlignedLinkedListBlock_FreeAll_B();
extern _DWORD AlignedLinkedListBlock_Init();
extern _DWORD DEAD_Phyre_ClassDescriptor_FindByName();
extern _DWORD DEAD_Phyre_TypeMap_ResolveValue();
extern _DWORD Engine_AlignedAllocAlign();
extern _DWORD Engine_AlignedFree();
extern _DWORD PClassDataMember_GetField13();
extern _DWORD PTree_Node_InitSelfRef();
extern _DWORD Phyre_AlignedAllocList_Alloc();
extern _DWORD Phyre_BSTree_InsertByNameAlt_SList();
extern _DWORD Phyre_BSTree_InsertByNameStrAlt_SList();
extern _DWORD Phyre_BSTree_InsertByName_SList();
extern _DWORD Phyre_BSTree_InsertByType();
extern _DWORD Phyre_BSTree_SearchByKey();
extern _DWORD Phyre_BSTree_SearchByNameStr();
extern _DWORD Phyre_BSTree_SearchByNameStrB();
extern _DWORD Phyre_BSTree_SearchByNameStrC();
extern _DWORD Phyre_BSTree_SearchByNameStrD();
extern _DWORD Phyre_BSTree_SearchByTypeStr();
extern _DWORD Phyre_NameMap_FindByNameBST();
extern _DWORD Phyre_PClassDescriptor_GetMemberCount();
extern _DWORD Phyre_PClassDescriptor_IsRegistered();
extern _DWORD Phyre_PClass_CopyMembers_PostProcess();
extern _DWORD Phyre_Stream_Printf();
extern _DWORD Phyre_Tree_GetPredecessor();
extern _DWORD Phyre_Tree_GetPredecessor_COMDAT();
extern _DWORD Phyre_Tree_RemoveNodeEx_COMDAT();
extern _DWORD Phyre_Tree_RemoveNodeWithRotation();
extern _DWORD Phyre_Tree_RemoveNode_COMDAT();
extern _DWORD Phyre_TypeMap_ResolveValueByFirstField();
extern _DWORD Phyre_Type_RegisterOrFindType();
extern _DWORD SList_Pop();
extern _DWORD getIDForType();
// Function: DEAD_PhyreTypeFactory_GetIDForType
// Address: 0x47A740
// Size: 0xFB0
// Phyre: TypeFactory get ID for type — maps a Phyre type name to its runtime type ID
// // DEAD-PC: 0 xrefs + 0 dataptrs; ?
// // DEAD-CLASS: phyre-middleware
// DEAD-CONFIRMED [dead-audit 2026-09-17]: 0 code/data xrefs; VA+RVA byte-scan: no table ref
int *__cdecl DEAD_PhyreTypeFactory_GetIDForType(int a1)
{
  _DWORD *Predecessor_COMDAT_5; // edi
  int *p_i_4; // ebx
  _DWORD *k_2; // ecx
  int *v4; // ecx
  int *p_i_5; // eax
  int p_i_6; // esi
  char *p_i_2; // esi
  int i_15; // eax
  int *Predecessor; // eax
  int *Predecessor_1; // edi
  int i_2; // edi
  _DWORD *v12; // eax
  _DWORD *v13; // eax
  unsigned int v14; // kr04_4
  int *Size_25; // ecx
  _DWORD *v16; // esi
  const char *Field; // esi
  _DWORD *v18; // eax
  const char *i_3; // esi
  _DWORD *v20; // eax
  int n4_1; // eax
  _DWORD *v22; // ebx
  int p_i_1; // esi
  const char *i_4; // edi
  _DWORD *v25; // eax
  int *Predecessor_COMDAT_6; // edi
  _DWORD *v27; // eax
  const char *i_5; // esi
  int v29; // eax
  int *v30; // eax
  int *v31; // edi
  int *v32; // eax
  int n4; // eax
  int MemberCount; // eax
  int v35; // esi
  _DWORD *v36; // eax
  int *v37; // eax
  int v38; // eax
  const char *i_6; // esi
  int v40; // ebx
  int v41; // edi
  int *p_i_7; // eax
  char *v43; // ebx
  int *ptr_1; // edx
  void *v45; // edx
  int i_7; // edi
  int v47; // esi
  int *v48; // edi
  int *v49; // eax
  int *v50; // ecx
  int *v51; // ecx
  size_t Size_1; // eax
  char *v53; // ebx
  _DWORD *Predecessor_COMDAT_7; // eax
  _DWORD *Predecessor_COMDAT_1; // esi
  _DWORD *Predecessor_COMDAT; // edi
  int v57; // edx
  const char *v58; // ecx
  unsigned int v59; // kr10_4
  _DWORD *Predecessor_COMDAT_4; // ecx
  _DWORD **Predecessor_COMDAT_2; // eax
  int *Size_7; // ecx
  int *Size_26; // eax
  int *Size_5; // edi
  int *Size_27; // eax
  int *Size_6; // eax
  int *Size_8; // esi
  int *Size_9; // ebx
  char *v69; // edi
  int v70; // edx
  const char *v71; // ecx
  unsigned int v72; // kr14_4
  int *Size_12; // ecx
  int *Size_10; // eax
  void **v75; // eax
  int v76; // ebx
  void ***v77; // esi
  char *v78; // edi
  const char *v79; // edx
  int *v80; // ebx
  int v81; // edx
  int *Size_16; // esi
  size_t Size_2; // eax
  int *Size_14; // ebx
  int ptr_2; // edx
  size_t Size_17; // eax
  int ptr_3; // edx
  const char *i_8; // ecx
  unsigned int ptr_4; // eax
  unsigned int i_9; // edx
  _DWORD *v91; // eax
  int v92; // esi
  unsigned int n0xFFFF; // edi
  _DWORD *v94; // ebx
  char v95; // al
  unsigned int v96; // ecx
  _DWORD *v97; // ecx
  _DWORD *v98; // eax
  _DWORD *k; // ecx
  unsigned int i_10; // eax
  _DWORD *v101; // ecx
  int v102; // eax
  int v103; // ecx
  int v104; // eax
  unsigned int n0xFF; // edi
  int v106; // ecx
  unsigned int n0xF; // edi
  int v108; // eax
  int v109; // ecx
  unsigned int n3; // edi
  int v111; // eax
  int v112; // ecx
  unsigned int v113; // edi
  int v114; // eax
  _DWORD *v115; // ecx
  int v116; // edi
  _DWORD *Size_19; // eax
  _DWORD *Size_20; // edi
  int v119; // eax
  int v120; // eax
  int v121; // eax
  int v122; // eax
  _DWORD *v123; // esi
  unsigned int v124; // esi
  int v125; // eax
  _DWORD *v126; // eax
  int v127; // eax
  int v128; // eax
  int v129; // eax
  char *i_12; // edi
  _DWORD *v131; // ebx
  int v132; // eax
  int v133; // eax
  int v134; // edi
  _DWORD *v135; // eax
  int *v136; // eax
  _DWORD *v137; // eax
  _DWORD *v138; // eax
  _DWORD *Size_3; // edx
  int v140; // eax
  int n4_2; // edi
  int v142; // eax
  bool v143; // al
  int Field13; // eax
  _DWORD *v145; // ebx
  int *v146; // ebx
  int v147; // edi
  int *v148; // edx
  int v149; // eax
  int v150; // edi
  _DWORD *v151; // ecx
  bool v152; // bl
  unsigned int v153; // eax
  int v154; // eax
  _DWORD *v155; // ecx
  _DWORD *j_1; // esi
  PhyrePClassDescriptor *i_14; // edi
  int v158; // esi
  char v159; // dl
  int Size_21; // ebx
  unsigned int m; // ebx
  _DWORD *Size_24; // edi
  _DWORD *Size_23; // esi
  _DWORD *v164; // eax
  int *v165; // eax
  _DWORD *v166; // eax
  int v167; // edi
  unsigned int n0xFFFF_1; // edx
  unsigned int v169; // ecx
  unsigned int v170; // eax
  unsigned int v171; // ecx
  unsigned int v172; // edi
  unsigned int v173; // ecx
  int v174; // eax
  unsigned int n0xFF_1; // edx
  _DWORD *v177; // [esp+20h] [ebp-DCh]
  int v178; // [esp+24h] [ebp-D8h]
  size_t Size_15; // [esp+28h] [ebp-D4h]
  _BYTE *v180; // [esp+30h] [ebp-CCh]
  int v181; // [esp+34h] [ebp-C8h]
  char *v182; // [esp+38h] [ebp-C4h]
  _DWORD *j; // [esp+3Ch] [ebp-C0h]
  void **v184[3]; // [esp+40h] [ebp-BCh] BYREF
  void ***v185; // [esp+4Ch] [ebp-B0h]
  void ***v186; // [esp+50h] [ebp-ACh]
  void ***v187; // [esp+54h] [ebp-A8h]
  int v188[7]; // [esp+58h] [ebp-A4h] BYREF
  size_t Size_18; // [esp+74h] [ebp-88h] BYREF
  int v190; // [esp+78h] [ebp-84h] BYREF
  _DWORD *k_1; // [esp+7Ch] [ebp-80h]
  int i_13; // [esp+80h] [ebp-7Ch] BYREF
  void *v193; // [esp+84h] [ebp-78h]
  _DWORD *v194; // [esp+88h] [ebp-74h]
  char *i_11; // [esp+8Ch] [ebp-70h] BYREF
  int ptr; // [esp+90h] [ebp-6Ch]
  _DWORD *v197; // [esp+94h] [ebp-68h]
  int ptr_5; // [esp+98h] [ebp-64h]
  size_t Size_4; // [esp+9Ch] [ebp-60h]
  int v200; // [esp+A0h] [ebp-5Ch]
  void *p_i_3; // [esp+A4h] [ebp-58h]
  int i; // [esp+A8h] [ebp-54h]
  char v203; // [esp+AFh] [ebp-4Dh]
  int *v204; // [esp+B0h] [ebp-4Ch]
  char **p_i; // [esp+B4h] [ebp-48h] BYREF
  int *Size_22; // [esp+B8h] [ebp-44h]
  _DWORD *Predecessor_COMDAT_3; // [esp+BCh] [ebp-40h]
  int *Size_11; // [esp+C0h] [ebp-3Ch]
  _DWORD *v209; // [esp+C4h] [ebp-38h]
  size_t Size; // [esp+C8h] [ebp-34h]
  void *v211; // [esp+CCh] [ebp-30h]
  int Size_13; // [esp+D0h] [ebp-2Ch]
  const char *i_1; // [esp+D4h] [ebp-28h] BYREF
  char v214; // [esp+DBh] [ebp-21h]
  _DWORD v215[3]; // [esp+DCh] [ebp-20h] BYREF
  char v216; // [esp+E8h] [ebp-14h]
  int n5; // [esp+F8h] [ebp-4h]

  Predecessor_COMDAT_5 = *(_DWORD **)a1;
  p_i_4 = *(int **)(a1 + 12);
  v193 = *(void **)(a1 + 8);
  v211 = *(void **)(a1 + 16);
  v197 = *(_DWORD **)(a1 + 20);
  k_2 = *(_DWORD **)(a1 + 24);
  v203 = *(_BYTE *)(a1 + 28);
  v194 = Predecessor_COMDAT_5 + 28;
  Size_11 = Predecessor_COMDAT_5 + 14;
  Predecessor_COMDAT_3 = Predecessor_COMDAT_5;
  p_i_3 = p_i_4;
  k_1 = k_2;
  v184[0] = (void **)v184;
  v184[1] = (void **)v184;
  v184[2] = (void **)v184;
  v187 = v184;
  v186 = v184;
  v185 = v184;
  n5 = 0;
  AlignedLinkedListBlock_Init(v188, 20, 8, 4, (int)"PMapPair");
  n5 = 1;
  Size_13 = 0;
  Size_22 = 0;
  Size = 0;
  v204 = 0;
  v4 = p_i_4 + 3;
  while ( 1 )
  {
    p_i_5 = (int *)*v4;
    if ( (int *)*v4 == p_i_4 || !p_i_5 )
      break;
    if ( p_i_5 == p_i_4 )
    {
      p_i_6 = *v4;
    }
    else
    {
      do
      {
        p_i_6 = (int)p_i_5;
        p_i_5 = (int *)*p_i_5;
      }
      while ( p_i_5 != p_i_4 );
    }
    if ( (int *)p_i_6 != p_i_4 )
      Phyre_Tree_GetPredecessor((_DWORD **)p_i_4, p_i_6);
    p_i_2 = *(char **)(p_i_6 + 12);
    i_15 = *(_DWORD *)p_i_2;
    i_1 = p_i_2;
    i = (*(int (__fastcall **)(char *))(i_15 + 4))(p_i_2);
    Predecessor = Phyre_BSTree_SearchByNameStrD(p_i_4, &i_1);
    Predecessor_1 = Predecessor;
    if ( Predecessor )
    {
      Phyre_Tree_RemoveNodeEx_COMDAT(p_i_4, Predecessor);
      SList_Pop(p_i_4 + 6, Predecessor_1);
    }
    i_2 = i;
    if ( i )
    {
      if ( !(unsigned char)Phyre_PClassDescriptor_IsRegistered((PhyrePClassDescriptor *)i) )
      {
        v204 = 0;
        goto LABEL_262;
      }
      p_i = (char **)i_2;
      v13 = Phyre_BSTree_SearchByNameStr(Size_11, (int *)&p_i);
      if ( !v13 || v13 == (_DWORD *)-16 )
      {
        v14 = strlen(*(const char **)(i_2 + 24));
        Size_25 = Size_11;
        Size_11[12] += v14 + 1;
        v16 = Size_25 + 13;
        Phyre_BSTree_InsertByName_SList(Size_25, (const char ***)&p_i, Size_25 + 13);
        ++*v16;
      }
      if ( *(_DWORD *)(i_2 + 64) )
      {
        Field = (const char *)Phyre_TypeMap_ResolveValueByFirstField(v193, *(_DWORD *)(i_2 + 64));
        i_1 = Field;
        v18 = Phyre_BSTree_SearchByNameStr(Size_11, (int *)&i_1);
        if ( !v18 || v18 == (_DWORD *)-16 )
        {
          i_1 = Field;
          Phyre_BSTree_InsertByNameStrAlt_SList(p_i_4, &i_1);
        }
      }
      i_3 = (const char *)DEAD_Phyre_TypeMap_ResolveValue(v193, i_2);
      i_1 = i_3;
      v20 = Phyre_BSTree_SearchByNameStr(Size_11, (int *)&i_1);
      if ( !v20 || v20 == (_DWORD *)-16 )
      {
        i_1 = i_3;
        Phyre_BSTree_InsertByNameStrAlt_SList(p_i_4, &i_1);
      }
      n4_1 = *(_DWORD *)(i_2 + 68);
      ptr_5 = i_2 + 68;
      if ( n4_1 != i_2 + 68 && n4_1 )
      {
        v22 = (_DWORD *)(n4_1 - 4);
        if ( n4_1 != 4 )
        {
          do
          {
            p_i_1 = v22[6];
            i_4 = (const char *)(*(int (__fastcall **)(int))(*(_DWORD *)p_i_1 + 4))(p_i_1);
            i_1 = i_4;
            if ( i_4 )
            {
              v25 = Phyre_BSTree_SearchByNameStr(Size_11, (int *)&i_1);
              if ( !v25 || v25 == (_DWORD *)-16 )
              {
                i_1 = i_4;
                Phyre_BSTree_InsertByNameStrAlt_SList((int *)p_i_3, &i_1);
              }
            }
            else
            {
              Predecessor_COMDAT_6 = Predecessor_COMDAT_3;
              p_i = (char **)p_i_1;
              v27 = Phyre_BSTree_SearchByNameStrB(Predecessor_COMDAT_3, (const char ***)&p_i);
              if ( !v27 || v27 == (_DWORD *)-16 )
              {
                Predecessor_COMDAT_6[12] += strlen(*(const char **)(p_i_1 + 24)) + 1;
                Phyre_BSTree_InsertByNameAlt_SList(
                  Predecessor_COMDAT_6,
                  (const char ***)&p_i,
                  Predecessor_COMDAT_6 + 13);
                ++Predecessor_COMDAT_6[13];
              }
            }
            i_5 = (const char *)v22[4];
            i_1 = i_5;
            v29 = Phyre_BSTree_SearchByTypeStr(v184, &i_1);
            if ( !v29 || v29 == -16 )
            {
              v30 = (int *)v188[0];
              v31 = (int *)v188[0];
              if ( v188[0]
                || (Phyre_AlignedAllocList_Alloc(v188, v188[2]), v30 = (int *)v188[0], (v31 = (int *)v188[0]) != 0) )
              {
                v188[0] = *v30;
                v32 = v204;
                *v31 = (int)v31;
                v31[1] = (int)v31;
                v31[2] = (int)v31;
                v31[3] = (int)i_5;
                v31[4] = (int)v32;
                if ( Phyre_BSTree_InsertByType(v184, (int)v31) )
                  SList_Pop(v188, v31);
                else
                  Phyre_Tree_RemoveNode_COMDAT(v184, (int)v31);
              }
              v204 = (int *)((char *)v204 + strlen(i_5) + 1);
            }
            n4 = v22[1];
            ++Size_13;
            if ( n4 == ptr_5 )
              break;
            if ( !n4 )
              break;
            v22 = (_DWORD *)(n4 - 4);
          }
          while ( n4 != 4 );
          i_2 = i;
        }
        p_i_4 = (int *)p_i_3;
      }
      v214 = *(_BYTE *)(i_2 + 144) & 1;
      MemberCount = Phyre_PClassDescriptor_GetMemberCount((PhyrePClassDescriptor *)i_2);
      v4 = p_i_4 + 3;
      if ( MemberCount )
      {
        if ( v203 || (v4 = p_i_4 + 3, v214) )
        {
          v35 = *(_DWORD *)(i_2 + 28);
          if ( k_1 )
          {
            if ( v214 )
            {
              i_1 = (const char *)i_2;
              v36 = Phyre_BSTree_SearchByKey(k_1, &i_1);
              if ( v36 )
              {
                v37 = v36 + 4;
                if ( v37 )
                {
                  v38 = *v37;
                  if ( v38 )
                    v35 = *(_DWORD *)(v38 + 28);
                }
              }
            }
          }
          Size += v35;
          Size_22 = (int *)((char *)Size_22 + 1);
          v4 = p_i_4 + 3;
        }
      }
      Predecessor_COMDAT_5 = Predecessor_COMDAT_3;
    }
    else
    {
      Predecessor_COMDAT_5 = Predecessor_COMDAT_3;
      p_i = (char **)p_i_2;
      v12 = Phyre_BSTree_SearchByNameStrB(Predecessor_COMDAT_3, (const char ***)&p_i);
      if ( !v12 || (v4 = p_i_4 + 3, v12 == (_DWORD *)-16) )
      {
        Predecessor_COMDAT_5[12] += strlen(*((const char **)p_i_2 + 6)) + 1;
        Phyre_BSTree_InsertByNameAlt_SList(Predecessor_COMDAT_5, (const char ***)&p_i, Predecessor_COMDAT_5 + 13);
        ++Predecessor_COMDAT_5[13];
        v4 = p_i_4 + 3;
      }
    }
  }
  i_6 = (const char *)Predecessor_COMDAT_5[13];
  v40 = Predecessor_COMDAT_5[26];
  i_1 = i_6;
  v41 = Predecessor_COMDAT_5[27] - 1;
  p_i_7 = 0;
  v43 = (char *)v204 + Predecessor_COMDAT_3[12] + v40;
  v200 = v41;
  p_i_3 = 0;
  if ( v41 )
  {
    p_i_7 = Engine_AlignedAllocAlign(4 * v41, 4);
    p_i_3 = p_i_7;
  }
  v181 = p_i_7 != 0 ? v41 : 0;
  ptr_1 = 0;
  LOBYTE(n5) = 2;
  ptr = 0;
  if ( v41 )
  {
    ptr_1 = Engine_AlignedAllocAlign(4 * v41, 4);
    ptr = (int)ptr_1;
    if ( ptr_1 )
    {
      memset(ptr_1, 0, 4 * v41);
      v41 = v200;
    }
  }
  v178 = ptr_1 != 0 ? v41 : 0;
  LOBYTE(n5) = 3;
  p_i = (char **)p_i_3;
  if ( v41 && (!p_i_3 || !ptr_1) )
    goto LABEL_83;
  v45 = v211;
  i_7 = 4 * (_DWORD)&i_6[8 * v41 + 6 * Size_13 + v41] + 32;
  i = i_7;
  v47 = (int)&v43[i_7 + Size];
  if ( v211 )
  {
    if ( v47 != *(_DWORD *)v211 )
    {
      v48 = 0;
      if ( !v47 || (v49 = Engine_AlignedAllocAlign(v47, 4), v45 = v211, (v48 = v49) != 0) )
      {
        v50 = (int *)*((_DWORD *)v45 + 1);
        if ( v50 != v48 && *(int *)v45 >= 0 && v50 )
        {
          Engine_AlignedFree(*((void **)v45 + 1));
          v45 = v211;
        }
        *((_DWORD *)v45 + 1) = v48;
        *(_DWORD *)v45 = v47;
      }
      i_7 = i;
    }
    v51 = (int *)*((_DWORD *)v45 + 1);
    v204 = v51;
  }
  else
  {
    v51 = Engine_AlignedAllocAlign((int)&v43[i_7 + Size], 4);
    v204 = v51;
  }
  if ( !v51 )
  {
LABEL_83:
    v204 = 0;
    goto LABEL_257;
  }
  v51[2] = (int)i_1;
  v51[3] = v200;
  v51[4] = Size_13;
  v51[6] = (int)Size_22;
  Size_1 = Size;
  v51[5] = (int)v43;
  v51[1] = v47;
  v53 = (char *)v51 + i_7;
  *v51 = (int)&g_PhyreUnkVar_1020304;
  v51[7] = Size_1;
  v211 = (char *)v51 + i_7;
  Predecessor_COMDAT_7 = (_DWORD *)Predecessor_COMDAT_3[3];
  Predecessor_COMDAT_1 = Predecessor_COMDAT_3 + 3;
  Size_22 = (int *)((char *)v51 + i_7);
  if ( Predecessor_COMDAT_7 == Predecessor_COMDAT_3 || !Predecessor_COMDAT_7 )
  {
    Predecessor_COMDAT_1 = Predecessor_COMDAT_7;
  }
  else
  {
    for ( ; Predecessor_COMDAT_7 != Predecessor_COMDAT_3; Predecessor_COMDAT_7 = (_DWORD *)*Predecessor_COMDAT_7 )
      Predecessor_COMDAT_1 = Predecessor_COMDAT_7;
  }
  if ( Predecessor_COMDAT_1 != Predecessor_COMDAT_3 )
  {
    Predecessor_COMDAT = Phyre_Tree_GetPredecessor_COMDAT((_DWORD **)Predecessor_COMDAT_3, (int)Predecessor_COMDAT_1);
    if ( Predecessor_COMDAT_1 != Predecessor_COMDAT_3 )
    {
      do
      {
        v57 = Predecessor_COMDAT_1[3];
        v204[Predecessor_COMDAT_1[4] + 8] = v53 - (char *)Size_22;
        v58 = *(const char **)(v57 + 24);
        v59 = strlen(v58);
        memcpy(v53, v58, v59 + 1);
        Predecessor_COMDAT_4 = Predecessor_COMDAT_3;
        v53 += v59 + 1;
        Predecessor_COMDAT_1 = Predecessor_COMDAT;
        if ( Predecessor_COMDAT != Predecessor_COMDAT_3 )
        {
          Predecessor_COMDAT_2 = Phyre_Tree_GetPredecessor_COMDAT(
                                   (_DWORD **)Predecessor_COMDAT_3,
                                   (int)Predecessor_COMDAT);
          Predecessor_COMDAT_4 = Predecessor_COMDAT_3;
          Predecessor_COMDAT = Predecessor_COMDAT_2;
        }
      }
      while ( Predecessor_COMDAT_1 != Predecessor_COMDAT_4 );
      v211 = v53;
    }
  }
  Size_7 = Size_11;
  Size_26 = (int *)Size_11[3];
  Size_5 = Size_11 + 3;
  Size_13 = (int)(Size_11 + 3);
  if ( Size_26 == Size_11 || !Size_26 )
  {
    Size_5 = Size_26;
    Size_13 = (int)Size_26;
  }
  else
  {
    for ( ; Size_26 != Size_11; Size_13 = (int)Size_5 )
    {
      Size_5 = Size_26;
      Size_26 = (int *)*Size_26;
    }
  }
  if ( Size_5 != Size_11 )
  {
    Size_27 = (int *)Phyre_Tree_GetPredecessor_COMDAT((_DWORD **)Size_11, (int)Size_5);
    Size_7 = Size_11;
    Size_5 = Size_27;
    Size_13 = (int)Size_27;
  }
  Size_6 = Size_5;
  Size_4 = (size_t)Size_5;
  if ( Size_5 != Size_7 )
  {
    Size_6 = (int *)Phyre_Tree_GetPredecessor_COMDAT((_DWORD **)Size_7, (int)Size_5);
    Size_7 = Size_11;
    Size_4 = (size_t)Size_6;
  }
  Size_8 = Size_5;
  Size_9 = Size_6;
  if ( Size_5 != Size_7 )
  {
    v69 = (char *)v211;
    do
    {
      v70 = Size_8[3];
      *((_DWORD *)p_i_3 + Size_8[4] - 1) = v69 - (char *)Size_22;
      v71 = *(const char **)(v70 + 24);
      v72 = strlen(v71);
      memcpy(v69, v71, v72 + 1);
      Size_12 = Size_11;
      v69 += v72 + 1;
      Size_8 = Size_9;
      if ( Size_9 != Size_11 )
      {
        Size_10 = (int *)Phyre_Tree_GetPredecessor_COMDAT((_DWORD **)Size_11, (int)Size_9);
        Size_12 = Size_11;
        Size_9 = Size_10;
      }
    }
    while ( Size_8 != Size_12 );
    v211 = v69;
    Size_5 = (int *)Size_13;
  }
  v182 = (char *)((_BYTE *)v211 - (_BYTE *)Size_22);
  v75 = (void **)v185;
  if ( v185 == v184 || !v185 )
  {
    v76 = (int)v185;
  }
  else
  {
    do
    {
      v76 = (int)v75;
      v75 = (void **)*v75;
    }
    while ( v75 != (void **)v184 );
  }
  if ( (void ***)v76 != v184 )
  {
    v77 = (void ***)Phyre_Tree_GetPredecessor_COMDAT(v184, v76);
    v78 = (char *)v211;
    do
    {
      v79 = *(const char **)(v76 + 12);
      i_1 = v79 + 1;
      strcpy(&v78[*(_DWORD *)(v76 + 16)], v79);
      v76 = (int)v77;
      if ( v77 != v184 )
        v77 = (void ***)Phyre_Tree_GetPredecessor_COMDAT(v184, (int)v77);
    }
    while ( (void ***)v76 != v184 );
    Size_5 = (int *)Size_13;
  }
  v80 = v204;
  v211 = (char *)&v204[9 * v204[3] + 8 + 6 * v204[4] + v204[2]] + v204[5];
  v180 = v211;
  memset(v211, 182, Size);
  v81 = v80[2];
  Size_16 = &v80[v81 + 8];
  Size_2 = (size_t)&v80[8 * v80[3] + 8 + v81 + v80[3]];
  Size_14 = Size_11;
  Size_15 = Size_2;
  Size_22 = Size_16;
  Size = Size_2;
  Size_13 = (int)Size_16;
  if ( Size_5 != Size_11 )
  {
    ptr_2 = ptr;
    do
    {
      *(_DWORD *)(ptr_2 + 4 * Size_5[4] - 4) = Size_5[3];
      Size_17 = Size_4;
      Size_5 = (int *)Size_4;
      if ( (int *)Size_4 != Size_14 )
      {
        Size_17 = (size_t)Phyre_Tree_GetPredecessor_COMDAT((_DWORD **)Size_14, Size_4);
        ptr_2 = ptr;
      }
      Size_4 = Size_17;
    }
    while ( Size_5 != Size_14 );
  }
  ptr_3 = ptr;
  i_8 = (const char *)(ptr + 4 * v200);
  ptr_4 = ptr;
  i_1 = i_8;
  ptr_5 = ptr;
  if ( ptr >= (unsigned int)i_8 )
    goto LABEL_237;
  do
  {
    i_9 = *(_DWORD *)ptr_4;
    v91 = *(_DWORD **)(*(_DWORD *)ptr_4 + 68);
    v92 = 0;
    i = i_9;
    for ( j = (_DWORD *)(i_9 + 68); v91 != (_DWORD *)(i_9 + 68); ++v92 )
      v91 = (_DWORD *)*v91;
    n0xFFFF = *(_DWORD *)(i_9 + 32);
    Size_18 = *(_DWORD *)(i_9 + 28);
    Size_4 = Size_18;
    v94 = 0;
    v95 = *(_BYTE *)(i_9 + 144) & 1;
    v214 = v95;
    v209 = 0;
    if ( !v197 )
      goto LABEL_142;
    if ( !v197[11] )
    {
      v96 = *(_DWORD *)(i_9 + 124);
      if ( v96 < (v197[12] & 0x7FFFFFFFu) )
      {
        v97 = *(_DWORD **)(v197[13] + 4 * v96);
LABEL_139:
        v209 = v97;
        goto LABEL_140;
      }
    }
    v97 = (_DWORD *)v197[7];
    v98 = &v97[8 * v197[6]];
    v209 = v97;
    if ( v97 >= v98 )
    {
LABEL_138:
      v97 = 0;
      goto LABEL_139;
    }
    while ( v97[2] != i_9 )
    {
      v97 += 8;
      v209 = v97;
      if ( v97 >= v98 )
        goto LABEL_138;
    }
LABEL_140:
    if ( !v97 )
    {
      v94 = v209;
      v95 = v214;
LABEL_142:
      if ( k_1 && v95 )
      {
        for ( k = (_DWORD *)k_1[3]; ; k = (_DWORD *)k[1] )
        {
          while ( 1 )
          {
            if ( k == k_1 )
              goto LABEL_154;
            i_10 = k[3];
            if ( i_10 <= i_9 )
              break;
            i_9 = i;
            k = (_DWORD *)*k;
          }
          if ( i_10 >= i_9 )
            break;
          i_9 = i;
        }
        v101 = k + 4;
        if ( !v101 )
        {
LABEL_154:
          v94 = 0;
          v209 = 0;
          goto LABEL_156;
        }
        v97 = (_DWORD *)v101[2];
        v209 = v97;
        if ( v97 )
          goto LABEL_152;
        v94 = 0;
      }
LABEL_156:
      v200 = 0;
      goto LABEL_157;
    }
LABEL_152:
    v102 = v97[1];
    v94 = v209;
    v200 = v102;
    if ( v102 )
    {
      v103 = *(_DWORD *)(v102 + 4) >> 28;
      Size_4 = *(_DWORD *)(v102 + 4) & 0xFFFFFFF;
      n0xFFFF = 1 << v103;
    }
LABEL_157:
    *(_DWORD *)Size_13 = 0;
    v104 = 16 * (n0xFFFF > 0xFFFF);
    n0xFF = n0xFFFF >> (16 * (n0xFFFF > 0xFFFF));
    v106 = 8 * (n0xFF > 0xFF);
    n0xF = n0xFF >> v106;
    v108 = v106 | v104;
    v109 = 4 * (n0xF > 0xF);
    n3 = n0xF >> v109;
    v111 = v109 | v108;
    v112 = 2 * (n3 > 3);
    v113 = n3 >> v112;
    v114 = v112 | v111;
    v115 = (_DWORD *)v200;
    v116 = v114 | (v113 >> 1);
    Size_19 = (_DWORD *)Size_13;
    *(_DWORD *)(Size_13 + 4) = Size_4 | (v116 << 28);
    Size_20 = Size_19;
    Size_19[3] = v92;
    if ( v115 )
      v119 = v115[4];
    else
      v119 = *(_DWORD *)(i_9 + 132);
    Size_20[4] = v119;
    if ( v115 )
      v120 = v115[5];
    else
      v120 = *(_DWORD *)(i_9 + 136);
    Size_20[5] = v120;
    if ( v115 )
      v121 = v115[6];
    else
      v121 = *(_DWORD *)(i_9 + 140);
    Size_20[6] = v121;
    if ( v115 )
      v122 = v115[7];
    else
      v122 = *(_DWORD *)(i_9 + 144) & 0x7FFFFFF;
    Size_20[7] = v122;
    Size_20[2] = *p_i;
    v123 = (_DWORD *)*j;
    if ( (_DWORD *)*j == j )
      goto LABEL_226;
    if ( !v123 )
      goto LABEL_226;
    v124 = (unsigned int)(v123 - 1);
    if ( !v124 )
      goto LABEL_226;
    do
    {
      i_11 = *(char **)(v124 + 16);
      v125 = Phyre_BSTree_SearchByTypeStr(v184, (const char **)&i_11);
      if ( v125 )
        v126 = (_DWORD *)(v125 + 16);
      else
        v126 = 0;
      *(_DWORD *)Size = &v182[*v126];
      v127 = (*(int (__fastcall **)(unsigned int))(*(_DWORD *)v124 + 4))(v124);
      if ( v127 )
        v128 = *(_DWORD *)(v127 + 48);
      else
        v128 = 0;
      v177 = v128 == 1 ? (_DWORD *)v124 : 0;
      v129 = **(_DWORD **)(v124 + 24);
      i_13 = *(_DWORD *)(v124 + 24);
      i_12 = (char *)(*(int (**)(void))(v129 + 4))();
      i_11 = i_12;
      v131 = 0;
      if ( v209
        && (v132 = DEAD_Phyre_ClassDescriptor_FindByName(v209, *(const char **)(v124 + 16))) != 0
        && (v131 = *(_DWORD **)(v132 + 4)) != 0 )
      {
        v133 = v131[4];
      }
      else
      {
        v133 = *(_DWORD *)(v124 + 20);
      }
      *(_DWORD *)(Size + 16) = v133 & 0xFFFFFFFE;
      if ( !i_12 )
      {
        i_12 = (char *)i_13;
        i_11 = (char *)i_13;
      }
      v190 = (*(int (__fastcall **)(char *))(*(_DWORD *)i_12 + 4))(i_12);
      i_13 = (int)i_11;
      v134 = -1;
      v135 = Phyre_BSTree_SearchByNameStrC(Predecessor_COMDAT_3, &i_13);
      if ( v135 )
      {
        v136 = v135 + 4;
        if ( v136 )
        {
          v134 = *v136;
          goto LABEL_192;
        }
      }
      if ( v190 )
      {
        v137 = Phyre_NameMap_FindByNameBST(Size_11, &v190);
        if ( v137 )
        {
          v138 = v137 + 4;
          if ( v138 )
          {
            v134 = Predecessor_COMDAT_3[13] + *v138;
LABEL_192:
            if ( v134 != -1 )
              goto LABEL_194;
          }
        }
      }
      Phyre_Stream_Printf(1, "getIDForType() can't find ID for type %s\n", *((const char **)i_11 + 6));
LABEL_194:
      Size_3 = (_DWORD *)Size;
      *(_DWORD *)(Size + 4) = v134;
      if ( v131 )
        v140 = v131[2];
      else
        v140 = *(_DWORD *)(v124 + 36);
      Size_3[2] = v140;
      if ( v131 )
      {
        n4_2 = v131[3];
      }
      else
      {
        n4_2 = *(_DWORD *)(*(_DWORD *)(v124 + 24) + 28);
        v142 = (*(int (__fastcall **)(unsigned int))(*(_DWORD *)v124 + 4))(v124);
        v143 = v142 && *(_DWORD *)(v142 + 48) == 2;
        Size_3 = (_DWORD *)Size;
        if ( (*(_DWORD *)(v124 + 20) & 2) != 0 || v143 && (*(_DWORD *)(v124 + 20) & 0x40) == 0 )
          n4_2 = 4;
      }
      Size_3[3] = n4_2;
      if ( v131 )
      {
        Field13 = v131[5];
      }
      else if ( v177 )
      {
        Field13 = PClassDataMember_GetField13(v177);
        Size_3 = (_DWORD *)Size;
      }
      else
      {
        Field13 = 0;
      }
      v145 = v194;
      Size_3[5] = Field13;
      v146 = v145 + 6;
      v147 = (int)((int)Size_3 + -4 - Size_15 + 4) / 24;
      v148 = (int *)*v146;
      if ( *v146 || (Phyre_AlignedAllocList_Alloc(v146, v146[2]), (v148 = (int *)*v146) != 0) )
      {
        *v146 = *v148;
        v149 = (int)v194;
        v148[4] = v147;
        v150 = v149 + 12;
        v148[3] = v124;
        v148[2] = (int)v148 - ((unsigned char)v148 & 1) + 1;
        *v148 = v149;
        v148[1] = v149;
        v151 = *(_DWORD **)(v149 + 12);
        v152 = 0;
        if ( v151 != (_DWORD *)v149 )
        {
          do
          {
            v153 = v151[3];
            v150 = (int)v151;
            if ( v153 <= v124 )
            {
              if ( v153 >= v124 )
              {
                SList_Pop(v194 + 6, v148);
                goto LABEL_219;
              }
              v154 = -1;
            }
            else
            {
              v154 = 1;
            }
            v152 = v154 < 0;
            v151 = (_DWORD *)v151[v154 < 0];
          }
          while ( v151 != v194 );
        }
        v155 = v194;
        v148[2] = v150 + (v148[2] & 1);
        *(_DWORD *)(v150 + 4 * v152) = v148;
        Phyre_Tree_RemoveNode_COMDAT(v155, (int)v148);
      }
LABEL_219:
      j_1 = *(_DWORD **)(v124 + 4);
      if ( j_1 == j || !j_1 )
        v124 = 0;
      else
        v124 = (unsigned int)(j_1 - 1);
      Size += 24;
    }
    while ( v124 );
    v94 = v209;
LABEL_226:
    i_14 = (PhyrePClassDescriptor *)i;
    v158 = Phyre_PClassDescriptor_GetMemberCount((PhyrePClassDescriptor *)i);
    if ( v158 && ((v159 = v214, v203) || v214) )
    {
      *(_DWORD *)(Size_13 + 32) = (_BYTE *)v211 - v180 + 1;
      if ( v159 && v94 && v200 )
      {
        v215[1] = Size_18;
        v215[0] = 1;
        v215[2] = Size_4;
        v216 = 1;
        memset(v211, 0, Size_4);
        Phyre_Type_RegisterOrFindType(
          v94,
          (int)v215,
          i_14->m_propCount + v158 - i_14->m_propCapacity,
          (int)v211 + *(_DWORD *)(v200 + 24) - *(_DWORD *)(v200 + 20));
        Size_21 = Size_13;
        v211 = (char *)v211 + Size_4;
      }
      else
      {
        Phyre_PClass_CopyMembers_PostProcess(i_14);
        Size_21 = Size_13;
        v211 = (char *)v211 + Size_4;
      }
    }
    else
    {
      Size_21 = Size_13;
      *(_DWORD *)(Size_13 + 32) = 0;
    }
    i_8 = i_1;
    ++p_i;
    ptr_4 = ptr_5 + 4;
    ptr_5 = ptr_4;
    Size_13 = Size_21 + 36;
  }
  while ( ptr_4 < (unsigned int)i_1 );
  Size_16 = Size_22;
  ptr_3 = ptr;
LABEL_237:
  for ( m = ptr_3; m < (unsigned int)i_8; Size_22 = Size_16 )
  {
    Size_24 = *(_DWORD **)(*(_DWORD *)m + 64);
    if ( Size_24 )
    {
      Size_23 = (_DWORD *)Phyre_TypeMap_ResolveValueByFirstField(v193, *(_DWORD *)(*(_DWORD *)m + 64));
      ptr_5 = 0;
      Size_18 = (size_t)Size_23;
      v164 = Phyre_NameMap_FindByNameBST(Size_11, (int *)&Size_18);
      if ( v164 )
      {
        v165 = v164 + 4;
        if ( v165 )
          ptr_5 = *v165;
      }
      if ( Size_24 == Size_23 )
      {
        Size_16 = Size_22;
      }
      else
      {
        v166 = v197;
        v167 = Size_23[7];
        n0xFFFF_1 = Size_23[8];
        if ( v197 )
        {
          if ( v197[11] || (v169 = Size_23[31], v166 = v197, v169 >= (v197[12] & 0x7FFFFFFFu)) )
          {
            v170 = v166[7];
            v171 = v170 + 32 * v197[6];
            if ( v170 >= v171 )
            {
LABEL_250:
              v170 = 0;
            }
            else
            {
              while ( *(_DWORD **)(v170 + 8) != Size_23 )
              {
                v170 += 32;
                if ( v170 >= v171 )
                  goto LABEL_250;
              }
            }
          }
          else
          {
            v170 = *(_DWORD *)(v197[13] + 4 * v169);
          }
          if ( v170 )
          {
            v172 = *(_DWORD *)(*(_DWORD *)(v170 + 4) + 4);
            v173 = v172 >> 28;
            v167 = v172 & 0xFFFFFFF;
            n0xFFFF_1 = 1 << v173;
          }
        }
        v174 = 16 * (n0xFFFF_1 > 0xFFFF);
        n0xFF_1 = n0xFFFF_1 >> (16 * (n0xFFFF_1 > 0xFFFF));
        Size_16 = Size_22;
        Size_22[1] = v167
                   | (((2 * (n0xFF_1 >> (8 * (n0xFF_1 > 0xFF)) >> (4 * (n0xFF_1 >> (8 * (n0xFF_1 > 0xFF)) > 0xF)) > 3))
                     | (4 * (n0xFF_1 >> (8 * (n0xFF_1 > 0xFF)) > 0xF))
                     | (8 * (n0xFF_1 > 0xFF))
                     | v174
                     | (n0xFF_1 >> (8 * (n0xFF_1 > 0xFF)) >> (4 * (n0xFF_1 >> (8 * (n0xFF_1 > 0xFF)) > 0xF)) >> (2 * (n0xFF_1 >> (8 * (n0xFF_1 > 0xFF)) >> (4 * (n0xFF_1 >> (8 * (n0xFF_1 > 0xFF)) > 0xF)) > 3)) >> 1)) << 28);
      }
      i_8 = i_1;
      *Size_16 = ptr_5;
    }
    m += 4;
    Size_16 += 9;
  }
LABEL_257:
  LOBYTE(n5) = 2;
  if ( v178 >= 0 )
    Engine_AlignedFree((void *)ptr);
  LOBYTE(n5) = 1;
  if ( v181 >= 0 && p_i_3 )
    Engine_AlignedFree(p_i_3);
LABEL_262:
  n5 = 5;
  PTree_Node_InitSelfRef(v184);
  AlignedLinkedListBlock_FreeAll_B(v188);
  LOBYTE(n5) = 4;
  AlignedLinkedListBlock_FreeAll(v188);
  n5 = 6;
  Phyre_Tree_RemoveNodeWithRotation(v184);
  n5 = -1;
  Phyre_Tree_RemoveNodeWithRotation(v184);
  return v204;
}
