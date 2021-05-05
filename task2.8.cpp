#include <functional>
#include <iostream>
using namespace std;

//task1
template <typename T> 
void div(T & a, T & b)
{
  
    if (b == 0)
        throw "DivisionByZero";
  
    cout << (a / b);
}

//task2
class Ex
{
private:
    double m_x;
public:
    Ex (double x) : m_x(x) {}
    ~Ex (){}
    int getEx() {
        return m_x;
    }
};

class Bar
{
private:
    double m_y = 0;
public:
    Bar() = default;
    ~Bar(){}

    void setBar(double a)
    {
        if ((m_y + a) > 100)
        {
            throw Ex(a*m_y);
        }
        else
            m_y = a;
    }
};


//task3
class OffTheField
{
private:
    string m_error;

public:
    OffTheField(string error) : m_error(error)
    { }
    const char* getError() { return m_error.c_str(); }
};

class IllegalCommand
{
private:
    string m_error;

public:
    IllegalCommand(string error) : m_error(error)
    { }
    const char* getError() { return m_error.c_str(); }
};

class Robot
{
private:
    int m_x = 1;
    int m_y = 1;
public:
    Robot() = default;
    ~Robot() {}

    void movePlusX(int a)
    {
        if ((m_x + a) <= 10)
        {
                m_x += a;
                cout << "X = " << m_x << endl;
        }
        else
            throw OffTheField("Not plus X");

    }
    void movePlusY(int a)
    {
        if ((m_y + a) <= 10)
        {
        m_y += a;
        cout << "Y = " << m_y << endl;
        }
        else
            throw OffTheField("Not plus Y");
    }

    void moveMinusX(int a)
    {
        if ((m_x + a) >= 10)
        {
            m_x -= a;
            cout << "X = " << m_x << endl;
        }
        else
            throw OffTheField("Not minus X");
    }

    void moveMinusY(int a)
    {
        if ((m_y + a) >= 10)
        {
            m_y -= a;
            cout << "Y = " << m_y << endl;
        }
        else
            throw OffTheField("Not minus Y");
    }
};


int main()
{
    //task1
  try { 
      int a = 20;
      int b = 2;
        div<int> (a, b);
      
    }

  catch (const char* c) {
      cerr << "b = " << c << endl;
  }

  //task2
  Bar bar;
  try {
      int n = 1;
      while (n != 0)
      {
          cin >> n;
          bar.setBar(n);
      }
  }
  catch (Ex ex){
      cout << "Ex = " <<ex.getEx();
  }

  //task3
  Robot robot;
  try {
      robot.movePlusX(3);
      robot.movePlusX(6);
      robot.movePlusX(8);
  }
  catch (OffTheField& a)
  {
      cout << a.getError() << endl;
  }

}

