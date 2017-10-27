#include <cstring>
#include <iostream>
#include <cmath>
#include <cassert>

#include "piece.h"
#include "board.h"


boardC::boardC()
{
     for(int i = 0;i < 8;i++)
     {
          for(int j = 0; j < 8;j++)
          {
               board[i][j] = pieces::empty;
          }
     }

     Enpassant = false;
     pawn.row = 0;
     pawn.column = 0;
}

void boardC::newBoard()
{

     for(int j = 0;j < 8;j++)
     {
          board[1][j] = pieces::white::pawn;
          board[6][j] = pieces::black::pawn;
     }

     for(int i = 0;i < 2;i++)
     {
          board[0][i * 7] = pieces::white::rook;
          board[0][1 + i * 5] = pieces::white::knight;
          board[0][2 + i * 3] = pieces::white::bishop;

          board[7][i * 7] = pieces::black::rook;
          board[7][1 + i * 5] = pieces::black::knight;
          board[7][2 + i * 3] = pieces::black::bishop;


     }

     board[0][3] = pieces::white::queen;
     board[0][4] = pieces::white::king;

     board[7][3] = pieces::black::queen;
     board[7][4] = pieces::black::king;

     for(int i = 2;i <= 5;i++)
     {
          memset(board[i],piece::empty,8);
     }

}

//bool is 0 for white
int boardC::movePiece(Square from,Square to,bool turn)
{
     //piece movement valification
     piece PFrom = board[from.row][from.column];
     //piece PTo = board[to.x][to.x];

     if(PFrom == pieces::empty)
     {
          return 1;
     }

     //determines if the right color piece
     if(turn == isWhite(PFrom))
     {
          return 1;
     }

     switch(PFrom)
     {
          case pieces::white::pawn:
          case pieces::black::pawn:
               if(validPawnMove(from,to) == false)
               {
                    return 1;
               }
               break;
          /*
          case pieces::white::rook:
          case pieces::black::rook:
               if(validLineMove(from,to) == false)
               {
                    return 1;
               }
               break;
          case pieces::white::bishop:
          case pieces::black::bishop:
               if(validDiagMove(from,to) == false)
               {
                    return 1;
               }
               break;
          case pieces::white::knight:
          case pieces::black::knight:
               if(validKnightMove(from,to) == false)
               {
                    return 1;
               }
               break;
          case pieces::white::queen:
          case pieces::black::queen:
               if((validDiagMove(from,to) == false) && (validLineMove(from,to) == false))
               {
                    return 1;
               }
               break;
          case pieces::white::king:
          case pieces::black::king:
               if(validKingMove(from,to) == false)
               {
                    return 1;
               }
               break;
               */
          default:
               std::cout << "Error with logic in move switch statement\n";
               exit(1);
     }

     board[to.row][to.column] = board[from.row][from.column];
     board[from.row][from.column] = pieces::empty;

     return 0;
}

void boardC::printboard()
{
     for(int i = 7;i >= 0;i--)
     {
          for(int j = 0;j < 8;j++)
          {
               switch(board[i][j])
               {
                    case pieces::empty : std::cout << "  ";
                         break;

                    case pieces::white::pawn : std::cout << "WP";
                         break;
                    case pieces::black::pawn : std::cout << "BP";
                         break;

                    case pieces::white::rook : std::cout << "WR";
                         break;
                    case pieces::black::rook : std::cout << "BR";
                         break;

                    case pieces::white::bishop : std::cout << "WB";
                         break;
                    case pieces::black::bishop : std::cout << "BB";
                         break;

                    case pieces::white::knight : std::cout << "WN";
                         break;
                    case pieces::black::knight : std::cout << "BN";
                         break;

                    case pieces::white::king : std::cout << "WK";
                         break;
                    case pieces::black::king : std::cout << "BK";
                         break;

                    case pieces::white::queen : std::cout << "WQ";
                         break;
                    case pieces::black::queen : std::cout << "BQ";
                         break;
               }

               std::cout << "  ";
          }
          std::cout << std::endl;
     }
}

bool boardC::validPawnMove(Square from,Square to)
{
     Square del = delta(from,to);
     int color = getColor(from);

     //can't move a pawn more then one space
     if(del.row * color > 2)
     {
          return false;
     }

     //moving two space
     if(del.row * color == 2)
     {
          //if it's at the beginning row and there isn't a piece infromt of it
          if((from.row == 1 || from.row == 6) && del.column == 0 && (from.row + color == piece::enpty))
          {
               Enpassant = true;
               pawn.row = to.row - color;
               pawn.column = to.column;

               return true;
          }
          else
          {
               return false;
          }
     }

     //if the piece just moves a single column
     if(del.row * color == 1 && del.column == 0)
     {
          return true;
     }

     if(del.row * color == 1 && abs(del.column) == 1)
     {
          if(board[to.row][to.column] != pieces::empty)
          {
               return true;
          }
          else if(Enpassant == true && to.row == pawn.row && to.column == pawn.column)
          {
               return true;
          }
          else
          {
               return false;
          }
     }

     return false;
}

int boardC::getColor(Square sq)
{
     piece p = board[sq.row][sq.column];

     assert(p != pieces::empty);

     if(isWhite(p) == true)
     {
          return 1;
     }
     else
     {
          return -1;
     }
}

Square boardC::delta(Square from,Square to)
{
     Square rtn;
     rtn.row = to.row - from.row;
     rtn.column = to.column - from.column;
     return rtn;

}

boardC::~boardC()
{

}
