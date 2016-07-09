#include"PlayerData.h"

void PlayerData::update()
{
	if (bullet != 10) {
		count++;
		if (count % 30 == 0)
		{
			bullet++;
			count = 0;
		}
	}
}
