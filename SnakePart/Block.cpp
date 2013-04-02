#include "Block.h"

Block::Block() 
{
	Block_Count = 0;
	Block_PosX = new int[100];
	Block_PosY = new int[100];
}
	
void Block::Block_AddNew(int PosX, int PosY)
{
	Block_PosX[Block_Count] = PosX;
	Block_PosY[Block_Count] = PosY;
	Block_Count++;
}
void Block::Block_ClearAll()
{
	for (int i=0; i<Block_Count; i++)
	{
		Block_PosX[i] = 0;
		Block_PosY[i] = 0;
	}
	Block_Count = 0;
}
