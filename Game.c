/*
 * Game.c
 *
 *  Created on: 12 áãöî 2018
 *      Author: nir
 */

#include "Game.h"


int hint(BOARD solved_board, int x, int y) {
	printf("Hint: set cell to %d\n", get_element_from_board(solved_board, x, y));
	return 0;
}

int validate(BOARD board, BOARD solved_board) {
	int is_solvable;
	BOARD temp_board;
	copy_board(board,temp_board);
	is_solvable = build_board(temp_board,1);
	if(is_solvable == 1){
		copy_board(temp_board,solved_board);
		printf("Validation passed: board is solvable\n");
	}
	else{
		printf("Validation failed: board is unsolvable\n");
	}
	return 0;
}

int exit_game() {
	/* free resources...? */
	printf("Exiting…\n");
	return 0;
}

int restart_game() {
	return 0;
}

int puzzle_solved(BOARD board) {
	int i;
	int j;
	for (i=0;i<M*N;i++){
		for (j=0;j<M*N;j++) {
			if (get_element_from_board(board, i, j) == 0) {
				return 0;
			}
		}
	}
	printf("Puzzle solved successfully\n");
	return 1;
}

void insert(BOARD board,BOARD fix_board, int x, int y, int z) {
	set_element_to_board(board,x,y,z);
	print_board(board, fix_board);
}

int set(BOARD board,BOARD fix_board, int x, int y, int z){
	int fix_val = get_element_from_board(fix_board,x,y);
	if(fix_val!=0){
		printf("Error: cell is fixed\n");
		return 0;
	}
	if(z==0){
		insert(board,fix_board,x,y,z);
		return 0;
	}
	if(is_valid_insertion(board,x,y,z)==1){
		insert(board,fix_board,x,y,z);
		return puzzle_solved(board);
	}
	printf("Error: value is invalid\n");
	return 0;
}

int execute_command(int *command, BOARD board, BOARD fix_board, BOARD solved_board) {
	switch (command[0]) {
	case SET:
		return set(board, fix_board, --command[1], --command[2], command[3]);
	case HINT:
		return hint(solved_board, --command[1], --command[2]);
	case VALIDATE:
		return validate(board, solved_board);
	case RESTART:
		return restart_game();
	case EXIT:
		return exit_game();
	default:
		return 0;
	}
}

