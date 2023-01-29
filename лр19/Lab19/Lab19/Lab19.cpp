#include "stdafx.h"
#include "FST.h"

int _tmain(int argc, TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");

	char str1[] = "abebb";
	char str2[] = "abbf";
	char str3[] = "abbbf";
	char str4[] = "abdbbbf";
	char str5[] = "abbbdbf";
	char str6[] = "abebf";
	char str7[] = "abdbf";
	char str8[] = "cdea";
	char str9[] = "afb";
	char str10[] = "abf";
	

	char* chains[] = { str1, str2, str3, str4, str5, str6, str7, str8, str9, str10 };

	for (int i = 0; i < sizeof(chains) / sizeof(char*); i++)
	{
		FST::FST fst(chains[i], 7,
			FST::NODE(1, FST::RELATION('a', 1)),
			FST::NODE(1, FST::RELATION('b', 2), FST::RELATION('b', 1)),
			FST::NODE(4, FST::RELATION('b', 5), FST::RELATION('e', 3), FST::RELATION('d', 3), FST::RELATION('c', 3)),
			FST::NODE(1, FST::RELATION('b', 4), FST::RELATION('b', 3)),
			FST::NODE(5, FST::RELATION('b', 5), FST::RELATION('b', 4), FST::RELATION('e', 3), FST::RELATION('d', 3), FST::RELATION('c', 3)),
			FST::NODE(1, FST::RELATION('f', 6)),
			FST::NODE()
		);

		if (FST::execute(fst))
			std::cout << "Цепочка " << fst.string << " распознана" << std::endl;
		else std::cout << "Цепочка " << fst.string << " не распознана" << std::endl;
	};

	system("pause");
	return 0;
}
