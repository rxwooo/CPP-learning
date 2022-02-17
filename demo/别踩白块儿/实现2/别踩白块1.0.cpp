#pragma comment (lib,"Advapi32.lib")
#include "pch.h"
#include "player.h"
#include <graphics.h>
#include <conio.h>
#include <cstdio>
#include <time.h>
#include <stdlib.h>
#include <cstring>
wchar_t name[5][40];
wchar_t key[5][40];
//游戏开始准备及人物创建
PLAYER **start ( int* N, wchar_t pd ) {
	
	int a;//人数
	if ( pd == 'y' )
	{
		//自由模式
		a= plnum ();	//获取玩家人数
	}
	else
	{
		//默认模式
		a=1;
	}
	if ( a>= 1 && a<= 5 )//控制人数在1~5，否则退出
	{
		rphb ();//读取排行榜文件
		initgraph ( a * 320 + 300, 580 );
		*N = a;
		getposition ( a );//传递显示排行榜坐标

		PLAYER** p = new PLAYER * [5];//获取内存
		if ( pd == 'y' )
		{
			for ( int i = 0; i < a; i++ )
			{
				//获取用户名和按键
				wcscpy_s ( name[i], 20, plname () );
				wcscpy_s ( key[i], 10, plkey () );
			}
			//创建玩家
			for ( int i = 0; i < a; i++ )
			{
				p[i] = new PLAYER ( name[i], key[i], 38 + 320 * i, 2 );
			}
		}
		else
		{
			p[0] = new PLAYER ( L"user", L"asdf", 38, 2 );
		}

		dphb ();//显示排行榜

		//加载音频
		mciSendString ( _T ( "load final1.wav" ), NULL, 0, NULL );
		mciSendString ( _T ( "load final1.wav" ), NULL, 0, NULL );
		mciSendString ( _T ( "load final1.wav" ), NULL, 0, NULL );
		mciSendString ( _T ( "load final1.wav" ), NULL, 0, NULL );
		return p;
	}
	else
	{
		MessageBox ( GetHWnd (), _T ( "INPUT ERROR EXIT" ), _T ( "FAILED" ), MB_OK );
		exit ( 1 );
	}
}

int main()
{
	//加载音频文件
	mciSendString ( _T ( "load BG.wav" ), NULL, 0, NULL );
	mciSendString ( _T ( "open BG.wav" ), NULL, 0, NULL );
	mciSendString ( _T ( "play BG.wav" ), NULL, 0, NULL );

	PLAYER** p; //玩家类数组
	static int N;
	p = start ( &N, startpage1 () );//进入开始界面
	exitbutton1 ( N );//退出按钮
	srand ( (unsigned)time ( NULL ) );		//设置随机函数种子
	setbkcolor ( BLACK );

	mciSendString ( _T ( "stop  BG.wav" ), NULL, 0, NULL );		//停止播放音频文件
	mciSendString ( _T ( "close BG.wav" ), NULL, 0, NULL );	//关闭音频文件
	while ( true )
	{
		char c;
		while ( _kbhit () ) {				//判断是否有按键
			// 按键处理
			c = _getch ();
			for ( int i = 0; i < N; i++ ) {
				(*p[i]).Hit ( c );
			}
		}
		while ( MouseHit () )
		{  
			//鼠标处理
			MOUSEMSG m;
			m = GetMouseMsg ();

			//退出按钮及界面
			if ( 320 * N + 20 < m.x && m.x < 320 * N + 20 + 200 && m.y>420 && m.y < 490 )
			{
				exitbutton2 ( N );
			}
			if ( !(320 * N + 20 < m.x && m.x < 320 * N + 20 + 200 && m.y>420 && m.y < 490) )
			{
				exitbutton1 ( N );
			}
			switch ( m.uMsg ) {
			case WM_LBUTTONDOWN:

				//判断退出
				if ( 320 * N+20 < m.x && m.x < 320 * N +20+ 200 && m.y>420 && m.y < 490 )
				{
					flash_word ( N );
					exit ( 1 );
				}

				//玩家鼠标点击判断
				for ( int i = 0; i < N; i++ )
				{
					if ( 38 + 320 * i + 0 * 60 < m.x && m.x < 38 + 320 * i + 3 * 60 + 59 ) {
						for ( int j = 0; j < 4; j++ ) {
							if ( 38 + 320 * i + j * 60 < m.x && m.x < 38 + 320 * i + j * 60 + 59 ) {
								(*p[i]).Hit ( (*p[i]).m_keys[j] );
								break;
							}
						}
						break;
					}
				}
				break;
			default:
				break;
			}
		}
		// 绘制游戏场景
		for ( int i = 0; i < N; i++ ) {
			p[i]->Draw ();
		}
		// 延时
		HpSleep ( 16 );
	}

	// 结束游戏
	closegraph ();							// 关闭绘图窗口

	return 0;
}