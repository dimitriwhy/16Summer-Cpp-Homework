#ifndef HIT_CS_CURVE3D
#define HIT_CS_CURVE3D

class ListNode{
	/*
	  �������࣬ÿһ�������еĽ���һ��Point3D��
	 */
	friend class Curve3D;
protected :
	Point3D p;
	ListNode *next;
public:
	ListNode();
	ListNode(const ListNode &pl); //��������
	ListNode(const Point3D &pp); //����ĳ���㹹��
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
	Curve3D operator = (const Curve3D  c) ; //���ص��ںŽ��ǳ����
	double CurveLen() const;
	void DisplayCurve();
};

#endif
