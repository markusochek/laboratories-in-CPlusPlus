/*******************************************************************
Информация об автомобилях Автобазы Правительства Мордовии представлена следующим 
набором данных: государственный номер автомобиля (госномер в стандартном виде),
модель, марка, год и месяц выпуска автомобиля. Построить бинарное дерево поиска,
ключом которого является госномер. Обеспечить:
а) поиск автомобиля по госномеру;
б) поиск автомобилей по году выпуска (поиск типа «от и до...»);
в) поиск всех автомобилей определенной марки;
г) выдачу всего списка автомобилей, упорядоченных по госномерам;
д) удаление информации об автомобиле по госномеру;
е) построение другого бинарного дерева поиска, ключом которого является модель, и
выдача списка автомобилей, упорядоченного по моделям.
Авор: Мизюков В.С. ИТ-21
Дата: 02.11.2020
********************************************************************/

#include <iostream>
#include <locale.h>
#include <string>
#include <windows.h>

#include "Car.h"
#include "CarSBTree.h"

using namespace std;

int main()
{
	// Локализация по кириллице
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	Car a(39673, "Lada", "Calina", 2000.11);
	Car b(20587, "Porsche", "Macan", 2014.9);
	Car c(19534, "Skoda", "Octavia", 2014.3);
	Car d(95873, "Lada", "Priora", 1995.5);

	CarSBTree data;
	data.insertNum(a);
	data.insertNum(b);
	data.insertNum(c);
	data.insertNum(d);
	data.insertNum(*new Car(90213, "Niva", "Chevrolet", 1994.5));

	Car q;

	cout << "--Полный список автомобилей:" << "\n" << data;

	int key = 39673;
	cout << "--Поиск по гос номеру " << key << endl;
	if (data.searchNum(key, q))
		cout << q << endl;
	else
		cout << "--Номер не найден" << endl;

	double key1 = 2010;
	double key2 = 2020;
	cout << "--Поиск по дате, с " << key1 << " по " << key2 << endl;
	data.searchDate(2010, 2020);

	string key3 = "Macan";
	cout << "--Поиск марки " << key3 << endl;
	data.searchMark(key3);

	key = 95873;
	if (data.erase(key))
	{
		cout << "--Удалении машины № " << key << endl << "Конечный список: " << endl << data;
	}

	CarSBTree data1;
	Car z(94738, "Kia", "Rio", 2000.1);
	Car w(90598, "Toyota", "Qwe", 2010.5);
	Car e(32858, "Nissan", "Uew", 2015.7);
	Car r(99248, "Nissan", "Mfa", 2013.5);

	data1.insertModel(z);
	data1.insertModel(w);
	data1.insertModel(e);
	data1.insertModel(r);
	data1.insertModel(*new Car(97832, "Porshe", "Una", 2010.12));

	cout << "--Новый список автомобилей, отсортированный по модели: \n" << data1;

	data.clear();
	system("pause");
	return 0;
}