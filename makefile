#
# makefile
#
# Created by Ricky Wilson on 12/01/18.
# CS 4280
# Project 4
#


all: comp 

comp: 
	gcc -Wall tree.c node.c token.c main.c parser.c scanner.c testtree.c staticsemantics.c codeGen.c -o comp

clean:
	rm comp  
	rm *.asm
