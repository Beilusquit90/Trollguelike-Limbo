#pragma once
#include "stdafx.h"
#include "Limbo.h"
#include <thread>

extern TileTextures tails;
using namespace std;


namespace vLimbs {
	std::vector<Limbo*>vLimbo;
	Limbo * mmap[13][13];
	Limbo * mmap2[13][13];

}

Limbo::Limbo()
{

	ltop = 0;
	lbot = 0;
	lleft = 0;
	lright = 0;
	body = 0;
	MA = 0;
	me = 0;
	drc = 0;
	vLimbs::vLimbo.push_back(this);


}

Limbo::Limbo(int flag)
{

	ltop = 0;
	lbot = 0;
	lleft = 0;
	lright = 0;
	body = 0;
	me = 0;
	drc = 0;
	MA = 0;
}

Limbo::Limbo(const Limbo&rhs)
{

	ltop = rhs.ltop;
	lbot = rhs.lbot;
	lleft = rhs.lleft;
	lright = rhs.lright;
	MA = rhs.MA;
	start = rhs.start;
	size = rhs.size;
	me = rhs.me;
	body = rhs.body;
	drc = rhs.drc;
}

void Limbo::operator=(const Limbo&rhs)
{

	ltop = rhs.ltop;
	lbot = rhs.lbot;
	lleft = rhs.lleft;
	lright = rhs.lright;
	MA = rhs.MA;
	start = rhs.start;
	size = rhs.size;
	me = rhs.me;
	body = rhs.body;
	drc = rhs.drc;
}

Limbo::Limbo(Limbo*rhs)
{

	ltop = rhs->ltop;
	lbot = rhs->lbot;
	lleft = rhs->lleft;
	lright = rhs->lright;
	MA = rhs->MA;
	start = rhs->start;
	size = rhs->size;
	me = rhs->me;
	body = rhs->body;
	drc = rhs->drc;
}

Limbo* Limbo::getpatch(int x, int y) {
	std::cout << x << " " << y << std::endl;
	return vLimbs::mmap[x][y];
}

Limbo::~Limbo()
{
	std::cout << "i`m DIE!!!" << std::endl;
}

std::vector<Limbo*>* Limbo::getvLimbo() { return &vLimbs::vLimbo; }


int chek(Limbo*asd, std::vector<Limbo*>*qwe)
{
	for (auto*zzz : *qwe) {
		if (asd == zzz)
			return 0;
	}
	return 1;
}



