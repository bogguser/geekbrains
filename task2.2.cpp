
#include <iostream>
#include <string>
using namespace std;

//task1
class Person
{
private:
	string m_name = "Unknow";
	int m_age = 0;
	string m_sex = "Unknow";
	int m_weight = 0;
public:
	Person() = default;

	Person (const string& name, const string& sex, int age, int weight) :
		m_name(name), m_age(age), m_sex(sex), m_weight(weight) {}

	void ChangeName(const string& name)
	{
		m_name = name;
	}

	void ChangeAge(int age)
	{
		m_age = age;
	}

	void ChangeWeight(int weight)
	{
		m_weight = weight;
	}

	void print()
	{
		cout << m_name << " " << m_age << " " << m_weight << " " << m_sex << " ";
	}
};

class Student : public Person
{
private:
	int m_study = 0;
	static int m_counter  ;
public:
	
	Student() {
		m_counter ++;
	}

	Student(const string& name, const string& sex, int age, int weight, int study) :
		Person (name, sex, age, weight), m_study(study) {
		m_counter ++;
	}

	void ChangeStudy(int study)
	{
		m_study = study;
	}

	static int getCounter()
	{
		return m_counter;
	}

	void printStudent()
	{
		print();
		cout << m_study << endl;
	}
	
};
int Student::m_counter = 0;


//task2
class Fruit
{
protected:
	string m_name = "Unknow";
	string m_color = "Unknow";
public:
	Fruit() = default;

	Fruit(const string& name, const string& color) :
		m_name(name), m_color(color) {}

	string getName()
	{
		return m_name;
	}

	string getColor()
	{
		return m_color;
	}
	
};

class Apple : public Fruit
{

	
public:
	Apple() {
		m_name = "apple";
		m_color = "red";
	};

	Apple(const string& color) 
		 {
		m_name = "apple";
		m_color = color;
	}
};

class Banana : public Fruit
{

public:
	Banana() {
		m_name = "Banana";
		m_color = "yellow";
	};

	
};

class GrannySmith : public Apple
{
public:
	GrannySmith() {
		m_name = "GrannySmith apple";
		m_color = "green";
	};

	
};


int main()
{
	//task1
	{
		cout << "task1\n";
		Student stud1;
		Student stud2("Ivan", "male", 23, 80, 1);
		Student stud3;
		cout << "Count object: " << Student::getCounter() << endl;
		stud2.printStudent();
		cout << "-------------\n";
	}
	//task2
	cout << "task2\n";
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}

