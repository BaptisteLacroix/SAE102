#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "entetesVersion2.h"

void version2(int grille[10][10], int largeur, int cible, solution tabSolutions[], int *taille)
{
    int indiceLigne = 0, indiceColonne = 0;
    while ((indiceLigne < largeur))
    {
        while ((indiceColonne < largeur))
        {
            if (indiceColonne < largeur - 2)
                test_ligne2(grille, indiceLigne, indiceColonne, cible, tabSolutions, taille);

            if (indiceLigne < largeur - 2)
                test_colonne2(grille, indiceLigne, indiceColonne, cible, tabSolutions, taille);

            if (indiceColonne < largeur - 2 && indiceLigne < largeur - 2)
                test_diagonale_droite2(grille, indiceLigne, indiceColonne, cible, tabSolutions, taille);

            if (indiceColonne > 1 && indiceLigne < largeur - 2)
                test_diagonale_gauche2(grille, indiceLigne, indiceColonne, cible, tabSolutions, taille);

            indiceColonne++;
        }
        indiceColonne = 0;
        indiceLigne++;
    }
    affichageSolutions(tabSolutions, taille, cible);
}

void test_ligne2(int grille[10][10], int indiceLigne, int indiceColonne, int cible, solution tabSolutions[], int *taille)
{
    if (grille[indiceLigne][indiceColonne] * grille[indiceLigne][indiceColonne + 1] - grille[indiceLigne][indiceColonne + 2] == cible)                         // Si grille[0][0] * grille[0][1] - grille[0][2] == cible
        ajouteSolutions(grille, indiceLigne, indiceColonne, indiceLigne, indiceColonne + 1, indiceLigne, indiceColonne + 2, tabSolutions, '-', taille, cible); // On affiche le résultat
    if (grille[indiceLigne][indiceColonne] * grille[indiceLigne][indiceColonne + 1] + grille[indiceLigne][indiceColonne + 2] == cible)                         // Si grille[0][0] * grille[0][1] + grille[0][2] == cible
        ajouteSolutions(grille, indiceLigne, indiceColonne, indiceLigne, indiceColonne + 1, indiceLigne, indiceColonne + 2, tabSolutions, '+', taille, cible); // On affiche le résultat

    if (grille[indiceLigne][indiceColonne + 1] * grille[indiceLigne][indiceColonne] - grille[indiceLigne][indiceColonne + 2] == cible)                         // Si grille[0][0] * grille[0][1] - grille[0][2] == cible
        ajouteSolutions(grille, indiceLigne, indiceColonne + 1, indiceLigne, indiceColonne, indiceLigne, indiceColonne + 2, tabSolutions, '-', taille, cible); // On affiche le résultat
    if (grille[indiceLigne][indiceColonne + 1] * grille[indiceLigne][indiceColonne] + grille[indiceLigne][indiceColonne + 2] == cible)                         // Si grille[0][0] * grille[0][1] + grille[0][2] == cible
        ajouteSolutions(grille, indiceLigne, indiceColonne + 1, indiceLigne, indiceColonne, indiceLigne, indiceColonne + 2, tabSolutions, '+', taille, cible); // On affiche le résultat

    if (grille[indiceLigne][indiceColonne] * grille[indiceLigne][indiceColonne + 2] - grille[indiceLigne][indiceColonne + 1] == cible)                         // Si grille[0][0] * grille[0][2] - grille[0][1] == cible
        ajouteSolutions(grille, indiceLigne, indiceColonne, indiceLigne, indiceColonne + 2, indiceLigne, indiceColonne + 1, tabSolutions, '-', taille, cible); // On affiche le résultat
    if (grille[indiceLigne][indiceColonne] * grille[indiceLigne][indiceColonne + 2] + grille[indiceLigne][indiceColonne + 1] == cible)                         // Si grille[0][0] * grille[0][2] + grille[0][1] == cible
        ajouteSolutions(grille, indiceLigne, indiceColonne, indiceLigne, indiceColonne + 2, indiceLigne, indiceColonne + 1, tabSolutions, '+', taille, cible); // On affiche le résultat

    if (grille[indiceLigne][indiceColonne + 2] * grille[indiceLigne][indiceColonne] - grille[indiceLigne][indiceColonne + 1] == cible)                         // Si grille[0][0] * grille[0][2] - grille[0][1] == cible
        ajouteSolutions(grille, indiceLigne, indiceColonne + 2, indiceLigne, indiceColonne, indiceLigne, indiceColonne + 1, tabSolutions, '-', taille, cible); // On affiche le résultat
    if (grille[indiceLigne][indiceColonne + 2] * grille[indiceLigne][indiceColonne] + grille[indiceLigne][indiceColonne + 1] == cible)                         // Si grille[0][0] * grille[0][2] + grille[0][1] == cible
        ajouteSolutions(grille, indiceLigne, indiceColonne + 2, indiceLigne, indiceColonne, indiceLigne, indiceColonne + 1, tabSolutions, '+', taille, cible); // On affiche le résultat

    if (grille[indiceLigne][indiceColonne + 1] * grille[indiceLigne][indiceColonne + 2] - grille[indiceLigne][indiceColonne] == cible)                         // Si grille[0][1] * grille[0][2] - grille[0][0] == cible
        ajouteSolutions(grille, indiceLigne, indiceColonne + 1, indiceLigne, indiceColonne + 2, indiceLigne, indiceColonne, tabSolutions, '-', taille, cible); // On affiche le résultat
    if (grille[indiceLigne][indiceColonne + 1] * grille[indiceLigne][indiceColonne + 2] + grille[indiceLigne][indiceColonne] == cible)                         // Si grille[0][1] * grille[0][2] + grille[0][0] == cible
        ajouteSolutions(grille, indiceLigne, indiceColonne + 1, indiceLigne, indiceColonne + 2, indiceLigne, indiceColonne, tabSolutions, '+', taille, cible); // On affiche le résultat

    if (grille[indiceLigne][indiceColonne + 2] * grille[indiceLigne][indiceColonne + 1] - grille[indiceLigne][indiceColonne] == cible)                         // Si grille[0][1] * grille[0][2] - grille[0][0] == cible
        ajouteSolutions(grille, indiceLigne, indiceColonne + 2, indiceLigne, indiceColonne + 1, indiceLigne, indiceColonne, tabSolutions, '-', taille, cible); // On affiche le résultat
    if (grille[indiceLigne][indiceColonne + 2] * grille[indiceLigne][indiceColonne + 1] + grille[indiceLigne][indiceColonne] == cible)                         // Si grille[0][1] * grille[0][2] + grille[0][0] == cible
        ajouteSolutions(grille, indiceLigne, indiceColonne + 2, indiceLigne, indiceColonne + 1, indiceLigne, indiceColonne, tabSolutions, '+', taille, cible); // On affiche le résultat
}

