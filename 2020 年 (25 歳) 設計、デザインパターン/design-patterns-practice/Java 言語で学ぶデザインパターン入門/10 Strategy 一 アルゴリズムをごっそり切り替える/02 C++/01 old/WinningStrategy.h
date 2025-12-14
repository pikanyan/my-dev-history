#pragma once

#include "Strategy.h"
#include <random>



class WinningStrategy : public Strategy
{
private:
    std::mt19937 random;
    bool won = false;
    Hand prevHand;

public:
    WinningStrategy(int seed) :
        random(seed),
        prevHand(Hand::getHand(0))
    {

    }

    Hand nextHand() override
    {
        if (!won)
        {
            std::uniform_int_distribution<> dis(0, 2);

            prevHand = Hand::getHand(dis(random));
        }

        return prevHand;
    }

    void study(bool win) override
    {
        won = win;
    }
};
