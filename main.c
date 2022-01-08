#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "entetesGestionGrille.h"
#include "entetesVersion1.h"
#include "entetesVersion2.h"


int main()
{
    FILE    *fGrille ;                  /// lien vers le fichier conteant les valeurs de la grille
    int     largeurGrille ;             /// variables qui permettent
    int     grille [10][10] ;           /// de repr�senter la grille
    int     cible ;                     /// variable qui contienr la valeur pour laquelle on cherche le calcul
    clock_t tempsDebut1, tempsFin1 ;    /// variables qui permettent de caculer
    float   tempsCpu1 ;                 /// le temps d'ex�cution du programme 1
    clock_t tempsDebut2, tempsFin2 ;    /// variables qui permettent de caculer
    float   tempsCpu2 ;                 /// le temps d'ex�cution du programme 2
    int     choixMenu = 0 ;


    /// ////////////////////////////////////////////////////// ///
    /// r�cup�ration de la grille stock� dans un fichier texte ///
    /// ////////////////////////////////////////////////////// ///
    ///fGrille = fopen ("grille3x3.txt","r") ;
    fGrille = fopen ("grille.txt","r") ;
    ///fGrille = fopen ("grille4x4.txt","r") ;
    ///fGrille = fopen ("grille5x5.txt","r") ;
    ///fGrille = fopen ("grille6x6.txt","r") ;
    ///fGrille = fopen ("grille7x7.txt","r") ;
    ///fGrille = fopen ("grille8x8.txt","r") ;
    ///fGrille = fopen ("grille9x9.txt","r") ;
    ///fGrille = fopen ("grille10x10.txt","r") ;
    recuperationGrille (fGrille, grille, &largeurGrille) ;

    /// d�claration des variables qui permettent de stocker toutes les solutions possibles
    int         taille = 0 ;                                    /// taille r�elle du tableau qui va contenir l'ensemble des solutions
    ///int         tailleMax = (int)pow (6, largeurGrille+1) ;     /// taille maximale du tableau qui va contenir l'ensemble des solutions
    int         tailleMax = 100000 ;                            /// taille maximale du tableau qui peut �tre allou�e
    solution    tabSolutions [tailleMax] ;                      /// tableau qui va contenir toutes les solutions possibles

    /// affichage de la grille r�cup�r�e
    afficherGrille (grille, largeurGrille) ;

    printf ("Que voulez-vous faire? Trouver un calcul (1), afficher tous les calculs possibles (2) ou quitter (0)?  ") ;
    scanf ("%d", &choixMenu) ;

    while (choixMenu != 0)
    {
        if (choixMenu == 1)
        /// version 1 : on parcours la grille jusqu'� trouver les valeurs qui correspondent � la cible
        {
            printf ("Donnez une valeur pour la cible : ") ;
            scanf ("%d", &cible) ;
            while (cible<0 || cible>90)
            {
                printf ("Donnez une valeur pour la cible : ") ;
                scanf ("%d", &cible) ;
            }
            ///recherche avec la version 1 de l'op�ration correspondant � la cible
            tempsDebut1 = clock () ;
            version1 (grille, largeurGrille, cible) ;

            tempsFin1 = clock () ;
            tempsCpu1 = (tempsFin1 - tempsDebut1) * 1e-6 ;
            printf ("Temps d'execution du programme 1 = %lf\n", tempsCpu1) ;
        }
        else
        /// version 2 : on g�n�re tous les calculs possibles pr�sents dans la grille, on les tri par
        /// ordre croissant de la valeur de la cible, et on affiche tous les calculs de la grille qui
        /// correspondent � la cible
        {
            printf ("Donnez une valeur pour la cible : ") ;
            scanf ("%d", &cible) ;
            while (cible<0 || cible>90)
            {
                printf ("Donnez une valeur pour la cible : ") ;
                scanf ("%d", &cible) ;
            }
            ///recherche avec la version 2 de l'op�ration correspondant � la cible
            tempsDebut2 = clock () ;
            version2 (grille, largeurGrille, cible, tabSolutions, &taille) ;

            tempsFin2 = clock () ;
            tempsCpu2 = (tempsFin2 - tempsDebut2) * 1e-6 ;
            printf ("Temps d'execution du programme 2 = %lf\n", tempsCpu2) ;
            taille=0 ;
        }
        printf ("Que voulez-vous faire? Trouver un calcul (1), afficher tous les calculs possibles (2) ou quitter (0)?  ") ;
        scanf ("%d", &choixMenu) ;
    }

    /// fermeture du fichier
    fclose (fGrille) ;

    return 0;
}
