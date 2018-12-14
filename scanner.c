//
//  scanner.c
//
//  Created by Ricky Wilson on 12/01/18.
//
//  CS 4280
//  Project 4
//  Dr. Janikow

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"
#include "table.h"

void setUp(){
	while((ch = getc(fin)) != EOF){
		printf("%c", ch);
		fseek(fin, -1, SEEK_CUR);
		printf("Pointer position: %ld\n", ftell(fin));
		fseek(fin, 1, SEEK_CUR);
		printf("Pointer position: %ld\n", ftell(fin));
		fseek(fin, -1, SEEK_CUR);
		printf("Pointer position: %ld\n", ftell(fin));
		fseek(fin, 1, SEEK_CUR);
		printf("Pointer position: %ld\n", ftell(fin));


	}

	return;
}

int filter(state) {
		int column;
		ch = getc(fin);
	
		if (checkIfComment(ch)){
			ch = getc(fin);
			while(!checkIfComment(ch) && ch != EOF){
				checkIfNewLine(ch);
				
				ch = getc(fin);
			}

			if (ch == EOF){
				fprintf(stderr, "Error: %d\nEnd of comment not found! \n", -3);
				exit(1);
			}
			ch = getc(fin);
		}

		if (checkIfLowerCase(ch)){
			column = 1;
		} else if (checkIfUpperCase(ch)){
			column = 2;
		} else if (checkIfUnderScore(ch)){
			column = 3;
		} else if (checkIfDigit(ch)){
			column = 4;
		} else if (checkIfWhitespace(ch)){
			while(checkIfWhitespace(ch = getc(fin))){
			}
			if (state != 0){
				fseek(fin, -1, SEEK_CUR);
			}
			column = 5;
		} else if (checkIfSymbol(ch)){
			column = 0;
		} else if (checkIfEOF(ch)){
			column = 6;
		} else if (checkIfNewLine(ch)){
			if(state == 0){
				lineNum += 1;
			}
			column = 5;
		} else {	
			printf("Error: %d\nUnknown character: %c\n", -1, ch);
			exit(1);
		}

	fseek(fin, -1, SEEK_CUR);
	return column;
}

Token * scanner(){
	
	Token * tok = NULL;
	char tokn[9] = "";
	int tokenIndex = 0;
	int state = 0;
	char tmp[2];
	int column;
	
	while (state >= 0 && state < 1000){
		
		state = FATable[state][column = filter(state)];
		ch = getc(fin);
		// printf("Character(c) processed by filter: %c\n", ch);
		// printf("Character(d) processed by filter: %d\n", ch);

		if (state >= 0 && state < 1000){
			if (!checkIfWhitespace(ch) && !checkIfNewLine(ch)){	
				tmp[0] = ch;
				tokn[tokenIndex] = tmp[0];
				tokenIndex += 1;
			}
		}
	}

	if (state >= 1000){
		if(state == 1000){
			state = checkIfIdentifierIsKeyword(tokn);
		}
		tok = tokenConstruct(state, tokn, lineNum);
		// tokenPrint(tok);
	}
	if (state == -2){
		fprintf(stderr, "Error: %d\nCan't begin ID with: %c\n", state, ch);
		exit(1);
	}

	if (checkIfNewLine(ch)){
		// printf("This should be a new line: %c\n", ch);
		// printf("This should be a new line: %d\n", ch);
		lineNum += 1;
	}

	if (checkIfEOF(ch)){
		Token * tok = NULL;
		tok = tokenConstruct(1004, tokn, -1);
		// tokenPrint(tok);

	}

	return tok;

}

int checkIfIdentifierIsKeyword(char *tk){
	int k;
	for(k = 0; k < 12; k++){
		if (strcmp(tk, keywordNames[k]) == 0){
			return 1002;
		}
	}
	return 1000; 
}

int checkIfUnderScore(char ch){
	if (ch == '_'){
		return 1;
	} else {
		return 0;
	}
}

int checkIfDigit(char ch){
	if (isdigit(ch) != 0){
		return 1;
	} else {
		return 0;
	}
}

int checkIfLowerCase(char ch){
	if (ch >= 'a' && ch <= 'z'){
		return 1;
	} else {
		return 0;
	}

}

int checkIfUpperCase(char ch){
	if (ch >= 'A' && ch <= 'Z'){
		return 1;
	} else {
		return 0;
	}
}

int checkIfWhitespace(char ch){
	if (ch == ' ' || ch == '\t'){
		return 1;
	} else {
		return 0;
	}
}

int checkIfSymbol(char ch){
	int i;
	for (i = 0; i < 18; i++){
		if(ch == opsAndDelimiters[i]){
			return 1;
		} 
	} 
	return 0;
}

int checkIfEOF(char ch){
	if (ch == EOF){
		return 1;
	}
	return 0;

}
int checkIfNewLine(char ch){
	if (ch == '\n'){
		return 1;
	}
	return 0;
}


int checkIfComment(char ch){
	if (ch == '$'){
		return 1;
	}
	return 0;
}
