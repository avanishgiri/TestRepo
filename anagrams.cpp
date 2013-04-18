#include <iostream>
#include <cstring>

using namespace std;

bool anagrams(char *s1, char *s2)
{
	int length1 = strlen(s1);
	int length2 = strlen(s2);

	if(length1 != length2)
		return 0;

	int array[256];

	for(int i = 0; i < 256; i++)
		array[i] = 0;

	for(int i = 0; i < length1; i++)
		array[(s1[i])]++;

	for(int i = 0; i < length2; i++)
	{
		array[(s2[i])]--;
	}

	for(int i = 0; i < 256; i++)
		if(array[i])
			return 0;

	return 1;
}


int main()
{
	char* s1 = "yykcfuseu ca";

	char* s2 = "kfucky sauce";

	if(anagrams(s1, s2))
		cout << "yay" << endl;
}
