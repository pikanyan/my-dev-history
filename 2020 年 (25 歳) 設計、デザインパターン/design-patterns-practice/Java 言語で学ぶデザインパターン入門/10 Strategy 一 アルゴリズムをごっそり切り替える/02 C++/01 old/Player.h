#pragma once

#include "Strategy.h"
#include <string>

class Player
{
private:
    std::string name;
    Strategy* strategy;
    int wincount = 0;
    int losecount = 0;
    int gamecount = 0;

public:
    Player(std::string name, Strategy* strategy) : name(name), strategy(strategy) {}

    Hand nextHand()
    {
        return strategy->nextHand();
    }

    void win()
    {
        strategy->study(true);
        wincount++;
        gamecount++;
    }

    void lose()
    {
        strategy->study(false);
        losecount++;
        gamecount++;
    }

    void even()
    {
        gamecount++;
    }

    std::string toString() const
    {
        return "[" + name + ":" + std::to_string(gamecount) + " games, "
            + std::to_string(wincount) + " win, "
            + std::to_string(losecount) + " lose"
            + "]";
    }
};

