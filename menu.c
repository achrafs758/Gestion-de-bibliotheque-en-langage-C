#include <stdio.h>
#include<stdlib.h>
#include "SousMenu.h"
#include "Structure.h"
#include "Emprunt.h"


void menu(){
    int choix;
    Emprunt *Ep=NULL;
    Mise_A_Jour_Date();
    Ep=TransfererDonnees();
    Mise_A_Jour_Emprunt(Ep);
    do{
        system("color 2F");
        printf(
        "                             ------------------------\n"
		"                           | GESTION DE BIBLIOTHEQUE |\n"
		"                              -----------------------\n"
		"                                       |\n"
		"  ------------------------------------------------------------------------ \n"
		" |  ->1) Consultation de l'espace \"Livre\".                                |\n"
		" |  ->2) Consultation de lespace \"Inscription\".                           |\n"
		" |  ->3) Consultation de l'espace \"Emprunt\".                              |\n"
        " |  ->0)Quitter.                                                          |\n"
        " ------------------------------------------------------------------------- \n"
        "                                                   |Choix : ");
        scanf("%d",&choix);
        getchar();
        system("cls");
        switch(choix)
        {
            case 0: break;
            case 1: SousMenuLivres();
                    system("pause");
                    system("cls");
                    break;
            case 2: SousMenuInscrits();
                    system("pause");
                    system("cls");
                    break;
            case 3: SousMenuEmprunt();
                    system("pause");
                    system("cls");
                    break;
            default: system("color 4F");
                     printf("\nChoix invalide !!\n\n");
                     system("pause");
                     system("cls");
                     break;
        }
    }while(choix!=0);
}
