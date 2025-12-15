#include <stdio.h>
#include <stdlib.h>

// I think this is how to make a node?
struct Node {
    int data;
    struct Node *next; // pointer to... next? I think
};

// I wanted to make a function to add node
void addNode(struct Node *head, int value) {
    // I don’t know how to do this
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // I think this should connect somehow
    head->next = newNode; // but this only works once?
    // what if head is NULL? idk
}

// Print function maybe?
void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        // I think I need to go to next
        head = head->next;
        // but sometimes this crashes??
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;

    // Trying to add elements
    addNode(head, 10);
    addNode(head, 20);
    addNode(head, 30);

    printList(head); // doesn't print anything :(
    return 0;
}
