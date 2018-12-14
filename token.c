//
//  token.c
//
//  Created by Ricky Wilson on 12/01/18.
//
//  CS 4280
//  Project 4
//  Dr. Janikow

#include <stdio.h>
#include <stdlib.h>
#include "token.h"

Token * tokenConstruct(int tokenID, char *tokenName, int line)
{
	// allocates memory for both a Token's size as well as the input string
	Token * tok = malloc(sizeof(Token));
	tok -> tokenID = tokenID;
	tok -> tokenName = malloc(strlen(tokenName) + 1);
	tok -> line = line;
	strcpy(tok -> tokenName, tokenName);
	
	return tok;
}

void tokenPrint(Token *tok)
{
	printf("%s: ", tokenNames[tok ->tokenID%1000]);
	if(tok -> tokenID == 1004){
		printf("EOF \n");

	} else {
	printf("%s ", tok -> tokenName);
	}
}

// void tokenPrint(Token *tok)
// {
// 	printf("\nToken Type: %s\n", tokenNames[tok ->tokenID%1000]);
// 	if(tok -> tokenID == 1004){
// 		printf("Token Name: EOF\n");

// 	} else {
// 	printf("Token Name: %s\n", tok -> tokenName);
// 	}
// 	printf("Line Number: %d\n\n", tok -> line);
// }

