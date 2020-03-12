#ifndef SNAKE_H
#define SNAKE_H
#include<deque>
#include"point.h"
#include"food.h"
using namespace std;

class Food;
class Snake
{

public:
	enum Direction{UP,DOWN,LEFT,RIGHT};

	Snake()
	{
		snake.emplace_back(Point(14, 8));
        snake.emplace_back(Point(15, 8));
        snake.emplace_back(Point(16, 8));
        direction = Direction::DOWN;
	}
	void InitSnake();
	void Move();
	void NormalMove();
	bool OverEdge();
	bool HitItself();
	bool ChangeDirection();
	bool GetFood(const Food& );
	bool GetBigFood(Food& );

private:
	std::deque<Point> snake;
	Direction direction;
	friend class Food; //将Food类置为友元，以便访问其实有元素
};


#endif
