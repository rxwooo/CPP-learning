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

#define GIW_WIDTH 640 // 设置程序窗口尺寸
#define GIW_HIGH 580
IMAGE img_background; // 程序背景图片
DWORD cursor_a, cursor_b; // 定义系统时间变量
wchar_t input_text[45]; // 用户输入的字符串
int text_length; // 用户输入字符串的长度// 绘制输入框和光标
void DrawInputBox1 ( int width_a, int high_a, int width_b, int high_b)
{
	setfillcolor ( RGB ( 255, 255, 255 ) ); // 设置输入框颜色
	solidrectangle ( width_a, high_a, width_b, high_b);
	LOGFONT f;
	gettextstyle ( &f ); // 获取当前字体设置
	f.lfHeight = 44; // 设置字体高度为 44
	_tcscpy_s ( f.lfFaceName, _T ( "黑体" ) ); // 设置字体为黑体
	f.lfQuality = ANTIALIASED_QUALITY; // 设置输出效果抗锯齿 
	settextstyle ( &f ); // 设置字体样式 
	wchar_t shuru[10] = L"玩家数量";
	setbkmode ( TRANSPARENT );
	settextcolor ( RGB ( 255, 255, 255 ) ); // 设置字体颜色 
	outtextxy ( width_a + (width_b - width_a) / 2 - textwidth ( shuru ) / 2, high_a - 46, shuru );
	settextstyle ( 30, 0, L"楷体" );
	settextcolor ( RGB ( 0, 0, 0 ) ); // 设置字体颜色
	outtextxy ( width_a + 30, high_a + ((high_b - high_a) / 2 - 15), input_text );// 输出用户输入的字符串

	// 绘制光标 
	setlinecolor ( RGB ( 0, 0, 0 ) ); // 设置光标颜色
	cursor_b = GetTickCount (); // 第二次获取系统时间
	int cursor_width = width_a + 30 + textwidth ( input_text );// 设置光标横坐标
	int cursor_frequency = cursor_b - cursor_a; // 计算光标频率
	if ( cursor_frequency <= 200 || cursor_frequency >= 700 ) // 判断是否显示光标
	{
		line ( cursor_width, high_a + 5, cursor_width, high_b - 5 );
	}
	if ( cursor_frequency >= 900 ) // 判断是否更新获取的系统时间
	{
		cursor_a = cursor_b;
	}
}

void DrawInputBox2 ( int width_a, int high_a, int width_b, int high_b )
{
	setfillcolor ( RGB ( 255, 255, 255 ) ); // 设置输入框颜色
	solidrectangle ( width_a, high_a, width_b, high_b );
	LOGFONT f;
	gettextstyle ( &f ); // 获取当前字体设置
	f.lfHeight = 44; // 设置字体高度为 44
	_tcscpy_s ( f.lfFaceName, _T ( "黑体" ) ); // 设置字体为黑体
	f.lfQuality = ANTIALIASED_QUALITY; // 设置输出效果抗锯齿 
	settextstyle ( &f ); // 设置字体样式 
	wchar_t shuru[10] = L"玩家名";
	setbkmode ( TRANSPARENT );
	settextcolor ( RGB ( 255, 255, 255 ) ); // 设置字体颜色 
	outtextxy ( width_a + (width_b - width_a) / 2 - textwidth ( shuru ) / 2, high_a - 46, shuru );
	settextstyle ( 30, 0, L"楷体" );
	settextcolor ( RGB ( 0, 0, 0 ) ); // 设置字体颜色
	outtextxy ( width_a + 30, high_a + ((high_b - high_a) / 2 - 15), input_text );// 输出用户输入的字符串

	// 绘制光标 
	setlinecolor ( RGB ( 0, 0, 0 ) ); // 设置光标颜色
	cursor_b = GetTickCount (); // 第二次获取系统时间
	int cursor_width = width_a + 30 + textwidth ( input_text );// 设置光标横坐标
	int cursor_frequency = cursor_b - cursor_a; // 计算光标频率
	if ( cursor_frequency <= 200 || cursor_frequency >= 700 ) // 判断是否显示光标
	{
		line ( cursor_width, high_a + 5, cursor_width, high_b - 5 );
	}
	if ( cursor_frequency >= 900 ) // 判断是否更新获取的系统时间
	{
		cursor_a = cursor_b;
	}
}


