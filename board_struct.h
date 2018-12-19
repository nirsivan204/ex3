/*
 * board_struct.h
 *
 *  Created on: 12 בדצמ 2018
 *      Author: nir
 */
#include <stdlib.h>
#include <stdio.h>
#define N 2
#define M 2
typedef int BLOCK[N][M];
typedef BLOCK BOARD[M][N];

int get_element_from_block(BLOCK block, int x, int y);
int get_element_from_board(BOARD board, int x,int y);

void set_element_to_block(BLOCK block, int x, int y, int z);

void set_element_to_board(BOARD board, int x,int y,int z);
void zero_boards(BOARD board1, BOARD board2, BOARD board3);
void zero_board(BOARD board);
int is_valid_insertion(BOARD board,int x,int y,int z);
void print_block(BLOCK block);
void print_board(BOARD board, BOARD fixed_board);
void copy_board(BOARD in_board, BOARD out_board);
