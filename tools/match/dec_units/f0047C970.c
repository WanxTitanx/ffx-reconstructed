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

extern _DWORD Phyre_ClassDescriptor_ConfigureDispatch();
extern _DWORD Phyre_NameMap_BST_FindOrInsert();
extern _DWORD Phyre_PClassDescriptor_FindByNamePropertyList();
extern _DWORD Phyre_PMap_FindByStringKey();
extern _DWORD Phyre_PNamespace_FindClassDescriptor();
extern _DWORD Phyre_PTypeDefault_PUInt64_SingletonInit();
extern _DWORD Phyre_Stream_Printf();
extern _DWORD Phyre_Type_ValidateClassCompatibility();
// Function: Phyre_Type_ResolveOnLoad
// Address: 0x47C970
// Size: 0x3C5
// Phyre: Type resolve on load — resolves type references during deserialization
unsigned int __fastcall Phyre_Type_ResolveOnLoad(
        _DWORD *self,
        PhyrePNamespace *Singleton,
        _DWORD *a3,
        int a4,
        char Sizea)
{
  _DWORD *this_1; // edi
  _DWORD *v6; // esi
  _DWORD *v7; // ebx
  int v8; // edx
  int this_6; // ecx
  int v10; // eax
  _DWORD *v11; // edx
  _DWORD *this_13; // eax
  PhyrePClassDescriptor *name_4; // edi
  _DWORD *v14; // esi
  void ***this_12; // eax
  int vfptr_low; // ecx
  PhyrePClassDescriptor *name_5; // esi
  int n1973; // edx
  _DWORD *v19; // eax
  _DWORD *v20; // edx
  unsigned int this_7; // ebx
  int v22; // eax
  unsigned int this_9; // esi
  int v24; // eax
  PhyrePClassDescriptor *name; // edi
  void ***this_14; // eax
  int v27; // ecx
  PhyrePClassDescriptor *name_3; // edx
  int n1973_1; // esi
  _DWORD *v30; // eax
  PhyrePClassDescriptor *ClassDescriptor; // esi
  int v32; // eax
  int v33; // ecx
  char *v34; // edx
  int v35; // eax
  int v36; // ecx
  unsigned int this_10; // ebx
  _DWORD *Singletona_1; // edx
  _DWORD *v39; // esi
  _DWORD *v40; // eax
  unsigned int this_5; // ecx
  unsigned int v42; // ebx
  const char *name_1; // edi
  int v44; // eax
  unsigned int v45; // ecx
  unsigned int v46; // eax
  int v47; // ebx
  char v48; // cl
  int v49; // eax
  bool v50; // zf
  unsigned int this_3; // eax
  int *v52; // esi
  unsigned int v53; // ecx
  unsigned int v54; // ebx
  int v55; // edi
  int v56; // ecx
  int p_n1973; // [esp+Ch] [ebp-28h] BYREF
  PhyrePClassDescriptor *name_2; // [esp+10h] [ebp-24h]
  void ***this_11; // [esp+14h] [ebp-20h]
  char *v60; // [esp+18h] [ebp-1Ch]
  PhyrePClassDescriptor *v61; // [esp+1Ch] [ebp-18h]
  int v62; // [esp+20h] [ebp-14h]
  _DWORD *v63; // [esp+24h] [ebp-10h]
  unsigned int this_4; // [esp+28h] [ebp-Ch]
  _DWORD *this_8; // [esp+2Ch] [ebp-8h]
  _DWORD *this_2; // [esp+30h] [ebp-4h]
  _DWORD *Singletona; // [esp+3Ch] [ebp+8h]
  _DWORD *Singletonb; // [esp+3Ch] [ebp+8h]
  _DWORD *v69; // [esp+40h] [ebp+Ch]

  this_1 = self;
  this_2 = self;
  v6 = (_DWORD *)*self;
  v7 = (_DWORD *)*(self + 2);
  v8 = 3 * *(_DWORD *)(*self + 16);
  this_6 = *(self + 1) & 0x7FFFFFFF;
  v10 = 9 * v6[3];
  this_4 = this_6;
  v11 = &v6[2 * v8 + 8 + v6[2] + v10];
  this_13 = v6 + 8;
  v63 = v11;
  this_8 = v6 + 8;
  if ( this_6 )
  {
    while ( 1 )
    {
      name_4 = (PhyrePClassDescriptor *)((char *)v11 + *this_13);
      if ( name_4 )
      {
        this_12 = Phyre_PTypeDefault_PUInt64_SingletonInit();
        vfptr_low = LOBYTE(name_4->vfptr);
        this_11 = this_12;
        name_2 = name_4;
        name_5 = name_4;
        n1973 = 1973;
        if ( vfptr_low )
        {
          do
          {
            name_5 = (PhyrePClassDescriptor *)((char *)name_5 + 1);
            n1973 = (vfptr_low & 0x1F) + 33 * n1973;
            LOBYTE(vfptr_low) = name_5->vfptr;
          }
          while ( LOBYTE(name_5->vfptr) );
          this_12 = this_11;
        }
        p_n1973 = n1973;
        v19 = Phyre_NameMap_BST_FindOrInsert(this_12, &p_n1973);
        this_6 = this_4;
        v14 = v19;
        this_13 = this_8;
        if ( v14 )
          goto LABEL_10;
      }
      else
      {
        v14 = 0;
      }
      if ( Sizea )
      {
        Phyre_Stream_Printf(
          2,
          "Unable to find type '%s' on load. Has the type been registered?\n",
          (const char *)name_4);
        this_13 = this_8;
        this_6 = this_4;
      }
LABEL_10:
      v11 = v63;
      *v7 = this_13;
      v7[2] = name_4;
      v7[1] = v14;
      ++this_13;
      v7 += 3;
      --this_6;
      this_8 = this_13;
      this_4 = this_6;
      if ( !this_6 )
      {
        this_1 = this_2;
        break;
      }
    }
  }
  v20 = (_DWORD *)*this_1;
  this_7 = *this_1 + 4 * (*(_DWORD *)(*this_1 + 8) + 8);
  v22 = 9 * (this_1[3] & 0x7FFFFFFF);
  this_4 = this_7;
  this_9 = this_7 + 4 * v22;
  v62 = this_1[4];
  v24 = v20[4];
  this_8 = (_DWORD *)this_9;
  v60 = (char *)&v20[9 * v20[3] + 8 + 6 * v24 + v20[2]] + v20[5];
  if ( this_7 < this_9 )
  {
    do
    {
      name = (PhyrePClassDescriptor *)((char *)v63 + *(_DWORD *)(this_7 + 8));
      if ( !name )
        goto LABEL_20;
      this_14 = Phyre_PTypeDefault_PUInt64_SingletonInit();
      v27 = LOBYTE(name->vfptr);
      this_11 = this_14;
      name_2 = name;
      name_3 = name;
      n1973_1 = 1973;
      if ( v27 )
      {
        do
        {
          name_3 = (PhyrePClassDescriptor *)((char *)name_3 + 1);
          n1973_1 = (v27 & 0x1F) + 33 * n1973_1;
          LOBYTE(v27) = name_3->vfptr;
        }
        while ( LOBYTE(name_3->vfptr) );
        this_14 = this_11;
      }
      p_n1973 = n1973_1;
      v30 = Phyre_NameMap_BST_FindOrInsert(this_14, &p_n1973);
      if ( !v30
        || (ClassDescriptor = (PhyrePClassDescriptor *)(*(int (__fastcall **)(_DWORD *))(*v30 + 4))(v30)) == 0
        || ClassDescriptor->m_pNamespace != Singleton )
      {
LABEL_20:
        ClassDescriptor = Phyre_PNamespace_FindClassDescriptor(Singleton, (const char *)name);
        if ( !ClassDescriptor || ClassDescriptor->m_pNamespace != Singleton )
          ClassDescriptor = 0;
      }
      if ( !ClassDescriptor )
      {
        if ( (*(_BYTE *)(this_7 + 28) & 1) != 0 )
        {
          if ( a3 )
            ClassDescriptor = (PhyrePClassDescriptor *)Phyre_PMap_FindByStringKey(a3, (const char *)name);
        }
        else if ( Sizea )
        {
          Phyre_Stream_Printf(
            1,
            "File refers to compiled class '%s' which does not exist in the current runtime\n",
            (const char *)name);
        }
      }
      v32 = *(_DWORD *)(this_7 + 32);
      v33 = *(_DWORD *)this_7;
      if ( v32 )
        v34 = &v60[v32 - 1];
      else
        v34 = 0;
      if ( v33 <= 0 )
        v35 = 0;
      else
        v35 = 32 * v33 + this_2[4] - 32;
      v36 = v62 + 32;
      *(_DWORD *)(v62 + 4) = this_7;
      *(_DWORD *)(v36 - 32) = v35;
      *(_DWORD *)(v36 - 24) = ClassDescriptor;
      *(_DWORD *)(v36 - 20) = name;
      *(_DWORD *)(v36 - 8) = v34;
      this_7 += 36;
      v62 = v36;
    }
    while ( this_7 < (unsigned int)this_8 );
    this_1 = this_2;
  }
  this_10 = this_4;
  Singletona_1 = (_DWORD *)this_1[4];
  v39 = (_DWORD *)this_1[6];
  Singletona = Singletona_1;
  v40 = (_DWORD *)(*this_1 + 32 + 4 * (*(_DWORD *)(*this_1 + 8) + 9 * *(_DWORD *)(*this_1 + 12)));
  this_5 = (unsigned int)this_8;
  v69 = v40;
  this_11 = (void ***)this_4;
  if ( this_4 < (unsigned int)this_8 )
  {
LABEL_38:
    name_2 = (PhyrePClassDescriptor *)Singletona_1[2];
    Singletona_1[4] = v39;
    v60 = *(char **)(this_10 + 12);
    if ( !v60 )
      goto LABEL_58;
    while ( 1 )
    {
      v42 = v40[1];
      name_1 = (char *)v63 + *v40;
      v61 = name_2 ? Phyre_PClassDescriptor_FindByNamePropertyList(name_2, name_1) : 0;
      v44 = 0;
      v45 = this_2[1] & 0x7FFFFFFF;
      v62 = 0;
      if ( v42 < v45 )
        break;
      v46 = v42;
      v47 = v62;
      v44 = this_2[4] + 32 * (v46 - v45 - 1);
      if ( !v44 )
        goto LABEL_46;
      v48 = *(_BYTE *)(*(_DWORD *)(v44 + 4) + 28) & 1;
LABEL_47:
      *v39 = Singletona;
      v39[1] = v69;
      v39[3] = name_1;
      v39[5] = v44;
      if ( v44 )
      {
        v49 = *(_DWORD *)(v44 + 8);
      }
      else if ( v47 )
      {
        v49 = *(_DWORD *)(v47 + 4);
      }
      else
      {
        v49 = 0;
      }
      v39[4] = v49;
      if ( !v49 && Sizea && !v48 )
        Phyre_Stream_Printf(
          2,
          "Unable to find type for '%s_%s' on load. Has the type been registered?\n",
          (const char *)Singletona[3],
          name_1);
      v39[2] = v61;
      v40 = v69 + 6;
      v39 += 8;
      v50 = v60-- == (char *)1;
      v69 += 6;
      if ( v50 )
      {
        Singletona_1 = Singletona;
        this_10 = (unsigned int)this_11;
LABEL_58:
        this_5 = (unsigned int)this_8;
        this_10 += 36;
        Singletona_1 += 8;
        this_11 = (void ***)this_10;
        Singletona = Singletona_1;
        if ( this_10 >= (unsigned int)this_8 )
        {
          this_1 = this_2;
          goto LABEL_60;
        }
        goto LABEL_38;
      }
    }
    v47 = this_2[2] + 12 * v42;
LABEL_46:
    v48 = 0;
    goto LABEL_47;
  }
LABEL_60:
  this_3 = this_4;
  v52 = (int *)this_1[4];
  if ( this_4 < this_5 )
  {
    v53 = this_5 - this_4 - 1;
    this_3 = 954437177 * v53;
    v54 = v53 / 0x24 + 1;
    do
    {
      if ( v52[2] )
      {
        Singletonb = (_DWORD *)*v52;
        v55 = Phyre_Type_ValidateClassCompatibility(v52, Sizea);
        if ( Singletonb )
          v56 = Singletonb[5];
        else
          v56 = 0;
        v52[5] = v55 | v56;
        if ( v55 )
          Phyre_ClassDescriptor_ConfigureDispatch(v52, a4);
        this_3 = (unsigned int)this_2;
        this_2[7] |= v55;
      }
      v52 += 8;
      --v54;
    }
    while ( v54 );
  }
  return this_3;
}
