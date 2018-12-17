#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

int num_of_cells_to_fill() {
	int numOfCells;
	printf("Please enter the number of cells to fill [0-80]:\n");
	fflush(stdout);
	if (scanf("%d", &numOfCells) == -1) {/* EOF */
		printf("Exiting…\n");
		return -1;
	}
	if (!is_legal_number(numOfCells, 0, 80)) {
		printf("Error: invalid number of cells to fill (should be between 0 and 80)\n");
		return num_of_cells_to_fill();
	}
	return numOfCells;
}

int is_legal_number(int number, int minValue, int maxValue) {
	return number >= minValue && number <= maxValue;
}

void read_command(char *command[]) {
	int index;
	char *string;
	char command_input[MAX_COMMAND_LENGTH];
	fgets(command_input, MAX_COMMAND_LENGTH, stdin);
	string = strtok(command_input, " \t\r\n");
	while (string && index < 4) {
		command[index] = string;
		string = strtok(NULL, " \t\r\n");
		index++;
	}
}

int read_command2(int *command) {
	char command_input[MAX_COMMAND_LENGTH];
	fgets(command_input, MAX_COMMAND_LENGTH, stdin);
	int num_of_command = is_valid_command(command_input, command);
	if (num_of_command==-1) {
		printf("Error: invalid command\n");
		return read_command2(command);
	}
	return num_of_command;
}

int is_valid_command(char command_input[], int *command) {
	char *string;
	int index = 0;
	int num_of_params;
	string = strtok(command_input, " \t\r\n");
	command[index] = search_command(string);
	if (command[index] == 0)
		return -1;
	num_of_params = get_num_of_params(command[0]);
	for (index = 1; index <= num_of_params; index++) {
		string = strtok(NULL, " \t\r\n");
		if (string == NULL)
			return -1;
		command[index] = atoi(string);
	}
	return num_of_params;
}

//void execute_command(int *command) {
//	switch (command[0]) {
//	case SET:
//		//
//	case HINT:
//		//
//	case VALIDATE:
//		//
//	case RESTART:
//		//
//	case EXIT:
//		//
//	}
//}

int get_num_of_params(int command) {
	switch (command) {
	case SET:
		return 3;
	case HINT:
		return 2;
	default:
		printf("%d", 7);
		return 0;
	}
}

int search_command(char *s) {
	int index;
	char *commands[] = {"set", "hint", "validate", "restart", "exit"};
	for (index = 0; index < 5; index++)
		if (strcmp(s, commands[index]) == 0)
			return ++index;
	return 0;
}
