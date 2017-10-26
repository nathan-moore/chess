#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "board.h"

int parse(std::string str,Square* to,Square* from);
bool _ValidXIndex(int x);

void newgame()
{
     boardC Board;
     Board.newBoard();

     //0 for white's turn
     //1 for black
     bool turn = 0;

     while(true)
     {
          std::string turn_name[] = {"white","black"};

          Board.printboard();

          std::cout << "It is currently " << turn_name[(unsigned int)turn] << "\'s turn" << std::endl;

          std::string input;
          Square to;
          Square from;
          int status;

          do{
               std::getline(std::cin,input);
               status = parse(input,&to,&from);

               if(status == 0)
               {
                    status = Board.movePiece(from,to);
               }
          }while(status != 0);

          std::cout << "I got here" << std::endl;

          turn = !turn;
     }
}

int parse(std::string str,Square* to,Square* from)
{
     std::transform(str.begin(),str.end(),str.begin(),::tolower);

     char first = str[0];
     from -> x = first - 'a';

     first = str[3];
     to -> x = first - 'a';

     from -> y = str[1] - '0';
     to -> y = str[4] - '0';

     if(!_ValidXIndex(from -> x) || !_ValidXIndex(from -> y) || !_ValidXIndex(to -> x) || !_ValidXIndex(to -> y))
     {
          return 1;
     }
     return 0;
}

bool _ValidXIndex(int x)
{
     return (x >= 0) && (x < 8);
}
