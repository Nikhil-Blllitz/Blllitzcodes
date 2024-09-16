#include<stdio.h>
#include<stdlib.h>
struct SLL{
    int sem;
    char usn[11],name[20],branch[20],phone[11];
    struct SLL *next;
};
typedef struct SLL node;
node *start=NULL;
node* getNode(){
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("enter the student details: usn, name, branch, sem and phno\n");
    scanf("%s",newnode->usn);
    scanf("%s",newnode->name);
    scanf("%s",newnode->branch);
    fflush(stdin);
    scanf("%d",&newnode->sem);
    scanf("%s",newnode->phone);
    newnode->next=NULL;
    return newnode;
}
void insertbegin(){
    node *newnode;
    newnode=getNode();
    if(start==NULL){
        start=newnode;
        return;
    }
    newnode->next=start;
    start=newnode;
}
void insertend(){
    node *newnode,*temp;
    newnode=getNode();
    if(start==NULL){
        start=newnode;
        return;
    }
    temp=start;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newnode;
}
void deletebegin(){
    node* temp=start;
    if(start==NULL){
        printf("list is empty\n");
        return;
    }
    printf("deleted node is %s\n",temp->usn);
    start=temp->next;
    free(temp);
}
void display(){
    int count=0;
    node* temp=start;
    if(start==NULL){
        printf("list is empty\n");
        return;
    }
    printf("list elements are\n");
    while(temp!=NULL){
        printf("%s\t",temp->usn);
        temp=temp->next;
        count++;
    }
    printf("count=%d\n",count);
}
void deleteend(){
    node *temp=start,*prev;
    if(start==NULL){
        printf("list is empty\n");
        return;
    }
    if(start->next==NULL){
        printf("deleted node is %s\n",temp->usn);
        start=NULL;
        free(temp);
    }
    else{
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        printf("deleted node is %s\n",temp->usn);
        free(temp);
    }
}
int main(){
    int choice,n,i;
    while(1){
    printf("enter your choice\n1.insert in the beginning\n2.insert at the end\n3.delete in the beginning\n4.delete at the end\n5.display\n6.exit\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:printf("enter the no of students\n");
        scanf("%d",&n);
        for(i=0;i<n;i++){
            insertbegin();
        }
        break;
        case 2:insertend();
        break;
        case 3:deletebegin();
        break;
        case 4:deleteend();
        break;
        case 5:display();
        break;
        case 6:exit(0);
        break;
        default:printf("invalid chioce\n");
        }
    }
}