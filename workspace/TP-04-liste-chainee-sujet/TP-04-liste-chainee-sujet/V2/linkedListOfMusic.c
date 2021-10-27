// gcc -W -Wall -std=c99 linkedList.c linkedListOfString.c -o linkedListOfString

// valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./linkedListOfString

#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ============
// Definitions of external functions
// ============

void afficheElement(Element e) {
	//On dit que Element e pointe vers une Music
	//Dont on enregistre l'adresse (on force)
	Music *m = (Music*)e; 
	//On affiche tous les élements
	printf("%s",(char*)m->name);
	printf("%s",(char*)m->artist);
	printf("%s",(char*)m->album);
	printf("%s",(char*)m->genre);
	printf("%s",(char*)m->DiscNumber);
	printf("%s",(char*)m->trackNumber);
	printf("%s",(char*)m->year);
	printf("\n");
}

void detruireElement(Element e) {
	Music *m = (Music*)e; 

	//On free la fin
	free(m->name);
	free(m->artist);
	free(m->album);
	free(m->genre);
	free(m->DiscNumber);
	free(m->trackNumber);
	free(m->year);

	//on free la nouvelle fin
	free(e);
}


// compare deux elements
bool equalsElement(Element e1, Element e2){

	return strcmp((char *)e1,(char *)e2)==0;
}	

MusicList triAnne(MusicList l){
	
}
