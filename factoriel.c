#include <stdio.h>
//Objectif rajouter des Tests unitaires
int main() {
    int n, i;
    unsigned long long fact = 1;

    printf("Entrez un entier positif : ");
    scanf("%d", &n);

    if(n < 0) {
        printf("Erreur : l'entier doit être positif.\n");
        return 1;
    }

    // Calcul de la factorielle directement dans le main
    for(i = 1; i <= n; i++) {
        fact *= i;
    }

    printf("La factorielle de %d est : %llu\n", n, fact);
    return 0;
}
