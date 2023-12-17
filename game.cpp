#include "game.h"
using namespace std;

Game::Game()
{
    // Fix conditions
    playerPerTeam = 4;
    totalPlayers = 11;
    maxBalls = 6;

    // Array of Players
    players[0] = "Virat";
    players[1] = "Rohit";
    players[2] = "Sachin";
    players[3] = "Head";
    players[4] = "Guptil";
    players[5] = "Jadeja";
    players[6] = "Shami";
    players[7] = "Siraj";
    players[8] = "Bumrah";
    players[9] = "Maharaj";
    players[10] = "Rashid";

    // Some basic declarations
    isFirstInning = false;
    teamA.name = "Team-A";
    teamB.name = "Team-B";
}

void Game::welcome()
{
    cout << "------------------------------------------------------" << endl;
    cout << "-                                                    -" << endl;
    cout << "     🙏🏻Welcome to the Virtual Cricket Game🙏🏻      " << endl;
    cout << "-                                                    -" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << '\n'
         << '\n';
    cout << "--------------------------------------------------------" << endl;
    cout << "-    1️⃣ Create 2 teams of 4 players each               -" << endl;
    cout << "-    2️⃣ Lead the toss and decide what to choose first  -" << endl;
    cout << "-    3️⃣ Each inning will be of 6 balls only            -" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << endl
         << endl;
}

void Game::showAllPlayers()
{
    cout << "Press enter key to continue\n";
    char enterKey = cin.get();
    cout << "------------------------------------------------------" << endl;
    cout << "-                                                    -" << endl;
    cout << "-         🏏 List of All Players Available 🎾         " << endl;
    cout << "-                                                    -" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << endl
         << endl;
    while (enterKey != '\n')
    {
        cout << "Press enter key to continue\n";
        enterKey = cin.get();
    }
    for (int i = 0; i < 11; i++)
    {
        cout << "player[" << i << "] "
             << "= " << players[i] << "\n";
    }
    cout << '\n'
         << '\n';
}

int Game::integerInput()
{
    int n;
    while (!(cin >> n))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Input 😬! Please give valid input\n";
    }
    return n;
}

void Game::selectPlayers()
{
    cout << "Press enter key to select the players 😃\n";
    char enterKey = cin.get();

    cout << "------------------------------------------------------" << endl;
    cout << "                                                      " << endl;
    cout << "     ⚡️⚡️ Create Team-A and Team-B for the Match  ⚡️⚡️   " << endl;
    cout << "                                                      " << endl;
    cout << "------------------------------------------------------" << endl;
    cout << endl
         << endl;

    int visited[11] = {0};
    for (int i = 0; i < 4; i++)
    {
    // For team A
    TeamASelection:
        cout << "Select the player no " << i + 1 << " for Team A - ";
        int playerTeamAID = integerInput();
        if (playerTeamAID < 0 || playerTeamAID > 10)
        {
            cout << "Invalid Input 😬! Please give valid input\n";
            goto TeamASelection;
        }
        else if (visited[playerTeamAID] == 1)
        {
            cout << "Sadly the given player is already selected 😔. Please choose a different player\n";
            goto TeamASelection;
        }
        else
        {
            visited[playerTeamAID] = 1;
            Player teamAPlayer;
            teamAPlayer.index = playerTeamAID;
            teamAPlayer.name = players[playerTeamAID];
            teamA.players.push_back(teamAPlayer);
        }

    // For team B
    TeamBSelection:
        cout << "Select the player no " << i + 1 << " for Team B - ";
        int playerTeamBID = integerInput();
        if (playerTeamBID < 0 || playerTeamBID > 10)
        {
            cout << "Invalid Input 😬! Please give valid input\n";
            goto TeamBSelection;
        }
        else if (visited[playerTeamBID] == 1)
        {
            cout << "Sadly the given player is already selected 😔. Please choose a different player\n";
            goto TeamBSelection;
        }
        else
        {
            visited[playerTeamBID] = 1;
            Player teamBPlayer;
            teamBPlayer.index = playerTeamBID;
            teamBPlayer.name = players[playerTeamBID];
            teamB.players.push_back(teamBPlayer);
        }
    }
    cout << '\n'
         << '\n';
}

void Game::showAllTeamPlayers()
{
    cout << "--------------------------\t\t--------------------------"<< endl;
    cout << "-      Team-A            -\t\t-          Team-B        -" << endl;
    cout << "--------------------------\t\t--------------------------" << endl;

    for (int i = 0; i < playerPerTeam; i++)
    {
        cout <<"|\t"<< " [" << i << "] " << teamA.players[i].name << "\t |"<< "\t\t"<<"|\t"<<" [" << i << "] " << teamB.players[i].name << "\t |" << '\n';
    }
    cout << '\n' << '\n';
}

