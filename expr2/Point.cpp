#include <iostream>
#include "Point.h"
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
