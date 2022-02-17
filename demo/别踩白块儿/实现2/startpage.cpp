#include "pch.h"
#include "player.h"
#include <graphics.h>
#include <conio.h>
#include <cstdio>
#include<string>
#include<fstream>

#include<iostream>

using namespace std;

//退出按钮1
void exitbutton1 ( int n )
{
	setfillcolor ( BLUE );
	solidellipse ( 320 * n + 20, 420, 320 * n + 20 + 200, 490 );
	RECT r = { 320 * n + 20,420,320 * n + 20 + 200,490 };
	settextstyle ( 40, 0, L"宋体" );
	settextcolor ( WHITE );
	drawtext ( L"结束游戏", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
}
//退出按钮2
void exitbutton2 ( int n )
{
	setfillcolor ( YELLOW );
	solidellipse ( 320 * n + 20, 420, 320 * n + 20 + 200, 490 );
	RECT r = { 320 * n + 20,420,320 * n + 20 + 200,490 };
	settextstyle ( 40, 0, L"宋体" );
	settextcolor ( BLACK );
	drawtext ( L"EXIT", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
}

//退出界面byebye 从上到下
void flash_word ( int n )
{
	int i = 0;
	settextstyle ( 80, 0, L"宋体" );
	settextcolor ( WHITE );
	for ( ; i != 6; i++ )
	{
		cleardevice ();
		RECT r = { 0,80 * i,320 * n + 200,80 * (i + 1) };
		drawtext ( L"BYE BYE", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
		Sleep ( 700 );
	}
}

//开始界面，返回值判断游戏开始模式
char startpage1 ()
{
	initgraph ( 640, 580 );
	loadimage ( NULL, L"test.jpg", 640, 580 );
	RECT l = { 80,400,240,500 };
	RECT r = { 400,400,560,500 };
	settextstyle ( 40, 0, L"宋体" );
	settextcolor ( WHITE );

	//鼠标点击坐标判断游戏模式及按钮显示
	while ( 1||MouseHit () )
	{
		MOUSEMSG m;
		m = GetMouseMsg (); 
		if ( 80 < m.x && m.x < 240 && m.y>400 && m.y < 500 )
		{
			drawtext ( L"SURE?", &l, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
			//按钮点击返回判断值
			if ( m.uMsg == WM_LBUTTONDOWN )
			{
				if ( 80 < m.x && m.x < 240 && m.y>400 && m.y < 500 )
				{
					cleardevice ();
					return 'n';
				}
			}
		}
		if ( !(80 < m.x && m.x < 240 && m.y>400 && m.y < 500) )
		{
			drawtext ( L"默认模式", &l, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
		}
		if ( 400 < m.x && m.x < 560 && m.y>400 && m.y < 500 )
		{
			drawtext ( L"SURE?", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
			//按钮点击返回判断值
			if ( m.uMsg == WM_LBUTTONDOWN )
			{
				if ( 400 < m.x && m.x < 560 && m.y>400 && m.y < 500 )
				{
					cleardevice ();
					return 'y';
				}
			}
		}
		if ( !(400 < m.x && m.x < 560 && m.y>400 && m.y < 500) )
		{
			drawtext ( L"自由模式", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
		}
	}
}
