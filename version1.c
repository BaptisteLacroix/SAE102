#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "entetesVersion1.h"

void version1 (int grille[10][10], int largeur, int cible)
{
    int trouve = 0;
    int indiceLigne = 0;
    int indiceColonne = 0;
    while ((trouve == 0) && (indiceLigne < largeur))
    {
        while ((trouve == 0) && (indiceColonne < largeur))
        {
            if (indiceColonne < largeur - 2)                                                                // Si la colonne est inférieur à largeur - 2 alors (avant-dernière colonne)
                test_ligne(grille, indiceLigne, indiceColonne, cible, &trouve);                       // on test la ligne

            if (indiceLigne < largeur - 2)                                                                  // Si la ligne est inférieur à largeur - 2 alors (avant-dernière ligne)
                test_colonne(grille, indiceLigne, indiceColonne, cible,&trouve);                      // on test la colonne

            if (indiceColonne < largeur - 2 && indiceLigne < largeur - 2)
                test_diagonale_droite(grille, indiceLigne, indiceColonne, cible,&trouve);             // on test la diagonale droite

            if (indiceColonne > 1 && indiceLigne < largeur - 2)
                test_diagonale_gauche(grille, indiceLigne, indiceColonne, cible,&trouve);             // on test la diagonale gauche
            indiceColonne++;                                                                                // On augmente la colonne de + 1
        }
        indiceColonne = 0;                                                                                  // On remet a 0 la colonne
        indiceLigne++;                                                                                      // On augmente de + 1 la ligne
    }
    if (trouve == 0)
        printf("pas de solution trouvee\n");
}

