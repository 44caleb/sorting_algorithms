#include "sort.h"


void insertion_sort_list(listint_t **list)
{
	listint_t *ptr_f, *curr_node, *prev_node;

	if ((*list)->next == NULL)
	{
		return; /* only one element in list*/
	}
	ptr_f = (*list)->next;

	while (ptr_f != NULL)
	{
		curr_node = ptr_f;

		while (curr_node->prev != NULL)
		{
			prev_node = curr_node->prev;

			if (prev_node->n > curr_node->n)
			{
				if (prev_node->prev != NULL && curr_node->next != NULL)
				{
					(curr_node->next)->prev = prev_node;
					(prev_node->prev)->next = curr_node;
					prev_node->next = (curr_node->next);
					curr_node->prev = prev_node->prev;
					curr_node->next = prev_node;
					prev_node->prev = curr_node;
				}
				else if (prev_node->prev == NULL && curr_node->next == NULL)
				{
					prev_node->prev = curr_node;
					curr_node->next = prev_node;
					prev_node->next = NULL;
					curr_node->prev = NULL;
					*list = curr_node;
				}
				else if (prev_node->prev == NULL && curr_node->next != NULL)
				{
					prev_node->prev = curr_node;
					prev_node->next = curr_node->next;
					(curr_node->next)->prev = prev_node;
					curr_node->next = prev_node;
					curr_node->prev = NULL;
					*list = curr_node;
				}
				else if (prev_node->prev != NULL && curr_node->next == NULL)
				{
					curr_node->next = prev_node;
					curr_node->prev = prev_node->prev;
					(prev_node->prev)->next = curr_node;
					prev_node->prev = curr_node;
					prev_node->next = NULL;
				}
				print_list(*list);
			}
			else
			{
				curr_node = curr_node->prev;
			}
		}
		ptr_f = ptr_f->next;
	}
}




int main(void)
{
	listint_t *list;
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);
	list = create_listint(array, n);
	if (!list)
		return (1);
	print_list(list);
	printf("\n");
	insertion_sort_list(&list);
	printf("\n");
	print_list(list);
	return (0);
}

