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
	
	
	cout << "������� �������� int: ";
	cin.getline(intVal, 50);
	
	cout << "������� �������� unsigned int: ";
	cin.getline(unsignedVal, 30);
	
	Int = atol(intVal); //�������������� ������ � �����

	Unsigned = strtoul(unsignedVal, NULL, 10); //�������������� ������ � �����

	cout << Int << " " << Unsigned << endl;
	
	serealizer.Serialize(Int, Unsigned); //c�����������
	
}
