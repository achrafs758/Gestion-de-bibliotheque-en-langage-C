#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "Structure.h"
#define tmax 300


void Conversion_En_Majuscule(char *CH){
    int i;
   for (i = 0; CH[i]!='\0'; i++) {
      if(CH[i] >= 'a' && CH[i] <= 'z') {
         CH[i] = CH[i] -32;
      }
   }
}

void RechercheCoteLivre(livre **premier){
    livre *p;
    p = *premier;
    int cot;
    Bool trouve=faux;
    printf("Saisir la cote du livre  :\n");
    scanf("%d",&cot);
    while (p != NULL){
        if(p->cote==cot){
            printf("\nResultat de la recherche :\n\n");
            printf("Cote | Titre                                    | Auteur                         |"
                    " Theme           | Edition | Prix(DH)\n");
            printf("**************************************************************************************"
                    "*********************************\n");
            printf("%-4d | %-40s | %-30s | %-15s | %-7d | %.2lf\n",p->cote,p->titre,p->auteur,
                    p->theme,p->edition,p->prix);
            trouve=vrai;
            break;
        }
        p = p->suiv;
    }
    if(trouve==faux)
        printf("\nCe livre ne se trouve pas dans la bibliotheque.\n");
    printf("\n\n");
}

void RechercheTitreLivre(livre **premier){
    livre *p;
    p = *premier;
    int compt=0;
    Bool trouve=faux;
    char Tit[40];
    printf("Saisir le Nom du livre :\n");
    gets(Tit);
    Conversion_En_Majuscule(Tit);
    while (p != NULL){
        if( strcmp(p->titre,Tit)==0 ){
            if(compt==0){
                printf("\nResultat de la recherche :\n\n");
                printf("Cote | Titre                                    | Auteur                         |"
                        " Theme           | Edition | Prix(DH)\n");
                printf("**************************************************************************************"
                       "*********************************\n");
            }
            printf("%-4d | %-40s | %-30s | %-15s | %-7d | %.2lf\n",p->cote,p->titre,p->auteur,
                    p->theme,p->edition,p->prix);
            trouve=vrai;
            compt++;
        }
        p = p->suiv;
    }
    if(trouve==faux)
        printf("\nAucun resultat ne correspond a ce titre.\n\n");
    printf("\n\n");
}

void RechercheAuteurLivre(livre **premier){
    livre *p;
    p = *premier;
    int compt=0;
    Bool trouve=faux;
    char aut[30];
    printf("Saisir l'auteur :\n");
    gets(aut);
    Conversion_En_Majuscule(aut);
    while (p != NULL){
        if( strcmp(p->auteur,aut)==0 ){
            if(compt==0){
                printf("\nResultat de la recherche :\n\n");
                printf("Cote | Titre                                    | Auteur                         |"
                        " Theme           | Edition | Prix(DH)\n");
                printf("**************************************************************************************"
                       "*********************************\n");
            }
            printf("%-4d | %-40s | %-30s | %-15s | %-7d | %.2lf\n",p->cote,p->titre,p->auteur,
                    p->theme,p->edition,p->prix);
            trouve=vrai;
            compt++;
        }
        p = p->suiv;
    }
    if(trouve==faux)
        printf("\nAucun resultat ne correspond a cet auteur.\n\n");
    printf("\n\n");
}

void RechercheThemeLivre(livre **premier){
    livre *p;
    p = *premier;
    int compt=0;
    Bool trouve=faux;
    char theme[20];
    printf("Saisir le theme du livre :\n");
    gets(theme);
    Conversion_En_Majuscule(theme);
    while (p != NULL){
        if( strcmp(p->theme,theme)==0 ){
            if(compt==0){
                printf("\nResultat de la recherche :\n\n");
                printf("Cote | Titre                                    | Auteur                         |"
                        " Theme           | Edition | Prix(DH)\n");
                printf("**************************************************************************************"
                       "*********************************\n");
            }
            printf("%-4d | %-40s | %-30s | %-15s | %-7d | %.2lf\n",p->cote,p->titre,p->auteur,
                    p->theme,p->edition,p->prix);
            trouve=vrai;
            compt++;
        }
        p = p->suiv;
    }
    if(trouve==faux)
        printf("\nAucun resultat ne correspond a ce theme.\n\n");
    printf("\n\n");
}


