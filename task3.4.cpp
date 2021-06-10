

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//task1
template <typename T> 
void insert_sorted(vector<T>& v1, int value)
{
    int a = v1.size(); //замер размера вектора
    for (auto it = begin(v1); it != end(v1); ++it)
    {

        if (value < *it) {
            v1.insert(it, value);
            break;
        }
    }
    int b = v1.size();
    if (a == b) { v1.push_back(value); } //если не заходил в цикл т.е value > всех значений
}


//task2


int main()
{
    //task1
    vector<int> v{ 1, 2, 3, 6, 7 };
    insert_sorted(v, 8);
    for (auto n : v)
        cout << n << " ";
    cout << "\n";
    //task2
    vector <double> Asignal(100);
    vector <int> Csignal(100);
    generate(Asignal.begin(), Asignal.begin() + 50, [] {static double current = 0; return current += 0.1; });
    generate(Asignal.begin() + 50, Asignal.end() - 1, [] {static double current = 5; return current -= 0.1; });
    copy(Asignal.begin(), Asignal.end(), Csignal.begin());
    cout << "Asignal: " << "\n";
    for (auto n : Asignal) { cout << n << "\n"; }
    cout << "Csignal: " << "\n";
    for (auto n : Csignal) { cout << n << "\n"; }
    double c = 0;
    for (int i = 0; i < Asignal.size() - 1; ++i)
    {
        double a = Asignal[i] - Csignal[i];
        double b = a * a;
        c += b;
        cout << "Error " << i << " elementa = " << b << "\n";
    }
    cout << "All eror = " << c;
}

