#pragma
#include "MapSetUp.cpp"
#include "DisplayMap.cpp"
#include "CheckIfAllMinesAreBlocked.cpp"

void MapSetUpFunction(char ** map, char **visibleMap, int mapSize, int numberOfBombs);
void DisplayMapFunction(char **map, int mapSize);
bool CheckIfAllMinesAreBlockedFunction(char **map, char **visibleMap, int mapSize);