void RechercheEditionLivre(livre **premier){
    livre *p;
    p = *premier;
    int edi,compt=0;
    Bool trouve=faux;
    printf("Saisir l'annee d'edition du livre  :\n");
    scanf("%d",&edi);
    while (p != NULL){
        if(p->edition==edi){
            if(compt==0){
                printf("\nResultat de la recherche :\n\n");
                printf("Cote | Titre                                    | Auteur                         |"
                        " Theme           | Edition | Prix(DH)\n");
                printf("**************************************************************************************"
                       "*********************************\n");
            }
            printf("%-4d | %-40s | %-30s | %-15s | %-7d | %.2lf\n",p->cote,p->titre,p->auteur,
                    p->theme,p->edition,p->prix);
            trouve=vrai;
            compt++;
        }
        p = p->suiv;
    }
    if(trouve==faux)
        printf("\nAucun resultat ne correspond a cette annee.\n\n");
    printf("\n\n");
}

void RecherchePrixLivre(livre **premier){
    livre *p;
    p = *premier;
    int compt=0;
    double prix;
    Bool trouve=faux;
    printf("Saisir le prix du livre  :\n");
    scanf("%lf",&prix);
    while (p != NULL){
        if(p->prix==prix){
            if(compt==0){
                printf("\nResultat de la recherche :\n\n");
                printf("Cote | Titre                                    | Auteur                         |"
                        " Theme           | Edition | Prix(DH)\n");
                printf("**************************************************************************************"
                       "*********************************\n");
            }
            printf("%-4d | %-40s | %-30s | %-15s | %-7d | %.2lf\n",p->cote,p->titre,p->auteur,
                    p->theme,p->edition,p->prix);
            trouve=vrai;
            compt++;
        }
        p = p->suiv;
    }
    if(trouve==faux)
        printf("\nAucun resultat ne correspond a ce prix.\n\n");
    printf("\n\n");
}

void RechercheIDInscrit(inscrit **premier){
    inscrit *p;
    p = *premier;
    int ID;
    Bool trouve=faux;
    printf("Saisir L'ID de l'inscrit :\n");
    scanf("%d",&ID);
    while (p != NULL){
        if(p->id==ID){
            printf("\nResultat de la recherche :\n\n");
            printf("ID  | Nom                       | Prenom                    |"
                   " Adresse                             | Telephone\n");
            printf("******************************************************************************"
                   "********************************\n");
            printf("%-3d | %-25s | %-25s | %-35s | 0%ld\n",p->id,p->nom,p->prenom,p->adresse,p->tel);
            trouve=vrai;
            break;
        }
        p = p->suiv;
    }
    if(trouve==faux)
        printf("\nAucun inscrit ne porte l'ID saisie.\n\n");
    printf("\n\n");
}


void RechercheNomInscrit(inscrit **premier){
    inscrit *p;
    p = *premier;
    int compt=0;
    char nom[20];
    Bool trouve=faux;
    printf("Saisir Le nom :\n");
    gets(nom);
    Conversion_En_Majuscule(nom);
    while (p != NULL){
        if( strcmp(p->nom,nom)==0 ){
            if(compt==0){
                printf("\nResultat de la recherche :\n\n");
                printf("ID  | Nom                       | Prenom                    |"
                   " Adresse                             | Telephone\n");
                printf("******************************************************************************"
                   "********************************\n");
            }
            printf("%-3d | %-25s | %-25s | %-35s | 0%ld\n",p->id,p->nom,p->prenom,p->adresse,p->tel);
            trouve=vrai;
            compt++;
        }
        p = p->suiv;
    }
    if(trouve==faux)
        printf("\nAucun resultat ne correspond a ce nom.\n\n");
    printf("\n\n");
}

