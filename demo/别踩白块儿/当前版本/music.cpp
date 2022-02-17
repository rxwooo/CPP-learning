#include "pch.h"
#include "player.h"
#include <graphics.h>
#include <conio.h>

#pragma comment(lib,"Winmm.lib")
//����winmm.lib�⣬ʵ����Ƶ����

//ʵ�ְ�����Ч����
void PLAYER::PlayMusic(int i)
{
	if (i == 0)
	{
		mciSendString(_T("open final1.wav"), NULL, 0, NULL);		//����Ƶ�ļ�1
		mciSendString(_T("play final1.wav"), NULL, 0, NULL);		//������Ƶ�ļ�1
	}
	else if (i == 1)
	{
		mciSendString(_T("open final2.wav"), NULL, 0, NULL);		//����Ƶ�ļ�2
		mciSendString(_T("play final2.wav"), NULL, 0, NULL);		//������Ƶ�ļ�2
	}
	else if (i == 2)
	{
		mciSendString(_T("open final3.wav"), NULL, 0, NULL);		//����Ƶ�ļ�3
		mciSendString(_T("play final3.wav"), NULL, 0, NULL);		//������Ƶ�ļ�3
	}
	else if (i == 3)
	{
		mciSendString(_T("open final4.wav"), NULL, 0, NULL);		//����Ƶ�ļ�4
		mciSendString(_T("play final4.wav"), NULL, 0, NULL);		//������Ƶ�ļ�4
	}
}

//�رհ�����Ч
void PLAYER::CloseMusic(int i)
{
	if (i == 0)
	{
		//mciSendString()���ú�������ͬ
		mciSendString(_T("stop final1.wav"), NULL, 0, NULL);		//ֹͣ������Ƶ�ļ�1
		mciSendString(_T("close final1.wav"), NULL, 0, NULL);	//�ر���Ƶ�ļ�1
	}
	else if (i == 1)
	{
		mciSendString(_T("stop final2.wav"), NULL, 0, NULL);		//ֹͣ������Ƶ�ļ�2
		mciSendString ( _T ( "close final2.wav" ), NULL, 0, NULL );	//�ر���Ƶ�ļ�2

	}
	else if (i == 2)
	{
		mciSendString(_T("stop final3.wav"), NULL, 0, NULL);		//ֹͣ������Ƶ�ļ�3
		mciSendString(_T("close final3.wav"), NULL, 0, NULL);	//�ر���Ƶ�ļ�3

	}
	else if (i == 3)
	{
		mciSendString(_T("stop final4.wav"), NULL, 0, NULL);		//ֹͣ������Ƶ�ļ�4
		mciSendString(_T("close final4.wav"), NULL, 0, NULL);	//�ر���Ƶ�ļ�4
	}
}

//���Ű���������Ч
void PLAYER::PlayFailMusic()
{
	mciSendString(_T("open fail.wav"), NULL, 0, NULL);
	mciSendString(_T("play fail.wav"), NULL, 0, NULL);
}

//�رհ���������Ч
void PLAYER::CloseFailMusic()
{
	mciSendString(_T("stop fail.wav"), NULL, 0, NULL);
	mciSendString(_T("close fail.wav"), NULL, 0, NULL);
}