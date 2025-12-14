#include "Hand.h"


Hand::Hand(int handvalue) :
    handvalue(handvalue)
{
}

Hand Hand::getHand(int handvalue)
{
    return hands[handvalue];
}

bool Hand::isStrongerThan(Hand h)
{
    return fight(h) == 1;
}

bool Hand::isWeakerThan(Hand h)
{
    return fight(h) == -1;
}


int Hand::fight(Hand h)
{
    if (this->handvalue == h.handvalue)
        return 0;
    else if ((this->handvalue + 1) % 3 == h.handvalue)
        return 1;
    else
        return -1;
}


std::string Hand::toString()
{
    return names[handvalue];
}

std::array<Hand, 3> Hand::hands
{
    {
        Hand(HANDVALUE_GUU),
        Hand(HANDVALUE_CHO),
        Hand(HANDVALUE_PAA)
    }
};

std::array<std::string, 3> Hand::names
{
    "グー",
    "チョキ",
    "パー"
};
