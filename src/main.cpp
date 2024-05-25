#include <iostream>
//#include <vector>
//#include "randomiii.h"
#include "Listint.h"

void randomy(Listint& list, int count) {
	for (int i = 0; i < count; i++) {
		list.addElement(rand() % 100);
	}
}

int main() {
	srand(time(0));
	setlocale(LC_ALL, "rus");

	/*
	Container<Container<Man>> man_of_man;

	Container<Man> mans;

	ListNode<Container<Man>> node = ListNode<Container<Man>>(mans);

	randomlyFillMan(mans, 10);
	mans.print();

	man_of_man.addElement(mans);
	 
	auto it = mans.begin();
	for (; it != mans.end(); ++it) {
		if ((*it).getAge() >= 45) {
			std::cout << (*it).to_string() << '\n';
		}
	}
	*/
	Listint l;
	randomy(l, 10);
	l.print();

	auto it = l.begin();
	++it;
	for (; it != l.end(); ++it) {
		std::cout << *it << '\n';
	}
	l.clear();

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