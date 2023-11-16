#include "main.h"

/**
 * add_v_node - adds a variable at the end
 * of a variable list.
 * @head: head of the linked list.
 * @lengthVar: length of the variable.
 * @value: value of the variable.
 * @lengthValue: length of the value.
 * Return: address of the head.
 */
replacement_var_list *add_v_node(replacement_var_list **head, int lengthVar, char *value, int lengthValue)
{
replacement_var_list *newVar, *tempVar;
newVar = malloc(sizeof(replacement_var_list));
if (newVar == NULL)
return (NULL);
newVar->len_var = lengthVar;
newVar->val = value;
newVar->len_val = lengthValue;
newVar->next = NULL;
tempVar = *head;
if (tempVar == NULL)
{
*head = newVar;
}
else
{
while (tempVar->next != NULL)
tempVar = tempVar->next;
tempVar->next = newVar;
}
return (*head);
}

/**
 * free_variable_list - frees a variable list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_variable_list(replacement_var_list **head)
{
replacement_var_list *tempVar;
replacement_var_list *currVar;
if (head != NULL)
{
currVar = *head;
while ((tempVar = currVar) != NULL)
{
currVar = currVar->next;
free(tempVar);
}
*head = NULL;
}
}

