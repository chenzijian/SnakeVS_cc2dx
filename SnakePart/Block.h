#ifndef __BLOCK_H__
#define __BLOCK_H__

#define MAX_BLOCK 100

class Block {
public:
	int *Block_PosX , *Block_PosY;
	int Block_Count;
	
	Block();
	
	void Block_AddNew(int PosX, int PosY);
	void Block_ClearAll();
};

#endif