#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Liste l;
	l =(Liste)malloc(sizeof(Cellule));
	l->val = v;
	l->suiv = NULL;
	return l;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	Liste m;
	m =	creer(v);
	m->suiv = l;
	return m;
}


void afficheElement(Element e) {
	printf("%i ",e);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe afficheElement
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	Liste p = l;
	while(!estVide(p)){
		 afficheElement(p->val);
		 p=p->suiv;
	}
	printf("\n");
}

// version recursive
void afficheListe_r(Liste l) {
	if(!estVide(l)){//Vraiment utiliser la fonction car le jour ou on change la struct des listes c'est la cata partout, alors que là juste estVide();
		 afficheElement(l->val);//Encapsulation
		 afficheListe_r(l->suiv);
	}
	printf("\n");
}

void detruireElement(Element e) {
}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste t;
	while(!estVide(l)){
		t = l->suiv;//On stock
		detruireElement(l->val);//on détruit le contenu
		free(l);//On libere le lien
		l = t;//on initialise la prochaine boucle
	}
}

// version récursive
void detruire_r(Liste l) {
	if(!estVide(l)){
		detruire_r(l->suiv);
	}
	detruireElement(l->val);
	free(l);
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	Liste n = l;
	
	while(!estVide(n->suiv)){
		 n=n->suiv;
	}
	n->suiv = creer(v);
	return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if(!estVide(l->suiv)){
		ajoutFin_r(v,l->suiv);
	}else{
		l->suiv=creer(v);
	}
	return l;
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	while(!estVide(l)){
		if(equalsElement(l->val, v)){
			return l;
		}
		l = l->suiv;
	}	
	return NULL;

	//CORRECTION
	/*while(!estVide(l)|| ) */
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if(equalsElement(l->val, v)){
			return l;
		}
	if(!estVide(l->suiv)){
		return cherche_r(v,l->suiv);
	}	
	return NULL;
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l){
	Liste m =l;
	
	while (!estvide(m)){
		if(equalsElement(v,m->val)){
		m=m->suiv;
		return l;
		}
	}
	return NULL;
		
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	return TODO;
}


void afficheEnvers_r(Liste l) {
	TODO;
}



