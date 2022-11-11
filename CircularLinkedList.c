//Circular linked list
/*
The circular linked list is a linked list where all nodes are connected 
to form a circle. In a circular linked list, the first node and the last node
are connected to each other which forms a circle. There is no NULL at the 
end.
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}K;
K *Head=NULL;
void Create(int A[],int n)
{
    int i;
    K *last,*t;
    Head=(K*)malloc(sizeof(K));
    Head->data=A[0];
    Head->next=Head;
    last=Head;
    for(i=1;i<n;i++)
    {
        t=(K*)malloc(sizeof(K));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
void Display(K *p)
{
  printf("%d ",p->data);
  p=p->next;
  while(p!=Head)
  {
    printf("%d ",p->data);
    p=p->next;
  }
}
void insertAtfirst(K *p,int x)
{
    K *temp;
    temp=(K*)malloc(sizeof(K));
    if(Head==NULL)
    {
    temp->data=x;
    temp->next=temp;
    Head=temp;
    }
    else{
        do{
            p=p->next;
        }while(p->next!=Head);
        temp->data=x;
        temp->next=Head;
        p->next=temp;
        Head=temp;
    }
}
void insertAtEnd(K *p, int x)
{
    K *temp;
    temp=(K*)malloc(sizeof(K));
    temp->data=x;
    do
    {
     p=p->next; 
    } while (p->next!=Head);
    temp->next=p->next;
    p->next=temp;
    
}
void Insert(K *p, int index, int x)
{
    K *temp;
    int i;
    if(index==0)
    {
        temp=(K*)malloc(sizeof(K));
        temp->data=x;
        if(Head==NULL)
        {
        Head=temp;
        Head->next=Head;
        }
        else{
            p=p->next;
            while(p->next!=Head)
            {
                p=p->next;
            }
            temp->next=Head;
            Head=temp;
            p->next=Head;
        }
    }
    else{
      temp=(K*)malloc(sizeof(K));
      for(i=0;i<index-1;i++)
      {
        p=p->next;
      }
      temp->data=x;
      temp->next=p->next;
      p->next=temp;
    }
}
void Delete(K *p, int index)
{
    K *temp;
    temp=NULL;
    int i;
    if(index==1)
    {
     while(p->next!=Head)
     {
        p=p->next;
     }
     if(p==Head)
     {
      free(Head);
      Head=NULL;
     }
     else{
        temp=Head;
        Head=Head->next;
        p->next=Head;
        free(temp);
     }
    }
    else
    {
      for(i=0;i<index-1;i++)
      {
        temp=p;
        p=p->next;
      }
      temp->next=p->next;
      free(p);
    }
}
void addToEmpty(K *p, int x)
{
p=(K*)malloc(sizeof(K));
p->data=x;
Head=p;
Head->next=Head;
}
int main()
{
  int key;
  while(1)
  {
  printf("\n ------------------Menu Drive of circular linked list----------------");
  printf("\n 1. To create a circular linked list");
  printf("\n 2. To insert a node in a circular linked");
  printf("\n 3. To delete a node in a circular linked list");
  printf("\n 4. To display a circular linked list");
  printf("\n 5. To exit ");
  printf("\n Choose a number\n");
  scanf("%d",&key);
  switch(key)
  {
    case 1: 
    {
        int i,n;
        printf("\n Enter the number of element in a circular linked list\n");
        scanf("%d",&n);
        int p[n];
        printf("\n Enter the element of circular linked list\n");
        for(i=0;i<n;i++)
        scanf("%d",&p[i]);
        Create(p,n);
        break;
    }
    case 2:
    {
        int n,index;
        printf("\n Enter the element and index you want to insert\n");
        scanf("%d%d",&n,&index);
        Insert(Head,index,n);
        break;
    }
    case 3:
    {
        int index;
        printf("\n Enter the index you want to delete");
        scanf("%d",&index);
        Delete(Head,index);
        break;
    }
    case 4:
    {
        Display(Head);
        break;
    }
    case 5:
    {
        return 0;
        break;
    }
    default:
    {
        printf("\n Choose the right index");
        break;
    }
  }
}
  return 0;
}
