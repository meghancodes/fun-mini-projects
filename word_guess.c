/*
**  A word guess game that gives the player three tries to guess
**  a word (pulled randomly from a file) -- a hint is given before
**  each guess
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *word1 = "lobster";
char *word2 = "teddybear";
char *word3 = "smartphone";
char *word4 = "purse";
char *word5 = "lipstick";

int word_1(void);
int word_2(void);
int word_3(void);
int word_4(void);
int word_5(void);

int main(void)
{
	FILE *fp;
	int ch;
	int ch2;
	int i;
	int select = 0;
	int word_count = 0;
	int random; //instead of uint32_t
	int index = 0;
	char buf[256];
	char *token;
	char tmp_buf[256];
	char *selected_word;

	fp = fopen("word_guess.txt", "r");

	if (fp == NULL)
	{
		printf("Failed to open and read from the file\n");
		return (0);
	}

	while ((ch = fgetc(fp)) != EOF)
	{
		if (ch == ' ' || ch == '\n')
			word_count++;
	}

	random = (int)(arc4random_uniform(word_count) + 1);
	
	printf("%d\n", random);

	rewind(fp);

	while ((fgets(buf, sizeof(buf), fp)) != NULL)
	{
		while (buf[index] != '\0')
		{
			tmp_buf[index] = buf[index];
			index++;
		}
		tmp_buf[index] = '\0';
	}

	printf("%s", tmp_buf);



	printf("Rules: You have three tries to guess the correct word. A hint \\
		will be given to you before each of your guesses. Good luck!\n");
	if (strcmp(word1, selected_word) == 0)
	{
		word_1();
		return (0);
	}
	else if (strcmp(word2, selected_word) == 0)
	{
		word_2();
		return (0);
	}
	else if (strcmp(word3, selected_word) == 0)
	{
		word_3();
		return (0);
	}
	else if (strcmp(word4, selected_word) == 0)
	{
		word_4();
		return (0);
	}
	else if (strcmp(word5, selected_word) == 0)
	{
		word_5();
		return (0);
	}

	fclose(fp);

	return (0);
}

int word_1(void)
{
	char *guess1;
	char *guess2;
	char *guess3;

	printf("It lives in the ocean, but you're more likely to see it somewhere else\n");
	scanf("%s", guess1);
	if (strcmp(word1, guess1) == 0)
	{
		printf("Congratulations! You guessed correctly!\n");
		return (0);
	}
	else
		printf("Sorry! That wasn't right. Try again.\n");
	printf("It's red in color\n");
	scanf("%s", guess2);
	if (strcmp(word1, guess2) == 0)
	{
		printf("Congratulations! You guessed correctly!\n");
		return (0);
	}
	else
		printf("Sorry! That wasn't right. Try again.\n");
	printf("It's considered a delicacy by many seafood lovers\n");
	scanf("%s", guess3);
	if (strcmp(word1, guess3) == 0)
	{
		printf("Congratulations! You guessed correctly!\n");
		return (0);
	}
	else
		printf("Sorry! That wasn't right. You lose :(\n");
	return (0);	
}

int word_2(void)
{
	char *guess1;
	char *guess2;
	char *guess3;

	printf("It's a common child's toy\n");
	scanf("%s", guess1);
	if (strcmp(word1, guess1) == 0)
	{
		printf("Congratulations! You guessed correctly!\n");
		return (0);
	}
	else
		printf("Sorry! That wasn't right. Try again.\n");
	printf("Can't get a Ruxpin? Try getting a Ted\n");
	scanf("%s", guess2);
	if (strcmp(word1, guess2) == 0)
	{
		printf("Congratulations! You guessed correctly!\n");
		return (0);
	}
	else
		printf("Sorry! That wasn't right. Try again.\n");
	printf("Not a teddylion or a teddytiger...\n");
	scanf("%s", guess3);
	if (strcmp(word1, guess3) == 0)
	{
		printf("Congratulations! You guessed correctly!\n");
		return (0);
	}
	else
		printf("Sorry! That wasn't right. You lose :(\n");
	return (0);	
}

int word_3(void)
{
	char *guess1;
	char *guess2;
	char *guess3;

	printf("These days, you almost can't live without one\n");
	scanf("%s", guess1);
	if (strcmp(word1, guess1) == 0)
	{
		printf("Congratulations! You guessed correctly!\n");
		return (0);
	}
	else
		printf("Sorry! That wasn't right. Try again.\n");
	printf("It performs many of the functions of a computer\n");
	scanf("%s", guess2);
	if (strcmp(word1, guess2) == 0)
	{
		printf("Congratulations! You guessed correctly!\n");
		return (0);
	}
	else
		printf("Sorry! That wasn't right. Try again.\n");
	printf("Take a bite out of an apple or run a sprint to get one\n");
	scanf("%s", guess3);
	if (strcmp(word1, guess3) == 0)
	{
		printf("Congratulations! You guessed correctly!\n");
		return (0);
	}
	else
		printf("Sorry! That wasn't right. You lose :(\n");
	return (0);	
}

int word_4(void)
{
	char *guess1;
	char *guess2;
	char *guess3;

	printf("Throw it on your shoulder and go\n");
	scanf("%s", guess1);
	if (strcmp(word1, guess1) == 0)
	{
		printf("Congratulations! You guessed correctly!\n");
		return (0);
	}
	else
		printf("Sorry! That wasn't right. Try again.\n");
	printf("It's the perfect place to store small personal items\n");
	scanf("%s", guess2);
	if (strcmp(word1, guess2) == 0)
	{
		printf("Congratulations! You guessed correctly!\n");
		return (0);
	}
	else
		printf("Sorry! That wasn't right. Try again.\n");
	printf("You can get one from Louis, Michael, or Chanel...\n");
	scanf("%s", guess3);
	if (strcmp(word1, guess3) == 0)
	{
		printf("Congratulations! You guessed correctly!\n");
		return (0);
	}
	else
		printf("Sorry! That wasn't right. You lose :(\n");
	return (0);	
}

int word_5(void)
{
	char *guess1;
	char *guess2;
	char *guess3;

	printf("You put it on your lips\n");
	scanf("%s", guess1);
	if (strcmp(word1, guess1) == 0)
	{
		printf("Congratulations! You guessed correctly!\n");
		return (0);
	}
	else
		printf("Sorry! That wasn't right. Try again.\n");
	printf("Nude, Dusty Rose, and Apricot are favorites for spring\n");
	scanf("%s", guess2);
	if (strcmp(word1, guess2) == 0)
	{
		printf("Congratulations! You guessed correctly!\n");
		return (0);
	}
	else
		printf("Sorry! That wasn't right. Try again.\n");
	printf("You can put it on a pig but the pig will still be a pig\n");
	scanf("%s", guess3);
	if (strcmp(word1, guess3) == 0)
	{
		printf("Congratulations! You guessed correctly!\n");
		return (0);
	}
	else
		printf("Sorry! That wasn't right. You lose :(\n");
	return (0);	
}