int NombreLivres(){
    FILE *fichier;
    int Nb_Livres=0;
    char CH[500];
    fichier = fopen("Livres.txt","r");
    if (fichier==NULL){
        printf("\nLe fichier n'existe pas !\n");
        exit(-1);
    }
    while(fgets(CH,500,fichier)!=NULL)
    {
            Nb_Livres++;
    }
    fclose(fichier);
    return Nb_Livres;
}

void AfficheTabLivres(livre T[],int n){
    int i;
    printf("Cote | Titre                                    | Auteur                         |"
            " Theme           | Edition | Prix(DH)\n");
    printf("**************************************************************************************"
            "********************************\n");
    for(i=0;i<n;i++){
        Conversion_En_Majuscule(T[i].titre);
        Conversion_En_Majuscule(T[i].auteur);
        Conversion_En_Majuscule(T[i].theme);
        printf("%-4d | %-40s | %-30s | %-15s | %-7d | %.2lf\n",T[i].cote,T[i].titre,T[i].auteur,
                T[i].theme,T[i].edition,T[i].prix);
    }
}

void EnregistrerModificationLivres(livre T[],int n){
    char reponse,fich[35];
    int i;
    printf("\n\nVoulez-vous enregistrer les modification ? (O ou o:Oui autre caractere:Non) : ");
    scanf(" %c",&reponse);
    getchar();
    printf("\n\n");
    if(reponse=='O' || reponse=='o'){
        FILE *f=NULL;
        printf("\tNom du fichier : ");
        gets(fich);
        f=fopen(fich,"w");
        for(i=0;i<n;i++){
        fprintf(f,"%d|%s|%s|%s|%d|%.2lf\n",T[i].cote,T[i].titre,T[i].auteur,T[i].theme,T[i].edition,
                   T[i].prix);
        }

        fclose(f);
    }
}

void StockerLivresEnTab(livre T[],int n){
    int i;  //n est le nombre des livre de la liste
    FILE *f=NULL;
    f = fopen("Livres.txt", "r");
    if (f==NULL)
        printf("\nLe fichier n'existe pas !\n");
    for(i=0;i<n;i++)
        fscanf(f,"%d|%[^|]|%[^|]|%[^|]|%d|%lf\n",&T[i].cote,T[i].titre,T[i].auteur,T[i].theme,&T[i].edition,
               &T[i].prix);

    fclose(f);
}

void TrierCoteLivres(){
    int n,i,j;
    livre Tab[tmax],tmp;
    n=NombreLivres();
    StockerLivresEnTab(Tab,n);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++)
        if(Tab[i].cote > Tab[j].cote){
            tmp = Tab[i];
            Tab[i] = Tab[j];
            Tab[j] = tmp;
        }
    }
    AfficheTabLivres(Tab,n);
    EnregistrerModificationLivres(Tab,n);
}

void TrierTitreLivres(){
    int n,i,j;
    livre Tab[tmax],tmp;
    n=NombreLivres();
    StockerLivresEnTab(Tab,n);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++)
        if(strcmp(Tab[i].titre,Tab[j].titre) > 0){
            tmp = Tab[i];
            Tab[i] = Tab[j];
            Tab[j] = tmp;
        }
    }
    AfficheTabLivres(Tab,n);
    EnregistrerModificationLivres(Tab,n);
}

void TrierAuteurLivres(){
    int n,i,j;
    livre Tab[tmax],tmp;
    n=NombreLivres();
    StockerLivresEnTab(Tab,n);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++)
        if(strcmp(Tab[i].auteur,Tab[j].auteur) > 0){
            tmp = Tab[i];
            Tab[i] = Tab[j];
            Tab[j] = tmp;
        }
    }
    AfficheTabLivres(Tab,n);
    EnregistrerModificationLivres(Tab,n);
}

void TrierThemeLivres(){
    int n,i,j;
    livre Tab[tmax],tmp;
    n=NombreLivres();
    StockerLivresEnTab(Tab,n);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++)
        if(strcmp(Tab[i].theme,Tab[j].theme) > 0){
            tmp = Tab[i];
            Tab[i] = Tab[j];
            Tab[j] = tmp;
        }
    }
    AfficheTabLivres(Tab,n);
    EnregistrerModificationLivres(Tab,n);
}

