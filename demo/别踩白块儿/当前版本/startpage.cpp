#include "pch.h"
#include "player.h"
#include <graphics.h>
#include <conio.h>
#include <cstdio>
#include<string>
#include<fstream>

#include<iostream>

//�˳���ť1
void exitbutton1 ( int n )
{
	setfillcolor ( BLUE );//������ɫ
	solidellipse ( 320 * n + 20, 420, 320 * n + 20 + 200, 490 );// ������Բ����
	RECT r = { 320 * n + 20,420,320 * n + 20 + 200,490 };//����������ʾ��������
	settextstyle ( 40, 0, L"����" );//��������
	settextcolor ( WHITE );//����������ɫ
	drawtext ( L"������Ϸ", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );//��ʾ����
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

//�������byebye���ִ��ϵ���
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

//��ʼ����
char startpage1 ()
{
	initgraph ( 740, 580 );
	loadimage ( NULL, L"BG.png", 740, 580 );
	RECT l = { 80,400,240,500 };
	RECT r = { 400,400,560,500 };
	settextstyle ( 40, 0, L"����" );
	settextcolor ( WHITE );
	while ( MouseHit () )//  ��ʼ�����ȡ�����Ϣ
	{
		MOUSEMSG m;
		m = GetMouseMsg ();

		//��ʼ���水ť

		if ( 80 < m.x && m.x < 240 && m.y>400 && m.y < 500 )//�ж����������
		{
			drawtext ( L"SURE?", &l, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
			
			if ( m.uMsg == WM_LBUTTONDOWN )//�жϵ�������Ƿ���ȷ
			{
				if ( 80 < m.x && m.x < 240 && m.y>400 && m.y < 500 )//����ȷ���˳�
				{
					cleardevice ();
					return 'n';//����ֵ�����ж��Ƿ�����ģʽ
				}
			}
		}
		//��ʾĬ��ģʽ����
		if ( !(80 < m.x && m.x < 240 && m.y>400 && m.y < 500) )
		{
			drawtext ( L"Ĭ��ģʽ", &l, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
		}



		//������������
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
			drawtext ( L"����ģʽ", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
		}
	}
}
