#include <iostream>
#include <fstream>

using namespace std;

//1, 9 Переменная: текстовая строка длиной 127 байтов;
//целочисленный литерал(4 байта)

#define INT 1;
#define Char 2;

int main()
{
	setlocale(LC_ALL, "rus");
	ofstream serFile("serialization.txt", ios::binary);

	cout << "\nВведите значения для INT: ";
	int elemInt;
	cin >> elemInt;
	serFile << INT;
	serFile << sizeof(int);
	serFile << elemInt;
	serFile << " ";
	
	char symbsChar[127]="";
	cout << "Введите значения для Char: ";
		cin >> symbsChar;
		serFile << Char;
		serFile << sizeof(symbsChar);
		serFile << symbsChar;
	

	
	

	serFile.close();
}