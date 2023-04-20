#pragma once
//#define HORIZON 21
//#define VERTICAL 20
const int HORIZON = 21;
const int VERTICAL = 20; //�������� ������ ����

//��ġ
typedef struct _tagpos
{
	int x;
	int y;
}POS, * PPOS;

//�÷��̾�
typedef struct _tagplayer
{
	POS tpos;
	int iBombpower;
	int iBombcount;
	bool bWallpush;
	bool bPushOnOff;
	bool bGhost;
}PLAYER, * PPLAYER;

typedef struct _tagboom
{
	int x;
	int y;
	int life;
	bool bDie;
}BOOM, * PBOOM;

void Init(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer, PPOS _pStartpos, PPOS _pEndpos); // �ʱ�ȭ
void Update(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer); //���� ����
void Render(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer); //�׷��ִ�
