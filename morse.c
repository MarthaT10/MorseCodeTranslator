#include "gen8.h"
#include "morse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function that recursively free a binary tree
void free_tree(Node * node){
    if(node==NULL)
        return;

    if (node != NULL)
    {
        free(node->word);
        free_tree(node->left);
        free_tree(node->right);
        free(node);
     }
}

//function that translates morse code to english from a .txt file and called in main
void translated_printer()
{
    FILE *fp;
    fp=fopen("m.txt", "r");
    if(fp==NULL)
    {
        printf("No file.\n");
    }

    char * arr[] = {"start", "t", "e", "m", "n", "a", "i", "o", "g", "k", "d", "w", "r", "u", "s", "~", "~", "q", "z", "y", "c", "x","b", "j", "p", "~", "l", "~", "f", "v", "h"};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = NULL;
    root = insertLevelOrder(arr, root, 0, n);
    char* input = malloc(500);
    fgets(input, 500, fp);
    char str[50];

    printf("---Reading in ");
    strtok(input,"");
    printf("\n---Translating...\n");
    printf("What file to save to?");
    scanf("%s", str);
    decode_morse(root, input, str);
    printf("Saved to file! ");
    fclose(fp);
    free_tree(root);
}
