#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "Structure.h"
#include "Rech_Tri_Livres_Inscrits.h"


void AfficherInscrits(inscrit *premier){
    inscrit *p;
    p = premier;
    printf("ID  |          Nom              |            Prenom         |              Adresse                |"
           " Telephone\n");
    printf("***************************************************************************************************"
           "***********\n");
    do {
        printf("%-3d | %-25s | %-25s | %-35s | 0%ld\n",p->id,p->nom,p->prenom,p->adresse,p->tel);
        p = p->suiv;
    }
    while (p != NULL);
    printf ("\n");
}

Bool VerificationID(inscrit *premier,int ID){
    inscrit *p;
    p=premier;
    while(p!=NULL){
        if(p->id==ID)
            return vrai;
        p=p->suiv;
    }
    return faux;
}

void AjouterInscrits(inscrit *premier){
    inscrit ins,*p;
    p = premier;
    FILE *liste= NULL;
    printf("Saisie de l'etiquette de l'inscrit :\n");
    do{
        printf("\tID  (il faut Saisir un ID qui n'est pas attribuer a un autre inscrit): ");
        scanf("%d",&ins.id);

    }while(VerificationID(p,ins.id)==vrai);
    getchar();
    printf("\tNom : ");
    gets(ins.nom);
    Conversion_En_Majuscule(ins.nom);
    printf("\tPrenom : ");
    gets(ins.prenom);
    Conversion_En_Majuscule(ins.prenom);
    printf("\tAdresse : ");
    gets(ins.adresse);
    Conversion_En_Majuscule(ins.adresse);
    printf("\tTelephone: ");
    scanf("%ld",&ins.tel);
    getchar();
    liste=fopen("Inscrits.txt","a");
    if(liste==NULL)
        printf("\nLe Fichier n'existe pas !!\n");
    fprintf(liste,"%d|%s|%s|%s|%ld\n",ins.id,ins.nom,ins.prenom,ins.adresse,ins.tel);
    fclose(liste);
}

void SupprimerInscrits(inscrit *premier){
    FILE *f1=NULL,*f2=NULL;
    inscrit *p,ins;
    int ID;
    p=premier;
    printf("\nSaisir l'ID de l'inscrit qui veut desinscrire (il faut Saisir un ID qui existe deja): \n");
    do{
        printf("\tID: ");
        scanf("%d",&ID);

    }while(VerificationID(p,ID)==faux);
    getchar();
    f1 = fopen("Inscrits.txt","r");
    if (f1==NULL)
        printf("\nLe fichier n'existe pas !\n");
    f2 = fopen("InscritsTemp.txt","a");
    while(!feof(f1)){
        fscanf(f1,"%d|%[^|]|%[^|]|%[^|]|%ld\n",&ins.id,ins.nom,ins.prenom,ins.adresse,&ins.tel);
        if(ins.id!=ID)
            fprintf(f2,"%d|%s|%s|%s|%ld\n",ins.id,ins.nom,ins.prenom,ins.adresse,ins.tel);
    }
    fclose(f1);
    fclose(f2);
    remove("Inscrits.txt");
    rename("InscritsTemp.txt","Inscrits.txt");
    printf("\nLa suppression est faite avec succes.\n\n");
}

inscrit* TransfererInscrits(){
    int i,n;  //n est le nombre des inscrits de la liste
    FILE *f=NULL;
    inscrit *p,*premier;
    n=NombreInscrits(f);
    f = fopen("Inscrits.txt", "r");
    if (f==NULL)
        printf("\nLe fichier n'existe pas !\n");
    for(i=0;i<n;i++){
        if(i==0){
            premier = (inscrit*)malloc(sizeof(inscrit));
            p=premier;
        }
        else{
            p->suiv=(inscrit*)malloc(sizeof(inscrit));
            p=p->suiv;
        }
        fscanf(f,"%d|%[^|]|%[^|]|%[^|]|%ld\n",&p->id,p->nom,p->prenom,p->adresse,&p->tel);
    }
    fclose(f);
    p->suiv=NULL;
    return premier;
}

void ModifierAdresse(inscrit **premier,int ID){
    inscrit *p;
    p=*premier;
    while(p!=NULL){
        if(p->id==ID){
            printf("Saisir la nouvelle adresse :\n");
            gets(p->adresse);
            Conversion_En_Majuscule(p->adresse);
            break;
        }
        p=p->suiv;
    }
}

void ModifierTele(inscrit **premier,int ID){
    inscrit *p;
    p=*premier;
    while(p!=NULL){
        if(p->id==ID){
            printf("Saisir le nouveau numero de telephone :\n");
            scanf("%ld",&p->tel);
            getchar();
            break;
        }
        p=p->suiv;
    }
}

void ModifierInscrits(inscrit **premier){
    int ID;
    char reponse;
    inscrit *p;
    p=*premier;
    printf("\nSaisir l'ID de l'inscrit (il faut Saisir un ID qui existe deja): \n");
    do{
        printf("\tID : ");
        scanf("%d",&ID);

    }while(VerificationID(p,ID)==faux);
    getchar();
    printf("Voulez-vous modifier l'adresse de l'inscrit ? (O ou o:Oui autre caractere:Non) : ");
    scanf(" %c",&reponse);
    getchar();
        if(reponse=='O' || reponse=='o')
            ModifierAdresse(&*premier,ID);
        printf("Voulez-vous modifier le numero de telephone de l'inscrit ? (O ou o:Oui autre caractere:Non) : ");
        scanf(" %c",&reponse);
        getchar();
        if(reponse=='O' || reponse=='o')
            ModifierTele(&*premier,ID);
        printf("Voulez-vous enregistrer les modification ? (O ou o:Oui autre caractere:Non) : ");
        scanf(" %c",&reponse);
        getchar();
        if(reponse=='O' || reponse=='o'){
            FILE *f=NULL;
            f=fopen("Inscrits.txt","w");
            inscrit *q;
            q = *premier;
            printf ("\n");
            while (q != NULL) {
                fprintf(f,"%d|%s|%s|%s|%ld\n",q->id,q->nom,q->prenom,q->adresse,q->tel);
                q = q->suiv;
            }
            fclose(f);
        }
}


void RechercherInscrit(inscrit **premier){
    int choix;
    inscrit *q;
    q=*premier;
    printf("\n 1 : Rechercher un inscrit par son ID."
           "\n 2 : Rechercher un inscrit par son Nom.\n\n");
    printf("\tSaisir Votre choix : ");
    scanf("%d",&choix);
    getchar();
    system("cls");
    switch(choix){
        case 1: RechercheIDInscrit(&q);
                system("pause");
                system("cls");
                break;
        case 2: RechercheNomInscrit(&q);
                system("pause");
                system("cls");
                break;
        default: printf("\nChoix invalide !!\n\n");
                 system("pause");
                 system("cls");
                 break;
    }
}

void TrierInscrits(){
    int choix;
    printf("\n 1 : Trier les inscrits de la bibliotheque par ID (ordre croissant)."
           "\n 2 : Trier les inscrits de la bibliotheque par nom.\n\n");
    printf("\tSaisir Votre choix : ");
    scanf("%d",&choix);
    getchar();
    system("cls");
    switch(choix){
        case 1: TrierIDInscrits();
                system("pause");
                system("cls");
                break;
        case 2: TrierNomInscrits();
                system("pause");
                system("cls");
                break;
        default: printf("\nChoix invalide !!\n\n");
                 system("pause");
                 system("cls");
                 break;
    }
}

