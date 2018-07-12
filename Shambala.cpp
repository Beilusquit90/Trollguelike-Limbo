#include "stdafx.h"
#include "Shambala.h"
#include <gl\glut.h>
#include "GameMenu.h"
#include <time.h>
extern int flags;
extern int flagMenu;
extern TileTextures tails;
extern double mx;		//мышка икс
extern double my;		//мышка игрик

Shambala::Shambala()
{
	std::cout << "Shambala gen start." << std::endl;
	srand(time(NULL));
	TheSeed.push_back(RuinesMap());
	
	
	//myHero->me = 5;
	flag = 0;
	myHero = &(*TheSeed[0].myHero);
	std::cout << "TICA TAC MYHERO= " << myHero->cell->body->tiktak << std::endl;


	myHero->inventory.push_back(bag(1,1));
	myHero->inventory.push_back(bag(2,2));
}

Shambala::~Shambala()
{
}

void Shambala::MousePress(int button, int  state, int x, int y)
{
	
	TheSeed[flag].MousePress(button, state, x, y);		
}

void Shambala::SetMyHero()
{
	//MyLovelyHero.hp += 1000;
//	TheSeed[0].SetMyHero(MyLovelyHero);

}

void Shambala::sKeyboard(int keyx, int x, int y)// икс и игрик, это координаты мышки.
{	

	//if (TheSeed[flag].mflag == 0)
	//myHero->me = 0;
		switch (keyx)
		{
		case GLUT_KEY_LEFT: if (flags == 0 && myHero->cell->lleft) { flags = 3; }	break;	//влево
		case GLUT_KEY_RIGHT:if (flags == 0 && myHero->cell->lright) { flags = 1; }	break;	//вправо
		case GLUT_KEY_DOWN:	if (flags == 0 && myHero->cell->lbot) { flags = 4; }	break;	//вниз
		case GLUT_KEY_UP:	if (flags == 0 && myHero->cell->ltop) { flags = 2; }	break;	//вверх
		}
		//myHero->me = 5;

		/*
		case GLUT_KEY_LEFT: if (flags == 0 && myHero->lleft) { TheSeed[0].Move(&myHero, 3); }	break;	//влево
		case GLUT_KEY_RIGHT:if (flags == 0 && myHero->lright) { TheSeed[0].Move(&myHero, 1); }	break;	//вправо
		case GLUT_KEY_DOWN:	if (flags == 0 && myHero->lbot) { TheSeed[0].Move(&myHero, 4); }	break;	//вниз
		case GLUT_KEY_UP:	if (flags == 0 && myHero->ltop) { TheSeed[0].Move(&myHero, 2); }	break;	//вверх
		*/
}

void Shambala::Keyboard(unsigned char keyx, int x, int y)
{
#define MCL myHero->cell->lleft
#define MCR myHero->cell->lright
#define MCB myHero->cell->lbot
#define MCT myHero->cell->ltop
#define f0 flags == 0

	if (TheSeed[flag].mflag == 0)
		switch (keyx)
	{
		//case 27: flagMenu = 1; break;
		case 'a':  if (f0 && MCL) { flags = 3; }	break;	//left
		case 'd':   if (f0 && MCR) { flags = 1; }	break;	//right
		case 'x':	if (f0 && MCB) { flags = 4; }	break;	//bot
		case 'w':	if (f0 && MCT) { flags = 2; }	break;	//top
		case 'e':	if (f0 && (MCT || MCR)) { flags = 5; }	break;	//top-right
		case 'c':	if (f0 && (MCB || MCR)) { flags = 6; }	break;	//bot-right
		case 'z':	if (f0 && (MCB || MCL)) { flags = 7; }	break;	//bot-left
		case 'q':	if (f0 && (MCT || MCL)) { flags = 8; }	break;	//top-left

		case 'A':  if (f0 && MCL) { flags = 3; }	break;	//left
		case 'D':   if (f0 && MCR) { flags = 1; }	break;	//right
		case 'X':	if (f0 && MCB) { flags = 4; }	break;	//bot
		case 'W':	if (f0 && MCT) { flags = 2; }	break;	//top
		case 'E':	if (f0 && (MCT || MCR)) { flags = 5; }	break;	//top-right
		case 'C':	if (f0 && (MCB || MCR)) { flags = 6; }	break;	//bot-right
		case 'Z':	if (f0 && (MCB || MCL)) { flags = 7; }	break;	//bot-left
		case 'Q':	if (f0 && (MCT || MCL)) { flags = 8; }	break;	//top-left
		case ' ':	myHero->tiktak += 0.2; 	break;	//top-left
		
		case '+':	myHero->inventory.push_back(bag(rand() % 2 + 1, rand() % 2 + 1));	break;	//--
		case '-':	if (myHero->inventory.size() > 0) myHero->inventory.pop_back();	break;	//--
	}
	else
		std::cout << "ELSE mflag!=0" << std::endl;
}


