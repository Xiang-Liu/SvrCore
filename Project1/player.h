#pragma once
#include "common.h"
//#include "card_stack.h"
#include <vector>
#include "card.h"
#include "card_factory.h"
using namespace std;

class player
{
private:
	vector<card> cards;
	int id;
	int score;
public:
	player(int id, int score);
	int get_cards();
	~player();
};

