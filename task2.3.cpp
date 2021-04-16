
#include <iostream>

using namespace std;

//task1
class Figure
{
public:
    Figure() {}
    virtual ~Figure() {}

    virtual void area() = 0;

};

class Parallelogram : public Figure
{
private:
    int m_a;
    int m_h;
public:
    Parallelogram() {}
    
    Parallelogram(int x, int y) :
        m_a(x), m_h(y) {}
  

    void area() override {
        cout << "parallelogram area = " << m_a * m_h << endl;

    }
};

class Circle : public Figure
{
private:
    int m_x;
    
public:
    Circle() {}
    Circle(int x) :
        m_x(x) {}
    

    void area() override {
        
        
        cout << "Circle area = " <<pow(m_x, 2) * 3.14 << endl;

    }
};

class Rectangle : public Parallelogram
{
private:
    int m_x;
    int m_y;
public:
    Rectangle() {}
    Rectangle(int x, int y) :
        m_x(x), m_y(y) {}
   

    void area() override {
        cout << "Rectangle area = " << m_x * m_y << endl;

    }
};

class Square : public Parallelogram
{
private:
    int m_x;
    int m_y;
public:
    Square() {}
    Square(int x) :
        m_x(x){}
   

    void area() override {
        cout << "Square area = " << pow (m_x, 2) << endl;

    }
};

class Rhombus : public Parallelogram
{
private:
    int m_a;
    int m_h;
public:
    Rhombus() {}
    Rhombus(int x, int y) :
        m_a(x), m_h(y) {}
   

    void area() override  {
        cout << "Rhombus area = " << m_a * m_h << endl;

    }
};

//task2

class Car
{
private:
    string m_company;
    string m_model;
public:
     Car () {
        cout << "car construktor\n";
    }
 
    virtual ~Car (){
        cout << "car destruktor\n";
    }

   
};

class PassengerCar : virtual public Car
{
public:
    PassengerCar() {
        cout << "PassengerCar construktor\n";
    }

    ~PassengerCar() {
        cout << "PassengerCar destruktor\n";
    }
        
    
};

class Bus : virtual public Car
{
public:
    Bus() {
        cout << "Bus  construktor\n";
    }

    ~Bus() {
       
        cout << "Bus destruktor\n";
    }

};

class Minivan : public Bus, public PassengerCar
{
public:
    Minivan() {
        cout << "Minivan   construktor\n";
    }

    ~Minivan() {

        cout << "Minivan destruktor\n";
    }


};

//task3



class Fraction
{
private:
    int m_chis = 1;
    int m_znam = 1;
public:
    Fraction(){}
    Fraction(int chis, int znam) :
        m_chis(chis), m_znam(znam) {
        if (chis <= 0 || znam <= 0)
        {
            cout << "chis or znam <=0!!!\n";
            m_chis = 1;
            m_znam = 1;
        };
    }
    Fraction operator+ (const Fraction& a) const {
        return Fraction(m_chis + a.m_chis, m_znam + a.m_znam);
    };
    
    Fraction operator- (const Fraction& a) const {
        return Fraction(m_chis - a.m_chis, m_znam - a.m_znam);
    };

    Fraction operator* (const Fraction& a) const {
        return Fraction(m_chis * a.m_chis, m_znam * a.m_znam);
    };

    Fraction operator/ (const Fraction& a) const {
        return Fraction(m_chis / a.m_chis, m_znam / a.m_znam);
    };

    Fraction operator- () const
    {
        return Fraction(-m_chis, -m_znam);
    }

    int getChis() const { return m_chis; }
    int getZnam() const { return m_znam; }

    friend bool operator== (const Fraction& c1, const Fraction& c2);
    friend bool operator!= (const Fraction& c1, const Fraction& c2);
    friend bool operator> (const Fraction& d1, const Fraction& d2);
    friend bool operator<= (const Fraction& d1, const Fraction& d2);

    friend bool operator< (const Fraction& d1, const Fraction& d2);
    friend bool operator>= (const Fraction& d1, const Fraction& d2);

    void print() {
        cout << "chis = " << m_chis << " znam = " << m_znam << endl;
    }
};

bool operator== (const Fraction& c1, const Fraction& c2)
{
    return (c1.m_chis == c2.m_chis &&
        c1.m_znam == c2.m_znam);
}

bool operator!= (const Fraction& c1, const Fraction& c2)
{
    return !(c1 == c2);
}

bool operator> (const Fraction& d1, const Fraction& d2)
{
    return (d1.m_chis > d2.m_chis &&
        d1.m_znam > d2.m_znam);
}

bool operator>= (const Fraction& d1, const Fraction& d2)
{
    return (d1.m_chis >= d2.m_chis &&
        d1.m_znam >= d2.m_znam);
}

bool operator< (const Fraction& d1, const Fraction& d2)
{
    return (d1.m_chis < d2.m_chis &&
        d1.m_znam < d2.m_znam);
}

bool operator<= (const Fraction& d1, const Fraction& d2)
{
    return (d1.m_chis == d2.m_chis &&
        d1.m_znam == d2.m_znam);
}

//task4

class Card
{
private:
    enum M_SUIT { Hearts , Diamonds, Clubs, Spades};
    enum M_CARD_VALUE { one = 1, two, three, four, five, six, seven, eight, nine, ten = 10, Jack = 2, Queen = 3, King = 4, Ace = 1 };
    int m_value = (int)M_CARD_VALUE(one);
    bool m_card_position = false;   //true = открыта, false = закрыта 
public:
    Card() = default;
    virtual ~Card() {}
    void Flip() {
        if (m_card_position == true) {
            m_card_position = false;

        }
        else {
            m_card_position = true;
        }
    }
    
    int GetValue() const { 
        
        return m_value; };

};

int main()
{
    //task1
    {
        cout << "task1\n";
        Parallelogram pr(2, 3);
        pr.area();
        Circle ci(5);
        ci.area();
        Rectangle re(3, 4);
        re.area();
        Square sq(5);
        sq.area();
        Rhombus rh(5, 6);
        rh.area();
        cout << "----------\n";
    }
    //task2
    {
        cout << "task2\n";
        Car *ps = new PassengerCar;
        delete ps;
        Car* bus = new Bus;
        delete bus;
        Car* mini = new Minivan;
        delete mini;
        cout << "----------\n";
    }
    //task3
    {
        cout << "task3\n";
        Fraction fraction1(3, 6);
        fraction1.print();
        Fraction fraction2(2, 5);
        fraction2.print();
        Fraction fraction3 = fraction1 + fraction2;
        fraction3.print();
        Fraction fraction4 = fraction3 - fraction1;
        fraction4.print();
        Fraction fraction5 = fraction3 * fraction1;
        fraction5.print();
        Fraction fraction6 = fraction5 / fraction1;
        fraction6.print();
        Fraction fr(8,9);
        cout << -fr.getChis() << ", " << -fr.getZnam() << endl;
        
        Fraction one(3, 3);
        Fraction two(3, 3);
        Fraction three(1, 3);
        Fraction four(3, 4);
        if (one == two) {
            cout << "one and two are the same\n";
        }
        if (three != four) {
            cout << "one and two are not the same\n";
        }
        Fraction a(11, 15);
        Fraction b(21, 51);
        if (a > b) {
            cout << "a > b\n";
        }
        if (a < b) {
            cout << "a < b\n";
        }
        if (a >= b) {
            cout << "a >= b\n";
        }
        if (a <= b) {
            cout << "a <= b\n";
        }
        cout << "----------\n";
    }
    //task4
    {
        cout << "task4\n";
        Card card;
        cout<<card.GetValue() << endl;
        
    }
}

