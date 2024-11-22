#include "linked_list.h"
#include "error.h"

/* 
 * Time complexity: O(1)
 */
Node* create_node(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    
    node->data = data;
    node->next = NULL;
    
    return node;
}

/* 
 * Time complexity: O(n)
 */
Node* search_recursive(Node* list, int index, int count) {
    if(list == NULL || index < 0 || count < 0) {
        return NULL;
    }
    if(index == count) {
        return list;
    }
    
    return search_recursive(list->next, index, count + 1);
}

/* 
 * Time complexity: O(n)
 */
Node* search_iterative(Node* list, int index) {
    if(list == NULL || index < 0) {
        return NULL;
    }
    
    int count = 0;
    
    while(count < index) {
        if(list->next == NULL) {
            return NULL;
        }
        
        list = list->next;
        count++;
    }
    
    return list;
}

/* 
 * Time complexity: O(n)
 */
Node* search_last(Node* list) {
    if(list == NULL) {
        return NULL;
    }
    if(list->next == NULL) {
        return list;
    }
    
    return search_last(list->next);
}

/* 
 * Time complexity: O(n)
 */
Node* search_prelast(Node* list) {
    if(list == NULL) {
        return NULL;
    }
    if(list->next == NULL) {
        return NULL;
    }
    if(list->next->next == NULL) {
        return list;
    }
    
    return search_prelast(list->next);
}

/*
 * Time complexity: O(n)
 */
int length_recursive(Node* list, int count) {
    if(count < 0) {
        return -1;
    }
    if(list == NULL) {
        return count;
    }
    
    return length_recursive(list->next, count + 1);
}

/* 
 * Time complexity: O(n)
 */
int length_iterative(Node* list) {
    int count = 0;
    
    while(list != NULL) {
        count++;
        list = list->next;
    }
    
    return count;
}

/*
 * Time complexity: O(1)
 */
bool is_empty(Node* list) {
    if(list == NULL) {
        return true;
    } else {
        return false;
    }
}

/* 
 * Time complexity: O(1)
 */
int insert_first(Node** list, int data) {
    if(list == NULL) {
        return ERR_NULL_POINTER;
    }
    
    Node* new_node = create_node(data);
    
    new_node->next = (*list);
    
    (*list) = new_node;
    
    return SUCCESS;
}

/* 
 * Time complexity: O(n)
 */
int insert_last(Node** list, int data) {
    if(list == NULL) {
        return ERR_NULL_POINTER;
    }
    if(is_empty((*list))) {
        return insert_first(list, data);
    }
    
    Node* new_node = create_node(data);
    
    Node* last_node = search_last(*list);
    
    last_node->next = new_node;
    
    return SUCCESS;
}

/* 
 * Time complexity: O(n)
 */
int insert(Node** list, int data, int index) {
    if(list == NULL) {
        return ERR_NULL_POINTER;
    }
    if(index == 0) {
        return insert_first(list, data);
    }
    if(is_empty(*list)) {
        return ERR_OUT_OF_BOUNDS;
    }
    
    Node* previous_node = search_iterative(*list, index - 1);
    
    if(previous_node == NULL) {
        return ERR_OUT_OF_BOUNDS;
    }
    
    Node* next_node = previous_node->next;
    Node* new_node = create_node(data);
    
    previous_node->next = new_node;
    new_node->next = next_node;
    
    return SUCCESS;
}

/*
 * Time complexity: O(1)
 */
int update_first(Node* list, int data) {
    if(list == NULL) {
        return ERR_NULL_POINTER;
    }
    
    list->data = data;
    
    return SUCCESS;
}

/*
 * Time complexity: O(n)
 */
int update_last(Node* list, int data) {
    if(list == NULL) {
        return ERR_NULL_POINTER;
    }
    
    Node* last_node = search_last(list);
    
    last_node->data = data;
    
    return SUCCESS;
}

/*
 * Time complexity: O(n)
 */
int update(Node* list, int data, int index) {
    if(list == NULL) {
        return ERR_NULL_POINTER;
    }
    
    Node* node = search_iterative(list, index);
    
    if(node == NULL) {
        return ERR_OUT_OF_BOUNDS;
    }
    
    node->data = data;
    
    return SUCCESS;
}

/*
 * Time complexity: O(1)
 */
int delete_first(Node** list) {
    if(list == NULL) {
        return ERR_NULL_POINTER;
    }
    if(is_empty(*list)) {
        return ERR_INVALID_OPERATION;
    }
    
    Node* old_head = (*list);
    
    (*list) = (*list)->next;
    
    free(old_head);
    
    return SUCCESS;
}

/*
 * Time complexity: O(n)
 */
int delete_last(Node** list) {
    if(list == NULL) {
        return ERR_NULL_POINTER;
    }
    if(is_empty(*list)) {
        return ERR_INVALID_OPERATION;
    }
    
    Node* previous_node = search_prelast(*list);
    
    if(previous_node == NULL) {
        return delete_first(list);
    }
    
    free(previous_node->next);
    
    previous_node->next = NULL;
    
    return SUCCESS;
}

/*
 * Time complexity: O(n)
 */
int delete(Node** list, int index) {
    if(list == NULL) {
        return ERR_NULL_POINTER;
    }
    if(index == 0) {
        return delete_first(list);
    }
    if(is_empty(*list)) {
        return ERR_INVALID_OPERATION;
    }
    
    Node* previous_node = search_iterative(*list, index - 1);
    
    if(previous_node == NULL) {
        return ERR_OUT_OF_BOUNDS;
    }
    
    Node* target_node = previous_node->next;
    
    if(target_node == NULL) {
        return ERR_OUT_OF_BOUNDS;
    }
    
    previous_node->next = target_node->next;
    
    free(target_node);
    
    return SUCCESS;
}

/*
 * Time complexity: O(n)
 */
int empty(Node** list) {
    if(list == NULL) {
        return ERR_NULL_POINTER;
    }
    
    while(!is_empty(*list)) {
        delete_first(list);
    }
    
    return SUCCESS;
}

/*
 * Time complexity: O(1)
 */
void print_node(Node* node) {
    if(node == NULL) {
        printf("|NULL|");
    } else {
        printf("|%d|", node->data);
    }
}

/*
 * Time complexity: O(n)
 */
void print_list(Node* list) {
    print_node(list);
    
    if(list == NULL || list->next == NULL) {
        return;
    }
    
    printf("->");
    
    print_list(list->next);
}
