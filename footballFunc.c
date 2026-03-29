// footballFunc.c
// Name: Marcos Cisneros
// Description: Program will compile all the functions defined in the footballFunc.h

#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
   char firstName[20];
   char lastName[20];
   char schoolName[30];
   char position[5];
   char gradYear[5];
   int gamesPlayed;
   int passingAttempts;
   int passingCompletions;
   float passingPerc;
   int passingYards;
   int passingTDs;
   float qbSacks;
   int playFumb;
   int qbInt;
   float qbRating;
   int rushAtt;
   int rushYds;
   float rushAvg;
   int rushTDs;
   int recYds;
   float recAvg;
   int recTgt;
   int recCat;
   int recTDs;
   float recPerc;
   int olPan;
   int olPre;
   float olSack;
} Offense;  


typedef struct {
   char firstName[20];
   char lastName[20];
   char schoolName[5];
   char position[5];
   char gradYear[5];
   int gamesPlayed;
   int passDefl;
   int playFF;
   int playFREC;
   int playInt;
   float playSack;
   int playTOT;
   int playTklAst;
   int playTklSolo;
   int playTklLoss;
   int playTD;
} Defense;


void printOptions()
{
  printf("\n-------------------------------------\n\nOptions:\n\n");
  printf("  o: add an offensive player to the database\n");
  printf("  d: add a defensive player to the database\n");
  printf("  v: view a player from the database\n");
  printf("  t: view a team from the database\n");
  printf("  p: view a position from the database\n");
  printf("  q: quit the program\n\n");
}

