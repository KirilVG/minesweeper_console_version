/**
*  
* Solution to course project # 13
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Kiril Gradinarov
* @idnumber 9MI0600086
* @compiler GCC
*
* <header file>
*
*/
#pragma
#include "MapSetUp.cpp"
#include "DisplayMap.cpp"
#include "CheckIfAllMinesAreBlocked.cpp"
#include "RecReveal.cpp"

void MapSetUpFunction(char **map, char **visibleMap, int mapSize, int numberOfBombs);
void DisplayMapFunction(char **map, int mapSize);
bool CheckIfAllMinesAreBlockedFunction(char **map, char **visibleMap, int mapSize);
void RecursiveReveal(char **map, char **visibleMap, int mapSize, int rowCourdinate, int colCourdinate);