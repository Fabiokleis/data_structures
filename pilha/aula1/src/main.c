#include <stdio.h>
#include <string.h>
#include "stack.h"

int main(int argc, char argv[]) {

    /*    
    Stack *p = create(3);
    push(p, 1);
    push(p, 2);
    push(p, 4);
    
    while (!empty(p)) {
        printf("%d\n", pop(p));
    }
    desalloc(p);
    */

    /* //////////////////// parser /////////////////// */

    char* buffer = "[] ( [ ( [ ] ) ] ) ()";
    Stack* p = create(strlen(buffer));

    int i = 0;

    while (buffer[i] != '\0') {

        if (buffer[i] == '(' || buffer[i] == '[') {

            push(p, buffer[i]);

        } else if (buffer[i] == ')') {

            if (empty(p) || pop(p) != '(') {
                printf("Mal formada!\n");
                exit(1);
            }
                
        } else if (buffer[i] == ']') {

            if (empty(p) || pop(p) != '[') {
                printf("Mal formada!\n");
                exit(1);
            }
        }
        i++;
    }
    
    if (empty(p)) {

        printf("Bem formada!\n");

    } else {

        printf("Mal formada!\n");
    }
    
    desalloc(p);
    return 0;
}
