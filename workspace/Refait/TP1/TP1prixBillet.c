#include <stdbool.h>
#include <stdio.h>

int prixEnfant(int age, int prix_plein_tarif){

    if(age <= 2){
        return prix_plein_tarif*0.10;
    }
    else{
        if (age <= 12){
            return prix_plein_tarif*0.5;
        }
    }
    return prix_plein_tarif;
}

int prixPlaces(int age, int prix_plein_tarif){
    return prix_plein_tarif + prixEnfant(age, prix_plein_tarif);
}




int main(){
    printf("%i \n",prixPlaces(2,35));
    printf("%i \n",prixPlaces(6,35));
    printf("%i \n",prixPlaces(15,35));

    return 0;
}