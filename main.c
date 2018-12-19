/*
 * main.c
 *
 *  Created on: 12 בדצמ 2018
 *      Author: nir
 */

#include "SPBufferset.h"
#include "MainAux.h"
#include "Solver.h"
#include "Game.h"
#include "Parser.h"
#include <time.h>
#include "board_struct.h"

int main(int argc, char *argv[]){
	BOARD game_board;
	BOARD fix_board;
	BOARD solved_board;
	int fix;
	int is_game_over = 0;
	int command[4];
	int seed = atoi(argv[0]);
	srand(seed);
	SP_BUFF_SET();
	do {
		fix = num_of_fixed_cells();
		initialize_puzzle(fix, game_board, fix_board, solved_board);
		do{
			read_command(command, is_game_over);
			is_game_over = execute_command(command, game_board, fix_board, solved_board);
		}while(command[0] < 4);/*set, hint or validate*/
	}while(command[0] == RESTART);
	return 0;
}
