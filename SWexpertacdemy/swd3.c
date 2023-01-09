#include <stdio.h>

char examine(short, int *, int *);
int sidemax(int *, short, int *);

int main(void) {
    short N;
    char family;
    int count;
    int maxbuildingindex;

    for(count = 0; count<10; count++){
        family = 0;    
        scanf("%hd", &N);
        int Building[N];

        for(short i=0; i<N; i++){
            scanf("%d", &Building[i]);
        }

        for(short i=2; i<N-2; i++){
            if(examine(i, Building, &maxbuildingindex)){
                family += Building[i] - Building[maxbuildingindex];
            }else{
                continue;
            }
        }
        printf("#%d %d",count+1, family);
    }

}


int sidemax(int *buildingindex, short i, int *Building){
    int maxbuilding;
    *buildingindex = i-2;

    maxbuilding = Building[i-2];

    if(maxbuilding < Building[i-1]){
        maxbuilding = Building[i-1];
        *buildingindex = i-1;
    }
    if(maxbuilding < Building[i+1]){
        maxbuilding = Building[i+1];
        *buildingindex = i+1;
    }
    if(maxbuilding < Building[i+2]){
        maxbuilding = Building[i+2];
        *buildingindex = i+2;
    }
    
    return maxbuilding;


}

char examine(short i, int *Building, int *address){
    if(sidemax(address, i, Building)<Building[i]){
        return 1;
    }else{
    return 0;
    }
}