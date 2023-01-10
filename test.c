/*#include <stdio.h>

void testfun(char map[][4], int j, int i){
    map[j][i] = 's';
}

int main(){
    int j,i;
    char map[2][4] = {"abcd", "asdf"};

    testfun(map, 0,0);
    printf("%s", map);
    return 0;
}*/

#include <stdio.h>


char stack[26];
int head = -1;

void push(char tmp){
    head++;
    stack[head] = tmp;
    
}

char pop(void){
    head--;
    return stack[head+1];
}

int main(){
    push('c');

    printf("%d", head);

    printf("%c", stack[head]);

    return 0;
}