void test_colonne2(int grille[10][10], int indiceLigne, int indiceColonne, int cible, solution tabSolutions[], int *taille)
{
    if (grille[indiceLigne][indiceColonne] * grille[indiceLigne + 1][indiceColonne] - grille[indiceLigne + 2][indiceColonne] == cible)                         // Si grille[0][0] * grille[1][0] - grille[2][0] == cible
        ajouteSolutions(grille, indiceLigne, indiceColonne, indiceLigne + 1, indiceColonne, indiceLigne + 2, indiceColonne, tabSolutions, '-', taille, cible); // On affiche le résultat
    if (grille[indiceLigne][indiceColonne] * grille[indiceLigne + 1][indiceColonne] + grille[indiceLigne + 2][indiceColonne] == cible)                         // Si grille[0][0] * grille[1][0] + grille[2][0] == cible
        ajouteSolutions(grille, indiceLigne, indiceColonne, indiceLigne + 1, indiceColonne, indiceLigne + 2, indiceColonne, tabSolutions, '+', taille, cible); // On affiche le résultat

    if (grille[indiceLigne + 1][indiceColonne] * grille[indiceLigne][indiceColonne] - grille[indiceLigne + 2][indiceColonne] == cible)                         // Si grille[0][0] * grille[1][0] - grille[2][0] == cible
        ajouteSolutions(grille, indiceLigne + 1, indiceColonne, indiceLigne, indiceColonne, indiceLigne + 2, indiceColonne, tabSolutions, '-', taille, cible); // On affiche le résultat
    if (grille[indiceLigne + 1][indiceColonne] * grille[indiceLigne][indiceColonne] + grille[indiceLigne + 2][indiceColonne] == cible)                         // Si grille[0][0] * grille[1][0] + grille[2][0] == cible
        ajouteSolutions(grille, indiceLigne + 1, indiceColonne, indiceLigne, indiceColonne, indiceLigne + 2, indiceColonne, tabSolutions, '+', taille, cible); // On affiche le résultat

    if (grille[indiceLigne][indiceColonne] * grille[indiceLigne + 2][indiceColonne] - grille[indiceLigne + 1][indiceColonne] == cible)                         // Si grille[0][0] * grille[2][0] - grille[1][0] == cible
        ajouteSolutions(grille, indiceLigne, indiceColonne, indiceLigne + 2, indiceColonne, indiceLigne + 1, indiceColonne, tabSolutions, '-', taille, cible); // On affiche le résultat
    if (grille[indiceLigne][indiceColonne] * grille[indiceLigne + 2][indiceColonne] + grille[indiceLigne + 1][indiceColonne] == cible)                         // Si grille[0][0] * grille[2][0] + grille[1][0] == cible
        ajouteSolutions(grille, indiceLigne, indiceColonne, indiceLigne + 2, indiceColonne, indiceLigne + 1, indiceColonne, tabSolutions, '+', taille, cible); // On affiche le résultat

    if (grille[indiceLigne + 2][indiceColonne] * grille[indiceLigne][indiceColonne] - grille[indiceLigne + 1][indiceColonne] == cible)                         // Si grille[0][0] * grille[2][0] - grille[1][0] == cible
        ajouteSolutions(grille, indiceLigne + 2, indiceColonne, indiceLigne, indiceColonne, indiceLigne + 1, indiceColonne, tabSolutions, '-', taille, cible); // On affiche le résultat
    if (grille[indiceLigne + 2][indiceColonne] * grille[indiceLigne][indiceColonne] + grille[indiceLigne + 1][indiceColonne] == cible)                         // Si grille[0][0] * grille[2][0] + grille[1][0] == cible
        ajouteSolutions(grille, indiceLigne + 2, indiceColonne, indiceLigne, indiceColonne, indiceLigne + 1, indiceColonne, tabSolutions, '+', taille, cible); // On affiche le résultat

    if (grille[indiceLigne + 1][indiceColonne] * grille[indiceLigne + 2][indiceColonne] - grille[indiceLigne][indiceColonne] == cible)                         // Si grille[1][0] * grille[2][0] - grille[0][0] == cible
        ajouteSolutions(grille, indiceLigne + 1, indiceColonne, indiceLigne + 2, indiceColonne, indiceLigne, indiceColonne, tabSolutions, '-', taille, cible); // On affiche le résultat
    if (grille[indiceLigne + 1][indiceColonne] * grille[indiceLigne + 2][indiceColonne] + grille[indiceLigne][indiceColonne] == cible)                         // Si grille[1][0] * grille[2][0] + grille[0][0] == cible
        ajouteSolutions(grille, indiceLigne + 1, indiceColonne, indiceLigne + 2, indiceColonne, indiceLigne, indiceColonne, tabSolutions, '+', taille, cible); // On affiche le résultat

    if (grille[indiceLigne + 2][indiceColonne] * grille[indiceLigne + 1][indiceColonne] - grille[indiceLigne][indiceColonne] == cible)                         // Si grille[1][0] * grille[2][0] - grille[0][0] == cible
        ajouteSolutions(grille, indiceLigne + 2, indiceColonne, indiceLigne + 1, indiceColonne, indiceLigne, indiceColonne, tabSolutions, '-', taille, cible); // On affiche le résultat
    if (grille[indiceLigne + 2][indiceColonne] * grille[indiceLigne + 1][indiceColonne] + grille[indiceLigne][indiceColonne] == cible)                         // Si grille[1][0] * grille[2][0] + grille[0][0] == cible
        ajouteSolutions(grille, indiceLigne + 2, indiceColonne, indiceLigne + 1, indiceColonne, indiceLigne, indiceColonne, tabSolutions, '+', taille, cible); // On affiche le résultat
}

