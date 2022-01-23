#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  node {
  char          *key;
  void          *data;
  struct node   *left;
  struct node   *right;
}               node_t;

node_t  *allocnode(){
    node_t *root = malloc(sizeof(node_t));
    return root;
}
node_t  *insert(node_t *root, char *key, void *data){
    if (root == NULL) {
        root = allocnode();
        root->key = key;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    int diff = strcmp(key, root->key);
    if (diff < 0) {
        if (root->left == NULL) {
            root->left = insert(NULL, key, data);
        } else {
            insert(root->left, key, data);
        }
    } else if (diff > 0) {
        if (root->right == NULL) {
            root->right = insert(NULL, key, data);
        } else {
            insert(root->right, key, data);
        }
    }else {
        root->data = data;
    }
    return root;
}
void    print_node(node_t *node){
    if (node != NULL){
        printf("KEY:: %s DATA:: %s\n", node -> key, (char *) node -> data);    
    }
}
void    visit_tree(node_t *node, void (*fp)(node_t *root)){
    if (node != NULL){
        visit_tree(node -> left, fp);
        visit_tree(node -> right, fp);
        fp(node);
    }
}
void    destroy_tree(node_t *node, void (*fdestroy)(node_t *root)){
    if (node != NULL)
    {
        destroy_tree(node -> left, fdestroy);
        destroy_tree(node -> right, fdestroy);
        fdestroy(node);
        free(node);
    }
}
