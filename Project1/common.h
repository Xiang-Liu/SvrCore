#pragma once
typedef enum _CARD_COLOUR
{
	HEART = 3,
	SPADE = 4,
	CLUB = 2,
	DIMOND = 1,
}CARD_COLOUR;

typedef enum _CARD_NUMBER
{
	NUMBER_3 = 1,
	NUMBER_4,
	NUMBER_5,
	NUMBER_6,
	NUMBER_7,
	NUMBER_8,
	NUMBER_9,
	NUMBER_10,
	NUMBER_J,
	NUMBER_Q,
	NUMBER_K,
	NUMBER_A,
	NUMBER_2,
}CARD_NUMBER;

#define RETURN_ERROR ((int)-1)
#define RETURN_OK ((int)0)