void DrawInputBox3 ( int width_a, int high_a, int width_b, int high_b)
{
	setfillcolor ( RGB ( 255, 255, 255 ) ); // 设置输入框颜色
	solidrectangle ( width_a, high_a, width_b, high_b );
	LOGFONT f;
	gettextstyle ( &f ); // 获取当前字体设置
	f.lfHeight = 44; // 设置字体高度为 44
	_tcscpy_s ( f.lfFaceName, _T ( "黑体" ) ); // 设置字体为黑体
	f.lfQuality = ANTIALIASED_QUALITY; // 设置输出效果抗锯齿 
	settextstyle ( &f ); // 设置字体样式 
	wchar_t shuru[10] = L"操作按键";
	setbkmode ( TRANSPARENT );
	settextcolor ( RGB ( 255, 255, 255 ) ); // 设置字体颜色 
	outtextxy ( width_a + (width_b - width_a) / 2 - textwidth ( shuru ) / 2, high_a - 46, shuru );
	settextstyle ( 30, 0, L"楷体" );
	settextcolor ( RGB ( 0, 0, 0 ) ); // 设置字体颜色
	outtextxy ( width_a + 30, high_a + ((high_b - high_a) / 2 - 15), input_text );// 输出用户输入的字符串

	// 绘制光标 
	setlinecolor ( RGB ( 0, 0, 0 ) ); // 设置光标颜色
	cursor_b = GetTickCount (); // 第二次获取系统时间
	int cursor_width = width_a + 30 + textwidth ( input_text );// 设置光标横坐标
	int cursor_frequency = cursor_b - cursor_a; // 计算光标频率
	if ( cursor_frequency <= 200 || cursor_frequency >= 700 ) // 判断是否显示光标
	{
		line ( cursor_width, high_a + 5, cursor_width, high_b - 5 );
	}
	if ( cursor_frequency >= 900 ) // 判断是否更新获取的系统时间
	{
		cursor_a = cursor_b;
	}
}


// 添加与删除字符
void AddDeleteCharacter ( wchar_t c )
{
	if ( c != 8 ) // 判断输入是否为BACK键
	{
		if ( c == 27 ) // 判断输入是否为ESC键
		{
			EndBatchDraw (); // 结束绘图
			closegraph (); // 关闭绘图窗口
			exit ( 0 ); // 退出程序
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
}// 获取用户输入
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
	//BeginBatchDraw (); // 开始绘图 
	input_text[0] = '\0';
	text_length = 0;
	cursor_a = GetTickCount (); // 第一次获取系统时间
	wchar_t key; // 用户输入的英文 
	while ( true )
	{
		RECT r = { 200,400,560,500 };
		settextstyle ( 40, 0, L"宋体" );
		settextcolor ( WHITE );
		putimage ( 0, 0, &img_background );
		DrawInputBox1 ( 80, 200, 600, 240 );
		drawtext ( L"按ENTRT进入下一步", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
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
	DWORD dwNum = WideCharToMultiByte ( CP_OEMCP, NULL, wText, -1, NULL, 0, NULL, FALSE );// WideCharToMultiByte的运用
	char* psText; // psText为char*的临时数组，作为赋值给std::string的中间变量
	psText = new char[dwNum];
	WideCharToMultiByte ( CP_OEMCP, NULL, wText, -1, psText, dwNum, NULL, FALSE );// WideCharToMultiByte的再次运用
	szDst = psText;// std::string赋值
	delete[]psText;// psText的清除
}

wchar_t* plname ()
{
	std::string s;
	//cleardevice ();
	loadimage ( &img_background, L"BG.jpg", GIW_WIDTH, GIW_HIGH );
	//BeginBatchDraw (); // 开始绘图 
	input_text[0] = '\0';
	text_length = 0;
	cursor_a = GetTickCount (); // 第一次获取系统时间
	wchar_t key; // 用户输入的英文 
	while ( true || MouseHit () )
	{

		RECT r = { 400,400,560,500 };
		settextstyle ( 40, 0, L"宋体" );
		settextcolor ( WHITE );
		drawtext ( L"按ENTRT进入", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
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
	cursor_a = GetTickCount (); // 第一次获取系统时间
	wchar_t key; // 用户输入的英文 
	while ( true || MouseHit () )
	{
		RECT r = { 400,400,560,500 };
		settextstyle ( 40, 0, L"宋体" );
		settextcolor ( WHITE );
		drawtext ( L"按ENTRT进入", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
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