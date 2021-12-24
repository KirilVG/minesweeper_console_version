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
    MapSetUpFunction(map,visibleMap,mapSize,numberOfBombs);

    //DisplayMapFunction(visibleMap, mapSize);
}

int main()
{
    playGame();
    
    return 0;
}