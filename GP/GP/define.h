#pragma once
#define SAFE_DELETE(p) if(p) {delete p; p = nullptr;}
const int MAP_x = 50;
const int MAP_y = 10;
enum class STAGE_TYPE
{
	WALL = '0',
	ROAD = '1',
	START = '2',
	END = '3',
	COIN = '4'
};