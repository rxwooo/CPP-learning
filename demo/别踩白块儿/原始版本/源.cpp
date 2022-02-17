///////////////////////////////////////////////////
// 程序名称：别踩白块儿（双人版） VC 源代码
// 编译环境：Visual C++ 6.0、2013，EasyX 20140321(beta)
// 作　　者：yangw80 <yw80@qq.com>
// 最后修改：2014-5-26
//
#undef UNICODE
#undef _UNICODE
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>

#define MAXTASK 50							// 定义游戏需要完成的黑块数量

// 定义宏 __sprintf 自适应 vc6 与 vc2013
#if _MSC_VER > 1200
#define __sprintf(...) sprintf_s(__VA_ARGS__)
#else
#define __sprintf sprintf
#endif


// 精确延时函数(可以精确到 1ms，精度 ±1ms)
// 摘自 www.easyx.cn
void HpSleep ( int ms )
{
	static clock_t oldclock = clock ();		// 静态变量，记录上一次 tick

	oldclock += ms * CLOCKS_PER_SEC / 1000;	// 更新 tick

	if ( clock () > oldclock )					// 如果已经超时，无需延时
		oldclock = clock ();
	else
		while ( clock () < oldclock )			// 延时
			Sleep ( 1 );						// 释放 CPU 控制权，降低 CPU 占用率
}


// 游戏状态常量
enum STATUS {
	BEGIN,			// 游戏开始
	RUNNING,		// 游戏运行中
	PASSANI,		// 游戏通过的动画
	PASS,			// 游戏通过
	FAILANI,		// 游戏失败的动画
	FAIL
};			// 游戏失败


// 游戏者类（每个游戏者都有一个独立的游戏区域）
class PLAYER
{
private:
	STATUS	m_status;					// 游戏状态
	char* m_strName;					// 游戏者名称
	POINT	m_offset;					// 界面的偏移量
	char* m_keys;						// 按键

	// 任务
	byte	m_Task[MAXTASK];			// 任务列表
	byte	m_iTask;					// 当前需要执行的任务 ID
	int		m_nextTaskY;				// 界面中下一个任务的 Y 坐标

	// 时钟和游戏记录
	clock_t	m_beginClock;				// 游戏开始的时钟计数
	float	m_bestTime;					// 最佳纪录的完成时间
	float	m_lastTime;					// 最后一次的完成时间

	// 控制失败动画的变量
	byte	m_failErrorKey;				// 按错的键的序号（值为 0、1、2、3）
	RECT	m_failRect;					// 按错的键的区域
	int		m_failFrame;				// 失败后的动画的帧计数

public:
	PLAYER ( char* name, char* keys, int offsetx, int offsety );		// 构造函数
	void Hit ( char key );												// 处理游戏者按键
	void Draw ();													// 绘制该游戏者的游戏界面
private:
	void Init ();						// 初始化当前游戏者的游戏信息
	void DrawFrame ();					// 绘制游戏界面的外框
	void DrawRow ( int baseY, int iTask );	// 绘制游戏界面中的一行任务
	void DrawPass ();					// 绘制通过游戏后的界面
	void DrawFail ();					// 绘制游戏失败后的界面

	// 进行偏移量计算的绘图函数
	void OutTextXY ( int x, int y, LPCTSTR s )							// 在指定位置输出字符串
	{
		outtextxy ( m_offset.x + x, m_offset.y + y, s );
	}
	void OutTextXY ( int x, int y, char c )							// 在指定位置输出字符
	{
		outtextxy ( m_offset.x + x, m_offset.y + y, c );
	}
	void Rectangle ( int x1, int y1, int x2, int y2 )					// 绘制矩形
	{
		rectangle ( m_offset.x + x1, m_offset.y + y1, m_offset.x + x2, m_offset.y + y2 );
	}
	void FillRectangle ( int x1, int y1, int x2, int y2 )				// 绘制有边框填充矩形
	{
		fillrectangle ( m_offset.x + x1, m_offset.y + y1, m_offset.x + x2, m_offset.y + y2 );
	}
	void SolidRectangle ( int x1, int y1, int x2, int y2 )				// 绘制无边框填充矩形
	{
		solidrectangle ( m_offset.x + x1, m_offset.y + y1, m_offset.x + x2, m_offset.y + y2 );
	}
};


