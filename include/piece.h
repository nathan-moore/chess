#ifndef piece_h
#define piece_h

enum piece{
     empty = -1,
     wpawn = 1,
     bpawn = 11,
     wknight = 2,
     bknight = 12,
     wbishop = 3,
     bbishop = 13,
     wqueen = 4,
     bqueen = 14,
     wking = 5,
     bking = 15,
     wrook = 6,
     brook = 16
};

class pieces{
public:
     const static piece empty = empty;
     class white{
     public:
          const static piece pawn = wpawn;
          const static piece rook = wrook;
          const static piece bishop = wbishop;
          const static piece knight = wknight;
          const static piece king = wking;
          const static piece queen = wqueen;
     };

     class black{
     public:
          const static piece pawn = bpawn;
          const static piece rook = brook;
          const static piece bishop = bbishop;
          const static piece knight = bknight;
          const static piece king = bking;
          const static piece queen = bqueen;
     };
};

bool isWhite(piece);
bool isBlack(piece);

#endif
