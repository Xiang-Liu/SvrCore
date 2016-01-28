#include "card.h"
#include <stdlib.h>

card::~card()
{
}


card::card(CARD_COLOUR colour, CARD_NUMBER number)
{
	this->colour = colour;
	this->number = number;
}

