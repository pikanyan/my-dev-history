#include "MessageBox.h"

MessageBox::MessageBox(char decochar) : 
	decochar_(decochar)
{
}

void MessageBox::use(const std::string& str)
{
    int length = str.length();

    for (int i = 0; i < length + 4; i++)
    {
        std::cout << decochar_;
    }



    std::cout << std::endl;
    std::cout << decochar_ << " " << str << " " << decochar_;
    std::cout << std::endl;



    for (int i = 0; i < length + 4; i++)
    {
        std::cout << decochar_;
    }

    std::cout << std::endl;
}

std::unique_ptr<Product> MessageBox::clone()
{
    return std::make_unique<MessageBox>(*this);
}
