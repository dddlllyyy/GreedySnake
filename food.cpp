#include "food.h"
#include "tools.h"
#include <cstdlib>
#include<iostream>
using namespace std;

void Food::DrawFood(Snake & csnake)
{/*利用rand函数获得坐标，并将其范围限制在2-29内，即在地图内，如果获得的坐标与蛇身重叠，则重新获取。
      同时每5颗食物就出现一颗限时食物*/
	while(true)
	{
	int tmp_x = rand() % 30;
	int tmp_y = rand() % 30;
	if(tmp_x < 2) tmp_x += 2;
	if(tmp_y < 2) tmp_y += 2;
	bool flag = false;
	for(int i = 0; i < csnake.snake.size();i++)//检测生成的食物坐标是否与蛇身重叠
	{
		if(tmp_x == csnake.snake[i].GetX()&& tmp_y == csnake.snake[i].GetX())
		{
			flag = true;
			break;
		}
	} 
	if(flag == true)continue;
	x = tmp_x;
	y = tmp_y;
	SetCursorPosition(x,y);
	SetColor(13);
	cout << "★" ;
	cnt++;
	cnt %= 5;
	if(cnt == 0)
	{
		DrawBigFood(csnake);
	}
	break;
  }
}

void Food::DrawBigFood(Snake& csnake)
	{
	SetCursorPosition(5, 0);
    SetColor(11);
    std::cout << "------------------------------------------" ;//进度条
    progress_bar = 42;
    while (true)
    {
        int tmp_x = rand() % 30;
        int tmp_y = rand() % 30;
        if(tmp_x < 2) tmp_x += 2;
        if(tmp_y < 2) tmp_y += 2;
        bool flag = false;
        for(int i = 0; i < csnake.snake.size();i++)//检测生成的食物坐标是否与蛇身重叠
	{
		if(tmp_x == csnake.snake[i].GetX()&& tmp_y == csnake.snake[i].GetX())
		{
			flag = true;
			break;
		}
	} 
        if (flag)
            continue;

        big_x = tmp_x;
        big_y = tmp_y;
        SetCursorPosition(big_x, big_y);
        SetColor(18);
        std::cout << "■" ;
        big_flag = true;
        flash_flag = true;
        break;
    }
	}

bool Food::GetBigFlag()
{
	return big_flag;
}

int Food::GetCnt()
{
	return cnt;
}

int Food::GetProgressBar()
{
	return progress_bar;
}

void Food::FlashBigFood()
{
	 SetCursorPosition(big_x, big_y);
    SetColor(18);
    if (flash_flag)
    {
        std::cout << "  " ;
        flash_flag = false;
    }
    else
    {
        std::cout << "■" ;
        flash_flag = true;
    }

    SetCursorPosition(26, 0);
    SetColor(11);
    for (int i = 42; i >= progress_bar; --i)//进度条缩短
        cout << "\b \b" ;
        --progress_bar;
    if (progress_bar == 0) {
        SetCursorPosition(big_x, big_y);
        cout << "  " ;
        big_flag = false;
        big_x = 0;
        big_y = 0;
    }
}
