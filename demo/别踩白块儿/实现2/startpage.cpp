#include "pch.h"
#include "player.h"
#include <graphics.h>
#include <conio.h>
#include <cstdio>
#include<string>
#include<fstream>

#include<iostream>

using namespace std;

//�˳���ť1
void exitbutton1 ( int n )
{
	setfillcolor ( BLUE );
	solidellipse ( 320 * n + 20, 420, 320 * n + 20 + 200, 490 );
	RECT r = { 320 * n + 20,420,320 * n + 20 + 200,490 };
	settextstyle ( 40, 0, L"����" );
	settextcolor ( WHITE );
	drawtext ( L"������Ϸ", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
}
//�˳���ť2
void exitbutton2 ( int n )
{
	setfillcolor ( YELLOW );
	solidellipse ( 320 * n + 20, 420, 320 * n + 20 + 200, 490 );
	RECT r = { 320 * n + 20,420,320 * n + 20 + 200,490 };
	settextstyle ( 40, 0, L"����" );
	settextcolor ( BLACK );
	drawtext ( L"EXIT", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
}

//�˳�����byebye ���ϵ���
void flash_word ( int n )
{
	int i = 0;
	settextstyle ( 80, 0, L"����" );
	settextcolor ( WHITE );
	for ( ; i != 6; i++ )
	{
		cleardevice ();
		RECT r = { 0,80 * i,320 * n + 200,80 * (i + 1) };
		drawtext ( L"BYE BYE", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
		Sleep ( 700 );
	}
}

//��ʼ���棬����ֵ�ж���Ϸ��ʼģʽ
char startpage1 ()
{
	initgraph ( 640, 580 );
	loadimage ( NULL, L"test.jpg", 640, 580 );
	RECT l = { 80,400,240,500 };
	RECT r = { 400,400,560,500 };
	settextstyle ( 40, 0, L"����" );
	settextcolor ( WHITE );

	//����������ж���Ϸģʽ����ť��ʾ
	while ( 1||MouseHit () )
	{
		MOUSEMSG m;
		m = GetMouseMsg (); 
		if ( 80 < m.x && m.x < 240 && m.y>400 && m.y < 500 )
		{
			drawtext ( L"SURE?", &l, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
			//��ť��������ж�ֵ
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
			drawtext ( L"Ĭ��ģʽ", &l, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
		}
		if ( 400 < m.x && m.x < 560 && m.y>400 && m.y < 500 )
		{
			drawtext ( L"SURE?", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
			//��ť��������ж�ֵ
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
			drawtext ( L"����ģʽ", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
		}
	}
}
