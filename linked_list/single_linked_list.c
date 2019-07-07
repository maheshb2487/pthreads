#include<stdio.h>
#include<stdlib.h>

struct node{
 int element;
 struct node *next;
};

struct node * new_node(int element)
{
 struct node *temp = (struct node *)malloc(sizeof(struct node));
 temp->element = element;
 temp->next = NULL;
 return temp;
}

struct node * insert_node(struct node *head, int element)
{
  if(head == NULL) return new_node(element);

  struct node *cur = head;
  while(cur->next != NULL){
    cur = cur->next;
  }
  
  cur->next = new_node(element);
  return head;
}

void display(struct node *head)
{
  if(head == NULL) {
   printf("Empty linked list\n");
   return ;
  }

  while(head != NULL){
   printf("%d  ",head->element);
   head = head->next;
 }
 printf("\n");
 return;
}

struct node * search(struct node *head,int element,int *position)
{
 
 if(head == NULL){
   printf("Empty list\n");
   return NULL;
 }

 *position = 0;

 while(head != NULL){
   if(head->element == element){
     printf("element present at position : %d\n",*position);
     return head;
   }else{
     head = head->next;
     (*position)++;
     printf("Moving to next element\n");
   }//else
 }//while

 if(head == NULL){
  printf("element not found in list\n");
 }
 return NULL;
}

void cleanup(struct node *head)
{
  if(head == NULL){
   printf("Empty list\n");
   return; 
  }

  struct node *temp = NULL;

  while(head != NULL){
    temp = head->next;

    free(head);

    head = temp;

  }

}
struct node * delete_node(struct node *head, int element)
{
  if(head == NULL){
    printf("list empty\n");
    return;
  }
  
  struct node *cur = NULL;
  struct node *prev = NULL;
  if(head->element == element){
    cur = head->next;

    free(head);
    head = NULL;

    head = cur;
    return cur;
   
  }

  prev = NULL;
  cur = head;
  while(cur != NULL)
  {
    if(cur->element == element)
    {   
      prev->next = cur->next;
      free(cur);
      cur = NULL;
      printf("Element found and deleted\n");
      return head;
    }else{
      prev = cur;
      cur = cur->next;
    }
  }
  return head;
}

void main()
{
  int choice = 0;
  struct node *head = NULL;
  int pos = 0;
  int element = 0;
  while(1){
  printf("1. Insert\n");
  printf("2. Display\n");
  printf("3. Search\n");
  printf("4. exit\n");
  printf("5. Delete\n");
  scanf("%d",&choice);
  switch(choice){
    case 1: printf("Enter Element\n");
            scanf("%d",&element);
            head = insert_node(head,element);
            break;
    case 2: display(head);
            break;
    case 3: printf("Enter search element\n");
            scanf("%d",&element);
            search(head,element,&pos); 
            break;
    case 4: cleanup(head);
            exit(0);
    case 5: printf("Enter the element to be deleted\n");
            scanf("%d",&element);
            head = delete_node(head,element);
            break; 
  }
}
}
