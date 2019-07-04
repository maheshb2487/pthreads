#include<stdio.h>
#include<stdlib.h>

struct node{
 int key;
 struct node *left;
 struct node *right;
};

struct node * newnode(int key)
{
 struct node *temp = (struct node *)malloc(sizeof(struct node));
 temp->key = key;
 temp->left = NULL;
 temp->right = NULL;
 return temp;
}

void inorder_traversal(struct node *root)
{
 if(root != NULL){
  inorder_traversal(root->left);
  printf("%d	",root->key);
  inorder_traversal(root->right);
 }
}

struct node * insert(struct node *root, int key)
{
 if(root == NULL) return newnode(key);

 if(key < root->key)
  root->left = insert(root->left,key);
 else if(key > root->key)
  root->right = insert(root->right,key);

 return root;
}
void main()
{
  int switch_element;
  int key;
  struct node *root = NULL;
  while(1){
   printf("1. Insert element\n");
   printf("2. Display Tree\n");
   scanf("%d",&switch_element);
  switch(switch_element){
   case 1 : printf("Enter the element to be inserted\n");
            scanf("%d",&key);
            root = insert(root,key);
            break;
   case 2 : inorder_traversal(root);
            break;
   default : printf("invalid option\n");
  }            
 }
}
