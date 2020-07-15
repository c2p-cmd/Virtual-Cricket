#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "team.h"       // "player.h" <string> <vector>

class Game {

public:
    Game();
    int playersPerTeam, maxBalls, totalPlayers;
    std::string players[11];

    bool isFirstInnings;
    Team teamA, teamB;    
    Team *battingTeam, *bowlingTeam;
    Player *batsman, *bowler;

    void welcome();
    void showPlayers();
    int takeInput();
    void selectPlayers();
    bool validateSelectedPlayer(int);
    void showTeamPlayers();
    void toss();
    void tossChoice(Team);
    void startFirstInnings();
    void initPlayers();
    void playInnings();
    void bat();
    bool validateInningScore();
    void showScoreCard();
    void startSecondInnings();
    void swap();
    void climax();

};

