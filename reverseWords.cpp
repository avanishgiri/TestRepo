#include <iostream>

using namespace std;
char *reverseWord(char *string)
{
	int length = 0;
	while(string[length] != ' ' && string[length] != '\0')
		length++;
	
	for(int i = 0; i <= --length; i++)
		swap(string[i], string[length]);
}

void *reverse(char *string)
{
	int length = 0;
	while(string[length] != '\0')
		length++;

	int orig = length;
	for(int i = 0; i <= --length; i++)
	{
		swap(string[i],string[length]);
	}

	reverseWord(string);
	for(int i = 0; i < orig; i++)
	{
		if(string[i] == ' ')
			reverseWord(string+i+1);
	}
}

	

int main()
{
	char* poo = strdup("hey there fuck stick");

	reverse(poo);

	cout << poo;

}
