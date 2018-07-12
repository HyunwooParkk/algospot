
#include <list>
#include <string.h>
#include <stdio.h>
using namespace std;

/*
dmih
11
B
B
P x
L
B
B
B
P y
D
D
P z
------------------
yxz
*/

int main(void) {
	char str[100001], N;
	scanf("%s", str);
	list<char> charLst;
	int i;
	int len = strlen(str);
	for (i = 0; i<len; i++)
	{
		charLst.push_back(str[i]);
	}
	list<char>::iterator iter = charLst.end();
	scanf("%d", &N);; // 명령어 개수 

	while (N>0)
	{
		char cmd[2];
		scanf("%s", cmd);
		switch (cmd[0])
		{
		case 'L':
			//iter==charLst.begin()?iter:iter--;
			if (iter != charLst.begin()) iter--;
			break;
		case 'D': // R로 썼다 한참 찾았다.. 
				  //iter==charLst.end()?iter:iter++;
			if (iter != charLst.end()) iter++;
			break;
		case 'B':
			if (len>0)
			{
				if (iter != charLst.begin())
				{
					iter--;
					iter = charLst.erase(iter);
					len--;
				}
			}
			break;
		case 'P':
			char tmp[2];
			scanf("%s", tmp);
			iter = charLst.insert(iter, tmp[0]);
			++iter;
			len++;
			break;
		}
		N--;
	}

	list<char>::iterator iterEnd = charLst.end();
	for (iter = charLst.begin(); iter != iterEnd; ++iter)
	{
		//cout << *iter;
		printf("%c", *iter);
	}
	return 0;
}