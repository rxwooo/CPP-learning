#include "pch.h"
#include "player.h"
#include <graphics.h>
#include <conio.h>
#include <cstdio>
#include<string>
#include<fstream>

#include<iostream>

//退出按钮1
void exitbutton1 ( int n )
{
	setfillcolor ( BLUE );//设置颜色
	solidellipse ( 320 * n + 20, 420, 320 * n + 20 + 200, 490 );// 设置椭圆坐标
	RECT r = { 320 * n + 20,420,320 * n + 20 + 200,490 };//设置文字显示矩形区域
	settextstyle ( 40, 0, L"宋体" );//设置字体
	settextcolor ( WHITE );//设置文字颜色
	drawtext ( L"结束游戏", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );//显示文字
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

//结束后的byebye文字从上到下
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

//开始界面
char startpage1 ()
{
	initgraph ( 740, 580 );
	loadimage ( NULL, L"BG.png", 740, 580 );
	RECT l = { 80,400,240,500 };
	RECT r = { 400,400,560,500 };
	settextstyle ( 40, 0, L"宋体" );
	settextcolor ( WHITE );
	while ( MouseHit () )//  开始界面获取鼠标信息
	{
		MOUSEMSG m;
		m = GetMouseMsg ();

		//开始界面按钮

		if ( 80 < m.x && m.x < 240 && m.y>400 && m.y < 500 )//判断鼠标点击坐标
		{
			drawtext ( L"SURE?", &l, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
			
			if ( m.uMsg == WM_LBUTTONDOWN )//判断点击区域是否正确
			{
				if ( 80 < m.x && m.x < 240 && m.y>400 && m.y < 500 )//若正确就退出
				{
					cleardevice ();
					return 'n';//返回值用于判断是否自由模式
				}
			}
		}
		//显示默认模式文字
		if ( !(80 < m.x && m.x < 240 && m.y>400 && m.y < 500) )
		{
			drawtext ( L"默认模式", &l, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
		}



		//功能类似上面
		if ( 400 < m.x && m.x < 560 && m.y>400 && m.y < 500 )
		{
			drawtext ( L"SURE?", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
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
