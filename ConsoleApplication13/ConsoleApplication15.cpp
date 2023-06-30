//Пусть дан некоторый список, назовём его основным.
// Индексом по ключу называется список адресов элементов основного списка, выстроенный таким образом,
//  что эти адреса расположены в порядке не убыванию значений ключевого поля основного списка.
// Дан основной список cотрудников(Фамилия, Рост, IQ).Построить индекс по ключу
//Рост и индекс по ключу IQ.Вывести основной список по каждому из индексов.

#include <iostream>
#include <iomanip>
#include <time.h>
#include <locale.h>
#include <string>

using namespace std;
using std::string;

struct List
{
	int IQ;
	int Height;
	string Surname;
	List* pred, * next;
};

struct Listid
{
	List* idIQ, * idHeight;
	Listid* pred, * next;
};


//Функция вставляет элемент p в список после элемента last
// возвращает указатель на вставленный в список элемент
List* insertElementIntoList(List* last, List* p)
{
	if (last && p)
	{
		p->pred = last;
		p->next = last->next;
		last->next = p;
		p->next->pred = p;
		return p;
	}
	else
		return NULL;
}

Listid* insertElementIntoListid(Listid* last, Listid* p)
{
	if (last && p)
	{
		p->pred = last;
		p->next = last->next;
		last->next = p;
		p->next->pred = p;
		return p;
	}
	else
		return NULL;
}

// Функция создает двусвязный список из n элементов с двумя сторожами
// Через head возвращает указатель на головного сторожа, 
// через tail - на хвостового сторожа
void createRandomList(List*& head, List*& tail, int n)
{
	srand(time(NULL));

	head = new List;
	tail = new List;

	head->next = tail;
	tail->pred = head;

	List* last = head;

	string s;
	for (int i = 0; i < n; i++)
	{
		List* p = new List;
		p->IQ = rand() % 50 + 200;
		p->Height = rand() % 30 +180;
		cout << "введите фамилию" << endl;
		cin >> s;
		p->Surname = s;
		last = insertElementIntoList(last, p);
	}

	return;
}

void createListid(Listid*& headid, Listid*& tailid, int n)
{

	headid = new Listid;
	tailid = new Listid;

	Listid* last = headid;

	headid->next = tailid;
	tailid->pred = headid;

	for (int i = 0; i < n; i++)
	{
		Listid* p = new Listid;
		last = insertElementIntoListid(last, p);
	}

	return;
}

// Функция печатает на консоль значения двусвязного списка
// с двумя сторожами head и tail
void printList(List* head, List* tail)
{
	List* p = head->next;
	while (p != tail)
	{
		cout << "IQ:" << setw(4) << p->IQ << "  height:" << setw(4) << p->Height << "  surname:" << p->Surname << endl;
		p = p->next;
	}
	cout << endl;
	return;
}

void printListidIQ(Listid* headid, Listid* tailid)
{
	Listid* p = headid->next;
	while (p != tailid)
	{
		cout << "IQ:" << setw(4) << p->idIQ->IQ << "  height:" << setw(4) << p->idIQ->Height << "  surname:" << p->idIQ->Surname << endl;
		p = p->next;
	}
	cout << endl;
	return;
}

void printListidHeight(Listid* headid, Listid* tailid)
{
	Listid* p = headid->next;
	while (p != tailid)
	{
		cout << "IQ:" << setw(4) << p->idHeight->IQ << "  height:" << setw(4) << p->idHeight->Height << "  surname:" << p->idHeight->Surname << endl;
		p = p->next;
	}
	cout << endl;
	return;
}

//функция сортирует список в порядке возрастания по ключу IQ
void sortIQ(List*& head, List*& tail, Listid*& headid, Listid*& tailid)
{
	cout << "сортировка по ключу IQ" << endl;

	List* p = head->next;
	Listid* p1 = headid->next;

	while (p != tail)
	{
		p1->idIQ = p;
		p = p->next;
		p1 = p1->next;
	}

	Listid* idIQ = headid->next;
	Listid* id = new Listid;
	while (idIQ != tailid)
	{
		Listid* min = idIQ;
		p1 = idIQ;

		while (p1 != tailid)
		{
			if (p1->idIQ->IQ < min->idIQ->IQ)
			{
				min = p1;
			}
			p1 = p1->next;
		}
		id->idIQ = idIQ->idIQ;
		idIQ->idIQ = min->idIQ;
		min->idIQ = id->idIQ;

		idIQ = idIQ->next;
	}
}

void sortHeight(List*& head, List*& tail, Listid*& headid, Listid*& tailid)
{
	cout << "сортировка по ключу Height" << endl;

	List* p = head->next;
	Listid* p1 = headid->next;

	while (p != tail)
	{
		p1->idHeight = p;
		p = p->next;
		p1 = p1->next;
	}

	Listid* idHeight = headid->next;
	Listid* id = new Listid;
	while (idHeight != tailid)
	{
		Listid* min = idHeight;
		p1 = idHeight;

		while (p1 != tailid)
		{
			if (p1->idHeight->Height < min->idHeight->Height)
			{
				min = p1;
			}
			p1 = p1->next;
		}
		id->idHeight = idHeight->idHeight;
		idHeight->idHeight = min->idHeight;
		min->idHeight = id->idHeight;

		idHeight = idHeight->next;
	}
}

//функция сортирует список в порядке возрастания по ключу Height
//void sortHeight(List*& head, List*& tail)
//{
//	cout << "сортировка по ключу Height" << endl;
//	List* head1 = new List;
//	List* tail1 = new List;
//
//	List* last = head1;
//
//	head1->next = tail1;
//	tail1->pred = head1;
//
//	while (head->next != tail)
//	{                  
//		List* min = head->next, * p = head->next;
//		while (p != tail)
//		{
//			if (p->Height < min->Height)
//				min = p;
//			p = p->next;
//		}
//		min->next->pred = min->pred;
//		min->pred->next = min->next;
//
//		last = insertElementIntoList(last, min);
//	}
//	head = head1;
//	tail = tail1;
//}

// Функция удаляет список
void deleteList(List* head, List* tail)
{
	List* p = head;
	while (p != tail)
	{
		List* p1 = p->next;
		delete p;
		p = p1;
	}
	delete tail;
}

void main()
{
	setlocale(LC_ALL, "Rus");

	List* head = NULL, * tail = NULL;
	Listid* headid = NULL, * tailid = NULL;

	cout << "Исходный список" << endl;
	cout << "введите количество человек" << endl;
	int kol;
	cin  >> kol;

	createRandomList(head, tail, kol);
	createListid(headid, tailid, kol);
	printList(head, tail);
	sortIQ(head, tail,headid, tailid);
	printListidIQ(headid, tailid);
	sortHeight(head, tail, headid, tailid);
	printListidHeight(headid, tailid);
	printList(head, tail);
	deleteList(head, tail);
	system("pause");
	return;
}



