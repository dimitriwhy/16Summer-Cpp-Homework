#ifndef HOME_WORK2
#define HOME_WORK2
class Point{
private :
	double m_x, m_y;
public :
	Point(double x = 0,double y = 0);
	~Point();
	void set_x(double x);
	void set_y(double y);
	double get_x() const;
	double get_y() const;
};
class Circle : public Point {
private :
	double m_r;
public :
	Circle(double x = 0,double y = 0,double r = 0);
	~Circle();
	void set_r(double r);
	double get_r() const;
	double area() const;
};
class Cylinder : public Circle{
private :
	double m_h;
public :
	Cylinder(double x = 0,double y = 0,double r = 0,double h = 0);
	~Cylinder();
	void set_h(double h);
	double get_h() const;
	double volume() const;
};
#endif
