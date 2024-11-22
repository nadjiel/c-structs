#include <stdio.h>
#include "linked_list.h"
#include "error.h"

void print_step(char* msg, Node* list, int status) {
    printf("%s: ", msg);
    print_list(list);
    printf(" %s\n", get_error_msg(status));
}

void show_insertion() {
    int status = SUCCESS;
    Node* list = NULL;
    
    print_step("start", list, status);
    
    status = insert_first(NULL, 1);
    print_step("insert_first(NULL)", list, status);
    
    status = insert_first(&list, 1);
    print_step("insert_first(1)", list, status);
    
    status = insert_first(&list, 2);
    print_step("insert_first(2)", list, status);
    
    status = empty(&list);
    print_step("cleared", list, status);
    
    status = insert_last(NULL, 1);
    print_step("insert_last(NULL)", list, status);
    
    status = insert_last(&list, 1);
    print_step("insert_last(1)", list, status);
    
    status = insert_last(&list, 2);
    print_step("insert_last(2)", list, status);
    
    status = empty(&list);
    print_step("cleared", list, status);
    
    status = insert(&list, 1, -1);
    print_step("insert(1, -1)", list, status);
    
    status = insert(&list, 1, 1);
    print_step("insert(1, 1)", list, status);
    
    status = insert(&list, 1, 0);
    print_step("insert(1, 0)", list, status);
    
    status = insert(&list, 2, 1);
    print_step("insert(2, 1)", list, status);
}

void show_update() {
    int status = SUCCESS;
    Node* list = create_node(0);
    status = insert_last(&list, 1);
    
    print_step("start", list, status);
    
    status = update_first(NULL, 1);
    print_step("update_first(NULL, 1)", list, status);
    
    status = update_first(list, 1);
    print_step("update_first(list, 1)", list, status);
    
    status = update_last(NULL, 2);
    print_step("update_last(NULL, 2)", list, status);
    
    status = update_last(list, 2);
    print_step("update_last(list, 2)", list, status);
    
    status = update(list, 0, -1);
    print_step("update(0, -1)", list, status);
    
    status = update(list, 1, 2);
    print_step("update(1, 2)", list, status);
    
    status = update(list, 0, 0);
    print_step("update(0, 0)", list, status);
    
    status = update(list, 1, 1);
    print_step("update(1, 1)", list, status);
}

void show_deletion() {
    int status = SUCCESS;
    Node* list = NULL;
    
    print_step("start", list, status);
    
    status = delete_first(NULL);
    print_step("delete_first(NULL)", list, status);
    
    status = delete_first(&list);
    print_step("delete_first(&list)", list, status);
    
    status = insert_last(&list, 1);
    print_step("inserted", list, status);
    
    status = delete_first(&list);
    print_step("delete_first(&list)", list, status);
    
    status = delete_last(NULL);
    print_step("delete_last(NULL)", list, status);
    
    status = delete_last(&list);
    print_step("delete_last(&list)", list, status);
    
    status = insert_last(&list, 1);
    print_step("inserted", list, status);
    
    status = delete_last(&list);
    print_step("delete_last(&list)", list, status);
    
    status = delete(NULL, 0);
    print_step("delete(NULL, 0)", list, status);
    
    status = delete(&list, 0);
    print_step("delete(&list, 0)", list, status);
    
    status = insert_last(&list, 1);
    print_step("inserted", list, status);
    
    status = insert_last(&list, 2);
    print_step("inserted", list, status);
    
    status = delete(&list, -1);
    print_step("delete(&list, -1)", list, status);
    
    status = delete(&list, 2);
    print_step("delete(&list, 2)", list, status);
    
    status = delete(&list, 1);
    print_step("delete(&list, 1)", list, status);
    
    status = delete(&list, 0);
    print_step("delete(&list, 0)", list, status);
}

int main() {
    printf("Linked Lists in C\n\n");
    
    show_deletion();
    
    return 0;
}
