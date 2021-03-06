#include <iostream>
#include <string>

// Part 1
class Person {
public:
	Person(std::string _name, unsigned int _age, unsigned int _weight)
	: m_name(_name), m_age(_age), m_weight(_weight)
	{}

	~Person() {}

	void set_name(std::string _name) {
		m_name = _name;
	};

	void inc_age() {
		m_age++;
	};

	void dec_age() {
		m_age--;
	};

	void inc_weight() {
		m_weight++;
	};

	void dec_weight() {
		m_weight--;
	};

	std::string get_name() {
		return m_name;
	};

	unsigned int get_age() {
		return m_age;
	};

	unsigned int get_weight() {
		return m_weight;
	};

private:
	std::string m_name;
	unsigned int m_age;
	unsigned int m_weight;
};

class Student : public Person {
public:
	Student(std::string _name, unsigned int _age, unsigned int _weight, unsigned int _study_year)
	: Person(_name, _age, _weight), m_study_year(_study_year)
	{
		m_pos_num = s_count++;
	}

	~Student() {
		s_count--;
	}

	static unsigned int s_count;

	unsigned int get_study_year() {
		return m_study_year;
	};

	void inc_study_year() {
		m_study_year++;
	};

	unsigned int get_pos_num() {
		return m_pos_num;
	};

	void get_info() {
		std::cout << "\n" << get_pos_num() << ":"
			<< "\nName: " << get_name()
			<< "\nAge: " << get_age()
			<< "\nWeight: " << get_weight()
			<< "\nYear of study: " << get_study_year() << "\n";
	};

private:
	unsigned int m_study_year;
	unsigned int m_pos_num;
};

unsigned int Student::s_count;

// Part 2
class Fruit {
public:
	Fruit(std::string _name, std::string _color) : m_name(_name), m_color(_color) {}
	~Fruit() {}

	std::string get_name() {
		return m_name;
	};
	
	std::string get_color() {
		return m_color;
	};
private:
	std::string m_name;
	std::string m_color;
};

class Apple : public Fruit {
public:
	Apple(std::string _name, std::string _color) : Fruit(_name + " apple", _color) {}
	Apple(std::string _color) : Fruit("apple", _color) {}
	~Apple() {}
private:
};

class Banana : public Fruit {
public:
	Banana() : Fruit("banana", "yellow") {}
	~Banana() {}
};

class GrannySmith : public Apple {
public:
	GrannySmith() : Apple("Granny Smith", "green") {}
	~GrannySmith() {}
};

int main(void)
{
	// Part 1
	Student s1("Ivan Ivanov", 19, 76, 2014);
	Student s2("Vladislav Galimyanov", 24, 92, 2022);
	Student s3("Ekaterina Novikova", 22, 62, 2013);

	s1.get_info();
	s1.inc_age();
	s1.set_name("Ivan Smirnov");
	s1.get_info();

	s2.get_info();
	s2.dec_weight();
	s2.inc_study_year();
	s2.get_info();

	s3.get_info();

	// Part 2
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "\nMy " << a.get_name() << " is " << a.get_color() << ".\n";
	std::cout << "My " << b.get_name() << " is " << b.get_color() << ".\n";
	std::cout << "My " << c.get_name() << " is " << c.get_color() << ".\n";
}
