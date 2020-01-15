#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

void getPlayers (vector <pair<string, int>> &players)
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

bool gameOver (vector <pair<string, int>> &players, vector <string> &losers)
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

int main () {
    vector <pair<string, int>> players;
    vector <string> losers;
    system("clear");
    getPlayers(players);
    while(!gameOver(players, losers))
    {
        system("clear");
        playerSort(players);
        printPlayers(players);
        cout << endl;
        getScores(players);
    }
    system("clear");
    playerSort(players);
    printLosers(losers);
    printPlayers (players);
    return 0;
}
