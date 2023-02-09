오답노트 or 배운 것
================

## 1월 14일
### #SWexpertacademy 사전문제 1번




### #SWexpertacademy 사전문제 2번

1. 동일한 숫자 카드 m개를 조합하여 n자리 숫자 만들기  
--> nCm 사용

2. 중첩 횟수가 변하는 중첩 for문 구현  
-->재귀함수를 응용하여 구현한다  
설명 : 중첩 횟수를 조절할 변수 i를 매개변수로 받아 i-1로 조절한 뒤, i==1이면 마지막 for문을 수행하고 함수호출을 종료한다.  

>ex) 중첩 횟수를 3번으로 하고 싶다  

    int overlapfor(int i){
        //중첩횟수를 조절하는 매개변수 i가 1이면 마지막 중첩 for문임으로 간주한다.
        if(i==1){
            for(int x=0; x<10; x++){
                실행문;
            }
            return 0; //함수 종료
        }
        
        for(int x=0; x<10; x++){
            실행문;
            overlapfor(i-1); //중첩 횟수를 조절하는 매개변수 i를 -1함으로써 재귀호출을 끝내도록 조절한다
        }
        return 0; //형식상의 리턴
    }

    int main(){
        i=3;
        overlapfor(i);

        return 0;
    }

  
  

3. 실행 할 때마다 크기가 변하는 배열을 매개변수로 받는 법  
-->매개변수를 포인터 변수로 선언한다  
설명 : 배열을 인수로 전달하는 방법에는 매개변수를 배열로 선언하거나 포인터 변수로 선언하는 두가지 방법이 있다.  
  
    if)매개변수를 배열로 선언하면 --> 매개변수 배열의 크기가 고정된다

        void array(int a[4]){
            ...
        }
        

        array(b); //배열 b의 크기가 4로 선언되어야 한다 .

    if)매개변수를 포인터 변수로 선언하면 --> 가변적인 배열을 인수로 받을 수 있다.

        void array(int *a){
            ...
        }

        array(b); //배열 b의 크기는 상관없다



## 1월 24일
### 삼성 SWexpertacademy 알고리즘 문제 파일 입출력
1. 파일 입출력(스트림)을 이용한다.  
* freopen  
    --> fopen함수와는 달리 스트림 변경이 가능하다  
    --> stdin, stdout 을 이용하여 printf, scanf 사용 가능  

            FILE* freopen(const char* filename, const char* mode, FILE* stream);


            <예시>
            freopen("input.txt", "r", stdin); //input.txt파일을 read모드로 스트림은 stdin으로 변경하여 읽는다.

            scanf("%d", &~); 
            //freopen함수로 stdin스트림을 읽어들임으로 파일에서 정수형을 빈칸 단위로 읽어들인다.
            //파일 포인터는 데이터를 읽은 후 뒤로 자동이동한다.
            //(형식화된 입출력 참고하기)


## 백준 10952번
### 테스트 케이스 scanf입력 사용법  

        EOF != scanf("%d", &a);
        //테스트 케이스가 더이상 없을 경우 scanf는 EOF를 반환한다.

