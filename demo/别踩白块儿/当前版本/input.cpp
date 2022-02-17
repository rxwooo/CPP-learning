#include "pch.h"
#include "player.h"
#include <graphics.h>
#include <conio.h>
#include <cstdio>
#include <iostream>
#include <windows.h>
#include <string>
#include<fstream>

#include<iostream>

using namespace std;

#define GIW_WIDTH 640 // ���ó��򴰿ڳߴ�
#define GIW_HIGH 580
IMAGE img_background; // ���򱳾�ͼƬ
DWORD cursor_a, cursor_b; // ����ϵͳʱ�����
wchar_t input_text[45]; // �û�������ַ���
int text_length; // �û������ַ����ĳ���// ���������͹��
void DrawInputBox1 ( int width_a, int high_a, int width_b, int high_b)
{
	setfillcolor ( RGB ( 255, 255, 255 ) ); // �����������ɫ
	solidrectangle ( width_a, high_a, width_b, high_b);
	LOGFONT f;
	gettextstyle ( &f ); // ��ȡ��ǰ��������
	f.lfHeight = 44; // ��������߶�Ϊ 44
	_tcscpy_s ( f.lfFaceName, _T ( "����" ) ); // ��������Ϊ����
	f.lfQuality = ANTIALIASED_QUALITY; // �������Ч������� 
	settextstyle ( &f ); // ����������ʽ 
	wchar_t shuru[10] = L"�������";
	setbkmode ( TRANSPARENT );
	settextcolor ( RGB ( 255, 255, 255 ) ); // ����������ɫ 
	outtextxy ( width_a + (width_b - width_a) / 2 - textwidth ( shuru ) / 2, high_a - 46, shuru );
	settextstyle ( 30, 0, L"����" );
	settextcolor ( RGB ( 0, 0, 0 ) ); // ����������ɫ
	outtextxy ( width_a + 30, high_a + ((high_b - high_a) / 2 - 15), input_text );// ����û�������ַ���

	// ���ƹ�� 
	setlinecolor ( RGB ( 0, 0, 0 ) ); // ���ù����ɫ
	cursor_b = GetTickCount (); // �ڶ��λ�ȡϵͳʱ��
	int cursor_width = width_a + 30 + textwidth ( input_text );// ���ù�������
	int cursor_frequency = cursor_b - cursor_a; // ������Ƶ��
	if ( cursor_frequency <= 200 || cursor_frequency >= 700 ) // �ж��Ƿ���ʾ���
	{
		line ( cursor_width, high_a + 5, cursor_width, high_b - 5 );
	}
	if ( cursor_frequency >= 900 ) // �ж��Ƿ���»�ȡ��ϵͳʱ��
	{
		cursor_a = cursor_b;
	}
}

void DrawInputBox2 ( int width_a, int high_a, int width_b, int high_b )
{
	setfillcolor ( RGB ( 255, 255, 255 ) ); // �����������ɫ
	solidrectangle ( width_a, high_a, width_b, high_b );
	LOGFONT f;
	gettextstyle ( &f ); // ��ȡ��ǰ��������
	f.lfHeight = 44; // ��������߶�Ϊ 44
	_tcscpy_s ( f.lfFaceName, _T ( "����" ) ); // ��������Ϊ����
	f.lfQuality = ANTIALIASED_QUALITY; // �������Ч������� 
	settextstyle ( &f ); // ����������ʽ 
	wchar_t shuru[10] = L"�����";
	setbkmode ( TRANSPARENT );
	settextcolor ( RGB ( 255, 255, 255 ) ); // ����������ɫ 
	outtextxy ( width_a + (width_b - width_a) / 2 - textwidth ( shuru ) / 2, high_a - 46, shuru );
	settextstyle ( 30, 0, L"����" );
	settextcolor ( RGB ( 0, 0, 0 ) ); // ����������ɫ
	outtextxy ( width_a + 30, high_a + ((high_b - high_a) / 2 - 15), input_text );// ����û�������ַ���

	// ���ƹ�� 
	setlinecolor ( RGB ( 0, 0, 0 ) ); // ���ù����ɫ
	cursor_b = GetTickCount (); // �ڶ��λ�ȡϵͳʱ��
	int cursor_width = width_a + 30 + textwidth ( input_text );// ���ù�������
	int cursor_frequency = cursor_b - cursor_a; // ������Ƶ��
	if ( cursor_frequency <= 200 || cursor_frequency >= 700 ) // �ж��Ƿ���ʾ���
	{
		line ( cursor_width, high_a + 5, cursor_width, high_b - 5 );
	}
	if ( cursor_frequency >= 900 ) // �ж��Ƿ���»�ȡ��ϵͳʱ��
	{
		cursor_a = cursor_b;
	}
}


