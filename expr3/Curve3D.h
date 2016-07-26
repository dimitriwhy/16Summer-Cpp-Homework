#ifndef HIT_CS_CURVE3D
#define HIT_CS_CURVE3D

class ListNode{
	/*
	  链表结点类，每一个链表中的结点存一个Point3D类
	 */
	friend class Curve3D;
protected :
	Point3D p;
	ListNode *next;
public:
	ListNode();
	ListNode(const ListNode &pl); //拷贝构造
	ListNode(const Point3D &pp); //利用某个点构造
	~ListNode();
	Point3D get_p() const;
	ListNode* get_next() const;
	void set_next(ListNode * ne);
};
class Curve3D{
private :
	ListNode *head;
	int tot;
public :
	Curve3D();
	Curve3D(const Curve3D & oc);
	~Curve3D();
    ListNode* begin() const;
	Curve3D operator + (const Point3D & p) const;
	Curve3D operator = (const Curve3D  c) ; //重载等于号解决浅拷贝
	double CurveLen() const;
	void DisplayCurve();
};

#endif
