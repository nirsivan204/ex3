/*
 * Game.c
 *
 *  Created on: 12 בדצמ 2018
 *      Author: nir
 */

#include "Game.h"
#include "MainAux.h"
int get_element_from_block(BLOCK block, int x, int y){
	print_block(block);
	return block[y%N][x%M];
}

void set_element_to_block(BLOCK block, int x, int y, int z){
	block[y%N][x%M] = z;
}

int is_valid_insertion(BOARD board,int x,int y,int z){



}


int set(BOARD board,BOARD fix_board, int x, int y, int z){
	x--;
	y--;
	int fix_val = get_element_from_block(fix_board[y/N][x/M],x,y);
	if(fix_val!=0){
		printf("Error: cell is fixed\n");
		return 0;
	}
	if(z==0){
		set_element_to_block(board[y/N][x/M],x,y,z);
		print_board(board,fix_board);
		return 1;
	}
	if(is_valid_insertion(board,x,y,z)==1){
		set_element_to_block(board[y/N][x/M],x,y,z);
		print_board(board, fix_board);
		return 1;
	}else{
		printf("Error: value is invalid\n");
		return 0;
	}
}

