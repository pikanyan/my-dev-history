#include "main.h"

#include <iostream>
#include <memory>



class A
{
public:
    const int value = 10;

public:
    A() { std::cout << __FUNCTION__ << std::endl; }
    ~A() { std::cout << __FUNCTION__ << std::endl; }
};

class B
{
public:
    int value = 0;

public:
    B(A& a_) : 
        value(a_.value)
    {
        std::cout << __FUNCTION__ << std::endl; 

        std::cout << value << std::endl;
    }

    ~B() { std::cout << __FUNCTION__ << std::endl; }
};

class BuilderA
{
public:
    A build() { return A(); }
};

class BuilderB
{
private:
    BuilderA builderA;

public:
    B build()
    {
        A a = builderA.build();

        return B(a);
    }
};

class Director
{
private:
    BuilderB builderB;

public:
    B construct()
    {
        return builderB.build();
    }
};

int main()
{
    Director director;
    B b = director.construct();

    while (1)
    {

    }

    return 0;
}



/*
一貫性があるコード
複雑なコード

一貫性がないコード
単純なコード
*/

/*
Director が単数の Builder を持つ
使う側が楽
一貫性を保ち易い

Director が複数の Builder を持つ
使う側が苦
一貫性を保ち難い
*/

/*
Director が Builder を持つ
使う側が楽
一貫性を保ち易い

Director が Director を持つ
使う側が苦
一貫性を保ち難い
*/

/*
A
B を構築する為の使い捨てである

B
A を構築する為の使い捨てでない
*/
