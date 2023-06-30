// ConsoleApplication1d.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <list>

#include <iomanip>

using namespace std;

void main() {

	srand(time(NULL));

	list<int> l;
	list<int> l_klon;
	list<int> L;

	for (int i = 0; i < 10; i++) {

		l.push_back(rand() % 7);

	}

	L = l;

	for (auto x : l) {

		cout << setw(4) << x;

	}

	cout << endl;

	list<int>::iterator it = l.begin();

	list<int>::iterator it2;

	list<int>::iterator itD;

	list<int>::iterator it3;

	int i = 0;

	int n = 0;

	while (it != l.end()) {

		it3 = it;

		it3++;

		it2 = it3;

		i = 0;

		n = *it;

		while (it2 != l.end()) {

			if (n == *it2)

				i++;

			it2++;

		}

		if (i >= 2) {

			it2 = l.begin();

			while (it2 != l.end()) {
				if (*it2 == n) {
					itD = it2;
					it2++;
					l.erase(itD);
				}
				else {
					it2++;
				}
			}
			it = l.begin();
		}
		else {
			it++;
		}
	}

	for (auto x : l) {
		cout << setw(4) << x;
	}

	return;

}

