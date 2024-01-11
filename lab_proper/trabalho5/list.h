#ifndef LIST_H
#define LIST_H

struct list
{
    long long registration;
    int entry_year;
    char name[64];
    struct list* next;
};
typedef struct list List;

List* create_list();
List* insert_list(List* l);
void print_list(List* l);
List* remove_from_list(List* l);

#endif