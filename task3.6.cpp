
#include <iostream>
#include <thread>
#include <random>
#include <future>
#include <iomanip>
using namespace std;
mutex m;
//task1
void pcout(string s)
{
    cout << s << "\n";
}

//task2
int easy() {
   int a;
    static time_t tval = time(0);
    tval += 10;
    srand(tval);
    while (1)
    {
        int z = 0, kol = 0;
        a = 1 + rand() % 100;
        printf("%d\n", a);
        for (int i = 2; i < a; i++)
        {
            if (a % i == 1)
                continue;
            if (a % i == 0)
            {
                z = 1;
                break;
            }
        }
        if (z == 0)
        {
            printf("chislo prostoe\n");
            break;
        }
        else
            printf("chislo sostavnoe\n");
    }
    return a;
}

int easy2() {
    return easy();
}


//task3
mutex mut_a;
mutex mut_b;
class c1
{
    int n,b, a;

public:
    c1 (int m_n, int m_b, int m_a): n(m_n), b(m_b), a(m_a) {}
    void house();
    void thief();
};
void c1::house()
{
    cout << "in house  " << n << ", " << b << ", " << a << "\n";
    lock_guard<mutex> la{ mut_a };
    this_thread::sleep_for(3s);
    cout <<"thief in house  " << n << ", " << b << ", " << a << "\n";
    lock_guard<mutex> lb{ mut_b };


    
}

void c1::thief()
{
    
    lock_guard<mutex> lb{ mut_b };
    if (n > b && n > a)
    {
        n = 0; return;
    }
    if (b > n && b > a)
    {
        b = 0; return;
    }
    if (a > n && a > b)
    {
        a = 0; return;
    };
    
    lock_guard<mutex> la{ mut_a };
    
}

int main()
{
    //task1
    thread th(pcout, "Hello");
    th.join();
    thread th1(pcout, "World");
    th1.join();
    //task2
    auto easy3(async(launch::async, easy, easy2)); //здесь проблема с async возникла
    //task3
    c1 one(5, 28, 15);
    thread t1 {&c1::house, &one};
    thread t2 {&c1::thief, &one};
    t1.join();
    t2.join();
}

