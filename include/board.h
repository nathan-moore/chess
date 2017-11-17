#ifndef board_h
#define board_h

#include <cstdint>

#include "piece.h"

#define ENPASSANT 2

struct Square{
     int_least8_t row;
     int_least8_t column;
};

class boardC{

public:
     void newBoard();
     int movePiece(Square from,Square to,bool turn);
     void printboard();
     boardC();
     ~boardC();

private:
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
};

#endif
