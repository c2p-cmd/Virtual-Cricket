#include "game.h"   // <string> <vector> "player.h"
using namespace std;

void pause() {
    printf("\nPress Enter to continue.");
    cin.ignore();
} void clear() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
} 

Game::Game() {
    playersPerTeam = 4;
    maxBalls = 6;
    totalPlayers = 11;

    players[0] = "Virat";
    players[1] = "Rohit";
    players[2] = "Dhawan";
    players[3] = "Pant";
    players[4] = "Kartik";
    players[5] = "KLRahul";
    players[6] = "Jadeja";
    players[7] = "Hardik";
    players[8] = "Bumrah";
    players[9] = "BKumar";
    players[10] = "Ishant";

    isFirstInnings = false;
    teamA.name = "Team A";
    teamB.name = "Team B";
}

void Game::welcome() {
    cout << "\t\t\t\t\t";
    cout << "-----------------------------------" << endl << "\t\t\t\t\t";
    cout << "|=================================|" << endl << "\t\t\t\t\t";
    cout << "|             CRIC-IN             |" << endl << "\t\t\t\t\t";
    cout << "|=================================|" << endl << "\t\t\t\t\t";
    cout << "-----------------------------------" << endl << "\t\t\t\t\t";
    cout << "|                                 |" << endl << "\t\t\t\t\t";
    cout << "| Welcome to Virtual Cricket Game |" << endl << "\t\t\t\t\t";
    cout << "-----------------------------------" << endl << "\t\t\t\t\t";
    putchar('\n');
    putchar('\n'); cout << "\t\t\t\t";
    cout << "-------------------------------------------------" << endl << "\t\t\t\t";
    cout << "|================= Instructions ================|" << endl << "\t\t\t\t";
    cout << "|                                               |" << endl << "\t\t\t\t";
    cout << "| 1. Create 2 teams (Team A & B with 4 players  |" << endl << "\t\t\t\t";
    cout << "|    each) from a given pool of 11 players.     |" << endl << "\t\t\t\t";
    cout << "| 2. Lead the toss & decide the choice of play. |" << endl << "\t\t\t\t";
    cout << "| 3. Each innings will of 6 balls.              |" << endl << "\t\t\t\t";
    cout << "-------------------------------------------------" << endl << "\t\t\t\t";
    puts("\nPress Enter to Continue. ");
    cin.ignore(); 
    putchar('\n');
}

void Game::showPlayers() {
    cout << "\t\t\t\t\t";
    cout << "-----------------------------------" << endl << "\t\t\t\t\t";
    cout << "|=================================|" << endl << "\t\t\t\t\t";
    cout << "|        Players Available        |" << endl << "\t\t\t\t\t";
    cout << "|=================================|" << endl << "\t\t\t\t\t";
    cout << "-----------------------------------" << endl;
    puts("\n");

    for (int i=0; i < 11; i++) {
        cout << "\t\t\t\t\t\t [" << i << "]. " << players[i] << endl;
    }
   pause();
}

int Game::takeInput() {
    int n;

    while (!(cin >> n)) {

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please provide valid (integer) input. " << endl;
    }

    return n;

}

bool Game::validateSelectedPlayer(int k) {
    int n;
    vector<Player> players;

    players = teamA.players;
    n = players.size();
    for (int i = 0; i < n; i++) {
        if (players[i].id == k) {
            return false;
        }
    }

    players = teamB.players;
    n = players.size();
    for (int i = 0; i < n; i++) {
        if (players[i].id == k) {
            return false;
        }
    }

    return true;
}

void Game::selectPlayers() {

    cout << "\n\t\t\t\t";
    cout << "-------------------------------------------------" << endl << "\t\t\t\t";
    cout << "|============= Create Teams: A & B =============|" << endl << "\t\t\t\t";
    cout << "-------------------------------------------------" << endl << endl;

    for (int i = 0; i < playersPerTeam; i++) {

        // Add player to Team A
        teamASelection:
            cout << "\nSelect Player " << i + 1 << " of Team A-  ";
        
            int playerIndexTeamA = takeInput();

            if (playerIndexTeamA < 0 || playerIndexTeamA > 10) {
                cout << "\nPlease select from the pool of players. \n" << endl;
                goto teamASelection;
            } else if ( !validateSelectedPlayer(playerIndexTeamA) )  {
                cout << "\nPlayer already selected.\n";
                goto teamASelection;
            } else {
                Player teamAPlayer;
                teamAPlayer.id = playerIndexTeamA;
                teamAPlayer.name = players[playerIndexTeamA];
                teamA.players.push_back(teamAPlayer);
            }
        

        // Add player to Team B
        teamBSelection:
            cout << "\nSelect Player " << i + 1 << " of Team B-  ";
            
            int playerIndexTeamB = takeInput();

            if (playerIndexTeamB < 0 || playerIndexTeamB > 10) {
                cout << "\nPlease select from the pool of players. \n" << endl;
                goto teamBSelection;
            } else if ( !validateSelectedPlayer(playerIndexTeamB) )  {
                cout << "\nPlayer already selected.\n";
                goto teamBSelection;
            } else {
                Player teamBPlayer; 
                teamBPlayer.id = playerIndexTeamB;
                teamBPlayer.name = players[playerIndexTeamB];
                teamB.players.push_back(teamBPlayer);
            }
        
        
        // Done.

    }

}

