
#pragma once
class bag
{
public:
	bag();
	bag(int x, int y);
	bag(int x);
	~bag();
	bag(bag *rhs);
	bag(const bag &rhs);

	//void addr(){ arrow++; }
	int type;
	int value;
};

