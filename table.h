//
//  table.h
//
//  Created by Ricky Wilson on 12/01/18.
//
//  CS 4280
//  Project 4
//  Dr. Janikow

#include <stdio.h>


// Finite Automota Table for lookups from Scanenr
int FATable[4][7] = {
	{	3, 	  1,   -2,   -2, 	2, 	  0, 1004},
	{1000, 	  1, 	1,    1, 1000, 1000, 1000},
	{1001, 1001, 1001, 1001, 	2, 1001, 1001},
	{1003, 1003, 1003, 1003, 1003, 1003, 1003}
};