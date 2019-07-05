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

void get_smallest_element(struct node *root)
{
  if(root == NULL){
    printf("empty tree\n");
  }
  while(root != NULL && root->left != NULL)
  {
      root = root->left;
  }
  printf("smallest element : %d\n",root->key);

}

void get_largest_element(struct node *root)
{
  if(root == NULL){
    printf("empty tree\n");
  }

  while(root != NULL && root->right != NULL)
  {
    root = root->right;
  }
  printf("largest element : %d\n",root->key);

}

void get_element(struct node *root,int key , struct node **cur, struct node **parent)
{
  if(root == NULL){
    printf("empty tree\n");
  }

  *parent =  root;
  *cur = root;
  while(root != NULL)
  {
    if(root->key == key){
      printf("Element present\n");
      break;
     }
   
    else if(key < root->key){
      *parent = root;
      *cur = root->left;
      root = root->left;
    }
    else if(key > root->key){
       *parent = root;
       *cur = root->right;
       root = root->right;
    }
  }
 
  if(root != NULL){
     printf("Element searched was : %d its parent : %d\n",(*cur)->key,(*parent)->key);
   
  }



}
void main()
{
  int switch_element;
  int key;
  struct node *root = NULL;
  while(1){
   printf("1. Insert element\n");
   printf("2. Display Tree\n");
   printf("3. Get Smallest Element\n");
   printf("4. Get Largest Element\n");
   printf("5. Search Element\n");
   scanf("%d",&switch_element);
  switch(switch_element){
   case 1 : printf("Enter the element to be inserted\n");
            scanf("%d",&key);
            root = insert(root,key);
            break;
   case 2 : inorder_traversal(root);
            printf("\n");
            break;
   case 3 : get_smallest_element(root);
            break;
   case 4 : get_largest_element(root);
            break;
   case 5 : printf("Enter the element to be searched\n");
            scanf("%d",&key);
            struct node *current;
            struct node *parent; 
            get_element(root,key,&current,&parent);
   default : printf("invalid option\n");
  }            
 }
}
