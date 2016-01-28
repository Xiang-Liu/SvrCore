#include "card_factory.h"
#define WIN32



card_factory::card_factory()
{

}


card_factory::~card_factory()
{
}

card* card_factory::get_instance(CARD_COLOUR colour, CARD_NUMBER number)
{
	card* new_card = NULL;

	if (colour > SPADE || colour < DIMOND || number > NUMBER_2 || number < NUMBER_3)
	{
		return new_card;
	}
	else
	{
		new_card = new card(colour,number);
		return new_card;
	}

}

int card_factory::generate_cards(void)
{
	int i = 0; 
	int j = 0;
	card* new_card = NULL;
	for (i = 1; i <= SPADE; i++)
	{
		for ( j = 1; j <= NUMBER_2; j++)
		{
			new_card = card_factory::get_instance((CARD_COLOUR)i,(CARD_NUMBER)j);
			if (NULL != new_card)
			{
				cards.push_back(*new_card);
			}
			else
			{
				return -1;
			}
		}
	}
	return 0;
}

unsigned long long get_cpu_cycle(void)
{	
	unsigned long high32 = 0, low32 = 0;
#ifdef WIN32 // WIN32
	_asm
	{
		RDTSC;
		mov high32, ebx;
		mov low32, eax;
	}
#else
	__asm__("RDTSC" : "=a"(low32), "=d"(high32));
#endif
	unsigned long long counter = high32;
	counter = (counter << 32) + low32;
	return counter;
}

int card_factory::resort_cards(void)
{
	card* cardtmp;
	int index = 0;
	srand((unsigned int)get_cpu_cycle);
	rand();
	vector<card>::iterator it = vector<card>::iterator();
	for (it = cards.begin(); cards.end() != it; it++)
	{
		card* cardtmp = (card*)malloc(sizeof card);
		memcpy_s(cardtmp,sizeof card,&(*it),sizeof card);
		srand((unsigned int)get_cpu_cycle);
		index = rand() / SPADE * NUMBER_2;
		memcpy_s(&(*it), sizeof card, &(cards.at(index)),sizeof card);
		memcpy_s(&(cards.at(index)), sizeof card, cardtmp, sizeof card);
		
	}

	return -1;
	/////////////////////////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

vector<card> card_factory::cards = vector<card>();