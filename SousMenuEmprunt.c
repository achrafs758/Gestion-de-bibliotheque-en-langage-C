#include <stdio.h>
#include<stdlib.h>
#include "Structure.h"
#include "Emprunt.h"
#include "Livres.h"
#include "Inscrits.h"


void SousMenuEmprunt(){
    Emprunt *Empt=NULL;
    livre *L=NULL;
    inscrit *I=NULL;
    int c,N;
    do{
        system("color E1");
        printf("\n"
		"                   *** Bienvenu sur l'Espace Emprunt ***\n"
		"                                   *\n"
		"                                   *\n"
		"  ------------------------------------------------------------------------ \n"
		" |  ->1) Afficher la liste des Emprunts.                                  |\n"
		" |  ->2) Emprunter un livre de la bibliotheque.                           |\n"
		" |  ->3) Rendre un livre a la bibliotheque.                               |\n"
		" |  ->4) Savoir si un livre est emprunte ou non.                          |\n"
		" |  ->5) Savoir si un inscrit a emprunter un livre ou non.                |\n"
		" |  ->6) Savoir si un emprunteur est penalise.                            |\n"
		" |  ->7) Savoir le nombre des livres Empruntes.                           |\n"
		" |  ->8) Afficher la liste des Emprunteurs penealises.                    |\n"
        " |  ->9) Afficher la liste des livres Empruntes.                          |\n"
        " |  ->0)Retour au menu principal.                                         |\n"
        " ------------------------------------------------------------------------- \n"
        "                                                   |Choix : ");
        scanf("%d",&c);
        getchar();
        system("cls");
        Empt=TransfererDonnees();
        I=TransfererInscrits();
        L=TransfererLivres();
        switch(c)
        {
            case 0: break;
            case 1: AfficherEmprunt(Empt);
                    printf("\n");
                    system("pause");
                    system("cls");
                    break;
            case 2: EmprunterLivre(&Empt,L,I);
                    printf("\n");
                    system("pause");
                    system("cls");
                    break;
            case 3: RendreLivres(&Empt,L,I);
                    system("pause");
                    system("cls");
                    break;
            case 4: Livre_Emprunte_0u_Non(&Empt,L);
                    printf("\n");
                    system("pause");
                    system("cls");
                    break;
            case 5: Emprunteur_0u_Non(&Empt,I);
                    printf("\n");
                    system("pause");
                    system("cls");
                    break;
            case 6: Penalise(Empt,I);
                    printf("\n");
                    system("pause");
                    system("cls");
                    break;
            case 7: N=NombreEmprunt();
                    printf("\nLe nombre des livres empruntes est : %d\n\n",N);
                    printf("\n");
                    system("pause");
                    system("cls");
                    break;
            case 8: AffichePenalise(Empt,I);
                    printf("\n");
                    system("pause");
                    system("cls");
                    break;
            case 9: AfficheLivresEmpt(Empt,L);
                    printf("\n");
                    system("pause");
                    system("cls");
                    break;
            default: system("color 4F");
                     printf("\nChoix invalide !!\n\n");
                     system("pause");
                     system("cls");
                     break;
        }
    }while(c!=0);
}