void Game::showTeamPlayers() {
    vector<Player> teamAPlayers = teamA.players;
    vector<Player> teamBPlayers = teamB.players;

    cout << endl << endl << "\t\t";
    cout << "--------------------------\t\t--------------------------" << endl << "\t\t";
    cout << "|=======  Team-A  =======|\t\t|=======  Team-B  =======|" << endl << "\t\t";
    cout << "--------------------------\t\t--------------------------" << endl;

    for (int i = 0; i < playersPerTeam; i++) {
        cout << "\t\t";
        cout << "|\t" << "[" << i << "] " << teamAPlayers[i].name << "\t |"
        	<< "\t\t"
			<< "|\t" << "[" << i << "] " << teamBPlayers[i].name << "\t |" << endl;
    }
    cout << "\t\t" << "--------------------------\t\t--------------------------" << endl << endl;
}

void Game::toss() {
    clear();
    srand(time(NULL));

    cout << "\nPress Enter to toss..." << endl;
    getchar();

    cout << "\n\t\t\t\t";
    cout << "--------------------------------------" << endl << "\t\t\t\t";
    cout << "|============ Let's Toss ============|" << endl << "\t\t\t\t";
    cout << "--------------------------------------" << endl << endl;

    int n = rand() % 2;

    cout << "Tossing coin...\n" << endl;

    switch (n){
    case 0:
        cout << "Team A wins!\n" << endl;
        tossChoice(teamA);
        break;
    case 1:
        cout << "Team B wins!\n" << endl;
        tossChoice(teamB);
        break;
    default:
        cout << "error." << endl;
    }

}

void Game::tossChoice(Team tossWinnerTeam) {

    clear();

    cout << "Choose whether to bat or bowl.\n" <<
        "1. Bat" << endl <<
        "2. Bowl" << endl;

    int tossInput = takeInput();
    clear();

    switch (tossInput) {
        case 1: 
            cout << endl << tossWinnerTeam.name << " won the toss and chose to bat first.\n" << endl;
            
            if (tossWinnerTeam.name.compare("Team A") == 0) { // if Team A wins the toss.
                battingTeam = &teamA;
                bowlingTeam = &teamB;
            } else {                           // if Team B wins the toss.
                battingTeam = &teamB;
                bowlingTeam = &teamA;
            } break;
            
        case 2: 
            cout << endl << tossWinnerTeam.name << " won the toss and elected to bowl first.\n" << endl;
            
            if (tossWinnerTeam.name.compare("Team B") == 0) { // if Team A wins the toss.
                battingTeam = &teamA;
                bowlingTeam = &teamB;
            } else {
                battingTeam = &teamB;
                bowlingTeam = &teamA;
            } break;

        default:
            cout << "Invalid input. Please try again.\n" << endl;
            tossChoice(tossWinnerTeam);

    }
}

void Game::swap(){
    // cout << battingTeam << "&" << bowlingTeam << endl;    // debugging purposes
    Team *temp = battingTeam;
    battingTeam = bowlingTeam;
    bowlingTeam = temp;
    // cout << battingTeam << "&" << bowlingTeam << endl;    // debugging purposes
    initPlayers();
}

void Game::startFirstInnings() {
    isFirstInnings = true;

    cout << "\n\t\t||| FIRST INNINGS |||" << endl << endl;
    initPlayers();
}


void Game::startSecondInnings() {
    isFirstInnings = false;

    cout << "\n\t\t||| SECOND INNINGS |||" << endl << endl;
    swap();
} 

void Game::initPlayers() {

    batsman = &battingTeam->players[0];
    bowler = &bowlingTeam->players[0];

    cout << battingTeam->name << "-" << batsman->name << " is batting." << endl;
    cout << bowlingTeam->name << "-" << bowler->name << " is bowling." << endl;

}

