#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#pragma warning (disable: 4996)
using namespace std;

struct Triangle {
	double a, b, c;
	void Getstruct(int one, int two, int three)
	{
		a = one;
		b = two;
		c = three;
	};
	void Increase(double k)
	{
		a = a*k;
		b = b*k;
		c = c*k;
	};
	void Decrease(double k)
	{
		a = a / k;
		b = b / k;
		c = c / k;
	};
	double Perimetr()
	{
		return a + b + c;
	};
	double Area()
	{
		return 0.25*sqrt((a + b + c)*(a + b - c)*(a + c - b)*(b + c - a));
	};
	void Corners(double *corn)
	{
		corn[0] = acos((a*a + c*c - b*b) / (2 * a*c)) * 180 / 3.14159265;
		corn[1] = acos((a*a + b*b - c*c) / (2 * a*b)) * 180 / 3.14159265;
		corn[2] = 180 - corn[0] - corn[1];
	};
};

int main(int argc, char *argv[])
{
	char* str = getenv("QUERY_STRING");


	cout << "Content-type:text/html\n\n";
	cout << "<html>\n";
	cout << "<head>\n";

	cout << "</head>\n";
	cout << "<body>\n";
	//str = "3,4,5,1,3,3,2,3";
	if(str == NULL) 
	{ cout << "ERROR!!!" << "<br>";
	cout << "</body>\n";
	cout << "</html>\n";
	}
	else if (strcmp(str,"") == 0) { 
		cout << "Side???" << "<br>";
		cout << "</body>\n";
		cout << "</html>\n";
	}
	else
	{
		string s = str;

		vector<int> koef;
		int i = 0;
		string temp = "";
		while (i < s.length())
		{
			if (str[i] == ',')
			{
				int k = stoi(temp);
				koef.push_back(k);
				temp = "";
				i++;
			}
			else if (i == s.length() - 1)
			{
				temp += str[i];
				int k = stoi(temp);
				koef.push_back(k);
				i++;
			}
			else
			{
				temp += str[i];
				i++;
			}

		}
		if (koef.size()<3) { 
			cout << "Side???" << "<br>";
			cout << "</body>\n";
			cout << "</html>\n";
		}
		else
		{
			//int i;
			int n = 1, l = 3;
			//cout << "Введите количество треугольников:";
			//cin >> n;
			Triangle *one = new Triangle[1];
			//for (int j = 0; j < n; j++)
			//{
			one[0].Getstruct(koef[0], koef[1], koef[2]);
			//}
			//cout << "Выберете треугольник с которым будете работать: ";
			//cin >> n;
			n = 0;
			cout << "Select:" << "<br>";
			cout << "1 - Increase side" << "<br>";
			cout << "2 - Decrease side" << "<br>";
			std::cout << "3 - Perimeter" << "<br>";
			std::cout << "4 - Area" << "<br>";
			std::cout << "5 - Corners" << "<br>";
			while (l < koef.size())
			{
				//cin >> i;
				switch (koef[l]) {
				case 1:
				{
					//double k;
					//cout << "Введите число: ";
					//cin >> k;
					one[n].Increase(koef[l + 1]);
					std::cout << "Side: a=" << one[n].a << " b=" << one[n].b << " c=" << one[n].c;
					l++;
					break;
				}
				case 2:
				{
					//double k;
					//cout << "Введите число: ";
					//cin >> k;
					one[n].Decrease(koef[l + 1]);
					std::cout << "Side: a=" << one[n].a << " b=" << one[n].b << " c=" << one[n].c;
					l++;
					break;
				}
				case 3:
				{
					std::cout << "Perimeter = " << one[n].Perimetr();
					break;
				}
				case 4:
				{
					std::cout << "Area = " << one[n].Area();
					break;
				}
				case 5:
				{
					double *corn = new double[3];
					one[n].Corners(corn);
					std::cout << "Angle a^c = " << corn[0] << " degrees" << "<br>";
					std::cout << "Angle a^b = " << corn[1] << " degrees" << "<br>";
					std::cout << "Angle b^c = " << corn[2] << " degrees" << "<br>";
					break;
				}
				default:
				{
					std::cout << "ERROR!" << "<br>";
				}
				}
				l++;
				cout << "<br>";
			}
		}
		cout << "</body>\n";
		cout << "</html>\n";
	}
	//system("pause");
	return 0;
}