// 构造函数
//	参数：
//		name: 游戏者名称
//		keys: 游戏者所用按键（指向长度为 4 的字符串）
//		offsetx, offsety: 游戏者对应的游戏区域在主窗口中的偏移量
PLAYER::PLAYER ( char* name, char* keys, int offsetx, int offsety )
{
	m_strName = name;
	m_keys = keys;
	m_offset.x = offsetx;
	m_offset.y = offsety;

	m_bestTime = 99;	// 设置最佳成绩

	Init ();				// 初始化游戏者
}


// 初始化当前游戏者的游戏信息
void PLAYER::Init ()
{
	// 初始化任务
	for ( int i = 0; i < MAXTASK; i++ )
		m_Task[i] = rand () % 4;

	m_iTask = 0;			// 从第一个任务开始
	m_nextTaskY = 200;			// 设定下一行任务的 Y 坐标，100 是基准，200 表示开始会有下落的动画
	m_status = BEGIN;		// 设置游戏初始状态
	m_failFrame = 0;			// 重置失败后的动画的帧计数

	// 初始化游戏界面
	DrawFrame ();
}


// 绘制该游戏者的游戏界面
void PLAYER::Draw ()
{
	switch ( m_status )
	{
	case PASSANI:			// 游戏成功后的动画
		if ( m_nextTaskY == 100 )
		{
			m_status = PASS;
			DrawPass ();
			break;
		}

	case BEGIN:				// 游戏初次开始
	case RUNNING:			// 游戏运行中
	{
		// 如果画面处于静止，直接返回不再重绘
		if ( m_nextTaskY == 100 )
			return;

		m_nextTaskY -= (m_nextTaskY - 100 + 9) / 10;

		// 绘制完成的任务区
		int rowy = m_nextTaskY;
		int itask = m_iTask;
		do
		{
			rowy -= 100;
			itask--;
			DrawRow ( rowy, itask );
		} while ( rowy > 0 );

		// 绘制未完成的任务区
		rowy = m_nextTaskY;
		itask = m_iTask;
		do
		{
			DrawRow ( rowy, itask );
			rowy += 100;
			itask++;
		} while ( rowy < 400 );

		break;
	}

	case FAILANI:			// 游戏失败后的动画
		DrawFail ();
		break;

	case PASS:				// 游戏通过后的成绩显示
	case FAIL:				// 游戏失败后的成绩显示
		break;
	}
}


// 绘制游戏界面的外框
void PLAYER::DrawFrame ()
{
	// 画外框
	setlinecolor ( 0xfb9700 );
	Rectangle ( 0, 0, 243, 464 );
	setfillcolor ( 0xeca549 );
	settextcolor ( BLACK );
	settextstyle ( 16, 0, "Verdana" );
	setbkmode ( TRANSPARENT );

	// 画姓名区
	SolidRectangle ( 2, 2, 241, 21 );
	int w = textwidth ( m_strName );
	OutTextXY ( (244 - w) / 2, 4, m_strName );

	// 画成绩区
	SolidRectangle ( 2, 23, 241, 42 );
	char tmp[50];
	__sprintf ( tmp, "最好记录：%.3f 秒", m_bestTime );
	OutTextXY ( 10, 26, tmp );

	// 2 <= x <= 241, 44 <= y <= 443 为游戏区

	// 画控制区
	SolidRectangle ( 2, 445, 241, 462 );
	for ( int i = 0; i < 4; i++ )
		OutTextXY ( 2 + i * 60 + 26, 446, m_keys[i] );
}


