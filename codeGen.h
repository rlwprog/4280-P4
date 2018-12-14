//
//  codeGen.h
//
//  Created by Ricky Wilson on 12/01/18.
//
//  CS 4280
//  Project 4
//  Dr. Janikow


#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "token.h"
#include "tree.h"

void genCode(TreeNode * root, FILE * outFile);