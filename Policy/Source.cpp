#include<iostream>
#include<map>
#include<string>
#include<list>
#include<vector>
#include<fstream>
#include<Windows.h>
#include<conio.h>




using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::pair;

const std::map<int, string> CRIMES =
{
pair<int,string>(1,"Проезд на красный"),
pair<int,string>(2,"Превышение скорости"),
pair<int,string>(3,"езда по всетрчной полосе"),
pair<int,string>(4,"Дрифт на перекресте"),
pair<int,string>(5,"Парковка в неположенном месте"),
pair<int,string>(6,"Оскобрелние офицера"),
pair<int,string>(7,"Вождение в нетрезвом состоянии")
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

std::ofstream& operator << (std::ofstream& ofs, const Crime& obj) {
	
	ofs << obj.get_id() << obj.get_place();
	return ofs;
}

void print(const std::map<string, std::list<Crime>>& base);
void save(const std::map<string, std::list<Crime>>& base, const string& filename);
void load(std::map<string, std::list<Crime>>& base,const string& filename);
int check_prime();
string input_place();
string input_plate();

// Выбор авто по номеру
void number_selection(std::map<string,std::list<Crime>>& base); 
// Выбор авто по диапазону
void number_range(std::map<string, std::list<Crime>>& base);

void menu(std::map<string, std::list<Crime>>& base,const string& filename);


//#define ADD_base

void main() {
	//setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	
	std::map<string, std::list<Crime>> base; 

	/*=
	{
		pair<string,std::list<Crime>>("a555nn",{Crime(1,"ул.ЛЕНИНА"),Crime(2,"ул. Октябрят")}),
		pair<string,std::list<Crime>>("r234er",{Crime(5,"ул.Game"),Crime(6,"Street")}),
		pair<string,std::list<Crime>>("e321tt",{Crime(4,"ул.Революции")})
	}*/
	
	load(base, "base.txt");
	menu(base, "base.txt");

#ifdef ADD_base
	print(base);
	
	int id;
	id=check_prime();
	/*cout << "Введите место происшетсвия: "; 
	cin.ignore();
	std::getline(std::cin,place);*/
	base[input_plate()].push_back(Crime(id,input_place()));

#endif // ADD_base
	
}
void number_range(std::map<string, std::list<Crime>>& base) {
	string num_range_from;
	string num_range_to;
	cout << "\n--------------------------------------\n"<< endl;
	cout << "Введите диапазон от авто: "; cin >> num_range_from;
	cout << "Введите диапазон до авто: "; cin >> num_range_to;
	cout << "\n--------------------------------------\n"<< endl;
	
	system("PAUSE");

}

void number_selection(std::map<string, std::list<Crime>>& base) {
	string nomer_car;
	cout << "\n--------------------------------------\n"<< endl;
	cout << "Введите номер авто: "; cin >> nomer_car;
	
	for (std::map<std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
	{
		if (it->first == nomer_car) 
		{
			for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
			{
				cout << *jt << "; \n";
			}
			cout << "\n--------------------------------------\n";
		}
		
	}
	
	system("PAUSE");
}

void menu(std::map<string, std::list<Crime>>& base,const string& filename) {
	char key;
	do
	{
		system("CLS");
		cout << "1. Вывод всей базый:" << endl;
		cout << "2. Вывод по номерному знаку:" << endl;
		cout << "3. Вывод по диапазону номеров:" << endl;
		cout << "4. Выборка по шаблону:" << endl;
		cout << "5. Выборка по правонарушению:" << endl;
		cout << "6. Выборка по адресам:" << endl;
		cout << "7. Сохраннеи базы:" << endl;
		cout << "8. Загрузка базы:" << endl;
		cout << "9. Доюавление записи:" << endl;

		key = _getch();
		switch (key)
		{
		case '1': print(base); break;
		case '2': number_selection(base); break;
		case '3': number_range(base); break;
		case '4': cout << "НЕ добавлена"; break;
		case '5': cout << "НЕ добавлена"; break;
		case '6': cout << "НЕ добавлена"; break;
		case '7': save(base,filename); break;
		case '8': load(base,filename); break;
		case '9': base[input_plate()].push_back(Crime(check_prime(),input_place())); break;


		default:
			break;
		}
	} while (key!=27);

}
string input_plate() {
	string lincence_plate;
	cout << "Введите номер автомобиля: "; cin >> lincence_plate;
	return lincence_plate;
}

void load(std::map<string, std::list<Crime>>& base, const string& filename) 
{
	
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		while(!fin.eof())
		{
		std::string lincence_plate;
		std::string all_crimes;
		std::getline(fin, lincence_plate, ':');
		std::getline(fin, all_crimes);
		if (lincence_plate.empty() || all_crimes.empty())continue;
		all_crimes.erase(all_crimes.find(';'));
		for (int start = -1, end = 0; end != std::string::npos; start = end)
		{
			start++;
			end = all_crimes.find(',', start);
			std::string place = all_crimes.substr(start, end - start);
			int id = std::stoi(place,0,10);
			place.erase(0, 1);
			//place.erase(place.find_last_of(';'));
			base[lincence_plate].push_back(Crime(id, place));
		}

		}
		fin.close();
	}
	else
	{
		std::cerr << "Error File not found";
	}

}

void save(const std::map<string, std::list<Crime>>& base, const string& filename)
{
	std::ofstream fout(filename);
	for (std::map<string, std::list<Crime>>::const_iterator it = base.begin();
		it != base.end(); ++it)
	{
		fout << it->first << ":";
		for (std::list<Crime>::const_iterator jt = it->second.begin();
			jt != it->second.end(); ++jt)
		{
			fout << *jt << ",";
		}
		fout.seekp(-1, std::ios::cur);
		fout << ";\n";
	}
	fout.close();
	std::string command = "notepad ";
	command += filename;
	system(command.c_str());
}

string input_place() {
	string place;
	cout << "Введите место происшетсвия: ";
	cin.ignore();
	std::getline(std::cin, place);
	return place;
}

int check_prime() {
	system("CLS");
	for (std::pair<int, string> i : CRIMES)
	{
		cout << i.first << "\t" << i.second << endl;
	}
	int id;
	cout << "Выберите правнарушение: "; cin >> id;
	return id;
}

void print(const std::map<string, std::list<Crime>>& base) {
	
	system("CLS");
	for (std::map<std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
	{
		cout << it->first << ": \n";
		for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			cout << *jt << "; \n";
		}
		cout << "\n--------------------------------------\n";
	}

	system("PAUSE");
}