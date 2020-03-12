#include"snake.h"
#include<conio.h>//此库定义了通过控制台进行数据输入和数据输出的函数
#include"tools.h"
#include <iostream>
using namespace std;

void Snake::InitSnake()
{
	for(int i = 0; i < snake.size(); i++)
	{
		snake[i].PrintCircular();
	}
}

void Snake::Move()//蛇
{
	switch(direction)
	{
	case Direction::UP:
		snake.emplace_back(Point(snake.back().GetX(),snake.back().GetY()-1));
		break;
	case Direction::DOWN:
		snake.emplace_back(Point(snake.back().GetX(),snake.back().GetY()+1));
		break;
	case Direction::LEFT:
		snake.emplace_back(Point(snake.back().GetX()-1,snake.back().GetY()));
		break;
	case Direction::RIGHT:
		snake.emplace_back(Point(snake.back().GetX()+1,snake.back().GetY()));
		break;
	default:
		break;
    
	}
	SetColor(14);
	snake.back().PrintCircular();
}

void Snake::NormalMove()//蛇正常移动，头增长，尾缩短
{
	Move();
	snake.front().Clear();
	snake.pop_front();
	//snake.back().Print();
}


bool Snake::ChangeDirection()//改变方向,如果按下ESC键返回false
{
	char ch;
	if(kbhit())//kbhit函数检查当前是否有键盘输入
	{
		ch = getch();//从控制台读取一个字符，但不显示在屏幕上，所在头文件conio.h
		switch(ch)
		{
	
			case 72:
				if(direction != Direction::DOWN)//如果方向与运动方形相反，无效
					direction = Direction::UP;
				break;
			case 80:
				if(direction != Direction::UP)
					direction = Direction::DOWN;
				break;
			case 75:
				if(direction != Direction::RIGHT)
					direction = Direction::LEFT;
				break;
			case 77:
				if(direction != Direction::LEFT)
					direction = Direction:: RIGHT;
				break;
			
		
		case 27:
			return false;
		default:
			return true;
		}
	}
	return true;
}

bool Snake::GetBigFood(Food & cfood)
{
	if(snake.back().GetX() == cfood.big_x && snake.back().GetY() == cfood.big_y)
	{
		cfood.big_flag = false;
		cfood.big_x = 0;
		cfood.big_y = 0;
		SetCursorPosition(1,0);
		cout << "                                                            " ;
		return true;
	}
	else
		return false;
}

bool Snake::GetFood(const Food & cfood)
{
	if(snake.back().GetX() == cfood.x  && snake.back().GetY() == cfood.y)
		return true;
	else
		return false;
}

bool Snake::HitItself()//撞到自身返回false
{  
	//检测蛇头以外的部分是与蛇头相同
	deque<Point>:: size_type cnt =1;
	Point *head = new Point(snake.back().GetX(),snake.back().GetY());//获得头部坐标
	for(int i = 0; i < snake.size()-1;i++)
	{
		if(snake[i] == snake.back())
			return false;
	}
	return true;
}



bool Snake::OverEdge()//撞到边界返回false
{
	return snake.back().GetX() < 30 &&
           snake.back().GetY() < 30 &&
           snake.back().GetX() > 1  &&
           snake.back().GetY() > 1;
}
