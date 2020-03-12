#ifndef STARTINTERFACE_H
#define STARTINTERFACE_H
#include "point.h"
#include <vector>
#include <deque>//双端队列也是迭代器
using namespace std;

class StartInterface
{
public:
	StartInterface()
	{   
		speed = 20;
		startsnake.push_back(Point(0,19));
		startsnake.push_back(Point(0,18));//蛇初始化
		startsnake.push_back(Point(0,17));
		startsnake.push_back(Point(0,16));
		startsnake.push_back(Point(0,15));
		startsnake.push_back(Point(1,15));
		startsnake.push_back(Point(2,15));
		startsnake.push_back(Point(2,16));
		startsnake.push_back(Point(2,17));
		startsnake.push_back(Point(2,18));
		startsnake.push_back(Point(2,19));

		//SNAKE初始化
		textsnake.push_back(Point(-26, 14));//S
        textsnake.push_back(Point(-25, 14));
        textsnake.push_back(Point(-27, 15));
        textsnake.push_back(Point(-26, 16));
        textsnake.push_back(Point(-25, 17));
        textsnake.push_back(Point(-27, 18));
        textsnake.push_back(Point(-26, 18));

        textsnake.push_back(Point(-23, 14));//N
        textsnake.push_back(Point(-23, 15));
        textsnake.push_back(Point(-23, 16));
        textsnake.push_back(Point(-23, 17));
        textsnake.push_back(Point(-23, 18));
        textsnake.push_back(Point(-22, 15));
        textsnake.push_back(Point(-21, 16));
        textsnake.push_back(Point(-20, 17));
        textsnake.push_back(Point(-19, 14));
        textsnake.push_back(Point(-19, 15));
        textsnake.push_back(Point(-19, 16));
        textsnake.push_back(Point(-19, 17));
        textsnake.push_back(Point(-19, 18));

        textsnake.push_back(Point(-17, 18));//A
        textsnake.push_back(Point(-16, 17));
        textsnake.push_back(Point(-15, 16));
        textsnake.push_back(Point(-14, 15));
        textsnake.push_back(Point(-14, 16));
        textsnake.push_back(Point(-13, 14));
        textsnake.push_back(Point(-13, 16));
        textsnake.push_back(Point(-12, 15));
        textsnake.push_back(Point(-12, 16));
        textsnake.push_back(Point(-11, 16));
        textsnake.push_back(Point(-10, 17));
        textsnake.push_back(Point(-9, 18));

		textsnake.push_back(Point(-7, 14));//K
        textsnake.push_back(Point(-7, 15));
        textsnake.push_back(Point(-7, 16));
        textsnake.push_back(Point(-7, 17));
        textsnake.push_back(Point(-7, 18));
        textsnake.push_back(Point(-6, 16));
        textsnake.push_back(Point(-5, 15));
        textsnake.push_back(Point(-5, 17));
        textsnake.push_back(Point(-4, 14));
        textsnake.push_back(Point(-4, 18));

        textsnake.push_back(Point(-2, 14));//E
        textsnake.push_back(Point(-2, 15));
        textsnake.push_back(Point(-2, 16));
        textsnake.push_back(Point(-2, 17));
        textsnake.push_back(Point(-2, 18));
        textsnake.push_back(Point(-1, 14));
        textsnake.push_back(Point(-1, 16));
        textsnake.push_back(Point(-1, 18));
        textsnake.push_back(Point(0, 14));
        textsnake.push_back(Point(0, 16));
        textsnake.push_back(Point(0, 18));
	};
    
	void PrintFirst();
	void PrintSecond();
	void PrintThird();
	void PrintText();
	void ClearText();
	void Action();

	


private:
	int speed;//动画速度
	 vector<Point> textsnake;
	 deque<Point> startsnake;



};

#endif
