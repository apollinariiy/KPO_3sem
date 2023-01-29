#include "stdafx.h"
#include "Serealizer.h"

using namespace std;
int indexNumIn(char arr[]);

void main()
{
	setlocale(LC_ALL, "ru");
	Serealizer serealizer;
	char intVal[50];
	short Int;
	char unsignedVal[30];
	unsigned short Unsigned;
	
	
	cout << "Введите значение int: ";
	cin.getline(intVal, 50);
	
	cout << "Введите значение unsigned int: ";
	cin.getline(unsignedVal, 30);
	
	Int = atol(intVal); //преобразование строки в число

	Unsigned = strtoul(unsignedVal, NULL, 10); //преобразование строки в число

	cout << Int << " " << Unsigned << endl;
	
	serealizer.Serialize(Int, Unsigned); //cериализация
	
}
