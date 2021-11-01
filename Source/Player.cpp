#include "../Header/player.h"

string playerName;
int playerPosition;


void Player::setPlayerName(string name){
    playerName=name;
}
void Player::setPlayerPosition(int pos){
    playerPosition=pos;
}

string Player::getPlayerName(){
    return playerName;
}
int Player::getPlayerPosition(){
    return playerPosition;
}
