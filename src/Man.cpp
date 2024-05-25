#include "Man.h"

std::string Man::getName() {
	return this->name;
}

std::string Man::getSurname() {
	return this->surname;
}

int Man::getAge() {
	return this->age;
}

int Man::getWeight() {
	return this->weight;
}

Man::Man(std::string name, std::string surname, int age, int weight){
	this->name = name;
	this->surname = surname;
	this->age = age;
	this->weight = weight;
}

std::string Man::to_string() {
	return surname + " " + name + " age: " + std::to_string(age) + " w: " + std::to_string(weight);
}