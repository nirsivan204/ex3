/*
 * board_struct.h
 *
 *  Created on: 12 בדצמ 2018
 *      Author: nir
 */
#include <stdlib.h>
#include <stdio.h>
#define N 2
#define M 3
typedef int BLOCK[N][M];
typedef BLOCK BOARD[M][N];

int get_element_from_block(BLOCK block, int x, int y);
int get_element_from_board(BOARD board, int x,int y);

void set_element_to_block(BLOCK block, int x, int y, int z);

void set_element_to_board(BOARD board, int x,int y,int z);
