//
//  node.h
//
//  Created by Ricky Wilson on 12/01/18.
//
//  CS 4280
//  Project 4
//  Dr. Janikow

#include <stdbool.h>
#include "token.h"

//structure for a node in the linked list containing the strings within the bst
typedef struct node
{
    Token *tok;
    struct node *next;

} Node;

// constructs a node in the linked list
Node * nodeConstruct(Token * tok);

//inserts a new node into the linked list
Node * listInsert(Node *head, Token *tok);

// // searches the linked list for a particular string and returns true if there, false if not
// bool listSearch(Node *head, char *str);

// prints the linked list in order from latest to oldest
void listPrint(Node *head);

