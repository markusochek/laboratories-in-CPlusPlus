using System;

namespace Error
{
    class Program
    {
        static void Main(string[] args)
        {
            decimal sum = 3400;
            decimal PL = 20;
            //Boolean с большой буквы(ошибка условия)
            Boolean is_cor = true;
            decimal K_cor = 1.05m;
            //есть ли смысл тратить память на decimal в этом случае?
            int mes = 12;

            //decimal sum = 4600;
            //decimal PL = 46;
            //Boolean is_cor = false;
            //decimal K_cor = 1;
            //int mes = 10;

            //decimal sum = 5800;
            //decimal PL = 325;
            //Boolean is_cor = false;
            //decimal K_cor = 1;
            //int mes = 9;

            //decimal sum = 7900;
            //decimal PL = 0;
            //Boolean is_cor = true;
            //decimal K_cor = 1.1m;
            //int mes = 5;

            //decimal sum = 10000;
            //decimal PL = 980;
            //Boolean is_cor = true;
            //decimal K_cor = 0.9m;
            //int mes = 6;

            decimal ar_mes = 0;
            decimal baz_st = 0;
            decimal sum_k = sum;

            // должно быть ==
            if (is_cor == true)
            {
                // K_cor должно быть написано с большой буквы
                sum_k = sum * K_cor;
            }

            //в таблице наблюдается случай,
            //когда площадь по договору может быть не заполнена,
            //поэтому мы обязаны проверить не делим ли мы на ноль
            if (PL != 0)
            {
                baz_st = sum_k / PL;
            }

            //нет смысла в else и 2 раза прописанной конструкции
            //проще в начале задать sum_k = sum;
            //не хватает ;
            ar_mes = sum_k * mes / 12;

            Console.WriteLine(ar_mes);
            Console.WriteLine(baz_st);
        }
    }
}
