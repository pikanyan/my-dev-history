#pragma once

#include <string>
#include <array>



class Hand
{
public:
    static const int HANDVALUE_GUU = 0;
    static const int HANDVALUE_CHO = 1;
    static const int HANDVALUE_PAA = 2;

    static std::array<Hand, 3> hands;
    static std::array<std::string, 3> names;

private:
    int handvalue;

public:
    Hand(int);

    static Hand getHand(int);
    bool isStrongerThan(Hand);
    bool isWeakerThan(Hand);

private:
    int fight(Hand);

public:
    std::string toString();
};

