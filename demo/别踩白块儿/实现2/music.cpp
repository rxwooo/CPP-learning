#include "pch.h"
#include "player.h"
#include <graphics.h>
#include <conio.h>

#pragma comment(lib,"Winmm.lib")
//导入winmm.lib库，实现音频播放

//实现按键音效播放
void PLAYER::PlayMusic(int i)
{
	if (i == 0)
	{
		mciSendString(_T("open final1.wav"), NULL, 0, NULL);		//打开音频文件1
		mciSendString(_T("play final1.wav"), NULL, 0, NULL);		//播放音频文件1
	}
	else if (i == 1)
	{
		mciSendString(_T("open final2.wav"), NULL, 0, NULL);		//打开音频文件2
		mciSendString(_T("play final2.wav"), NULL, 0, NULL);		//播放音频文件2
	}
	else if (i == 2)
	{
		mciSendString(_T("open final3.wav"), NULL, 0, NULL);		//打开音频文件3
		mciSendString(_T("play final3.wav"), NULL, 0, NULL);		//播放音频文件3
	}
	else if (i == 3)
	{
		mciSendString(_T("open final4.wav"), NULL, 0, NULL);		//打开音频文件4
		mciSendString(_T("play final4.wav"), NULL, 0, NULL);		//播放音频文件4
	}
}

//关闭按键音效
void PLAYER::CloseMusic(int i)
{
	if (i == 0)
	{
		//mciSendString()调用函数，下同
		mciSendString(_T("stop final1.wav"), NULL, 0, NULL);		//停止播放音频文件1
		mciSendString(_T("close final1.wav"), NULL, 0, NULL);	//关闭音频文件1
	}
	else if (i == 1)
	{
		mciSendString(_T("stop final2.wav"), NULL, 0, NULL);		//停止播放音频文件2
		mciSendString ( _T ( "close final2.wav" ), NULL, 0, NULL );	//关闭音频文件2

	}
	else if (i == 2)
	{
		mciSendString(_T("stop final3.wav"), NULL, 0, NULL);		//停止播放音频文件3
		mciSendString(_T("close final3.wav"), NULL, 0, NULL);	//关闭音频文件3

	}
	else if (i == 3)
	{
		mciSendString(_T("stop final4.wav"), NULL, 0, NULL);		//停止播放音频文件4
		mciSendString(_T("close final4.wav"), NULL, 0, NULL);	//关闭音频文件4
	}
}

//播放按键错误音效
void PLAYER::PlayFailMusic()
{
	mciSendString(_T("open fail.wav"), NULL, 0, NULL);
	mciSendString(_T("play fail.wav"), NULL, 0, NULL);
}

//关闭按键错误音效
void PLAYER::CloseFailMusic()
{
	mciSendString(_T("stop fail.wav"), NULL, 0, NULL);
	mciSendString(_T("close fail.wav"), NULL, 0, NULL);
}