#include <stdio.h>
#include <stdlib.h>

/*
**  Converts valid input to Pig Latin
**  
**  Valid input: A string of letters (No spaces)
**  
**  Rules: To convert English words to Pig Latin the initial consonant sound 
**  is transposed to the end of the word and 'ay' is affixed to the end.
**  For words that start with a vowel, 'way' is affixed to the end. 
**  (Ex.: "pig" would yield "igpay", "apple" would yield "appleway")
*/

int		check_input(char *original);
char	*pig_latin(char *original);

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Incorrect number of arguments. Sorry!");
		return (0);
	}
	if (!(check_input(argv[1])))
	{
		printf("That's not a valid input. Sorry!");
		return (0);
	}
	else
		printf("%s\n", pig_latin(argv[1]));
	return (0);
}

/*
**  Determines the length of string s
*/

int	is_letter(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

/*
**  Ensures that the input is valid
*/

int	check_input(char *original)
{
	int	index;

	index = 0;
	while (original[index] != '\0')
	{
		if (!(is_letter(original[index])))
			return (0);
		index++;
	}
	return (1);
}

/*
**  Determines the length of string s
*/

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
	{
		index++;
	}
	return (index);
}

/*
**  Determines whether c is a vowel or not
*/

int	is_vowel(int c)
{
	if (c == 65 || c == 69 || c == 73 || c == 79 || c == 85 || c == 97
		|| c == 101 || c == 105 || c == 111 || c == 117)
		return (1);
	return (0);
}

/*
**  Appends a copy of the NULL-terminated string s2 to s1
**  and adds a terminating '\0'
*/

char	*ft_strcat(char *s1, const char *s2)
{
	char	*str;

	str = s1;
	while (*str != '\0')
		str++;
	while (*s2 != '\0')
	{
		*str = *s2;
		s2++;
		str++;
	}
	*str = '\0';
	return (s1);
}

/*
**  Converts input to Pig Latin
*/

char	*pig_latin(char *original)
{
	char	*p_latin;
	char	*cons_end = "ay";
	char	*vow_end = "way";
	char	*s1;
	char	*s2;
	int		index;
	int		p_index;
	int		tmp;
	int		tmp2;

	index = 0;
	p_index = 0;
	if (!(p_latin = (char *)malloc(sizeof(char) * (ft_strlen(original) + 1))))
		return (0);
	if (is_vowel(original[0]))
	{
		while (original[index] != '\0')
			p_latin[p_index++] = original[index++];
		s1 = ft_strcat(p_latin, vow_end);
		return (s1);
	}
	while (original[index] != '\0')
	{
		if (is_vowel(original[index]))
		{
			tmp = index;
			tmp2 = 0;
			while (original[index] != '\0')
				p_latin[p_index++] = original[index++];
			while (tmp2 < tmp)
				p_latin[p_index++] = original[tmp2++];
			s2 = ft_strcat(p_latin, cons_end);
			return (s2);
		}
		index++;
	}
	return (NULL);
}
