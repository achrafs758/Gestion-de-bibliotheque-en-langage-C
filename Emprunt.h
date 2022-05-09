#ifndef EMPRUNT_H_INCLUDED
#define EMPRUNT_H_INCLUDED

void Conversion_En_Jour(unsigned long *s);
unsigned long Difference_Date(Emprunt *p);
int NombreEmprunt();
Bool TestLivre(Emprunt **premier,int COT);
Bool TestEmprunteur(Emprunt **premier,int id);
Emprunt* TransfererDonnees();
void EmprunterLivre(Emprunt **premier,livre *Li,inscrit *In);
void RendreLivres(Emprunt **premier,livre *Li,inscrit *In);
void Mise_A_Jour_Date();
void Mise_A_Jour_Emprunt(Emprunt *premier);
void Penalise(Emprunt *premier,inscrit *Ins);
void AfficherEmprunt(Emprunt *premier);
void Livre_Emprunte_0u_Non(Emprunt **Emp,livre *LiV);
void Emprunteur_0u_Non(Emprunt **Emp,inscrit *Ins);
void AffichePenalise(Emprunt *Emp,inscrit *In);
void AfficheLivresEmpt(Emprunt *Emp,livre *L);


#endif // EMPRUNT_H_INCLUDED
