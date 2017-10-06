#ifndef piece_h
#define piece_h

enum piece{
     empty,
     wpawn,
     bpawn,
     wknight,
     bknight,
     wbishop,
     bbishop,
     wqueen,
     bqueen,
     wking,
     bking,
     wrook,
     brook
};

class pieces{
public:
     const static piece empty = empty;
     class white{
          const static piece pawn = wpawn;
          const static piece rook = wrook;
          const static piece bishop = wbishop;
          const static piece knight = wknight;
          const static piece king = wking;
          const static piece queen = wqueen;
     };

     class black{
          const static piece pawn = bpawn;
          const static piece rook = brook;
          const static piece bishop = bbishop;
          const static piece knight = bknight;
          const static piece king = bking;
          const static piece queen = bqueen;
     };
};

#endif
