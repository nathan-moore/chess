#include "board.h"
#include "piece.h"

#include <iostream>
#include <cstring>

int main (void)
{
	piece board[8][8];

	piece temp[] = {brook,bknight,bbishop,bqueen,bking,bbishop,bknight,brook};
	std::memcpy(board[7],temp,sizeof(piece) * 8);

	for(int i = 0;i < 8;++i)
	{
		board[6][i] = pieces::white::pawn;
	}
	for(int i = 0;i < 6;++i)
	{
		for(int j = 0;j < 8;++j)
		{
			board[i][j] = pieces::empty;
		}
	}

	boardC bd;
	bd.setBoard(board);

	bool passed = true;
	for(int_least8_t i = 0;i < 8;++i)
	{
		for(int_least8_t j = 0;j < 2;++j)
		{
			Square from = {.row = 6,.column = i};
			Square to = {.row = 7,.column = i};
			int rtn = bd.movePiece(from,to,(bool) j);
			if(rtn == 0)
			{
				std::cout << "operation successed where it shouldn't have\n";
				std::cout << "from\n";
				from.print();
				std::cout << "to\n";
				to.print();
				bd.printboard();
				passed = false;
			}
		}
	}
	if(passed)
	{
		std::cout << "passed all cases\n";
	}
}
