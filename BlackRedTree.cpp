#include <iostream>
#include "Node.h"
#include "Trees.h"

int main()
{
	system("chcp 1251"); // для корректного отображения слов
	Trees tst;

	int n;
	std::cout << "Введите число (-1: Текущий корень, -2: Выход): ";
	while (std::cin >> n) {
		if (n >= 0)
			std::cout << (tst.add(n) ? "Ok\n" : "Value already exists\n");
		else
			if (n == -1) {
				auto x = tst.getRoot();
				std::cout << *x;
			}
			else if (n == -2)
				break;

		std::cout << "Введите число (-1: Текущий корень, -2: Выход): ";
	}
}

