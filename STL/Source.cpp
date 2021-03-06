#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<list>

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n------------------------------------\n"

//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_DEQUE
#define STL_LIST

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_LIST
	int index;
	std::list<int> lst = {10,5,8,9,7,5,2,1,47};
	std::list<int>::iterator it;
	for (it = lst.begin(); it != lst.end(); ++it)
	{
		cout << *it << "\t";
	}
	cout << endl;
	cout << "Input value index: "; cin >> index;
	
	it = lst.begin();
	if (index > 9) index = 9;
	for (int i = 0; i < index; i++)
	{
		it++;
	}
	lst.insert(it, rand()%100);

	for (it = lst.begin(); it != lst.end(); ++it)
	{
		cout << *it << "\t";
	}


#endif // STL_LIST

#ifdef STL_ARRAY
	const int N = 5;
	/*int arr[N] = { 3,5,8 };
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;*/
	std::array<int, N> arr = { 3,5,8,13,21 };
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR
	std::vector<int> vec = { 0,1,1,2,3,5,8,13,21,34 };
	vec.reserve(25);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << tab;
	}
	cout << endl;
	cout << "Size:     " << vec.size() << endl;
	cout << "Max size: " << vec.max_size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;
	cout << delimiter << endl;;
	vec.push_back(55);
	vec.shrink_to_fit();
	cout << "Size:     " << vec.size() << endl;
	cout << "Max size: " << vec.max_size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;
	try
	{
		for (int i = 0; i < vec.capacity(); i++)
		{
			cout << vec.at(i) << tab;
			//cout << vec[i] << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}

	vec.insert(vec.begin() + 3, { 1024, 2048, 3072 });
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
#endif // STL_VECTOR

#ifdef STL_DEQUE
	
	std::deque<int> deque = { 3,5,8,13,21 };
	deque.push_back(34);
	deque.push_back(55);
	deque.push_back(89);

	deque.push_front(2);
	deque.push_front(1);
	deque.push_front(1);
	deque.push_front(0);
	for (int i : deque)
	{
		cout << i << tab;
	}
	cout << endl;
#endif // STL_DEQUE

}