void TrierEditionLivres(){
    int n,i,j;
    livre Tab[tmax],tmp;
    n=NombreLivres();
    StockerLivresEnTab(Tab,n);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++)
        if(Tab[i].edition < Tab[j].edition){
            tmp = Tab[i];
            Tab[i] = Tab[j];
            Tab[j] = tmp;
        }
    }
    AfficheTabLivres(Tab,n);
    EnregistrerModificationLivres(Tab,n);
}

void TrierPrixLivres(){
    int n,i,j;
    livre Tab[tmax],tmp;
    n=NombreLivres();
    StockerLivresEnTab(Tab,n);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++)
        if(Tab[i].prix < Tab[j].prix){
            tmp = Tab[i];
            Tab[i] = Tab[j];
            Tab[j] = tmp;
        }
    }
    AfficheTabLivres(Tab,n);
    EnregistrerModificationLivres(Tab,n);
}

int NombreInscrits(){
    FILE *fichier;
    int Nb_Inscrits=0;
    char CH[500];
    fichier = fopen("Inscrits.txt","r");
    if (fichier==NULL){
        printf("\nLe fichier n'existe pas !\n");
        exit(-1);
    }
    while(fgets(CH,500,fichier)!=NULL)
    {
            Nb_Inscrits++;
    }
    fclose(fichier);
    return Nb_Inscrits;
}

void AfficheTabInscrits(inscrit T[],int n){
    int i;
    printf("ID  | Nom                       | Prenom                    |"
            " Adresse                             | Telephone\n");
    printf("******************************************************************************"
            "********************************\n");
    for(i=0;i<n;i++){
        printf("%-3d | %-25s | %-25s | %-35s | 0%ld\n",T[i].id,T[i].nom,T[i].prenom,T[i].adresse,T[i].tel);
    }
}

void EnregistrerModificationInscrits(inscrit T[],int n){
    char reponse,fich[35];
    int i;
    printf("\n\nVoulez-vous enregistrer les modification ? (O ou o:Oui autre caractere:Non) : ");
    scanf(" %c",&reponse);
    getchar();
    printf("\n\n");
    if(reponse=='O' || reponse=='o'){
        FILE *f=NULL;
        printf("\tNom du fichier : ");
        gets(fich);
        f=fopen(fich,"w");
        for(i=0;i<n;i++)
            fprintf(f,"%d|%s|%s|%s|%ld\n",T[i].id,T[i].nom,T[i].prenom,T[i].adresse,T[i].tel);
        fclose(f);
    }
}

void StockerInscritsEnTab(inscrit T[],int n){
    int i;  //n est le nombre des livre de la liste
    FILE *f=NULL;
    f = fopen("Inscrits.txt", "r");
    if (f==NULL)
        printf("\nLe fichier n'existe pas !\n");
    for(i=0;i<n;i++)
        fscanf(f,"%d|%[^|]|%[^|]|%[^|]|%ld\n",&T[i].id,T[i].nom,T[i].prenom,T[i].adresse,&T[i].tel);
    fclose(f);
}

void TrierIDInscrits(){
    int n,i,j;
    inscrit Tab[tmax],tmp;
    n=NombreInscrits();
    StockerInscritsEnTab(Tab,n);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++)
        if(Tab[i].id > Tab[j].id){
            tmp = Tab[i];
            Tab[i] = Tab[j];
            Tab[j] = tmp;
        }
    }
    AfficheTabInscrits(Tab,n);
    EnregistrerModificationInscrits(Tab,n);
}

void TrierNomInscrits(){
    int n,i,j;
    inscrit Tab[tmax],tmp;
    n= NombreInscrits();
    StockerInscritsEnTab(Tab,n);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++)
        if(strcmp(Tab[i].nom,Tab[j].nom) > 0){
            tmp = Tab[i];
            Tab[i] = Tab[j];
            Tab[j] = tmp;
        }
    }
    AfficheTabInscrits(Tab,n);
    EnregistrerModificationInscrits(Tab,n);
}

