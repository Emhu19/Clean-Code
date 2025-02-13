#include <stdio.h>
#include <stdlib.h>
//Objectif : faire la Somme et Moyenne d’un Tableau Dynamique

int main() {
    int n, i; // n est la taille du tableau, i est pour les boucles
    printf("Entrez le nombre de valeurs : ");
    scanf("%d", &n);
    int *tab = (int*)malloc(n * sizeof(int)); // Alloue le tableau
    if (!tab) {
        printf("Erreur d'allocation\n");
        return 1;
    }
    for (i = 0; i < n; i++) { // Remplit le tableau
        printf("Entrez la valeur %d : ", i + 1);
        scanf("%d", &tab[i]);
    }
    int somme = 0;
    for (i = 0; i < n; i++) { // Calcule la somme
        somme += tab[i];
    }
    printf("Somme = %d\n", somme);
    printf("Moyenne = %.2f\n", somme / (double)n);
    free(tab); // Libère le tableau
    return 0;
}
