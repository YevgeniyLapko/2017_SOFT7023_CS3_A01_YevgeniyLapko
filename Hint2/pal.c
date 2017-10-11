//--------------------------------------------------
// INCLUDE SECTION
//--------------------------------------------------
#include "pal.h"

//--------------------------------------------------
// is_pal
//--------------------------------------------------
boolean is_pal(int* a, int size_num) {
	boolean res = True;

	int middle = size_num / 2;

	for (int i = 0; i < middle; i++) // from 0 1 2 3
	{
		if (  *(a + i) != *(a + (size_num - 1 - i))  )

		{
			res = False;
		}

	}

	return res;

}

boolean is_command_valid(char chars[], char ch, int size)
{
	boolean checker = False;

	for (int i = 0; i < size; i++)
	{
		if (ch == chars[i])
		{
			checker = True;
		}
	}

	return checker;
}

//--------------------------------------------------
// ask_for_command
//--------------------------------------------------
char ask_for_command(char c[], int size) {
	char input = ' ';

	do
	{
		printf("\nNEW MOVEMENT: Enter a valid command by keyword:\n");
		printf("Valid commands:");

		for (int i = 0; i < size; i++)
		{
			printf("     ");
			printf("%c", c[i]);
		}

		printf("\nYour command is: ");
		input = my_get_char();
	} while (is_command_valid(c, input, size) != True);


	return input;
}


//--------------------------------------------------
// process_movement
//--------------------------------------------------
void process_movement(int* a, int size_num, int** p_p, int* p_nm, char c) {

	if (c == 'a')
	{
		if (*p_p != (a + 0))
		{
			*p_p = *p_p - 1;
			*p_nm = *p_nm + 1;
		}
	}

	else if (c == 'd')
	{
		if (*p_p != (a + (size_num - 1)))
		{
			*p_p = *p_p + 1;
			*p_nm = *p_nm + 1;
		}
	}

	else if (c == 'w')
	{
		if (**p_p != 9)
		{
			**p_p = (**p_p) + 1;
			*p_nm = *p_nm + 1;
		}
	}

	else if (c == 'x')
	{
		if (**p_p != 0)
		{
			**p_p = (**p_p) - 1;
			*p_nm = *p_nm + 1;
		}
	}

	else if (c == 'h')
	{
		if (*p_p != (a + 0))
		{
			*p_p = (a + 0);
			*p_nm = *p_nm + 1;
		}
	

	}

	else if (c == 'k')
	{
		if (*p_p != (a + (size_num - 1)))
		{
			*p_p = (a + (size_num - 1));
			*p_nm = *p_nm + 1;
		}
		

	}

	else if (c == 'u')
	{
		if (**p_p != 9)
		{
			**p_p = 9;
			*p_nm = *p_nm + 1;
		}
		
	}

	else if (c == 'm')
	{
		if (**p_p != 0)
		{
			**p_p = 0;
			*p_nm = *p_nm + 1;
		}
		
	}

}

//--------------------------------------------------
// print_status
//--------------------------------------------------
void print_status(int* a, int size_num, int* p, int num_mov) {
	printf("--- Game Status ---\n");
	printf("Number =  ");

	for (int i = 0; i < size_num; i++)
	{
		printf("%d", *(a + i));
	}

	printf("\n");

	for (int j = 0; j < size_num; j++)
	{
		if (p == (a + j))
		{

			int k = 0;
			printf("          ");
			while (k < (0 + j))
			{
				printf(" ");
				k++;
			}

		}

	}
	printf("^");

	printf("\nNumber moves  = ");

	printf("%d\n", num_mov);

}

//--------------------------------------------------
// user_game_palindrome
//--------------------------------------------------
void user_game_palindrome(int pal_num, int num_size, char commands[], int command_size) {

	int* a = (int*)malloc(num_size * sizeof(int));
	int aux_num = gen_num(0, (num_size - 1));
	int* p = &a[aux_num];
	int** pp = &p;
	int num_mov = 0;
	int* pnm = &num_mov;

	for (int i = (num_size - 1); i >= 0; i--)
	{
		*(a + i) = pal_num % 10;
		pal_num = pal_num / 10;
	}

	while (is_pal(a, num_size) == False)
	{
		char c = ' ';
		print_status(a, num_size, p, num_mov);
		c = ask_for_command(commands, command_size);
		process_movement(a, num_size, pp, pnm, c);

	} 

	print_status(a, num_size, p, num_mov);
		printf("------------------\n");
		printf("----- SOLVED -----\n");
		printf("------------------");

	my_get_char();
}