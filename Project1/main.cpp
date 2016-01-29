#include <stdlib.h>
#include "card_factory.h"
#include "player.h"

int main()
{
	card_factory::generate_cards();
	card_factory::resort_cards();
	player p1 = player(1, 100);
	player p2 = player(2, 100);
	player p3 = player(3, 100);
	player p4 = player(4, 100);

	while (true)
	{
		int ret = 0;
		ret |= p1.get_cards();
		ret |= p2.get_cards();
		ret |= p3.get_cards();
		ret |= p4.get_cards();
		if (0 != ret)
		{
			break;
		}
	}
	system("pause");
	return 0;
}

void sendData()
{

}

int receive_Data()
{
	return NULL;
}