void test_diagonale_droite2(int grille[10][10], int indiceLigne, int indiceColonne, int cible, solution tabSolutions[], int *taille)
{
    if (grille[indiceLigne][indiceColonne] * grille[indiceLigne + 1][indiceColonne + 1] - grille[indiceLigne + 2][indiceColonne + 2] == cible)                         // Si grille[0][0] * grille[1][1] - grille[2][2] == cible
        ajouteSolutions(grille, indiceLigne, indiceColonne, indiceLigne + 1, indiceColonne + 1, indiceLigne + 2, indiceColonne + 2, tabSolutions, '-', taille, cible); // On affiche le résultat
    if (grille[indiceLigne][indiceColonne] * grille[indiceLigne + 1][indiceColonne + 1] + grille[indiceLigne + 2][indiceColonne + 2] == cible)                         // Si grille[0][0] * grille[1][1] + grille[2][2] == cible
        ajouteSolutions(grille, indiceLigne, indiceColonne, indiceLigne + 1, indiceColonne + 1, indiceLigne + 2, indiceColonne + 2, tabSolutions, '+', taille, cible); // On affiche le résultat

    if (grille[indiceLigne + 1][indiceColonne + 1] * grille[indiceLigne][indiceColonne] - grille[indiceLigne + 2][indiceColonne + 2] == cible)                         // Si grille[0][0] * grille[1][1] - grille[2][2] == cible
        ajouteSolutions(grille, indiceLigne + 1, indiceColonne + 1, indiceLigne, indiceColonne, indiceLigne + 2, indiceColonne + 2, tabSolutions, '-', taille, cible); // On affiche le résultat
    if (grille[indiceLigne + 1][indiceColonne + 1] * grille[indiceLigne][indiceColonne] + grille[indiceLigne + 2][indiceColonne + 2] == cible)                         // Si grille[0][0] * grille[1][1] + grille[2][2] == cible
        ajouteSolutions(grille, indiceLigne + 1, indiceColonne + 1, indiceLigne, indiceColonne, indiceLigne + 2, indiceColonne + 2, tabSolutions, '+', taille, cible); // On affiche le résultat

    if (grille[indiceLigne][indiceColonne] * grille[indiceLigne + 2][indiceColonne + 2] - grille[indiceLigne + 1][indiceColonne + 1] == cible)                         // Si grille[0][0] * grille[2][2] - grille[1][1] == cible
        ajouteSolutions(grille, indiceLigne, indiceColonne, indiceLigne + 2, indiceColonne + 2, indiceLigne + 1, indiceColonne + 1, tabSolutions, '-', taille, cible); // On affiche le résultat
    if (grille[indiceLigne][indiceColonne] * grille[indiceLigne + 2][indiceColonne + 2] + grille[indiceLigne + 1][indiceColonne + 1] == cible)                         // Si grille[0][0] * grille[2][2] + grille[1][1] == cible
        ajouteSolutions(grille, indiceLigne, indiceColonne, indiceLigne + 2, indiceColonne + 2, indiceLigne + 1, indiceColonne + 1, tabSolutions, '+', taille, cible); // On affiche le résultat

    if (grille[indiceLigne + 2][indiceColonne + 2] * grille[indiceLigne][indiceColonne] - grille[indiceLigne + 1][indiceColonne + 1] == cible)                         // Si grille[0][0] * grille[2][2] - grille[1][1] == cible
        ajouteSolutions(grille, indiceLigne + 2, indiceColonne + 2, indiceLigne, indiceColonne, indiceLigne + 1, indiceColonne + 1, tabSolutions, '-', taille, cible); // On affiche le résultat
    if (grille[indiceLigne + 2][indiceColonne + 2] * grille[indiceLigne][indiceColonne] + grille[indiceLigne + 1][indiceColonne + 1] == cible)                         // Si grille[0][0] * grille[2][2] + grille[1][1] == cible
        ajouteSolutions(grille, indiceLigne + 2, indiceColonne + 2, indiceLigne, indiceColonne, indiceLigne + 1, indiceColonne + 1, tabSolutions, '+', taille, cible); // On affiche le résultat

    if (grille[indiceLigne + 1][indiceColonne + 1] * grille[indiceLigne + 2][indiceColonne + 2] - grille[indiceLigne][indiceColonne] == cible)                         // Si grille[1][1] * grille[2][2] - grille[0][0] == cible
        ajouteSolutions(grille, indiceLigne + 1, indiceColonne + 1, indiceLigne + 2, indiceColonne + 2, indiceLigne, indiceColonne, tabSolutions, '-', taille, cible); // On affiche le résultat
    if (grille[indiceLigne + 1][indiceColonne + 1] * grille[indiceLigne + 2][indiceColonne + 2] + grille[indiceLigne][indiceColonne] == cible)                         // Si grille[1][1] * grille[2][2] + grille[0][0] == cible
        ajouteSolutions(grille, indiceLigne + 1, indiceColonne + 1, indiceLigne + 2, indiceColonne + 2, indiceLigne, indiceColonne, tabSolutions, '+', taille, cible); // On affiche le résultat

    if (grille[indiceLigne + 2][indiceColonne + 2] * grille[indiceLigne + 1][indiceColonne + 1] - grille[indiceLigne][indiceColonne] == cible)                         // Si grille[1][1] * grille[2][2] - grille[0][0] == cible
        ajouteSolutions(grille, indiceLigne + 2, indiceColonne + 2, indiceLigne + 1, indiceColonne + 1, indiceLigne, indiceColonne, tabSolutions, '-', taille, cible); // On affiche le résultat
    if (grille[indiceLigne + 2][indiceColonne + 2] * grille[indiceLigne + 1][indiceColonne + 1] + grille[indiceLigne][indiceColonne] == cible)                         // Si grille[1][1] * grille[2][2] + grille[0][0] == cible
        ajouteSolutions(grille, indiceLigne + 2, indiceColonne + 2, indiceLigne + 1, indiceColonne + 1, indiceLigne, indiceColonne, tabSolutions, '+', taille, cible); // On affiche le résultat
}

