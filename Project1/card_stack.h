#pragma once
#include <stack>
#include "card.h"
using namespace std;
class card_stack
{
public:
	stack<card> cards;
	card_stack();
	virtual ~card_stack();
};

