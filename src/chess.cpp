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
                    status = Board.movePiece(from,to,turn);
               }
          }while(status != 0);



          turn = !turn;
     }
}

int parse(std::string str,Square* to,Square* from)
{
     std::transform(str.begin(),str.end(),str.begin(),::tolower);

     char first = str[0];
     from -> column = first - 'a';

     first = str[3];
     to -> column = first - 'a';

     from -> row = str[1] - '0';
     to -> row = str[4] - '0';

     if(!_ValidXIndex(from -> row) || !_ValidXIndex(from -> column) || !_ValidXIndex(to -> row) || !_ValidXIndex(to -> column))
     {
          return 1;
     }
     return 0;
}

bool _ValidXIndex(int x)
{
     return (x >= 0) && (x < 8);
}