void Limbo::vtext()
{
	
	/*	for (int x = 12; x >=0 ; x--) 
		{
			for (int y = 0; y  <=12; y++) {
				if (vLimbs::mmap[x][y])
					std::cout << 1 << " ";
				else
				{
					std::cout << "-" << " ";
				}
			}
			std::cout << std::endl;
		}
	std::cout << std::endl;
	*/

	for (int x = 0; x<=12; x++)
		for (int y = 0; y <=12; y++) {
			vLimbs::mmap[x][y] = 0;
		}
}
void Limbo::Draw(int step, int x, int y, int from, std::vector<Limbo*>*qwe,int flag) {
	int tx = start + (x * size);
	int ty = start + (y * size);
	flag = 0;
	//cout <<  (x )+5 << " " <<  (y )+5 << endl;
	//cout << "zaza->" << (tx / size) - 3 << " " << (ty / size) - 3 << endl;
	//cout << x+6 << " " << y+6 << endl;

	
	vLimbs::mmap[(y )+6][(x )+6]= this;
	//cout << (x )+6<<" "<<(y )+6<< endl;

	if (drc < 5)
		if (step>0)
		{
			if (!drc)
				qwe->push_back(this);

			switch (from)
			{
			case 0: {
				if (ltop)
				{	
					if(ltop->lbot==this)
					ltop->Draw(step - 2, x, y + 1, 0, qwe,flag);
					else
					{
						cout << "ltop BUG" << endl;
					}
				}
				break;
			}

			case 1: {
				if (lbot)
				{
					if (lbot->ltop == this)
					lbot->Draw(step - 2, x, y - 1, 1, qwe, flag);
					else
					{
						cout << "lbot BUG" << endl;
					}
				}
				break;
			}

			case 2: {
				if (lleft)
				{
					if (lleft->lright == this)
					lleft->Draw(step - 2, x - 1, y, 2, qwe, flag);
					else
					{
						cout << "lleft BUG" << endl;
					}
				}
				break;
			}

			case 3: {
				if (lright)
				{
					if (lright->lleft == this)
					lright->Draw(step - 2, x + 1, y, 3, qwe, flag);
					else
					{
						cout << "lright BUG" << endl;
					}
				}
				break;
			}
			case 5: {

				if (ltop) {
					ltop->Draw(1, x, y + 1, 999, qwe, flag);
					ltop->Draw(step - 3, x , y + 1, 13, qwe, flag);//DIAGONAL
					ltop->Draw(step - 3, x, y + 1, 11, qwe, flag);//DIAGONAL
					if (ltop->lright) {
						//ltop->lright->Draw(step - 3, x + 1, y + 1, 11, qwe);//DIAGONAL
						ltop->lright->Draw(step - 3, x + 1, y + 1, 0, qwe, flag); //top righttop
						ltop->lright->Draw(step - 3, x + 1, y + 1, 3, qwe, flag); //top rightright
					}
					if (ltop->lleft) {
						//ltop->lleft->Draw(step - 3, x - 1, y + 1, 13, qwe);//DIAGONAL
						ltop->lleft->Draw(step - 3, x - 1, y + 1, 0, qwe, flag); //top lefttop
						ltop->lleft->Draw(step - 3, x - 1, y + 1, 2, qwe, flag); //top leftleft
					}
					ltop->Draw(step - 1, x, y + 1, 0, qwe, flag); //top
				}
				if (lbot) {
					lbot->Draw(1, x, y - 1, 999, qwe, flag);
					lbot->Draw(step - 3, x , y - 1, 12, qwe, flag);//DIAGONAL
					lbot->Draw(step - 3, x, y - 1, 14, qwe, flag);//DIAGONAL
					if (lbot->lright) {
					//	lbot->lright->Draw(step - 3, x + 1, y - 1, 12, qwe);//DIAGONAL
						lbot->lright->Draw(step - 3, x + 1, y - 1, 1, qwe, flag); //bot rightbot
						lbot->lright->Draw(step - 3, x + 1, y - 1, 3, qwe, flag); //bot rightright
					}
					if (lbot->lleft) {
						//lbot->lleft->Draw(step - 3, x - 1, y - 1, 14, qwe);//DIAGONAL
						lbot->lleft->Draw(step - 3, x - 1, y - 1, 1, qwe, flag); //bot leftbot
						lbot->lleft->Draw(step - 3, x - 1, y - 1, 2, qwe, flag); //bot leftleft
					}
					lbot->Draw(step - 1, x, y - 1, 1, qwe, flag); //bot
				}
				if (lleft) {
					lleft->Draw(1, x - 1, y, 999, qwe, flag);
					lleft->Draw(step - 3, x - 1, y , 13, qwe, flag);//DIAGONAL
					lleft->Draw(step - 3, x - 1, y , 14, qwe, flag); //DIAGONAL
					if (lleft->ltop) {
						//lleft->ltop->Draw(step - 3, x - 1, y + 1, 13, qwe);//DIAGONAL
						lleft->ltop->Draw(step - 3, x - 1, y + 1, 2, qwe, flag); //left topleft
						lleft->ltop->Draw(step - 3, x - 1, y + 1, 0, qwe, flag); //left toptop
					}
					if (lleft->lbot) {
					//	lleft->lbot->Draw(step - 3, x - 1, y - 1, 14, qwe); //DIAGONAL
						lleft->lbot->Draw(step - 3, x - 1, y - 1, 2, qwe, flag); //left botleft
						lleft->lbot->Draw(step - 3, x - 1, y - 1, 1, qwe, flag); //left botbot
				}
					lleft->Draw(step - 1, x - 1, y, 2, qwe, flag); //left
				}
				if (lright) {
					lright->Draw(1, x + 1, y, 999, qwe, flag);
					lright->Draw(step - 3, x + 1, y , 11, qwe, flag);//DIAGONAL
					lright->Draw(step - 3, x + 1, y , 12, qwe, flag);//DIAGONAL
					if (lright->ltop) {
						//lright->ltop->Draw(step - 3, x + 1, y + 1, 11, qwe);//DIAGONAL
						lright->ltop->Draw(step - 3, x + 1, y + 1, 0, qwe, flag);  //right toptop
						lright->ltop->Draw(step - 3, x + 1, y + 1, 3, qwe, flag);  //right topright
					}
					if (lright->lbot) {
					//	lright->lbot->Draw(step - 3, x + 1, y - 1, 12, qwe);//DIAGONAL
						lright->lbot->Draw(step - 3, x + 1, y - 1, 1, qwe, flag);  //right botbot
						lright->lbot->Draw(step - 3, x + 1, y - 1, 3, qwe, flag);  //right botright
					}
					lright->Draw(step - 1, x + 1, y, 3, qwe, flag); //right

				}


				break;
			}
			case 11: { //diagonal right top
				if (ltop) {
					ltop->Draw(1, x, y + 1, 999, qwe, flag);
					if (ltop->lright)
						ltop->lright->Draw(step - 3, x + 1, y + 1, 11, qwe, flag);

					}
				
				if (lright) {
					lright->Draw(1, x+1, y, 999, qwe, flag);
					if (lright->ltop)
						lright->ltop->Draw(step - 3, x + 1, y + 1, 11, qwe, flag);
				}

				break;
			}
			case 12: { //diagonal right bot
				if (lbot) {
					lbot->Draw(1, x, y - 1, 999, qwe, flag);
					if (lbot->lright)
						lbot->lright->Draw(step - 3, x + 1, y - 1, 12, qwe, flag);

				}

				if (lright) {
					lright->Draw(1, x + 1, y, 999, qwe, flag);
					if (lright->lbot)
						lright->lbot->Draw(step - 3, x + 1, y - 1, 12, qwe, flag);
				}

				break;
			}

			case 13: { //diagonal left top
				if (ltop) {
					ltop->Draw(1, x, y + 1, 999, qwe, flag);
					if (ltop->lleft)
						ltop->lleft->Draw(step - 3, x - 1, y + 1, 13, qwe, flag);

				}

				if (lleft) {
					lleft->Draw(1, x - 1, y, 999, qwe, flag);
					if (lleft->ltop)
						lleft->ltop->Draw(step - 3, x - 1, y + 1, 13, qwe, flag);
				}

				break;
			}
			case 14: { //diagonal left bot
				if (lbot) {
					lbot->Draw(1, x, y - 1, 999, qwe, flag);
					if (lbot->lleft)
						lbot->lleft->Draw(step - 3, x - 1, y - 1, 14, qwe, flag);

				}

				if (lleft) {
					lleft->Draw(1, x - 1, y, 999, qwe, flag);
					if (lleft->lbot)
						lleft->lbot->Draw(step - 3, x - 1, y - 1, 14, qwe, flag);
				}

				break;
			}



			default:
				break;
			}
			
			if (!ltop)
			{
				
				if (!lleft)
				{
					glBindTexture(GL_TEXTURE_2D, tails.textures[2]);
					glBegin(GL_QUADS);
						glColor3f(1, 1, 1);
					glTexCoord2f(0.0, 0.0); glVertex2f(tx - size, ty + size);
					glTexCoord2f(0.0, 1.0); glVertex2f(tx - size, ty + (size * 2));
					glTexCoord2f(1.0, 1.0); glVertex2f(tx , ty + (size * 2));
					glTexCoord2f(1.0, 0.0); glVertex2f(tx , ty + size);
						glColor3f(1, 1, 1);
					glEnd();
				}
				if (!lright)
				{
					
					glBindTexture(GL_TEXTURE_2D, tails.textures[2]);
					glBegin(GL_QUADS);
						glColor3f(1, 1, 1);
					glTexCoord2f(0.0, 0.0); glVertex2f(tx + size, ty + size);
					glTexCoord2f(0.0, 1.0); glVertex2f(tx + size, ty + (size * 2));
					glTexCoord2f(1.0, 1.0); glVertex2f(tx + size*2, ty + (size * 2));
					glTexCoord2f(1.0, 0.0); glVertex2f(tx + size * 2, ty + size);
						glColor3f(1, 1, 1);
					glEnd();
				}
				glBindTexture(GL_TEXTURE_2D, tails.textures[2]);
				glBegin(GL_QUADS);
					glColor3f(1, 1, 1);
				glTexCoord2f(0.0, 0.0); glVertex2f(tx, ty + size);
				glTexCoord2f(0.0, 1.0); glVertex2f(tx, ty + (size*2));
				glTexCoord2f(1.0, 1.0); glVertex2f(tx + size, ty + (size*2));
				glTexCoord2f(1.0, 0.0); glVertex2f(tx + size, ty + size);
					glColor3f(1, 1, 1);
				glEnd();
			}
			if (!lbot)
			{
				if(!lright)
				{
					glBindTexture(GL_TEXTURE_2D, tails.textures[2]);
					glBegin(GL_QUADS);
						glColor3f(1, 1, 1);
					glTexCoord2f(0.0, 0.0); glVertex2f(tx + size, ty - size);
					glTexCoord2f(0.0, 1.0); glVertex2f(tx + size, ty);
					glTexCoord2f(1.0, 1.0); glVertex2f(tx + (size*2), ty);
					glTexCoord2f(1.0, 0.0); glVertex2f(tx + (size*2), ty - size);
						glColor3f(1, 1, 1);
					glEnd();
				}
				if (!lleft)
				{
					glBindTexture(GL_TEXTURE_2D, tails.textures[2]);
					glBegin(GL_QUADS);
						glColor3f(1, 1, 1);
					glTexCoord2f(0.0, 0.0); glVertex2f(tx - size, ty - size);
					glTexCoord2f(0.0, 1.0); glVertex2f(tx - size, ty);
					glTexCoord2f(1.0, 1.0); glVertex2f(tx , ty);
					glTexCoord2f(1.0, 0.0); glVertex2f(tx , ty - size);
						glColor3f(1, 1, 1);
					glEnd();
				}

				glBindTexture(GL_TEXTURE_2D, tails.textures[2]);
				glBegin(GL_QUADS);
					glColor3f(1, 1, 1);
				glTexCoord2f(0.0, 0.0); glVertex2f(tx, ty - size);
				glTexCoord2f(0.0, 1.0); glVertex2f(tx, ty );
				glTexCoord2f(1.0, 1.0); glVertex2f(tx + size, ty);
				glTexCoord2f(1.0, 0.0); glVertex2f(tx + size, ty - size);
					glColor3f(1, 1, 1);
				glEnd();
			}
			if (!lright)
			{
				glBindTexture(GL_TEXTURE_2D, tails.textures[2]);
				glBegin(GL_QUADS);
					glColor3f(1, 1, 1);
				glTexCoord2f(0.0, 0.0); glVertex2f(tx+size, ty);
				glTexCoord2f(0.0, 1.0); glVertex2f(tx + size, ty+size);
				glTexCoord2f(1.0, 1.0); glVertex2f(tx + size*2, ty+size);
				glTexCoord2f(1.0, 0.0); glVertex2f(tx + size*2, ty);
					glColor3f(1, 1, 1);
				glEnd();
			}
			if (!lleft)
			{
				glBindTexture(GL_TEXTURE_2D, tails.textures[2]);
				glBegin(GL_QUADS);
					glColor3f(1, 1, 1);
				glTexCoord2f(0.0, 0.0); glVertex2f(tx - (size), ty);
				glTexCoord2f(0.0, 1.0); glVertex2f(tx - (size), ty + size);
				glTexCoord2f(1.0, 1.0); glVertex2f(tx , ty + size);
				glTexCoord2f(1.0, 0.0); glVertex2f(tx , ty);
					glColor3f(1, 1, 1);
				glEnd();
			}

			if (me == 5)
				glBindTexture(GL_TEXTURE_2D, tails.textures[4]);
			else
				if (me == 6)
					glBindTexture(GL_TEXTURE_2D, tails.textures[1]);
				else
					if (me == 1)
						glBindTexture(GL_TEXTURE_2D, tails.textures[3]);
					else
				glBindTexture(GL_TEXTURE_2D, tails.textures[10]);
			glBegin(GL_QUADS);
			glColor3f(1, 1, 1);
			glTexCoord2f(0.0, 0.0); glVertex2f(tx, ty);
			glTexCoord2f(0.0, 1.0); glVertex2f(tx, ty + size);
			glTexCoord2f(1.0, 1.0); glVertex2f(tx + size, ty + size);
			glTexCoord2f(1.0, 0.0); glVertex2f(tx + size, ty);
			glColor3f(1, 1, 1);
			glEnd();

					
		
			


			drc++;



		}
}

