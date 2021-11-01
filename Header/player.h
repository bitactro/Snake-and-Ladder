#include<bits/stdc++.h>
using namespace std;

class Player{

    string playerName;
    int currentPosition;
    public:
  
    void setPlayerName(string name);
    void setPlayerPosition(int n);
    string getPlayerName();
    int getPlayerPosition();
};