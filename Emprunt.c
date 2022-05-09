#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Structure.h"
#include "Livres.h"
#include "Inscrits.h"



void Conversion_En_Jour(unsigned long *s){
    *s=(*s/86400); // 1 jour = 86400 secondes
}

unsigned long Difference_Date(Emprunt *p)
{
    time_t today;
    struct tm Date_Retour;
    Date_Retour.tm_mday = p->retour.jour;   /* jour */
    Date_Retour.tm_mon  = (p->retour.mois)-1;   /* mois (le premier mois est 0 et le dernier est 11) */
    Date_Retour.tm_year = (p->retour.annee)-1900; /* Origine des années dans cette struct est par defaut 1990 */
    Date_Retour.tm_hour = 0;   /* 0 heure            */
    Date_Retour.tm_min  = 0;   /* 0 minute           */
    Date_Retour.tm_sec  = 0;   /* 0 seconde          */
    today = time(NULL);
    unsigned long secondes = (unsigned long) difftime(today, mktime(&Date_Retour));
    Conversion_En_Jour(&secondes);
    return secondes;
}

int NombreEmprunt(){
    FILE *fichier=NULL;
    int Nb_Emprunt=0;
    char CH[500];
    fichier = fopen("Emprunt.txt","r");
    if (fichier==NULL){
        printf("\nLe fichier n'existe pas !\n");
        EXIT_FAILURE;
    }
    while(fgets(CH,500,fichier)!=NULL)
    {
            Nb_Emprunt++;
    }
    fclose(fichier);
    return Nb_Emprunt;
}

Bool TestLivre(Emprunt **premier,int COT){
    Emprunt *p;
    p=*premier;
    while(p!=NULL){
        if(p->COTE==COT)
            return vrai;
        p=p->suiv;
    }
    return faux;
}

Bool TestEmprunteur(Emprunt **premier,int id){
    Emprunt *p;
    p=*premier;
    while(p!=NULL){
        if(p->ID==id)
            return vrai;
        p=p->suiv;
    }
    return faux;
}

Emprunt* TransfererDonnees(){
    int i,n;
    FILE *f=NULL;
    Emprunt *premier; //pointeur sur la premire ligne du fichier "Emprunt.txt"
    Emprunt *p;
    n=NombreEmprunt();
    f = fopen("Emprunt.txt", "r");
    if (f==NULL)
        printf("\nLe fichier n'existe pas !\n");
    for(i=0;i<n;i++){
        if(i==0){
            premier = (Emprunt*)malloc(sizeof(Emprunt));
            p=premier;
        }
        else{
            p->suiv=(Emprunt*)malloc(sizeof(Emprunt));
            p=p->suiv;
        }
        fscanf(f,"%d|%d|%d/%d/%d|%d/%d/%d|%d\n",&p->COTE,&p->ID,&p->emprunt.jour,&p->emprunt.mois,
               &p->emprunt.annee,&p->retour.jour,&p->retour.mois,&p->retour.annee,&p->penalite);
    }
    fclose(f);
    p->suiv=NULL;
    return premier;
}

void EmprunterLivre(Emprunt **premier,livre *Li,inscrit *In){
    Emprunt E,*q;
    q=*premier;
    FILE *liste= NULL,*f=NULL;
    printf("Saisir la cote du livre a emprunter (Il faut Saisir une cote qui existe deja dans la bibliotheque):\n");
    do{
        printf("\tCote : ");
        scanf("%d",&E.COTE);

    }while(VerificationCote(Li,E.COTE)==faux);
    getchar();
    if(TestLivre(&q,E.COTE)==vrai)
        printf("\nCe livre est deja emprunter.\n");
    else{
        printf("Saisir l'ID de l'emprunteur: \n");
        do{
            printf("\tID: ");
            scanf("%d",&E.ID);

        }while(VerificationID(In,E.ID)==faux);
        getchar();
        if(TestEmprunteur(&q,E.ID)==vrai)
            printf("\nCette personne a deja emprunter un livre.\n");
        else{
            f = fopen("date.txt", "r");
            if (f==NULL)
                printf("\nLe fichier n'existe pas !\n");
            fscanf(f,"%d/%d/%d\n",&E.emprunt.jour,&E.emprunt.mois,&E.emprunt.annee);
            fclose(f);
            printf("Saisir la date du retour du livre :\n");
            printf("\tJour : ");
            scanf("%d",&E.retour.jour);
            printf("\tMois : ");
            scanf("%d",&E.retour.mois);
            printf("\tAnnee : ");
            scanf("%d",&E.retour.annee);
            E.penalite=0;
            liste=fopen("Emprunt.txt","a");
            if(liste==NULL)
                printf("\nLe Fichier n'existe pas !!\n");
            fprintf(liste,"%d|%d|%d/%d/%d|%d/%d/%d|%d\n",E.COTE,E.ID,E.emprunt.jour,E.emprunt.mois,
               E.emprunt.annee,E.retour.jour,E.retour.mois,E.retour.annee,E.penalite);
            fclose(liste);
        }
    }
}

