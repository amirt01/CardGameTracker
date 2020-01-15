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

void printWinner (vector <pair<string, int>> players)
{
    cout << players.front().first << " won!" << endl;
}

void getScores(vector <pair<string, int>> &players)
{
    int score;
    for (auto &player : players)
    {
        cout << "How many points did " << player.first << " get? ";
        cin >> score;
        player.second += score;
    }
}

bool compareByScoreUp(pair<string, int> player1, pair<string, int> player2)
{
    return (player1.second > player2.second);
}

bool compareByScoreDown(pair<string, int> player1, pair<string, int> player2)
{
    return (player1.second < player2.second);
}

void playerSort (vector <pair<string, int>> &players)
{
    sort(players.begin(), players.end(), compareByScoreUp);
}

int main () {
    vector <pair<string, int>> players;
    int MAXROUNDS = 8;

    system("cls");
    getPlayers(players);
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
    return 0;
}
