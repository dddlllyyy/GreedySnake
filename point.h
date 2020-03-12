#ifndef POINT_H
#define POINT_H

//Point类声明
class Point
{
 public:
	 Point(const int x, const int y):x(x),y(y){};
	 void Print();
	 void PrintCircular();
	 void Clear();
	 void ChangePosition(const int x, const int y);
	 //操作符重载
	 bool operator == (const Point & point1){return (point1.x == this->x) && (point1.y == this->y);}
	 int GetX(){return this->x;}
	 int GetY(){return this->y;}
private:
	int x,y;

};
#endif
