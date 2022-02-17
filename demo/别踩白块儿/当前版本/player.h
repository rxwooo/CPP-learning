#pragma comment(lib,"easyxw.lib")
#include "pch.h"
#include <graphics.h>
#include <conio.h>
#include <cstdio>
#include <time.h>

#include <cstdio>
#include <iostream>
#include <windows.h>
#include <string>
#undef UNICODE
#undef _UNICODE//��ֹ�����ַ���������

const int MAXTASK = 50; // ������Ϸ��Ҫ��ɵĺڿ��������������õ���100��

// ����� __sprintf ����Ӧ vc6 �� vc2013
#if _MSC_VER > 1200
#define __sprintf(...) sprintf_s(__VA_ARGS__)
#else
#define __sprintf sprintf
#endif

//��ʱ��������
void HpSleep(int ms);

// ��Ϸ״̬��������
enum STATUS {
	BEGIN,			// ��Ϸ��ʼ
	RUNNING,		// ��Ϸ������
	PASSANI,		// ��Ϸͨ���Ķ���
	PASS,			// ��Ϸͨ��
	FAILANI,		// ��Ϸʧ�ܵĶ���
	FAIL			// ��Ϸʧ��
};			

// ��Ϸ���ࣨÿ����Ϸ�߶���һ����������Ϸ����
class PLAYER
{
private:
	STATUS	m_status;						// ��Ϸ״̬
	const wchar_t*	m_strName;					// ��Ϸ������
	//TODO: POINT���ǿ����Դ����࣬�����ڽ���������.
	POINT	m_offset;						// �����ƫ��������ÿ����Ϸ��������Ͻǵ�λ��
						// Ԥ����Ҫ����İ���

	// ���� (��ÿ�л�ɫ�����ţ�
	//byte ���� typedef unsigned char BYTE ���ͱ������޷���char��
	byte	m_Task[MAXTASK];			// �����б�  char �������飻
	byte	m_iTask;					// ��ǰ��Ҫִ�е����� ID | char ��������
	int		m_nextTaskY;				// ��������һ������� Y ����

	// ʱ�Ӻ���Ϸ��¼�� ��ȡʱ��
	clock_t	m_beginClock;				// ��Ϸ��ʼ��ʱ�Ӽ����� ע��typedef long clock_t
	float	m_bestTime;					// ��Ѽ�¼�����ʱ��
	float	m_lastTime;					// ������Ϸ�����ʱ��

	// ����ʧ�ܶ����ı���
	byte	m_failErrorKey;				// ����ļ�����ţ�ֵΪ 0��1��2��3��
	//TODO�� RECT��һ���࣬�����ڳ�������䡣��UMLͼ�εȵȣ�
	RECT	m_failRect;					// ����ļ������� RECTΪһ���࣬���ƾ���
	int		m_failFrame;				// ʧ�ܺ�Ķ�����֡����

public:
	const wchar_t* m_keys;
	PLAYER(const wchar_t* name, const wchar_t* keys, int offsetx, int offsety);		// ���캯��
	void Hit(wchar_t key);												// ������Ϸ�߰���
	void Draw();													// ���Ƹ���Ϸ�ߵ���Ϸ����
	void PlayMusic(int i);											//ʵ��ÿ�ΰ�������Ч
	void CloseMusic(int j);											//ÿ�ΰ���֮ǰ��Ҫ�ر��ϴο�������Ч
	void PlayFailMusic();											//��������������ʧ�ܵ���Ч
	void CloseFailMusic();											//�ر���Ч
private:
	void Init();													// ��ʼ����ǰ��Ϸ�ߵ���Ϸ��Ϣ
	void DrawFrame();												// ������Ϸ��������
	void DrawRow(int baseY, int iTask);								// ������Ϸ�����е�һ������
	void DrawPass();												// ����ͨ����Ϸ��Ľ���
	void DrawFail();												// ������Ϸʧ�ܺ�Ľ���
	void DrawRealTimeScore(int iTask);								// ����ʵʱ��ɵķ���������δ��ɵķ�����
	//�����������ƺ���
	void OutTextXY(int x, int y, LPCTSTR s);						// ��ָ��λ������ַ���
	void OutTextXY(int x, int y, char c);							// ��ָ��λ������ַ�
	void Rectangle(int x1, int y1, int x2, int y2);					// ���ƾ���
	void FillRectangle(int x1, int y1, int x2, int y2);				//�����б߿�������
	void SolidRectangle(int x1, int y1, int x2, int y2);			//�����ޱ߿�������
};

void exitbutton1 ( int n );

void exitbutton2 ( int n );

void flash_word ( int n );

char startpage1 ();

int plnum ();

void Wchar_tToString ( std::string& szDst, wchar_t* wchar );

wchar_t* plkey ();

wchar_t* plname ();

void rphb ();

void dphb ();

wchar_t* char2wchar ( const char* cchar );
void getposition ( int n );
void swapgrade ( float grade, const  wchar_t* Name );
void wphb ();