void Limbo::SoloDraw(int x, int y,int b) {
	int tx = start + (x * size);
	int ty = start + (y * size);
	if(b)
	glBindTexture(GL_TEXTURE_2D, tails.textures[10]);
	else
	glBindTexture(GL_TEXTURE_2D, tails.textures[2]);
	glBegin(GL_QUADS);
	//	glColor3f(1, 1, 1);
	glTexCoord2f(0.0, 0.0); glVertex2f(tx - (size), ty);
	glTexCoord2f(0.0, 1.0); glVertex2f(tx - (size), ty + size);
	glTexCoord2f(1.0, 1.0); glVertex2f(tx, ty + size);
	glTexCoord2f(1.0, 0.0); glVertex2f(tx, ty);
	//	glColor3f(1, 1, 1);
	glEnd();
}

void Limbo::rgen(int x,int nope)
{
	cout << "RGEN" << endl;
	if (x)
	{
		int z = rand() % 4;
		
		if (z != nope)
		{
			while (z == nope)
			{
				z = rand() % 4;
			}

		}
		switch (z)
		{
		case 0: {
			lright = new Limbo;
			lright->rgen(x - 1, 1);
			break;
		}
		case 1: {
			lleft = new Limbo;
			lleft->rgen(x - 1, 0);
			break;
		}
		case 2: {
			ltop = new Limbo;
			ltop->rgen(x - 1, 3);
			break;
		}
		case 3: {
			lbot = new Limbo;
			lbot->rgen(x - 1, 2);
			break;
		}
		default: {
			break;
		}

		}
	}
}

