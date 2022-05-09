#ifndef INSCRITS_H_INCLUDED
#define INSCRITS_H_INCLUDED

void AfficherInscrits(inscrit *premier);
// Cette fonction retourne vrai si la cote du livre existe dans la bibliotheque et faux sinon
Bool VerificationID(inscrit *premier,int ID);
void AjouterInscrits(inscrit *premier);
void SupprimerInscrits(inscrit *premier);
inscrit* TransfererInscrits();
void ModifierAdresse(inscrit **premier,int ID);
void ModifierTele(inscrit **premier,int ID);
void ModifierInscrits(inscrit **premier);
void RechercherInscrit(inscrit **premier);
void TrierInscrits();



#endif // INSCRITS_H_INCLUDED
