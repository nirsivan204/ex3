/*
 * MainAux.c
 *
 *  Created on: 12 בדצמ 2018
 *      Author: nir
 */
#include "MainAux.h"


#define SEPERATOR_ROW "----------------------------------\n"

void print_block_row(BLOCK block,BLOCK fixed_block,int row){
	int i=0;
	for (;i<m;i++){
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
	for (;block_row<m;block_row++){
		printf(SEPERATOR_ROW);
		printf("| ");
		for (;block_col<n;block_col++){
			for(;row<n;row++){
				print_block_row(board[block_row,block_col],fixed_board[block_row,block_col],row);
				printf(" |");
			}
			row = 0;
			printf("\n");
		}
		block_col = 0;
		printf(SEPERATOR_ROW);
	print(SEPERATOR_ROW);
	}

}
void copy_Block(in_block ,out_block){
	int i=0;
	int j=0;
	for (;i<n;i++){
		for(;j<m;j++){
			out_block[i][j]=in_block[i][j];
		}
	}
}

void copy_board(BOARD in_board, BOARD out_board){
	int i=0;
	int j=0;
	for (;i<m;i++){
		for(;j<n;j++){
			copy_Block(in_board[i][j],out_board[i][j]);
		}
	}
}


