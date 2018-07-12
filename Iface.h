#pragma once
class Iface
{
public:
	Iface();
	Iface(int x, int y,int xx,int yy) :x1(x), y1(y), x2(xx), y2(yy) {};
	~Iface();
	int x1;
	int y1;
	int x2;
	int y2;
	

};

