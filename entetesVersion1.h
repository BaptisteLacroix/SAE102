#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void version1 (int grille [10][10], int largeur, int cible) ;

void test_ligne(int grille[10][10], int indiceLigne, int indiceColonne, int cible, int * trouve);
void test_colonne(int grille[10][10], int indiceLigne, int indiceColonne, int cible, int * trouve);
void test_diagonale_droite(int grille[10][10], int indiceLigne, int indiceColonne, int cible, int * trouve);
void test_diagonale_gauche(int grille[10][10], int indiceLigne, int indiceColonne, int cible, int * trouve);

void affiche_solution_moins(int grille[10][10], int A0, int A1, int B0, int B1, int C0, int C1, int * trouve);
void affiche_solution_plus(int grille[10][10], int A0, int A1, int B0, int B1, int C0, int C1, int * trouve);