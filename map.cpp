#include "map.h"
#include "windows.h"

void Map::PrintInitmap()//绘制初始地图
{
	for(int i = 0; i < initmap.size();i++)
	{
		initmap[i].Print();
		Sleep(10);
	}
}
