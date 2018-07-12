#include "stdafx.h"
#include "bag.h"


bag::bag()
{
	value = 1;
	type = 1;
}

bag::bag(int x,int y)
{
	value = x;
	type = y;
}

bag::bag(bag *rhs)
{
	value = rhs->value;
	type = rhs->type;
}

bag::bag(const bag &rhs)
{
	value = rhs.value;
	type = rhs.type;
}


bag::bag(int randx)
{
	value = rand()%2+1;
	type = rand() % 2 + 1;

}

bag::~bag()
{
}
