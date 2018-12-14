//
//  node.c
//
//  Created by Ricky Wilson on 12/01/18.
//
//  CS 4280
//  Project 4
//  Dr. Janikow


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "node.h"

Node * nodeConstruct(Token * tok) 
{
	// allocates memory for both a Node's size as well as the input string
	Node * nd = malloc(sizeof(Node));
	nd->tok = malloc(sizeof(Token));
	nd->tok = tok;
	nd -> next = NULL;
	
	return nd;
}

Node * listInsert(Node * head, Token *tok) 
{
	if(head == NULL){
		
		head = nodeConstruct(tok);
	} else {
		Node * ptr = nodeConstruct(tok);
		head->next = ptr;
	}

	return head;

}

void listPrint(Node *head)
{
	Node * current = head;

    while (current != NULL) {
    	tokenPrint(current->tok);
    	current = current -> next;
    }
}

