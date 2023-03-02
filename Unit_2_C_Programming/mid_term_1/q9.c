/*
 ==================================================================
 Name        : q9 mid term 1 reverse words in string
 Author      : Mohamed Belal
 Created on  : 2/3/2023
 Description : Unit 2 C-Programming => mid term 1 => q9
 ==================================================================
 */
#include <stdio.h>
#include <string.h>
void reverse_word(char str[], int size);

int main(void) {
	char string[] = "mohamed belal";
	reverse_word(string, strlen(string));

	return 0;
}

void reverse_word(char str[], int size)
{
	int i, j = 0, k;
	char word[100];

	for (i = size - 1; i >= 0; i--)
	{
		if (str[i] != ' ')
		{
			word[j] = str[i];
			j++;
		} else
		{
			for (k = j - 1; k >= 0; k--)
			{
				printf("%c", word[k]);
			}
			printf(" ");
			j = 0;
		}
	}

	if (j != 0)
	{
		for (k = j - 1; k >= 0; k--)
		{
			printf("%c", word[k]);
		}
	}
}

