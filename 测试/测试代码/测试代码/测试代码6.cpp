#include<iostream>
using namespace std;
class Point2D {
protected:
	int x; 
	short y;
};
class Point3D : public Point2D {
private:
	short z;
};
int main6() {
	Point2D *p1;
	Point3D *p2;
	p1 = new Point2D;
	p2 = new Point3D;
	cout << "p1£º" << sizeof(*p1) << endl;
	cout << "p2£º" << sizeof(*p2) << endl;
	*p1 = *p2;
	cout << "p1£º" << sizeof(*p1) << endl;
	cout << "p2£º" << sizeof(*p2) << endl;
	return 0;
}