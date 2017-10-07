
#include "pal.h"

//--------------------------------------------------
// is_pal
//--------------------------------------------------
boolean is_pal(int a[6]) {

	for (int i = 0; i <= 2; i++)
	{
		if (*(a + i) != *(a + (5 - i)))
		
		{
			return False;
		}

	}
	return True;

}

//--------------------------------------------------
// ask_for_command
//--------------------------------------------------
char ask_for_command() {
	char input;
	do
	{
		printf("\nNEW MOVEMENT: Enter a valid command by keyword:\n");
			printf("Valid commands: a     d     w     x\n");
			printf("Your command is: ");
			input = my_get_char();
	} while ((input != 'a') && (input != 'x') && (input != 'd') && (input != 'w'));
	return input;
}

//--------------------------------------------------
// process_movement 
//--------------------------------------------------

//0
void process_movement(int a[6], int** p_p, int* p_nm, char c) {

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
		if (*p_p != (a + 5))
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

}

//--------------------------------------------------
// print_status
//--------------------------------------------------
void print_status(int a[6], int* p, int nm) {
	printf("--- Game Status ---\n");
	printf("Number =  ");

	for (int i = 0; i < 6; i++)
		{
		 printf("%d", a[i]);
		}
	
	printf("\n");
	
	for (int j = 0; j < 6; j++)
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

	printf("%d\n", nm);

}

//--------------------------------------------------
// user_game_palindrome
//--------------------------------------------------
void user_game_palindrome(int pal_num) {

	int a[6];
	int num_mov = 0;
	int i = 5;
	int aux_num = gen_num(0, 5);
	int* p = &a[aux_num];
	int** pp = &p;
	int* pnm = &num_mov;

	do
	{
		a[i] = pal_num % 10;
		pal_num = pal_num / 10;
		i--;
	} while (pal_num > 0);

	//do
	while (is_pal(a) == False)
	{
		char c = ' ';
		print_status(a, p, num_mov);
		c = ask_for_command();
		process_movement(a, pp, pnm, c);

	} 

	print_status(a, p, num_mov);
		printf("------------------\n");
		printf("----- SOLVED -----\n");
		printf("------------------");

	

}
