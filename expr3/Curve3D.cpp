#include <bits/stdc++.h>
using namespace std;

#include "Point.h"
#include "Point3D.h"
#include "Curve3D.h"
ListNode :: ListNode():p(Point3D()),next(NULL){}
ListNode :: ListNode(const ListNode &pl){
	p = pl.p;
	if (pl.next != NULL){
		next = new ListNode(*pl.next);
	}else next = NULL;
}
ListNode :: ListNode(const Point3D &pp){
	p = pp;
	next = NULL;
}
ListNode :: ~ListNode(){
	if (next != NULL) //递归释放空间
		delete next;
}
Point3D ListNode :: get_p() const{
	return p;
}
ListNode* ListNode :: get_next() const{
	return next;
}
void ListNode :: set_next(ListNode * ne){
	next = ne;
}

Curve3D :: Curve3D() : head(NULL),tot(0) {}
Curve3D :: Curve3D(const Curve3D & oc){
	tot = oc.tot;
	if (oc.head != NULL){ //特判Curve3D中没有点的情况。
		head = new ListNode(*oc.head); //利用拷贝构造解决浅拷贝。
	}else head = NULL;
}
Curve3D :: ~Curve3D(){
	delete head;
}
ListNode* Curve3D :: begin() const{
	return head;
}
double Curve3D :: CurveLen() const{
	if (tot == 0 || tot == 1) return 0;
	else {
		double length = 0;
		for (ListNode * it = begin();it->get_next() != NULL;it = it->get_next()){
			Point3D p1 = it->p,p2 = it->get_next()->p;
			length += sqrt((p1.get_x() - p2.get_x())*(p1.get_x() - p2.get_x()) + (p1.get_y() - p2.get_y())*(p1.get_y() - p2.get_y())
						   +(p1.get_z() - p2.get_z())*(p1.get_z() - p2.get_z()));
		}
		return length;
	}
}
void Curve3D :: DisplayCurve(){
	cout << "There are(is) " << tot << " point(s)." <<endl;
	for (ListNode * it = begin();it != NULL;it = it->get_next()){
		if (it != begin()) cout << "->";
		cout << "(" << it->p.get_x() << "," << it->p.get_y() << "," << it->p.get_z() << ")";
	}
	cout << endl;
}
Curve3D Curve3D :: operator = (const Curve3D c){
	tot = c.tot;
	if (c.head != NULL){
		head = new ListNode(*c.head); //利用拷贝构造解决浅拷贝
	}else head = NULL;
	return *this;
}
Curve3D Curve3D :: operator + (const Point3D & p) const{
	Curve3D ans = *this; //由于重载了等于号，所以ans得到一个不同的副本。
	if (ans.tot == 0){
		ans.tot = 1;
		ans.head = new ListNode(p);
	}else {
		ans.tot ++;
		ListNode * it = ans.begin();
		while (it->get_next() != NULL) it = it->get_next(); //遍历链表，找到最后一个结点。
		it->next = new ListNode(p);
	}
	return ans;
}
int main(){
	Curve3D c;
	c = c + Point3D();
	c = c + Point3D(1,1,1);
	c = c + Point3D(2,2,2);
	c = c + Point3D(5,6,7);
	c.DisplayCurve();
	cout << c.CurveLen() << endl;
	c = c + Point3D(10,10,10);
	c.DisplayCurve();
	cout << c.CurveLen() << endl;
	return 0;
}
