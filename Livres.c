#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "Structure.h"
#include "Rech_Tri_Livres_Inscrits.h"

void AfficherLivres(livre *premier){
    livre *p;
    p = premier;
    printf("Cote | Titre                                    | Auteur                         |"
            " Theme           | Edition | Prix(DH)\n");
    printf("**************************************************************************************"
            "*********************************\n");
    do {
        printf("%-4d | %-40s | %-30s | %-15s | %-7d | %.2lf\n",p->cote,p->titre,p->auteur,p->theme,p->edition,p->prix);
        p = p->suiv;
    }
    while (p != NULL);
    printf ("\n");
}


Bool VerificationCote(livre *premier,int COT){
    livre *p;
    p=premier;
    while(p!=NULL){
        if(p->cote==COT)
            return vrai;
        p=p->suiv;
    }
    return faux;
}

void AjouterLivre(livre *premier){
    livre lvr,*p;
    p=premier;
    FILE *liste= NULL;
    printf("Saisie de l'etiquette du livre :\n");
    do{
        printf("\tCote (il faut Saisir une cote qui n'est pas attribuer a aucun livre): ");
        scanf("%d",&lvr.cote);

    }while(VerificationCote(p,lvr.cote)==vrai);
    getchar();
    printf("\tTitre: ");
    gets(lvr.titre);
    Conversion_En_Majuscule(lvr.titre);
    printf("\tAuteur: ");
    gets(lvr.auteur);
    Conversion_En_Majuscule(lvr.auteur);
    printf("\tTheme: ");
    gets(lvr.theme);
    Conversion_En_Majuscule(lvr.theme);
    printf("\tAnnee d'edition: ");
    scanf("%d",&lvr.edition);
    getchar();
    printf("\tPrix: ");
    scanf("%lf",&lvr.prix);
    liste=fopen("Livres.txt","a");
    if(liste==NULL)
        printf("\nLe Fichier n'existe pas !!\n");
    fprintf(liste,"%d|%s|%s|%s|%d|%.2lf\n",lvr.cote,lvr.titre,lvr.auteur,lvr.theme,lvr.edition,lvr.prix);
    fclose(liste);
}

void SupprimerLivres(livre *premier){
    FILE *f1=NULL,*f2=NULL;
    livre lvr,*p;
    int COT;
    p=premier;
    printf("\nSaisir la cote du livre que vous voulez supprimer (il faut Saisir une cote qui existe deja): \n");
    do{
        printf("\tCote : ");
        scanf("%d",&COT);

    }while(VerificationCote(p,COT)==faux);
    getchar();
    f1 = fopen("Livres.txt","r");
    if (f1==NULL)
        printf("\nLe fichier n'existe pas !\n");
    f2 = fopen("LivreTemp.txt","a");
    while(!feof(f1)){
        fscanf(f1,"%d|%[^|]|%[^|]|%[^|]|%d|%lf\n",&lvr.cote,lvr.titre,lvr.auteur,lvr.theme,&lvr.edition,&lvr.prix);
        if(lvr.cote!=COT)
            fprintf(f2,"%d|%s|%s|%s|%d|%.2lf\n",lvr.cote,lvr.titre,lvr.auteur,lvr.theme,lvr.edition,lvr.prix);
    }
    fclose(f1);
    fclose(f2);
    remove("Livres.txt");
    rename("LivreTemp.txt","Livres.txt");
    printf("\nLa suppression est faite avec succes.\n\n");
}

livre* TransfererLivres(){
    int i,n;  //n est le nombre des livre de la bibliotheque
    FILE *f=NULL;
    livre *premier; //pointeur sur le premier livre
    livre *p;
    n=NombreLivres();
    f = fopen("Livres.txt", "r");
    if (f==NULL)
        printf("\nLe fichier n'existe pas !\n");
    for(i=0;i<n;i++){
        if(i==0){
            premier = (livre*)malloc(sizeof(livre));
            p=premier;
        }
        else{
            p->suiv=(livre*)malloc(sizeof(livre));
            p=p->suiv;
        }
        fscanf(f,"%d|%[^|]|%[^|]|%[^|]|%d|%lf\n",&p->cote,p->titre,p->auteur,p->theme,&p->edition,&p->prix);
        Conversion_En_Majuscule(p->titre);
        Conversion_En_Majuscule(p->auteur);
        Conversion_En_Majuscule(p->theme);
    }
    fclose(f);
    p->suiv=NULL;
    return premier;
}

void RechercherLivre(livre **premier){
    int choix;
    livre *q;
    q=*premier;
    printf("\n 1 : Rechercher un livre par sa cote."
           "\n 2 : Rechercher un livre par son titre."
           "\n 3 : Rechercher un livre par nom de l'auteur."
           "\n 4 : Rechercher un livre par theme."
           "\n 5 : Rechercher un livre par annee d'edition."
           "\n 6 : Rechercher un livre par prix.\n\n");
    printf("\tSaisir Votre choix : ");
    scanf("%d",&choix);
    getchar();
    system("cls");
    switch(choix){
        case 1: RechercheCoteLivre(&q);
                system("pause");
                system("cls");
                break;
        case 2: RechercheTitreLivre(&q);
                system("pause");
                system("cls");
                break;
        case 3: RechercheAuteurLivre(&q);
                system("pause");
                system("cls");
                break;
        case 4: RechercheThemeLivre(&q);
                system("pause");
                system("cls");
                break;
        case 5: RechercheEditionLivre(&q);
                system("pause");
                system("cls");
                break;
        case 6: RecherchePrixLivre(&q);
                system("pause");
                system("cls");
                break;
        default: printf("\nChoix invalide !!\n\n");
                 system("pause");
                 system("cls");
                 break;
    }
}

