#include <cstring>
#include <iostream>

#include "piece.h"
#include "board.h"


boardC::boardC()
{
     board = new piece*[8];
     for(int i = 0;i < 8;i++)
     {
          board[i] = new piece[8];
          memset(board[i],pieces::empty,8);
     }
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

void boardC::movePiece(Square from,Square to)
{
     //TODO check if move is valid

     board[to.y][to.x] = board[from.y][from.x];
     board[from.y][from.x] = pieces::empty;

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

boardC::~boardC()
{
     for(int i= 0;i < 8;i++)
     {
          delete[] board[i];
     }
     delete[] board;
}
