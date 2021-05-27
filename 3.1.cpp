
#include <iostream>
#include <string>
#include <optional>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

struct Person {
    
    string first_name;
    string last_name;
    optional <string> middle_name;
    

    Person(string a, optional <string> b, string c) : first_name(a), middle_name(b), last_name(c) {}
    void print_person ()
    {

       cout << first_name << " " << last_name;

    }
};


bool operator<(const Person& t1, const Person& t2)
{
    return tie(t1.first_name, t1.middle_name, t1.last_name) <
        tie(t2.first_name, t2.middle_name, t2.last_name);
}

bool operator==(const Person& t1, const Person& t2)
{
    return tie(t1.first_name, t1.middle_name, t1.last_name) <
        tie(t2.first_name, t2.middle_name, t2.last_name);
}

struct PhoneNumber : Person {
    
    int code_country, code_city, number;
    optional <unsigned int> addNumber;
    void print_phone_number (Person)
    {
        cout << "+" << code_country << "(" << code_city << ")" << number;
    }
};


class PhoneBook : PhoneNumber {
private:
    vector <pair <Person, PhoneNumber>> phonebook1;
public:
   
    PhoneBook(ifstream& file);
    friend std::ostream& operator<< (std::ostream& out, const PhoneBook& point);
 
    void GetPhoneNumber(string surname)
    {
        cout << "+" << code_city << "(" << code_country << ")" << number;
    }

    void SortByPhone();
    void SortByName();
    void ChangePhoneNumber(Person a, Person b);
};
std::ostream& operator<< (std::ostream& out, const PhoneBook& point)
{
    out << point.first_name << " " << point.last_name << " " << "+" << point.code_city << "(" << point.code_country << ")" << point.number;
    return out;
}

void PhoneBook::SortByPhone() {
    sort(phonebook1.begin(), phonebook1.end(), sum);

}

void PhoneBook::SortByName() {
    sort(phonebook1.begin(), phonebook1.end(), sum);

}

void PhoneBook::ChangePhoneNumber(Person a, Person b) {
    Person temp = a;
    a = b;
    b = temp;
}

int main() {

    ifstream file ("f:\new\PhoneBook.txt"); // путь к файлу PhoneBook.txt
    PhoneBook book(file);
    cout << book;

    cout << "------SortByPhone-------" << endl;
    book.SortByPhone();
    cout << book;

    cout << "------SortByName--------" << endl;
    book.SortByName();
    cout << book;

    cout << "-----GetPhoneNumber-----" << endl;
    // лямбда функция, которая принимает фамилию и выводит номер телефона этого    	человека, либо строку с ошибкой
    auto print_phone_number = [&book](const string& surname) {
        cout << surname << "\t";
        auto answer = book.GetPhoneNumber(surname);
        if (get<0>(answer).empty())
            cout << get<1>(answer);
        else
            cout << get<0>(answer);
        cout << endl;
    };

    // вызовы лямбды
    print_phone_number("Ivanov");
    print_phone_number("Petrov");

    cout << "----ChangePhoneNumber----" << endl;
    book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" }, PhoneNumber{ 7, 123, "15344458", nullopt });
    book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" }, PhoneNumber{ 16, 465, "9155448", 13 });
    cout << book;
}
