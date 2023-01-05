#include <stdio.h>

char examine(short, char *);
char findheight(short, char *);

int main(void) {
    short N;
    char family;
    int count;

    for(count = 0; count<10; count++){
        family = 0;    
        scanf("%d", &N);
        char Building[N];

        for(short i=0; i<N; i++){
            scanf("%d", &Building[i]);
        }

        for(short i=0; i<N; i++){
            if(examine(i, Building)){
                family += findheight(i, Building);
            }else{
                continue;
            }
        }
        printf("#%d %d",count, family);
    }

}

char examine(short i, char *Building){
    if((Building[i-1]<Building[i] && Building[i-2]<Building[i]) && (Building[i+1]<Building[i] && Building[i+2]<Building[i])){
        return 1;
    }else{
    return 0;
    }
}

char findheight(short i, char *Building){
    char max1, max2;

    max1 = Building[i-2]>Building[i-1]?Building[i-2]:Building[i-1];

    max2 = Building[i+1]>Building[i+2]?Building[i+1]:Building[i+2];

    return max1>max2?max1:max2;

    
}