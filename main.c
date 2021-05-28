#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node* next; //pointer with address of the next node
};

void push(struct node** head, int x){ //insertion to the beginning
    struct node* temp = (struct node*) malloc(sizeof(struct node)); //creating a node
    temp->data = x;
    temp->next = *head;
    *head = temp;
}

void print(struct node** head){
    struct node* temp = *head;
    printf("The List is:");
    while(temp != NULL){
        printf(" %d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert(struct node** head, int n, int value){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
}

void pop(struct node** head, int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    struct node* iter = *head;
    while(iter != NULL){
        if(iter->next == NULL)
            temp->next = iter;
    }

}

int main() {

    struct node* head = NULL;

    printf("How many elements?\n");
    int n,x;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        printf("Enter the number:\n");
        scanf("%d",&x);
        pop(&head, x);
        print(&head);
    }
}


