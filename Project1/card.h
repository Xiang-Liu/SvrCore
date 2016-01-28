#pragma once
#include "common.h"
#include <stdlib.h>

class card
{
public:
//	card();
	~card();
	card(CARD_COLOUR colour, CARD_NUMBER number);
private:
	CARD_NUMBER number;
	CARD_COLOUR colour;
};