// 绘制游戏界面中的一行任务
void PLAYER::DrawRow ( int baseY, int iTask )
{
	int fromY = baseY;				// 任务行的起始 y 坐标
	int toY = baseY + 99;			// 任务行的终止 y 坐标

	// 如果 y 坐标超出显示范围，做调整
	if ( fromY < 0 ) fromY = 0;
	if ( toY > 399 ) toY = 399;

	COLORREF c[4];					// 任务行四个方块的颜色
	if ( iTask < 0 )
	{
		for ( int i = 0; i < 4; i++ )
			c[i] = YELLOW;
	}
	else if ( iTask >= MAXTASK )
	{
		for ( int i = 0; i < 4; i++ )
			c[i] = GREEN;
	}
	else
	{
		for ( int i = 0; i < 4; i++ )
			c[i] = WHITE;

		c[m_Task[iTask]] = (iTask < m_iTask) ? LIGHTGRAY : BLACK;
	}

	// 画任务行的四个方块
	setlinecolor ( 0xe9dbd6 );
	for ( int i = 0; i < 4; i++ )
	{
		setfillcolor ( c[i] );
		FillRectangle ( 2 + i * 60, 44 + 399 - fromY, 2 + i * 60 + 59, 44 + 399 - toY );
	}

	// 如果是第一行，在方块儿上写“开始”两个字
	if ( iTask == 0 && m_iTask == 0 )
	{
		int w = textwidth ( "开始" );
		int h = textheight ( "开始" );
		int x = 2 + m_Task[iTask] * 60 + (60 - w) / 2;
		int y = 44 + 399 - 99 - fromY + (100 - h) / 2;
		settextcolor ( WHITE );
		settextstyle ( 16, 0, "Verdana" );
		OutTextXY ( x, y, "开始" );
	}
}


// 绘制通过游戏后的界面
void PLAYER::DrawPass ()
{
	// 绘制成功的背景
	setfillcolor ( GREEN );
	SolidRectangle ( 2, 44, 241, 443 );

	// 输出"成功"
	settextcolor ( WHITE );
	settextstyle ( 60, 0, "Verdana" );
	int w = textwidth ( "成功" );
	OutTextXY ( (244 - w) / 2, 100, "成功" );

	// 输出成绩
	char tmp[100];
	settextstyle ( 32, 0, "Verdana" );
	__sprintf ( tmp, "成绩：%.3f 秒", m_lastTime );
	w = textwidth ( tmp );
	OutTextXY ( (244 - w) / 2, 200, tmp );
	__sprintf ( tmp, "速度：%.3f/s", MAXTASK / m_lastTime );
	OutTextXY ( (244 - w) / 2, 240, tmp );

	// 输出重新开始的提示
	settextstyle ( 16, 0, "Verdana" );
	w = textwidth ( "按任意控制键重新开始" );
	OutTextXY ( (244 - w) / 2, 400, "按任意控制键重新开始" );
}


