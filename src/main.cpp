#include <iostream>

#include "chess.h"

//project to implement an command line chess program, then eventually make
//a chess ai based on this

int main(void)
{
     while(true)
     {
          std::cout << "what do you want to do?" << std::endl;
          std::cout << "1:start a new game" << std::endl;
          std::cout << "2:exit" << std::endl;

          char answer;
          std::cin >> answer;
          if(answer == '1')
          {
               newgame();
          }
          else if (answer == '2')
          {
               return 0;
          }
          else
          {
               std::cout << "not a valid answer" << std::endl;
          }

     }
}
