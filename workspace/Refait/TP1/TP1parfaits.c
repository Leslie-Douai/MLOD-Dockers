#include <stdlib.h>
#include <stdio.h>

void afficheParfaits(int N){
    for(int i=0;i<=N; i++){
        if(estParfaits(i)){
            printf("%i \n",i);
        }
    }
}

int estParfaits(int n){
    int somme =1;
    for(int i = 2; i<n;i++){
        if(n%i==0){
            somme += i;
        }
    }
    return somme == n;
}

int main(){
    afficheParfaits(10);
    printf("%s \n", "Oui");
    afficheParfaits(30);
    return 0;
}