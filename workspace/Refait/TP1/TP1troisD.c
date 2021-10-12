#include <stdlib.h>
#include <stdio.h>

void valeurDesDes(int N){
    if(N<=2 || N > 6*3){
        printf("%s \n", "Impossible ");
    }
    else{
        for(int i = 1; i<7;i++){
            for(int j = 1; j<7;j++){
                if(N-i-j <=6 && N-i-j >0){
                    printf("%i %i %i \n", i,j,N-i-j);
                }
            }
        }
    }
}


int main(){
    valeurDesDes(-3);
    printf("%s \n","Autre test 19");
    valeurDesDes(19);
    printf("%s \n","Autre test 4");
    valeurDesDes(4);
    return 0;
}