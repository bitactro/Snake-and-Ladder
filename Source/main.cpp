#include<bits/stdc++.h>
#include "../Header/player.h"
using namespace std;
void getInputForSnakes(vector<vector<int>>&snake, int noOfSnakes);
void getInputForLadders(vector<vector<int>>&ladder, int noOfLadders);
void getInputPlayerName(vector<Player>&playerObj, int noOfPlayers);
void playTheGame(int noOfPlayers, vector<Player>playerObj, vector<vector<int>>snake, vector<vector<int>>ladder);
int fetchFinalPosition(vector<vector<int>>ladder, vector<vector<int>>snake, int finalPosition);

int main(){

    int noOfSnakes;
    cin>>noOfSnakes;

    vector<vector<int>>snakes(noOfSnakes,vector<int>(2));
    getInputForSnakes(snakes, noOfSnakes);

    int noOfLadders;
    cin>>noOfLadders;

    vector<vector<int>>ladders(noOfLadders, vector<int>(2));
    getInputForLadders(ladders, noOfLadders);

    int noOfPlayers;
    cin>>noOfPlayers;

    vector<Player>playerObject(noOfPlayers);
    getInputPlayerName(playerObject, noOfPlayers);

   playTheGame(noOfPlayers,playerObject, snakes, ladders);
  
}

void getInputForSnakes(vector<vector<int>>&snake, int noOfSnakes){
     for(int i=0; i < noOfSnakes; i++){
         cin>>snake[i][0]>>snake[i][1];
     }
}

void getInputForLadders(vector<vector<int>>&ladder, int noOfLadders){
     for(int i=0; i < noOfLadders; i++){
         cin>>ladder[i][0]>>ladder[i][1];
     }
}

void getInputPlayerName(vector<Player>&playerObj, int noOfPlayers){
     for(int i=0; i < noOfPlayers; i++){
         string name;
         cin>>name;
         
         playerObj[i].setPlayerName(name);
         playerObj[i].setPlayerPosition(0);
         
     }
}
void playTheGame(int noOfPlayers, vector<Player>playerObj
                 , vector<vector<int>>snake, vector<vector<int>>ladder){
     
     int noOfTotalTurns=0;

    while (1)
    {
        int diceNo=0;

        while(diceNo == 0){
          diceNo = rand()%7;
        }

        int playerTurn= noOfTotalTurns%noOfPlayers;

        int playerPos = playerObj[playerTurn].getPlayerPosition();

        int finalPosition=playerPos;
        if(finalPosition+diceNo<=100){
            finalPosition +=diceNo;
        }
        else{
            cout<<playerObj[playerTurn].getPlayerName()<<" rolled a "<<diceNo<<" and moved from "<<playerPos<<" to "<<finalPosition;
            continue;
        }

        finalPosition=fetchFinalPosition(ladder, snake, finalPosition);

       


        cout<<playerObj[playerTurn].getPlayerName()<<" rolled a "<<diceNo<<" and moved from "<<playerPos<<" to "<<finalPosition;
        cout<<"\n";
        if(finalPosition==100){
            cout<<playerObj[playerTurn].getPlayerName()<<" wins the game\n";
            break;
        }

         //update Player's Position
        playerObj[playerTurn].setPlayerPosition(finalPosition);

        noOfTotalTurns++;
        
    }
}

int fetchFinalPosition(vector<vector<int>>ladder, vector<vector<int>>snake, int finalPosition){
       
        int count=10;

        while(count--){

             bool ladderFound=true;
             while (ladderFound==true)
             {
                bool ok=false;
                for(int i=0; i<ladder.size(); i++){
                    if(ladder[i][0]==finalPosition){
                         finalPosition += ladder[i][1]-ladder[i][0];
                         ok=true;
                    }
                }
                if(ok==false){
                    ladderFound=false;
                }
            }

            bool snakeFound=true;
             while (snakeFound==true)
            {
                bool ok=false;
                for(int i=0; i<snake.size(); i++){
                    if(snake[i][0]==finalPosition){
                          finalPosition -= snake[i][0]-snake[i][1];
                           ok=true;
                    }
                }
                if(ok==false){
                  snakeFound=false;
                 }
            }
        }
        return finalPosition;

}