Limbo * Limbo::CreateRoom(int x, int y)
{
	
/*	std::vector<vector<Limbo*>> lmx;
	
	for (int i = 0; i < x; i++)
	{
		std::vector<Limbo*> lmy;
		for (int j = 0; j < y; j++)
			lmy.push_back(new Limbo);
		lmx.push_back(lmy);
	}

	for(int i=0;i<x;i++)
		for (int j = 0; j < y; j++)
		{

			if(!i)
				lmx[i][j]->lright = lmx[i + 1][j];
			else
				if(i==x-1)
					lmx[i][j]->lleft = lmx[i - 1][j];
				else
				{
					lmx[i][j]->lleft = lmx[i - 1][j];
					lmx[i][j]->lright = lmx[i + 1][j];
				}

			if (!j)
				lmx[i][j]->lbot = lmx[i][j + 1];
			else
				if (j == y - 1)
					lmx[i][j]->ltop = lmx[i][j - 1];
				else
				{
					lmx[i][j]->ltop = lmx[i][j - 1];
					lmx[i][j]->lbot = lmx[i][j + 1];
				}
		

		}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++)
			cout << 1;
		cout << endl;
	}
	lmx[int(x / 2)][0]->setTop(new Limbo);
	lmx[int(x / 2)][0]->ltop->setTop(lmx[int(x/2)][y -1]);

	lmx[int(0)][int(y/2)]->setLeft(new Limbo);
	lmx[int(0)][int(y/2)]->lleft->setLeft(lmx[int(x-1)][y/2]);
	
	
	/*
	lmx[0][int(y/2)]->setLeft(new Limbo);
	Limbo *t = lmx[0][int(y / 2)]->lleft;
	t = t->setLeft(new Limbo);
	t = t->setLeft(new Limbo);
	t = t->setTop(new Limbo);
	t = t->setTop(new Limbo);
	t = t->setRight(new Limbo);
	t = t->setRight(new Limbo);
	t = t->setRight(new Limbo);
	t = t->setRight(new Limbo);
	t = t->setRight(lmx[0][int(y-1)]);
	t = 0;
	///
	lmx[int(x - 1)][y - 2]->lbot = 0;
	lmx[int(x - 1)][y - 1]->setRight(new Limbo);
	lmx[int(x - 1)][y - 1]->lright->setRight(new Limbo);
	lmx[int(x - 1)][y - 1]->lright->lright->setRight(lmx[int(0)][0]);
	*/
	//return lmx[int(x/2)][int(y/2)];
	return new Limbo;
}

