#include "monty.h"
carry_t carry = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: arguments vector
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *input;
size_t size_line = 0;
	ssize_t read_line = 1;
	FILE *filename;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = fopen(argv[1], "r");
	carry.file = filename;
	if (!filename)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		input = NULL;
		read_line = getline(&input, &size_line, filename);
		carry.matrial = input;
		counter++;
		if (read_line > 0)
		{
			execute(input, &stack, counter, filename);
		}
		free(input);
	}
	stack_free(stack);
	fclose(filename);
return (0);
}

/**
* execute - executes the opcode
* @stack: the stack
* @counter: line counter
* @fname: poiner to monty file
* @codeline: opcode line
* Return: 0 or 1
*/
int execute(char *codeline, stack_t **stack, unsigned int counter, FILE *fname)
{
	instruction_t op_instructions[] = {
				{"push", _push}, {"pall", _pall}, {"pint", _pint},
				{"pop", _pop},
				{"swap", _swap},
				{"add", _add},
				{"nop", _nop},
				{"sub", _sub},
				{"div", _div},
				{"mul", _mul},
				{"mod", _mod},
				{"pchar", _pchar},
				{"pstr", _pstr},
				{"rotl", _rotl},
				{"rotr", _rotr},
				{"queue", _queue},
				{"stack", _stack},
				{NULL, NULL}
				};

	char *opcodestr;
unsigned int index = 0;
	opcodestr = strtok(codeline, " \n\t");
	if (opcodestr && opcodestr[0] == '#')
		return (0);
	carry.arg = strtok(NULL, " \n\t");
	while (op_instructions[index].opcode && opcodestr)
	{
		if (strcmp(opcodestr, op_instructions[index].opcode) == 0)
		{	op_instructions[index].f(stack, counter);
			return (0);
		}
		index++;
	}
	if (opcodestr && op_instructions[index].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcodestr);
		fclose(fname);
		free(codeline);
		stack_free(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
