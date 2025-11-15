// ให้เขียนคลาสที่เป็น “container class” สำหรับเก็บค่าของเมทริกซ์ขนาด 2x2 (ง่าย ๆ คือเมทริกซ์ที่มี 4 ค่าคือ 2 แถว 2 คอลัมน์)
//ให้เพิ่ม operator << และ operator >>
//>> ใช้สำหรับรับค่าจากผู้ใช้เข้าไปเก็บในเมทริกซ์
//<< ใช้สำหรับพิมพ์ค่าเมทริกซ์ออกทางหน้าจอ
//ให้ทดสอบคลาสนี้ด้วยค่าที่แตกต่างกัน โดยใช้ constructor เพื่อสร้างเมทริกซ์ และใช้ operator เพื่อรับค่าและพิมพ์ค่าของเมทริกซ์ออกมา

#include <iostream>
#include <string>

using namespace std;

class Matrix2x2 {
    int a, b, c, d;

    public:
        Matrix2x2() {
            a = b = c = d = 0;
        }

    friend ostream& operator<<(ostream& out, const Matrix2x2& m);
    friend istream& operator>>(istream& in, Matrix2x2& m);
};


ostream& operator<<(ostream& out, const Matrix2x2& m) {
    out << m.a << " " << m.b << endl;
    out << m.c << " " << m.d;
    return out;
}

istream& operator>>(istream& in, Matrix2x2& m) {
    in >> m.a >> m.b >> m.c >> m.d;
    return in;
}


int main() {
    Matrix2x2 m;
    cout << "Enter 4 values: ";
    cin >> m;
    cout << "You entered:\n" << m << endl;
    return 0;
}

/* #include <iostream>

using namespace std;
class Matrix2x2
{
public:
	Matrix2x2(double v1, double v2, double v3, double v4)
	{
		v[0][0] = v1;
		v[0][1] = v2;
		v[1][0] = v3;
		v[1][1] = v4;
	}

	void addValue(const double& rhs)
	{
		switch(lastAdded)
		{
		case 0:v[0][0] = rhs;break;
		case 1:v[0][1] = rhs;break;
		case 2:v[1][0] = rhs;break;
		case 3:v[1][1] = rhs;break;
		}
		lastAdded++;
		if (lastAdded > 4)
			lastAdded = 0;
	}

	void operator<<(const double& rhs) 
	{
		addValue(rhs);
	}
	void print(ostream &os) const
	{
		os << v[0][0] << " " << v[0][1] << endl;
		os << v[1][0] << " " << v[1][1] << endl;
	}
private:
	int lastAdded = 0;
	double v[2][2];
};


istream& operator>>(istream& is, Matrix2x2& rhs)
{
	double value;
	is >> value;
	rhs.addValue(value);
	return is;
}


ostream& operator<<(ostream& os, const Matrix2x2& rhs)
{
	rhs.print(os);
	return os;
}

int main(void) {
	Matrix2x2 m(1, 5.5, 6, 9);
	//m << 3;//LEFT intentionally - for clarification
	//m << 4;
	//m << 5;
	//m << 6;
	cin >> m;
	cin >> m;
	cin >> m;
	cin >> m;
	cout << m;
	
	return 0;
}*/