void test_ligne(int grille[10][10], int indiceLigne, int indiceColonne, int cible, int * trouve)
{
    if (grille[indiceLigne][indiceColonne] * grille[indiceLigne][indiceColonne+1] - grille[indiceLigne][indiceColonne+2] == cible)                     // Si grille[0][0] * grille[0][1] - grille[0][2] == cible
        affiche_solution_moins(grille, indiceLigne, indiceColonne, indiceLigne, indiceColonne+1, indiceLigne, indiceColonne+2, trouve);        // On affiche le résultat
    else if (grille[indiceLigne][indiceColonne] * grille[indiceLigne][indiceColonne+1] + grille[indiceLigne][indiceColonne+2] == cible)                // Si grille[0][0] * grille[0][1] + grille[0][2] == cible
        affiche_solution_plus(grille, indiceLigne, indiceColonne, indiceLigne, indiceColonne+1, indiceLigne, indiceColonne+2, trouve);         // On affiche le résultat

    else if (grille[indiceLigne][indiceColonne+1] * grille[indiceLigne][indiceColonne] - grille[indiceLigne][indiceColonne+2] == cible)                     // Si grille[0][0] * grille[0][1] - grille[0][2] == cible
        affiche_solution_moins(grille, indiceLigne, indiceColonne+1, indiceLigne, indiceColonne, indiceLigne, indiceColonne+2, trouve);        // On affiche le résultat
    else if (grille[indiceLigne][indiceColonne+1] * grille[indiceLigne][indiceColonne] + grille[indiceLigne][indiceColonne+2] == cible)                // Si grille[0][0] * grille[0][1] + grille[0][2] == cible
        affiche_solution_plus(grille, indiceLigne, indiceColonne+1, indiceLigne, indiceColonne, indiceLigne, indiceColonne+2, trouve);         // On affiche le résultat

    else if (grille[indiceLigne][indiceColonne] * grille[indiceLigne][indiceColonne+2] - grille[indiceLigne][indiceColonne+1] == cible)              // Si grille[0][0] * grille[0][2] - grille[0][1] == cible
        affiche_solution_moins(grille, indiceLigne, indiceColonne, indiceLigne, indiceColonne+2, indiceLigne, indiceColonne+1, trouve);      // On affiche le résultat
    else if (grille[indiceLigne][indiceColonne] * grille[indiceLigne][indiceColonne+2] + grille[indiceLigne][indiceColonne+1] == cible)              // Si grille[0][0] * grille[0][2] + grille[0][1] == cible
        affiche_solution_plus(grille,indiceLigne, indiceColonne, indiceLigne, indiceColonne+2, indiceLigne, indiceColonne+1, trouve);        // On affiche le résultat

    else if (grille[indiceLigne][indiceColonne+2] * grille[indiceLigne][indiceColonne] - grille[indiceLigne][indiceColonne+1] == cible)              // Si grille[0][0] * grille[0][2] - grille[0][1] == cible
        affiche_solution_moins(grille, indiceLigne, indiceColonne+2, indiceLigne, indiceColonne, indiceLigne, indiceColonne+1, trouve);      // On affiche le résultat
    else if (grille[indiceLigne][indiceColonne+2] * grille[indiceLigne][indiceColonne] + grille[indiceLigne][indiceColonne+1] == cible)              // Si grille[0][0] * grille[0][2] + grille[0][1] == cible
        affiche_solution_plus(grille,indiceLigne, indiceColonne+2, indiceLigne, indiceColonne, indiceLigne, indiceColonne+1, trouve);        // On affiche le résultat

    else if (grille[indiceLigne][indiceColonne+1] * grille[indiceLigne][indiceColonne+2] - grille[indiceLigne][indiceColonne] == cible)              // Si grille[0][1] * grille[0][2] - grille[0][0] == cible
        affiche_solution_moins(grille, indiceLigne, indiceColonne+1, indiceLigne, indiceColonne+2, indiceLigne, indiceColonne, trouve);      // On affiche le résultat
    else if (grille[indiceLigne][indiceColonne+1] * grille[indiceLigne][indiceColonne+2] + grille[indiceLigne][indiceColonne] == cible)              // Si grille[0][1] * grille[0][2] + grille[0][0] == cible
        affiche_solution_plus(grille, indiceLigne, indiceColonne+1, indiceLigne, indiceColonne+2, indiceLigne, indiceColonne, trouve);       // On affiche le résultat

    else if (grille[indiceLigne][indiceColonne+2] * grille[indiceLigne][indiceColonne+1] - grille[indiceLigne][indiceColonne] == cible)              // Si grille[0][1] * grille[0][2] - grille[0][0] == cible
        affiche_solution_moins(grille, indiceLigne, indiceColonne+2, indiceLigne, indiceColonne+1, indiceLigne, indiceColonne, trouve);      // On affiche le résultat
    else if (grille[indiceLigne][indiceColonne+2] * grille[indiceLigne][indiceColonne+1] + grille[indiceLigne][indiceColonne] == cible)              // Si grille[0][1] * grille[0][2] + grille[0][0] == cible
        affiche_solution_plus(grille, indiceLigne, indiceColonne+2, indiceLigne, indiceColonne+1, indiceLigne, indiceColonne, trouve);       // On affiche le résultat
}

