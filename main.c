#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node* next; //pointer with address of the next node
};

struct node* head = NULL; //empty list

void insert(int x){ //insertion to the beginning
    struct node* temp = (struct node*) malloc(sizeof(struct node)); //creating a node
    temp->data = x;
    temp->next = head;
    head = temp;
}

void print(){
    struct node* temp = head;
    printf("The List is:");
    while(temp != NULL){
        printf(" %d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    printf("How many elements?\n");
    int n,x;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        printf("Enter the number:\n");
        scanf("%d",&x);
        insert(x);
        print();
    }
}


