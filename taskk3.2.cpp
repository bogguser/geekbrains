
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


//task1
template <typename T>
void Swap(T& a, T& b)
{
    T neutral = a;
    a = b;
    b = neutral;
}

//task2

    template <typename T>
    void SortPointers(T& a) {
        sort(a.begin(), a.end(), [](int* a, int* b) {return *a > *b; });
        for (auto i : a) {
            cout << *i;
        }
    }



int main()
{
    //task1
    int a = 3;
    int b = 5;
    int* Aptr = &a;
    int* Bptr = &b;
    cout << "task 1" << endl;
    cout << *Aptr << endl;
    cout << *Bptr << endl;
    Swap(Aptr, Bptr);
    cout << *Aptr << endl;
    cout << *Bptr << endl;

    //task2
    cout << "task 2" << endl;
    vector <int> v = { 3,1,5,2,4 };
    vector <int*> p_arr;
    p_arr.resize(v.size());

    for (int i = 0; i < v.size(); i++)
    {
        p_arr[i] = &v[i];
        cout << *p_arr[i];
    }
    cout << "\n";
    SortPointers(p_arr);
    cout << "\n";
    
    //task3
    cout << "task 3" << endl;
    const string eng_cons = "BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz";
    const string eng_glas = "AEIOUYaeiouy";
    string Book = "WarAndPeace";
    cout << "soglasnih: ";
    cout << count_if (Book.begin(), Book.end(), [eng_cons](char currentChar) -> bool {
        return count(eng_cons.begin(), eng_cons.end(), tolower(currentChar));
    }) << endl;
    cout << "glasnih: ";
    cout << count_if(Book.begin(), Book.end(), [eng_glas](char currentChar) -> bool {
        return count(eng_glas.begin(), eng_glas.end(), tolower(currentChar));
    }) << endl;
   
}
