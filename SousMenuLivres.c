#include <stdio.h>
#include<stdlib.h>
#include "Structure.h"
#include "Livres.h"
#include "Rech_Tri_Livres_Inscrits.h"

void SousMenuLivres(){
    livre *liv=NULL;
    int c,cp;
    do{
        system("color b4");
        printf("\n"
		"                   *** Bienvenu sur l'Espace Livre ***\n"
		"                                   *\n"
		"                                   *\n"
		"  ------------------------------------------------------------------------ \n"
		" |  ->1) Lister tous les livres de la bibliotheque.                       |\n"
		" |  ->2) Ajouter des livres a la bibliotheque.                            |\n"
		" |  ->3) Supprimer un livre de la bibliotheque.                           |\n"
		" |  ->4) Rechercher un livre dans la bibliotheque.                        |\n"
		" |  ->5) Modifier un livre dans la bibliotheque.                          |\n"
		" |  ->6) Savoir le nombre des livres dans la bibliotheque.                |\n"
		" |  ->7) Savoir le nombre des copies d'un livre dans la bibliotheque.     |\n"
        " |  ->8) Trier les livres de la bibliotheque.                             |\n"
        " |  ->0) Retour au menu principal.                                        |\n"
        " ------------------------------------------------------------------------- \n"
        "                                                   |Choix : ");
        scanf("%d",&c);
        getchar();
        system("cls");
        liv=TransfererLivres();
        switch(c)
        {
            case 0: break;
            case 1: AfficherLivres(liv);
                    printf("\n");
                    system("pause");
                    system("cls");
                    break;
            case 2: AjouterLivre(liv);
                    system("pause");
                    system("cls");
                    break;
            case 3: SupprimerLivres(liv);
                    system("pause");
                    system("cls");
                    break;
            case 4: RechercherLivre(&liv);
                    break;
            case 5: ModifierLivre(&liv);
                    printf("\n");
                    system("pause");
                    system("cls");
                    break;
            case 6: printf("\nLe nombre des livres de la bibliotheque est : %d\n",NombreLivres());
                    printf("\n");
                    system("pause");
                    system("cls");
                    break;
            case 7: cp=Nb_copies(&liv);
                    if(cp!=0)
                        printf("\nLe nombre des copies de ce livre est : %d\n",cp);
                    else
                        printf("\nCe livre ne se trouve pas dans la bibliotheque.\n");
                    printf("\n");
                    system("pause");
                    system("cls");
                    break;
            case 8: TrierLivre();
                    break;
            default: system("color 4F");
                     printf("\nChoix invalide !!\n\n");
                     system("pause");
                     system("cls");
                     break;
        }
    }while(c!=0);
}
