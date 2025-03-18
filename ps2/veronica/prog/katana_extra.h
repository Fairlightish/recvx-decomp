// TODO: include sg_sybt.h and remove the below struct
struct tag_SYS_BT_SYSTEMID{                   /*                    */
    Sint32 nNo ;                              /*                    */
    Sint32 nAll ;                             /*                    */
    Sint8  szProduct[16];                     /*                    */
} ;                                           /*                    */
typedef struct tag_SYS_BT_SYSTEMID SYS_BT_SYSTEMID ;

/******** ?��?��?��?��?��?��?��J?��[?��h?��?��?��\?��?��?��?�� *******************************************/
/******** Memory card information structure ********************************/
typedef struct {
	Uint16 Ready;               /* ?��?��?��?��?��?��?��J?��[?��h?��?��?��}?��E?��?��?��g?��?��?��?��Ă�?��邩      */
	                            /* Is memory card mounted ?                */
	Uint16 IsFormat;            /* ?��t?��H?��[?��}?��b?��g?��?��?��?��Ă�?��邩?��ǂ�?��?��          */
	                            /* Is memory card formatted ?              */
	Uint32 LastError;           /* ?��Ō�ɔ�?��?��?��?��?��?��?��G?��?��?��[?��R?��[?��h              */
	                            /* Error code which occured last.          */
	Uint32 ProgressCount;       /* ?��?��?��?��?��o?��߃J?��E?��?��?��g                        */
	                            /* Operation progress count.               */
	Uint32 ProgressMax;         /* ?��?��?��?��?��o?��߃J?��E?��?��?��g?��ő�                    */
	                            /* Operattion progress count maximum.      */
	Uint32 Operation;           /* ?��?��?��?��?��?��?��̃I?��y?��?��?��[?��V?��?��?��?��?��R?��[?��h            */
	                            /* Operation code in handling now.         */
	BUS_DISKINFO DiskInfo;      /* ?��h?��?��?��C?��u?��?��?��                            */
	                            /* Drive information.                      */
	Uint32 Connect;             /* ?��?��?��?��?��?��?��[?��J?��[?��h?��?��?��ڑ�?��?��?��?��Ă�?��邩        */
	                            /* Is memory card connected ?              */
	void* Work;                 /* ?��?��?��[?��N?��A?��h?��?��?��X                          */
	                            /* Work address.                           */
	Uint32 WorkSize;            /* ?��?��?��[?��N?��T?��C?��Y                            */
	                            /* Work size (bytes).                      */
	Uint32 Capacity;            /* ?��?��?��?��?��?��?��J?��[?��h?��̗e?��ʃt?��?��?��O(BUD_CAPACITY)  */
	                            /* Capacity flag of memory card.           */
    Sint32 MemMode;             // manually added
} BACKUPINFO;

/*===============================================================*/
/* ?��Ή�?��?��?���??��?��?��?��?��[?��J?��[?��h?��̍ő�e?��?��                              */
/* Mamimum volume to use.                                        */
/*===============================================================*/

#define MAX_CAPS BUD_CAPACITY_1MB

/*===============================================================*/
/* ?��Ή�?��?��?���??��?��?��?��?��[?��J?��[?��h?��̃h?��?��?��C?��u?��?��                            */
/* Number of memory card to use.                                 */
/*===============================================================*/

#define MAX_DRIVES 8
#define USE_DRIVES BUD_USE_DRIVE_ALL

#define set_imask(mask)             _builtin_set_imask(mask)

/* SH-4 program area address. */
#define P1AREA   0x80000000

/* Define work RAM end address (16 MB). */
#define WORK_END (((Uint32) _BSG_END) & 0xe0000000 | 0x0d000000)

#define HEAP_AREA ((void*) ((((Uint32) _BSG_END | P1AREA) & 0xffffffe0) + 0x20))
#define HEAP_SIZE (WORK_END - (Uint32) HEAP_AREA)