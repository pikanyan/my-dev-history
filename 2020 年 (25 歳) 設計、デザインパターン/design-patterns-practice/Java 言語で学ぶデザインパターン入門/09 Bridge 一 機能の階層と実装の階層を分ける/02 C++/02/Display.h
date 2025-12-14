#pragma once

#include "DisplayImpl.h"



// 機能クラス
class Display
{
private:
	DisplayImpl* impl;

public:
    explicit Display(DisplayImpl*);
    virtual ~Display();

    void open();
    void print();
    void close();

    void display()
    {
        open();
        print();
        close();
    }
};

