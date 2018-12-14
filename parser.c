//
//  parser.c
//
//  Created by Ricky Wilson on 12/01/18.
//
//  CS 4280
//  Project 4
//  Dr. Janikow

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

static Token * tk;

// driver to test the scanner 
TreeNode * parser(FILE *fileIn) {
	
	fin = fileIn;

	TreeNode * root;

	tk = scanner();

	root = program();
	if (tk->tokenID == 1004){

	} else {

		printf("Error: %d Program didn't end correctly with EOF\n", -4);
		exit(0);
		
	}
	return root;
}

TreeNode * program(){

	TreeNode * n = newTreenode("program");

	if(strcmp(tk->tokenName, "void") == 0){

		tk = scanner();

		n->child1 = vars();
		n->child2 = block();	
		return n;	
	} else {
		printf("Error: Unsupported program, occurred in program()\n");
		exit(0);
	}
}

TreeNode * block(){
	TreeNode * n = newTreenode("block");
	if(strcmp(tk->tokenName, "start") == 0){

		tk = scanner();

		n->child1 = vars();
		n->child2 = stats();

		if(strcmp(tk->tokenName,"stop") == 0){
			tk = scanner();
			return n;
		} else {
			printf("Error: Unsupported program, occurred in block() after start\n");
			exit(0);
		}
	} else {
		printf("Error: Unsupported program, occurred in block() before start.\n");
		exit(0);

	}
	return NULL;
}

TreeNode * vars(){
	TreeNode * n = newTreenode("vars");
	if(strcmp(tk->tokenName,"var") == 0){
		tk = scanner();
	
		if(tk->tokenID == 1000){
			n->head = listInsert(n->head, tk);

			tk = scanner();

			if(strcmp(tk->tokenName, ":") == 0){
				tk = scanner();

				if(tk->tokenID == 1001){
					n->head = listInsert(n->head, tk);

					tk = scanner();
					n->child1 = vars();
					return n;
				} else {
					printf("Error: Unsupported program, occurred in vars() after ':'\n");
					exit(0);
				}
			} else {
				printf("Error: Unsupported program, occurred in vars() after Identifier\n");
				exit(0);
			}
		} else {
			printf("Error: Unsupported program, occurred in vars() after Keyword\n");
			exit(0);
		}
	} 
	return n;
}

TreeNode * expr(){
	TreeNode * n = newTreenode("expr");
	n->child1 = A();
	if((strcmp(tk->tokenName, "/") == 0) || (strcmp(tk->tokenName, "*") == 0)){
		n->head = listInsert(n->head, tk);
		tk = scanner();
		n->child1 = expr();
	} 
	return n;
}

TreeNode * A(){
	TreeNode * n = newTreenode("A");
	n->child1 = M();
	if((strcmp(tk->tokenName, "+") == 0) || (strcmp(tk->tokenName, "-") == 0)){
		n->head = listInsert(n->head, tk);
		tk = scanner();

		n->child2 = A();
		return n;
	} 
	return n;
}

TreeNode * M(){
	TreeNode * n = newTreenode("M");
	if(strcmp(tk->tokenName,"-") == 0){
		n->head = listInsert(n->head, tk);
		tk = scanner();

		n->child1 = M();
	} else {
		n->child1 = R();
	} 
	return n;
}

TreeNode * R(){
	TreeNode * n = newTreenode("R");
	if(strcmp(tk->tokenName,"(") == 0){
		tk = scanner();
		n->child1 = expr();

		if(strcmp(tk->tokenName,")") == 0){
			tk = scanner();

			return n;
		} else {
			printf("Error: Unsupported program, occurred in R() after '('\n");	
			exit(0);
		}
	} else if (tk->tokenID == 1000){
		n->head = listInsert(n->head, tk);
		tk = scanner();
		return n;
	} else if (tk->tokenID == 1001){
		n->head = listInsert(n->head, tk);
		tk = scanner();
		return n;
	} else {		
		fprintf(stderr, "Parsing error: Unsupported program, occurred in R() after ')'\n");
		exit(0);
	}
	return n;
}

TreeNode * stats(){
	TreeNode * n = newTreenode("stats");
	n->child1 = stat();
	n->child2 = mStat();
	return n;
}

TreeNode * mStat(){
	TreeNode * n = newTreenode("mStat");
	if(strcmp(tk->tokenName, "scan") == 0 || strcmp(tk->tokenName, "out") == 0 || strcmp(tk->tokenName, "start") == 0 || strcmp(tk->tokenName, "if") == 0 || strcmp(tk->tokenName, "loop") == 0 || strcmp(tk->tokenName, "let") == 0){
		n->child1 = stat();
		n->child2 = mStat();
		return n;
	} else {
		return NULL;
	}
}

