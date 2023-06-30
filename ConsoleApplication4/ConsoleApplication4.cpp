/*
Шапка программы
постановока задачи:
4.3 Дана квадратная целочисленная матрица.
Найти сумму элементов, расположенных выше побочной диагонали, 
и максимальное значение среди элементов, расположенных ниже побочной диагонали.
*/

#include <iostream>
#include <iomanip>

using namespace std;

void main() {

	const int N = 4, M = 10;
	int a[N][N];

	cout << "integer array" << endl;
	srand(time(NULL));//randomize;
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			a[i][j] = rand() % M + 1;
			cout << setw(4) << a[i][j];

		}

		cout << endl;

	}

	int k = N + 1;
	int S = 0;
	for (int i = 0; i < N; i++) {

		k--;
		for (int j = 0; j < k - 1; j++) {

			S += a[i][j];

		}

	}
	k = N+1;
	int max = 0;
	for (int i = 0; i < N; i++) {

		k--;
		for (int j = k; j < N; j++) {

			if (max < a[i][j]) {

				max = a[i][j];

			}

		}

	}

	cout << "the sum is equal to " << S << endl;
	cout << "the maximum value is exactly " << max << endl;

	system("pause");

}

