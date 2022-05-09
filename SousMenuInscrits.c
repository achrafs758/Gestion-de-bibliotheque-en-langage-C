#include <stdio.h>
#include<stdlib.h>
#include "Structure.h"
#include "Inscrits.h"
#include "Rech_Tri_Livres_Inscrits.h"


void  SousMenuInscrits(){
    inscrit *ins=NULL;
    int c;
    do{
        system("color 6F");
        printf("\n"
		"                   *** Bienvenu sur l'Espace Inscription ***\n"
		"                                      *\n"
		"                                      *\n"
		"  ------------------------------------------------------------------------ \n"
		" |  ->1) Afficher la liste des inscrits.                                  |\n"
		" |  ->2) Inscription.                                                     |\n"
		" |  ->3) Desinscription.                                                  |\n"
		" |  ->4) Modification d'un inscrit.                                       |\n"
		" |  ->5) Recherche d'un inscrit.                                          |\n"
		" |  ->6) Savoir le nombre des inscrits dans la bibliotheque.              |\n"
        " |  ->7) Trier les inscrits.                                              |\n"
        " |  ->0) Retour au menu principal.                                        |\n"
        " ------------------------------------------------------------------------- \n"
        "                                                   |Choix : ");
        scanf("%d",&c);
        getchar();
        system("cls");
        ins=TransfererInscrits();
        switch(c)
        {
            case 0: break;
            case 1: AfficherInscrits(ins);
                    printf("\n");
                    system("pause");
                    system("cls");
                    break;
            case 2: AjouterInscrits(ins);
                    printf("\n");
                    system("pause");
                    system("cls");
                    break;
            case 3: SupprimerInscrits(ins);
                    printf("\n");
                    system("pause");
                    system("cls");
                    break;
            case 4: ModifierInscrits(&ins);
                    printf("\n");
                    system("pause");
                    system("cls");
                    break;
            case 5: RechercherInscrit(&ins);
                    break;
            case 6: printf("\nLe nombre des inscrits dans la bibliotheque est : %d\n",NombreInscrits());
                    printf("\n");
                    system("pause");
                    system("cls");
                    break;
            case 7: TrierInscrits();
                    break;
            default: system("color 4F");
                     printf("\nChoix invalide !!\n\n");
                     system("pause");
                     system("cls");
                     break;
        }
    }while(c!=0);
}
