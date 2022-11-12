//Doubly circular linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}K;
K *first=NULL;
void Create(int A[], int n)
{
    K *last,*temp;
    int i;
    first=(K*)malloc(sizeof(K));
    first->data=A[0];
    first->prev=first->next=first;
    last=first;
    for(i=1;i<n;i++)
    {
        temp=(K*)malloc(sizeof(K));
        temp->data=A[i];
        temp->prev=last;
        temp->next=first;
        last->next=temp;
        first->prev=temp;
        last=temp;
    }     
    
}
void Display(K *p)
{
    while(p->next!=first)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("%d ",p->data);
}
void insertAtFirst(K *p, int x)
{
K *temp=NULL;
if(first==NULL)
{
temp=(K*)malloc(sizeof(K));
temp->data=x;
temp->prev=temp->next=temp;
first=temp;
}
else
{
    temp=(K*)malloc(sizeof(K));
    temp->data=x;
    temp->next=first;
    temp->prev=first->prev;
    first->prev->next=temp;
    first->prev=temp;
    first=temp;
}
}
void insertAtLast(K *p ,int x)
{
K *temp=NULL;
if(first==NULL)
{
temp=(K*)malloc(sizeof(K));
temp->data=x;
temp->prev=temp->next=temp;
first=temp;
}
else
{
    temp=(K*)malloc(sizeof(K));
    temp->data=x;
    temp->next=first;
    temp->prev=first->prev;
    first->prev->next=temp;
    first->prev=temp;
}
}
void DeleteFirst(K *p)
{
    K *q;
    if(first->prev==first && first->next==first)
    {
        free(p);
        first=NULL;
    }
    else
    {
        q=p;
        p=p->next;
        p->prev=first->prev;
        first->prev->next=p;
        first=p;
        free(q);
    }
}

void DeleteLast(K *p)
{
    K *q;
    if(first->prev==first && first->next==first)
    {
        free(p);
        first=NULL;
    }
    else{
        while(p->next!=first)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        first->prev=p->prev;
        free(p);
       }
}
int Count(K *p)
{
int l=1;
while(p->next!=first)
{
    l++;
    p=p->next;
}
return l;
}
void Reverse(K *p)
{
int n=Count(first);
int i;
int A[n-1];
for(i=0;i<n;i++)
{
    A[i]=p->data;
    p=p->next;
}
p=first;
for(i=n-1;i>=0;i--)
{
    p->data=A[i];
    p=p->next;
}
first=p;
}
void Insert(K *p, int index, int x)
{
    K *temp=(K*)malloc(sizeof(K));
    temp->data=x;
    if(index<0 || index>Count(p))
     return;
    if(index==0)
    {
        if(first==NULL)
        {
            temp->prev=temp->next=temp;
            first=temp;
        }
        else{
            temp->next=first;
            temp->prev=first->prev;
            first->prev->next=temp;
            first->prev=temp;
            first=temp;
        }
    }
    else{
        int i;
        for(i=0;i<index-1;i++)
        {
            p=p->next;
        }
        temp->prev=p;
        temp->next=p->next;
        p->next->prev=temp;
        p->next=temp;

    }
}
void Delete(K *p, int index)
{
    K *q;
    if(index<0 || index>Count(p))
    return;
    if(index==1)
    {
        if(first->prev==first && first->next==first)
        {
            free(p);
            first=NULL;
        }
        else{
        q=p;
       p=p->next;
       p->prev=first->prev;
       first->prev->next=p;
       first=p;
       free(q);
    }
    }
    else{
        int i;
        for(i=1;i<index;i++)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        p->next->prev=p->prev;
        free(p);
        
    }
}
int main()
{
    while(1)
    {
    int key;
    printf("\n-----------------Menu drive of circular doubly linked list----------------");
    printf("\n 1. To create a circular doubly linked list");
    printf("\n 2. To insert a node in a circular doubly linked list");
    printf("\n 3. To delete a node from a circular doubly linked list");
    printf("\n 4. To reverse a circular doubly linked list");
    printf("\n 5. To display a circular doubly linked list");
    printf("\n 6. To exit form program\n");
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

            Create(A,n);
            break;
        }
        case 2:
        {
            int index,element;
            printf("\n Enter the index of and element");
            scanf("%d%d",&index,&element);
            Insert(first,index,element);
            break;
        }
        case 3: {
             int index;
            printf("\n Enter the index of node you want to delete");
            scanf("%d", &index);
            Delete(first,index);
            break;
        }
        case 4:
        {
            Reverse(first);
            break;
        }
        case 5:
        {
            Display(first);
            break;
        }
        case 6: 
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
