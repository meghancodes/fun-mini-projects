#include <stdio.h>

/*
**  Prints a diamond of size "size". The size corresponds to the number
**  of rows in the top half of the diamond
*/

void print_diamond(int size);

int main(void)
{
	int size;
	printf("Enter diamond size:\n");
	scanf("%d", &size);
	print_diamond(size);
	return(0);

}

/*
**  Prints the bottom half of the diamond
*/

void print_diamond2(int size, int counter, int last_value)
{
	int copy_size;
	int copy_size2;
	int new_counter;
	int tmp_value;

	copy_size = size;
	copy_size2 = size - 1;
	new_counter = 2;
	while (copy_size2 > 0)
	{
		last_value -= 2;
		while (copy_size < counter)
		{
			printf(" ");
			copy_size++;
		}
		tmp_value = last_value;
		while (last_value > 0)
		{
			printf("*");
			last_value--;
		}
		printf("\n");
		copy_size = copy_size - new_counter;
		copy_size2--;
		new_counter++;
		last_value = tmp_value;
	}
}

/*
**  Prints the top half of the diamond
*/

void print_diamond(int size)
{
	int stars;
	int tmp;
	int last_value;
	int copy_size;
	int copy_size2;
	int counter;
	int value;

	stars = 1;
	tmp = 0;
	copy_size = size;
	counter = 1;
	while (copy_size > tmp)
	{	
		value = (stars * 2) - 1;
		while (copy_size > 1)
		{
			printf(" ");
			copy_size--;
		}
		last_value = value;
		while (value > 0)
		{	
			printf("*");
			value--;
		}
		printf("\n");
		stars++;  
		copy_size = size - counter;
		counter++;
	}
	print_diamond2(size, counter, last_value);
}