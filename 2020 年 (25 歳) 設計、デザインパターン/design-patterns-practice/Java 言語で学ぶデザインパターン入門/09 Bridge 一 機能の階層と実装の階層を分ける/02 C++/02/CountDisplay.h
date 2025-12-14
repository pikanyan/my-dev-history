#pragma once

#include "Display.h"



// 機能クラス
class CountDisplay : public Display
{
public:
    explicit CountDisplay(DisplayImpl*);

    void multiDisplay(int);
};