void Game::playInnings() {

    for (int i=1; i <= maxBalls ; i++){
        cout << "Press Enter to bowl...";
        getchar();
        cout << "Bowling..." << endl;
        bat();

        if (!validateInningScore()) {
            break;
        }
    }

}

void Game::bat() {
    srand(time(NULL));

    int runsMade = rand() % 7;

    // Update batting team & batsman score
    batsman->runsScored += runsMade;
    battingTeam->totalRunsScored += runsMade;
    batsman->ballsPlayed += 1 ;
    
    // Update bowling team & boeling score
    bowler->runsGiven += runsMade;
    bowler->ballsBowled += 1;
    bowlingTeam->totalBallsBowled += 1;
    

    if (runsMade != 0) { // if runs scored is between 1-6
        cout << endl << bowler->name << " to " << batsman->name << " " << runsMade << " runs!.\n" << endl;
        showScoreCard();

    } else {   // If runs made is 0 i.e, out.
        cout << endl << bowler->name << " to " << batsman->name << " OUT!\n" << endl;

        battingTeam->wicketsLost += 1;
        bowler->wicketsTaken += 1;

        showScoreCard();

        int nextPlayerIndex = battingTeam->wicketsLost;
        batsman = &battingTeam->players[nextPlayerIndex];
    }

    

}

bool Game::validateInningScore() {
    if (isFirstInnings) {
        if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls) {

            cout << "\t\t ||| FIRST INNINGS ENDS ||| " << endl << endl;

			cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - "
					<< battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled
					<< ")" << endl;

			cout << bowlingTeam->name << " needs " << battingTeam->totalRunsScored + 1
					<< " runs to win the match" << endl << endl;

            return false;
        }
    } else {
        if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls) {

            cout << "\t\t ||| SECOND INNINGS ENDS ||| " << endl << endl;

            cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - "
                 << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled
                 << ")" << endl;

            if (battingTeam->totalRunsScored > bowlingTeam->totalRunsScored) {
                cout << battingTeam->name << "has won the match!" << endl << endl;
            } else if (battingTeam->totalRunsScored == bowlingTeam->totalRunsScored) {
                cout << "The match is tied!" << endl << endl;
            }else {
                cout << bowlingTeam->name << " has won the match!" << endl << endl;
            }
            climax();

            return false;
        }
    }

    return true;
}

void Game::showScoreCard() {

    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << "\t\t" << battingTeam->name << " " << battingTeam->totalRunsScored << " - " << battingTeam->wicketsLost << 
        " (" <<  bowlingTeam->totalBallsBowled << ") " << " | " << 
        batsman->name << " " << batsman->runsScored << " (" << batsman->ballsPlayed << ")\t\t" <<
        bowler->name << " " << bowler->ballsBowled << " - "  << bowler->runsGiven << " - " << bowler->wicketsTaken
        << endl;
    cout << "---------------------------------------------------------------------------------------" << endl << endl;


}

void Game::climax() {

    cout << "\t\t\t ||| MATCH ENDS ||| " << endl << endl;

    cout << teamA.name << "\t" <<
    teamA.totalRunsScored << "-" << teamA.wicketsLost <<
    " (" << teamA.totalBallsBowled << ")" << endl;
    cout << "=================================================" << endl;
    cout << "|  PLAYER\t\tBATTING\t\tBOWLING |" << endl;
    cout << "|-----------------------------------------------|" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "| " << " [" << i << "] " << teamA.players[i].name <<
        "\t\t" << teamA.players[i].runsScored << "(" << teamA.players[i].ballsPlayed << ")"
        << "\t\t" << teamA.players[i].ballsBowled << "-" << teamA.players[i].runsGiven
        << "-" << teamA.players[i].wicketsTaken << "\t|"<< endl;
    } cout << "=================================================" << endl;

    cout << teamB.name << "\t" <<
    teamB.totalRunsScored << "-" << teamB.wicketsLost <<
    " (" << teamB.totalBallsBowled << ")" << endl;
    cout << "=================================================" << endl;
    cout << "|  PLAYER\t\tBATTING\t\tBOWLING |" << endl;
    cout << "|-----------------------------------------------|" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "| " << " [" << i << "] " << teamB.players[i].name <<
             "\t\t" << teamB.players[i].runsScored << "(" << teamB.players[i].ballsPlayed << ")"
             << "\t\t" << teamB.players[i].ballsBowled << "-" << teamB.players[i].runsGiven
             << "-" << teamB.players[i].wicketsTaken << "\t|" << endl;
    } cout << "=================================================" << endl;
}
