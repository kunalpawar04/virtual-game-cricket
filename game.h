#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <random>
#include "team.h" ////player.h, string, vector
class Game
{
public:
    // Basic conditions
    Game();
    int playerPerTeam;
    int totalPlayers;
    int maxBalls;
    int targetToChase;
    std ::string players[11];

    bool isFirstInning;
    Team teamA, teamB;
    Team *battingTeam, *bowlingTeam;
    Player *batsman, *bowler;

    // Welcome function declaration
    void welcome();

    // ShowAll function declaration
    void showAllPlayers();

    // Integer input function
    int integerInput();

    // Select Players
    void selectPlayers();

    // Show all team players
    void showAllTeamPlayers();

    // Toss function
    void generateToss();

    // Choose b/w batting or bowling
    void chooseBatOrBowl(Team);

    // To play the first inning
    void playFirstInning();

    // Assigning pointers to teams and players
    void initialisePlayers();

    void actualGamePlay();

    // random function to produce runs
    void handleBatting();

    // Checks if all are out or over is finished
    bool isInningScoreValid();

    // Displaying score card after each ball
    void showScoreCard();

    // To play second inning
    void playSecondInning();

    // Display final outcome of the match
    void displayResult();

    // Final ScoreCard
    void displayFinalScoreCard();
};