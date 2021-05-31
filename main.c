#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next; //pointer with address of the next node
};

int length(struct node** head){ //WORKING
    int len = 0;
    struct node* temp = *head;
    while(temp != NULL){
        ++len;
        temp = temp->next;
    }
    return len;
}

void print(struct node** head){ //WORKING
    struct node* temp = *head;
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    printf("The List is:");
    while(temp != NULL){
        printf(" %d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse(struct node** head){
    struct node* previous, *current, *next;
    current = *head;
    previous = NULL;

    while(current != NULL){
        next = current->next;
        current->next = previous; // adding ling to the n - 1 element
        previous = current; // resetting previous -> next
        current = next; // resetting current -> next
    }

    *head = previous; // when current is pointing to NULL previous contains index of the last element
}

void push(struct node** head, int x){ //insertion to the beginning.
    //TODO: fix the problem with pop and push sequence of calls
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;

    if(*head == NULL){
        temp->next = NULL;
        *head = temp;
        return;
    }

    temp->next = *head;
    *head = temp;
}

void insert(struct node** head, int n, int value){ //WORKING
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

void pop(struct node** head, int x){ //insertion to the end. WORKING
    int len = 0;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;

    struct node* iter = *head;
    if(*head == NULL){
        temp->next = NULL;
        *head = temp;
        return;
    }

    while(iter->next != NULL){ //counting the number of elements
        iter = iter->next;
        ++len;
    }

    for (int i = 0; i < len - 2; ++i) {
        iter = iter->next;
    }
    iter->next = temp;
    temp->next = NULL;
}

void delete(struct node** head, int n){ //WORKING
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

    if(currentNode->next == NULL){
        previous->next = NULL;
        free(currentNode);
        return;
    }

    previous->next = currentNode->next;
    free(currentNode);
}

int isContains(struct node** head, int n){ //finding first element with value = n
    if(*head == NULL){
        return 0;
    }

    struct node* iter = *head;
    while(iter != NULL){
        if(iter->data == n){
            return 1;
        }
        iter = iter->next;
    }

    return 0;
}

int findIndex(struct node** head, int n){
    if(*head == NULL){
        return 0;
    }

    struct node* iter = *head;
    int index = 0;
    while(iter != NULL){
        ++index;
        if(iter->data == n)
            return index;
    }
}

int main() {
    struct node* head = NULL;
    insert(&head, 1, 2);
    insert(&head, 2, 3);
    insert(&head, 3, 5);
    print(&head);
    reverse(&head);
    print(&head);
}


