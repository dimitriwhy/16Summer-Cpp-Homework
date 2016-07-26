#include <iostream>
#include "Point.h"
using namespace std;
Point :: Point() : m_x(0),m_y(0) {}
Point :: Point(double x,double y) : m_x(x),m_y(y) {}
Point :: ~Point() {}
double Point :: get_x() const{
	return m_x;
}
double Point :: get_y() const{
	return m_y;
}
void Point :: set_x(double x){
	m_x = x;
}
void Point :: set_y(double y){
	m_y = y;
}
void Point :: display_point() const{
	cout << "X=" << m_x << " " << "Y=" << m_y << endl;
}
int main(int argv,char *argc[]){
	double x,y;Point p;
	p.display_point();
	p = Point(100,200);
	p.display_point();
	cin >> x >> y;
	p.set_x(x),p.set_y(y);
	p.display_point();
	cout << p.get_x() << " " << p.get_y() << endl;
	return 0;
}
