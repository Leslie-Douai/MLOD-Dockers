#include <stdio.h>



void somme_3D(int N){ //Valeurs du 3eme dés  est fixé donc on peut passer à 2 boucles
    if (N<=18 && N>=3){
        for(int i = 1; i<7;i++){
            for(int j= 1; j<7; j++){
                for(int k ; k<7; k++){
                    if (i+j+k == N){
                        printf("%i%i%i \n", i,j,k);
                    }
                }
            }
        }
    }
    else{
        printf("veuillez choisir un autre nombre entre 3 et 18");
    }
    }

    int main(void){
    somme_3D(8);
    return 0;
}