#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void recuperationGrille (FILE *f, int grille [10][10], int *largeurGrille)
{
    fscanf (f, "%d", largeurGrille) ;
    for(int i=0; i<*largeurGrille; i++)
    {
        for (int j=0; j<*largeurGrille; j++)
        {
            fscanf (f, "%d", &grille [i][j]) ;
        }
    }
}


/// ///////////////////////////////////////// ///
/// //////Début affichage de la grille/////// ///
/// ///////////////////////////////////////// ///

void afficherLigneVide (int largeur)
{
    for (int j=0; j<largeur; j++)
    {
        printf ("\t|") ;
    }
    printf ("\n") ;
}

void afficherLigneNumeros (int grille [10][10], int largeur, int l)
{
    printf("|") ;
    for (int j=0; j<largeur; j++)
        printf ("   %d\t|", grille [l][j]) ;
    printf ("\n|") ;
}

void afficherLignePleine (int largeur)
{
    for (int i=0; i<largeur; i++)
    {
        printf ("+-------") ;
    }
    printf ("+\n") ;
}

void afficherGrille (int grille [10][10], int largeur)
{
    int i ;

    ///Ligne du haut de la grille
    afficherLignePleine (largeur) ;

    for (i=0; i<largeur; i++)
    {
        printf ("|") ;
        afficherLigneVide (largeur) ;
        afficherLigneNumeros (grille, largeur, i) ;
        afficherLigneVide (largeur) ;
        afficherLignePleine (largeur) ;
    }
}

/// ///////////////////////////////////////// ///
/// ///////Fin affichage de la grille//////// ///
/// ///////////////////////////////////////// ///

