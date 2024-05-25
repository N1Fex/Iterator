#pragma once
#include <string>

class Man
{
private:
	std::string name;
	std::string surname;
	int age;
	int weight;
public:
	std::string getName();
	std::string getSurname();
	int getAge();
	int getWeight();

	Man(std::string name, std::string surname, int age, int weight);
	std::string to_string();
};

