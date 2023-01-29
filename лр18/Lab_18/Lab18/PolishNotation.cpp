#include "stdafx.h"


map <char, int> priority = { 
	{'(', 1},
	{')', 1},
	{'+', 2},
	{'-', 2},
	{'*', 3},
	{'/', 3},
};

bool PolishNotation(char* str, string &result)
{
	stack<char> st;
	for (int i = 0; i < strlen(str); i++)
	{
		char s = str[i];
		switch (s)
		{
			case ' ':
			case '\t':
				continue;
				break;
			case '(':
				st.push(s);
				break;
			case ')':
			{
				if (st.empty())
					return false;
				while (st.top() != '(')
				{
					s = st.top();
					st.pop();
					result.push_back(s);

					if (st.empty())
						return false;
				}
				st.pop();
			} break;
			case '+':
			case '-':
			case '*':
			case '/':
			{
				while (!st.empty() && priority[s] <= priority[st.top()])
				{
					result.push_back(st.top());
					st.pop();
				}
				st.push(s);
			} break;
			default: 
				result.push_back(s);

		}
	}
	while (!st.empty())
	{
		char s = st.top();
		st.pop();
		if (s == '(')
			return false;
		while(!st.empty() && priority[s] <= priority[st.top()])
		{
			result.push_back(st.top());
			st.pop();
		}
		result.push_back(s);
	}

	return true;
}