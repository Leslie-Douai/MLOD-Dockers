#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


enum Mois{
    Janvier,
    Fevrier,
    Mars,
    Avril,
    Mai,
    Juin,
    Juillet,
    Aout,
    Septembre,
    Octobre,
    Novembre,
    Decembre
};

struct Date{
    int Jour;
    enum Mois mois;
    int annee;
};


typedef enum Mois Mois;
typedef struct Date Date;

void initialiseDate(Date *d){
    printf( "Jour :");
    scanf("%i", &d->Jour);
    printf( "Mois :");
    scanf("%i", (int*)&d->mois);
    printf( "Anne :");
    scanf("%i", &d->annee);
}

Date creerDateParCopie(){
    Date d;
    printf( "Jour :");
    scanf("%i", &d->Jour);
    printf( "Mois :");
    scanf("%i", (int*)&d->mois);
    printf( "Anne :");
    scanf("%i", &d->annee);
    return d;
}

Date* newDate(){
    Date* pDate = (Date*)malloc(sizeof(Date));
    if (pDate){
        initialiseDate(pDate);
    }
    return pDate;
}
int main(void){
    Date d; //On a déjà def d une date
    initialiseDate(&d);
    d = creerDateParCopie();
    afficheDate(&d);
    

    Date *date;
    return 0;
}