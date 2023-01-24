#include <stdio.h>
#include <math.h>

int head =0;

int cipher(int N){
    
    N = N/10;

    if(N==0){ 
        return 1;
    }

    return 1+cipher(N);    
}

/*
 *cip,y를 넣으면 조합 cip C y를 구해서 뱉는 함수, 조합공식 = cip!/y! * (cip-y)! 
*/
int combination(int cip, int y){

    int cipfactorial = 1;
    for(int f = cip; f>0; f--){
        cipfactorial *= f;
    }
    
    //printf("\ncip factorial : %d\n", cipfactorial);

    int yfactorial = 1;
    for(int f = y; f>0; f--){
        yfactorial *= f;
    }

    //printf("\n y factorial : %d", yfactorial);

    int cip_minus_yf = 1;
    for(int f = cip-y; f>0; f--){
        cip_minus_yf *= f;
    }

    return cipfactorial / (yfactorial*cip_minus_yf);

}



int makecase(int k, int i, int xxxx, int x, int y, int tmpcase, int limitline, int *everycase, int howmuchy);


/*
*N보다 큰 요소는 다 날리는 함수
*/
void filteroverN(int *everycase, int N){

    for(int i = 0; i <= head; i++){
        if(everycase[i] > N){
            everycase[i] = 0;
        }
    }
}

/**
 * 모든 경우의 수 중에서 가장 큰 case를 뱉는 함수
*/
int mostbig(int *everycase){
    int tmp = everycase[0];
    for(int i = 0; i <= head; i++){
        if(everycase[i] > tmp){
            tmp = everycase[i];
        }
    }
    return tmp;
}


int main(){

    freopen("input.txt", "r", stdin);

    int T = 0;
    //테스트 케이스 횟수 T 입력
    scanf("%d", &T);


    for(int t = 1; t<=T; t++){
    //T 만큼 전체 반복



    
    int cip = 0;
    int N, x, y;


    
    scanf("%d %d %d", &N, &x, &y);

    //주어진 N의 자릿수를 구한다.
    cip = cipher(N);

    int limitline;

//모든 경우의 수를 담을 수 있는 everycase 배열 선언
    int number = 0;
    for(int ga = cip; ga>=2; ga--){
        for(int ia = 1; ia <= ga; ia++){
            number += combination(ga,ia);
        }

    }

    printf("\n-----%d-------\n", number);
    int everycase[number*2]; //위 구문이 정상적으로 모든 경우의 수를 구하지 못했기 때문에 그냥 충분한 3000으로 메모리를 할당함 -->segmantation fault가 안뜸 





//모든 경우의 수를 구하여 everycase배열에 차곡차곡 넣는다.
    int a;
    

        //자리수 2개인 경우의 수부터~ 자리수 cip개인 경우의 수까지
        for(int g = 2; g <= cip; g++){
            //printf("dddddd\n");
            int xxxx = 0;
            //자릿수 g에 따라 변하는 xxxx변수 ex)x가 3이면 g가2일때 33
            for(int c = 0; c<g; c++){
                xxxx += (int)pow(10.0, (float)c);
            }
            xxxx *= x;

            //printf("%d", xxxx);
            
            for(int howmuchy = g-1; howmuchy >= 1; howmuchy--){
            //y개수 변화 1개에서 g-1개까지 반복(x 또한 적어도 1개는 있어야하기 때문에 g-1로 상한선) 즉 , 변수 i는 y의 개수

                limitline = 0;

                if(howmuchy == 1 ){
                    for(int u = 1; u <= g; u++){
                        everycase[head] = xxxx - (int)pow(10.0, (float)(u-1)) * x + (int)pow(10.0, (float)(u-1)) * y;
                        head++;
                    }
                    continue;
                }

                for(a = 1; a <= g+1 - howmuchy; a++){
                //맨 모른쪽 숫자 y의 변화
                    makecase(g, howmuchy-1, xxxx, x, y, (int)pow(10.0, (float)(a-1)), limitline, everycase, howmuchy);
                    limitline++;
                }
                
            }
        }
    




    //filteroverN(everycase, N);
    filteroverN(everycase, N);

   /* printf("---- head : %d", head);
   for(int m = 0; m<head; m++){
        printf("%d\n", everycase[m]);
    }*/

    printf("#%d %d\n", t, mostbig(everycase));
    }



    return 0;
}

int makecase(int k, int i, int xxxx, int x, int y, int tmpcase, int limitline, int *everycase, int howmuchy){
    
    if(i == 0) return 0;

    if(i == 1){
        for(int c = howmuchy+1 - i + limitline; c <= k; c++){
            everycase[head] = xxxx - (tmpcase + (int)pow(10.0, (float)(c-1))) * x + (tmpcase + (int)pow(10.0, (float)(c-1))) * y;
            head++;
        }
        return 0;
    }

    for(int b = howmuchy+1 - i + limitline; b <= k+1 - i; b++){

        makecase(k, i-1, xxxx, x, y, tmpcase + (int)pow(10.0, (float)(b-1)), limitline, everycase, howmuchy);
        limitline++;

    }

    return 0;
}
