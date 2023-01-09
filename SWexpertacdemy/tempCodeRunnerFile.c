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

int overlappingcheck(char tmp){
    int tmphead = head;
    
    if(tmp < 97 && tmp > 122) {
        return 0;
    }

    while (head)
    {
        if(tmp == pop()){
            head = tmphead;
            return 0;
        }
        head--;
    }
    head = tmphead;
    return 1; 
}



/**
 * 현재 맵 위치와 스택, 몇번째 반복중인지에 대한 count변수를 입력받고 count(거리)를 뱉는 함수
**/
int move(int *j, int *i, char map[][4], int count){
    //a를 0부터 3까지 반복해가며 왼쪽아래오른쪾위 차례대로 검사 후 이동한다
    for(int a=0; a<4; a++){
            
        switch (a)
        {
        case 0: //왼쪽이동
            if(overlappingcheck(map[*j][*(i+1)])){
                push(map[*j][*(i+1)]); //해당 요소(tmp변수)를 push한다
                count++;
                (*i)++;
                return 1+move(j,i, map, count);
        }
            break;
        case 1: //아래로 이동
            if(overlappingcheck(map[*(j+1)][*(i)])){
                push(map[*(j+1)][*i]); //해당 요소(tmp변수)를 push한다
                count++;
                (*j)++;
                return 1+move(j,i, map, count);
        }
            break;
        case 2: //오른쪽 이동
            if(overlappingcheck(map[*j][*(i-1)])){
                push(map[*j][*(i-1)]); //해당 요소(tmp변수)를 push한다
                count++;
                (*i)--;
                return 1+move(j,i, map, count);
        }
            break;
        case 3: //위로 이동
            if(overlappingcheck(map[*(j-1)][*i])){
                push(map[*(j-1)][*i]); //해당 요소(tmp변수)를 push한다
                count++;
                (*j)--;
                return 1+move(j,i, map, count);
        }
            break;
            
        default:
            break;
        }
        
    }
    return 1;

}





int main(void){
    int j,i, count;
    scanf("%d %d", &j, &i);

    char map[j][i];

    printf("%s", map[0]);

    //j번 만큼 행을 입력받는다
    for(int x = 0; x<j; x++){
        scanf("%s", map[x]);
    }

    push(map[0][0]);
    count =1;

    count += move(&j,&i,map,count);
    
    printf("%d", count);

    
    printf("%s", stack);
    return 0;

    }