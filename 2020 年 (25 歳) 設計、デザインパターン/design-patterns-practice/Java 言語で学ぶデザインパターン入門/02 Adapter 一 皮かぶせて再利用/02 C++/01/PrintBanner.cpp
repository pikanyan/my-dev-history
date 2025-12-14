#include "PrintBanner.h"

#include <iostream>



PrintBanner::PrintBanner(const std::string& string) :
    banner_(std::make_unique<Banner>(string))
{
    std::cout << __FUNCTION__ << std::endl;
}

PrintBanner::~PrintBanner()
{
    std::cout << __FUNCTION__ << std::endl;
}

void PrintBanner::printWeak()
{
    banner_->show_withParen();
}

void PrintBanner::printStrong()
{
    banner_->show_withAster();
}
