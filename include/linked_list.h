#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

struct linked_list_node {
	void *data;
	struct linked_list_node *next;
};

typedef int (*comp_func)(void *existing, void *passed);

extern void linked_list_append(struct linked_list_node **head, void *data);
extern void linked_list_remove(struct linked_list_node **head, void *data,
                comp_func comp, int free_data);
extern void linked_list_free(struct linked_list_node *head, int free_data);
extern struct linked_list_node *linked_list_find(struct linked_list_node *head,
                void *data, comp_func comp);
extern void linked_list_itr(struct linked_list_node *head,
                void (*for_each)(struct linked_list_node *entry, void *extra), void *extra);

#endif
