#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>
using namespace std;

class Pokemon
{
    public:
        //Constructors
        Pokemon();
        Pokemon(string name, int hp, int att, int def, vector<string> type);
        //Mutator Functions
        void speak();
        void printStats();
        //Accessor Functions
    
    private:
        string name;
        int hp;
        int attack;
        int defense;
        vector<string> type;
};
#endif