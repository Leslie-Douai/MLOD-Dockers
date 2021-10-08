#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//compte nombre de changemente t si sup à 2 c mort (check sur )
bool estConvexe(bool tab[], int length){
    int nbChange = 0;
    for(int i=0; i<length-1;i++){
        if (tab[i] != tab[i+1]){
            nbChange ++;
        }
    }
    if (nbChange==0 || nbChange == 1){
        return true;
    }
    if(nbChange==2){
        if (tab[0]== tab[length-1]){
            return true;
        }
    }
    return false;
}
// Commence indice à 0 et on parcourt tant que rencontre true et tant que 
int main(void){
    //main ou on déclare des tableau de booleean
    bool t1 [] = {false, true, true, false,false};
    bool t2 [] = {true, true, false, false, true};
    bool t3 [] = {true, true, false, true, false};

    printf("%d \n",estConvexe( t1, 5));
    printf("%d \n",estConvexe( t2, 5));
    printf("%d \n",estConvexe( t3, 5));

    //opérateur ternaire ? : est_convexe(tabConvexe1,5)?
    return 0;
}