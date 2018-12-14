//
//  token.h
//
//  Created by Ricky Wilson on 12/01/18.
//
//  CS 4280
//  Project 4
//  Dr. Janikow

#ifndef FILE_TOKENH_SEEN
#define FILE_TOKENH_SEEN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum tokenID {IDENT_tk, NUM_tk, KW_tk, OP_tk, EOF_tk};
static const char *tokenNames[] = {"Identifier", "Number", "Keyword", "Operator", "EOF"};
static const char *keywordNames[] = {"start", "stop", "loop", "void", "var", "return", "scan", "out", "program", "if", "then", "let"};
static char opsAndDelimiters[] = {'=', '<', '>', ':', '+', '-', '*', '/', '%', '.', '(', ')', ',', '{', '}', ';', '[', ']'};

typedef struct token
{
    int tokenID;
    char *tokenName;
    int line;

} Token;

Token * tokenConstruct(int tokenID, char *tokenName, int line);

void tokenPrint(Token *tok);


#endif