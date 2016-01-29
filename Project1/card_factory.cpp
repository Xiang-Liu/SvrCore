#include "card_factory.h"
#define WIN32
#include <Windows.h>



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

/*unsigned long get_cpu_cycle(void)
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
    //return counter;
    return high32;
}
*/

int card_factory::resort_cards(void)
{
    card* cardtmp;
    int index = 0;
    int i = 0;
    for (i = 0; i < SPADE * NUMBER_2; i++)
    {
        card* cardtmp = (card*)malloc(sizeof card);
        memcpy_s((void *)cardtmp,sizeof card,(void *)&cards[i],sizeof card);
        LARGE_INTEGER long_num = { 0 };
        int x = QueryPerformanceCounter(&long_num); /*if hardware not support, 0 will be returned*/
        if (0 != x)
        {
            (void)srand(long_num.LowPart);
            index = rand() % SPADE * NUMBER_2;
            (void)memcpy_s((void *)&cards[i], sizeof card, (void *)&cards[index], sizeof card);
            (void)memcpy_s((void *)&cards[index], sizeof card, (void *)cardtmp, sizeof card);
            free(cardtmp);
        }
		else
		{
			return RETURN_ERROR;
		}
    }
    return RETURN_OK;
}

card* card_factory::get_one_card(void)
{
	if (true == cards.empty())
	{
		return NULL;
	}
	else
	{
		card* rear_card = &(cards[cards.size()-1]);
		cards.pop_back();
		return rear_card;
	}
	
}

vector<card> card_factory::cards = vector<card>();