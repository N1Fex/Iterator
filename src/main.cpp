#include <iostream>
//#include <vector>
#include "randomiii.h"


int main() {
	srand(time(0));
	setlocale(LC_ALL, "rus");


	Container<Man> mans;


	randomlyFillMan(mans, 10);
	mans.print();

	 
	auto it = mans.begin();
	for (; it != mans.end(); ++it) {
		if ((*it).getAge() >= 45) {
			std::cout << (*it).to_string() << '\n';
		}
	}

	/* 
	Container<int> con;

	randomlyFill(con, 30);
	con.addElement(16);
	con.print();
	auto it = con.begin();
	++it;
	for (; it != con.end(); ++it) {
		std::cout << *it << '\n';
	}
	con.clear();
	*/
	system("pause");
	return 0;
}