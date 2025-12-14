#pragma once

#include "Builder.h"

#include <fstream>
#include <vector>


class HTMLBuilder : public Builder
{
private:
	std::string filename;
	std::ofstream writer;

public:
    void makeTitle(const std::string&) override;
    void makeString(const std::string&) override;
    void makeItems(const std::vector<std::string>&) override;
    void close() override;

    std::string getResult() const;
};
