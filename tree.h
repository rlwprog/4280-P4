//
//  tree.h
//
//  Created by Ricky Wilson on 12/01/18.
//
//  CS 4280
//  Project 4
//  Dr. Janikow

#ifndef FILE_TREEH_SEEN
#define FILE_TREEH_SEEN

#include <stdio.h>
#include "node.h"

// struct for a tree node within the bst
typedef struct treenode
{
    char *label;
    struct node * head;
    struct treenode *child1;
    struct treenode *child2;
    struct treenode *child3;
    struct treenode *child4;

}TreeNode;

// function creates a new treenode for the bst
TreeNode *newTreenode(char *label);

// traverses the file in preorder, at each treenode traverses each list of unique strings
// void traversePreorder(int lvl, TreeNode *root);

#endif