#ifndef RECH_TRI_LIVRES_INSCRITS_H_INCLUDED
#define RECH_TRI_LIVRES_INSCRITS_H_INCLUDED


/* Cette fonction à pour objective convertir un chaine de caractéres en Majuscule, elle est appelée à chaque
   saisie d'une chaine par l'utilisateur pour rendre le programme non sensible à la casse */
void Conversion_En_Majuscule(char *CH);
void RechercheCoteLivre(livre **premier);
void RechercheTitreLivre(livre **premier);
void RechercheAuteurLivre(livre **premier);
void RechercheThemeLivre(livre **premier);
void RechercheEditionLivre(livre **premier);
void RecherchePrixLivre(livre **premier);
void RechercheIDInscrit(inscrit **premier);
void RechercheNomInscrit(inscrit **premier);
int NombreLivres();
void AfficheTabLivres(livre T[],int n);
void StockerLivresEnTab(livre T[],int n);
void EnregistrerModificationLivres(livre T[],int n);
void TrierCoteLivres();
void TrierTitreLivres();
void TrierAuteurLivres();
void TrierThemeLivres();
void TrierEditionLivres();
void TrierPrixLivres();
int NombreInscrits();
void AfficheTabInscrits(inscrit T[],int n);
void EnregistrerModificationInscrits(inscrit T[],int n);
void StockerInscritsEnTab(inscrit T[],int n);
void TrierIDInscrits();
void TrierNomInscrits();


#endif // RECH_TRI_LIVRES_INSCRITS_H_INCLUDED
