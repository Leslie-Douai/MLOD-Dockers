#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

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

void initialiseDate(Date ){

}
int main(){
    Date d;
    initialiseDate(&d); //Pourquoi a t-on ajouté un &? 

    return 0;
}