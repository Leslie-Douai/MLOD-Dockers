
void affichageFactorielle(void){
    int N=0;
    printf("Entrez un nombre entier : ");
    scanf("%d", &N);
    printf ("%d = %11d\n", N, factorielle(N));
}

void calculFactorielles(void){
    for(int i=0 ; i<= 15; i++){
        printf("%d! =  %11d\n", i , factorielle(i));
        }
}

/* En récursif
TypeEntier factorielle(TypeEntier n){
    if (n<=1)
        return 1;
    return n*factorielle(n-1);*/

int main(void){
    affichageFactorielle();
    return 0;
}