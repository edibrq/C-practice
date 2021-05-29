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
    temp->next = NULL;

    if(n == 1){ //when list is empty
        temp->next = *head;
        *head = temp;
        return;
    }

    struct node* iter = *head;
    for (int i = 0; i < n - 2; ++i) {
        iter = iter->next; //goto n - 1 element of the list
    }
    temp->next = iter->next;
    iter->next = temp;
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

//    printf("How many elements?\n");
//    int n,x;
//    scanf("%d",&n);
//    for (int i = 0; i < n; ++i) {
//        printf("Enter the number:\n");
//        scanf("%d",&x);
//        pop(&head, x);
//        print(&head);
//    }

    insert(&head, 1, 2);
    print(&head);
    insert(&head, 2, 3);
    print(&head);
    insert(&head, 3, 4);
    print(&head);



}


