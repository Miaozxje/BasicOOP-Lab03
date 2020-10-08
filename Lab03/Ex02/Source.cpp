#include <iostream>
#include <string>
using namespace std;
class SoNguyenLon
{
private:
	string Num;
	int range = 0;
	static SoNguyenLon NguyenMax;
public:
	SoNguyenLon()
	{
		Num = "0";
	};
	SoNguyenLon(int value)
	{
		Num = to_string(value);
		range = Num.size();
		SoNguyenLon temp = *this - NguyenMax;
		if (temp.Num != "0")
			NguyenMax = *this;
	}
	SoNguyenLon(int value, int n)
	{
		range = n;
		if(range <= 100)
			for (int i = 0; i < range; i++)
				Num += to_string(value);
		else cout <<"Overflow of range value!!!!\n";
		SoNguyenLon temp = *this - NguyenMax;
		if (temp.Num != "0")
			NguyenMax = *this;
	};
	SoNguyenLon operator-(SoNguyenLon b)
	{
		SoNguyenLon a = *this;
		SoNguyenLon Result;
		Result.Num.erase(0, 1);
		reverse(a.Num.begin(), a.Num.end());
		reverse(b.Num.begin(), b.Num.end());
		int n1 = a.range;
		int n2 = b.range;
		if (n1 > n2)
			for (int i = 0; i < (n1 - n2); i++)
				b.Num.push_back('0');
		else if (n1 < n2)
		{
			Result.Num = '0';
			Result.range = 0;
			return Result;
		}
		else if (n1 == n2)
		{
			for (int i = a.Num.size() - 1; i >= 0; i--)
			{
				bool flag = false;
				if (a.Num[i] < b.Num[i]) flag = true;
				if (flag)
				{
					Result.Num = '0';
					Result.range = 0;
					return Result;
				}
			}
		}
		for (int i = 0; i < n1; i++)
		{
			if (a.Num[i] > b.Num[i]) Result.Num += a.Num[i] - b.Num[i] + 48;
			else if (a.Num[i] == b.Num[i]) Result.Num += '0';
			else 
			{
				int temp1 = a.Num[i] - 48;
				temp1 += 10;
				int temp2 = b.Num[i] - 48;
				Result.Num += to_string(temp1 - temp2);
				a.Num[i + 1]--;
				int count = 1;
				while (a.Num[i + count] == 47)
				{
					a.Num[i + count++] = 57;
					a.Num[i + count]--;
				}
			}
			Result.range++;
		}
		reverse(Result.Num.begin(), Result.Num.end());
		return Result;
	}
	SoNguyenLon operator+(int n)
	{
		SoNguyenLon a = *this;
		SoNguyenLon b(n);
		SoNguyenLon Result;
		Result.Num.erase(0, 1);
		reverse(a.Num.begin(), a.Num.end());
		reverse(b.Num.begin(), b.Num.end());
		int i = 0;
		bool flag = false;
		int n1 = a.range;
		int n2 = b.range;
		if (n1 > n2)
			for (int i = n2; i < n1; i++)
				b.Num.push_back('0');
		else 
			for (int i = n1; i < n2; i++)
				a.Num.push_back('0');
		while (a.Num[i] != NULL || b.Num[i] != NULL)
		{
			int temp = a.Num[i] - 48 + b.Num[i] - 48;
			if (flag) temp++;
			if (temp < 10)
			{
				Result.Num += to_string(temp);
				flag = false;
			}
			else
			{
				Result.Num += to_string(temp - 10);
				flag = true;
			}
			Result.range++;
			i++;
		}
		if (Result.range > 100)
		{
			Result.Num = '0';
			Result.range = 0;
			cout << "Result of operator+ is out of range !!!!";
			return Result;
		}
		SoNguyenLon temp = Result - NguyenMax;
		if (temp.Num != "0")
			NguyenMax = Result;
		reverse(Result.Num.begin(), Result.Num.end());
		return Result;
	}
	static SoNguyenLon SNLMax()
	{
		return NguyenMax;
	}
	friend SoNguyenLon operator-(int n, SoNguyenLon b)
	{
		SoNguyenLon a(n);
		SoNguyenLon Result;
		Result = a - b;
		return Result;
	}
	friend ostream& operator<<(ostream& os, const SoNguyenLon& S)
	{
		os << S.Num;
		return os;
	}
};
SoNguyenLon SoNguyenLon::NguyenMax;
void main()
{
	SoNguyenLon snl1;
	SoNguyenLon snl2(1234567);
	SoNguyenLon snl3(3, 14);
	SoNguyenLon snl4(9, 20);
	SoNguyenLon snl5 = snl3 - snl2;
	SoNguyenLon snl6 = 45678910 - snl2;
	SoNguyenLon snl7 = snl4 - snl3 + 123456789;
	cout << snl1 << endl << snl2 << endl << snl3 << endl << snl4 << endl << snl5 << endl << snl6 << endl <<snl7 << endl;
	cout << endl << "SoNguyenLon Max:" << endl;
	cout << SoNguyenLon::SNLMax() << endl;
}