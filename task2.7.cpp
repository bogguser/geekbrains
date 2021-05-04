
#include <iostream>

using namespace std;
//task1
class Date
{
private:
    int m_day = 1;
    int m_month = 1;
    int m_year = 2021;
public:
    Date() = default;
    Date(int day, int month, int year) : m_day(day), m_month(month), m_year(year) {}
    ~Date(){}

    friend ostream& operator<< (ostream& out, const Date& date);
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
};

void Date::setDay(int day)
{
    m_day = day;
}

void Date::setMonth(int month)
{
    m_month = month;
}

void Date::setYear(int year)
{
    m_year = year;
}

int Date::getDay() const
{
  
    return m_day;
}

int Date::getMonth() const
{
  
    return m_month;
}

int Date::getYear() const
{
  
    return m_year;
}

ostream& operator<< (ostream& out, const Date& date)
{
    out << "Date: " << date.m_day << "." << date.m_month << "." << date.m_year << "\n";
    return out;
};

//task2
void Sravnenie(Date& date1, Date& date2)
{
    
    if (date1.getYear() > date2.getYear())
    {
        cout << date2;
    }                  
    else if (date1.getYear() < date2.getYear())
    {
        cout << date1;
    }
    else if (date1.getMonth() > date2.getMonth())
    {
        cout << date2;
    }
    else if (date1.getMonth() < date2.getMonth())
    {
        cout << date1;
    }
    else if (date1.getDay() > date2.getDay())
    {
        cout << date2;
    }
    else if (date1.getDay() < date2.getDay())
        cout << date1;
}

void Change(Date& date1, Date& date2)
{
    int day1 = date1.getDay();
    int month1 = date1.getMonth();
    int year1 = date1.getYear();
    date1.setDay(date2.getDay());
    date1.setMonth(date2.getMonth());
    date1.setYear(date2.getYear());
    date2.setDay(day1);
    date2.setMonth(month1);
    date2.setYear(year1);
}

int main()
{
    //task1
    unique_ptr<Date> today = make_unique<Date>(4,5,2021);
    today->getDay();
    today->getMonth();
    today->getYear();
    cout << *today;
    unique_ptr<Date> date = move(today);
    if (date)
        date->getDay();
    else
        cout << "Date is nullptr\n";
    if (today)
        today->getDay();
    else
        cout << "Today is nullptr\n";

    //task2
    unique_ptr<Date> date1 = make_unique<Date>(4, 7, 2020);
    unique_ptr<Date> date2 = make_unique<Date>(8, 9, 2021);
    Sravnenie(*date1, *date2);
    Change(*date1, *date2);
    cout << *date1;
    cout << *date2;

}

