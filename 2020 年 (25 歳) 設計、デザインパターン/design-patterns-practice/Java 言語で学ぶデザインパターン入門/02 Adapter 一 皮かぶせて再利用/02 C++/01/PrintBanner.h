#pragma once

#include "Banner.h"
#include "Print.h"

#include <memory>
#include <string>



class PrintBanner : public Print
{
private:
    const std::unique_ptr<Banner> banner_;

public:
    explicit PrintBanner(const std::string&);
    virtual ~PrintBanner();

    void printWeak() override;
    void printStrong() override;
};
