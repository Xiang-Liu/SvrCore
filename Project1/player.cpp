#include "player.h"



player::player(int id, int score)
{
	this->id = id;
	this->score = score;
	this->cards = vector<card>();
}

int player::get_cards()
{
	card* one_card = NULL;
	one_card = card_factory::get_one_card(); /*get the rear card from card stack*/
	if (NULL != one_card)
	{
		cards.push_back(*one_card); /*add to hand cards*/
		return RETURN_OK;
	}
	else
	{
		return RETURN_ERROR;
	}
}

player::~player()
{
}
