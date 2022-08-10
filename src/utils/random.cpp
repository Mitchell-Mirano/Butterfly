#include<stdlib.h>
#include<time.h>


int randomRose(){

    int num=rand()%100;
    if(num>50){
        return 1;
    }else{
        return 2;
    }
}