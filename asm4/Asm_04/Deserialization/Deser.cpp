#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define INT 1
#define Char 2
#define HEADER ".586\n.MODEL FLAT, STDCALL\nincludelib kernel32.lib\nExitProcess PROTO : DWORD\n.STACK 4096\n\n.CONST\n\n"
#define FOOTER "\n\n.CODE\nmain PROC\nSTART :\npush - 1\ncall ExitProcess\nmain ENDP\nend main\n"

int main()
{
	ifstream readSer("..\\Asm_04\\serialization.txt", ios::binary);
	ofstream writeCode("..\\Asm_04\\Deserialization.asm");
	string str, words[128];
	getline(readSer, str);
	int q = 0;

	for (int w = 0; w < str.length(); w++)
	{
		if (str[w] == ' ')
		{
			q++;
			continue;
		}
		words[q] += str[w];

	}

	if (readSer.is_open())
	{
		writeCode << HEADER;
		for (int i = 0; i < q + 1; i++)
		{
			switch (words[i][0])
			{
			case '1':
				writeCode << "INT";
				writeCode << i;
				writeCode << " DWORD ";
				writeCode << words[i].substr(2);
				writeCode << "\n\n";
				writeCode << ".DATA\n\n";
				break;
			case '2':
				writeCode << "CHAR";
				writeCode << i;
				writeCode << " BYTE ";
				words[i] = words[i].substr(4);
				for (int n = 0; n < words[i].length(); n++)
				{
					
						writeCode << words[i][n];
						if (n < words[i].length() - 1) {
							writeCode << ", ";
						}
					
					
				}
				writeCode << "\n";
			default:
				break;
			}
		}
				writeCode << FOOTER;
	}
		
		readSer.close();
		writeCode.close();

}