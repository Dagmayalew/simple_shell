#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;

/**
 * struct data_container - struct that contains all relevant data on runtime
 * @argVector: argument vector
 * @input: command line written by the user
 * @arguments: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environment: environment variable
 * @processId: process ID of the shell
 */
typedef struct data_container
{
	char **argVector;
	char *input;
	char **arguments;
	int status;
	int counter;
	char **_environment;
	char *processId;
} data_container;

/**
 * struct separator_list - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct separator_list
{
	char separator;
	struct separator_list *next;
} separator_list;

/**
 * struct line_list - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct line_list
{
	char *line;
	struct line_list *next;
} line_list;

/**
 * struct replacement_var_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct replacement_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct replacement_var_list *next;
} replacement_var_list;

/**
 * struct builtin_struct - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_struct
{
	char *name;
	int (*f)(data_container *data);
} builtin_t;


separator_list *add_separator_node_end(separator_list **head, char sep);
void free_separator_list(separator_list **head);
line_list *add_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);
replacement_var_list *add_v_node(replacement_var_list **head, int lengthVar, char *value, int lengthValue);
void free_variable_list(replacement_var_list **head);
#endif
