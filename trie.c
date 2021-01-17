#include "trie.h"
#include <stdio.h>
#include <stdlib.h>

node* CheckIfExistChar(node* n, char c);
void ConnectChildToParent(node* parent, node* child);

node* ctor(){
    node* root = malloc(sizeof(node));//initial memory source
    return root;
}
node* add (char* word, int size, node* root){// will add "child" each letter

    node* current = root; //save variable to "run the tree"
    node* child = NULL;
    for(int i = 0; i< size; ++i){//run each letter

        char c = word[i];//save the i letter of the word on char c
        child = CheckIfExistChar(current, c); //return node*
        if(child == NULL){//means we DONT have child 
            child = malloc(sizeof(node));//create new memory - child
            child->letter = c;//set the right letter
            child->count = 0;

            current->children[c-97] = child;//enter to array and sort
        }

        if(i == size - 1){//if the word end
            child->count = child->count + 1;//dont create another cell
            child->endWord = TRUE;//put leg, word end here
        }

        current = child;    //every iteration set the new child
    }

    return child;
}

node* CheckIfExistChar(node* n, char c){

    if(n->children[c-97] != NULL){
        return n->children[c-97];// if there is child - return him
    }

    return NULL;//if didnt found any child
}

void deleteTree(node* root){
    
    for (int i = 0; i < 26; i++){//run each child
        if(root->children[i] != NULL){
            deleteTree(root->children[i]);//if there is child - call and delete each child in recursion
        }
    }

    free(root); //delete the leaf
}

void printN(node* root, char* word, int wordSize){
    //set memory + 1 for the new letter
    char* newWord = malloc((wordSize + 1)*sizeof(char));
    for (size_t i = 0; i < wordSize; i++)//run the size
    {
        newWord[i] = word[i];
    }
    //place the new letter in the last cell of wordSize array
    newWord[wordSize] = root->letter;

    if(root->endWord == TRUE){//if the word ended, print
        for (size_t i = 0; i < wordSize + 1; i++)
        {
            printf("%c", newWord[i]);
        }
        printf(" %ld\n", root->count);
    }

    for (int i = 0; i < 26; i++){   //run each child
        if(root->children[i] != NULL){
            //call printN and print each child in recursion
            printN(root->children[i], newWord, wordSize+1);
        }
    }

    free(newWord);

}

void p(node* root){
    char* firstWord = "";
    printN(root, firstWord, 0);
}

void printR(node* root, char* word, int wordSize){

    char* newWord = malloc((wordSize + 1)*sizeof(char));//set new memory
    //run on the size of word and "copy" to newWord
    for (size_t i = 0; i < wordSize; i++)
    {
        newWord[i] = word[i];
    }
    newWord[wordSize] = root->letter;
    for (int i = 25; i >= 0; i--){   //run each child
        if(root->children[i] != NULL){ //if there is a child
            //call printR and print each child in recursion (reverse)
            printR(root->children[i], newWord, wordSize+1);
        }
    }

    if(root->endWord == TRUE){
        for (size_t i = 0; i < wordSize + 1; i++)
        {
            printf("%c", newWord[i]);
        }
        printf(" %ld\n", root->count);
    }

    free(newWord);

}

void r(node* root){
    char* firstWord = "";
    printR(root, firstWord, 0);  
}