#include <iostream>

newgame()
{
     board Board;
     Board::newgame();

     //0 for white's turn
     //1 for black
     bool turn = 0;

     while(true)
     {
          string turn_name;
          if(!turn)
          {
               turn_name = "white";
          }
          else
          {
               turn_name = "black";
          }

          Board::printboard();

          cout << "It is currently " << turn_name << "\'s turn" << std::endl;
     }
}
