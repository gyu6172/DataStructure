#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int index = -1;
int n;
void push(char* stack, char data) {
   if (index == n) { return; }
   stack[++index] = data;
}

char pop(char* stack) {
   return stack[index--];
}

int main() {
   scanf("%d", &n);
   char* str = (char*)malloc(sizeof(char) * (n));
   char*stack = (char*)malloc(sizeof(char) * (n));
   scanf("%s", str);

   int check = 0;
   int len = strlen(str);
   
   for (int i = 0; i < len / 2; i++) {
      push(stack, str[i]);
   }

   int half_len = len % 2 == 0 ? len / 2 : len / 2 + 1;
   for (int i = half_len; i < len; i++) {
      char data = pop(stack);

      if (data != str[i]) {
         check = 1;
      }
   }

   if (check == 0) {
      printf("1");
   }
   else {
      printf("%s", str);
      for (int i = len - 1; i >= 0; i--) {
         printf("%c", str[i]);
      }
   }


   return 0;
}
