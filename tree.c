//
//  tree.c
//
//  Created by Ricky Wilson on 12/01/18.
//
//  CS 4280
//  Project 4
//  Dr. Janikow

#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// A utility function to create a new BST node
TreeNode *newTreenode(char *label)
{
    TreeNode *temp;
    temp = malloc(sizeof(TreeNode));
    temp->label = malloc(sizeof(label) + 1);
    temp->label = label;
    temp->head = malloc(sizeof(Node));
    temp->head = NULL;
    temp->child1 = NULL;
    temp->child2 = NULL;
    temp->child3 = NULL;
    temp->child4 = NULL;
    return temp;
}

// // A utility function to do inorder traversal of BST
// void traversePreorder(int lvl, TreeNode *root)
// {
//     int i;

//     if (root != NULL)
//     {
//         for (i = 0; i < lvl; i++){
//             printf("  ");

//         }  
//         printf("%s ", root->label);
//         // for (i = 0; i < lvl; i++){
//         //     printf("\t");
//         // }           
//         listPrint(root->head);
//         printf("\n");

//         traversePreorder(lvl + 1, root->child1);
//         traversePreorder(lvl + 1, root->child2);
//         traversePreorder(lvl + 1, root->child3);
//         traversePreorder(lvl + 1, root->child4);

//     }

// }
