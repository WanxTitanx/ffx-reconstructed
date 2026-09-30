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

extern _DWORD Engine_AlignedAllocAlign();
extern _DWORD Engine_AlignedFree();
extern _DWORD Phyre_ClassDescriptor_ConfigureDispatch();
extern _DWORD Phyre_Matrix3x3_ToEuler();
extern _DWORD Phyre_Node_AccumulateFlags();
extern _DWORD Phyre_PClassDescriptor_FindByNamePropertyList();
extern _DWORD Phyre_Tree_GetPredecessor();
extern _DWORD Phyre_Tree_GetPredecessor_COMDAT();
extern _DWORD Phyre_Tree_MakeIterator();
extern _DWORD Phyre_TypeDeserializer_ZeroArray();
extern _DWORD Phyre_TypeDeserializer_ZeroArray_v2();
extern _DWORD Phyre_Type_ValidateClassCompatibility();
extern _DWORD function();
// Function: Phyre_Loose_47D790
// Address: 0x47D790
// Size: 0x541
// DEFINE-FUNC-SWEEP leva9: orphan code block defined as function (was decoded code, 0 xrefs, not a func item). calls:Phyre_Matrix3x3_ToEuler,Phyre_Tree_GetPredecessor_COMDAT,Engine_AlignedAllocAlign,Phyre_TypeDeserializer_ZeroArray_v2,Engine_
int __fastcall Phyre_Loose_47D790(int self, _DWORD *a2)
{
  _DWORD *Predecessor_COMDAT_1; // ebx
  _DWORD *this_1; // eax
  int v5; // edi
  _DWORD **Predecessor_COMDAT; // edx
  _DWORD *v7; // ecx
  _DWORD *v8; // eax
  _DWORD *i; // eax
  _DWORD *v10; // eax
  int v11; // ebx
  int *n8; // eax
  int *n8_4; // edx
  int *n8_3; // eax
  int *Predecessor_7; // ecx
  int *Predecessor_8; // edx
  int *n8_5; // ebx
  int *n8_1; // eax
  int *n8_6; // ecx
  int *v21; // ebx
  int *v22; // ecx
  int **v23; // edi
  int *v24; // ebx
  int v25; // eax
  int *Predecessor_2; // edx
  PhyrePClassDescriptor **v27; // esi
  _DWORD *v28; // eax
  void *m_pParentCD; // ecx
  unsigned int v30; // edx
  unsigned int v31; // eax
  _DWORD *v32; // ecx
  PhyrePClassDescriptor *v33; // edx
  int *v34; // eax
  _DWORD *v35; // esi
  int v36; // eax
  PhyrePClassDescriptor *j; // esi
  int *m_pClassName; // ecx
  int v39; // edx
  int v40; // eax
  int *v41; // ecx
  int *v42; // edx
  PhyrePClassDescriptor *j_1; // eax
  int n4; // edi
  int v45; // eax
  bool v46; // dl
  int v47; // eax
  bool v48; // dl
  int m_pClassName_2; // eax
  _DWORD *v50; // eax
  _DWORD *m_namespaceList; // esi
  int *n8_7; // esi
  int *v53; // ecx
  _DWORD *v54; // ecx
  unsigned int n0xFFFF; // edx
  int v56; // eax
  unsigned int n0xFF; // edx
  int *v58; // ecx
  int v59; // eax
  int v60; // ecx
  int v61; // esi
  int *Predecessor; // eax
  int *Predecessor_5; // ecx
  int *Predecessor_4; // [esp+Ch] [ebp-44h] BYREF
  int *Predecessor_6; // [esp+10h] [ebp-40h]
  int *Predecessor_9; // [esp+14h] [ebp-3Ch]
  int *v67; // [esp+18h] [ebp-38h]
  int *m_pClassName_1; // [esp+1Ch] [ebp-34h]
  const char *m_pClassDescriptor; // [esp+20h] [ebp-30h]
  PhyrePClassDescriptor *j_2; // [esp+24h] [ebp-2Ch]
  int v71; // [esp+28h] [ebp-28h]
  int *Predecessor_1; // [esp+2Ch] [ebp-24h]
  int *v73; // [esp+30h] [ebp-20h]
  PhyrePClassDescriptor *v74; // [esp+34h] [ebp-1Ch]
  int v75; // [esp+38h] [ebp-18h]
  int **v76; // [esp+3Ch] [ebp-14h]
  int *Predecessor_3; // [esp+40h] [ebp-10h]
  int *n8_2; // [esp+44h] [ebp-Ch]
  unsigned int v79; // [esp+48h] [ebp-8h]
  _DWORD *v80; // [esp+4Ch] [ebp-4h]

  Predecessor_COMDAT_1 = (_DWORD *)(self + 12);
  v71 = Phyre_Matrix3x3_ToEuler((_DWORD *)self);
  this_1 = (_DWORD *)*Predecessor_COMDAT_1;
  v5 = 0;
  if ( *Predecessor_COMDAT_1 == self || !this_1 )
  {
    Predecessor_COMDAT_1 = *(_DWORD **)(self + 12);
  }
  else
  {
    for ( ; this_1 != (_DWORD *)self; this_1 = (_DWORD *)*this_1 )
      Predecessor_COMDAT_1 = this_1;
  }
  if ( Predecessor_COMDAT_1 != (_DWORD *)self )
  {
    Predecessor_COMDAT = Phyre_Tree_GetPredecessor_COMDAT((_DWORD **)self, (int)Predecessor_COMDAT_1);
    do
    {
      v7 = (_DWORD *)(Predecessor_COMDAT_1[3] + 68);
      v8 = (_DWORD *)*v7;
      if ( (_DWORD *)*v7 != v7 )
      {
        if ( v8 )
        {
          for ( i = v8 - 1; i; i = v10 - 1 )
          {
            v10 = (_DWORD *)i[1];
            ++v5;
            if ( v10 == v7 )
              break;
            if ( !v10 )
              break;
          }
        }
      }
      Predecessor_COMDAT_1 = Predecessor_COMDAT;
      if ( Predecessor_COMDAT != (_DWORD **)self )
        Predecessor_COMDAT = Phyre_Tree_GetPredecessor_COMDAT((_DWORD **)self, (int)Predecessor_COMDAT);
    }
    while ( Predecessor_COMDAT_1 != (_DWORD *)self );
  }
  v11 = v71;
  if ( v71 != *(_DWORD *)(self + 48) )
  {
    n8_2 = 0;
    if ( v71 )
    {
      n8 = Engine_AlignedAllocAlign(32 * v71, 4);
      n8_2 = n8;
      if ( !n8 )
        return 13;
      Phyre_TypeDeserializer_ZeroArray_v2(n8, (int)n8, v71);
    }
    n8_4 = *(int **)(self + 52);
    n8_3 = n8_2;
    if ( n8_4 != n8_2 && *(int *)(self + 48) >= 0 && n8_4 )
    {
      Engine_AlignedFree(*(void **)(self + 52));
      n8_3 = n8_2;
    }
    *(_DWORD *)(self + 52) = n8_3;
    *(_DWORD *)(self + 48) = v11;
  }
  if ( v11 != *(_DWORD *)(self + 64) )
  {
    Predecessor_7 = 0;
    Predecessor_3 = 0;
    if ( v11 )
    {
      Predecessor_7 = Engine_AlignedAllocAlign(36 * v11, 4);
      Predecessor_3 = Predecessor_7;
      if ( !Predecessor_7 )
        return 13;
    }
    Predecessor_8 = *(int **)(self + 68);
    if ( Predecessor_8 != Predecessor_7 && *(int *)(self + 64) >= 0 && Predecessor_8 )
    {
      Engine_AlignedFree(*(void **)(self + 68));
      Predecessor_7 = Predecessor_3;
    }
    *(_DWORD *)(self + 68) = Predecessor_7;
    *(_DWORD *)(self + 64) = v11;
  }
  if ( v5 != *(_DWORD *)(self + 56) )
  {
    n8_5 = 0;
    if ( v5 )
    {
      n8_1 = Engine_AlignedAllocAlign(32 * v5, 4);
      n8_5 = n8_1;
      if ( !n8_1 )
        return 13;
      Phyre_TypeDeserializer_ZeroArray(n8_1, (int)n8_1, v5);
    }
    n8_6 = *(int **)(self + 60);
    if ( n8_6 != n8_5 && *(int *)(self + 56) >= 0 && n8_6 )
      Engine_AlignedFree(*(void **)(self + 60));
    *(_DWORD *)(self + 60) = n8_5;
    *(_DWORD *)(self + 56) = v5;
  }
  if ( v5 != *(_DWORD *)(self + 72) )
  {
    v21 = 0;
    if ( !v5 || (v21 = Engine_AlignedAllocAlign(24 * v5, 4)) != 0 )
    {
      v22 = *(int **)(self + 76);
      if ( v22 != v21 && *(int *)(self + 72) >= 0 && v22 )
        Engine_AlignedFree(*(void **)(self + 76));
      *(_DWORD *)(self + 76) = v21;
      *(_DWORD *)(self + 72) = v5;
      goto LABEL_53;
    }
    return 13;
  }
LABEL_53:
  v23 = *(int ***)(self + 60);
  v24 = *(int **)(self + 76);
  Predecessor_1 = *(int **)(self + 52);
  v25 = *(_DWORD *)(self + 68);
  v76 = v23;
  v71 = v25;
  Phyre_Tree_MakeIterator(&Predecessor_4, (_DWORD *)self);
  Predecessor_2 = Predecessor_6;
  Predecessor_3 = Predecessor_6;
  if ( Predecessor_6 != Predecessor_4 )
  {
    n8_2 = (int *)(v71 + 12);
    v27 = (PhyrePClassDescriptor **)(Predecessor_1 + 2);
    v71 = (int)(Predecessor_1 + 2);
    Predecessor_1 = Predecessor_9;
    do
    {
      v28 = (_DWORD *)Predecessor_2[4];
      v74 = (PhyrePClassDescriptor *)Predecessor_2[3];
      m_pParentCD = v74->m_pParentCD;
      v80 = v28;
      if ( m_pParentCD && (v30 = a2[7], v31 = v30 + 32 * a2[6], v79 = v30, v30 < v31) )
      {
        while ( *(void **)(v30 + 8) != m_pParentCD )
        {
          v30 += 32;
          v79 = v30;
          if ( v30 >= v31 )
            goto LABEL_59;
        }
      }
      else
      {
LABEL_59:
        v30 = 0;
        v79 = 0;
      }
      v32 = v80;
      v73 = (int *)(v27 - 2);
      *v73 = v30;
      v33 = v74;
      v32 += 17;
      v27[1] = (PhyrePClassDescriptor *)v74->m_pClassName;
      v34 = n8_2 - 3;
      *(v27 - 1) = (PhyrePClassDescriptor *)(n8_2 - 3);
      *v27 = v33;
      v27[2] = (PhyrePClassDescriptor *)v23;
      v27[4] = 0;
      v35 = (_DWORD *)*v32;
      v67 = v34;
      v36 = 0;
      v75 = 0;
      if ( v35 != v32 )
      {
        if ( v35 )
        {
          for ( j = (PhyrePClassDescriptor *)(v35 - 1); j; ++v75 )
          {
            m_pClassDescriptor = (const char *)j->m_pClassDescriptor;
            j_2 = Phyre_PClassDescriptor_FindByNamePropertyList(v33, m_pClassDescriptor);
            m_pClassName = (int *)j->m_pClassName;
            v39 = *m_pClassName;
            m_pClassName_1 = m_pClassName;
            v40 = (*(int (__fastcall **)(int *))(v39 + 4))(m_pClassName);
            if ( v40 && (v41 = (int *)a2[7], v42 = &v41[8 * a2[6]], v41 < v42) )
            {
              while ( v41[2] != v40 )
              {
                v41 += 8;
                if ( v41 >= v42 )
                  goto LABEL_67;
              }
            }
            else
            {
LABEL_67:
              v41 = 0;
            }
            *v23 = v73;
            j_1 = j_2;
            v23[1] = v24;
            if ( !j_1 )
              j_1 = j;
            v23[2] = (int *)j_1;
            v23[3] = (int *)m_pClassDescriptor;
            v23[4] = m_pClassName_1;
            v23[5] = v41;
            if ( v41 )
            {
              n4 = *(_DWORD *)(v41[1] + 4) & 0xFFFFFFF;
            }
            else
            {
              n4 = *((_DWORD *)j->m_pClassName + 7);
              v45 = (*((int (__fastcall **)(PhyrePClassDescriptor *))j->vfptr + 1))(j);
              v46 = v45 && *(_DWORD *)(v45 + 48) == 2;
              if ( (((int)j->m_pBaseClass & 2) != 0)
                 | v46 & (unsigned char)~(unsigned char)((unsigned int)j->m_pBaseClass >> 6) & 1 )
              {
                n4 = 4;
              }
            }
            m_pClassName_1 = (int *)a2[15];
            *v24 = 0;
            v24[1] = 0;
            v24[2] = j->m_alignSize;
            v47 = (*((int (__fastcall **)(PhyrePClassDescriptor *))j->vfptr + 1))(j);
            v48 = v47 && *(_DWORD *)(v47 + 48) == 2;
            m_pClassName_2 = (int)m_pClassName_1;
            if ( !((((int)j->m_pBaseClass & 2) != 0)
                 | v48 & (unsigned char)~(unsigned char)((unsigned int)j->m_pBaseClass >> 6) & 1) )
              m_pClassName_2 = n4;
            v24[3] = m_pClassName_2;
            v24[4] = (int)j->m_pBaseClass;
            v50 = v80;
            v24[5] = 0;
            m_namespaceList = (_DWORD *)j->m_namespaceList;
            if ( m_namespaceList == v50 + 17 || !m_namespaceList )
              j = 0;
            else
              j = (PhyrePClassDescriptor *)(m_namespaceList - 1);
            v33 = v74;
            v23 = v76 + 8;
            v36 = v75 + 1;
            v24 += 6;
            v76 += 8;
          }
        }
      }
      n8_7 = n8_2;
      v53 = v67;
      *n8_2 = v36;
      *v53 = 0;
      v54 = v80;
      *(n8_7 - 1) = 0;
      n8_7[1] = v54[33];
      n8_7[2] = v54[34];
      n8_7[3] = v54[35];
      n8_7[4] = v54[36] & 0x7FFFFFF;
      n8_7[5] = 0;
      n0xFFFF = v54[8];
      v56 = 16 * (n0xFFFF > 0xFFFF);
      n0xFF = n0xFFFF >> (16 * (n0xFFFF > 0xFFFF));
      v58 = v73;
      *(n8_7 - 2) = v80[7]
                  | (((2
                     * ((4 * (n0xFF >> (8 * (n0xFF > 0xFF)) > 0xF))
                      | (8 * (n0xFF > 0xFF))
                      | v56
                      | (2 * (n0xFF >> (8 * (n0xFF > 0xFF)) >> (4 * (n0xFF >> (8 * (n0xFF > 0xFF)) > 0xF)) > 3))))
                    | (n0xFF >> (8 * (n0xFF > 0xFF)) >> (4 * (n0xFF >> (8 * (n0xFF > 0xFF)) > 0xF)) >> (2 * (n0xFF >> (8 * (n0xFF > 0xFF)) >> (4 * (n0xFF >> (8 * (n0xFF > 0xFF)) > 0xF)) > 3)))
                    & 0xFFFFFFFE) << 27);
      v59 = Phyre_Type_ValidateClassCompatibility(v58, 0);
      if ( v79 )
        v60 = *(_DWORD *)(v79 + 20);
      else
        v60 = 0;
      v61 = v71;
      *(_DWORD *)(v71 + 12) = v59 | v60;
      if ( v59 )
        Phyre_ClassDescriptor_ConfigureDispatch((_DWORD *)(v61 - 8), 1);
      *(_DWORD *)(v61 + 20) = -1;
      Phyre_Node_AccumulateFlags((_DWORD *)(v61 - 8));
      Predecessor_3[6] = v61 - 8;
      Predecessor = Predecessor_1;
      Predecessor_5 = Predecessor_4;
      Predecessor_2 = Predecessor_1;
      Predecessor_3 = Predecessor_1;
      if ( Predecessor_1 != Predecessor_4 )
      {
        Predecessor = (int *)Phyre_Tree_GetPredecessor((_DWORD **)Predecessor_4, (int)Predecessor_1);
        Predecessor_2 = Predecessor_3;
        Predecessor_5 = Predecessor_4;
      }
      n8_2 += 9;
      v27 = (PhyrePClassDescriptor **)(v61 + 32);
      Predecessor_1 = Predecessor;
      v71 = (int)v27;
    }
    while ( Predecessor_2 != Predecessor_5 );
  }
  return 0;
}
