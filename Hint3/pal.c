//--------------------------------------------------
// INCLUDE SECTION
//--------------------------------------------------
#include "pal.h"

//--------------------------------------------------
// is_pal
//--------------------------------------------------
boolean is_pal(int* a, int size_num) {
	boolean res = True;

	return res;
}

//--------------------------------------------------
// ask_for_command
//--------------------------------------------------
char ask_for_command() {
	char input = ' ';

	return input;
}

//--------------------------------------------------
// process_movement
//--------------------------------------------------
void process_movement(int* a, int size_num, int** p_p, int* p_nm, char c) {


}

//--------------------------------------------------
// print_status
//--------------------------------------------------
void print_status(int* a, int size_num, int* p) {
	
	printf("--- Game Status ---\n");
	printf("Number =  ");

	for (int i = 0; i < size_num; i++)
	{
		printf("%d", *(a + i));
	}

	printf("\n");


}

void print_status1(int* a, int size_num) {

	printf("\nThe optimum palindrome is:\n");
	printf("Number =  ");

	for (int i = 0; i < size_num; i++)
	{
		printf("%d", *(a + i));
	}

	printf("\n");

	

}

//--------------------------------------------------
// user_game_palindrome
//--------------------------------------------------


//--------------------------------------------------
// get_solving_array
//--------------------------------------------------
char* get_solving_array(int* a, int size_num, int* p, int* total_movs) {
	//char* res = NULL;

	char* solving = (char*)malloc( *total_movs * sizeof(char));
	int k = 0;


	for (int i = 0; i < (size_num / 2); i++) // start at 3 finish at 5 654381
	{
		if (*(a + i) != *(a + ((size_num - 1) - i)))

		{
			int dif = *(a + i) - *(a + ((size_num - 1) - i));

			boolean up = False;
			if (dif < 0) {
				up = True;
				dif = dif * (-1);
			}

			for (int j = 0; j < dif; j++) {
				if (up == True)
					solving[k] = 'W';
				else
					solving[k] = 'X';
				k++;
			}
		}

		if (i != ((size_num / 2) - 1)) {
			solving[k] = 'D';
			k++;
		}
	}


	return solving;
}

//--------------------------------------------------
// machine_game_palindrome
//--------------------------------------------------										  012345
void machine_game_palindrome(int pal_num, int num_size, char* commands, int commands_size) { //654321, 6, adwx, 4

	int* a = (int*)malloc(num_size * sizeof(int));
	int* b = (int*)malloc(num_size * sizeof(int));
	int totalMoves = (num_size/2) - 1;
	int* ptm = &totalMoves;
	int count = 0;
	int* pA = &a;
	int* pB = &b;
	
	
	for (int i = (num_size - 1); i >= 0; i--)
	{
		*(a + i) = pal_num % 10;
		*(b + i) = pal_num % 10;
		pal_num = pal_num / 10;

	}
	for
		(int i = 0; i < (num_size / 2); i++)
	{
		if (b[i] > b[num_size - 1 - i])
		{
			while (b[i] > b[num_size - 1 - i])
			{
				b[i] = b[i] - 1;
				totalMoves = totalMoves + 1;
			}
		}

		else if (b[i] < b[num_size - 1 - i])
		{
			while (b[i] < b[num_size - 1 - i])
			{
				b[i] = b[i] + 1;
				totalMoves = totalMoves + 1;
			}
		}
	}

	print_status(a, num_size, pA, totalMoves);
	

	print_status1(b, num_size);

		

	char* arr = get_solving_array(a, num_size, pA, &totalMoves);

	printf("\nSTART");
	printf("\n-----");

	for (int z = 0; z < totalMoves; z++)
	{
		char input = ' ';

		{
			do
			{
				printf("\nWant to see next move?\nPress 'Enter' to see next correct move!");
				input = my_get_char();
			} while (input != '\n');
		}

		printf("Guess what... next correct move is ");
		printf("%c", arr[z]);
		printf("\n");
	}

	printf("\nNumber moves done total = ");

	printf("%d", totalMoves);
	my_get_char();



}