void Game::generateToss()
{
    cout << "------------------------------------------------------" << endl;
    cout << "-                                                    -" << endl;
    cout << "      Heads up or tails down, let's crown! 🤘💯       " << endl;
    cout << "-                                                    -" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << '\n'
         << '\n';


    srand(static_cast<unsigned int>(time(nullptr)));
    cout << "Press any key to see the result 🌝" << '\n'
         << '\n';
    char enterKey = cin.get();
    if (rand() % 2)
    {
        cout << "Tossing..... And the winner is Team-A!" << '\n'
             << '\n';
        chooseBatOrBowl(teamA);
    }
    else
    {
        cout << "Tossing..... And the winner is Team-B!" << '\n'
             << '\n';
        chooseBatOrBowl(teamB);
    }
}

void Game::chooseBatOrBowl(Team tossWinnerTeam)
{
    cout << "Press 1 to bat & 2 to bowl" << '\n';
    int tossChoice = integerInput();
    if (tossChoice == 1)
    {
        cout << tossWinnerTeam.name << " has decided to do batting first🏏\n"<<"\n";
        if (tossWinnerTeam.name == "Team-A")
        {
            battingTeam = &teamA;
            bowlingTeam = &teamB;
        }
        else
        {
            battingTeam = &teamB;
            bowlingTeam = &teamA;
        }
    }
    else if (tossChoice == 2)
    {
        cout << tossWinnerTeam.name << " has decided to do bowling first🎾\n"<<"\n";
        if (tossWinnerTeam.name == "Team-A")
        {
            battingTeam = &teamB;
            bowlingTeam = &teamA;
        }
        else
        {
            battingTeam = &teamA;
            bowlingTeam = &teamB;
        }
    }
    else
    {
        cout << "Invalid Input 😬! Please give valid input\n";
        chooseBatOrBowl(tossWinnerTeam);
    }
}

void Game ::playFirstInning() {
    cout<<"\t\t  ⭐️⭐️⭐️ First Inning Starts ⭐️⭐️⭐️ "<<'\n'<<'\n';
    isFirstInning = true;
    initialisePlayers();
    actualGamePlay();
}

void Game ::initialisePlayers() {
    batsman = &battingTeam->players[0];
    bowler = &bowlingTeam->players[0];
    cout<<battingTeam->name<<" - "<<batsman->name<<" is batting...🏏\n";
    cout<<bowlingTeam->name<<" - "<<bowler->name<<" is bowling...🎾\n";
}

void Game::actualGamePlay() {
    for(int i=0; i<maxBalls; i++) {
        if(!isInningScoreValid()) {    
            break;
        }   
        cout<<"Press enter to bowl...🎾\n";
        char enterKey = cin.get();
        cout<<bowler->name<<" is Bowling...🎾\n"<<'\n';
        handleBatting();
    }
    if(isFirstInning) {
        targetToChase = battingTeam->totalRunsScored;
        cout<<"\t\t  🔴🟢🟡 First Innings Ends 🔴🟢🟡"<<"\n"<<"\n";
        cout<<"Batting Team- "<<battingTeam->name<<" | "<<"Total runs-"<<battingTeam->totalRunsScored<<"\n"<<"\n";
        cout<<bowlingTeam->name<<" needs "<<battingTeam->totalRunsScored+1<<" runs to win the match"<<"\n"<<"\n";
    }else {
        //Final Result
        displayResult();
    }
}

void Game::handleBatting() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 6);
    int runsScored = dis(gen);
    // srand(time(NULL));
    // int runsScored = rand()%7;
    //Batting team score update
    battingTeam->totalRunsScored += runsScored;
    batsman->runsScored += runsScored;
    batsman->ballPlayed += 1;

    //Bowling team score update
    bowlingTeam->totalBallsPlayed += 1;
    bowler->ballsBowled += 1;
    bowler->runsGiven += runsScored;

    if(runsScored != 0) {
        cout<<batsman->name<<" scored "<<runsScored<<" runs against "<<bowler->name<<" now\n"<<'\n';
        showScoreCard();
    }else {
        cout<<bowler->name<<" took the wicket of "<<batsman->name<<"💥!\n"<<'\n';
        battingTeam->wicketLost += 1;
        bowler->wicketsTaken += 1;
        showScoreCard(); 
        //Next batsman after wicket
        batsman = &battingTeam->players[battingTeam->wicketLost];
    }
}

