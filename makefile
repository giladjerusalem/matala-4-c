all: trie.h trie.c main.c
	gcc -Wall trie.c main.c -o frequency