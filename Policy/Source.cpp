#include<iostream>
#include<map>
#include<string>
#include<list>
#include<vector>
#include<fstream>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::pair;

const std::map<int, string> CRIMES =
{
pair<int,string>(1,"������ �� �������"),
pair<int,string>(2,"���������� ��������"),
pair<int,string>(3,"���� �� ��������� ������"),
pair<int,string>(4,"����� �� ����������"),
pair<int,string>(5,"�������� � ������������ �����"),
pair<int,string>(6,"����������� �������"),
pair<int,string>(7,"�������� � ��������� ���������")
};

class Crime
{
	int id;
	string place;
public:
	int get_id()const
	{
		return id;
	}
	const string& get_place()const
	{
		return place;
	}
	Crime(int id,const string& place):id(id),place(place){}
	~Crime() {}
};

std::ostream& operator << (std::ostream& os, const Crime& obj)
{
	return os << CRIMES.at(obj.get_id()) << "-" << obj.get_place();
};

void main() {
	std::map<string, std::list<Crime>> base =
	{
		pair<string,std::list<Crime>>("a555nn",{Crime(1,"��.������"),Crime(2,"��. ��������")}),
		pair<string,std::list<Crime>>("r234er",{Crime(5,"��.Game"),Crime(6,"Street")}),
		pair<string,std::list<Crime>>("e321tt",{Crime(4,"��.���������")})
	};
}