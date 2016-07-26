#include <iostream>
#include <cmath>
#include "Homework2.hpp"
using namespace std;
Point :: Point(double x,double y) : m_x(x),m_y(y) {}
Point :: ~Point() {}
void Point :: set_x(double x){
	m_x = x;
}
void Point :: set_y(double y){
	m_y = y;
}
double Point :: get_x() const{
	return m_x;
}
double Point :: get_y() const{
	return m_y;
}
Circle :: Circle(double x,double y,double r) :Point(x,y),m_r(r) {}
Circle :: ~Circle() {}
void Circle :: set_r(double r){
	m_r = r;
}
double Circle :: get_r() const{
	return m_r;
}
double Circle :: area() const{
	return acos(-1) * m_r * m_r;
}
Cylinder :: Cylinder(double x,double y,double r,double h) : Circle(x,y,r),m_h(h){}
Cylinder :: ~Cylinder() {}
void Cylinder :: set_h(double h){
	m_h = h;
}
double Cylinder :: get_h() const {
	return m_h;
}
double Cylinder :: volume() const{
	return area() * m_h;
}
int main(){
	Cylinder c(1,2,3,4);
	cout << c.get_x() << " " << c.get_y() << " " << c.get_r() << " " << c.get_h() << endl;
	cout << "Area = " << c.area() << endl;
	cout << "Volume = " << c.volume() << endl;
	c.set_x(5),c.set_y(5),c.set_r(5),c.set_h(5);
	cout << c.get_x() << " " << c.get_y() << " " << c.get_r() << " " << c.get_h() << endl;
	cout << "Area = " << c.area() << endl;
	cout << "Volume = " << c.volume() << endl;

	return 0;
}
