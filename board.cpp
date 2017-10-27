#include <cstring>
#include <iostream>

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
     pawn.x = 0;
     pawn.y - 0;
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
     piece PFrom = board[from.x][from.y];
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
          default:
               std::cout << "Error with logic in move switch statement\n";
               exit(1);
     }

     board[to.y][to.x] = board[from.y][from.x];
     board[from.y][from.x] = pieces::empty;

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
                    case pieces::empty : std::cout << " ";
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
     if(del.x * color > 2)
     {
          return false;
     }

     if(del.x * color = 2)
     {
          if((rom.x == 1 || from.x == 6) && del.y == 0)
          {
               return true;
          }
          else
          {
               return false;
          }
     }

     //TODO check taking a piece


}

boardC::~boardC()
{

}
