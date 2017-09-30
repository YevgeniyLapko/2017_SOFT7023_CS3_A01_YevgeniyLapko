
#include "pal.h"

//--------------------------------------------------
// is_pal
//--------------------------------------------------
boolean is_pal(int a[6]) {

	for (int i = 0; i < 2; i++)
	{
		if (a[i] != a[5 - i])
		{
			return False;
		}
		
	  return True;
		
	}

	
}

//--------------------------------------------------
// ask_for_command
//--------------------------------------------------
char ask_for_command() {
	char input;

	scanf_s("%c", &input);

	return input;
}

//--------------------------------------------------
// process_movement //nm = number of movements
//--------------------------------------------------
// int nm = 0;
// int* p_nm = &nm;
// p_p = is a pointer > pointer > int from an array
// int* p = &a[0];
//int** p_p = &p;
// p_p > pointing to address of p > pointing to p

//0
void process_movement(int a[6], int** p_p, int* p_nm, char c) {
	//int* ptr = &a[0];
	if (c == 'a') // have to change value of p to the next address
	{
		while (*p_p != &a[0]);
		{
			*p_p = *p_p - (1 * 4);
		} 
	}
	else if (c == 'd')
	{
		while (*p_p != &a[5])
		do {
			*p_p = *p_p + (1 * 4);
		} 
	}
	else if (c == 'w')
	{
		while (**p_p != 9)
		{
			**p_p = (**p_p) + 1;
		} 
	}
	else if (c == 'x')
	{
		while (**p_p != 1)
		{
			**p_p = (**p_p) - 1;
		} 
	}

	*p_nm = *p_nm + 1;

}

//--------------------------------------------------
// print_status
//--------------------------------------------------
void print_status(int a[6], int* p, int nm) {
	printf("--- Game Status ---\n");
	printf("Number =  ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n Number moves = ");
	printf("%d", nm);
	printf("%d", *p);
	//printf("\n");

}

//--------------------------------------------------
// user_game_palindrome
//--------------------------------------------------
void user_game_palindrome(int pal_num) {

	int a[6];
	int num_mov = 0;
	int* pnm = &num_mov;
	int i = 5;

	while (pal_num > 0)
	{
		a[i] = pal_num % 10;
		pal_num = pal_num / 10;
		i--;
	}

	int* p = &a;
	int** pp = &p;

	while (is_pal(a) == False)
	{
		char c;
		print_status(a, p, num_mov);
		while (c != 'a' || 'd' || 'w' || 'x')
		{
			printf("NEW MOVEMENT: Enter a valid command by keyword:\n");
			printf("Valid commands: a     d     w     x");
			c = ask_for_command();
		} 
		process_movement(a, pp, pnm, c);
	}

	printf("------------------");
	printf("----- SOLVED -----");
	printf("------------------");

}
