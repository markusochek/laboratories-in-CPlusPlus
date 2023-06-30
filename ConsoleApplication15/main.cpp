//Информация о банковских счетах банка «БТВ» представлена следующим набором данных: 
// номер счёта, ФИО владельца, остаток по счёту.
// Построить бинарное деревом поиска, ключом которого является номер счёта.Обеспечить:
//    а) поиск банковского счёта по номеру;
//    б) поиск всех счетов определённого владельца и их общий остаток;
//    в) выдачу всего списка банковских счетов, упорядоченных по номерам;
//    г) удаление счёта по номеру;
//    д) построение другого бинарного дерева поиска, ключом которого является ФИО владельца, и выдача списка банковских счетов, упорядоченного по владельцам.

#include <iostream>
#include <locale.h>
#include <string>
#include <windows.h>
#include <vector>

#include "Person.h"
#include "PersonSBTree.h"
#include "PersonSurNameTree.h"

using namespace std;

int main()
{
	// Локализация по кириллице
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	// ------ Формирование базы данных (бинарное дерево поиска) о персонах
	PersonSBTree dataBase;
	PersonSurNameTree dataBaseSurName;

	// Вставка в базу данных объектов, созданных как локальные
	Person p101(1004, "Собаков", 40000);
	dataBase.insert(p101);
	Person p102(1006, "Петухов", 60000);
	dataBase.insert(p102);

	// Вставка в базу данных объектов, созданных в динамической памяти
	dataBase.insert(*new Person(1003, "Крысов", 30000));
	dataBase.insert(*new Person(1001, "Собаков", 10000));
	dataBase.insert(*new Person(1005, "Котов", 50000));
	dataBase.insert(*new Person(1002, "Петухов", 20000));

	// Вставка в базу данных объектов, созданных как локальные
	dataBaseSurName.insert(p101);
	dataBaseSurName.insert(p102);

	// Вставка в базу данных объектов, созданных в динамической памяти
	dataBaseSurName.insert(*new Person(1003, "Крысов", 30000));
	dataBaseSurName.insert(*new Person(1001, "Собаков", 10000));
	dataBaseSurName.insert(*new Person(1005, "Котов", 50000));
	dataBaseSurName.insert(*new Person(1002, "Петухов", 20000));

	cout << "База данных по ключу 'номер счёта':" << endl;
	cout << dataBase << endl;

	// ------ Поиск в базе данных по ключу 'номер счёта'
	int keyInt = 1004;
	if (dataBase.search(keyInt, p101)) {
		cout << "Поиск персоны с номером счета = " << keyInt << " успешен:" << endl;
		cout << p101 << endl << endl;
	}
	else
		cout << "Поиск персоны с номером счета = " << keyInt << " не успешен." << endl << endl;

	// ------ Поиск в базе данных по ключу 'фамилия' и вывод общего остатка
	int i = 0;
	int sum = 0;
	 Person persons[5];
	//vector <Person> persons;
	string keyString = "Собаков";
	if (dataBase.searchSumSurName(keyString, persons, i, sum)) {
		cout << "Поиск персоны с фамилией = " << keyString << " успешен:" << endl;
		for (int m=0; m < i; m++)
		{
			cout << persons[m] << endl;
		}
		cout << "общий остаток = " << sum << endl << endl;
	}
	else
		cout << "Поиск персоны с фамилией = " << keyString << " не успешен." << endl << endl;

	// ------ Удаление объекта из базы данных по ключу 'номер счёта'
	keyInt = 1004;
	if (dataBase.erase(keyInt)) {
		cout << "Персона с номером счета = " << keyInt << " удалена:" << endl;
		cout << "База данных по ключу 'номер счёта':" << endl;
		cout << dataBase << endl;
	}
	else
		cout << "Удаляемая персона с номером счета = " << keyInt << " не обнаружена." << endl;

	cout << "База данных по ключу 'фамилия':" << endl;
	cout << dataBaseSurName << endl;

	// ------ Поиск в базе данных по ключу 'фамилия'
	keyString = "Собаков";
	if (dataBaseSurName.search(keyString, p101)) {
		cout << "Поиск персоны с фамилией = " << keyString << " успешен:" << endl;
		cout << p101 << endl << endl;
	}
	else
		cout << "Поиск персоны с фамилией = " << keyString << " не успешен." << endl << endl;

	dataBase.clear();
	dataBaseSurName.clear();

	system("pause");
	return 0;
}

