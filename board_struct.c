/*
 * board_struct.c
 *
 *  Created on: 17 בדצמ 2018
 *      Author: nir
 */
#include "board_struct.h"

int get_element_from_block(BLOCK block, int x, int y){
	return block[y%N][x%M];
}
int get_element_from_board(BOARD board, int x,int y){
	return get_element_from_block(board[y/N][x/M],x,y);
}

void set_element_to_block(BLOCK block, int x, int y, int z){
	block[y%N][x%M] = z;
}

void set_element_to_board(BOARD board, int x,int y,int z){
	set_element_to_block(board[y/N][x/M],x,y,z);
}

void zero_boards(BOARD board1, BOARD board2, BOARD board3){
	zero_board(board1);
	zero_board(board2);
	zero_board(board3);
}

void zero_board(BOARD board){
	int i;
	int j;
	for (i=0;i<M*N;i++){
		for (j=0;j<M*N;j++){
			set_element_to_board(board,j,i,0);
		}
	}
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

int is_valid_insertion(BOARD board,int x,int y,int z) {
	return is_valid_column(board,x,z) && is_valid_row(board,y,z) && is_valid_block(board[y/N][x/M],z);
}



