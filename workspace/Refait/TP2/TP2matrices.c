<<<<<<< Updated upstream
=======
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

void mult_matrice(int64_t (*AB)[5],int64_t (*A)[5],int64_t(*B)[5]){ //(*A) Pointe vers un array
    
    for(int i=0;i<5;i++){
        for(int j=0; j<5;j++){
            AB[i][j] = 0;
            for(int k=0;k<5;k++){
                AB[i][j] += A[i][k] * B[k][j];
            }

        }
    }
}

void affiche_matrice(int64_t (*AB)[5]){
    for (int i = 0; i <5; i++){
        for (int j = 0; j <5; j++){
            printf("%ld \t", AB[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
//matrices en ligne * colonne
int64_t matrice1[5][5]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
int64_t matrice2[5][5]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
int64_t matriceResultat[5][5];

mult_matrice(matriceResultat,matrice1,matrice2);
affiche_matrice(matriceResultat);

return 0;
}


>>>>>>> Stashed changes
