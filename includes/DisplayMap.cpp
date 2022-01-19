#include <iostream>

void DisplayMapFunction(char **map,int mapSize){
    for(int i=0;i<mapSize;i++){
        for(int j=0;j<mapSize;j++){
            std::cout<<map[i][j];
        }
        std::cout<<std::endl;
    }
}