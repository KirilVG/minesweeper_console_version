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
void RecursiveReveal(char **map, char **visibleMap, int mapSize, int rowCourdinate, int colCourdinate)
{
    for (int i = rowCourdinate - 1; i <= rowCourdinate + 1; i++)
    {
        for (int j = colCourdinate - 1; j <= colCourdinate + 1; j++)
        {
            if (i >= 0 && i < mapSize && j >= 0 && j < mapSize)
            {
                if (visibleMap[i][j] == '_')
                {
                    visibleMap[i][j] = map[i][j];
                    if (visibleMap[i][j] == '0')
                    {
                        RecursiveReveal(map, visibleMap, mapSize, i, j);
                    }
                }
            }
        }
    }
}