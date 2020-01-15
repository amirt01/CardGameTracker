#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

void addPlayers (vector <pair<string, int>> &players)
{
    string tempPlayer;
    while(1)
    {
        cout << "Please enter the name of a new player, or press Enter to start the game. ";
        getline(cin, tempPlayer);
        if (tempPlayer == "")
            break;
        else
            players.push_back(make_pair(tempPlayer, 0));
    }
}

void printPlayers (vector <pair<string, int>> &players)
{
    for (auto player : players)
        cout << player.first << " | " << player.second << endl;
}

void printLosers (vector <string> &losers)
{
    for (auto loser : losers)
        cout << loser << " lost!" << endl;
}

bool gameOverDutch (vector <pair<string, int>> &players, vector <string> &losers)
{
    bool gameOver = false;
    int MAXSCORE = 100;
    for (auto player : players)
    {
        if (player.second >= MAXSCORE)
        {
            losers.push_back(player.first);
            gameOver = true;
        }
    }
    return gameOver;
}

void getScores(vector <pair<string, int>> &players)
{
    int score;
    for (auto &player : players)
    {
        cout << "how many points did " << player.first << " get? ";
        cin >> score;
        player.second += score;
    }
}

bool compareByScore(pair<string, int> player1, pair<string, int> player2)
{
    return (player1.second < player2.second);
}

void playerSort (vector <pair<string, int>> &players)
{
    sort(players.begin(), players.end(), compareByScore);
}

void printWinner (vector <pair<string, int>> players)
{
    cout << players.front().first << " won!" << endl;
}

int UI ()
{
    int choice = 0;

    cout << "Please select your choice from the following options:\n(1) Dutch\n(2) 3.5.8\n(3) Peanuts\n(4) Add Players\n(5) Exit" << endl;
    cin >> choice;

    cin.ignore();

    return choice;
}

int main () {
    vector <pair<string, int>> players;
    vector <string> losers;
    int MAXROUNDS = 8;

    while(1)
    {
        switch (UI())
        {
            case 1:
                while(!gameOverDutch(players, losers))
                {
                    system("cls");
                    playerSort(players);
                    printPlayers(players);
                    cout << endl;
                    getScores(players);
                }
                system("cls");
                playerSort(players);
                printLosers(losers);
                printPlayers(players);
                system("pause");
                break;
            case 2:
                for(int i = 0; i < MAXROUNDS; i++)
                {
                    system("cls");
                    playerSort(players);
                    printPlayers(players);
                    cout << endl;
                    getScores(players);
                }
                system("cls");
                playerSort(players);
                printWinner(players);
                printPlayers (players);
                system("pause");
            case 4:
                system("cls");
                addPlayers(players);
                break;
            case 5:
                return 0;
                break;
            default:
                cout << "We could not understand. Please try again.";
        }
        system("cls");
    }
    return 0;
}