bool Game::isInningScoreValid() {
    if(isFirstInning) {
        if(bowlingTeam->totalBallsPlayed == maxBalls || battingTeam->wicketLost == playerPerTeam) {
            return false;
        }
    }else {
        if(battingTeam->totalRunsScored > targetToChase || bowlingTeam->totalBallsPlayed == maxBalls || battingTeam->wicketLost == playerPerTeam) {
            return false;
        }
    }
    return true;
}

void Game::showScoreCard() {
    cout << "--------------------------------------------------------------------------------------------------" << "\n";
    cout << "\t"<<battingTeam->name<<" "<<battingTeam->totalRunsScored<<" - "<<battingTeam->wicketLost
    <<" ("<<bowlingTeam->totalBallsPlayed<<") | "<<batsman->name<<" "<<batsman->runsScored<<" ("<<batsman->ballPlayed
    <<" ) \t"<<bowler->name<<" "<<bowler->ballsBowled<<" - "<<bowler->runsGiven<<" - "<<bowler->wicketsTaken<<"\t"<<"\n";
    cout << "--------------------------------------------------------------------------------------------------" << "\n"<<"\n";
}

void Game::playSecondInning() {
    cout<<"\t\t  ⭐️⭐️⭐️ Second Inning ⭐️⭐️⭐️ "<<'\n'<<'\n';
    isFirstInning = false;
    swap(battingTeam, bowlingTeam);
    initialisePlayers();
    actualGamePlay();
}

void Game::displayResult() {
    if(battingTeam->totalRunsScored == targetToChase) {
        //tie
        cout << "------------------------------------------------------" << endl;
        cout << "-                                                    -" << endl;
        cout << "-        🔥🔥 Evenly Matched! It's a Tie! 🔥🔥        -" << endl;
        cout << "-                                                    -" << endl;
        cout << "------------------------------------------------------" << endl;
        cout<<"\n"<<"\n";
    }else if(battingTeam->totalRunsScored > targetToChase) {
        //won
        cout << "------------------------------------------------------" << endl;
        cout << "-                                                    -" << endl;
        cout << "      🎉✨✨ "<<battingTeam->name<<" won the match! 🎉✨✨  "<< endl;
        cout << "-                                                    -" << endl;
        cout << "------------------------------------------------------" << endl;
    }else {
        //lost
        cout << "------------------------------------------------------" << endl;
        cout << "-                                                    -" << endl;
        cout << "     🎉✨✨ "<<bowlingTeam->name<<" won the match! 🎉✨✨  "<< endl;
        cout << "-                                                    -" << endl;
        cout << "------------------------------------------------------" << endl;
    }
    cout<<'\n'<<'\n';
}

void Game::displayFinalScoreCard() {
    cout<<battingTeam->name<<" "<<battingTeam->totalRunsScored<<"-"<<battingTeam->wicketLost<<"  ("<<battingTeam->totalBallsPlayed<<")"<<"\n"<<"\n";
    cout << "---------------------\t\t------------------------\t\t------------------------"<< endl;
    cout << "-      Player       -\t\t-        Batting       -\t\t-        Bowling       -" << endl;
    cout << "---------------------\t\t------------------------\t\t------------------------" << endl;
    for(int i=0; i<playerPerTeam; i++) {
        cout<< "   ["<<i<<"]" << battingTeam->players[i].name <<"\t\t\t\t"
        <<  battingTeam->players[i].runsScored << "(" << battingTeam->players[i].ballPlayed <<")" <<"\t\t\t\t\t" 
        << battingTeam->players[i].runsGiven <<"-"<< battingTeam->players[i].wicketsTaken << "-" <<battingTeam->players[i].ballsBowled;
        cout<<"\n";
    }
    cout<<"\n"<<"\n";

    cout<<bowlingTeam->name<<" "<<bowlingTeam->totalRunsScored<<"-"<<bowlingTeam->wicketLost<<"  ("<<bowlingTeam->totalBallsPlayed<<")"<<"\n"<<"\n";
    cout << "---------------------\t\t------------------------\t\t------------------------"<< endl;
    cout << "-      Player       -\t\t-        Batting       -\t\t-        Bowling       -" << endl;
    cout << "---------------------\t\t------------------------\t\t------------------------" << endl;
    for(int i=0; i<playerPerTeam; i++) {
        cout<< "   ["<<i<<"]" << bowlingTeam->players[i].name <<"\t\t\t\t"
        <<  bowlingTeam->players[i].runsScored << "(" << bowlingTeam->players[i].ballPlayed <<")" <<"\t\t\t\t\t" 
        << bowlingTeam->players[i].runsGiven <<"-"<< bowlingTeam->players[i].wicketsTaken << "-" <<bowlingTeam->players[i].ballsBowled;
        cout<<"\n";
    }
    cout<<"\n"<<"\n";
}