void test_colonne(int grille[10][10], int indiceLigne, int indiceColonne, int cible, int * trouve)
{
    if (grille[indiceLigne][indiceColonne] * grille[indiceLigne+1][indiceColonne] - grille[indiceLigne+2][indiceColonne] == cible)                  // Si grille[0][0] * grille[1][0] - grille[2][0] == cible
        affiche_solution_moins(grille,indiceLigne, indiceColonne, indiceLigne+1, indiceColonne, indiceLigne+2, indiceColonne, trouve);       // On affiche le résultat
    else if (grille[indiceLigne][indiceColonne] * grille[indiceLigne+1][indiceColonne] + grille[indiceLigne+2][indiceColonne] == cible)              // Si grille[0][0] * grille[1][0] + grille[2][0] == cible
        affiche_solution_plus(grille, indiceLigne, indiceColonne, indiceLigne+1, indiceColonne, indiceLigne+2, indiceColonne, trouve);       // On affiche le résultat

    else if (grille[indiceLigne+1][indiceColonne] * grille[indiceLigne][indiceColonne] - grille[indiceLigne+2][indiceColonne] == cible)                  // Si grille[0][0] * grille[1][0] - grille[2][0] == cible
        affiche_solution_moins(grille,indiceLigne+1, indiceColonne, indiceLigne, indiceColonne, indiceLigne+2, indiceColonne, trouve);       // On affiche le résultat
    else if (grille[indiceLigne+1][indiceColonne] * grille[indiceLigne][indiceColonne] + grille[indiceLigne+2][indiceColonne] == cible)              // Si grille[0][0] * grille[1][0] + grille[2][0] == cible
        affiche_solution_plus(grille, indiceLigne+1, indiceColonne, indiceLigne, indiceColonne, indiceLigne+2, indiceColonne, trouve);       // On affiche le résultat

    else if (grille[indiceLigne][indiceColonne] * grille[indiceLigne+2][indiceColonne] - grille[indiceLigne+1][indiceColonne] == cible)              // Si grille[0][0] * grille[2][0] - grille[1][0] == cible
        affiche_solution_moins(grille,indiceLigne, indiceColonne, indiceLigne+2, indiceColonne, indiceLigne+1, indiceColonne, trouve);      // On affiche le résultat
    else if (grille[indiceLigne][indiceColonne] * grille[indiceLigne+2][indiceColonne] + grille[indiceLigne+1][indiceColonne] == cible)              // Si grille[0][0] * grille[2][0] + grille[1][0] == cible
        affiche_solution_plus(grille, indiceLigne, indiceColonne, indiceLigne+2, indiceColonne, indiceLigne+1, indiceColonne, trouve);       // On affiche le résultat

    else if (grille[indiceLigne+2][indiceColonne] * grille[indiceLigne][indiceColonne] - grille[indiceLigne+1][indiceColonne] == cible)              // Si grille[0][0] * grille[2][0] - grille[1][0] == cible
        affiche_solution_moins(grille,indiceLigne+2, indiceColonne, indiceLigne, indiceColonne, indiceLigne+1, indiceColonne, trouve);      // On affiche le résultat
    else if (grille[indiceLigne+2][indiceColonne] * grille[indiceLigne][indiceColonne] + grille[indiceLigne+1][indiceColonne] == cible)              // Si grille[0][0] * grille[2][0] + grille[1][0] == cible
        affiche_solution_plus(grille, indiceLigne+2, indiceColonne, indiceLigne, indiceColonne, indiceLigne+1, indiceColonne, trouve);       // On affiche le résultat

    else if (grille[indiceLigne+1][indiceColonne] * grille[indiceLigne+2][indiceColonne] - grille[indiceLigne][indiceColonne] == cible)              // Si grille[1][0] * grille[2][0] - grille[0][0] == cible
        affiche_solution_moins(grille, indiceLigne+1, indiceColonne, indiceLigne+2, indiceColonne, indiceLigne, indiceColonne, trouve);      // On affiche le résultat
    else if (grille[indiceLigne+1][indiceColonne] * grille[indiceLigne+2][indiceColonne] + grille[indiceLigne][indiceColonne] == cible)              // Si grille[1][0] * grille[2][0] + grille[0][0] == cible
        affiche_solution_plus(grille, indiceLigne+1, indiceColonne, indiceLigne+2, indiceColonne, indiceLigne, indiceColonne, trouve);       // On affiche le résultat

    else if (grille[indiceLigne+2][indiceColonne] * grille[indiceLigne+1][indiceColonne] - grille[indiceLigne][indiceColonne] == cible)              // Si grille[1][0] * grille[2][0] - grille[0][0] == cible
        affiche_solution_moins(grille, indiceLigne+2, indiceColonne, indiceLigne+1, indiceColonne, indiceLigne, indiceColonne, trouve);      // On affiche le résultat
    else if (grille[indiceLigne+2][indiceColonne] * grille[indiceLigne+1][indiceColonne] + grille[indiceLigne][indiceColonne] == cible)              // Si grille[1][0] * grille[2][0] + grille[0][0] == cible
        affiche_solution_plus(grille, indiceLigne+2, indiceColonne, indiceLigne+1, indiceColonne, indiceLigne, indiceColonne, trouve);       // On affiche le résultat
}

