#include <iostream>
#include <cstring>
#include "reverse.h"

using namespace std;

bool isUnique(char *str)
{
	char array[256];
	
	for(int i = 0; i < 256; i++)
		array[i] = 0;
	
	for(int i = 0; i < 256; i++)
		if(array[i])
			cout << i;
	
	int length = strlen(str);

	for(int i = 0; i < length; i++)
	{
		if(array[(str[i])] == 1)
			return 0;
		else
			array[(str[i])] = 1;
	}
	return 1;	
}

int main()
{
	char poo[5] = {'a', 'b', 'c', 'd', 'e'};

	if(isUnique(poo))
		cout << "Is unique" << endl;
	else
		cout << " no " << endl;
}
