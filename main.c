#include "trie.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){

    node* root = ctor();//create root

    char str[100];//define str
    while(scanf("%s", str)>0){ //get from user
            add(str, strlen(str), root);//add
    }

    if(argc == 1){//if argc == 1 which means input "prequency" print normal
        p(root);//function print normal
    }else if(argc == 2){
        if(strcmp(argv[1], "r") == 0){//else only if char "r",print in reverse
            r(root);//function print in reverse
        }
    }
    deleteTree(root);//delete function
    return 0;
}