
#define MAX_COMMAND_LENGTH 1024

enum Command {SET = 1, HINT = 2, VALIDATE = 3, RESTART = 4, EXIT = 5};

int is_legal_number(int number, int minValue, int maxValue);
int num_of_cells_to_fill();
void read_command(char *str[]);
int read_command2(int *command);
int is_valid_command(char command_input[], int *command);
void execute_command(int *command);
int get_num_of_params(int command);
int search_command(char *s);

