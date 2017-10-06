#include <iostream>
#include <string>

#include "board.h"

void newgame()
{
     boardC Board;
     Board.newBoard();

     //0 for white's turn
     //1 for black
     bool turn = 0;
     int input;

     while(true)
     {
          std::string turn_name;
          if(!turn)
          {
               turn_name = "white";
          }
          else
          {
               turn_name = "black";
          }

          Board.printboard();

          std::cout << "It is currently " << turn_name << "\'s turn" << std::endl;
          std::cin >> input;
          return;
     }
}
