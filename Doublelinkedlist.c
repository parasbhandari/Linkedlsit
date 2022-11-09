//Double linked list operations
/*
A Doubly Linked List (DLL) contains an extra pointer, typically called 
the previous pointer, together with the next pointer and data which are
there in the singly linked list.
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}K;
K *first=NULL;
int Count(K *p)
{
    int l=0;
    while(p)
    {
        l++;
        p=p->next;
    }
    return l;
}
void create(int A[],int n)
{
    int i;
    K *last,*temp;
    first=(K*)malloc(sizeof(K));
    first->prev=first->next=NULL;
    first->data=A[0];
    last=first;
    for(i=1;i<n;i++)
    {
        temp=(K*)malloc(sizeof(K));
        temp->data=A[i];
        temp->prev=last;
        temp->next=last->next;
        last->next=temp;
        last=temp;
         }
}
void reverse(K *p)
{
K *temp=NULL;
while(p!=NULL)
{
    temp=p->next;
    p->next=p->prev;
    p->prev=temp;
    p=p->prev;
    if(p!=NULL && p->next==NULL)
     first=p;
}
}
void display(K *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void insert(K *p,int index, int x)
{
K *t;
int i;
if(index<0 || index> Count(p))
return;
if(index==0)
{
    t=(K*)malloc(sizeof(K));
    t->data=x;
    t->prev=NULL;
    t->next=first;
    first->prev=t;
    first=t;
}
else{
    for(i=0;i<index-1;i++)
     p=p->next;
    t=(K*)malloc(sizeof(K));
    t->data=x;
    t->prev=p;
    t->next=p->next;
    if(p->next)
     p->next->prev=t;
    p->next=t;    
}
}
int Search(K *p, int x)
{
while(p)
{
    if(p->data==x)
    return 1;
    else
    p=p->next;
}
return 0;
}
void delete(K *p, int index)
{
    int i;
    K *q=NULL;
    if(first==NULL)
    {
        printf("\n Linked list is empty");
    }
    if(index<1 || index>Count(p))
    {
        printf("\n Please click right index");
    }
    if(index==1)
    {
        first=first->next;
        first->prev=NULL;
        free(p);
    }
    else{
        for(i=1;i<index;i++)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next)
         p->next->prev=p->prev;
        free(p);
 }
}
int main()
{
    while(1)
    {
    int key;
    printf("\n-----------------Menu drive of double linked list----------------");
    printf("\n 1. To create a double linked list");
    printf("\n 2. To insert a node in double linked list");
    printf("\n 3. To delete a node from a double linked list");
    printf("\n 4. To search a data in a double linked list");
    printf("\n 5. To reverse a double linked list");
    printf("\n 6. To display a linked list");
    printf("\n 7. To exit form program\n");
    scanf("%d",&key);
    switch(key)
    {
        case 1: 
        {
            int n,i;
            printf("\n Enter the number of element in a linked list");
            scanf("%d",&n);
            int A[n];
            printf("\n Enter the elements of linked list");
            for(i=0;i<n;i++)
            scanf("%d",&A[i]);

            create(A,n);
            break;
        }
        case 2:
        {
            int index,element;
            printf("\n Enter the index of and element");
            scanf("%d%d",&index,&element);
            insert(first,index,element);
            break;
        }
        case 3: {
             int index;
            printf("\n Enter the index of node you want to delete");
            scanf("%d", &index);
            delete(first,index);
            break;
        }
        case 4:
        {
            int x;
            printf("\n Enter the element you want to seach in double linked list\n");
            scanf("%d ",&x);
            if(Search(first,x))
            {
                printf("\n yes, element is present in double linked list");
            }
            break;
        }
        case 5:
        {
            reverse(first);
            break;
        }
        case 6:
        {
            display(first);
            break;
        }
        case 7: 
        {
          return 0;
          break;
        }
        default:
        {
            printf("\n Please choose right index\n");
            break;
        }
    }
    }
    return 0;
}
