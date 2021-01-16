#define NUM_LETTERS ((int)26)

typedef enum { FALSE=0, TRUE=1} boolean;

typedef struct node{
    char letter;
    long unsigned int count;
    struct node * children [NUM_LETTERS];
    boolean endWord;
} node;

node* ctor();
node* add (char* letter, int size, node* root);
void deleteTree(node* root);
void p(node* root);
void r(node* root);