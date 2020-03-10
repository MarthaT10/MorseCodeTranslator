#include "gen8.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//struct for the morse code binary tree
Node* addNode(char* ptr) {
    Node* temp = malloc(sizeof(Node));
    temp->word = ptr;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

//function that forms the binary tree that relates the Morse code with English alphabet and returns the root.
Node* insertLevelOrder(char* arr[], Node* root, int i, int n) {
    /*	Base	case	for	recursion*/
    if (i < n) {
        Node * temp = addNode(arr[i]);
        root = temp;
        /*insert	left	child*/
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
        /*insert	right	child*/
        root-> right = insertLevelOrder(arr, root-> right, 2 * i + 2, n);
    }
    return root;
}

//Function that returns that respective letter in English after taking the root and the Morse code as parameter
char * find_letter(Node * n, char * letter)
{
    int num = strlen(letter);
    int i;

    for (i = 0; i < num; i++) {
        if (letter[i] == '-') /*dash*/ {
            n = n-> left;
        } else if(letter[i] == '.'){
            n = n-> right; /*dot*/
        }
        else
        {
            break;
        }
    }

    return n->word;
}


//Function that returns the English word together and takes the root of the binary tree, Morse code as a string literal and
//the .txt name of where the translated English will be saved.
void decode_morse(Node * n, char * word, char s[]) {
    FILE *fp;
    fp=fopen(s,"w");

    if(fp==NULL)
    {
        printf("No file.\n");
    }

    if (strcmp(word, "exit") == 0) {
        return;
    }
    char * token = strtok(word, " \n");
    while (token != NULL) {
        fprintf(fp, "%s", find_letter(n, token));
        token = strtok(NULL, " \n");
    }
    printf("\n");
    fclose(fp);
}
