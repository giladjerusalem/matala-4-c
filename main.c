#include "trie.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){

    node* root = ctor();

    char str[100];
    while(scanf("%s", str)>0){
            add(str, strlen(str), root);
    }

    if(argc == 1){
        p(root);
    }else if(argc == 2){
        if(strcmp(argv[1], "r") == 0){
            r(root);
        }
    }
    deleteTree(root);

    return 0;
}