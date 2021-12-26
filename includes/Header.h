#pragma
#include "MapSetUp.cpp"
#include "DisplayMap.cpp"
#include "CheckIfAllMinesAreBlocked.cpp"

void MapSetUpFunction(char map[][9], char visibleMap[][9], int mapSize, int numberOfBombs);
void DisplayMapFunction(char map[][9], int mapSize);
bool CheckIfAllMinesAreBlockedFunction(char map[][9], char visibleMap[][9], int mapSize);