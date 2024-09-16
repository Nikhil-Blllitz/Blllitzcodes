#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,n,type)\
p=(type*)malloc(n*sizeof(type));\
if(p==NULL)\
{\
    printf("\nInsufficient memory\n");\
    exit(0);\
}
struct node{
    int info;
    struct node* link;
};
typedef struct node*NODE;

NODE insert_first(int item){
    NODE first;
    MALLOC(first,1,struct node);
    first->info=item;
    first->link=NULL;
    return first;
}
NODE insert_front(int item,NODE first){
    NODE temp;
    MALLOC(temp,1,struct node);
    temp->info=item;
    temp->link=first;
    return temp;
}
NODE display_list(NODE first){
    NODE temp;
    temp=first;
    int n=1;
    while(temp!=NULL){
        printf("NODE %d->",n);
        temp=temp->link; 
        n++;
    }
    temp=first;
    n=1;
    printf("\nDetails of Node\n");
    while(temp!=NULL){
        printf("%d: %d\n",n,(*temp).info);
        temp=temp->link;
        n++;
    }
}
void main(){
    int command,item,i=1;
    printf("Enter item for first");
    scanf("%d",&item);
    NODE first=insert_first(item);
    while(i!=0){
    printf("\n1.InsertFront\n2.InsertRear\n3.DeleteFront\n4.DeleteRear\n5.SortList\n6.Display\n7.Exit\n");
    scanf("%d",&command);
    switch(command){
        case 1:printf("Enter item to be inserted\n");
        int item;
        scanf("%d",&item);
        first=insert_front(item,first);
        break;
        case 6:display_list(first);
        break;
        case 7:i=0;
        break;
        default:printf("\nInvalid Command\n");
        exit(0);
    }
    }
}
