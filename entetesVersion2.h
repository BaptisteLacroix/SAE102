
typedef struct
{
    int     a ;
    int     b ;
    int     c ;
    int     cible ;
    char    op ;       /// vaut '+' ou '-'
} solution ;


void version2 (int grille [10][10], int largeur, int cible, solution tabSolutions [], int *taille);

void test_ligne2(int grille[10][10], int indiceLigne, int indiceColonne, int cible, solution tabSolutions[], int *taille);

void test_colonne2(int grille[10][10], int indiceLigne, int indiceColonne, int cible, solution tabSolutions[], int *taille);

void test_diagonale_droite2(int grille[10][10], int indiceLigne, int indiceColonne, int cible, solution tabSolutions[], int *taille);

void test_diagonale_gauche2(int grille[10][10], int indiceLigne, int indiceColonne, int cible, solution tabSolutions[], int *taille);

void ajouteSolutions(int grille[10][10], int A0, int A1, int B0, int B1, int C0, int C1, solution tabSolutions[], char signe, int *taille, int cible);

int compare (const void * a, const void * b);

void affichageSolutions(solution tabSolutions[], int *taille, int cible);