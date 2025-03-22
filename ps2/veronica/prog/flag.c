



/*void bhStFlg(unsigned int* flg, unsigned int bit);
void bhCrFlg(unsigned int* flg, unsigned int bit);
int bhCkFlg(unsigned int* flg, unsigned int bit);

// 
// Start address: 0x280e40
void bhStFlg(unsigned int* flg, unsigned int bit)
{
	// Line 37, Address: 0x280e40, Func Offset: 0
	// Line 38, Address: 0x280e60, Func Offset: 0x20
	// Func End, Address: 0x280e68, Func Offset: 0x28
}

// 
// Start address: 0x280e70
void bhCrFlg(unsigned int* flg, unsigned int bit)
{
	// Line 45, Address: 0x280e70, Func Offset: 0
	// Line 46, Address: 0x280e94, Func Offset: 0x24
	// Func End, Address: 0x280e9c, Func Offset: 0x2c
}*/

// 100% matching! 
int bhCkFlg(unsigned int* flg, unsigned int bit)
{
    return flg[bit / 32] & (0x80000000 >> (bit & 31)); 
} 
