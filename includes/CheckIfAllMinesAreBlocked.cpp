bool CheckIfAllMinesAreBlockedFunction(char map[][9], char visibleMap[][9], int mapSize)
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