/*typedef struct GDS_DCF;
typedef struct GDS_FS_LIF;
typedef struct GDS_FS_HANDLE;
typedef struct GDS_FS_WORK;
typedef struct tag_SYS_BT_SYSTEMID;
typedef struct GDS_FS_DIRREC_ENT;
typedef struct GDS_FS_DIRREC_TBL;
typedef struct GDS_FS_DIRINFO;
typedef struct _anon0;

typedef void(*type_2)(void*);
typedef void(*type_3)(void*);
typedef void(*type_4)(void*, int);
typedef void(*type_5)(void*, int);
typedef void(*type_11)(void*, int);

typedef GDS_FS_HANDLE type_0[1];
typedef char type_1[16];
typedef _anon0 type_6[14];
typedef char type_7[32];
typedef char type_8[2];
typedef GDS_FS_DIRREC_ENT type_9[1];
typedef unsigned char type_10[3];
typedef unsigned int type_12[1040];

struct GDS_DCF
{
};

struct GDS_FS_LIF
{
};

struct GDS_FS_HANDLE
{
	GDS_FS_WORK* wk;
	int fid;
	int fad;
	int fsize;
	int fsctsize;
	int ofs;
	int trnsed;
	int rsize;
	int trsize;
	void(*rdendcb)(void*);
	void* rdcb_1st;
	void(*trendcb)(void*);
	void* trcb_1st;
	void(*errcb)(void*, int);
	void* errcb_1st;
	int gdchn;
	int gdchn_wait;
	int ex_errcode;
	short act;
	short trflag;
	short used;
	short tmode;
	short stat;
	short err;
};

struct GDS_FS_WORK
{
	int max_open;
	int pathtbl_fad;
	int pathtbl_size;
	GDS_DCF* dcf;
	GDS_FS_DIRREC_TBL* curdir;
	GDS_FS_HANDLE* syshdl;
	GDS_FS_HANDLE* hndtbl;
	GDS_FS_HANDLE* now_work;
	int f_svr;
	void(*g_errcb)(void*, int);
	void* g_errcb_1st;
	int gdc_ver;
	int errstat;
	int istray;
	short f_init;
	short daplayed;
	GDS_FS_LIF* liftbl;
	unsigned int sctbuf[1040];
	GDS_FS_HANDLE hndlist[1];
};

struct tag_SYS_BT_SYSTEMID
{
	int nNo;
	int nAll;
	char szProduct[16];
};

struct GDS_FS_DIRREC_ENT
{
	int fad;
	int fsize;
	unsigned char flag;
	unsigned char sid;
	char fname[32];
	char pad[2];
};

struct GDS_FS_DIRREC_TBL
{
	int dir_num;
	int max_ent;
	int dir_fad;
	int pad;
	GDS_FS_DIRREC_ENT dirrec_tbl[1];
};

struct GDS_FS_DIRINFO
{
	int fad;
	int fsize;
	unsigned char flag;
	unsigned char pad[3];
};

struct _anon0
{
	unsigned int Flag;
	GDS_FS_HANDLE* GdFs;
};*/

unsigned int MaxDirectoryEntry;
/*unsigned int DiscOpenTrayFlag;
unsigned int NewDiscCheckSw;
unsigned int GdErrorFlag;*/
NO_NAME_18 LfOpenInfo[14];
GDFS_DIRREC_TBL* GdDirRec;
/*void(*CallbackGdErrorFunc)(void*, int);*/
unsigned char* pDirTbl;
unsigned char* pDirWork;
unsigned int RequestMultiReadFlag;
unsigned int RequestReadBufferFlag;
unsigned int RequestReadFlag;
/*GDS_FS_HANDLE* CurrentGdFs;
GDS_FS_HANDLE* CurrentGdFsBuf;
unsigned int StatusUpdateCounter;
GDS_FS_HANDLE* LfGdFs;

void LfInitLib();
void CallbackGdErrorFunc(int err);
unsigned int InitGdSystem();
unsigned int InitGdSystemEx(unsigned int MaxDirNum);
void ExitGdSystem();
int GetFileSize(char* FileName);
int ReadFileEx(char* FileName, void* ReadAddress);
unsigned int CheckOpenTray();*/

// 100% matching!
void LfInitLib() 
{
    unsigned int i;
    
    for (i = 0; i < 14; i++) 
    { 
        LfOpenInfo[i].Flag = 0; 
    } 
} 

