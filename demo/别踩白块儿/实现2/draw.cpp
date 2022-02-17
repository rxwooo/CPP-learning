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
//绘制函数集合：
//1.每行图形绘制定义；
//2.按键失败画面绘制定义；
//3.任务完成画面绘制定义；
//4.实时成绩画面绘制定义；
//5.基本文字输出定义
// 绘制该游戏者的游戏界面
void PLAYER::Draw()
{
	switch (m_status)
	{
	case PASSANI:			// 游戏成功后的动画
		if (m_nextTaskY == 100)
		{
			m_status = PASS;
			DrawPass();
			break;
		}

	case BEGIN:				// 游戏初次开始
	case RUNNING:			// 游戏运行中
	{
		// 如果画面处于静止，直接返回不再重绘
		if (m_nextTaskY == 100)
			return;

		m_nextTaskY -= (m_nextTaskY - 100 + 9) / 10;
		DrawRealTimeScore(m_iTask);
		// 绘制完成的任务区
		int rowy = m_nextTaskY;
		int itask = m_iTask;
		do
		{
			rowy -= 100;
			itask--;
			DrawRow(rowy, itask);//绘制每行的方块

		} while (rowy > 0);

		// 绘制未完成的任务区
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

	case FAILANI:			// 游戏失败后的动画
		DrawFail();
		break;

	case PASS:				// 游戏通过后的成绩显示
	case FAIL:				// 游戏失败后的成绩显示
		break;
	}
}

// 绘制游戏界面的外框
void PLAYER::DrawFrame()
{

	
	// 画外框
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

	// 画姓名区
	SolidRectangle(2, 2, 241, 21);
	int w = textwidth(m_strName);
	OutTextXY((244 - w) / 2, 4, m_strName);

	// 画成绩区
	SolidRectangle(2, 23, 241, 42);
	wchar_t tmp[50];
	_stprintf_s(tmp, L"最好记录： %.3f 秒", g[0]);
	
	OutTextXY(10, 26, tmp);
	// 2 <= x <= 241, 44 <= y <= 443 为游戏区

	// 画控制区
	SolidRectangle(2, 445, 241, 462);
	for (int i = 0; i < 4; i++)
		OutTextXY(2 + i * 60 + 26, 446, m_keys[i]);
	
	//画实时成绩区
	SolidRectangle(2, 462, 241, 562);
	OutTextXY(10, 472, L"已完成的方块数是:");
	OutTextXY(10, 500,L"还需要完成的方块数是:");
	//具体剩余的方块数在其他函数实现
}
// 绘制游戏界面中的一行任务
void PLAYER::DrawRow(int baseY, int iTask)
{
	int fromY = baseY;				// 任务行的起始 y 坐标
	int toY = baseY + 99;			// 任务行的终止 y 坐标

	// 如果 y 坐标超出显示范围，做调整
	if (fromY < 0) fromY = 0;
	if (toY > 399) toY = 399;

	COLORREF c[4];					// 任务行四个方块的颜色

	//最下面的一行是黄色
	if (iTask < 0) //iTask = -1;
	{
		for (int i = 0; i < 4; i++)
			c[i] = YELLOW;
	}
	//完成之后的方块是绿色
	else if (iTask >= MAXTASK)
	{
		for (int i = 0; i < 4; i++)
			c[i] = GREEN;
	}
	//一般情况
	else
	{
		for (int i = 0; i < 4; i++)
			c[i] = WHITE;

		c[m_Task[iTask]] = (iTask < m_iTask) ? LIGHTGRAY : BLACK;
		//按键之后黑色方块将变成灰色
	}

	// 画任务行的四个方块
	setlinecolor(0xe9dbd6);
	for (int i = 0; i < 4; i++)
	{
		setfillcolor(c[i]);
		FillRectangle(2 + i * 60, 44 + 399 - fromY, 2 + i * 60 + 59, 44 + 399 - toY);
	}

	// 如果是第一行，在方块儿上写“开始”两个字
	if (iTask == 0 && m_iTask == 0)
	{
		int w = textwidth(L"开始");
		int h = textheight(L"开始");
		int x = 2 + m_Task[iTask] * 60 + (60 - w) / 2;
		int y = 44 + 399 - 99 - fromY + (100 - h) / 2;
		//寻找首行中黑块中中间位置，并写“开始”两个字
		settextcolor(WHITE);
		settextstyle(16, 0, L"Verdana");
		OutTextXY(x, y, L"开始");
	}
}


// 绘制通过游戏后的界面
void PLAYER::DrawPass()
{
	// 绘制成功的背景
	setfillcolor(GREEN);
	SolidRectangle(2, 44, 241, 443);

	// 输出"成功"
	settextcolor(WHITE);
	settextstyle(60, 0, L"Verdana");
	int w = textwidth(L"成功");
	OutTextXY((244 - w) / 2, 100, L"成功");

	// 输出成绩
	wchar_t tmp[100];
	settextstyle(32, 0, L"Verdana");
	_stprintf_s(tmp, L"成绩：%.3f 秒", m_lastTime);
	w = textwidth(tmp);
	OutTextXY((244 - w) / 2, 200, tmp);
	_stprintf_s(tmp, L"速度：%.3f/s", MAXTASK / m_lastTime);
	OutTextXY((244 - w) / 2, 240, tmp);

	// 输出重新开始的提示
	settextstyle(16, 0, L"Verdana");
	w = textwidth(L"按任意控制键重新开始");
	OutTextXY((244 - w) / 2, 400, L"按任意控制键重新开始");
	//wsprintf()
	swapgrade ( MAXTASK / m_lastTime, m_strName);
	dphb ();
	wphb ();
}


// 绘制游戏失败后的界面
void PLAYER::DrawFail()
{
	if (m_failFrame == 0)
	{	// 初始化，计算闪烁效果的区域
		m_failRect.left = 3 + m_failErrorKey * 60;
		m_failRect.right = m_failRect.left + 57;
		m_failRect.bottom = m_nextTaskY + 1;
		m_failRect.top = m_nextTaskY + 98;

		if (m_failRect.top > 398) m_failRect.top = 398;
		m_failRect.bottom = 44 + 399 - m_failRect.bottom;
		m_failRect.top = 44 + 399 - m_failRect.top;
	}

	if (m_failFrame < 60)
	{	// 实现闪烁效果
		setfillcolor(((m_failFrame / 6) % 2 == 0) ? RED : LIGHTRED);
		SolidRectangle(m_failRect.left, m_failRect.bottom, m_failRect.right, m_failRect.top);
		m_failFrame++;
	}
	else
	{
		// 改变游戏状态
		m_status = FAIL;

		// 绘制失败的背景
		setfillcolor(RED);
		SolidRectangle(2, 44, 241, 443);

		// 输出"失败"
		settextcolor(WHITE);
		settextstyle(60, 0, L"Verdana");
		int w = textwidth(L"失败");
		OutTextXY((244 - w) / 2, 100, L"失败");

		// 输出历史成绩
		settextstyle(20, 0, L"Verdana");
		wchar_t tmp[100];
		_stprintf_s(tmp, L"历史最好成绩：%.3f 秒", m_bestTime);
		w = textwidth(tmp);
		OutTextXY((244 - w) / 2, 200, tmp);

		// 输出重新开始的提示
		settextstyle(16, 0, L"Verdana");
		w = textwidth(L"按任意控制键重新开始");
		OutTextXY((244 - w) / 2, 400, L"按任意控制键重新开始");
	}
}

//绘制实时成绩区
void PLAYER::DrawRealTimeScore(int iTask)
{
	setfillcolor(BLACK);
	SolidRectangle(150, 472, 178, 488);
	SolidRectangle(180, 500, 208, 516);
	wchar_t tmp2[5]; 
	_stprintf_s(tmp2, L"%d", iTask);
	wchar_t tmp3[5];
	_stprintf_s(tmp3, L"%d", MAXTASK - iTask);
	//显示实时成绩
	if (iTask <= MAXTASK)
	{
		OutTextXY(150, 472, tmp2);
		OutTextXY(180, 500, tmp3);
	}
	else
	{
		OutTextXY(150, 472, L"END");
		OutTextXY(180, 500, L"NO");		//划分显示的位置，上同
	}
}


//基本显示函数定义
void PLAYER::OutTextXY(int x, int y, LPCTSTR s)							// 在指定位置输出字符串
{
	outtextxy(m_offset.x + x, m_offset.y + y, s);
}
void PLAYER::OutTextXY(int x, int y, char c)							// 在指定位置输出字符
{
	outtextxy(m_offset.x + x, m_offset.y + y, c);
}
void PLAYER::Rectangle(int x1, int y1, int x2, int y2)					// 绘制矩形
{
	rectangle(m_offset.x + x1, m_offset.y + y1, m_offset.x + x2, m_offset.y + y2);
}
void PLAYER::FillRectangle(int x1, int y1, int x2, int y2)				// 绘制有边框填充矩形
{
	fillrectangle(m_offset.x + x1, m_offset.y + y1, m_offset.x + x2, m_offset.y + y2);
	//4个参数分别是左上和右上的坐标
}
void PLAYER::SolidRectangle(int x1, int y1, int x2, int y2)				// 绘制无边框填充矩形
{
	solidrectangle(m_offset.x + x1, m_offset.y + y1, m_offset.x + x2, m_offset.y + y2);
}

//获取排行榜显示坐标
void getposition (int n)
{
	px = n;
}

//修改排行榜文件
void wphb ()
{
	FILE* f;
	_wfopen_s ( &f, L"phb.txt", L"w, ccs=UTF-8" );
	fwprintf_s ( f, L"%s:%.3f;%s:%.3f;%s:%.3f;", (wchar_t*)n[0], g[0], (wchar_t*)n[1], g[1], (wchar_t*)n[2],  g[2] );
	fclose ( f );
}

//读取排行榜
void rphb ()
{
	int i, j=0, k=0;
	//文件读取
	 errno_t ii=_wfopen_s (&fp, L"phb.txt", L"r+, ccs=UTF-8" );//将文本按照宽字符打开
	fwscanf_s ( fp, L" %[^:]:%f;%[^:]:%f;%[^:]:%f;", n[0], 10, &g[0],n[1], 10, &g[1], n[2], 10, &g[2] );//拆解分类存储数据
	fclose (fp);
}

//显示排行榜文件
void dphb ()
{
	//显示设置
	setfillcolor ( BLACK );
	solidellipse ( 320 * px + 20, 20, 320 * px + 20 + 200, 60 );
	RECT r = { 320 * px+ 20,20,320 * px + 20 + 200,60 };
	settextstyle ( 40, 0, L"宋体" );
	settextcolor ( WHITE );
	drawtext ( L"排行榜", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
	settextstyle ( 20, 0, L"宋体" );

	//逐行显示排行榜
	for(int i = 0; i < 3;i++)
	{
		fillrectangle ( 320 * px+20, 70 + i * 30, 320 * px + 20 + 200, 100 + i * 30);
		swprintf_s ( cj[i], L"%s:  %.3f块/s", n[i], g[i] );//将排行榜数据整合为一个字符串
		RECT a = { 320 * px + 20,70 + i * 30,320 * px + 20 + 200,100 + i * 30 };//设置排行榜显示区域
		drawtext ( cj[i] , &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE );//显示文本
	}
}

//ASCII字符转Unicode
wchar_t* char2wchar ( const char* cchar )
{
	wchar_t* m_wchar;
	int len = MultiByteToWideChar ( CP_ACP, 0, cchar, strlen ( cchar ), NULL, 0 );
	m_wchar = new wchar_t[len + 1];
	MultiByteToWideChar ( CP_ACP, 0, cchar, strlen ( cchar ), m_wchar, len );
	m_wchar[len] = '\0';
	return m_wchar;
}

//Unicode转ASCII
char* wchar2char ( const wchar_t* wchar )
{
	char* m_char;
	int len = WideCharToMultiByte ( CP_ACP, 0, wchar, wcslen ( wchar ), NULL, 0, NULL, NULL );
	m_char = new char[len + 1];
	WideCharToMultiByte ( CP_ACP, 0, wchar, wcslen ( wchar ), m_char, len, NULL, NULL );
	m_char[len] = '\0';
	return m_char;
}

//排行榜数据处理
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