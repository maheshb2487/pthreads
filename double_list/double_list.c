#include<stdio.h>
#include<stdlib.h>

struct node{
int element;
struct node *prev;
struct node *next;
};

struct node * new_node(int element)
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->element = element;
  temp->prev = NULL;
  temp->next = NULL;
  return temp;
}

struct node * insert(struct node *head, int element)
{
  if(head == NULL){
    return new_node(element);
  }
  struct node *new_head = head;
  while(head->next != NULL){
    head = head->next;
  }
  head->next = new_node(element);
  head->next->prev = head;
  return new_head;
}

void display_forward(struct node *head)
{
  if(head == NULL){
    printf("list empty\n");
    return;
  }
  
  while(head != NULL){
   printf("%d ",head->element);
   head = head->next;
  }
}

void display_backward(struct node *tail)
{
  if(tail == NULL){
    printf("list empty\n");
    return;
  }
  
  while(tail != NULL){
    printf("%d ",tail->element);
    tail = tail->prev;
  }
}

struct node * Get_tail_node(struct node *head)
{
  if(head == NULL){
      printf("list empty\n");
      return;
  }
 
  struct node *tail = NULL;
  while(head != NULL)
  {
      tail = head;
      head = head->next;
  }
  return tail;
}

void main()
{
  int choice;
  int element;
  struct node *head = NULL;
  while(1)
  {
    printf("1. Insert Element\n");
    printf("2. Display Forward\n");
    printf("3. Display Backward\n");
    scanf("%d",&choice);
    switch(choice){
      case 1 : printf("Enter the element\n");
               scanf("%d",&element);
               head = insert(head,element);
               break;
      case 2: display_forward(head);
              printf("\n");
              break;
      case 3: {struct node *tail = NULL;
              tail = Get_tail_node(head);
              display_backward(tail);
              printf("\n");
              break;
              }
    }


  }



}
