#include "main.h"

#include "Display.h"
#include "StringDisplayImpl.h"
#include "CountDisplay.h"



int main()
{
    Display* d1 = new Display(new StringDisplayImpl("Hello, Japan"));
    Display* d2 = new CountDisplay(new StringDisplayImpl("Hello, World"));
    CountDisplay* d3 = new CountDisplay(new StringDisplayImpl("Hello, Universe"));
    
    d1->display();
    d2->display();
    d3->display();
    d3->multiDisplay(3);

    delete d1;
    delete d2;
    delete d3;

	return 0;
}
