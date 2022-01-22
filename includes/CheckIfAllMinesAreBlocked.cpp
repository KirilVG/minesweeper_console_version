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
* <file with a helper function>
*
*/
bool CheckIfAllMinesAreBlockedFunction(char **map, char **visibleMap, int mapSize)
{
    for (int i = 0; i < mapSize; i++)
    {
        for (int j = 0; j < mapSize; j++)
        {
            if (map[i][j] == 'X' && visibleMap[i][j] != 'B')
            {
                return false;
            }
        }
    }
    return true;
}