// 绘制游戏失败后的界面
void PLAYER::DrawFail ()
{
	if ( m_failFrame == 0 )
	{	// 初始化，计算闪烁效果的区域
		m_failRect.left = 3 + m_failErrorKey * 60;
		m_failRect.right = m_failRect.left + 57;
		m_failRect.bottom = m_nextTaskY + 1;
		m_failRect.top = m_nextTaskY + 98;

		if ( m_failRect.top > 398 ) m_failRect.top = 398;
		m_failRect.bottom = 44 + 399 - m_failRect.bottom;
		m_failRect.top = 44 + 399 - m_failRect.top;
	}

	if ( m_failFrame < 60 )
	{	// 实现闪烁效果
		setfillcolor ( ((m_failFrame / 6) % 2 == 0) ? RED : LIGHTRED );
		SolidRectangle ( m_failRect.left, m_failRect.bottom, m_failRect.right, m_failRect.top );
		m_failFrame++;
	}
	else
	{
		// 改变游戏状态
		m_status = FAIL;

		// 绘制失败的背景
		setfillcolor ( RED );
		SolidRectangle ( 2, 44, 241, 443 );

		// 输出"失败"
		settextcolor ( WHITE );
		settextstyle ( 60, 0, "Verdana" );
		int w = textwidth ( "失败" );
		OutTextXY ( (244 - w) / 2, 100, "失败" );

		// 输出历史成绩
		settextstyle ( 20, 0, "Verdana" );
		char tmp[100];
		__sprintf ( tmp, "历史最好成绩：%.3f 秒", m_bestTime );
		w = textwidth ( tmp );
		OutTextXY ( (244 - w) / 2, 200, tmp );

		// 输出重新开始的提示
		settextstyle ( 16, 0, "Verdana" );
		w = textwidth ( "按任意控制键重新开始" );
		OutTextXY ( (244 - w) / 2, 400, "按任意控制键重新开始" );
	}
}


// 处理游戏者按键
void PLAYER::Hit ( char key )
{
	switch ( m_status )
	{
	case BEGIN:				// 游戏初次开始
		if ( strchr ( m_keys, key ) != NULL )
		{
			m_beginClock = clock ();				// 记录游戏开始时的时钟
			m_status = RUNNING;					// 改变游戏状态
		}

	case RUNNING:			// 游戏运行中
	{
		char* pdest = strchr ( m_keys, key );
		byte pos;
		if ( pdest != NULL )						// 判断是否是当前游戏者按键
		{
			pos = pdest - m_keys;				// 计算按键对应的位置

			if ( pos == m_Task[m_iTask] )			// 判断按键是否正确
			{
				// 按键正确
				m_iTask++;
				m_nextTaskY += 100;

				if ( m_iTask == MAXTASK )			// 如果完成了全部任务
				{
					// 计算完成时间
					clock_t t = clock ();
					m_lastTime = ((float)(clock () - m_beginClock)) / CLOCKS_PER_SEC;

					// 更新最好记录
					if ( m_lastTime < m_bestTime )
						m_bestTime = m_lastTime;

					// 将最后一条任务滚动出屏幕
					m_iTask++;
					m_nextTaskY += 100;
					m_status = PASSANI;
				}
			}
			else
			{
				// 按键失败
				m_failErrorKey = pos;
				m_status = FAILANI;
			}
		}

		break;
	}

	case PASSANI:			// 游戏成功后的动画
	case FAILANI:			// 游戏失败后的动画
		break;

	case PASS:				// 游戏通过后的成绩显示
	case FAIL:				// 游戏失败后的成绩显示
		if ( strchr ( m_keys, key ) != NULL )
			Init ();
		break;
	}
}


// 程序入口主函数
int main ()
{

	initgraph ( 640, 480 );					// 创建绘图窗口
	srand ( (unsigned)time ( NULL ) );			// 设置随机函数种子

	setbkcolor ( 0x01bbfb );
	cleardevice ();

	char n1[10]="喜羊羊",  n2[10]="灰太狼",  k1[5]="asdf",  k2[5]="jkl;";
	PLAYER p1 (n1 , k1, 38, 8 );		// 创建游戏者 喜羊羊
	PLAYER p2 ( n2, k2, 358, 8 );	// 创建游戏者 灰太狼

	char c = 0;

	while ( c != 27 )
	{
		while ( _kbhit () )					// 判断是否有按键
		{
			// 按键处理
			c = _getch ();
			p1.Hit ( c );
			p2.Hit ( c );
		}

		// 绘制游戏场景
		p1.Draw ();
		p2.Draw ();

		// 延时
		HpSleep ( 16 );
	}

	// 结束游戏
	closegraph ();							// 关闭绘图窗口
	return 0;
}
