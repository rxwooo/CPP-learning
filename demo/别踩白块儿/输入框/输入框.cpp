#include<graphics.h>
#include<conio.h>
#define GIW_WIDTH 800 // 设置程序窗口尺寸
#define GIW_HIGH 480
IMAGE img_background; // 程序背景图片
DWORD cursor_a, cursor_b; // 定义系统时间变量
wchar_t input_text[45]; // 用户输入的字符串
int text_length; // 用户输入字符串的长度// 绘制输入框和光标
void DrawInputBox ( int width_a, int high_a, int width_b, int high_b )
{
	setfillcolor ( RGB ( 255, 255, 255 ) ); // 设置输入框颜色
	solidrectangle ( width_a, high_a, width_b, high_b );
	LOGFONT f;
	gettextstyle ( &f ); // 获取当前字体设置
	f.lfHeight = 44; // 设置字体高度为 44
	_tcscpy_s ( f.lfFaceName, _T ( "黑体" ) ); // 设置字体为黑体
	f.lfQuality = ANTIALIASED_QUALITY; // 设置输出效果抗锯齿 
	settextstyle ( &f ); // 设置字体样式 
	wchar_t baidu_text[10] = L"Baidu 百度";
	setbkmode ( TRANSPARENT );
	settextcolor ( RGB ( 255, 255, 255 ) ); // 设置字体颜色 
	outtextxy ( width_a + (width_b - width_a) / 2 - textwidth ( baidu_text ) / 2, high_a - 46, baidu_text );
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
}int main ()
{
	initgraph ( 800, 480 );
	loadimage ( &img_background, L"BG.jpg", GIW_WIDTH, GIW_HIGH );
	BeginBatchDraw (); // 开始绘图 
	input_text[0] = '\0';
	text_length = 0;
	cursor_a = GetTickCount(); // 第一次获取系统时间
	wchar_t key; // 用户输入的英文 
	while (true)
	{
		key = GetInput ();
		if ( key != 0 )
		{
			AddDeleteCharacter ( key );
		}
		cleardevice (); // 清除屏幕
		putimage ( 0, 0, &img_background );
		DrawInputBox ( 100, 200, 700, 240 );
		FlushBatchDraw ();
	} 
	closegraph ();
	return 0;
}
