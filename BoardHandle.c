/*
 * board_struct.c
 *
 *  Created on: 17 בדצמ 2018
 *      Author: nir
 */
#include "BoardHandle.h"

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

#define SEPERATOR_ROW "----------------------------------\n"

void print_block(BLOCK block){
	int i;
	int j;
	for (i=0;i<N;i++){
		for (j=0;j<M;j++){
			printf("%d ", block[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void print_block_row(BLOCK block,BLOCK fixed_block,int row){
	int i;
	for (i=0;i<M;i++){
		if(fixed_block[row][i]!=0){
			printf(".");
		}else{
			printf(" ");
		}
		if(block[row][i]==0){
			printf(" ");
		}
		else{
			printf("%d",block[row][i]);
		}
	}
}


void print_board(BOARD board, BOARD fixed_board){
	int block_row = 0 ;
	int block_col = 0 ;
	int row = 0;
	for (block_row = 0;block_row<M;block_row++){
		printf(SEPERATOR_ROW);
		for(row = 0;row<N;row++){
			printf("| ");
			for (block_col = 0;block_col<N;block_col++){
				print_block_row(board[block_row][block_col],fixed_board[block_row][block_col],row);
				printf(" |");
			}
			printf("\n");
		}
	}
	printf(SEPERATOR_ROW);

}
void copy_Block(BLOCK in_block ,BLOCK out_block){
	int i=0;
	int j=0;
	for (i=0;i<N;i++){
		for(j=0;j<M;j++){
			out_block[i][j]=in_block[i][j];
		}
	}
}

void copy_board(BOARD in_board, BOARD out_board){
	int i=0;
	int j=0;
	for (i=0;i<M;i++){
		for(j=0;j<N;j++){
			copy_Block(in_board[i][j],out_board[i][j]);
		}
	}
}


