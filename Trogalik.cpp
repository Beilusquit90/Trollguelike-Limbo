// Trogalik.cpp: определяет точку входа для консольного приложения.


#pragma once

#include "stdafx.h"


#include <iostream>
#include <gl\glut.h>
//
#include <time.h>
#include <math.h>
#include <cstdio>
#include <stdlib.h>
//#include "RuinesMap.h"
#include "Shambala.h"
#include <string.h>
#include <gl\glaux.h>
#include "TileTextures.h"
#include "GameMenu.h"
#include "Iface.h"

//#ifndef M_PI
#define M_PI 3.14159265
//Limbo * mypos;
//экстернат как бы.
extern double mx;
extern double my;

extern TileTextures tails;
extern int flagMenu;
extern int flags;
extern int wWidth;
extern int wHeight;
extern Shambala x;
//Limbo * mmap[11][11];
//std::vector<Limbo*>* vLimbo;

Shambala * xxx=&x;
int ts = 70;
int flagK;
GameMenu menu;
int fexit = 0;
//Iface inface(350, 350);

int cursx;

int cursy;


void Draw();
void initialize();
void Timer(int x);
void Keyboard(unsigned char keyx, int x, int y);
void SKeyboard(int keyx, int x, int y);
void MouseMove(int x, int y);		
void MouseMotin(int x, int y);
void MousePress(int button, int state, int x, int y);
void changeSize(int w, int h);



int _tmain(int argc, char **argv)
{
	srand(time(NULL));
	
	std::cout << "Trollguelike started" << std::endl;
	
	//mypos->CreateRoom(10,10);
	
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);// два буфера, 24-битный цвет ргб
	glutInitWindowSize(wWidth, wHeight);           //Размер
	glutInitWindowPosition(200, 200);        // позиция окна.
	glutCreateWindow("Trollguelike.");      // создал окно с именем
	

	initialize();
	//glutFullScreen();
	glutSetCursor(GLUT_CURSOR_NONE);

	//glViewport(0, 5000, 0, 5000);       //Отвечает за то, какая область окна перерисовывается, то есть размер такой же как у окна
	glViewport(0, 1000, 0, 1000);       //Отвечает за то, какая область окна перерисовывается, то есть размер такой же как у окна
	glutDisplayFunc(Draw);    //  если ты свернул приложение и развернул, вот чтобы появилась картинка, программа вызывает функцию draw, где идет отрисовка
	
						  // Новая функция изменения размеров окна
	
	//
	glutTimerFunc(ts, Timer, 0);      // поясняем няшке глуту, что эту функцию юзаем для анимации
	

	glutMotionFunc(MouseMotin);			//движение с зажатой мышкой.
	glutMouseFunc(MousePress);
	glutPassiveMotionFunc(MouseMove);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SKeyboard);

	glutMainLoop();

	return 0;
}



void MouseMotin(int x, int y)
{
		//std::cout << "MouseMotin" << std::endl;
}

void MousePress(int button, int state, int x, int y)
{

	//	if (flagMenu == 0)
	
	xxx->MousePress(button, state, x, y);
	//else
	//	std::cout << "Menu" << std::endl;

		
	
}

void MouseMove(int x, int y) 
{
	
	cursy = x;
	//std::cout << "Cursx " << cursx << std::endl;;
	//std::cout << "Cursy " << cursy << std::endl;
	cursx = 800-y;

}


void initialize() //говорящее название
{
	
	
	//mypos->rgen(40, 5);
	//mypos = mypos->CreateRoom(20, 20);
	//mypos = mypos->genLimbo(10);
	//vLimbo = mypos->getvLimbo();
//	mypos->me = 5;
	tails.LoadTextures();
	
	glEnable(GL_TEXTURE_2D);

	//glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, wWidth, 0, wHeight);
	//glOrtho(0, wWidth, 0, wHeight, -1000, 1000);
	glMatrixMode(GL_MODELVIEW);
	glutSwapBuffers();

}

void Draw() //говорящее название
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//glColor3f(1, 1, 1);

	if (flagMenu == 0)
		std::cout << "flagmenu==0" << std::endl;
	//xxx->Draw();
	else
		//menu.Draw();
	{
		xxx->Draw();
	}


	glBindTexture(GL_TEXTURE_2D, tails.textures[11]);
	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 1);
	glTexCoord2f(0.0, 0.0); glVertex2f(cursy + 10, cursx);
	glTexCoord2f(0.0, 1.0); glVertex2f(cursy, cursx + 20);
	glTexCoord2f(1.0, 1.0); glVertex2f(cursy + 20, cursx + 10);
	//glTexCoord2f(1.0, 0.0); glVertex2f(cursy+20, cursx);
	glColor3f(1, 1, 1);
	glEnd();

	int size = 40;
	int ss = 7;
	/*	glBegin(GL_LINES);
		glColor3f(0, 0, 0);
		glVertex2f(inface.sx-(size*ss),inface.sy - (size*ss));
		glVertex2f(inface.sx + (size*ss), inface.sy - (size*ss));
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tails.textures[12]);
		glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glTexCoord2f(0.0, 0.0); glVertex2f(inface.sx - (size*ss), inface.sy - (size*ss));
		glTexCoord2f(0.0, 1.0); glVertex2f(inface.sx - (size*ss), (inface.sy - (size*ss)+size));
		glTexCoord2f(1.0, 1.0); glVertex2f(inface.sx + (size*ss), (inface.sy - (size*ss) + size));
		glTexCoord2f(1.0, 0.0); glVertex2f(inface.sx + (size*ss), inface.sy - (size*ss));
		glColor3f(1, 1, 1);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tails.textures[12]);
		glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glTexCoord2f(0.0, 0.0); glVertex2f(inface.sx - (size*ss), inface.sy - (size*ss));
		glTexCoord2f(0.0, 1.0); glVertex2f(inface.sx - (size*ss), (inface.sy + (size*ss) + size));
		glTexCoord2f(1.0, 1.0); glVertex2f(inface.sx - (size*ss)-size, (inface.sy - (size*ss) + size));
		glTexCoord2f(1.0, 0.0); glVertex2f(inface.sx - (size*ss) - size, inface.sy - (size*ss));
		glColor3f(1, 1, 1);
		glEnd();
		*/
		//std::cout << "Limbo.size(" << vLimbo->size() <<")"<< std::endl;

	glutSwapBuffers(); // та же херня что и флуш, но для двойного буфера
	
	
	
}


void Timer(int x)
{
	
	//if (flagMenu == 0)
//	{
//		
//	}
	xxx->myHero->cell->vtext();
	Draw();
	xxx->Activ();
	glutTimerFunc(ts, Timer, 0);
	if (fexit)
	{
		if (fexit == 1)
			exit(0);
			
		else
			xxx->Restart();
		fexit = 0;
	}
	
}

void SKeyboard(int keyx, int x, int y)// икс и игрик, это координаты мышки.
{// всякие ф11 и прочие юзабельные клавиши
	//if (flagMenu == 0)
		xxx->sKeyboard(keyx, x, y);
	
	//else
	//	menu.sKeyboard(keyx, x, y);
}

void Keyboard(unsigned char keyx, int x, int y)// икс и игрик, это координаты мышки.
{// все клавиши типа буквы цифры
	
	if (keyx == 27)
		fexit = 1;
	if (keyx == 'r')
		fexit = 2;
	xxx->Keyboard(keyx, x, y);
	//if (flagMenu == 0)
	//	xxx->Keyboard(keyx,x,y);
	//else
	//	menu.Keyboard(keyx, x, y);
}