void DrawInputBox3 ( int width_a, int high_a, int width_b, int high_b)
{
	setfillcolor ( RGB ( 255, 255, 255 ) ); // �����������ɫ
	solidrectangle ( width_a, high_a, width_b, high_b );
	LOGFONT f;
	gettextstyle ( &f ); // ��ȡ��ǰ��������
	f.lfHeight = 44; // ��������߶�Ϊ 44
	_tcscpy_s ( f.lfFaceName, _T ( "����" ) ); // ��������Ϊ����
	f.lfQuality = ANTIALIASED_QUALITY; // �������Ч������� 
	settextstyle ( &f ); // ����������ʽ 
	wchar_t shuru[10] = L"��������";
	setbkmode ( TRANSPARENT );
	settextcolor ( RGB ( 255, 255, 255 ) ); // ����������ɫ 
	outtextxy ( width_a + (width_b - width_a) / 2 - textwidth ( shuru ) / 2, high_a - 46, shuru );
	settextstyle ( 30, 0, L"����" );
	settextcolor ( RGB ( 0, 0, 0 ) ); // ����������ɫ
	outtextxy ( width_a + 30, high_a + ((high_b - high_a) / 2 - 15), input_text );// ����û�������ַ���

	// ���ƹ�� 
	setlinecolor ( RGB ( 0, 0, 0 ) ); // ���ù����ɫ
	cursor_b = GetTickCount (); // �ڶ��λ�ȡϵͳʱ��
	int cursor_width = width_a + 30 + textwidth ( input_text );// ���ù�������
	int cursor_frequency = cursor_b - cursor_a; // ������Ƶ��
	if ( cursor_frequency <= 200 || cursor_frequency >= 700 ) // �ж��Ƿ���ʾ���
	{
		line ( cursor_width, high_a + 5, cursor_width, high_b - 5 );
	}
	if ( cursor_frequency >= 900 ) // �ж��Ƿ���»�ȡ��ϵͳʱ��
	{
		cursor_a = cursor_b;
	}
}


// �����ɾ���ַ�
void AddDeleteCharacter ( wchar_t c )
{
	if ( c != 8 ) // �ж������Ƿ�ΪBACK��
	{
		if ( c == 27 ) // �ж������Ƿ�ΪESC��
		{
			EndBatchDraw (); // ������ͼ
			closegraph (); // �رջ�ͼ����
			exit ( 0 ); // �˳�����
		}
		if ( text_length < 44 )
		{
			input_text[text_length] = c;
			input_text[text_length + 1] = '\0';
			text_length++;
		}
	}
	else
	{
		if ( text_length > 0 )
		{
			text_length--;
			input_text[text_length] = '\0';
		}
	}
}// ��ȡ�û�����
wchar_t GetInput ()
{
	wchar_t c = 0;
	if ( _kbhit () )
	{
		c = _getwch ();
	}
	return c;
}
  
int hit ()
{
	MOUSEMSG m;
	m = GetMouseMsg ();
	if ( m.uMsg == WM_LBUTTONDOWN )
	{
		if ( 400 < m.x && m.x < 560 && m.y>400 && m.y < 500 )
		{
			return 1;
		}
	}
	return 0;
}

