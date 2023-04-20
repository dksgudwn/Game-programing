#pragma once
//#define HORIZON 21
//#define VERTICAL 20
const int HORIZON = 21;
const int VERTICAL = 20; //전역변수 데이터 영역

//위치
typedef struct _tagpos
{
	int x;
	int y;
}POS, * PPOS;

//플레이어
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

void Init(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer, PPOS _pStartpos, PPOS _pEndpos); // 초기화
void Update(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer); //값을 변경
void Render(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer); //그려주다
