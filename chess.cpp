#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "board.h"

int parse(std::string str,Square* to,Square* from);
bool cmp(int x);

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

          std::string input;
          Square to;
          Square from;
          int status;

          do{
               std::string temp;
               std::getline(std::cin,temp);
               std::getline(std::cin,input);

               status = parse(input,&to,&from);
          }while(status != 0);

          std::cout << "I got here" << std::endl;
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

     if(cmp(from -> x) || cmp(from -> y) || cmp(to -> x) || cmp(to -> y))
     {
          return 1;
     }
     return 0;
}

bool cmp(int x)
{
     return (x > 0) && (x < 8);
}
