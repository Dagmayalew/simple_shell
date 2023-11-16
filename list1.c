#include "main.h"

/**
 * add_separator_node_end - adds a separator found at the end
 * of a separator_list.
 * @head: head of the linked list.
 * @sep: separator found (; | &).
 * Return: address of the head.
 */
separator_list *add_separator_node_end(separator_list **head, char sep)
{
	separator_list *new_sep, *temp_sep;

	new_sep = malloc(sizeof(separator_list));
	if (new_sep == NULL)
		return (NULL);

	new_sep->separator = sep;
	new_sep->next = NULL;
	temp_sep = *head;

	if (temp_sep == NULL)
	{
		*head = new_sep;
	}
	else
	{
		while (temp_sep->next != NULL)
			temp_sep = temp_sep->next;
		temp_sep->next = new_sep;
	}

	return (*head);
}

/**
 * free_separator_list - frees a separator_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_separator_list(separator_list **head)
{
	separator_list *temp_sep;
	separator_list *curr_sep;

	if (head != NULL)
	{
		curr_sep = *head;
		while ((temp_sep = curr_sep) != NULL)
		{
			curr_sep = curr_sep->next;
			free(temp_sep);
		}
		*head = NULL;
	}
}

/**
 * add_line_node_end - adds a command line at the end
 * of a line_list.
 * @head: head of the linked list.
 * @command_line: command line.
 * Return: address of the head.
 */
line_list *add_line_node_end(line_list **head, char *command_line)
{
	line_list *new_line, *temp_line;

	new_line = malloc(sizeof(line_list));
	if (new_line == NULL)
		return (NULL);

	new_line->line = command_line;
	new_line->next = NULL;
	temp_line = *head;

	if (temp_line == NULL)
	{
		*head = new_line;
	}
	else
	{
		while (temp_line->next != NULL)
			temp_line = temp_line->next;
		temp_line->next = new_line;
	}

	return (*head);
}

/**
 * free_line_list - frees a line_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_line_list(line_list **head)
{
	line_list *temp_line;
	line_list *curr_line;

	if (head != NULL)
	{
		curr_line = *head;
		while ((temp_line = curr_line) != NULL)
		{
			curr_line = curr_line->next;
			free(temp_line);
		}
		*head = NULL;
	}
}
