#include "controller.h"
#include"windows.h"
#include <windows.h>
#pragma comment(lib, "Winmm.lib")



int main()//程序入口
{
	PlaySound(TEXT("happy8k.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    Controller c;//声明一个Controller类
    c.Game();//整个游戏循环
    return 0;
   


}
