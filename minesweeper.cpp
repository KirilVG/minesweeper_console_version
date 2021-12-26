#include <iostream>
#include <ctime>
#include "includes/Header.h"

using namespace std;
//void MapSetUpFunction(char map[][9],char visibleMap[][9],int mapSize,int numberOfBombs );
void playGame()
{
    //declaring variables
    const int mapSize = 9;
    int numberOfBombs = 10;
    char map[mapSize][mapSize];
    char visibleMap[mapSize][mapSize];

    //set up the map
    MapSetUpFunction(map, visibleMap, mapSize, numberOfBombs);

    //declare variables
    int row;
    int colum;
    char operation;

    //main gameplay loop
    while (true)
    {

        system("CLS");
        DisplayMapFunction(visibleMap, mapSize);
        cin >> row >> colum >> operation;

        if (operation == 'r' || operation == 'R')
        {
            //reveals a position
            visibleMap[row][colum] = map[row][colum];
            if (visibleMap[row][colum] == 'X')
            {
                system("CLS");
                cout << "Game over, you hit an explosive";
                break;
            }
        }
        else if (operation == 'b' || operation == 'B')
        {
            //blocks a position
            visibleMap[row][colum] = 'B';
            if (CheckIfAllMinesAreBlockedFunction(map, visibleMap, mapSize))
            {
                system("CLS");
                cout << "Victory";
                break;
            }
        }
    }
}

int main()
{
    playGame();

    return 0;
}