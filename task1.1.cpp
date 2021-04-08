#include <iostream>
#include <cstdint>
using namespace std;

/*task1*/
class Power {
private:
    int m_a = 2;
    int m_b = 3;
public:
    void set(int a, int b)
    {
        m_a = a;
        m_b = b;
    }

    void calculate()
    {
        int c = pow(m_a, m_b);
        cout << c << endl;

    }


};

//task2
class Rgba {
private:
    uint8_t m_red = 0;
    uint8_t m_green = 0;
    uint8_t m_blue = 0;
    uint8_t m_alpha = 255;

public:
    Rgba() {};
    Rgba(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
        : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) {}
        
    void print()
    {
        cout << m_red << " " << m_green << " " << m_blue << " " << m_alpha << endl;
    }
    ~Rgba() {};
};

//task3
class Stack
{
private:
    int m_stack = 0;
    int arr[10] = { m_stack };
    
public:
    void reset()
    {
        for (int m_stack = 0; m_stack < 10; m_stack++)
        {
            arr[m_stack] = 0;
        };

    }

    bool push(int a)
    {
        for (int i = 0; i < 10;) {
            if (arr[i] == 0) {
                arr[i] = a;
                m_stack = arr[i];
                return true;
            }
            else {
                i++;
                
            }
        }
        return false;
        
       
    }

    void print()
    {
        cout << "(";
        for (int i = 0; i < 10; i++)
        {
            if (arr[i] == 0) {
            
                
            }
            else {
                cout << arr[i] << " ";
            }
        }
        cout << ")\n";
    }

    bool pop()
    {
        for (int i = 9; i < 10 && i >= 0; i--)
        {
            if (arr[i] != 0)
            {
                arr[i] = 0;
                return true;
            }
        }
        return false;
    }
};
int main()
{
    //task1
    {
        cout << "task 1\n";
        Power power;
        power.set(5, 5);
        power.calculate();
    }
    //task2
    {
        cout << "task 2\n" ;
        Rgba fon(12, 152, 4, 25);
        fon.print();


    }
    //task3
    {
        cout << "task 3\n";
        Stack stack;
        stack.reset();
        stack.print();

        stack.push(3);
        stack.push(7);
        stack.push(5);
        stack.print();

        stack.pop();
        stack.print();

        stack.pop();
        stack.pop();
        stack.print();


    }
    return 0;
}



