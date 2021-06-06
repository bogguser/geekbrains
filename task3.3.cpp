

#include <iostream>
#include <list>
#include <cstdlib>
#include <vector>
using namespace std;
//task1
void task1(list<float> list1) {
    float sum = 0.0;
    int size = list1.size();
    for (float n : list1) {
        sum = sum + n;
     
    }
    sum = sum / size;
    list1.push_back(sum);
    for (float n : list1)
        std::cout << n << " ; ";

}

//task2

int rrand(int range_min, int range_max) {
    return rand() % (range_max - range_min + 1) + range_min;
}


class MATRIX
{
private:
    int m = 2;
    int n = 2;
    int M[2][2];
public:
    MATRIX() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                M[i][j] = rrand(1, 100);
            }
        }
    }
    ~MATRIX() {};
    

    void opred()
    {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                M[i][j] = rrand(1, 100);
            }
        }
        int opred = (M[1][1] * M[2][2]) - (M[1][2] * M[2][1]);
        cout << opred;
    };
};


//task3
class iterr {

public:
    iterr() {};
    void range(vector<int>& m)
    {
        auto __begin = m.begin();
        auto __end = m.end();
        for (; __begin != __end; ++__begin) {
            auto x = *__begin;
            cout << x << " ";
        }
    }
};
int main()
{
    //task1
    list<float> list1 = { 1.2, 2.1, 3.3, 4.6, 5.5 };
    task1(list1);
    cout << "\n";
    //task2
    MATRIX M;
    M.opred();
    cout << "\n";
    //task3
    vector<int>m{ 1, 2, 3, 4, 5 };
    iterr it;
    it.range(m);
}


