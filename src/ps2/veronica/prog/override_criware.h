/*	�t�@�C�����̕�����				*/
/*	Maximum number of file name strings	*/
#define ADXF_FNAME_MAX    		(256)

/*	�p�[�e�B�V�������		*/
/*	Partition information	*/
#ifndef ADXF_PTINFO_DEFINED
#define ADXF_PTINFO_DEFINED
typedef struct _adxf_ptinfo {
	struct _adxf_ptinfo	*next;		/*	���̃p�[�e�B�V����(NULL:�I���W�i��)	*/
	Sint32				size;		/*	�p�[�e�B�V�������̈�T�C�Y		*/
	Sint32				nfile;		/*	�p�[�e�B�V�������̃t�@�C����		*/
	Uint16				nentry;		/*	�p�[�e�B�V�������̓o�^�t�@�C����	*/
	Sint8				type;		/*	�I���W�i�����ǋL���̃t���O			*/
	Sint8				rev;		/*	�\��̈�							*/
	/*	ADXSTM_OpenRange -> ADXSTM_OpenFileRange(1999.8.19)	*/
	Sint8				fname[ADXF_FNAME_MAX];	/*	AFS�t�@�C����			*/
	void				*curdir;
	Sint16				top;		/*	�t�@�C�����̐擪					*/
	Sint16				btm[1];		
} ADXF_PTINFO;
#endif