void RendreLivres(Emprunt **premier,livre *Li,inscrit *In){
    Emprunt E,*q;
    int cot,id;
    FILE *f1=NULL,*f2=NULL;
    q=*premier;
    printf("\nSaisir la cote du livre a rendre :\n ");
    do{
        printf("\tCote : ");
        scanf("%d",&cot);

    }while(VerificationCote(Li,cot)==faux);
    if(TestLivre(&q,cot)==faux)
        printf("\nCe livre n'est meme emprunter pour le rendre.\n");
    else{
        printf("Saisir l'ID de l'emprunteur: \n");
        do{
            printf("\tID: ");
            scanf("%d",&id);

        }while(VerificationID(In,id)==faux);
        getchar();
        if(TestEmprunteur(&q,id)==faux)
            printf("\nCette personne n'a emprunter aucun livre.\n");
            else{
                f1 = fopen("Emprunt.txt","r");
                if (f1==NULL)
                    printf("\nLe fichier n'existe pas !\n");
                f2 = fopen("EmpruntTemp.txt","a");
                while(!feof(f1)){
                    fscanf(f1,"%d|%d|%d/%d/%d|%d/%d/%d|%d\n",&E.COTE,&E.ID,&E.emprunt.jour,&E.emprunt.mois,
                            &E.emprunt.annee,&E.retour.jour,&E.retour.mois,&E.retour.annee,&E.penalite);
                    if(cot!=E.COTE || id!=E.ID)
                        fprintf(f2,"%d|%d|%d/%d/%d|%d/%d/%d|%d\n",E.COTE,E.ID,E.emprunt.jour,E.emprunt.mois,
                       E.emprunt.annee,E.retour.jour,E.retour.mois,E.retour.annee,E.penalite);
                }
                fclose(f1);
                fclose(f2);
                remove("Emprunt.txt");
                rename("EmpruntTemp.txt","Emprunt.txt");
                printf("\nL'opperation est faite avec succes.\n\n");
            }
    }
}

void Mise_A_Jour_Date(){
    FILE *f=NULL;
    char date[20];
    time_t timestamp = time(NULL);
    strftime(date, sizeof(date), "%d/%m/%Y", localtime(&timestamp));
    f = fopen("date.txt","w");
    fputs(date,f);
    fclose(f);
}

void Mise_A_Jour_Emprunt(Emprunt *premier){
    FILE *f;
    Emprunt *q;
    unsigned long DCR;
    q = premier;
    f = fopen("EMP.txt","a");
    while (q != NULL){
        DCR=Difference_Date(q);
        if(DCR > 0 && DCR <= 30){
            q->penalite=2*DCR;
        }
        fprintf(f,"%d|%d|%d/%d/%d|%d/%d/%d|%d\n",q->COTE,q->ID,q->emprunt.jour,q->emprunt.mois,
                       q->emprunt.annee,q->retour.jour,q->retour.mois,q->retour.annee,q->penalite);
        q=q->suiv;
    }
    fclose(f);
    remove("Emprunt.txt");
    rename("EMP.txt","Emprunt.txt");
}

