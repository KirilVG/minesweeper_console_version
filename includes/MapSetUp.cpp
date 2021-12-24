#include <iostream>
#include <ctime>

void MapSetUpFunction(char map[][9],char visibleMap[][9],int mapSize,int numberOfBombs ){
    //set basic values to all of the elements of both matrixes
    for(int i=0;i<mapSize;i++){
        for(int j=0;j<mapSize;j++){
            map[i][j]='0';
            visibleMap[i][j]='_';
        }
    }

    srand((unsigned)time(0));

    //generate bombs at random places
    for(int i=0;i<numberOfBombs;i++){
        int posX;
        int posY;
        do{
            posX=(rand() % 9);
            posY=(rand() % 9);
        }
        while(map[posX][posY]=='X');
        map[posX][posY]='X';
    }

    //generate nubers indicating the amount of bombs in the surrounding places
    for(int i=0;i<mapSize;i++){
        for(int j=0;j<mapSize;j++){
            if(map[i][j]!='X'){
                int numberOfMines=0;
                if(i-1>=0 && map[i-1][j]=='X'){
                    numberOfMines++;
                }
                if(i+1<mapSize && map[i+1][j]=='X'){
                    numberOfMines++;
                }
                if(j-1>=0 && map[i][j-1]=='X'){
                    numberOfMines++;
                }
                if(j+1<mapSize && map[i][j+1]=='X'){
                    numberOfMines++;
                }
                if(i-1>=0 && j-1>=0 && map[i-1][j-1]=='X'){
                    numberOfMines++;
                }
                if(i-1>=0 && j+1<mapSize && map[i-1][j+1]=='X'){
                    numberOfMines++;
                }
                if(i+1<mapSize && j-1>=0 && map[i+1][j-1]=='X'){
                    numberOfMines++;
                }
                if(i+1<mapSize && j+1<mapSize && map[i+1][j+1]=='X'){
                    numberOfMines++;
                }
                map[i][j]=char('0'+numberOfMines);
            }
        }
    }
}