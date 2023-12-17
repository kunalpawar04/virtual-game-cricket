#include "game.h" //team.h, iostream, cstdlib, ctime, limits
using namespace std;
int main() {
    Game game;

    game.welcome();

    game.showAllPlayers();

    game.selectPlayers();

    game.showAllTeamPlayers();

    //To flush up input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    game.generateToss();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    game.playFirstInning();

    game.playSecondInning();

    game.displayFinalScoreCard();

    return 0;
}