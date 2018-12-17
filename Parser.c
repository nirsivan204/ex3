#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
int is_legal_number(int number, int minValue, int maxValue) {
	return number >= minValue && number <= maxValue;
}
int num_of_params(int command) {
	switch (command) {
	case 1: /* set */
		return 3;
	case 2: /* hint */
		return 2;
	default:
		return 0;
	}
}

int search_command(char *s) {
	int index;
	char *commands[] = {"set", "hint", "validate", "restart", "exit"};
	for (index = 0; index < 5; index++)
		if (strcmp(s, commands[index]) == 0)
			return ++index;
	return -1;
}

int is_valid_command(char command_input[], int *command) {
	char *string;
	int index = 0;
	string = strtok(command_input, " \t\r\n");
	command[index] = search_command(string);
	if (command[index] == -1)
		return -1;
	for (index = 1; index <= num_of_params(command[0]); index++) {
		string = strtok(NULL, " \t\r\n");
		if (string == NULL)
			return -1;
		command[index] = atoi(string);
	}
	return 1;
}

int num_of_fixed_cells() {
	int num_Of_cells;
	printf("Please enter the number of cells to fill [0-80]:\n");
	fflush(stdout);
	if (scanf("%d", &num_Of_cells) == -1) {/* EOF */
		printf("Exiting...\n");
		return -1;
	}
	if (!is_legal_number(num_Of_cells, 0, 80)) {
		printf("Error: invalid number of cells to fill (should be between 0 and 80)\n");
		return num_of_fixed_cells();
	}
	return num_Of_cells;
}



int read_command(int *command) {
	char command_input[MAX_COMMAND_LENGTH];
	fgets(command_input, MAX_COMMAND_LENGTH, stdin);
	if (is_valid_command(command_input, command)==-1) {
		printf("Error: invalid command\n");
		return read_command(command);
	}
	return 1;
}






