// vector string
#include <vector>
#include "player.h" //string
class Team
{
public:
    Team();
    std ::string name;
    int totalRunsScored;
    int wicketLost;
    int totalBallsPlayed;
    std ::vector<Player> players;
};