Limbo * Limbo::genLimbo(int count) {
	std::vector<Limbo*>doors;
	for (; count > 0; count--) {

		std::vector<vector<Limbo*>> lmx;

		int x = rand() % 3 + 5;
		int y = rand() % 3 + 5;

		for (int i = 0; i < x; i++)
		{
			std::vector<Limbo*> lmy;
			for (int j = 0; j < y; j++)
				lmy.push_back(new Limbo);
			lmx.push_back(lmy);
		}

		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
			{

				if (!i)
					lmx[i][j]->lright = lmx[i + 1][j];
				else
					if (i == x - 1)
						lmx[i][j]->lleft = lmx[i - 1][j];
					else
					{
						lmx[i][j]->lleft = lmx[i - 1][j];
						lmx[i][j]->lright = lmx[i + 1][j];
					}

				if (!j)
					lmx[i][j]->lbot = lmx[i][j + 1];
				else
					if (j == y - 1)
						lmx[i][j]->ltop = lmx[i][j - 1];
					else
					{
						lmx[i][j]->ltop = lmx[i][j - 1];
						lmx[i][j]->lbot = lmx[i][j + 1];
					}


			}
	//	for (int i = 0; i < x; i++) {
		//	for (int j = 0; j < y; j++)
			//	cout << 1;
			//cout << endl;
	//	}
		//cout << endl;
		int rx = rand() % 1;
		int ry = rand() % 1;


		if (rand() % 2){
			if (rand() % 2) 
				doors.push_back(lmx[0][rand() % (y - 1)]->setLeft(new Limbo, 1));

				doors.push_back(lmx[x - 1][rand() % (y - 1)]->setRight(new Limbo, 1));
			}
				
		else {
				if (rand() % 2)
			doors.push_back(lmx[rand() % (x - 1)][0]->setTop(new Limbo, 1));
				else
			doors.push_back(lmx[rand() % (x - 1)][y - 1]->setBot(new Limbo, 1));
		}
	}
	for (int zz = 1; zz < (doors.size()-1); zz+= 2)
	{
		//std::cout << "RAND()%2   " <<rand()%2<< endl;
		CreateDoors(doors[zz], doors[zz+1]);
	}
	std::cout << "Map gen Limbo end." << std::endl;
	
	return doors[0];
}

