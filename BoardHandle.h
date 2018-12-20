/*
 * BoardHandle.h - storing all the types_def,constants, and functions regarding the sudoko board.
 *x - col, starting from 0;
 *y - row, starting from 0;
 *
 *get_element_from_board     - getting the element in x,y cell. 0 means no value
 *set_element_to_board 		 - setting a digit in a cell.
 *zero_board				 - initializing a board with zeros
 *is_valid_insertion		 - checking if the digit can be in the cell by the laws of the game
 *print_board                - printing the board
 *copy_board                 - copying a board to another one
 */
#include <stdlib.h>
#include <stdio.h>
#define N 3 /*num of rows in a block*/
#define M 3 /*num of cols in a block*/
#define SEPERATOR_ROW "----------------------------------\n"
typedef int BLOCK[N][M]; /*BLOCK is a N X M matrix of ints*/
typedef BLOCK BOARD[M][N]; /*BOARD is a M X N matrix of BLOCKs*/





/*
 * @param board - the board.
 * @param x - the cell's col.
 * @param y - the cell's row.
 * @return the element in cell x,y. 0 is empty cell
 *
 */
int get_element_from_board(BOARD board, int x,int y);

/*
 * @param board - the board.
 * @param x - the cell's col.
 * @param y - the cell's row.
 * @param z - the desired value. 0 means to empty the cell.
 *
 */
void set_element_to_board(BOARD board, int x,int y,int z);

/*
 * @param board - the board needed to be empty. the board will be initialized with zeros
 *
 */
void zero_board(BOARD board);

/*
 * @param board - the board.
 * @param x - the cell's col.
 * @param y - the cell's row.
 * @param z - the value needed to be checked if legal.
 * @return 1 if z can be insert to the board in x,y. 0 if not
 *
 */
int is_valid_insertion(BOARD board,int x,int y,int z);

/*
 * @param board - the board needed to be printed.
 * @param fixed_board - the fixed board. the function needs it to print "." before fixed values, or " " before not fixed values.
 *
 */
void print_board(BOARD board, BOARD fixed_board);

/*
 * @param in_board - the board needed to be copied.
 * @param out_board- the board that will be a copy of in_board after the function call
 *
 */
void copy_board(BOARD in_board, BOARD out_board);
