#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct Matrix{
    int nbrLignes;
    int nbrColonnes;
    int* matrice;
} Matrix;

typedef struct MatrixArray {
    int taille;
    Matrix* matrices;
} MatrixArray;

MatrixArray readMatrixArray(){
    MatrixArray tableau;
	tableau.taille = scanLineAsInt();
	tableau.matrices =(Matrix*)malloc(tableau.taille*sizeof(Matrix));

	for(int i=0; i<tableau.taille; i++){
        readMatrix(i,&tableau);		
	}

	return tableau;
}

void readMatrix(int i,MatrixArray *tableau){
    

    scanf("%i %i",tableau->matrices[i].nbrLignes, tableau->matrices[i].nbrColonnes);
    int nbrLignes = tableau->matrices[i].nbrLignes;
    int nbrColonnes = tableau->matrices[i].nbrColonnes;

    //tableau->matrices[i].matrice[nbrLignes][nbrColonnes] => format tableau voulu
    
    for(int x=0; x<nbrLignes;x++){
            tableau->matrices[i].matrice[x]=scanLine();
        }
}


int scanLineAsInt() {
	int buf;
	scanf("%i\n",&buf);
	return buf;
}

char* scanLine()
{
	int maxLineSize = 255;
	char c, *line = calloc(maxLineSize+1,sizeof(char));

	scanf("%250[^\n]", line);

	if ( (c = getchar()) != '\n') {
		/* we did not get all the line */
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		// line[255] = '\0'; // useless because already initialized by calloc

		// let's skip all chars untli the end of line
		while (( (c = getchar()) != '\n') && c != EOF) ;
	}

	return line;
}

void affiches(MatrixArray *Matrices){
    int n = Matrices->taille;
    printf("%i",n);
    for(int i =0; i<n;i++){
        afficheMatrice(*Matrices,i);
    }
}

afficheMatrice(MatrixArray *Matrices,int i){
    int nbrLignes = Matrices->matrices[i].nbrLignes;
    int nbrColonnes = Matrices->matrices[i].nbrColonnes;

    printf("%i %i \n",nbrLignes,nbrColonnes);
    for(int x=0;x<Matrices->matrices[i].nbrLignes;x++){
        printf("%s \n",Matrices->matrices[i]->matrice[x])
    }
}

int main(){
    // MatrixArray* 
    MatrixArray Matrices = readMatrixArray();
	affiche(&Matrices);

	free(Matrices.matrices);
    return 0;
}

