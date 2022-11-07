//single Linked list operations
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}K;
K *first=NULL;
void create(int A[], int n)
{
    int i;
    K *t,*last;
    first=(K*)malloc(sizeof(K));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(K*)malloc(sizeof(K));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
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
void reverse(K *p)
{
    K *q,*r;
    q=r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
void insert(K *p,int index,int x)
{
    int i=0;
   K *temp;
   if(p==NULL)
   {
    temp=(K*)malloc(sizeof(K));
    temp->data=x;
    temp->next=first;
    first=temp;
   }
   else{
        for(i=0;i<index-1 && p;i++)
         p=p->next;
        if(p)
        {
          temp=(K*)malloc(sizeof(K));
          temp->data=x;
          temp->next=p->next;
          p->next=temp;
        }
   }
}
int Count(K *p)
{
    int x=0;
    while(p!=NULL)
    {
        x++;
        p=p->next;
    }
    return x;
}
void delete(K *p,int index)
{
K *q=NULL;
int i;
if(index<1 && index>Count(p))
 printf("\n Invalid index");
if(index==1)
{
    q=first;
    first=first->next;
    free(q);
}
else{
    for(i=0;i<index-1;i++)
    {
        q=p;
        p=p->next;
    }
    q->next=p->next;
    free(p);
}
}
int main()
{
    int key;
    while(1)
    {
    printf("\n --------------Menu drive for linked list-----------------");
    printf("\n 1. Type 1 to create a linked list");
    printf("\n 2. Tyep 2 to insert a linked node in a linked list");
    printf("\n 3. Type 3 to delete a node from linked list");
    printf("\n 4. Type 4 to reverse a linked list");
    printf("\n 5. Type 5 to display a linked list");
    printf("\n 6. Type 6 to exit");
    scanf("%d",&key);
    switch(key)
    {
        case 1: {
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
        case 2: {
            int index,element;
            printf("\n Enter the index of and element");
            scanf("%d%d",&index,&element);
            insert(first,index,element);
            break;
        }
        case 3:
        { 
            int index;
            printf("\n Enter the index of node you want to delete");
            scanf("%d", &index);
            delete(first,index);
            break;
        }
        case 4: {
                reverse(first);
                break;
        }

        case 5: {
            display(first);
            break;
        }
        case 6: {
            return 0;
        }
        default: {
            printf("\n please choose right number");
            break;
        }
        }

    }
    return 0;
}
