//RPG.cpp
#include <iostream>
#include <random>
#include <string>
#include "RPG.h"

//constructors
RPG::RPG()
{
    name = "NPC";
    hits_taken = 0;
    luck = 0.1;
    exp = 50.0;
    level = 1;
}

RPG::RPG(string name, int hits_taken, float luck, float exp, int level)
{
    this->name = name;
    this->hits_taken = hits_taken;
    this->luck = luck;
    this->exp = exp;
    this->level = level;
}

//accessor functions
string RPG::getName() const
{
    return name;
}

int RPG::getHitsTaken() const
{
    return hits_taken;

}

float RPG::getLuck() const
{
    return luck;
}

float RPG::getExp() const
{
    return exp;
}

int RPG::getLevel() const
{
    return level;
}

//mutators
void RPG::setHitsTaken(int new_hits)
{
    /**
    * @brief sets hits_taken to new_hits
    *
    */
    hits_taken = new_hits;
}

bool RPG::isAlive() const
{
    /**
    * @brief returns whether hits_taken is less than MAX_HITS_TAKEN
    * In other words, a player is alive as long as they have not been hit MAX_HITS_TAKEN times.
    *
    * @return true : player is alive
    * @return false : player is unalive
    */
    return hits_taken < MAX_HITS_TAKEN;
}

/**
 * @brief updates name
 * 
 * @param name 
 */
void RPG::setName(string name)
{
    this->name = name;
}

/**
 * @brief increases RPG experience by 50
 *        After updating, if RPG's experience is >= 100, increase
 *        RPG's level by 1, reset experience to 0, and increase luck by 0.1
 */
void RPG::updateExpLevel()
{
    exp += 50;
    if(exp >= 100)
    {
        level++;
        exp = 0;
        luck += 0.1;
    }
}

/**
 * @brief Hits or misses opponent at random. Luck is a form of defense.
 *        The higher the opponent's luck, the more likely the attack will miss.
 *        If the attack is a hit, opponent's hit taken should increment by 1.
 * 
 */
void RPG::attack(RPG * opponent)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);

    float random_num = dis(gen);

    //Create a bool called hit
    //hit is true if random_num > HIT_FACTOR * opponent's luck
    bool hit = false;
    if (random_num > (HIT_FACTOR * opponent->getLuck()))
    {
        hit = true;
    }
    //if hit is true, call updateHitsTaken() to increase opponent's hits_taken
    if (hit == true)
    {
        opponent->setHitsTaken(opponent->getHitsTaken() + 1);
    }
}

/**
 * @brief Prints in the format:
 * "Name: NPC_X     Hits Taken: X      Luck: 0.X00000     Level: X      Status: Alive or Dead"
 */
void RPG::printStats()
{
    printf("Name: %s\t Hits Taken: %i\t Luck: %f\t Level: %i\t ", name.c_str(), hits_taken, luck, level);
    if (hits_taken >= 3)
    {
        cout << "Status: Dead\n";
    }
    else
    {
        cout << "Status: Alive\n";
    }
}

/**
 * @brief Destroy the RPG::RPG object
 * 
 */
RPG::~RPG()
{
}