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
     void movePiece(Square from,Square to);
     void printboard();
     boardC();
     ~boardC();

private:
     piece** board;
};

#endif
