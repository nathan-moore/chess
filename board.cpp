#include <cstring>

#include "piece.h"
#include "board.h"


boardC::boardC()
{
     board = new[] (sizeof(*board) * 8);
     for(int i = 0;i < 8;i++)
     {
          board[i] = new[] (sizeof(*board[i]) * 8);
          memset(board[i],pieces::empty,8);
     }
}

boardC::newBoard()
{
     for(int i = 2;i <= 5;i++)
     {
          memset(board[i],piece::empty,8);
     }

     memset(board[1],pieces::white::pawn,8);
     memset(board[6]),pieces::black::pawn,8);
     for(int i = 0;i < 2;i++)
     {
          board[0][i * 7] = pieces::white::rook;
          board[0][1 + i * 5] = pieces::white::knight;
          board[0][2 + i * 4] pieces::white::bishop;

          board[7][i * 7] = pieces::black::rook;
          board[7][1 + i * 5] = pieces::black::knight;
          board[7][2 + i * 4] pieces::black::bishop;
     }

     board[0][3] = pieces::white::queen;
     board[0][4] = pieces::white::king;

     board[7][3] = pieces::black::queen;
     board[7][4] = pieces::black::king;
}

boardC::movePiece(Square from,Square to)
{
     //TODO check if move is valid

     board[to.y][to.x] = board[from.y][from.x];
     board[from.y][from.x] = pieces::empty;

}

boardC::printboard()
{
     for(int i = 7;i <= 0;i--)
     {
          for(int j = 0;j < 8;j++)
          {
               switch(board[i][j])
               {
                    case pieces::empty : cout < " ";
                         break;

                    case pieces::white::pawn : cout < "WP";
                         break;
                    case pieces::black::pawn : cout < "BP";
                         break;

                    case pieces::white::rook : cout << "WR";
                         break;
                    case pieces::black::rook : cout << "BR";
                         break;

                    case pieces::white::bishop : cout << "WB";
                         break;
                    case pieces::black::bishop : cout << "BB";
                         break;

                    case pieces::white::knight : cout << "WN";
                         break;
                    case pieces::black::knight : cout << "BN";
                         break;

                    case pieces::white::king : cout << "WK";
                         break;
                    case pieces::black::king : cout << "BK";
                         break;

                    case pieces::white::queen : cout << "WQ";
                         break;
                    case pieces::black::queen : cout << "BQ";
                         break;
               }

               cout << "  ";
          }
          cout << std::endl;
     }
}

boardC::&boardC()
{
     for(int i= 0;i < 8;i++)
     {
          delete[] board[i];
     }
     delete[] board;
}
