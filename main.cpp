#include "game.h"
using namespace std;


int main() {

    Game g1;
    g1.welcome();
    g1.showPlayers();     // pause(); also gets executed.
    g1.selectPlayers();
    g1.showTeamPlayers();
    g1.toss();
    g1.startFirstInnings();
    g1.playInnings();
    g1.startSecondInnings();
    g1.playInnings();   // climax(); called when ends.
    cout << "\n\n\t\tThank you for playing!" << endl;
    return 0;
}