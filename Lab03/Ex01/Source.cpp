#include <iostream>
#include <iomanip>
using namespace std;
class HocSinh
{
private:
	string Name;
	float d1, d2, d3, dtb;
	unsigned int mssv;
	static unsigned int ms;
	static HocSinh Max;
public:
	HocSinh()
	{
		Name = "";
		d1 = 0;
		d2 = 0;
		d3 = 0;
		dtb = 0;
		mssv = ++ms;
	};
	HocSinh(const string str, const float t1, const float t2, const float t3)
	{
		Name = str;
		d1 = abs(t1);
		d2 = abs(t2);
		d3 = abs(t3);
		dtb = (d1 + d2 + d3) / 3;
		mssv = ++ms;
		if (dtb > Max.dtb)
			Max = *this;
	};
	void DatHoTen(const string str)
	{
		Name = str;
	};
	void GanDiem(const float t1, const float t2, const float t3)
	{
		d1 = abs(t1);
		d2 = abs(t2);
		d3 = abs(t3);
		dtb = (d1 + d2 + d3) / 3;
	};
	static HocSinh HSDiemTrungBinhCaoNhat()
	{
		return Max;
	};
	friend ostream& operator<<(ostream& os, const HocSinh& hs)
	{
		os << "HS: " << hs.Name << ", MS: " << hs.mssv << ", DTB: " << setprecision(2) << fixed << hs.dtb;
		return os;
	};
};
unsigned int HocSinh::ms = 1363000;
HocSinh HocSinh::Max;
void main()
{
	HocSinh hs1;
	hs1.DatHoTen("Nguyen Van A");
	hs1.GanDiem(7, 8, 10);
	HocSinh hs2("Tran Thi B", 5, 8, 4.5);
	HocSinh hs3("Hoang Thi C", -9.5, 8.5, 4.5);
	HocSinh hs4("Le Van D", 7.5, 9, -10);
	cout << hs1 << endl << hs2 << endl << hs3 << endl << hs4 << endl << endl;
	cout << "Hoc sinh co diem TB cao nhat:" << endl;
	cout << HocSinh::HSDiemTrungBinhCaoNhat() << endl;
}