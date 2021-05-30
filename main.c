#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node* next; //pointer with address of the next node
};

void print(struct node** head){
    struct node* temp = *head;
    printf("The List is:");
    while(temp != NULL){
        printf(" %d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void push(struct node** head, int x){ //insertion to the beginning
    struct node* temp = (struct node*) malloc(sizeof(struct node)); //creating a node
    temp->data = x;
    temp->next = *head;
    *head = temp;
}

void insert(struct node** head, int n, int value){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;

    if(n == 1){ //when list is empty
        *head = temp;
        return;
    }

    struct node* iter = *head;
    for (int i = 0; i < n - 2; ++i) { //n - 1 is the first node there
        iter = iter->next; //goto n - 1 element of the list
    }
    temp->next = iter->next; // creating link to the next element
    iter->next = temp; // creating link from n - 1 element to nth element
}

void pop(struct node** head, int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    struct node* iter = *head;
    while(iter != NULL){
    }
    temp->next = iter->next;
}

void delete(struct node** head, int n){
    if(*head == NULL)
        return;

    struct node* iter = *head;
    if(n == 1){
        *head = iter->next;
        free(iter);
        return;
    }

    struct node* previous =*head;
    for (int i = 0; i < n - 2; ++i) {
        previous = previous->next;
    }
    struct node* currentNode = previous->next;
    previous->next = currentNode->next;
    free(currentNode);
}

int main() {
    struct node* head = NULL;
    insert(&head,1,3);
    insert(&head,2,5);
    insert(&head,3,7);
    print(&head);
    delete(&head,2);
    print(&head);


}


