#pragma once
//#define HORIZON 21
//#define VERTICAL 20
const int HORIZON = 21;
const int VERICAL = 20;

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
