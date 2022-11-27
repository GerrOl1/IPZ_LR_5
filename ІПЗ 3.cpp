#include <iostream>
#include <fstream>

using namespace std;

void OutputFile(int x, int y)       //оголошуємо функцію для зберігання данних у файл
{
    ofstream fout;
    string puth = "test.txt";       //присвоюємо назві файлі змінну
    fout.open(puth, ofstream::app);     //файл відкривається або створюється        //файл зберігає введені раніше дані
    fout << "x = " << x << " y = " << y << endl;    //дані які зберігаються
    fout.close();       //закриття файлу
}

void ChekVail()     //оголошуємо функцію для перевірки введених даних
{
    if (cin.fail())     //перевірка даних
    {
        throw " Не вiрно введенi данi!";        //виводимо результат перевірки
    }
}

void audit1(int x1, int x2)      //оголошуємо функцію для перевірки введених даних
{
    if (x2 < x1)     //перевірка даних
        throw  "x1 не може бути бiльше x2!  ";      //виводимо результат перевірки
}

void audit2(int x1, int x2, int h)       //оголошуємо функцію для перевірки введених даних
{
    if ((x2 - x1) < h)     //перевірка даних
        throw " Крок надто великий!";       //виводимо результат перевірки
}

int calculate1(int n)        //оголошення функції рохрахунку y
{  
    int y = 1;
    for (int j = 2; j <= (n - 2); j++)     //іттерація
    {
        y *= j + 1;
    }
    return y;      //повертаємо результат
}

int calculate2( int x, int n)     //оголошення функції рохрахунку y
{
    int y = 1;
    for (int i = 0; i <= (n - 1); i++)      //іттерація
    {
        int h = 1;
        for (int j = 0; j <= (n - 1); j++)      //іттерація 
        {
            h *= (x + i + j * j);
            y += h;
        }
    }
    return y;      //повертаємо результат
}

int main()
{
    setlocale(LC_ALL, "UKRAINIAN");
    try
    {
        int x1, x2;
        int n, h;
        cout << "Уведiть промiжки iнтервалу, х1 та х2 : " << endl;
        cin >> x1 >> x2;
        ChekVail();         //якщо дані потрапили в перервірку то виводиться вийняток
        audit1(x1, x2);        //якщо дані потрапили в перервірку то виводиться вийняток

        cout << "Уведiть значення n та крок h : " << endl;
        cin >> n >> h;

        ChekVail();     //якщо дані потрапили в перервірку то виводиться вийняток
        audit2(x1, x2, h);      //якщо дані потрапили в перервірку то виводиться вийняток

        char OutputFile1;       //char для зберігання тексту в файлі
        cout << " Чи бажаєте зберегти результат у файл? Натиснiть y - так, n - нi " << endl;
        cin >> OutputFile1;     //вводимо відповідь

        for (int x = x1; x <= x2; x += h)
        {
            int y = 1;
            if (x < 0) //розраховуємо y якщо х менше 0
            {
                calculate1( n);         //отримуємо значення з функції calculate1

                if (OutputFile1 = y)    //якщо вибранино зберегти у файл, зберігаємо дані 
                {
                    OutputFile(x, calculate1( n));
                }
                cout << " " << "x:\ty:\t" << x << "\t" << calculate1( n) << "\t" << endl;     //вивід результатів
            }
            if (x >= 0)        //розраховуємо y якщо х більше 0
            {
                calculate2(x, n);       //отримуємо значення з функції calculate2

                cout << " " << "x:\ty:\t" << x << "\t" << calculate2(x,n) << "\t" << endl;     //вивід результатів

                if (OutputFile1 = y)    //якщо вибранино зберегти у файл, зберігаємо дані 
                {
                    OutputFile(x, calculate2(x, n));
                }
            }
        }
    }
    catch (const char* ex)
    {
        cout << ex << endl;
    }
    catch (...)
    {
        cout << "Не вiдома помилка " << endl;
        return -2;
    }

    return 0;
}