// 
// Start address: 0x28e9d0
void CallbackGdErrorFunc(int err)
{
	// Line 131, Address: 0x28e9d0, Func Offset: 0
	// Line 132, Address: 0x28e9e8, Func Offset: 0x18
	// Line 134, Address: 0x28e9f4, Func Offset: 0x24
	// Func End, Address: 0x28e9fc, Func Offset: 0x2c
}

// 99.18% matching
unsigned int InitGdSystem() 
{ 
    unsigned int i;
    int GdErrorCode;

    pDirWork = syMalloc(5484); 
    pDirTbl = syMalloc((MaxDirectoryEntry * 44) + 16);

    RequestReadFlag = 0; 
    RequestReadBufferFlag = 0; 
    RequestMultiReadFlag = 0; 

    LfInitLib();

    for (i = 0; i < 128; i++) 
    { 
        GdErrorCode = gdFsInit(14, pDirWork, MaxDirectoryEntry, pDirTbl); 

        if ((GdErrorCode == -23) || (GdErrorCode == -33)) 
        {
            break;
        }

        if (GdErrorCode == 0) 
        {
            GdDirRec = gdFsCreateDirhn(pDirTbl, MaxDirectoryEntry);
            
            gdFsLoadDir("\\", GdDirRec); 
            gdFsSetDir(GdDirRec);

            gdFsEntryErrFuncAll((GDFS_ERRFUNC)CallbackGdErrorFunc, NULL); 

            return 0; 
        }
    } 

    return 1; 
} 

// 100% matching!
unsigned int InitGdSystemEx(unsigned int MaxDirNum)
{
    MaxDirectoryEntry = MaxDirNum; 
    
    InitGdSystem(); 
}

/*// 
// Start address: 0x28eb40
void ExitGdSystem()
{
	// Line 177, Address: 0x28eb40, Func Offset: 0
	// Line 178, Address: 0x28eb48, Func Offset: 0x8
	// Line 179, Address: 0x28eb54, Func Offset: 0x14
	// Line 181, Address: 0x28eb60, Func Offset: 0x20
	// Line 182, Address: 0x28eb68, Func Offset: 0x28
	// Func End, Address: 0x28eb74, Func Offset: 0x34
}

// 
// Start address: 0x28eb80
int GetFileSize(char* FileName)
{
	GDS_FS_DIRINFO DirInfo;
	// Line 190, Address: 0x28eb80, Func Offset: 0
	// Line 194, Address: 0x28eb88, Func Offset: 0x8
	// Line 198, Address: 0x28eba4, Func Offset: 0x24
	// Func End, Address: 0x28ebb0, Func Offset: 0x30
}

// 
// Start address: 0x28ebb0
int ReadFileEx(char* FileName, void* ReadAddress)
{
	int FileSize;
	GDS_FS_HANDLE* GdFs;
	// Line 201, Address: 0x28ebb0, Func Offset: 0
	// Line 206, Address: 0x28ebc0, Func Offset: 0x10
	// Line 207, Address: 0x28ebd4, Func Offset: 0x24
	// Line 210, Address: 0x28ebdc, Func Offset: 0x2c
	// Line 211, Address: 0x28ebf0, Func Offset: 0x40
	// Line 214, Address: 0x28ebf8, Func Offset: 0x48
	// Line 216, Address: 0x28ec04, Func Offset: 0x54
	// Line 217, Address: 0x28ec24, Func Offset: 0x74
	// Line 220, Address: 0x28ec2c, Func Offset: 0x7c
	// Line 222, Address: 0x28ec38, Func Offset: 0x88
	// Line 223, Address: 0x28ec3c, Func Offset: 0x8c
	// Func End, Address: 0x28ec50, Func Offset: 0xa0
}

// 
// Start address: 0x28ec50
unsigned int CheckOpenTray()
{
	int Stat;
	// Line 375, Address: 0x28ec50, Func Offset: 0
	// Line 378, Address: 0x28ec58, Func Offset: 0x8
	// Line 380, Address: 0x28ec60, Func Offset: 0x10
	// Line 381, Address: 0x28ec78, Func Offset: 0x28
	// Line 382, Address: 0x28ec80, Func Offset: 0x30
	// Line 386, Address: 0x28ec88, Func Offset: 0x38
	// Line 387, Address: 0x28ec9c, Func Offset: 0x4c
	// Line 388, Address: 0x28ecb0, Func Offset: 0x60
	// Line 403, Address: 0x28ecb8, Func Offset: 0x68
	// Line 404, Address: 0x28ecc0, Func Offset: 0x70
	// Line 405, Address: 0x28ecc4, Func Offset: 0x74
	// Func End, Address: 0x28ecd0, Func Offset: 0x80
}*/
