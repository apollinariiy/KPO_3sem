#include "stdafx.h"

bool PolishNotation(char*, string&);

int main()
{
    setlocale(LC_ALL, "Rus");

    char str[50];
    string result;
    cout << "Введите выражение, которое хотите преобразовать: ";
    cin.getline(str, 50);

    cout << endl;

    if (PolishNotation(str, result))
    {
        cout << "Введённая строка: " << str << endl;
        cout << "Польская строка: " << result << endl;
    }
    else
        cout << "Преобразованние не произошло" << endl;

    return 0;
}
