#include "pch.h"
#include "player.h"
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include<fstream>
#include<windows.h>
#include<iostream>
#include<wchar.h>
using namespace std;

wchar_t temp[1024];
wchar_t cj[3][40] = { 0 };
float g[3] = {0};
wchar_t n[3][10];
char un[10];
int px;
FILE* fp;
//���ƺ������ϣ�
//1.ÿ��ͼ�λ��ƶ��壻
//2.����ʧ�ܻ�����ƶ��壻
//3.������ɻ�����ƶ��壻
//4.ʵʱ�ɼ�������ƶ��壻
//5.���������������
// ���Ƹ���Ϸ�ߵ���Ϸ����
void PLAYER::Draw()
{
	switch (m_status)
	{
	case PASSANI:			// ��Ϸ�ɹ���Ķ���
		if (m_nextTaskY == 100)
		{
			m_status = PASS;
			DrawPass();
			break;
		}

	case BEGIN:				// ��Ϸ���ο�ʼ
	case RUNNING:			// ��Ϸ������
	{
		// ������洦�ھ�ֹ��ֱ�ӷ��ز����ػ�
		if (m_nextTaskY == 100)
			return;

		m_nextTaskY -= (m_nextTaskY - 100 + 9) / 10;
		DrawRealTimeScore(m_iTask);
		// ������ɵ�������
		int rowy = m_nextTaskY;
		int itask = m_iTask;
		do
		{
			rowy -= 100;
			itask--;
			DrawRow(rowy, itask);//����ÿ�еķ���

		} while (rowy > 0);

		// ����δ��ɵ�������
		rowy = m_nextTaskY;
		itask = m_iTask;
		do
		{
			DrawRow(rowy, itask);
			rowy += 100;
			itask++;
		} while (rowy < 400);

		break;
	}

	case FAILANI:			// ��Ϸʧ�ܺ�Ķ���
		DrawFail();
		break;

	case PASS:				// ��Ϸͨ����ĳɼ���ʾ
	case FAIL:				// ��Ϸʧ�ܺ�ĳɼ���ʾ
		break;
	}
}

// ������Ϸ��������
void PLAYER::DrawFrame()
{

	
	// �����
	setlinecolor(0xfb9700);
	Rectangle(0, 0, 243, 564);
	/*wchar_t title[40];
	wchar_t* key = new wchar_t[4];
	_stprintf_s ( title, L"stop" );
	InputBox ( key, 5, title );*/
	setfillcolor(0xeca549); 
	settextcolor(BLACK);
	settextstyle(16, 0,L"Verdana");
	setbkmode(0xFF5555);

	// ��������
	SolidRectangle(2, 2, 241, 21);
	int w = textwidth(m_strName);
	OutTextXY((244 - w) / 2, 4, m_strName);

	// ���ɼ���
	SolidRectangle(2, 23, 241, 42);
	wchar_t tmp[50];
	_stprintf_s(tmp, L"��ü�¼�� %.3f ��", g[0]);
	
	OutTextXY(10, 26, tmp);
	// 2 <= x <= 241, 44 <= y <= 443 Ϊ��Ϸ��

	// ��������
	SolidRectangle(2, 445, 241, 462);
	for (int i = 0; i < 4; i++)
		OutTextXY(2 + i * 60 + 26, 446, m_keys[i]);
	
	//��ʵʱ�ɼ���
	SolidRectangle(2, 462, 241, 562);
	OutTextXY(10, 472, L"����ɵķ�������:");
	OutTextXY(10, 500,L"����Ҫ��ɵķ�������:");
	//����ʣ��ķ���������������ʵ��
}
// ������Ϸ�����е�һ������
void PLAYER::DrawRow(int baseY, int iTask)
{
	int fromY = baseY;				// �����е���ʼ y ����
	int toY = baseY + 99;			// �����е���ֹ y ����

	// ��� y ���곬����ʾ��Χ��������
	if (fromY < 0) fromY = 0;
	if (toY > 399) toY = 399;

	COLORREF c[4];					// �������ĸ��������ɫ

	//�������һ���ǻ�ɫ
	if (iTask < 0) //iTask = -1;
	{
		for (int i = 0; i < 4; i++)
			c[i] = YELLOW;
	}
	//���֮��ķ�������ɫ
	else if (iTask >= MAXTASK)
	{
		for (int i = 0; i < 4; i++)
			c[i] = GREEN;
	}
	//һ�����
	else
	{
		for (int i = 0; i < 4; i++)
			c[i] = WHITE;

		c[m_Task[iTask]] = (iTask < m_iTask) ? LIGHTGRAY : BLACK;
		//����֮���ɫ���齫��ɻ�ɫ
	}

	// �������е��ĸ�����
	setlinecolor(0xe9dbd6);
	for (int i = 0; i < 4; i++)
	{
		setfillcolor(c[i]);
		FillRectangle(2 + i * 60, 44 + 399 - fromY, 2 + i * 60 + 59, 44 + 399 - toY);
	}

	// ����ǵ�һ�У��ڷ������д����ʼ��������
	if (iTask == 0 && m_iTask == 0)
	{
		int w = textwidth(L"��ʼ");
		int h = textheight(L"��ʼ");
		int x = 2 + m_Task[iTask] * 60 + (60 - w) / 2;
		int y = 44 + 399 - 99 - fromY + (100 - h) / 2;
		//Ѱ�������кڿ����м�λ�ã���д����ʼ��������
		settextcolor(WHITE);
		settextstyle(16, 0, L"Verdana");
		OutTextXY(x, y, L"��ʼ");
	}
}


