// 6210401252 Pongpol Rojanaadisorn

#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

void number(struct node **head, int n) {

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = n;

    if (*head == NULL) {
        temp -> next = *head;
        *head = temp;
    } 
    else {
        struct node *tmp = *head;
        struct node *prev = NULL;
        
        for (int i = 0 ; tmp != NULL && tmp -> data < temp -> data ; i++) {
            prev = tmp;
            tmp = tmp -> next;
        }

        temp -> next = tmp;

        if (prev != NULL) prev -> next = temp;
        else *head = temp;

    }

}

void print_list(struct node *head) {
    for ( head ; head ; head = head -> next )
        printf("%d\n", head -> data);
}

int main() {
    
    int input;
    struct node *head = NULL;
    int i = 0;

    while (scanf("%d", &input) == 1) {
        if (input <= -1)
            break;
        number(&head,input);
    }

    print_list(head);
}  