/*
Pablo Molina
Programming Assignment 1
Section: 0040 - Friday @ 3:30pm
01/25/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	/*
	! ALGORITHM
	new - old = chars to buy
		log frequency of new chars
		IF freq[old] > 0 --- (I need it and I have it)
			THEN decrement, 
		ELSE continue (don't need it)
		3) sum up frequencies
	*/
	const int ALPHABET = 26, LOW_ASCII=65, TOP_ASCII=90;
	int i, toBuy = 0;
	int *frequency = (int *)calloc(ALPHABET, sizeof(int));
	char *oldLetters = (char *)calloc(100002, sizeof(char));
	char *newLetters = (char *)calloc(100002, sizeof(char));

	fgets(oldLetters, 100002, stdin);
	fgets(newLetters, 100002, stdin);

	// Logs the frequency of each char in NEW string
	for (i = 0; i < strlen(newLetters) - 1; i++)
	{
		// ensures ASCII UPPERCASE valid values
		if((newLetters[i]<LOW_ASCII) || (newLetters[i]>TOP_ASCII))
		{
			continue;
		}
		int index = newLetters[i] - LOW_ASCII;
		frequency[index]++;
	}

	// for every letter I already own,
	for (i = 0; i < strlen(oldLetters) - 1; i++)
	{
		// ensures ASCII UPPERCASE valid values
		if ((oldLetters[i]<LOW_ASCII) || (oldLetters[i]>TOP_ASCII))
		{
			continue;
		}
		int index = oldLetters[i] - LOW_ASCII;
		// freq=0 when not needed to buy
		if (frequency[index] == 0)
		{
			continue;
		}
		// decrement its frequency,
		// since I already own it
		frequency[index]--;
	}

	//cummulative sum of frequencies
	for (i = 0; i < ALPHABET; i++)
	{
		toBuy += frequency[i];
	}
	printf("%d", toBuy);

	//free dynamic memory
	free(oldLetters);
	free(newLetters);
	free(frequency);
	return 0;
}