// ����ͨ����Ϸ��Ľ���
void PLAYER::DrawPass()
{
	// ���Ƴɹ��ı���
	setfillcolor(GREEN);
	SolidRectangle(2, 44, 241, 443);

	// ���"�ɹ�"
	settextcolor(WHITE);
	settextstyle(60, 0, L"Verdana");
	int w = textwidth(L"�ɹ�");
	OutTextXY((244 - w) / 2, 100, L"�ɹ�");

	// ����ɼ�
	wchar_t tmp[100];
	settextstyle(32, 0, L"Verdana");
	_stprintf_s(tmp, L"�ɼ���%.3f ��", m_lastTime);
	w = textwidth(tmp);
	OutTextXY((244 - w) / 2, 200, tmp);
	_stprintf_s(tmp, L"�ٶȣ�%.3f/s", MAXTASK / m_lastTime);
	OutTextXY((244 - w) / 2, 240, tmp);

	// ������¿�ʼ����ʾ
	settextstyle(16, 0, L"Verdana");
	w = textwidth(L"��������Ƽ����¿�ʼ");
	OutTextXY((244 - w) / 2, 400, L"��������Ƽ����¿�ʼ");
	//wsprintf()
	swapgrade ( MAXTASK / m_lastTime, m_strName);
	dphb ();
	wphb ();
}


// ������Ϸʧ�ܺ�Ľ���
void PLAYER::DrawFail()
{
	if (m_failFrame == 0)
	{	// ��ʼ����������˸Ч��������
		m_failRect.left = 3 + m_failErrorKey * 60;
		m_failRect.right = m_failRect.left + 57;
		m_failRect.bottom = m_nextTaskY + 1;
		m_failRect.top = m_nextTaskY + 98;

		if (m_failRect.top > 398) m_failRect.top = 398;
		m_failRect.bottom = 44 + 399 - m_failRect.bottom;
		m_failRect.top = 44 + 399 - m_failRect.top;
	}

	if (m_failFrame < 60)
	{	// ʵ����˸Ч��
		setfillcolor(((m_failFrame / 6) % 2 == 0) ? RED : LIGHTRED);
		SolidRectangle(m_failRect.left, m_failRect.bottom, m_failRect.right, m_failRect.top);
		m_failFrame++;
	}
	else
	{
		// �ı���Ϸ״̬
		m_status = FAIL;

		// ����ʧ�ܵı���
		setfillcolor(RED);
		SolidRectangle(2, 44, 241, 443);

		// ���"ʧ��"
		settextcolor(WHITE);
		settextstyle(60, 0, L"Verdana");
		int w = textwidth(L"ʧ��");
		OutTextXY((244 - w) / 2, 100, L"ʧ��");

		// �����ʷ�ɼ�
		settextstyle(20, 0, L"Verdana");
		wchar_t tmp[100];
		_stprintf_s(tmp, L"��ʷ��óɼ���%.3f ��", m_bestTime);
		w = textwidth(tmp);
		OutTextXY((244 - w) / 2, 200, tmp);

		// ������¿�ʼ����ʾ
		settextstyle(16, 0, L"Verdana");
		w = textwidth(L"��������Ƽ����¿�ʼ");
		OutTextXY((244 - w) / 2, 400, L"��������Ƽ����¿�ʼ");
	}
}

//����ʵʱ�ɼ���
void PLAYER::DrawRealTimeScore(int iTask)
{
	setfillcolor(BLACK);
	SolidRectangle(150, 472, 178, 488);
	SolidRectangle(180, 500, 208, 516);
	wchar_t tmp2[5]; 
	_stprintf_s(tmp2, L"%d", iTask);
	wchar_t tmp3[5];
	_stprintf_s(tmp3, L"%d", MAXTASK - iTask);
	//��ʾʵʱ�ɼ�
	if (iTask <= MAXTASK)
	{
		OutTextXY(150, 472, tmp2);
		OutTextXY(180, 500, tmp3);
	}
	else
	{
		OutTextXY(150, 472, L"END");
		OutTextXY(180, 500, L"NO");		//������ʾ��λ�ã���ͬ
	}
}


