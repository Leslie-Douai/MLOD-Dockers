#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void echangeContenu(int *x, int *y){

    int c = *x;
    *x = *y;
    *y=c;
}
int main(){
    int a = 10;
    int b =20;
    printf("%i \n",a);
    printf("%i \n",b);
    echangeContenu(&a,&b);
    printf("%i \n",a);
    printf("%i \n",b);

    return 0;
}
