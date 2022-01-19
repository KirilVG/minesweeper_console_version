#include <iostream>
#include <ctime>

void MapSetUpFunction(char **map,char **visibleMap,int mapSize,int numberOfBombs ){
    //set basic values to all of the elements of both matrixes
    for(int i=0;i<mapSize;i++){
        map[i]=new char[mapSize];
        visibleMap[i]=new char[mapSize];
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
            posX=(rand() % mapSize);
            posY=(rand() % mapSize);
        }
        while(map[posX][posY]=='X');
        map[posX][posY]='X';
    }

    //set up the emty positions    
    for(int i=0;i<mapSize;i++){
        for(int j=0;j<mapSize;j++){
            if(map[i][j]!='X'){

                int numberOfMines=0;
            
                for(int k=i-1;k<=i+1;k++){
                    for(int q=j-1;q<=j+1;q++){
                        if((k>=0 && k<mapSize) && (q>=0 && q<mapSize)){
                            
                            if(map[k][q]=='X')numberOfMines++;
                        
                        }
                    }
                }
                
                map[i][j]=char('0'+numberOfMines);
            }
        }
    }
}