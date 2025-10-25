//Game.h
#ifndef GAME_H
#define GAME_H
#include "RPG.h"
#include<vector>
#include <set>
using namespace std;

class Game: public RPG
{
    public:
        //constructors
        Game();

        //destructor
        ~Game();

        void generatePlayers(int n);
        int selectPlayer();
        void endRound(RPG * winner, RPG * loser, int loserIndex);
        void battleRound();
        void gameLoop();
        void printFinalResults();

    private:
        vector<RPG*> players;
        set<int> live_players;
};


#endif