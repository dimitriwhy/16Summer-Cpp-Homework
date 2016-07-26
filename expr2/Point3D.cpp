#include <iostream>
#include "Point3D.h"
Point3D :: Point3D(double x,double y,double z) : Point(x,y), m_z(z) {}
Point3D :: ~Point3D() {}
void Point3D :: display_point() const {
	cout << "X=" << get_x() << ", Y=" << get_y() << ", Z=" << get_z() << endl;
}
double Point3D :: get_z() const{
	return m_z;
}
void Point3D :: set_z(double z){
	m_z = z;
}
