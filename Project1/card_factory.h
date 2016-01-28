#pragma once
#include "card.h"
#include <vector>
using namespace std;

class card_factory
{
private:
	card_factory();
	~card_factory();
	static vector<card> cards;
public:
	static card* get_instance(CARD_COLOUR colour, CARD_NUMBER number);
	static int generate_cards(void);
	static int resort_cards(void);
	static int move_to_stack(void);
};

