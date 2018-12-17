/*
 * Game.c
 *
 *  Created on: 12 בדצמ 2018
 *      Author: nir
 */

#include "Game.h"
#include "MainAux.h"


int is_valid_insertion(BOARD board,int x,int y,int z) {
	return is_valid_column(board,x,z) && is_valid_row(board,y,z) && is_valid_block(board[y/N][x/M],z);
}

int is_valid_column(BOARD board,int column,int z){
	int index;
	for (index = 0; index < N*M; index++){
		if (get_element_from_board(board, column, index) == z){
			return 0;
		}
	}
	return 1;
}

int is_valid_row(BOARD board,int row,int z) {
	int index;
	for (index = 0; index < N*M; index++){
		if (get_element_from_board(board, index, row) == z){
			return 0;
		}
	}
	return 1;
}

int is_valid_block(BLOCK block,int z){
	int index_col, index_row;
	for (index_col = 0; index_col < M; index_col++){
		for (index_row = 0; index_row < N; index_row++){
			if (get_element_from_block(block, index_col, index_row) == z){
				return 0;
			}
		}
	}
	return 1;
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

