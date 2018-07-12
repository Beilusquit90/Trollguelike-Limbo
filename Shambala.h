#pragma once
#include <vector>
#include "RuinesMap.h"
#include <iostream>
#include "Limbo.h"
#include "Body.h"

class Shambala
{
public:
	Shambala();
	~Shambala();
	void SetMyHero();
	void Draw();
	int Activ();
	void Restart();
	void DrawHero();
	void HeroSteps();
	void MousePress(int button,int  state,int x,int y);
	void sKeyboard(int keyx, int x, int y);
	void Keyboard(unsigned char keyx, int x, int y);

	Body * myHero;
	std::vector<RuinesMap>TheSeed;
private:
	int flag;

	//Body MyLovelyHero;
};

