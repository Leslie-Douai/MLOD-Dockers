#include <stdlib.h>
#include <stdio.h>

typedef unsigned long long TypeEntier;
TypeEntier factorielle(TypeEntier n){
    if(n==1){
        return 1;
    }

    return factorielle(n-1)*n;
}

TypeEntier TousFactorielle( TypeEntier n){

    for(int i=1; i<n; i++){
        printf("%i \n",factorielle(i));
    }
}


int main(){
    TousFactorielle(15); // En short on remarque des valeurs étrange, car on a pas assez de bit alloué pour calculer le nombre, il faut passer en long voir long long
    printf("%lld \n",factorielle(3));
    printf("%lld \n",factorielle(19)); //affichable avec un long simple, mettre "%lu" pour le print
    printf("%lld \n",factorielle(32));//Pas atteignable, nombre négatif
    printf("%lld \n",factorielle(67));//pas atteignable avec long long
    return 0;
}