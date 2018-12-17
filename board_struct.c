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
