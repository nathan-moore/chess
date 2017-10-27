#ifndef board_h
#define board_h

#include <cstdint>

#include "piece.h"

struct Square{
     uint_least8_t x;
     uint_least8_t y;
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
     bool Enpassant;
     Square pawn;

     bool validPawnMove(Square from,Square to);
     bool validLineMove(Square from,Square to);
     bool validDiagMove(Square from,Square to);
     bool validKnightMove(Square from,Square to);
     bool validKingMove(Square from, Square to);

     Square delta(Square from,Square to);
     int getColar(Square);
};

#endif