void Penalise(Emprunt *premier,inscrit *Ins){
    Emprunt *p=NULL;
    int identifiant;
    Bool PENA=faux;
    p = premier;
    printf("Saisir l'ID de l'emprunteur : \n");
    do{
        printf("\tID : ");
        scanf("%d",&identifiant);

    }while(VerificationID(Ins,identifiant)==faux);
    if(TestEmprunteur(&p,identifiant)==faux)
        printf("\nCette personne n'a emprunter aucun livre.\n");
    else{
                while (p != NULL){
                    if((p->ID) == identifiant && (p->penalite)!=0 && PENA==faux){
                        printf("\nL'Emprunteur est penalise.\n");
                    printf("\nIl doit payer %d DH.\n\n",p->penalite);
                    PENA=vrai;
                    }
                    p=p->suiv;
                }
                if(PENA==faux)
                    printf("\nL'Emprunteur n'est pas penalise.\n");
        }
}

void AfficherEmprunt(Emprunt *premier){
    Emprunt *p;
    p = premier;
    printf("Cote du livre | Emprunter par | Date d'emprunt | Date de retour | Penalite\n");
    printf("**************************************************************************\n");
    do {
        printf("%-13d | %-13d | %2d/%2d/%d     | %2d/%2d/%d     | %d\n",p->COTE,p->ID,p->emprunt.jour,p->emprunt.mois,
               p->emprunt.annee,p->retour.jour,p->retour.mois,p->retour.annee,p->penalite);
        p = p->suiv;
    }
    while (p != NULL);
    printf ("\n");
}

void Livre_Emprunte_0u_Non(Emprunt **Emp,livre *LiV){
    int cot;
    printf("\nSaisir la cote du livre :\n ");
    do{
        printf("\tCote : ");
        scanf("%d",&cot);

    }while(VerificationCote(LiV,cot)==faux);
    if(TestLivre(&*Emp,cot)==faux)
        printf("\nCe livre n'est pas emprunte.\n");
    else
        printf("\nCe livre est emprunte. \n");
}

void Emprunteur_0u_Non(Emprunt **Emp,inscrit *Ins){
    int ID;
    printf("Saisir l'ID de l'emprunteur: \n");
    do{
        printf("\tID: ");
        scanf("%d",&ID);

    }while(VerificationID(Ins,ID)==faux);
    if(TestEmprunteur(&*Emp,ID)==faux)
        printf("\nCette personne n'a emprunter aucun livre.\n");
    else
        printf("\nCette personne a emprunter un livre de la bibliotheque.\n");
}

void AffichePenalise(Emprunt *Emp,inscrit *In){
    inscrit *p;
    Emprunt *q;
    int id=0,cpt=0;
    Bool TrouvePena=faux;
    q = Emp;
    while (q != NULL){
        if( q->penalite >= 2)
            id=q->ID;
        p = In;
        while (p != NULL){
            if( p->id==id ){
                if(cpt==0){
                    printf("ID  | Nom                    | Prenom                 |"
                           " Adresse                          | Telephone  | Penalite(DH)\n");
                    printf("*****************************************************************************"
                       "***************************************\n");
                }
                printf("%-3d | %-22s | %-22s | %-32s | 0%ld | %2d\n",p->id,p->nom,p->prenom,p->adresse,
                        p->tel,q->penalite);
                TrouvePena=vrai;
                cpt++;
                id=0;
            }
            p=p->suiv;
        }
        q=q->suiv;
    }
    if(TrouvePena==faux)
        printf("\n\nAucun Emprunteur n'est penalise.\n");
    printf("\n\n");
}

void AfficheLivresEmpt(Emprunt *Emp,livre *L){
    livre *p;
    Emprunt *q;
    int cot,cpt=0;
    Bool TrouveLiv=faux;
    q = Emp;
    while (q != NULL){
            cot=q->COTE;
        p = L;
        while (p != NULL){
            if( p->cote==cot ){
                if(cpt==0){
                    printf("Cote | Titre                                    | Auteur                         |"
                            " Theme           | Edition | Prix(DH)\n");
                    printf("**************************************************************************************"
                            "*********************************\n");
            }
            printf("%-4d | %-40s | %-30s | %-15s | %-7d | %.2lf\n",p->cote,p->titre,p->auteur,
                    p->theme,p->edition,p->prix);
                TrouveLiv=vrai;
                cpt++;
            }
            p=p->suiv;
        }
        q=q->suiv;
    }
    if(TrouveLiv==faux)
        printf("\n\nAucun livre n'est Emprunter pour le moment.\n");
    printf("\n\n");
}
