#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int front = 0, rear = 0;
int q;
void print(int* queue) {
   for (int i = 0; i < q; i++) {
      printf(" %d", queue[i]);
   }
   printf("\n");
}
int insert(int* queue, int data) {
   rear = (rear + 1) % q;
   if ((rear == front)) {
      printf("overflow");
      print(queue);
      return 0;
   }
   queue[rear] = data;
   return 1;
}
int delete_Queue(int* queue) {
   if (front == rear) {
      printf("underflow");
      return 0;
   }
   queue[++front] = 0;
   return 1;
}
void delete_Max(int* queue) {
   int max = 0;
   for (int i = 0; i < q; i++) {
      if (queue[max] < queue[i]) {
         max = i;
      }
   }

   queue[max] = 0;
}


int main() {
   int n;
   scanf("%d", &q);
   int* queue = (int*)malloc(sizeof(int) * q);
   scanf("%d", &n);
   memset(queue, 0, sizeof(int) * q);
   for (int i = 0; i < n; i++) {
      char command;
      scanf(" %c", &command);

      if (command == 'I') {
         int data;
         scanf("%d", &data);
         if (insert(queue, data) == 0) {
            return 0;
         }
      }
      else if (command == 'D') {
         if (delete_Queue(queue) == 0) {
            return 0;
         }
      }
      else if (command == 'M') {
         delete_Max(queue);
      }
      else {
         print(queue);
      }
   }



   return 0;
}
