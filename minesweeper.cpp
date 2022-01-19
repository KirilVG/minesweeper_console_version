#include <iostream>
#include <ctime>
#include "includes/Header.h"

using namespace std;

void playGame()
{
    //setting up key variables
    int mapSize;
    int numberOfBombs;
    cout<<"Please input the size of the map you want to play on"<<endl;
    cin>>mapSize;
    while (mapSize<1)
    {
        cout<<"The size of the map can not be less than 1."<<endl;
        cout<<"Try again"<<endl;
        cin>>mapSize;
    }
    cout<<"Please input the amount of bombs"<<endl;
    cin>>numberOfBombs;
    while(numberOfBombs<1 || numberOfBombs>mapSize*mapSize){
        cout<<"the  number of bombs must be between 1 and "<<mapSize*mapSize<<endl;
        cout<<"Try again"<<endl;
        cin>>numberOfBombs;
    }
    char ** map = new char*[mapSize];
    char ** visibleMap= new char*[mapSize];

    //set up the map
    MapSetUpFunction(map, visibleMap, mapSize, numberOfBombs);

    //declare variables
    int row;
    int colum;
    char operation;
    int currentNumberOfBlocks=0;
    char blockMessage[100]="Can not block more positions. Try revealing a blocked one";
    bool showBlockMessage=false;
    //main gameplay loop
    while (true)
    {
        
        system("CLS");
        DisplayMapFunction(visibleMap, mapSize);
        if(showBlockMessage)cout<<blockMessage;
        showBlockMessage=false;
        cin >> row>>colum>>operation;
        while(row<0 || row>=mapSize){
            cout<<"The value you chose for the x position is incorrect"<<endl;
            cout<<"Try again"<<endl;
            cin>>row;
        }
        while(colum<0 || colum>=mapSize){
            cout<<"The value you chose for the Y position is incorrect"<<endl;
            cout<<"Try again"<<endl;
            cin>>colum;
        }
        while (operation!='R' && operation!='r' && operation!='B' && operation!='b')
        {
            cout<<"Operation "<<operation<<" does not exist in the current context"<<endl;
            cout<<"Please try another one"<<endl;
            cin>>operation;
        }
        
    

        if (operation == 'r' || operation == 'R')
        {
            //reveals a position
            if(visibleMap[row][colum]=='B'){
                currentNumberOfBlocks--;
            }
            visibleMap[row][colum] = map[row][colum];
            if (visibleMap[row][colum] == 'X')
            {
                system("CLS");
                cout << "Game over, you hit an explosive"<<endl;
                break;
            }
        }
        else if (operation == 'b' || operation == 'B')
        {
            //blocks a position
            if(visibleMap[row][colum]!='B'){
                if(currentNumberOfBlocks==numberOfBombs){
                    showBlockMessage=true;
                }
                else{
                    visibleMap[row][colum] = 'B';
                    currentNumberOfBlocks++;
                }
            }
            if (CheckIfAllMinesAreBlockedFunction(map, visibleMap, mapSize))
            {
                system("CLS");
                cout << "Victory"<<endl;;
                break;
            }
        }
    }
    for (int i=0;i<mapSize;i++){
        delete[] map[i];
        delete[] visibleMap[i];
    }
    delete[] map;
    delete[] visibleMap;
    
}

int main()
{
    playGame();

    return 0;
}