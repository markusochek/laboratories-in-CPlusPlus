//Дан список из n целых чисел 𝑎0, 𝑎1, …, 𝑎𝑛−1(|𝑎𝑖| <=100).
// Найти элемент списка, наиболее близкий по значению к среднему арифметическому всех элементов списка, затем
//   часть списка слева от него переместить вправо, а, наоборот часть списка справа от него переместить влево.

#include <iostream>
#include <iomanip>
#include <locale.h>

struct List
{
	int info;
	List* next;
};

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");

	// Формирование односвязного списка со сторожем
	int n;
	cout << "Введите кол-во элементов списка" << endl;
	cin >> n;

	List* head, * p, * last;
	head = new List; // создание сторожа
	last = head;
	srand(time(NULL));

	for (int i = 0; i < n; i++)
	{
		// создание нового элемента
		p = new List;
		p->info = rand() % 200 - 100;
		last->next = p;
		p->next = NULL;
		last = p;
	}

	// Вывод списка на консоль
	p = head->next; // пропуск сторожа
	while (p != NULL)
	{
		cout << setw(4) << p->info;
		p = p->next;
	}
	cout << endl;

	p = head->next;
	float sum = 0;
	while (p != NULL)
	{
		sum = sum + (p->info);
		p = p->next;
	}
	sum = floor(sum / n);

	cout << "среднее арефмитическое примерно равно " << sum << endl;

	p = head->next;
	int min = 202;
	int j = 0; 
	while (p != NULL)
	{
		if (abs((p->info) - sum) < min)
			min = abs((p->info) - sum);
		p = p->next;
	}

	cout << "минимальная разница между средним арифметическим и числом в последовательности примерно равно "<< min << endl;

	p = head->next;
	List* p0=p;
	while (abs((p->info) - sum) != min)
	{
		p0 = p;
		p = p->next;
	}

	cout<< "искомое число равно " << p->info << endl;

	last->next = p;
	last = p0;
	List* p1 = p->next;
	p->next = head->next;
	head->next = p1;
	p0->next = NULL;
	p0 = head->next;

	// Вывод списка на консоль
	p = head->next; // пропуск сторожа
	while (p != NULL)
	{
		cout << setw(4) << p->info;
		p = p->next;
	}
	cout << endl;

	// Удаление списка из динамической памяти
	p = head;
	while (p != NULL) {
		List* p1 = p->next;
		delete p;
		p = p1;
	}
	head = NULL;

	system("pause");
}