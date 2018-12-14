//
//  scanner.h
//
//  Created by Ricky Wilson on 12/01/18.
//
//  CS 4280
//  Project 4
//  Dr. Janikow


#include <stdio.h>
#include <stdlib.h>
#include "token.h"

char ch;
int length;

static int lineNum = 1;


FILE * fin;

char buffer[100];

void setUp();

int filter(int state);

Token * scanner();

int checkIfDigit(char ch);

int checkIfUpperCase(char ch);

int checkIfLowerCase(char ch);

int checkIfSymbol(char ch);

int checkIfWhitespace(char ch);

int checkIfUnderScore(char ch);

int checkIfIdentifierIsKeyword(char *tk);

int checkIfNewLine(char ch);

int checkIfEOF(char ch);

int checkIfComment(char ch);