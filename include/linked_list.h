#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data);

Node* search_recursive(Node* list, int index, int count);

Node* search_iterative(Node* list, int index);

Node* search_last(Node* list);

Node* search_prelast(Node* list);

int length_recursive(Node* list, int count);

int length_iterative(Node* list);

bool is_empty(Node* list);

int insert_first(Node** list, int data);

int insert_last(Node** list, int data);

int insert(Node** list, int data, int index);

int update_first(Node* list, int data);

int update_last(Node* list, int data);

int update(Node* list, int data, int index);

int delete_first(Node** list);

int delete_last(Node** list);

int delete(Node** list, int index);

int empty(Node** list);

void print_node(Node* node);

void print_list(Node* list);

#endif
