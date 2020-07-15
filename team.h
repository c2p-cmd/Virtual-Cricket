#include "player.h"     // string,
#include <vector>

class Team{
public:
    Team();
    std::string name;
    int totalRunsScored;
    int wicketsLost;
    int totalBallsBowled;
    std::vector<Player> players;

};