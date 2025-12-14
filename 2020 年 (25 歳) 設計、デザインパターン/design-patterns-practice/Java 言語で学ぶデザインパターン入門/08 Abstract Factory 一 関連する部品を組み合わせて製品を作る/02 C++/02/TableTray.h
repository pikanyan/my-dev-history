#pragma once

#include "Tray.h"

#include <sstream>



class TableTray : public Tray
{
public:
	explicit TableTray(const std::string&);
	virtual ~TableTray();

	std::string makeHTML() override;
};
