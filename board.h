#ifndef board_h
#define board_h

#include <cstdint>

struct Square{
     uint_least8_t x;
     uint_least8_t y;
};

class boardC{
public:
     newBoard();
     movePiece(Square from,Square to);
     printboard();
     boardC();

private:
     piece** board;
};

#endif
