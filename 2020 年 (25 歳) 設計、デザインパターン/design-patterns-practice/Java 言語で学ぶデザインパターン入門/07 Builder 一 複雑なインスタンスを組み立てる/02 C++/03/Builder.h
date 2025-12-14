#pragma once

#include <string>
#include <vector>


class Builder
{
public:
    explicit Builder() = default;
    virtual ~Builder() = default;



    virtual void makeTitle(const std::string&) = 0;
    virtual void makeString(const std::string& str) = 0;
    virtual void makeItems(const std::vector<std::string>& items) = 0;
    virtual void close() = 0;
};