//������ʾ��������
void PLAYER::OutTextXY(int x, int y, LPCTSTR s)							// ��ָ��λ������ַ���
{
	outtextxy(m_offset.x + x, m_offset.y + y, s);
}
void PLAYER::OutTextXY(int x, int y, char c)							// ��ָ��λ������ַ�
{
	outtextxy(m_offset.x + x, m_offset.y + y, c);
}
void PLAYER::Rectangle(int x1, int y1, int x2, int y2)					// ���ƾ���
{
	rectangle(m_offset.x + x1, m_offset.y + y1, m_offset.x + x2, m_offset.y + y2);
}
void PLAYER::FillRectangle(int x1, int y1, int x2, int y2)				// �����б߿�������
{
	fillrectangle(m_offset.x + x1, m_offset.y + y1, m_offset.x + x2, m_offset.y + y2);
	//4�������ֱ������Ϻ����ϵ�����
}
void PLAYER::SolidRectangle(int x1, int y1, int x2, int y2)				// �����ޱ߿�������
{
	solidrectangle(m_offset.x + x1, m_offset.y + y1, m_offset.x + x2, m_offset.y + y2);
}

//��ȡ���а���ʾ����
void getposition (int n)
{
	px = n;
}

//�޸����а��ļ�
void wphb ()
{
	FILE* f;
	_wfopen_s ( &f, L"phb.txt", L"w, ccs=UTF-8" );
	fwprintf_s ( f, L"%s:%.3f;%s:%.3f;%s:%.3f;", (wchar_t*)n[0], g[0], (wchar_t*)n[1], g[1], (wchar_t*)n[2],  g[2] );
	fclose ( f );
}

//��ȡ���а�
void rphb ()
{
	int i, j=0, k=0;
	//�ļ���ȡ
	 errno_t ii=_wfopen_s (&fp, L"phb.txt", L"r+, ccs=UTF-8" );//���ı����տ��ַ���
	fwscanf_s ( fp, L" %[^:]:%f;%[^:]:%f;%[^:]:%f;", n[0], 10, &g[0],n[1], 10, &g[1], n[2], 10, &g[2] );//������洢����
	fclose (fp);
}

//��ʾ���а��ļ�
void dphb ()
{
	//��ʾ����
	setfillcolor ( BLACK );
	solidellipse ( 320 * px + 20, 20, 320 * px + 20 + 200, 60 );
	RECT r = { 320 * px+ 20,20,320 * px + 20 + 200,60 };
	settextstyle ( 40, 0, L"����" );
	settextcolor ( WHITE );
	drawtext ( L"���а�", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
	settextstyle ( 20, 0, L"����" );

	//������ʾ���а�
	for(int i = 0; i < 3;i++)
	{
		fillrectangle ( 320 * px+20, 70 + i * 30, 320 * px + 20 + 200, 100 + i * 30);
		swprintf_s ( cj[i], L"%s:  %.3f��/s", n[i], g[i] );//�����а���������Ϊһ���ַ���
		RECT a = { 320 * px + 20,70 + i * 30,320 * px + 20 + 200,100 + i * 30 };//�������а���ʾ����
		drawtext ( cj[i] , &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE );//��ʾ�ı�
	}
}

//ASCII�ַ�תUnicode
wchar_t* char2wchar ( const char* cchar )
{
	wchar_t* m_wchar;
	int len = MultiByteToWideChar ( CP_ACP, 0, cchar, strlen ( cchar ), NULL, 0 );
	m_wchar = new wchar_t[len + 1];
	MultiByteToWideChar ( CP_ACP, 0, cchar, strlen ( cchar ), m_wchar, len );
	m_wchar[len] = '\0';
	return m_wchar;
}

//UnicodeתASCII
char* wchar2char ( const wchar_t* wchar )
{
	char* m_char;
	int len = WideCharToMultiByte ( CP_ACP, 0, wchar, wcslen ( wchar ), NULL, 0, NULL, NULL );
	m_char = new char[len + 1];
	WideCharToMultiByte ( CP_ACP, 0, wchar, wcslen ( wchar ), m_char, len, NULL, NULL );
	m_char[len] = '\0';
	return m_char;
}

//���а����ݴ���
void swapgrade (float grade,const  wchar_t* Name )
{
	int i,j;
	for ( i = 0; i < 3; i++ )
	{
		if ( grade > g[i] )
		{
			for ( j=2;j>i;j-- )
			{
				g[j] = g[j - 1];
			}
			g[j] = grade;
			wcscpy_s ( n[j], Name );
			break;
		 }
	}
}