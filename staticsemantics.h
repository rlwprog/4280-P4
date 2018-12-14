//
//  staticsemantics.h
//
//  Created by Ricky Wilson on 12/01/18.
//
//  CS 4280
//  Project 4
//  Dr. Janikow


#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "tree.h"


// structure defining stack
typedef struct stack {

	char *label;
	struct stack *next;
	struct stack *last;

} Stack;

Stack * createStackNode(char *label);

void push(Stack * stack, char *label);

void pop(Stack* stack);

void stackPrint(Stack *stk);

Stack * staticsem(int lvl, TreeNode *root, Stack *top);

int checkStack(Stack * top, char *label);


// typedef struct stack {

// 	Token *tok;
// 	struct stack *next;
// 	struct stack *last;

// } Stack;

// struct stack * createStack(Token * tok);

// void push(Stack * stack, Token * tok);

// void pop(Stack* stack);