void test_diagonale_gauche2(int grille[10][10], int indiceLigne, int indiceColonne, int cible, solution tabSolutions[], int *taille)
{
    if (grille[indiceLigne][indiceColonne] * grille[indiceLigne + 1][indiceColonne - 1] - grille[indiceLigne + 2][indiceColonne - 2] == cible)                         // Si grille[0][0] * grille[1][-1] - grille[2][-2] == cible
        ajouteSolutions(grille, indiceLigne, indiceColonne, indiceLigne + 1, indiceColonne - 1, indiceLigne + 2, indiceColonne - 2, tabSolutions, '-', taille, cible); // On affiche le résultat
    if (grille[indiceLigne][indiceColonne] * grille[indiceLigne + 1][indiceColonne - 1] + grille[indiceLigne + 2][indiceColonne - 2] == cible)                         // Si grille[0][0] * grille[1][-1] + grille[2][-2] == cible
        ajouteSolutions(grille, indiceLigne, indiceColonne, indiceLigne + 1, indiceColonne - 1, indiceLigne + 2, indiceColonne - 2, tabSolutions, '+', taille, cible); // On affiche le résultat

    if (grille[indiceLigne + 1][indiceColonne - 1] * grille[indiceLigne][indiceColonne] - grille[indiceLigne + 2][indiceColonne - 2] == cible)                         // Si grille[1][1] * grille[0][0] - grille[2][-2] == cible
        ajouteSolutions(grille, indiceLigne + 1, indiceColonne - 1, indiceLigne, indiceColonne, indiceLigne + 2, indiceColonne - 2, tabSolutions, '-', taille, cible); // On affiche le résultat
    if (grille[indiceLigne + 1][indiceColonne - 1] * grille[indiceLigne][indiceColonne] + grille[indiceLigne + 2][indiceColonne - 2] == cible)                         // Si grille[1][1] * grille[0][0] + grille[2][-2] == cible
        ajouteSolutions(grille, indiceLigne + 1, indiceColonne - 1, indiceLigne, indiceColonne, indiceLigne + 2, indiceColonne - 2, tabSolutions, '+', taille, cible); // On affiche le résultat

    if (grille[indiceLigne][indiceColonne] * grille[indiceLigne + 2][indiceColonne - 2] - grille[indiceLigne + 1][indiceColonne - 1] == cible)                         // Si grille[0][0] * grille[2][-2] - grille[1][1] == cible
        ajouteSolutions(grille, indiceLigne, indiceColonne, indiceLigne + 2, indiceColonne - 2, indiceLigne + 1, indiceColonne - 1, tabSolutions, '-', taille, cible); // On affiche le résultat
    if (grille[indiceLigne][indiceColonne] * grille[indiceLigne + 2][indiceColonne - 2] + grille[indiceLigne + 1][indiceColonne - 1] == cible)                         // Si grille[0][0] * grille[2][-2] + grille[1][1] == cible
        ajouteSolutions(grille, indiceLigne, indiceColonne, indiceLigne + 2, indiceColonne - 2, indiceLigne + 1, indiceColonne - 1, tabSolutions, '+', taille, cible); // On affiche le résultat

    if (grille[indiceLigne + 2][indiceColonne - 2] * grille[indiceLigne][indiceColonne] - grille[indiceLigne + 1][indiceColonne - 1] == cible)                         // Si grille[2][-2] * grille[0][0] - grille[1][1] == cible
        ajouteSolutions(grille, indiceLigne + 2, indiceColonne - 2, indiceLigne, indiceColonne, indiceLigne + 1, indiceColonne - 1, tabSolutions, '-', taille, cible); // On affiche le résultat
    if (grille[indiceLigne + 2][indiceColonne - 2] * grille[indiceLigne][indiceColonne] + grille[indiceLigne + 1][indiceColonne - 1] == cible)                         // Si grille[2][-2] * grille[0][0] + grille[1][1] == cible
        ajouteSolutions(grille, indiceLigne + 2, indiceColonne - 2, indiceLigne, indiceColonne, indiceLigne + 1, indiceColonne - 1, tabSolutions, '+', taille, cible); // On affiche le résultat

    if (grille[indiceLigne + 1][indiceColonne - 1] * grille[indiceLigne + 2][indiceColonne - 2] - grille[indiceLigne][indiceColonne] == cible)                         // Si grille[1][1] * grille[2][-2] - grille[0][0] == cible
        ajouteSolutions(grille, indiceLigne + 1, indiceColonne - 1, indiceLigne + 2, indiceColonne - 2, indiceLigne, indiceColonne, tabSolutions, '-', taille, cible); // On affiche le résultat
    if (grille[indiceLigne + 1][indiceColonne - 1] * grille[indiceLigne + 2][indiceColonne - 2] + grille[indiceLigne][indiceColonne] == cible)                         // Si grille[1][1] * grille[2][-2] - grille[0][0] == cible
        ajouteSolutions(grille, indiceLigne + 1, indiceColonne - 1, indiceLigne + 2, indiceColonne - 2, indiceLigne, indiceColonne, tabSolutions, '+', taille, cible); // On affiche le résultat

    if (grille[indiceLigne + 2][indiceColonne - 2] * grille[indiceLigne + 1][indiceColonne - 1] - grille[indiceLigne][indiceColonne] == cible)                         // Si grille[2][-2] * grille[1][1] - grille[0][0] == cible
        ajouteSolutions(grille, indiceLigne + 2, indiceColonne - 2, indiceLigne + 1, indiceColonne - 1, indiceLigne, indiceColonne, tabSolutions, '-', taille, cible); // On affiche le résultat
    if (grille[indiceLigne + 2][indiceColonne - 2] * grille[indiceLigne + 1][indiceColonne - 1] + grille[indiceLigne][indiceColonne] == cible)                         // Si grille[2][-2] * grille[1][1] - grille[0][0] == cible
        ajouteSolutions(grille, indiceLigne + 2, indiceColonne - 2, indiceLigne + 1, indiceColonne - 1, indiceLigne, indiceColonne, tabSolutions, '+', taille, cible); // On affiche le résultat
}

void ajouteSolutions(int grille[10][10], int A0, int A1, int B0, int B1, int C0, int C1, solution tabSolutions[], char signe, int *taille, int cible)
{
    tabSolutions[*(taille)].a = grille[A0][A1];
    tabSolutions[*(taille)].b = grille[B0][B1];
    tabSolutions[*(taille)].op = signe;
    tabSolutions[*(taille)].c = grille[C0][C1];
    tabSolutions[*(taille)].cible = cible;
    *(taille) += 1;
}

int compare (const void * a, const void * b)
{
    solution *orderA = (solution *)a;
    solution *orderB = (solution *)b;
    return orderA->a - orderB->a;
}


void affichageSolutions(solution tabSolutions[], int *taille, int cible)
{
    printf("\nAffichage de tous les calculs permettant d'obtenir le nombre %d\n", cible);
    qsort (tabSolutions, (*taille), sizeof(solution), compare) ;
    for (int i = 0; i < (*taille); i++)
    {
        printf("%d x %d %c %d = %d\n", tabSolutions[i].a, tabSolutions[i].b, tabSolutions[i].op, tabSolutions[i].c, tabSolutions[i].cible);
    }
}
