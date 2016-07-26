#ifndef HIT_CS_POINT3D
#define HIT_CS_POINT3D
#include "Point.h"
class Point3D : public Point{
private :
	double m_z;
public :
	Point3D(double x = 0,double y = 0,double z = 0);
	~Point3D();
	void set_z(double z);
	double get_z() const;
	void display_point() const;
};

#endif
