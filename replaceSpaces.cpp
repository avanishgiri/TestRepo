#include <iostream>
#include <cstring>

using namespace std;

void replaceSpaces(char *str)
{
	int length = strlen(str);

	int spaces = 0;

	for(int i = 0; i < length; i++)	
		if(str[i] == ' ')
			spaces++;
	
	int newLength = length + spaces*2;

	str[newLength] = '\0';

}

int main()
{
int array[5][5];

for(int i = 0; i < 25; i++)
	array[i] = 0;




}
