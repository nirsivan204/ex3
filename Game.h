#include "board_struct.h"
enum Command {SET = 1, HINT = 2, VALIDATE = 3, RESTART = 4, EXIT = 5};
int set(BOARD board,BOARD fix_board, int x, int y, int z);
int is_valid_insertion(BOARD board,int x,int y,int z);
int is_valid_row(BOARD board,int row,int z);
int is_valid_column(BOARD board,int column,int z);
int is_valid_block(BLOCK block,int z);