void Limbo::CreateDoors(Limbo * d1, Limbo *d2)
{
	/*if (!d1->ltop)
	{
		if (!d2->ltop)
		{
			Limbo*t = d1->setTop(new Limbo);
			t = t->setLeft(new Limbo);
			t = t->setLeft(new Limbo);
			t = t->setLeft(d1->setTop(new Limbo));
		}
		else
			(d1->setTop(new Limbo))->setRight(d2);
	}
	else
		d1->setLeft(d2);
	*/
	int m = 4;

	if (!d1->ltop && !d2->ltop)
		(d1->setTop(new Limbo,m))->setRight(d2,m);
	else
		if (!d1->lbot && !d2->lbot)
		(d1->setBot(new Limbo,m))->setRight(d2,m);
		else
			if (!d1->lright && !d2->lright)
				(d1->setRight(new Limbo,m))->setBot(d2,m);
			else
				if (!d1->lleft && !d2->lleft)
					(d1->setLeft(new Limbo,m))->setTop(d2,m);
				else
				{
					if(!d1->ltop)
						(d1->setTop(new Limbo,m))->setLeft(d2,m);
						if(!d1->lbot)
							(d1->setBot(d2,m));
							if (!d1->lright)
								(d1->setRight(d2,m));
							if (!d1->lleft)
								(d1->setLeft(d2, m));
				}


}