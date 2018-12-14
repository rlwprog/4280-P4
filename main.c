//
//  main.c
//
//  Created by Ricky Wilson on 12/01/18.
//
//  CS 4280
//  Project 4
//  Dr. Janikow

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "parser.h"
#include "staticsemantics.h"
#include "codeGen.h"


int main(int argc, char *argv[]){
	
	FILE * inFile = stdin;
	FILE *outFile;

	char *fout;
	char *fin;

	TreeNode * root;
	Stack * stack;

	// make sure there are only zero or one arguments 
	if (argc > 2) {
		errno = 8;
		perror("Error: Too many arguments, run the program P1 with either zero or 1 argument");
		return 1;
	}
	
	// setup input and output files
	if (argc == 2){
		
		// concatenates the strings of the first passed argument and extension ".sp18"
		fin = malloc(strlen(argv[1]) + strlen(".fs182") + 1);
		strcpy(fin, argv[1]);
		strcat(fin, ".fs182");
		inFile = fopen(fin, "r");

		fout = malloc(strlen(argv[1]) + strlen(".asm") + 1);
		strcpy(fout, argv[1]);
		strcat(fout, ".asm");

	} else {

		fout = malloc(strlen("out.asm") + 1);
		strcpy(fout, "out.asm");

	}


	// create parse tree
	root = parser(inFile);

	printf("Printing tree:\n");
	printTree(0, root);

	// a parse tree was made
	if (root != NULL) {
		printf("Parser built parse tree!\n");
		outFile = fopen(fout, "w");
		stack = staticsem(0, root, NULL);
	} else {
		printf("Parser failed to build parse tree!\n");
		exit(1);
	}

	// a global stack was made
	if(stack == NULL){
		printf("Test file failed!\n");
	} else {
		printf("Test file passed!\n");
	}

	printf("\nGlobal variable stack: \n");
	stackPrint(stack);

	genCode(root, outFile);

	// close the input file
	fclose(inFile);
	fclose(outFile);

	
	return 0;
}