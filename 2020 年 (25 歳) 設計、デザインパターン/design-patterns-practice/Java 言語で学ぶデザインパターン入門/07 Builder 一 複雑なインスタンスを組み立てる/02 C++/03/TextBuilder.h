#pragma once

#include "Builder.h"

#include <sstream>
#include <vector>



class TextBuilder : public Builder
{
private:
	std::stringstream buffer;

public:
    void makeTitle(const std::string& title) override;
    void makeString(const std::string& str) override;
    void makeItems(const std::vector<std::string>& items) override;
    void close() override;

    std::string getResult() const;
};