int addOffense(Offense dataBaseO[100], int currentPlayer)
{
  system("clear");

  printf("Enter the first name of the player: ");
  scanf("%s", dataBaseO[currentPlayer].firstName);
  
  printf("Enter the last name of the player: ");
  scanf("%s", dataBaseO[currentPlayer].lastName);

  printf("Enter the abbreviation of the school that the player attends: ");
  scanf("%s", dataBaseO[currentPlayer].schoolName);

  printf("Enter the player's grad year (FR, SO, JR, SR, GRAD): ");
  scanf("%s", dataBaseO[currentPlayer].gradYear);

  printf("Enter the player's position (QB, HB, WR, TE, OL): ");
  scanf("%s", dataBaseO[currentPlayer].position);

  printf("Enter the number of games the player has played in: ");
  scanf("%d", &dataBaseO[currentPlayer].gamesPlayed);

  system("clear");

  printf("What you entered:\n\nName: %s %s\nSchool: %s\nGrad Year: %s\nPosition: %s\n\n", dataBaseO[currentPlayer].firstName, dataBaseO[currentPlayer].lastName, dataBaseO[currentPlayer].schoolName, dataBaseO[currentPlayer].gradYear, dataBaseO[currentPlayer].position);

  if (strcmp(dataBaseO[currentPlayer].position, "QB") == 0) 
  {
    printf("Enter the passing yards for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].passingYards);
  
    printf("Enter the passing attempts for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].passingAttempts);

    printf("Enter the passing completions for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].passingCompletions);

    printf("Enter the passing touchdowns thrown for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].passingTDs);

    printf("Enter the rushing yards for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].rushYds);

    printf("Enter the rushing attempts for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].rushAtt);
  
    dataBaseO[currentPlayer].rushAvg = (float)dataBaseO[currentPlayer].rushYds / (float)dataBaseO[currentPlayer].rushAtt;

    printf("Enter the rushing touchdowns for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].rushTDs);

    printf("Enter the interceptions thrown for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].qbInt);

    printf("Enter the number of fumbles for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].playFumb);

    printf("Enter the number of sacks for this player: ");

    int tempSack;
    scanf("%d", &tempSack);
    dataBaseO[currentPlayer].qbSacks = (float)tempSack;

    dataBaseO[currentPlayer].passingPerc = 100.0 * ((float)dataBaseO[currentPlayer].passingCompletions / (float)dataBaseO[currentPlayer].passingAttempts);

    float a = ((float)(dataBaseO[currentPlayer].passingCompletions / dataBaseO[currentPlayer].passingAttempts) - 0.3) * 5.0;
   
    float b = ((float)(dataBaseO[currentPlayer].passingYards / dataBaseO[currentPlayer].passingAttempts) - 3.0) * 0.25;

    float c = ((float)(dataBaseO[currentPlayer].passingTDs / dataBaseO[currentPlayer].passingAttempts)) * 20.0;
 
    float d = 2.375 - ((float)(dataBaseO[currentPlayer].qbInt / dataBaseO[currentPlayer].passingAttempts) * 25.0);

    dataBaseO[currentPlayer].qbRating = (a + b + c + d) / 6.0 * 100.0;

    system("clear");

    printf("\n%s %s %s %s has been added to the database!\n\n", dataBaseO[currentPlayer].schoolName, dataBaseO[currentPlayer].position, dataBaseO[currentPlayer].firstName, dataBaseO[currentPlayer].lastName);
    currentPlayer++;
  }

  else if (strcmp(dataBaseO[currentPlayer].position, "HB") == 0)
  {
    printf("Enter the rushing yards for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].rushAtt);
  
    printf("Enter the rushing attempts for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].rushYds);

    printf("Enter the rushing touchdowns for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].rushTDs);

    dataBaseO[currentPlayer].rushAvg = (float)dataBaseO[currentPlayer].rushYds / (float)dataBaseO[currentPlayer].rushAtt;

    printf("Enter the number of fumbles for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].playFumb);

    printf("Enter the receiving yards for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].recYds);

    printf("Enter the receiving targets for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].recTgt);

    printf("Enter the receiving completions for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].recCat);

    printf("Enter the receiving touchdowns for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].recTDs);

    dataBaseO[currentPlayer].recAvg = (float)dataBaseO[currentPlayer].recYds / (float)dataBaseO[currentPlayer].recCat;
    
    dataBaseO[currentPlayer].recPerc = 100.0 * ((float)dataBaseO[currentPlayer].recCat / (float)dataBaseO[currentPlayer].recTgt);

    system("clear");

    printf("\n%s %s %s %s has been added to the database!\n", dataBaseO[currentPlayer].schoolName, dataBaseO[currentPlayer].position, dataBaseO[currentPlayer].firstName, dataBaseO[currentPlayer].lastName);
    currentPlayer++;
  }

  else if (strcmp(dataBaseO[currentPlayer].position, "WR") == 0)
  {
    printf("Enter the receiving yards for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].recYds);
  
    printf("Enter the receiving targets for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].recTgt);

    printf("Enter the receiving catches for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].recCat);

    printf("Enter the receiving touchdowns for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].recTDs);
    
    printf("Enter the number of fumbles for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].playFumb);   

    printf("Enter the rushing yards for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].rushYds);

    printf("Enter the rushing attempts for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].rushAtt);

    printf("Enter the rushing touchdowns for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].rushTDs);

    dataBaseO[currentPlayer].recAvg = (float)dataBaseO[currentPlayer].recYds / (float)dataBaseO[currentPlayer].recCat;
    
    dataBaseO[currentPlayer].recPerc = 100.0 * ((float)dataBaseO[currentPlayer].recCat / (float)dataBaseO[currentPlayer].recTgt);

    dataBaseO[currentPlayer].rushAvg = (float)dataBaseO[currentPlayer].rushYds / (float)dataBaseO[currentPlayer].rushAtt;

    system("clear");

    printf("\n%s %s %s %s has been added to the database!\n\n", dataBaseO[currentPlayer].schoolName, dataBaseO[currentPlayer].position, dataBaseO[currentPlayer].firstName, dataBaseO[currentPlayer].lastName);
    currentPlayer++;
  }

  else if (strcmp(dataBaseO[currentPlayer].position, "TE") == 0)
  {
    printf("Enter the number of pancakes for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].olPan);
  
    printf("Enter the number of pressures allowed for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].olPre);

    printf("Enter the number of sacks allowed for this player: ");
    int tempSack;
    scanf("%d", &tempSack);
    dataBaseO[currentPlayer].olSack = (float)tempSack;
  
    printf("Enter the receiving yards for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].recYds);
  
    printf("Enter the receiving targets for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].recTgt);

    printf("Enter the receiving catches for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].recCat);

    printf("Enter the receiving touchdowns for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].recTDs);
    
    printf("Enter the number of fumbles for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].playFumb);  

    dataBaseO[currentPlayer].recAvg = (float)dataBaseO[currentPlayer].recYds / (float)dataBaseO[currentPlayer].recCat;
    
    dataBaseO[currentPlayer].recPerc = 100.0 * ((float)dataBaseO[currentPlayer].recCat / (float)dataBaseO[currentPlayer].recTgt);

    system("clear");

    printf("\n%s %s %s %s has been added to the database!\n\n", dataBaseO[currentPlayer].schoolName, dataBaseO[currentPlayer].position, dataBaseO[currentPlayer].firstName, dataBaseO[currentPlayer].lastName);
    currentPlayer++;
  }

  else if (strcmp(dataBaseO[currentPlayer].position, "OL") == 0)
  {
    printf("Enter the number of pancakes for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].olPan);
  
    printf("Enter the number of pressures allowed for this player: ");
    scanf("%d", &dataBaseO[currentPlayer].olPre);

    printf("Enter the number of sacks allowed for this player: ");

    int tempSack;
    scanf("%d", &tempSack);
    dataBaseO[currentPlayer].olSack = (float)tempSack;

  
    system("clear");

    printf("\n%s %s %s %s has been added to the database!\n\n", dataBaseO[currentPlayer].schoolName, dataBaseO[currentPlayer].position, dataBaseO[currentPlayer].firstName, dataBaseO[currentPlayer].lastName);
    currentPlayer++;
  }

  else
  {
    system("clear");
    printf("Error: Invalid position.\n");
  }

  return currentPlayer;

}

int addDefense(Defense dataBaseD[100], int currentPlayer)
{
  system("clear");

  printf("Enter the first name of the player: ");
  scanf("%s", dataBaseD[currentPlayer].firstName);
  
  printf("Enter the last name of the player: ");
  scanf("%s", dataBaseD[currentPlayer].lastName);

  printf("Enter the abbreviation of the school that the player attends: ");
  scanf("%s", dataBaseD[currentPlayer].schoolName);

  printf("Enter the player's grad year (FR, SO, JR, SR, GRAD): ");
  scanf("%s", dataBaseD[currentPlayer].gradYear);

  printf("Enter the player's position (DL, LB, CB, S): ");
  scanf("%s", dataBaseD[currentPlayer].position);

  printf("Enter the number of games the player has played in: ");
  scanf("%d", &dataBaseD[currentPlayer].gamesPlayed);
  
  system("clear");

  printf("What you entered:\n\nName: %s %s\nSchool: %s\nGrad Year: %s\nPosition: %s\n\n", dataBaseD[currentPlayer].firstName, dataBaseD[currentPlayer].lastName, dataBaseD[currentPlayer].schoolName, dataBaseD[currentPlayer].gradYear, dataBaseD[currentPlayer].position);

   
  if ((strcmp(dataBaseD[currentPlayer].position, "DL") == 0) || 
  (strcmp(dataBaseD[currentPlayer].position, "LB") == 0) || 
  (strcmp(dataBaseD[currentPlayer].position, "CB") == 0) || 
  (strcmp(dataBaseD[currentPlayer].position, "S") == 0))
  {
    printf("Enter the total number of tackles for this player: ");
    scanf("%d", &dataBaseD[currentPlayer].playTOT);
  
    printf("Enter the number of solo tackles from that total number: ");
    scanf("%d", &dataBaseD[currentPlayer].playTklSolo);

    printf("Enter the number of assisted tackles from that total number: ");
    scanf("%d", &dataBaseD[currentPlayer].playTklAst);
  
    printf("Enter the number of tackles for loss from that total number: ");
    scanf("%d", &dataBaseD[currentPlayer].playTklLoss);

    printf("Enter the number of sacks for this player: ");
    scanf("%d", &dataBaseD[currentPlayer].playSack);

    printf("Enter the number of pass deflections for this player: ");
    scanf("%d", &dataBaseD[currentPlayer].passDefl);

    printf("Enter the number of forced fumbles for this player: ");
    scanf("%d", &dataBaseD[currentPlayer].playFF);

    printf("Enter the number of recovered fumbles for this player: ");
    scanf("%d", &dataBaseD[currentPlayer].playFREC);

    printf("Enter the number of interceptions for this player: ");
    scanf("%d", &dataBaseD[currentPlayer].playInt);

    printf("Enter the number of defensive touchdowns for this player: ");
    scanf("%d", &dataBaseD[currentPlayer].playTD);

    system("clear");

    printf("\n%s %s %s %s has been added to the database!\n\n", dataBaseD[currentPlayer].schoolName, dataBaseD[currentPlayer].position, dataBaseD[currentPlayer].firstName, dataBaseD[currentPlayer].lastName);
    currentPlayer++;
  }

  else
  {
    system("clear");
    printf("Error: Invalid position.\n");
  }

  return currentPlayer;

}

void viewPlayerOffensive(Offense dataBaseO[100], int numPlayersO)
{
  printf("Enter the player's first name: ");
  char userFirst[20];
  scanf("%s", userFirst);

  printf("Enter the player's last name: ");
  char userLast[20];
  scanf("%s", userLast);

  printf("Enter the abbreviation of the school that the player attends: ");
  char userSchool[5];
  scanf("%s", userSchool);

  printf("Enter the offensive position that the player plays (QB, WR, HB, TE, OL): ");
  char userPos[5];
  scanf("%s", userPos);

  printf("Enter the grad year of the player (FR, SO, JR, SR, GRAD): ");
  char userGrad[5];
  scanf("%s", userGrad);

  int isFound = 0;
  
  for (int i = 0; i < numPlayersO; i++)
  {
    if ((strcmp((userFirst), (dataBaseO[i].firstName)) == 0) && 
    (strcmp((userLast), (dataBaseO[i].lastName)) == 0) &&
    (strcmp((userSchool), (dataBaseO[i].schoolName)) == 0) &&
    (strcmp((userPos), (dataBaseO[i].position)) == 0) && 
    (strcmp((userGrad), (dataBaseO[i].gradYear)) == 0))
    {
      system("clear");
      printf("Player found!\n\nName: %s %s\nSchool: %s\nPosition: %s\nGrad year: %s\n\nStats\n\n", userFirst, userLast, userSchool, userPos, userGrad);
 
      isFound = 1;

      printOffensivePlayer(dataBaseO, i);

      break;

    }
  }
  
  if (isFound == 0)
  {
    system("clear");
    printf("Error: Player not found.");
  }

}

void viewPlayerDefensive(Defense dataBaseD[100], int numPlayersD)
{
  printf("Enter the player's first name: ");
  char userFirst[20];
  scanf("%s", userFirst);

  printf("Enter the player's last name: ");
  char userLast[20];
  scanf("%s", userLast);

  printf("Enter the abbreviation of the school that the player attends: ");
  char userSchool[5];
  scanf("%s", userSchool);

  printf("Enter the defensive position that the player plays (DL, LB, CB, S): ");
  char userPos[5];
  scanf("%s", userPos);

  printf("Enter the grad year of the player (FR, SO, JR, SR, GRAD): ");
  char userGrad[5];
  scanf("%s", userGrad);

  int isFound = 0;
  
  for (int i = 0; i < numPlayersD; i++)
  {
    if ((strcmp((userFirst), (dataBaseD[i].firstName)) == 0) && 
    (strcmp((userLast), (dataBaseD[i].lastName)) == 0) &&
    (strcmp((userSchool), (dataBaseD[i].schoolName)) == 0) &&
    (strcmp((userPos), (dataBaseD[i].position)) == 0) && 
    (strcmp((userGrad), (dataBaseD[i].gradYear)) == 0))
    {
      system("clear");
      printf("Player found!\n\nName: %s %s\nSchool: %s\nPosition: %s\nGrad year: %s\n\nStats\n\n", userFirst, userLast, userSchool, userPos, userGrad);
 
      isFound = 1;
   
      printf(" _____________________________________________________________________________________________________________________________________\n");
      printDefensivePlayer(dataBaseD, i);
 
      break;
    }
  }
  
  if (isFound == 0)
  {
    system("clear");
    printf("Error: Player not found.");
  }
}

void printOffensivePlayer(Offense dataBaseO[100], int i)
{ 
  char firstIn = dataBaseO[i].firstName[0];
  char lastIn = dataBaseO[i].lastName[0];

  if(strcmp(dataBaseO[i].position, "QB") == 0)
  {
    printf(" __________________________________________________________________________________________________________________________________________________________\n");

    printf("| INIT. | POS | SCHOOL | YEAR | PASS YDS | PASS ATT | PASS CMP | PASS CMP % | PASS TDS | RUSH ATT | RUSH YDS | RUSH AVG | RUSH TDS | INT | SACK | FUM | GP |\n");  
       
    printf("| %c%c    | %-3s | %-6s | %-4s | %-8d | %-8d | %-8d | %-10.1f | %-8d | %-8d | %-8d | %-8.1f | %-8d | %-3d | %-4.1f | %-3d | %-2d |\n", firstIn, lastIn, dataBaseO[i].position, dataBaseO[i].schoolName, dataBaseO[i].gradYear, dataBaseO[i].passingYards, dataBaseO[i].passingAttempts, dataBaseO[i].passingCompletions, dataBaseO[i].passingPerc, dataBaseO[i].passingTDs, dataBaseO[i].rushAtt, dataBaseO[i].rushYds, dataBaseO[i].rushAvg, dataBaseO[i].rushTDs, dataBaseO[i].qbInt, dataBaseO[i].qbSacks, dataBaseO[i].playFumb, dataBaseO[i].gamesPlayed);   
  }
   

  else if(strcmp(dataBaseO[i].position, "HB") == 0)
  {
    printf(" _______________________________________________________________________________________________________________________________________________\n");
   
    printf("| INIT. | POS | SCHOOL | YEAR | RUSH YDS | RUSH ATT | RUSH AVG | RUSH TDS | REC YDS | REC TGTS | REC CMP | REC % | REC AVG | REC TDS | FUM | GP |\n");  
       
    printf("| %c%c    | %-3s | %-6s | %-4s | %-8d | %-8d | %-8.1f | %-8d | %-7d | %-8d | %-7d | %-4.1f% | %-7.1f | %-7d | %-3d | %-2d |\n", firstIn, lastIn, dataBaseO[i].position, dataBaseO[i].schoolName, dataBaseO[i].gradYear, dataBaseO[i].rushYds, dataBaseO[i].rushAtt, dataBaseO[i].rushAvg, dataBaseO[i].rushTDs, dataBaseO[i].recYds, dataBaseO[i].recTgt, dataBaseO[i].recCat, dataBaseO[i].recPerc, dataBaseO[i].recAvg, dataBaseO[i].recTDs, dataBaseO[i].playFumb, dataBaseO[i].gamesPlayed);   
  }
   
  
  else if(strcmp(dataBaseO[i].position, "WR") == 0)
  {
    printf(" _______________________________________________________________________________________________________________________________________________\n");

    printf("| INIT. | POS | SCHOOL | YEAR | REC YDS | REC TGTS | REC CMP | REC % | REC AVG | REC TDS | RUSH YDS | RUSH ATT | RUSH AVG | RUSH TDS | FUM | GP |\n");  
       
    printf("| %c%c    | %-3s | %-6s | %-4s | %-7d | %-8d | %-7d | %-4.1f% | %-7.1f | %-7d | %-8d | %-8d | %-8.1f | %-8d | %-3d | %-2d |\n", firstIn, lastIn, dataBaseO[i].position, dataBaseO[i].schoolName, dataBaseO[i].gradYear, dataBaseO[i].recYds, dataBaseO[i].recTgt, dataBaseO[i].recCat, dataBaseO[i].recPerc, dataBaseO[i].recAvg, dataBaseO[i].recTDs, dataBaseO[i].rushYds, dataBaseO[i].rushAtt, dataBaseO[i].rushAvg, dataBaseO[i].rushTDs, dataBaseO[i].playFumb, dataBaseO[i].gamesPlayed);   
  }
  
  else if(strcmp(dataBaseO[i].position, "TE") == 0)
  {
    printf(" ____________________________________________________________________________________________________________________\n");

    printf("| INIT. | POS | SCHOOL | YEAR | PC | PA | SACK | REC YDS | REC TGTS | REC CMP | REC % | REC AVG | REC TDS | FUM | GP |\n");  
       
    printf("| %c%c    | %-3s | %-6s | %-4s | %-2d | %-2d | %-3.1f | %-7d | %-8d | %-7d | %-4.1f | %-7.1f | %-7d | %-3d | %-2d |\n", firstIn, lastIn, dataBaseO[i].position, dataBaseO[i].schoolName, dataBaseO[i].gradYear, dataBaseO[i].olPan, dataBaseO[i].olPre, dataBaseO[i].olSack, dataBaseO[i].recYds, dataBaseO[i].recTgt, dataBaseO[i].recCat, dataBaseO[i].recPerc, dataBaseO[i].recAvg, dataBaseO[i].recTDs, dataBaseO[i].playFumb, dataBaseO[i].gamesPlayed);   
  }
   
  else if(strcmp(dataBaseO[i].position, "OL") == 0)
  {
    printf(" ___________________________________________________\n");

    printf("| INIT. | POS | SCHOOL | YEAR | PC | PA | SACK | GP |\n");  
       
    printf("| %c%c    | %-3s | %-6s | %-4s | %-2d | %-2d | %-3.1f | %-2d |\n", firstIn, lastIn, dataBaseO[i].position, dataBaseO[i].schoolName, dataBaseO[i].gradYear, dataBaseO[i].olPan, dataBaseO[i].olPre, dataBaseO[i].olSack, dataBaseO[i].gamesPlayed);   
  }
     

}

void printDefensivePlayer(Defense dataBaseD[100], int i)
{  
  printf(" ______________________________________________________________________________________________\n");

  printf("| INIT. | POS | SCHOOL | YEAR | TKLS | SOLO | AST | TFL | SACK | PD | INT | FF | REC | TD | GP |\n");  
       
  printf("| %c%c    | %-3s | %-6s | %-4s | %-4d | %-4d | %-3d | %-3d | %-4.1f | %-2d | %-3d | %-2d | %-3d | %-2d | %-2d |\n", dataBaseD[i].firstName, dataBaseD[i].lastName, dataBaseD[i].position, dataBaseD[i].schoolName, dataBaseD[i].gradYear, dataBaseD[i].playTOT, dataBaseD[i].playTklSolo, dataBaseD[i].playTklAst, dataBaseD[i].playTklLoss, dataBaseD[i].playSack, dataBaseD[i].passDefl, dataBaseD[i].playInt, dataBaseD[i].playFF, dataBaseD[i].playFREC, dataBaseD[i].playTD, dataBaseD[i].gamesPlayed);   

     

}

void printQBheader()
{
  printf(" __________________________________________________________________________________________________________________________________________________________\n");

  printf("| INIT. | POS | SCHOOL | YEAR | PASS YDS | PASS ATT | PASS CMP | PASS CMP % | PASS TDS | RUSH ATT | RUSH YDS | RUSH AVG | RUSH TDS | INT | SACK | FUM | GP |\n");  

}

void printSkillHeader()
{
    printf(" _______________________________________________________________________________________________________________________________________________\n");

    printf("| INIT. | POS | SCHOOL | YEAR | REC YDS | REC TGTS | REC CMP | REC % | REC AVG | REC TDS | RUSH YDS | RUSH ATT | RUSH AVG | RUSH TDS | FUM | GP |\n");  
 

}

void printLineHeader()
{
  printf(" ___________________________________________________\n");

  printf("| INIT. | POS | SCHOOL | YEAR | PC | PA | SACK | GP |\n");  
}

void printDefenseHeader()
{
  printf(" ______________________________________________________________________________________________\n");

  printf("| INIT. | POS | SCHOOL | YEAR | TKLS | SOLO | AST | TFL | SACK | PD | INT | FF | REC | TD | GP |\n");  
}

void printQBstats(Offense dataBaseO[100], int i)
{
  char firstIn = dataBaseO[i].firstName[0];
  char lastIn = dataBaseO[i].lastName[0];

  printf("| %c%c    | %-3s | %-6s | %-4s | %-8d | %-8d | %-8d | %-10.1f | %-8d | %-8d | %-8d | %-8.1f | %-8d | %-3d | %-4.1f | %-3d | %-2d |\n", firstIn, lastIn, dataBaseO[i].position, dataBaseO[i].schoolName, dataBaseO[i].gradYear, dataBaseO[i].passingYards, dataBaseO[i].passingAttempts, dataBaseO[i].passingCompletions, dataBaseO[i].passingPerc, dataBaseO[i].passingTDs, dataBaseO[i].rushAtt, dataBaseO[i].rushYds, dataBaseO[i].rushAvg, dataBaseO[i].rushTDs, dataBaseO[i].qbInt, dataBaseO[i].qbSacks, dataBaseO[i].playFumb, dataBaseO[i].gamesPlayed);  

}

void printSkillStats(Offense dataBaseO[100], int i)
{
  char firstIn = dataBaseO[i].firstName[0];
  char lastIn = dataBaseO[i].lastName[0];

  printf("| %c%c    | %-3s | %-6s | %-4s | %-7d | %-8d | %-7d | %-4.1f% | %-7.1f | %-7d | %-8d | %-8d | %-8.1f | %-8d | %-3d | %-2d |\n", firstIn, lastIn, dataBaseO[i].position, dataBaseO[i].schoolName, dataBaseO[i].gradYear, dataBaseO[i].recYds, dataBaseO[i].recTgt, dataBaseO[i].recCat, dataBaseO[i].recPerc, dataBaseO[i].recAvg, dataBaseO[i].recTDs, dataBaseO[i].rushYds, dataBaseO[i].rushAtt, dataBaseO[i].rushAvg, dataBaseO[i].rushTDs, dataBaseO[i].playFumb, dataBaseO[i].gamesPlayed);   

}
 

void printLineStats(Offense dataBaseO[100], int i)
{ 
  char firstIn = dataBaseO[i].firstName[0];
  char lastIn = dataBaseO[i].lastName[0];

  printf("| %c%c    | %-3s | %-6s | %-4s | %-2d | %-2d | %-3.1f | %-2d |\n", firstIn, lastIn, dataBaseO[i].position, dataBaseO[i].schoolName, dataBaseO[i].gradYear, dataBaseO[i].olPan, dataBaseO[i].olPre, dataBaseO[i].olSack, dataBaseO[i].gamesPlayed);   

}

void printDefStats(Defense dataBaseD[100], int i)
{
  char firstIn = dataBaseD[i].firstName[0];
  char lastIn = dataBaseD[i].lastName[0];

  printf("| %c%c    | %-3s | %-6s | %-4s | %-4d | %-4d | %-3d | %-3d | %-4.1f | %-2d | %-3d | %-2d | %-3d | %-2d | %-2d |\n", dataBaseD[i].firstName, dataBaseD[i].lastName, dataBaseD[i].position, dataBaseD[i].schoolName, dataBaseD[i].gradYear, dataBaseD[i].playTOT, dataBaseD[i].playTklSolo, dataBaseD[i].playTklAst, dataBaseD[i].playTklLoss, dataBaseD[i].playSack, dataBaseD[i].passDefl, dataBaseD[i].playInt, dataBaseD[i].playFF, dataBaseD[i].playFREC, dataBaseD[i].playTD, dataBaseD[i].gamesPlayed); 

}

void toLowerString(char str[20])
{
  for (int i = 0; i < strlen(str); i++)
  {
    str[i] = tolower(str[i]);
  }

}

void toUpperString(char str[20])
{
  for (int i = 0; i < strlen(str); i++)
  {
    str[i] = toupper(str[i]);
  }
}

void viewTeam(Offense dataBaseO[100], Defense dataBaseD[100], int offSize, int defSize)
{
  printf("Enter the abbreviation of the team you would like to view: ");
  
  char teamName[5];

  scanf("%s", teamName);

  toUpperString(teamName);

  int isTeamFound = 0;
  int isPosFound = 0;
 
  system("clear");

  for (int i = 0; i < offSize; i++)
  {
    if(strcmp(teamName, dataBaseO[i].schoolName) == 0)
    {
      if (isTeamFound == 0)
      {
        isTeamFound = 1;
        printf("Team found!\n\n");
      }
 
      if(strcmp(dataBaseO[i].position, "QB") == 0)
      {
        if (isPosFound == 0)
        {
          isPosFound = 1;
          printf("Quarterbacks\n");
          printQBheader();
        }
        printQBstats(dataBaseO, i);
      }
    }
    if(i == (offSize - 1) && isPosFound == 1)
    {
      printf("\n");
    }   
  }

  isPosFound = 0;
  
  for (int i = 0; i < offSize; i++)
  {
    if(strcmp(teamName, dataBaseO[i].schoolName) == 0)
    {
      if (isTeamFound == 0)
      {
        isTeamFound = 1;
        printf("Team found!\n\n");
      }
 
      if((strcmp(dataBaseO[i].position, "HB") == 0) || (strcmp(dataBaseO[i].position, "WR") == 0) || (strcmp(dataBaseO[i].position, "TE") == 0))
      {
        if (isPosFound == 0)
        {
          isPosFound = 1;
          printf("Skilled Players\n"); 
          printSkillHeader();
        }
        printSkillStats(dataBaseO, i);
      }
    }
    if(i == (offSize - 1) && isPosFound == 1)
    {
      printf("\n");
    }
  }

  isPosFound = 0;

  for (int i = 0; i < offSize; i++)
  {
    if(strcmp(teamName, dataBaseO[i].schoolName) == 0)
    {
      if (isTeamFound == 0)
      {
        isTeamFound = 1;
        printf("Team found!\n\n");
      }
 
      if((strcmp(dataBaseO[i].position, "OL") == 0) || (strcmp(dataBaseO[i].position, "TE") == 0))
      {
        if (isPosFound == 0)
        {
          isPosFound = 1;
          printf("Lineman\n"); 
          printLineHeader();
        }
        printLineStats(dataBaseO, i);
      }
    }
    if(i == (offSize - 1) && isPosFound == 1)
    {
      printf("\n");
    }  
  }

  isPosFound = 0;

  for (int i = 0; i < defSize; i++)
  {
    if((strcmp(teamName, dataBaseO[i].schoolName) == 0))
    {
      if (isTeamFound == 0)
      {
        isTeamFound = 1;
        printf("Team found!\n\n");
      }
 
      if((strcmp(dataBaseD[i].position, "DL") == 0) || (strcmp(dataBaseD[i].position, "LB") == 0) || (strcmp(dataBaseD[i].position, "CB") == 0) || (strcmp(dataBaseD[i].position, "S") == 0))

      {
        if (isPosFound == 0)
        {
          isPosFound = 1;
          printf("Defense\n"); 
          printDefenseHeader();
        }
        printDefStats(dataBaseO, i);
      }
    }
    if(i == (defSize - 1) && isPosFound == 1)
    {
      printf("\n");
    }  
  }

}












   
  
