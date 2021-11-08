#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a) {
	return a==NULL;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a) {
	*a = NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) {
	ArbreBinaire E;
	E = malloc(sizeof(E));
	E->val = e;
	E->filsGauche=NULL;
	E->filsDroit=NULL;

	return E;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) {
	if (a->val == e){
				return a;
	}

	ArbreBinaire p, p2 = a;

	bool feuille = false;
	while(!feuille){
		
		if (p2->val == e){
				return a;
			}

		if (p2->val<e){
			p = p2->filsDroit;
			if(estVide(p)){ 
				feuille =true;
				}
				else{
				p2=p;	
				}
			
		}else{
			p = p2->filsGauche;	
			if(estVide(p)){ 
				feuille =true;
				}
				else{
				p2=p;	
				}
		}
	}
	if (p2->val<e){
			p2->filsDroit = creer(e);
	}else{
			p2->filsGauche = creer(e);	
	}
	return a;
}	

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e) {
	
	if(estVide(a)){
		a = creer(e);
		return a;
	}
	if (a->val == e){
		return a;
	}	
	if (a->val<e){
		a->filsDroit = insere_r(a->filsDroit,e);
	}else{
		a->filsGauche = insere_r(a->filsGauche, e);	
	}
	return a;
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a){
	if(estVide(a)){
		return 0;
	}
	return nombreDeNoeud(a->filsGauche) + 1 + nombreDeNoeud(a->filsDroit);
}

// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e){
	if(estVide(a)){
		return -1;
	}

	if (a->val == e){
		return 1;
	}

	if (estVide(recherche_r(a,e))){
		return -1;
	}

	if (a->val < e){
		return profondeur(a->filsDroit,e) + 1 ;
	}else{
		return profondeur(a->filsGauche,e) + 1 ;
	}
		return 0;
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a){
	return NULL;
}

// retourne le pere de e dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element e){
	if(estVide(a) || a->val == e){
		return NULL;	
	}
	if(a->val < e){
		if(!estVide(a->filsDroit)){
			if (a->filsDroit->val== e){
				return a;
			}else{
				return pere(a->filsDroit, e);
			}
		}
	}else
		if(!estVide(a->filsGauche)){
			if (a->filsGauche->val== e){
				return a;
			}else{
				return pere(a->filsGauche, e);
			}
				
		}	
	return NULL;
}


void afficheRGD_r(ArbreBinaire a){
	if(!estVide(a)){
		printf("%i", a->val);

		if(!estVide(a->filsGauche)){
		afficheRGD_r(a->filsGauche);
		}
		if(!estVide(a->filsDroit)){
		afficheRGD_r(a->filsDroit);
		}
	}

}

void afficheGRD_r(ArbreBinaire a){
	if(!estVide(a)){
		if(!estVide(a->filsGauche)){
		afficheGRD_r(a->filsGauche);
		}

		printf("%i", a->val);

		if(!estVide(a->filsDroit)){
		afficheGRD_r(a->filsDroit);
		}
	}
	
}

void afficheGDR_r(ArbreBinaire a){
	if(!estVide(a)){
		if(!estVide(a->filsGauche)){
		afficheGDR_r(a->filsGauche);
		}
		if(!estVide(a->filsDroit)){
		afficheGDR_r(a->filsDroit);
		}
		printf("%i", a->val);
		
	}
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a){
	if(estVide(a))
		return NULL;

	if(estVide(a->filsGauche))
		return a;

	return min(a->filsGauche);
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a){
	if(estVide(a))
		return NULL;

	if(estVide(a->filsDroit))
		return a;

	return max(a->filsDroit);
}


// retourne l'arbre dont la valeur de la racine est e et NULL si e n'existe dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element e){

	if(estVide(a))
		return NULL;

	if(a->val == e)
		return a;
	
	if(a->val < e){
		return recherche_r(a->filsDroit, e);
	}else
		return recherche_r(a->filsGauche, e);
}


// supprime e de a
ArbreBinaire supprimer_r(ArbreBinaire a,Element e)
{
	ArbreBinaire p = recherche_r(a,e);
	if (estVide(p)){
		return a;
	}

	ArbreBinaire l = pere(a,e);

	if(estVide(p->filsDroit) && estVide(p->filsGauche)){
		if(e < l->val){
			l->filsGauche = NULL;
		}else{
			l->filsDroit = NULL;
		}

		
		free(p);
		return a;
	}

	ArbreBinaire t;
	
	if(!estVide(p->filsDroit) && !estVide(p->filsGauche)){
		t = max(p->filsGauche);
		t->filsDroit = p->filsDroit;

		if(estVide(l))//Pas d'élément au dessus (exemple racine)
			return p->filsGauche;

		if(e < l->val){
			l->filsGauche = t;
		}else{
			l->filsDroit = t;
		}

		
		free(p);
		return a;
	}

	
	if(estVide(p->filsDroit) && !estVide(p->filsGauche)){
		if(e < l->val){
			l->filsGauche = p->filsGauche;
		}else{
			l->filsDroit = p->filsGauche;
		}

		
		free(p);
		return a;
	}

	//	- à droite
	if(estVide(p->filsGauche) && !estVide(p->filsDroit)){
		if(e < l->val){
			l->filsGauche = p->filsDroit;
		}else{
			l->filsDroit = p->filsDroit;
		}
		
		free(p);
		return a;
	}

	return a;



	return NULL;
}


void detruire_r(ArbreBinaire a){
	if(!estVide(a)){
			detruire_r(a->filsDroit);
			detruire_r(a->filsGauche);
			free(a);
	}
}
