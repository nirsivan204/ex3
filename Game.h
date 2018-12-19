#include "board_struct.h"
#include "Solver.h"
enum Command {SET = 1, HINT = 2, VALIDATE = 3, RESTART = 4, EXIT = 5};
int execute_command(int *command, BOARD board, BOARD fix_board, BOARD solved_board);
