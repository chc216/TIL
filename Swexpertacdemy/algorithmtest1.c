#include <stdio.h>
#include <stdlib.h>

char stack[100];
int head = -1;

void push(char tmp){
    head++;
    stack[head] = tmp;
    
}

char pop(void){
    head--;
    return stack[head+1];
}

int overlappingcheck(char tmp){
    
    if(tmp < 97 || tmp > 122) {
        return 0;
    }

    for(int i=0; i<head+1; i++){
        if(tmp == stack[i]){
            return 0;
        }
    }
    
    return 1; 
}


/**
 * 현재 맵 위치와 스택, 몇번째 반복중인지에 대한 count변수를 입력받고 count(거리)를 뱉는 함수
**/
void move(int *jpointer, int *ipointer, char map[][*ipointer], int *countpinter){
    printf("move 함수 호출성공\n");
    //a를 0부터 3까지 반복해가며 왼쪽아래오른쪾위 차례대로 검사 후 이동한다
    for(int a=0; a<4; a++){
            
        switch (a)
        {
        case 0: //왼쪽이동
            if(overlappingcheck(map[*jpointer][*(ipointer)+1])){
                push(map[*jpointer][*(ipointer)+1]); //해당 요소(tmp변수)를 push한다
                (*ipointer)++;
                (*countpinter)++;
                move(jpointer,ipointer,map,countpinter);
        }
            break;
        case 1: //아래로 이동
            if(overlappingcheck(map[*(jpointer)+1][*(ipointer)])){
                push(map[*(jpointer)+1][*ipointer]); //해당 요소(tmp변수)를 push한다
                (*jpointer)++;
                (*countpinter)++;
                move(jpointer,ipointer,map,countpinter);
        }
            break;
        case 2: //오른쪽 이동
            if(overlappingcheck(map[*jpointer][*(ipointer)-1])){
                push(map[*jpointer][*(ipointer)-1]); //해당 요소(tmp변수)를 push한다
                (*ipointer)--;
                (*countpinter)++;
                move(jpointer,ipointer,map,countpinter);
        }
            break;
        case 3: //위로 이동
            if(overlappingcheck(map[*(jpointer)-1][*ipointer])){
                push(map[*(jpointer)-1][*ipointer]); //해당 요소(tmp변수)를 push한다
                (*jpointer)--;
                (*countpinter)++;
                move(jpointer,ipointer,map,countpinter);
        }
            break;
            
        default:
            break;
        }
        
    }
    (*countpinter)++;

}
hihihiihihihihhiihi
hihiihiihhi



int main(void){
    int j,i, count;
    scanf("%d", &j);
    scanf("%d", &i);

    char map[j][i+1];
    //j번 만큼 행을 입력받는다
    for(int x = 0; x<j; x++){
        scanf("%s", map[x]);
    }

    j=0;
    i=0;

    push(map[0][0]);

    count = 1;

    move(&j,&i, map, &count);
    
    printf("%d\n", count);

    for(int c = 0; c<=head; c++){
        printf("%c\n", stack[c]);
    }
    return 0;

    }