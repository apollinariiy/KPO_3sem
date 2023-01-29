#include "Serealizer.h"
#include "stdafx.h"

void Serealizer::Serialize(int intVal, unsigned int unsignedVal)
{
	ofstream file(FILENAME, ios::binary); //открытие файла для записи, в бинарном режиме
	if (file.is_open())
	{
		//запись в файл
		file.write(reinterpret_cast<char*>(&intVal), sizeof(int)); //запись int
		file.write(reinterpret_cast<char*>(&unsignedVal), sizeof(unsigned int)); //запись unsigned int
		file.close();
	}
	else
	{
		cout << "File not open" << endl;
	}
}