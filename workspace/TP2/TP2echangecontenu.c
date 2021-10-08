#include <stdio.h>

void echangeContenu(int* a , int* b){ //voir les pointeurs !
    int c = *a;
    *a = *b;
    *b = c;
}

int main(){
    int a = 10;
    int b = 20;

    printf("%d %d \n",a,b); // remplace le d par la variable rentrée en arguments, donc autant de %D que de variable
    echangeContenu(&a,&b); // Voir pointeur encore
    printf("%d %d \n",a,b);
    return 0;
}