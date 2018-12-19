/*
 * Solver.c

 *
 *  Created on: 12 בדצמ 2018
 *      Author: nir
 */
#include "Solver.h"
#include "assert.h"



void print_array(int *arr,int length){
	int i;
	for (i = 0;i<length;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int get_rand_number(int range){
	return rand()%range;
}
void delete_digit(int *legal_digits,int index, int length){
	int i;
	for(i=index;i<length-1;i++){
		legal_digits[i] = legal_digits[i+1];
	}
}

int find_legal_digits(int *legal_digits,BOARD game_board,int x,int y){
	int digit;
	int num_of_legal_digits = 0;
	for (digit = 1;digit<=N*M;digit++){
		if(is_valid_insertion(game_board,x,y,digit)==1){
			legal_digits[num_of_legal_digits] = digit;
			num_of_legal_digits++;
		}
	}
	return num_of_legal_digits;
}

int compute_next_cordinates(int x, int y , int *next_x , int *next_y){
	if(x==N*M-1){
		*next_x = 0;
		if(y == N*M-1){
			return 1;
		}else{
			*next_y =y+1;
		}
	}else{
		*next_x = x+1;
		*next_y = y;
	}
	return 0;
}

int get_valid_digit(int *legal_digits ,int num_of_legal_digits, int is_determin){
	int index = 0;
	int res = 0;
	if(num_of_legal_digits == 1){
		return legal_digits[0];
	}
	//print_array(legal_digits,num_of_legal_digits);
	if(is_determin==0){
		index = get_rand_number(num_of_legal_digits);
	}
	res = legal_digits[index];
	delete_digit(legal_digits,index,num_of_legal_digits);
	return res;
}

int build_board_helper(BOARD solved_board,int x, int y, int is_determin){
	int next_x;
	int next_y;
	int digit;
	int num_of_legal_digits;
	int valid = 0;
	int legal_digits[N*M];
	int end_of_board = 0;
	num_of_legal_digits = find_legal_digits(legal_digits,solved_board, x, y);
	end_of_board = compute_next_cordinates(x,y,&next_x,&next_y);
	if(get_element_from_board(solved_board,x,y)!=0){
		assert(is_determin == 1);
		if(end_of_board == 0 ){
			return build_board_helper(solved_board,next_x,next_y,is_determin);
		}
	}
	if(end_of_board == 1){
		//assert(num_of_legal_digits == 1);
		if(get_element_from_board(solved_board,x,y) == 0){

			set_element_to_board(solved_board,x,y,legal_digits[0]);
		}
		return 1;
	}
	if(get_element_from_board(solved_board,x,y)!=0){
		return build_board_helper(solved_board,next_x,next_y,is_determin);
	}
	if(num_of_legal_digits == 0){
		set_element_to_board(solved_board,x,y,0);
		return 0;
	}
	//printf("num_of_legal_digits = %d , valid = %d" , num_of_legal_digits,valid);
	while (num_of_legal_digits>0 && valid == 0){
		digit = get_valid_digit(legal_digits , num_of_legal_digits , is_determin);
		set_element_to_board(solved_board,x,y,digit);
		//print_board(solved_board,solved_board);
		valid = build_board_helper(solved_board,next_x,next_y,is_determin);
		num_of_legal_digits--;
	}
	if(valid == 0){
		set_element_to_board(solved_board,x,y,0);
		return 0;
	}
	return 1;
}

void make_fix_board(int fix, BOARD fix_board, BOARD solved_board){
	int counter = 0;
	int x;
	int y;
	while(counter<fix){
		x = get_rand_number(N*M);
		y = get_rand_number(N*M);
		if(get_element_from_board(fix_board,x,y)==0){
			set_element_to_board(fix_board,x,y,get_element_from_board(solved_board,x,y));
			counter++;
		}
	}
}

void initialize_puzzle (int fix, BOARD game_board ,BOARD fix_board, BOARD solved_board){
	zero_boards(game_board, fix_board, solved_board);
	int res = build_board_helper(solved_board,0,0,0);
	assert(res != 0);
	make_fix_board(fix,fix_board,solved_board);
	print_board(solved_board,fix_board);
	copy_board(fix_board,game_board);
	print_board(game_board,fix_board);
}




