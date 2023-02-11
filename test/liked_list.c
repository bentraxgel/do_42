#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *next;
};

int main() {
   struct node head;

   head.data = 1;
   head.next = (struct node *)malloc(sizeof(struct node));
   head.next->data = 2;
   head.next->next = NULL;


//    // linked list
//    struct node *temp = &head;
//    while (temp != NULL) {
//       printf("%d ", temp->data);
//       temp = temp->next;
//    }
   return 0;
}
