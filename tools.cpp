#include "tools.h"
#include <windows.h>
#include <stdio.h>

void SetWindowSize(int cols, int lines)//设置窗口大小
{
    system("title 贪吃蛇*");//设置窗口标题
    char cmd[30];
    sprintf(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//一个图形■占两个字符，故宽度乘以2
    system(cmd);//system(mode con cols=88 lines=88)设置窗口宽度和高度
}

void SetCursorPosition(const int x, const int y)//设置光标位置
{
    COORD position;//COORD是Windows API中定义的一种结构，表示一个字符在控制台屏幕上的坐标
    position.X = x * 2;
    position.Y = y;
//GetStdHandle(STD_OUTPUT_HANDLE)返回标准的输出设备的句柄，也就是获得输出的屏幕缓冲区的句柄
//SetConsoleCursorPosition()是一个window api;作用是设置控制台(cmd)光标位置
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void SetColor(int colorID)//设置文本颜色
{
//SetConsoleTextAttribute()是一个可以在API（应用程序编程接口）中设置控制台窗口字体颜色和背景色的计算机函数
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetBackColor()//设置文本背景色
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            FOREGROUND_BLUE |
                            BACKGROUND_BLUE |
                            BACKGROUND_GREEN |
                            BACKGROUND_RED );
}
