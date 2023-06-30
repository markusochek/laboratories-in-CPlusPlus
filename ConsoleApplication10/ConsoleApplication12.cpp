// 1.3 Обыкновенные дроби: Сумма, разность, произведение, деление

#include <iostream>

using namespace std;

class Drob
{
private:
    int chisl;
    int znamen;
    static int Count;
public:
    void setchisl(int chisl);
    int getchisl();
    void setznamen(int znamen);
    int getznamen();
    void write();
    Drob operator ++();
    Drob operator + (Drob & b);
    Drob operator - (Drob& b);
    Drob operator * (Drob& b);
    Drob operator / (Drob& b);
    const Drob& operator=(const Drob& b);
    static void InitCount();
    static void WriteCount();
    Drob(int chisl, int znamen);
    Drob(Drob& t);
    Drob();
    ~Drob();
   /* friend class Drobfriend;*/
};

void Drob::setchisl(int chisl)
{
   this -> chisl = chisl;
   return;
}
int Drob::getchisl()
{
    return chisl;
}
void Drob::setznamen(int znamen)
{
    this-> znamen = znamen;
    return;
}
int Drob::getznamen()
{
    return znamen;
}
void Drob::write()//вывод
{
    cout << "chisl=  "<<chisl << endl;
    cout << "znamen= "<<znamen << endl;
    cout << endl;
    return;
}
int Drob::Count = 0;//счётчик вне
void Drob::InitCount()//счётчик в
{
    Count = 0;
}
void Drob::WriteCount()//вывод количества
{
    cout << Count << endl;
    cout << endl;
}
Drob Drob::operator++ ()//прибавление 1 ко всем параметрам дроби
{
    znamen++;
    chisl++;
    return *this;
}
Drob Drob::operator+(Drob& b)//сложение
{
    Drob sum;
    sum.setchisl(this->chisl * b.znamen + b.chisl * znamen);
    sum.setznamen(this->znamen * b.znamen);
    return sum;
}
Drob Drob::operator-(Drob& b)//вычитание
{
    Drob dif;
    dif.setchisl(this->chisl * b.znamen - b.chisl * znamen);
    dif.setznamen(this->znamen * b.znamen);
    return dif;
}
Drob Drob::operator*(Drob& b)//умножение
{
    Drob mul;
    mul.setchisl(this->chisl * b.chisl);
    mul.setznamen(this->znamen * b.znamen);
    return mul;
}
Drob Drob::operator/(Drob& b)//деление
{
    Drob del;
    del.setchisl(this->chisl * b.znamen);
    del.setznamen(this->znamen * b.chisl);
    return del;
}
const Drob& Drob::operator=(const Drob& b)//замена старой дроби на новую
{
    this->znamen = b.znamen;
    this->chisl = b.chisl;
    return *this;
}
Drob::Drob(int chisl, int znamen)//создание новой дроби
{
    this->znamen = znamen;
    this->chisl = chisl;
    Count++;
}
Drob::Drob(Drob& t)//замена старой дроби на новую
{
    chisl = t.chisl;
    znamen = t.znamen;
}
Drob::Drob()//конструктор
{
    znamen = 0;
    chisl = 0;
    Count++;
}
Drob::~Drob()//деструктор
{
}
/*class friendDrob
{
public:
    void write(Drob x);
};
void friendDrob::write(Drob x)
{
    cout << x.chisl << endl;
    cout << x.znamen << endl;
    return;
}*/
int prompt_menu_item()//меню
{
    setlocale(LC_ALL, "Russian");
    // Выбранный вариант меню
    int variant;
    cout << endl;
    cout <<"выберите действие:\n" << endl;
    cout <<"1. ввод значений\n"
        << "2. изменение числителя\n"
        << "3. изменение знаменателя\n"
        << "4. вывод дробей\n"
        << "5. сложение дробей\n"
        << "6. вычитание дробей\n"
        << "7. умножение дробей\n"
        << "8. деление дробей\n"
        << "9. выход\n" << endl;
    cout << ">>> ";
    cin >> variant;
    cout << endl;
    return variant;
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");//язык

  /*  friendDrob d;
  d.write(a);*/

    int variant = 0;
    Drob a;
    Drob b;
    int x;
    int flag;
    do
    {
        int variant = prompt_menu_item();
        switch (variant)
        {
        case 1://создание
        {
            cout << "введите 1 дробь: числитель и знаменатель" << endl;
            cin >> x;
            a.setchisl(x);
            cin >> x;
            a.setznamen(x);
            cout << "введите 2 дробь: числитель и знаменатель" << endl;
            cin >> x;
            b.setchisl(x);
            cin >> x;
            b.setznamen(x);
            a.write();
            b.write();
            break;
        }
        case 2://изменение числителя
        {
            a.write();
            b.write();
            cout << "изменение числителя: для 1 или 2 дроби? Введите 1 или 2" << endl;
            cin >> flag;
            cout << "введите число" << endl;
            cin >> x;
            if (flag == 1)
                a.setchisl(x);
            else
                b.setchisl(x);
            break;
        }
        case 3://изменение знаменателя 
        {   
            a.write();
            b.write();
            cout << "изменение знаменаталя: для 1 или 2 дроби? Введите 1 или 2" << endl;
            cin >> flag;
            cout << "введите число" << endl;
            cin >> x;
            if (flag == 1)
                a.setznamen(x);
            else
                b.setznamen(x);
            break;
        }
        case 4://вывод
        {
            cout << "вывод дробей:" << endl;
            a.write();
            b.write();
            break;
        }
        case 5://сумма
        {  
            cout << "сумма дробей:" << endl;
            Drob sum;
            sum = a + b;
            sum.write();
            break;
        }
        case 6://разность
        {  
            cout << "разность дробей:" << endl;
            Drob dif;
            dif = a - b;
            dif.write();
            break;
        }
        case 7://умножение
        {   
            cout << "умножение дробей:" << endl;
            Drob mul;
            mul = a * b;
            mul.write();
            break;
        }
        case 8://деление
        {  
            cout << "деление дробей:" << endl;
            Drob del;
            del = a / b;
            del.write();
            break;
        }
        case 9://выход
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
    }
        while (variant != 6);
    return 0;
}