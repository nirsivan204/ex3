/*
 * Solver.h
 *
 *  Created on: 12 בדצמ 2018
 *      Author: nir
 */
#include "BoardHandle.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void initialize_puzzle (int fix,BOARD game_board ,BOARD fix_board, BOARD solved_board);
int build_board_helper(BOARD solved_board,int x, int y, int is_determin);
