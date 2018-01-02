#ifndef board_h
#define board_h

#include <cstdint>

#include "piece.h"

#define ENPASSANT 2

class Square{
public:
     int_least8_t row;
     int_least8_t column;
	 void print();
};

class boardC{

public:
	//makes a new board
     void newBoard();
	 //sets a board,does no error checking
	 void setBoard(const piece from[8][8]);
	 //turn is false for white
	 //returns 1 if not successfull
	 //0 if successfull
     int movePiece(Square from,Square to,bool turn);
     void printboard();
     boardC();
     ~boardC();

private:
	//00 is in the lower left
     piece board[8][8];
     int Enpassant;
     Square pawn;

     int validPawnMove(Square from,Square to);
     int validLineMove(Square from,Square to);
     int validDiagMove(Square from,Square to);
     int validKnightMove(Square from,Square to);
     int validKingMove(Square from, Square to);

     Square delta(Square from,Square to);
     int getColor(Square);

	 bool inline isEmpty(const Square &t);
};

#endif
