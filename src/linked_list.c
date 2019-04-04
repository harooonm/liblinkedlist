#include <stdlib.h>
#include "linked_list.h"

void linked_list_append(struct linked_list_node **head, void *data)
{
	struct linked_list_node **hc = head;
	while (*hc)
		hc = &(*hc)->next;
	*hc = malloc(sizeof(struct linked_list_node));
	(*hc)->data = data;
	(*hc)->next = NULL;
}

void linked_list_itr(struct linked_list_node *head,
		void (*for_each)(struct linked_list_node *entry))
{
	while(head){
		for_each(head);
		head = head->next;
	}
	
}

void linked_list_free(struct linked_list_node *head, int free_data)
{
	while(head){
		struct linked_list_node *n = head->next;
		if (free_data && head->data)
			free(head->data);
		free(head);
		head = n;
	}
}

struct linked_list_node *linked_list_find(struct linked_list_node *head, void *data,
                comp_func comp)
{
	while(head){
		if (comp(head->data, data))
			return head;
		head = head->next;
	}
}

void linked_list_remove(struct linked_list_node **head, void *data,     
                comp_func comp, int free_data)
{
	struct linked_list_node **hc = head;
	while(*hc){
		if (comp((*hc)->data, data)) {
			struct linked_list_node *nc = (*hc)->next;
			if (free_data && (*hc)->data)
				free((*hc)->data);
			free(*hc);
			*hc = nc;
			break;	
		}
		hc = &(*hc)->next;		
	}
}