TreeNode * stat(){
	TreeNode * n = newTreenode("stat");
	if(strcmp(tk->tokenName, "scan") == 0){
		n->child1 = in();
		return n;
	} else if(strcmp(tk->tokenName, "out") == 0){
		n->child1 = out();
		return n;
	} else if(strcmp(tk->tokenName, "start") == 0){
		n->child1 = block();
		return n;
	} else if(strcmp(tk->tokenName, "if") == 0){
		n->child1 = If();
		return n;
	} else if(strcmp(tk->tokenName, "loop") == 0){
		n->child1 = loop();
		return n;
	} else if (strcmp(tk->tokenName, "let") == 0){
		n->child1 = assign();
		return n;
	} else {
		printf("Error: Unsupported program, occurred in stat()\n");
		exit(0);
		return NULL;
	}
}

TreeNode * in(){
	TreeNode * n = newTreenode("in");
	tk = scanner();
	if(tk->tokenID == 1000){
		n->head = listInsert(n->head, tk);

		tk = scanner();
		if(strcmp(tk->tokenName, ".") == 0){
			tk = scanner();
			return n;
		}
	} else {
		printf("Error: Unsupported program, occurred in in() after 'scan'\n");
		exit(0);
	}
	return NULL;
}

TreeNode * out(){
	TreeNode * n = newTreenode("out");
	tk = scanner();
	if(strcmp(tk->tokenName, "[") == 0){
		tk = scanner();

		n->child1 = expr();

		if(strcmp(tk->tokenName, "]") == 0){
			tk = scanner();

			if(strcmp(tk->tokenName, ".") == 0){
				tk = scanner();
				return n;
			} else {
				printf("Error: Unsupported program, occurred in out() after ']'\n");
				exit(0);
			}
		} else {
			printf("Error: Unsupported program, occurred in out() after '['\n");
			exit(0);
		}
	} else {
		printf("Error: Unsupported program, ocurred in out() before '['\n");
		exit(0);
	}
	return NULL;
}

TreeNode * If(){
	TreeNode * n = newTreenode("if");
	tk = scanner();
	if(strcmp(tk->tokenName, "(") == 0){
		tk = scanner();
		n->child1 = expr();
		n->child2 = RO();
		n->child3 = expr();

		if(strcmp(tk->tokenName, ")") == 0){
			tk = scanner();
			n->child4 = stat();
			return n;
		} else {
			printf("Error: Unsupported program, ocurred in If() after '('\n");
			exit(0);
		}
	} else {
		printf("Error: Unsupported program, ocurred in If() before '('\n");
		exit(0);
	}
	return NULL;
}

TreeNode * loop(){
	TreeNode * n = newTreenode("loop");
	tk = scanner();
	if(strcmp(tk->tokenName, "(") == 0){
		tk = scanner();

		n->child1 = expr();
		n->child2 = RO();
		n->child3 = expr();

		if(strcmp(tk->tokenName, ")") == 0){
			tk = scanner();

			n->child4 = stat();
			return n;
		} else {
			printf("Error: Unsupported program, ocurred in loop() after '('\n");
			exit(0);
		}
	} else {
		printf("Error: Unsupported program, ocurred in loop() before '('\n");
		exit(0);
	}
	return NULL;
}

TreeNode * assign(){
	TreeNode * n = newTreenode("assign");
	tk = scanner();
	if(tk->tokenID == 1000){
		n->head = listInsert(n->head, tk);
		tk = scanner();

		if(strcmp(tk->tokenName, "=") == 0){
			n->head = listInsert(n->head, tk);
			tk = scanner();
			n->child1 = expr();

			if(strcmp(tk->tokenName, ".") == 0){
				tk = scanner();
				return n;
			} else {
				printf("Error: Unsupported program, ocurred in assign() before '.'\n");
				exit(0);
			}
		} else {
			printf("Error: Unsupported program, occurred in assign() after 'Identifier'\n");
			exit(0);
		}
	} else {
		printf("Error: Unsupported program, occurred in assign() before 'Identifier'\n");
		exit(0);
	}
	return NULL;
}

TreeNode * RO(){
	TreeNode * n = newTreenode("RO");
	if(strcmp(tk->tokenName, "<") == 0){
		n->head = listInsert(n->head, tk);
		
		tk = scanner();

		if(strcmp(tk->tokenName, "=") == 0){
			n->head = listInsert(n->head, tk);

			tk = scanner();
			return n;
		} else {
			return n;
		}
	} else if (strcmp(tk->tokenName, ">") == 0){
		n->head = listInsert(n->head, tk);

		tk = scanner();

		if(strcmp(tk->tokenName, "=") == 0){
			n->head = listInsert(n->head, tk);

			tk = scanner();
			return n;
		} else {
			return n;
		}
	} else if(strcmp(tk->tokenName, "=") == 0){
		n->head = listInsert(n->head, tk);

		tk = scanner();

		if(strcmp(tk->tokenName, "=") == 0){
			n->head = listInsert(n->head, tk);

			tk = scanner();
			return n;
		} else {
			return n;
		}
	} else {
		printf("Error: Unsupported program, occurred in RO()\n");
		exit(0);
	}
	return NULL;
}

















