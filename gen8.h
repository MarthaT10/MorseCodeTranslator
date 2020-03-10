typedef struct node {
    char* word;
    struct node * left;
    struct node * right;
}Node;

Node* addNode(char* ptr);
Node* insertLevelOrder(char* arr[], Node* root, int i, int n);
char* find_letter(Node* n, char* letter);
void decode_morse(Node* n, char* word, char s[]);