void test_diagonale_droite(int grille[10][10], int indiceLigne, int indiceColonne, int cible, int * trouve)
{
    if (grille[indiceLigne][indiceColonne] * grille[indiceLigne+1][indiceColonne+1] - grille[indiceLigne+2][indiceColonne+2] == cible)                           // Si grille[0][0] * grille[1][1] - grille[2][2] == cible
        affiche_solution_moins(grille, indiceLigne, indiceColonne, indiceLigne+1, indiceColonne+1, indiceLigne+2, indiceColonne+2, trouve);      // On affiche le résultat
    else if (grille[indiceLigne][indiceColonne] * grille[indiceLigne+1][indiceColonne+1] + grille[indiceLigne+2][indiceColonne+2] == cible)                      // Si grille[0][0] * grille[1][1] + grille[2][2] == cible
        affiche_solution_plus(grille, indiceLigne, indiceColonne, indiceLigne+1, indiceColonne+1, indiceLigne+2, indiceColonne+2, trouve);       // On affiche le résultat

    else if (grille[indiceLigne+1][indiceColonne+1] * grille[indiceLigne][indiceColonne] - grille[indiceLigne+2][indiceColonne+2] == cible)                           // Si grille[0][0] * grille[1][1] - grille[2][2] == cible
        affiche_solution_moins(grille, indiceLigne+1, indiceColonne+1, indiceLigne, indiceColonne, indiceLigne+2, indiceColonne+2, trouve);      // On affiche le résultat
    else if (grille[indiceLigne+1][indiceColonne+1] * grille[indiceLigne][indiceColonne] + grille[indiceLigne+2][indiceColonne+2] == cible)                      // Si grille[0][0] * grille[1][1] + grille[2][2] == cible
        affiche_solution_plus(grille, indiceLigne+1, indiceColonne+1, indiceLigne, indiceColonne, indiceLigne+2, indiceColonne+2, trouve);       // On affiche le résultat

    else if (grille[indiceLigne][indiceColonne] * grille[indiceLigne+2][indiceColonne+2] - grille[indiceLigne+1][indiceColonne+1] == cible)                      // Si grille[0][0] * grille[2][2] - grille[1][1] == cible
        affiche_solution_moins(grille, indiceLigne, indiceColonne, indiceLigne+2, indiceColonne+2, indiceLigne+1, indiceColonne+1, trouve);      // On affiche le résultat
    else if (grille[indiceLigne][indiceColonne] * grille[indiceLigne+2][indiceColonne+2] + grille[indiceLigne+1][indiceColonne+1] == cible)                     // Si grille[0][0] * grille[2][2] + grille[1][1] == cible
        affiche_solution_plus(grille, indiceLigne, indiceColonne, indiceLigne+2, indiceColonne+2, indiceLigne+1, indiceColonne+1, trouve);       // On affiche le résultat

    else if (grille[indiceLigne+2][indiceColonne+2] * grille[indiceLigne][indiceColonne] - grille[indiceLigne+1][indiceColonne+1] == cible)                      // Si grille[0][0] * grille[2][2] - grille[1][1] == cible
        affiche_solution_moins(grille, indiceLigne+2, indiceColonne+2, indiceLigne, indiceColonne, indiceLigne+1, indiceColonne+1, trouve);      // On affiche le résultat
    else if (grille[indiceLigne+2][indiceColonne+2] * grille[indiceLigne][indiceColonne] + grille[indiceLigne+1][indiceColonne+1] == cible)                     // Si grille[0][0] * grille[2][2] + grille[1][1] == cible
        affiche_solution_plus(grille, indiceLigne+2, indiceColonne+2, indiceLigne, indiceColonne, indiceLigne+1, indiceColonne+1, trouve);       // On affiche le résultat

    else if (grille[indiceLigne+1][indiceColonne+1] * grille[indiceLigne+2][indiceColonne+2] - grille[indiceLigne][indiceColonne] == cible)                      // Si grille[1][1] * grille[2][2] - grille[0][0] == cible
        affiche_solution_moins(grille, indiceLigne+1, indiceColonne+1, indiceLigne+2, indiceColonne+2, indiceLigne, indiceColonne, trouve);      // On affiche le résultat
    else if (grille[indiceLigne+1][indiceColonne+1] * grille[indiceLigne+2][indiceColonne+2] + grille[indiceLigne][indiceColonne] == cible)                     // Si grille[1][1] * grille[2][2] + grille[0][0] == cible
        affiche_solution_plus(grille, indiceLigne+1, indiceColonne+1, indiceLigne+2, indiceColonne+2, indiceLigne, indiceColonne, trouve);       // On affiche le résultat

    else if (grille[indiceLigne+2][indiceColonne+2] * grille[indiceLigne+1][indiceColonne+1] - grille[indiceLigne][indiceColonne] == cible)                      // Si grille[1][1] * grille[2][2] - grille[0][0] == cible
        affiche_solution_moins(grille, indiceLigne+2, indiceColonne+2, indiceLigne+1, indiceColonne+1, indiceLigne, indiceColonne, trouve);      // On affiche le résultat
    else if (grille[indiceLigne+2][indiceColonne+2] * grille[indiceLigne+1][indiceColonne+1] + grille[indiceLigne][indiceColonne] == cible)                     // Si grille[1][1] * grille[2][2] + grille[0][0] == cible
        affiche_solution_plus(grille, indiceLigne+2, indiceColonne+2, indiceLigne+1, indiceColonne+1, indiceLigne, indiceColonne, trouve);       // On affiche le résultat
}

