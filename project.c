// project.c
// Name: Marcos Cisneros
// Description: Program will compile all the functions provided in order to run the program in its designated order. Program overall will allow the user to compute football stats and analysis as needed with the user's inputted players.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "footballFunc.h"

int main(int argc, char *argv[])
{
  printf("\nAmerican Football Analytics Program");

  int currentOffense = 0; 
  int currentDefense = 0;

  int maxSize = 100;
  
  Offense dataBaseO[maxSize];
  Defense dataBaseD[maxSize];

  system("clear");

  if (argc == 1)
  {
    while(1)
    {
      printOptions(); // display options
  
      char userOption[5];
      printf("Enter your option: ");
      scanf("%s", userOption);

      toLowerString(userOption);
      
      if((strcmp(userOption, "o")) == 0)
      {
        system("clear");
        currentOffense = addOffense(dataBaseO, currentOffense);
      }
     
      else if(strcmp(userOption, "d") == 0)
      {
        system("clear");
        currentDefense = addDefense(dataBaseD, currentDefense);
      }

      else if(strcmp(userOption, "v") == 0)
      {
        system("clear");
 
        printf("Enter the side of the ball that the player plays (OFF or DEF): ");
 
        char userSide[5];
        scanf("%s", userSide);

        toLowerString(userSide);
  
        if(strcmp(userSide, "off") == 0)
        {
          viewPlayerOffensive(dataBaseO, currentOffense);
        }
        else if(strcmp(userSide, "def") == 0)
        {
          viewPlayerDefensive(dataBaseD, currentDefense);
        }
        else
        {
          printf("Error: Invalid input for side of the ball for player.\n");
        }
      }

      else if(strcmp(userOption, "t") == 0)
      {
        viewTeam(dataBaseO, dataBaseD, currentOffense, currentDefense);
        system("clear");
      }
  
      else if(strcmp(userOption, "p") == 0)    
      {
        system("clear");
      }

      else if(strcmp(userOption, "q") == 0)
      {
        break;
      }
  
      else
      {
        printf("Error: Invalid option. Please enter a correct option.\n"); 
      }

    }
 
    printf("Football Analytics Program has been exited out of. Goodbye!\n"); 
 
  }
  
  else if (argc == 2)
  { 

  }

  else
  {
    printf("Error: Too many arguments.\n");
  }
  
  return 0;

}
 
  
