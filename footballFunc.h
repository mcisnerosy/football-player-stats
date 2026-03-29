// footballFunc.h
// Name: Marcos Cisneros
// Description: Program contains all the definintions of the functions that will be used

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

void printOptions();
int addOffense(Offense dataBaseO[], int currentPlayer);
int addDefense(Defense dataBaseD[], int currentPlayer);
void viewPlayerOffensive(Offense dataBaseO[100], int numPlayersO);
void viewPlayerDefensive(Defense dataBaseD[100], int numPlayersD);
void printOffensivePlayer(Offense dataBaseO[100], int i);
void printDefensivePlayer(Defense dataBaseD[100], int i);
void toLowerString(char str[20]);
void toUpperString(char str[20]);
void printQBheader();
void printSkillHeader();
void printLineHeader();
void printDefenseHeader();
void printQBstats(Offense dataBaseO[100], int i);
void printSkillStats(Offense dataBaseO[100], int i);
void printLineStats(Offense dataBaseO[100], int i);
void printDefStats(Defense dataBaseD[100], int i);