void ModifierTitre(livre **premier,int COT){
    livre *p;
    p=*premier;
    while(p!=NULL){
        if(p->cote==COT){
            printf("Saisir le nouveau titre :\n");
            gets(p->titre);
            Conversion_En_Majuscule(p->titre);
            break;
        }
        p=p->suiv;
    }
}

void ModifierAuteur(livre **premier,int COT){
    livre *p;
    p=*premier;
    while(p!=NULL){
        if(p->cote==COT){
            printf("Saisir le nouveau auteur :\n");
            gets(p->auteur);
            Conversion_En_Majuscule(p->auteur);
            break;
        }
        p=p->suiv;
    }
}

void ModifierTheme(livre **premier,int COT){
    livre *p;
    p=*premier;
    while(p!=NULL){
        if(p->cote==COT){
            printf("Saisir le nouveau theme :\n");
            gets(p->theme);
            Conversion_En_Majuscule(p->theme);
            break;
        }
        p=p->suiv;
    }
}

void ModifierEdition(livre **premier,int COT){
    livre *p;
    p=*premier;
    while(p!=NULL){
        if(p->cote==COT){
            printf("Saisir la nouvelle annee d'edition :\n");
            scanf("%d",&p->edition);
            getchar();
            break;
        }
        p=p->suiv;
    }
}

void ModifierPrix(livre **premier,int COT){
    livre *p;
    p=*premier;
    while(p!=NULL){
        if(p->cote==COT){
            printf("Saisir le nouveau prix :\n");
            scanf("%lf",&p->prix);
            getchar();
            break;
        }
        p=p->suiv;
    }
}

void ModifierLivre(livre **premier){
    int COT,test=0;
    char reponse;
    livre *p;
    p=*premier;
    printf("Saisir la cote du livre a modifier :\n");
    do{
        printf("\tCote : ");
        scanf("%d",&COT);

    }while(VerificationCote(p,COT)==faux);
    getchar();
    test=VerificationCote(*premier,COT);
    if(test==0)
        printf("\nAucun livre ne correspond a la cote saisie !\n\n");
    else{
        printf("Voulez-vous modifier le titre du livre ? (O ou o:Oui autre caractere:Non) : ");
        scanf(" %c",&reponse);
        getchar();
        if(reponse=='O' || reponse=='o')
            ModifierTitre(&*premier,COT);
        printf("Voulez-vous modifier l'auteur du livre ? (O ou o:Oui autre caractere:Non) : ");
        scanf(" %c",&reponse);
        getchar();
        if(reponse=='O' || reponse=='o')
            ModifierAuteur(&*premier,COT);
        printf("Voulez-vous modifier le theme du livre ? (O ou o:Oui autre caractere:Non) : ");
        scanf(" %c",&reponse);
        getchar();
        if(reponse=='O' || reponse=='o')
            ModifierTheme(&*premier,COT);
        printf("Voulez-vous modifier l'annee d'edition du livre ? (O ou o:Oui autre caractere:Non) : ");
        scanf(" %c",&reponse);
        getchar();
        if(reponse=='O' || reponse=='o')
            ModifierEdition(&*premier,COT);
        printf("Voulez-vous modifier le prix du livre ? (O ou o:Oui autre caractere:Non) : ");
        scanf(" %c",&reponse);
        getchar();
        if(reponse=='O' || reponse=='o')
            ModifierPrix(&*premier,COT);
        printf("Voulez-vous enregistrer les modification ? (O ou o:Oui autre caractere:Non) : ");
        scanf(" %c",&reponse);
        getchar();
        if(reponse=='O' || reponse=='o'){
            FILE *f=NULL;
            f=fopen("Livres.txt","w");
            livre *q;
            q = *premier;
            printf ("\n");
            while (q != NULL) {
                fprintf(f,"%d|%s|%s|%s|%d|%.2lf\n",q->cote,q->titre,q->auteur,q->theme,q->edition,q->prix);
                q = q->suiv;
            }
            fclose(f);
        }
    }
}

void TrierLivre(){
    int choix;
    printf("\n 1 : Trier les livres de la bibliotheque par cote (ordre croissant)."
           "\n 2 : Trier les livres de la bibliotheque par titre."
           "\n 3 : Trier les livres de la bibliotheque par nom de l'auteur."
           "\n 4 : Trier les livres de la bibliotheque par theme."
           "\n 5 : Trier les livres de la bibliotheque par annee d'edition (ordre decroissant)."
           "\n 6 : Trier les livres de la bibliotheque par prix (ordre decroissant).\n\n");
    printf("\tSaisir Votre choix : ");
    scanf("%d",&choix);
    getchar();
    system("cls");
    switch(choix){
        case 1: TrierCoteLivres();
                system("pause");
                system("cls");
                break;
        case 2: TrierTitreLivres();
                system("pause");
                system("cls");
                break;
        case 3: TrierAuteurLivres();
                system("pause");
                system("cls");
                break;
        case 4: TrierThemeLivres();
                system("pause");
                system("cls");
                break;
        case 5: TrierEditionLivres();
                system("pause");
                system("cls");
                break;
        case 6: TrierPrixLivres();
                system("pause");
                system("cls");
                break;
        default: printf("\nChoix invalide !!\n\n");
                 system("pause");
                 system("cls");
                 break;
    }
}

int Nb_copies(livre **premier){
    livre *p;
    p = *premier;
    int NbCopie=0;
    char Titre[40];
    printf("Saisir le titre du livre :\n");
    gets(Titre);
    Conversion_En_Majuscule(Titre);
    while (p != NULL){
        if( strcmp(p->titre,Titre)==0 )
             NbCopie++;
        p=p->suiv;
    }
    return NbCopie;
}
