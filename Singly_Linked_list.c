#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head;

void begin_insert();
void last_insert();
void random_insert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();

void main(){
    int choice = 0;
    while(choice!=9){
        printf("\n\n.............Main Menu...................\n\n");
        printf("\nChoose one option from the following list\n");
        printf("\n1.Insert in begining\n2.Insert in last\n3.Insert at random location\n4.Delete from begining");
        printf("\n5.Delete from last\n6.Delete at random location\n7.Search for element\n8.Show\n9.Exit\n");

        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        begin_insert();
            break;
        case 2:
        last_insert();
            break;    
        case 3:
        random_insert();
            break;
        case 4:
        begin_delete();
            break;
        case 5:
        last_delete();
            break;
        case 7:
        random_delete();
            break;
        case 8:
        search();
            break;
        case 9:
        exit(0);
            break;
        default:
        printf("\nPlease enter valid choice : \n");
            break;
        }
    }
}
void begin_insert(){
    struct node *ptr;
    int item;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL) printf("\nOVERFOW\n");
    else{
        printf("\nEnter value : ");
        scanf("%d",&item);
        ptr->data=item;
        head=ptr;
        printf("\nNode inserted");
    }    
}
void last_insert(){
    struct node *ptr, *temp;
    int item;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL) printf("\nOVERFLOW\n");
    else{
        printf("\nEnter the value : ");
        scanf("%d",&item);
        ptr->data=item;
        if(head==NULL){
            ptr->next=NULL;
            head=ptr;
            printf("\nNode inserted \n");
        }
        else{
            temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->next=NULL;
            printf("\nNode inserted\n");
        }
    }
}
void random_insert(){
    int i, loc, item;
    struct node *ptr, *temp;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL) printf("\nOVERFOW\n");
    else{
        printf("\nEnter element : ");
        scanf("%d",&item);
        ptr->data=item;
        printf("\nEnter location : ");
        scanf("%d",&loc);
        temp = head;
        for(i=0; i<loc; i++){
            temp=temp->next;
            if(temp==NULL){
                printf("\nCan not inserted \n");
                return;
            }
        }
        ptr->next=temp->next;
        temp->next=ptr;
        printf("\nNode inserted\n");
    }
}
void begin_delete(){
    struct node *ptr;
    if(head==NULL) printf("\nList is Empty\n");
    else{
        ptr=head;
        head=ptr->next;
        free(ptr);
        printf("\nNode deleted \n");
    }
}
void last_delete(){
    struct node *ptr, *ptr1;
    if(head==NULL) printf("\nList is Empty \n");
    else if(head->next!=NULL){
        head=NULL;
        free(head);
        printf("\nNode is deleted\n");
    }
    else{
        ptr=head;
        while(ptr->next!=NULL){
            ptr1=ptr;
            ptr=ptr->next;
        }
        ptr1->next=NULL;
        free(ptr);
        printf("\nNode is deleted\n");
    }
}
void random_delete(){
    struct node *ptr, *ptr1;
    int loc;
    printf("\nEnter location\n");
    scanf("%d",&loc);
    ptr=head;
    for(int i=0; i<loc; i++){
        ptr1=ptr;
        ptr=ptr->next;
        if(ptr==NULL) printf("\nCan not delete\n");
    }
    ptr1->next=ptr->next;
    free(ptr);
    printf("\nNode  Deleted\n");
}
void search(){
    struct node *ptr;
    int item, i=0, flag;
    ptr=head;
    if(ptr==NULL) printf("\nEmpty list\n");
    else{
        printf("\nEnter item which you want to search : ");
        scanf("%d",&item);
        while(ptr!=NULL){
            if(ptr->data==item){
                printf("\nItem found at location %d",i+1);
                flag=0;
            }
            else flag=1;
            i++;
            ptr=ptr->next;
        }
        if(flag==1) printf("\nItem not found \n");
    }
}
void display(){
    struct node *ptr;
    ptr=head;
    if(ptr==NULL) printf("\nNothing to print\n");
    else{
        printf("\nPrinting value");
        while(ptr!=NULL){
            printf("\n%d",ptr->data);
            ptr=ptr->next;
        }
    }
}