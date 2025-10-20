#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    
}list;

list *start =NULL;

int main (void){
    int i=0,n;
    list *ptr ;
    list *temp;
    printf("N= ");
    scanf("%d",&n);
    while(i<n){
        ptr = (list*) malloc (sizeof(list));
        printf("Data :");
        scanf("%d",&ptr->data);
        ptr -> next =NULL;
        if(!start) start=ptr;
        else temp->next=ptr;
        temp=ptr;
        i++;
    }

    temp=start;
    while(temp){
        printf("%d\n",temp->data);
        temp=temp->next;

    }
    return 0;
}