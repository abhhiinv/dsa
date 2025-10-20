#include <stdio.h>
#define MAX 100

int main(void){
    int arr[MAX],i,n,pos=0,val,ch;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    while(1){
        printf("******MENU********\n");
        printf("1)Array insertion\n2)Array deletion\n3)Display\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the position of the element to insert\n");
                    scanf("%d",&pos);
                    printf("Enter the element\n");
                    scanf("%d",&val);
                    
                    for(i=pos;i>pos;i--){
                    arr[i]=arr[i-1];
                    arr[pos]=val;
                    n++;
                    break;
                    }
        }
    }
return 0;
}