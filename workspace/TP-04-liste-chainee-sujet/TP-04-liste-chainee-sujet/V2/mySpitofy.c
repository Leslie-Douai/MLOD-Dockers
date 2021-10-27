#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "linkedListOfMusic.h"
#include "linkedList.h"

//$ gcc -W -Wall linkedListOfMusic.c linkedList.c mySpitofy.c -o mySpitofy

Music extraitLigne(char* ligne){
    Music res;
        
        res.name = malloc(sizeof(res.name));
        res.name = strsep(&ligne, ",\n");

        res.artist = malloc(sizeof(res.artist));
        res.artist = strsep(&ligne, ",\n");

        res.album = malloc(sizeof(res.album));
        res.album = strsep(&ligne, ",\n");

        res.genre = malloc(sizeof(res.genre));
        res.genre = strsep(&ligne, ",\n");

        res.DiscNumber = malloc(sizeof(res.DiscNumber));
        res.DiscNumber = strsep(&ligne, ",\n");

        res.trackNumber = malloc(sizeof(res.trackNumber));
        res.trackNumber = strsep(&ligne, ",\n");

        res.year = malloc(sizeof(res.year));
        res.year = strsep(&ligne, ",\n");

    return res;
}

//Parcours le fichier, à chaque ligne enregistre chaque catégorie 
//et lui alloue de l'espace 
MusicList extraireTab(FILE* tab){

    MusicList l;
    l=NULL;

    char* ligne;
    ligne = calloc(256,sizeof(char));
    while(!feof(tab)){
        fgets(ligne, 256,tab);

        Music res ;
        res = extraitLigne(ligne);
        ajoutTete(&res,l);
    }

    return l;
}

int main(void){

    FILE* monFichier;
    monFichier = fopen("music.csv","r");

    if( monFichier == NULL) {
        printf ("ERROR");
        return 0;
    }

    MusicList playlist;
    playlist = extraireTab(monFichier);

    afficheListe_i(playlist);

    return 0;
}