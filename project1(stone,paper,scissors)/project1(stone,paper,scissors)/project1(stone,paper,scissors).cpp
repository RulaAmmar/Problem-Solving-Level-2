

#include <iostream>
#include<cstdlib>
using namespace std;

enum enGameChoice {
    Stone=1,Paper=2,Scissors=3
};

enum enWinner
{
Player1=1,Computer=2,Draw=3
};

short ReadHowManyRound() {

    short GameRoundsNumber=1;

    do {
        cout<<"How Many Rounds 1 to 10 ?\n";
        cin >> GameRoundsNumber;
    } while (GameRoundsNumber<1||GameRoundsNumber>10);

    return GameRoundsNumber;
}

enGameChoice ReadPlayer1Choice() {

    short Choice;

    do {
        cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ?";
        cin >> Choice;
    } while (Choice<1||Choice>3);

    return (enGameChoice)Choice;
}

int RandomNumber(int From,int To) {

    int RandNum = rand() % (To - From + 1) + From;

    return RandNum;
}

enGameChoice GetComputerChoice() {

    return (enGameChoice)RandomNumber(1, 3);
}

struct strRoundInfo
{
    short RoundNumber;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner RoundWinner;
};

struct strGameResult
{
    short HowManyRounds;
    short Player1WinTimes=0;
    short ComputerWinTimes=0;
    short DrawTimes=0;
    enWinner GameWinner;
};

enWinner WhoWinTheRound(enGameChoice Player1Choice,enGameChoice ComputerChoice) {
    if (Player1Choice == ComputerChoice)
        return Draw;
    switch (Player1Choice) {
    case Stone:
        if (ComputerChoice == Scissors) {
            return Player1;
        }
    case Paper:
        if (ComputerChoice == Stone) {
            return Player1;
        }
    case Scissors:
        if (ComputerChoice == Paper) {
            return Player1;
        }
    }
    return Computer;
}

string ChoiceName(enGameChoice Choice) {

    string arrGameChoices[3] = {"Stone", "Paper", "Scissor"};

    return arrGameChoices[Choice-1];
}

string WinnerName(enWinner Winner) {
    string arrWinnerName[3] = { "Plaer1","Computer","No Winner" };

    return arrWinnerName[Winner - 1];
}

void SetWinnerScreenColor(enWinner Winner) {

    switch (Winner) {
    case Player1:
        system("color 2F");
        break;
    case Computer:
        system("color 4F");
        cout << "\a";
        break;
    default:
        system("color 6F");
        break;
    }
}

void PrintRoundResult(strRoundInfo RoundInfo) {

    cout << "\n________Round [" << RoundInfo.RoundNumber << "]_______________________________\n\n";

    cout << "Player1 Choice: " << ChoiceName( RoundInfo.Player1Choice) << endl;

    cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;

    cout << "Round Winner : [" << WinnerName(RoundInfo.RoundWinner)<<"]" << endl;

    cout << "_________________________________________________\n" << endl;

    SetWinnerScreenColor(RoundInfo.RoundWinner);
}

enWinner WhoWinTheGame(short Player1WinTimes, short ComputerWinTimes) {

    if (Player1WinTimes == ComputerWinTimes)
        return Draw;
    else if (Player1WinTimes > ComputerWinTimes)
        return Player1;
    else
        return Computer;
}

strGameResult FillGameResults(short HowManyRound,short Player1WinTimes, short ComputerWinTimes, short DrawTimes) {

    strGameResult GameResult;

    GameResult.HowManyRounds = HowManyRound;

    GameResult.Player1WinTimes = Player1WinTimes;

    GameResult.ComputerWinTimes = ComputerWinTimes;

    GameResult.DrawTimes = DrawTimes;

    GameResult.GameWinner = WhoWinTheGame(Player1WinTimes, ComputerWinTimes);

    return GameResult;
}

strGameResult PlayGame(short HowManyRound) {

    strRoundInfo RoundInfo;

    short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

    for (short GameRound = 1; GameRound <= HowManyRound; GameRound++) {

        cout << "Round [" << GameRound << "] begins : \n";

        RoundInfo.RoundNumber = GameRound;

       enGameChoice Player1Choice=RoundInfo.Player1Choice = ReadPlayer1Choice();//1

       enGameChoice ComputerChoice=RoundInfo.ComputerChoice = GetComputerChoice();//2

       enWinner RoundWinner=RoundInfo.RoundWinner = WhoWinTheRound(Player1Choice, ComputerChoice);

       if (RoundWinner == Player1)
           Player1WinTimes++;
       else if (RoundWinner == Computer)
           ComputerWinTimes++;
       else
           DrawTimes++;

       PrintRoundResult(RoundInfo);
    }
    
    return FillGameResults(HowManyRound, Player1WinTimes, ComputerWinTimes, DrawTimes);
}

void ResetScreen() {
    system("cls");
    system("color 0F");
}

string Tabs(short NumberOfTabs) {

    string t = "";

    for (short i = 0; i < NumberOfTabs;i++) {
        t += "\t";
    }
    return t;
}

void ShowGameOverScreen() {
    cout << Tabs(2) << "__________________________________________________________\n\n";
    cout<<Tabs(2)<<"                +++ G a m e O v e r ++ + \n";
    cout << Tabs(2)<< "__________________________________________________________\n\n";
}

void ShowFinalGameResults(strGameResult GameResult) {

    cout << Tabs(2) << "__________________[Game Result]____________________________\n\n";

    cout << Tabs(2) << "Game Rounds        : " << GameResult.HowManyRounds << endl;

    cout << Tabs(2) << "Player1 won times  : " << GameResult.Player1WinTimes << endl;

    cout << Tabs(2) << "Computer won times : " << GameResult.ComputerWinTimes << endl;

    cout << Tabs(2) << "Draw times         : " << GameResult.DrawTimes << endl;

    cout << Tabs(2) << "Final Winner       : " << WinnerName(GameResult.GameWinner) << endl;

    cout << Tabs(2) << "__________________________________________________________\n\n";

    SetWinnerScreenColor(GameResult.GameWinner);
}

void StartGame() {

    char PlayAgain = 'Y';

    do {

     ResetScreen();

     strGameResult GameResult=PlayGame(ReadHowManyRound());

     ShowGameOverScreen();

     ShowFinalGameResults(GameResult);

     cout << endl << Tabs(2);
     cout<< "Do you want to play again? Y/N? ";

     cin >> PlayAgain;

    } while (PlayAgain=='Y'||PlayAgain=='y');
}

int main()
{
    srand((unsigned)time(NULL));
    
    StartGame();
}


