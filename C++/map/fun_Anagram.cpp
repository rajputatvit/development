#include "mapHeader.h"

#define MAX_CHARS 256

// To find anagram whether two strings are Anagram or not???

// Input 
// s1: First string
// s2: Second string

// Output
// True if it is Anagram
// False if it is not Anagram

bool fun_anagram(string s1, string s2)
{
	int count[MAX_CHARS] = { 0 };
	int i = 0;

	for (; s1[i] && s2[i]; ++i)
	{
		count[s1[i]]++;
		count[s2[i]]--;
	}

	if (s1[i] || s2[i])
		return false;

	for (i = 0; i < MAX_CHARS; ++i)
	{
		if (count[i])
			return false;
	}

	return true;
}