
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;


//task1
template <typename T>

void Unical(T begin, T end)
{
	set<string> MySet;
	copy(begin, end, inserter(MySet, MySet.end()));
	copy(MySet.begin(), MySet.end(), ostream_iterator<string>(cout, " "));
	//не понял как сделать для разных типов, но по коду можно понять что попытки были)
	//set<T> MySet;
	//copy(begin, end, inserter(MySet, MySet.end()));
	//copy(MySet.begin(), MySet.end(), ostream_iterator<T>(cout, " "));
}

//task2
void Pred()
{
	string n1, n2, n3;
	cout << "Pishi 1 predlojenie: ";
	cin >> n1;
	cout << "Pishi 2 predlojenie: ";
	cin >> n2;
	cout << "Pishi 3 predlojenie: ";
	cin >> n3;
	multiset<string> full;
	full.insert(n1);
	full.insert(n2);
	full.insert(n3);
	copy(full.begin(), full.end(), ostream_iterator<string>(cout, "\n"));
}

int main()
{
	//task1                                                                      
	vector<string>string1{ "A", "B", "C", "D", "A"};
	Unical(string1.begin(), string1.end());
	//task2
	Pred();

}