int plnum ()
{
	std::string s;
	//cleardevice ();
	loadimage ( &img_background, L"BG.jpg", GIW_WIDTH, GIW_HIGH );
	//BeginBatchDraw (); // ��ʼ��ͼ 
	input_text[0] = '\0';
	text_length = 0;
	cursor_a = GetTickCount (); // ��һ�λ�ȡϵͳʱ��
	wchar_t key; // �û������Ӣ�� 
	while ( true )
	{
		RECT r = { 200,400,560,500 };
		settextstyle ( 40, 0, L"����" );
		settextcolor ( WHITE );
		putimage ( 0, 0, &img_background );
		DrawInputBox1 ( 80, 200, 600, 240 );
		drawtext ( L"��ENTRT������һ��", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
		key = GetInput ();
		if ( key != 0 )
		{
			AddDeleteCharacter ( key );
		}
		if ( key==13 )
		{
				int back = _ttoi ( input_text );
				cleardevice ();
				return back;
		}
		//cleardevice ();
		FlushBatchDraw ();
	}
	return 0;
}


void Wchar_tToString ( std::string& szDst, wchar_t* wchar )
{
	wchar_t* wText = wchar;
	DWORD dwNum = WideCharToMultiByte ( CP_OEMCP, NULL, wText, -1, NULL, 0, NULL, FALSE );// WideCharToMultiByte������
	char* psText; // psTextΪchar*����ʱ���飬��Ϊ��ֵ��std::string���м����
	psText = new char[dwNum];
	WideCharToMultiByte ( CP_OEMCP, NULL, wText, -1, psText, dwNum, NULL, FALSE );// WideCharToMultiByte���ٴ�����
	szDst = psText;// std::string��ֵ
	delete[]psText;// psText�����
}

wchar_t* plname ()
{
	std::string s;
	//cleardevice ();
	loadimage ( &img_background, L"BG.jpg", GIW_WIDTH, GIW_HIGH );
	//BeginBatchDraw (); // ��ʼ��ͼ 
	input_text[0] = '\0';
	text_length = 0;
	cursor_a = GetTickCount (); // ��һ�λ�ȡϵͳʱ��
	wchar_t key; // �û������Ӣ�� 
	while ( true || MouseHit () )
	{

		RECT r = { 400,400,560,500 };
		settextstyle ( 40, 0, L"����" );
		settextcolor ( WHITE );
		drawtext ( L"��ENTRT����", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
		key = GetInput ();
		if ( key != 0 )
		{
			AddDeleteCharacter ( key );
		}
		if ( key==13 )
		{
				cleardevice ();
				return input_text;
		}
		//cleardevice ();
		DrawInputBox2 ( 80, 200, 600, 240);
		FlushBatchDraw ();
	}
	return 0;
}

wchar_t* plkey ()
{
	std::string s;
	cleardevice ();
	loadimage ( &img_background, L"BG.jpg", GIW_WIDTH, GIW_HIGH );
	//BeginBatchDraw ();
	input_text[0] = '\0';
	text_length = 0;
	cursor_a = GetTickCount (); // ��һ�λ�ȡϵͳʱ��
	wchar_t key; // �û������Ӣ�� 
	while ( true || MouseHit () )
	{
		RECT r = { 400,400,560,500 };
		settextstyle ( 40, 0, L"����" );
		settextcolor ( WHITE );
		drawtext ( L"��ENTRT����", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
		key = GetInput ();
		if ( key != 0 )
		{
			AddDeleteCharacter ( key );
		}
		if ( key==13 )
		{
				cleardevice ();
				return input_text;
		}
		//cleardevice ();
		//putimage ( 0, 0, &img_background );
		DrawInputBox3 ( 80, 200, 600, 240);
		FlushBatchDraw ();
	}
	return 0;
}