void Shambala::Restart() //restart level
{
	myHero = 0;
	Body * temp = new Body;
	auto &zz = *temp->getvBody();
	auto cc = temp->cell->getvLimbo();
	for (auto&x : zz ) {
		delete x;
		x = 0;
	}

	for (auto & ss : zz) {
		delete ss;
		ss = 0;
	}
	std::cout << "Delete end." << std::endl;

	zz.clear();
	cc->clear();
	temp = 0;

	TheSeed.clear();
	TheSeed.push_back(RuinesMap());
	flag = 0;

	myHero = &(*TheSeed[0].myHero);
	std::cout << "Restart complite. Hero 'me'-> " << myHero->cell->me << std::endl;
	
	

	//MyLovelyHero =Body();
	//SetMyHero();
	//glTranslatef((TheSeed[flag].tempTransx), (TheSeed[flag].tempTransy), 0);
	
	//glTranslatef(-(MyLovelyHero.cy * 50 - 350), -(MyLovelyHero.cx * 50 - 350), 0);
}

int Shambala::Activ()
{
	//Restart(); /*flagMenu = 1;*/ return 0;
	/*{
		if (TheSeed[flag].ioflag == 1)
		{
			if (int(TheSeed.size()) > (flag + 1))
			{
				TheSeed[flag].ioflag = 0;
				flag++;
				TheSeed[flag].PushUp(MyLovelyHero);
				MyLovelyHero.tiktak = 0;
				return 1;
			}
			else
			{
				TheSeed[flag].ioflag = 0;
				flag++;
				TheSeed.push_back(RuinesMap(flag + 1));
				TheSeed[flag].PushUp(MyLovelyHero);
				return 1;
			}
		}
		if (TheSeed[flag].ioflag == 2)
		{
			TheSeed[flag].ioflag = 0;
			flag--;
			TheSeed[flag].PushDown(MyLovelyHero);
			MyLovelyHero.tiktak = 0;
			return 1;
		}
	}*/
	TheSeed[flag].WhoDie();
	if (TheSeed[flag].HeroDeath){

		
		Restart(); /*flagMenu = 1;*/ return 0;
	}
	
	if (myHero->cell->body) {
		if (myHero->tiktak <= 0)
		{
			HeroSteps();

			return 0;
		}
		else {
			myHero->tiktak -= 0.2;
		}
	}
	else
		std::cout << "MY HERO HAVEN`T BODY" << std::endl;
	TheSeed[0].Activ();
	//TheSeed[flag].WhoDie();
	
	
	if (TheSeed[flag].HeroDeath) {
		myHero = 0;
		Restart(); /*flagMenu = 1;*/ return 0;
	}
	return 0;
}

void Shambala::Draw()
{
	if (myHero) {
		int start[2] = { 650,100 };
		int size = 35;
		for (auto &x : myHero->inventory)
		{	
			switch (x.type)
			{
			case 1:	glBindTexture(GL_TEXTURE_2D, tails.textures[13]);	break;
			case 2:	glBindTexture(GL_TEXTURE_2D, tails.textures[14]);	break;


			default:
				glBindTexture(GL_TEXTURE_2D, tails.textures[1]);
				break;
			}
		//	glBindTexture(GL_TEXTURE_2D, tails.textures[x.type]);
			glBegin(GL_QUADS);
			glColor3f(1, 1, 1);
			glTexCoord2f(0.0, 0.0); glVertex2f(start[0], start[1]);
			glTexCoord2f(0.0, 1.0); glVertex2f(start[0], start[1]+size);
			glTexCoord2f(1.0, 1.0); glVertex2f(start[0]+size, start[1] + size);
			glTexCoord2f(1.0, 0.0); glVertex2f(start[0] + size, start[1]);
			glColor3f(1, 1, 1);
			glEnd();

			start[1] += size;
			if (start[1] > 500)
			{
				start[1] = 100;
				start[0] += size;
			}
		}

		std::vector<Limbo *> qwe;

		//mypos->Draw(11, 0, 0, 5, &qwe);
		myHero->cell->Draw(11, 0, 0, 5, &qwe,0);
		//std::cout << qwe.size() << std::endl;
		for (auto *zz : qwe)
			zz->drc = 0;
		qwe.clear();
		/*
		TheSeed[flag].Draw();

		//TheSeed[flag].WhatIsee();		// на данный момент живчики и стены
		TheSeed[flag].DrawInterface();
		TheSeed[flag].DrawFly();		// выстрелленая магия
		TheSeed[flag].DrawGamePanel();
		*/

	}
	else
		std::cout << "HERO IS DIE!!" << std::endl;
}


void Shambala::HeroSteps() //work wish array hero steps
{
	static int fhp;
	if (fhp != myHero->cell->body->hp)(TheSeed[flag].steps.clear());
	fhp = myHero->cell->body->hp;

	if (TheSeed[flag].steps.size()==0)
	{
		int temp = 0;
		if (flags == 1) { temp = TheSeed[flag].Move(myHero, 1); flags = 0; }
		if (flags == 2) { temp = TheSeed[flag].Move(myHero, 2); flags = 0; }
		if (flags == 3) { temp = TheSeed[flag].Move(myHero, 3); flags = 0; }
		if (flags == 4) { temp = TheSeed[flag].Move(myHero, 4); flags = 0; }
		if (flags == 5) { temp = TheSeed[flag].Move(myHero, 5); flags = 0; }
		if (flags == 6) { temp = TheSeed[flag].Move(myHero, 6); flags = 0; }
		if (flags == 7) { temp = TheSeed[flag].Move(myHero, 7); flags = 0; }
		if (flags == 8) { temp = TheSeed[flag].Move(myHero, 8); flags = 0; }
	}
	else
	{
		TheSeed[flag].Step(); flags = 0;
	}
}
