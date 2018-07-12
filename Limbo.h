#pragma once
#include "stdafx.h"
#include <gl\glut.h>
#include "TileTextures.h"
#include <iostream>
#include "MAmap.h"
#include <vector>
//#include "Body.h"





class Limbo
{
public:
	Limbo();
	Limbo(int flag) ;
	Limbo(Limbo*rhs);
	Limbo(const Limbo&rhs);
	Limbo* getpatch(int x, int y);
	
	~Limbo();

	void operator=(const Limbo&rhs);

	void vtext();

	Limbo* setTop(Limbo*qwe,int x) {
		Limbo*z=new Limbo;
		ltop = z;
		z->lbot = this;
		for (int i = 0; i < x - 1; i++)
		{
			z->ltop = (new Limbo)->lbot=z;
			z = z->ltop;
		}
		z->ltop = qwe;
		qwe->lbot = z;
		return qwe;
	}

	Limbo* setLeft(Limbo*qwe,int x) {
		Limbo*z = new Limbo;
		lleft = z;
		z->lright = this;
		for (int i = 0; i < x - 1; i++)
		{
			z->lleft = (new Limbo)->lright=z;
			z = z->lleft;
		}
		z->lleft = qwe;
		qwe->lright = z;
		return qwe;
	}

	Limbo* setRight(Limbo*qwe,int x) {
		Limbo*z = new Limbo;
		lright = z;
		z->lleft = this;
		for (int i = 0; i < x - 1; i++)
		{
			z->lright = (new Limbo)->lleft=z;
			z = z->lright;
		}
		z->lright = qwe;
		qwe->lleft = z;
		return qwe;
	}
	Limbo* setBot(Limbo*qwe,int x) {
		Limbo*z = new Limbo;
		lbot = z;
		z->ltop = this;
		for (int i = 0; i < x - 1; i++)
		{
			z->lbot = (new Limbo)->ltop = z;
			z = z->lbot;
		}
		z->lbot = qwe;
		qwe->ltop = z;
		return qwe;
	}

	Limbo* genLimbo(int count);

	void Draw(int step, int x, int y,int from,std::vector<Limbo*>*qwe,int flag);
	void rgen(int count, int nope);
	void SoloDraw(int x, int y,int b);
	Limbo * CreateRoom(int x, int y);
	void CreateDoors(Limbo * d1, Limbo *d2);

	Limbo * ltop = 0;
	Limbo * lbot = 0;
	Limbo * lleft = 0;
	Limbo * lright = 0;
	Body * body;
	MAmap *MA;
	int drc = 0;
	int me = 0;

	int start = 350;
	int size = 40;

	

	std::vector<Limbo*> * getvLimbo();

};