void test_diagonale_gauche(int grille[10][10], int indiceLigne, int indiceColonne, int cible, int * trouve)
{
    if (grille[indiceLigne][indiceColonne] * grille[indiceLigne+1][indiceColonne-1] - grille[indiceLigne+2][indiceColonne-2] == cible)                                    // Si grille[0][0] * grille[1][1] - grille[2][-2] == cible
        affiche_solution_moins(grille, indiceLigne, indiceColonne, indiceLigne+1, indiceColonne-1, indiceLigne+2, indiceColonne-2, trouve);        // On affiche le résultat
    else if (grille[indiceLigne][indiceColonne] * grille[indiceLigne+1][indiceColonne-1] + grille[indiceLigne+2][indiceColonne-2] == cible)                               // Si grille[0][0] * grille[1][1] + grille[2][-2] == cible
        affiche_solution_plus(grille, indiceLigne, indiceColonne, indiceLigne+1, indiceColonne-1, indiceLigne+2, indiceColonne-2, trouve);         // On affiche le résultat

    else if (grille[indiceLigne+1][indiceColonne-1] * grille[indiceLigne][indiceColonne] - grille[indiceLigne+2][indiceColonne-2] == cible)                               // Si grille[1][1] * grille[0][0] - grille[2][-2] == cible
        affiche_solution_moins(grille, indiceLigne+1, indiceColonne-1, indiceLigne, indiceColonne, indiceLigne+2, indiceColonne-2, trouve);        // On affiche le résultat
    else if (grille[indiceLigne+1][indiceColonne-1] * grille[indiceLigne][indiceColonne] + grille[indiceLigne+2][indiceColonne-2] == cible)                               // Si grille[1][1] * grille[0][0] + grille[2][-2] == cible
        affiche_solution_plus(grille, indiceLigne+1, indiceColonne-1, indiceLigne, indiceColonne, indiceLigne+2, indiceColonne-2, trouve);         // On affiche le résultat

    else if (grille[indiceLigne][indiceColonne] * grille[indiceLigne+2][indiceColonne-2] - grille[indiceLigne+1][indiceColonne-1] == cible)                             // Si grille[0][0] * grille[2][-2] - grille[1][1] == cible
        affiche_solution_moins(grille, indiceLigne, indiceColonne, indiceLigne+2, indiceColonne-2, indiceLigne+1, indiceColonne-1, trouve);      // On affiche le résultat
    else if (grille[indiceLigne][indiceColonne] * grille[indiceLigne+2][indiceColonne-2] + grille[indiceLigne+1][indiceColonne-1] == cible)                             // Si grille[0][0] * grille[2][-2] + grille[1][1] == cible
        affiche_solution_plus(grille, indiceLigne, indiceColonne, indiceLigne+2, indiceColonne-2, indiceLigne+1, indiceColonne-1, trouve);       // On affiche le résultat

    else if (grille[indiceLigne+2][indiceColonne-2] * grille[indiceLigne][indiceColonne] - grille[indiceLigne+1][indiceColonne-1] == cible)                             // Si grille[2][-2] * grille[0][0] - grille[1][1] == cible
        affiche_solution_moins(grille, indiceLigne+2, indiceColonne-2, indiceLigne, indiceColonne, indiceLigne+1, indiceColonne-1, trouve);      // On affiche le résultat
    else if (grille[indiceLigne+2][indiceColonne-2] * grille[indiceLigne][indiceColonne] + grille[indiceLigne+1][indiceColonne-1] == cible)                             // Si grille[2][-2] * grille[0][0] + grille[1][1] == cible
        affiche_solution_plus(grille, indiceLigne+2, indiceColonne-2, indiceLigne, indiceColonne, indiceLigne+1, indiceColonne-1, trouve);       // On affiche le résultat

    else if (grille[indiceLigne+1][indiceColonne-1] * grille[indiceLigne+2][indiceColonne-2] - grille[indiceLigne][indiceColonne] == cible)                             // Si grille[1][1] * grille[2][-2] - grille[0][0] == cible
        affiche_solution_moins(grille, indiceLigne+1, indiceColonne-1, indiceLigne+2, indiceColonne-2, indiceLigne, indiceColonne, trouve);      // On affiche le résultat
    else if (grille[indiceLigne+1][indiceColonne-1] * grille[indiceLigne+2][indiceColonne-2] + grille[indiceLigne][indiceColonne] == cible)                             // Si grille[1][1] * grille[2][-2] - grille[0][0] == cible
        affiche_solution_plus(grille, indiceLigne+1, indiceColonne-1, indiceLigne+2, indiceColonne-2, indiceLigne, indiceColonne, trouve);       // On affiche le résultat

    else if (grille[indiceLigne+2][indiceColonne-2] * grille[indiceLigne+1][indiceColonne-1] - grille[indiceLigne][indiceColonne] == cible)                             // Si grille[2][-2] * grille[1][1] - grille[0][0] == cible
        affiche_solution_moins(grille, indiceLigne+2, indiceColonne-2, indiceLigne+1, indiceColonne-1, indiceLigne, indiceColonne, trouve);      // On affiche le résultat
    else if (grille[indiceLigne+2][indiceColonne-2] * grille[indiceLigne+1][indiceColonne-1] + grille[indiceLigne][indiceColonne] == cible)                               // Si grille[2][-2] * grille[1][1] - grille[0][0] == cible
        affiche_solution_plus(grille, indiceLigne+2, indiceColonne-2, indiceLigne+1, indiceColonne-1, indiceLigne, indiceColonne, trouve);       // On affiche le résultat
}

void affiche_solution_moins(int grille[10][10], int A0, int A1, int B0, int B1, int C0, int C1, int * trouve)
{
    printf("%d = %d x %d - %d\n", grille[A0][A1] * grille[B0][B1] - grille[C0][C1], grille[A0][A1], grille[B0][B1], grille[C0][C1]);
    *trouve = 1;
}

void affiche_solution_plus(int grille[10][10], int A0, int A1, int B0, int B1, int C0, int C1, int * trouve)
{
    printf("%d = %d x %d + %d\n", grille[A0][A1] * grille[B0][B1] + grille[C0][C1], grille[A0][A1], grille[B0][B1], grille[C0][C1]);
    *trouve = 1;
}