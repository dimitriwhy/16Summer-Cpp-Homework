using namespace std;
#include "Point.cpp"
#include "Point3D.cpp"
int main(){
	double x,y,z;
	cout << "Input X,Y,Z:" << endl;
	cin >> x >> y >> z;
	Point3D p(x,y,z);
	cout << p.get_x() << " " <<  p.get_y() <<" "  << p.get_z() << endl;
	p.set_x(1);p.set_y(2);p.set_z(3);
	p.display_point();
	return 0;
}
