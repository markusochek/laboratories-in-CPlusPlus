//2.21 Бытовая техника.Существует бытовая техника, каждый её экземпляр имеет серийный номер, цена.
// Бытовая техника бывает следующих типов : стиральная машина(вес загружаемого белья, мощность),
//  кухонный комбайн(потребляемая мощность, виды насадок) и пылесос(потребляемая мощность, тип пылесоса).
// Создать набор бытовой техники, вывести на экран и посчитать общую цену.

#include <iostream>

#include "Household.h"
#include "PowerConsumption.h"

#include "WashingMachine.h"
#include "FoodProcessor.h"
#include "VacuumCleaner.h"

using namespace std;

int prompt_menu_item()//меню
{
    setlocale(LC_ALL, "Russian");
    // Выбранный вариант меню
    int variant;
    cout << endl;
    cout << "выберите действие:\n" << endl;
    cout << "1. создание стиральной машины\n"
        << "2. создание кухонного комбайна\n"
        << "3. создание пылесоса\n"
        << "4. вывод \n"
        << "5. сложение цен на бытовую технику\n"
        << "6. выход\n" << endl;
    cout << ">>> ";
    cin >> variant;
    cout << endl;
    return variant;
}

void main()
{
    Household* p[10];
    int variant = 0;
    int* q;
    q = new int[4];
    int n = 0;
    int S = 0;
    do
    {
        int variant = prompt_menu_item();
        switch (variant)
        {
        case 1://создание стиральной машины
        {
            cout << "введите для стиральной машины номер, цену, вес и мощность" << endl;
            for (int i = 0; i <= 3; i++)
            {
                cin >> q[i];
            }
            p[n] = new WashingMachine(q[0], q[1], q[2], q[3]);
            p[n]->write();
            n++;
            break;
        }
        case 2://создание кухонного комбайна
        {
            cout << "введите для кухонноого комбайна номер, цену, потребляемая мощность и типы насадок" << endl;
            for (int i = 0; i <= 3; i++)
            {
                cin >> q[i];
            }
            p[n] = new FoodProcessor(q[0], q[1], q[2], q[3]);
            p[n]->write();
            n++;
            break;
        }
        case 3://создание пылесоса
        {
            cout << "введите для пылесоса номер, цену, потребляемая мощность, тип пылесоса" << endl;
            for (int i = 0; i <= 3; i++)
            {
                cin >> q[i];
            }
            p[n] = new VacuumCleaner(q[0], q[1], q[2], q[3]);
            p[n]->write();
            n++;
            break;
        }
        case 4:
        {
            for (int i = 0;  i<n; i++)
                p[i]->write();
            break;
        }
        case 5:
        {
            for (int i=0; i<n; i++)
                S=S + p[i]->getPrice();
            cout << "сумма цен бытовой техники равна " << S << endl;
            break;
        }
        case 6://выход
        {
            cout << "Выход из программы" << endl;
            exit(EXIT_SUCCESS);
            break;
        }
        default:
        {
            cerr << "Вы выбрали неверный вариант" << endl;
            exit(EXIT_FAILURE);
        }
        }
    } while (variant != 6);
    delete p;
    delete[] q;
    return;
}