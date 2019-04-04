#include "linked_list.h"
#include <stdio.h>
#include <string.h>

void for_e(struct linked_list_node *head)
{
	fprintf(stdout, "%s\n", (char *)head->data);
}

int com(void *existing, void *passed)
{
	if(!strcmp((char *)existing, (char *)passed))
		return 1;
	return 0;
}

int main()
{
	struct linked_list_node *head = NULL;
	
	linked_list_append(&head, "abcd");
	
	linked_list_append(&head, "xyz");
	
	linked_list_append(&head, "123");
	
	linked_list_append(&head, "456");
	
	linked_list_append(&head, "789");
	
	linked_list_append(&head, "101112");
	
	linked_list_remove(&head, "abcd", com, 0);

	linked_list_itr(head, for_e);
	
	linked_list_free(head, 0);
}
