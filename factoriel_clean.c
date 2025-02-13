#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
 * Calcule la factorielle d'un entier non négatif.
 *
 * @param n L'entier dont on souhaite calculer la factorielle.
 * @return La factorielle de n.
 */
unsigned long long calculerFactorielle(int n) {
    if(n < 0) {
        // La factorielle n'est définie que pour n >= 0.
        return 0;
    }
    unsigned long long resultat = 1;
    for (int i = 1; i <= n; i++) {
        resultat *= i;
    }
    return resultat;
}

/*
 * Exécute les tests unitaires pour la fonction calculerFactorielle.
 */
void lancerTests() {
    assert(calculerFactorielle(0) == 1);
    assert(calculerFactorielle(1) == 1);
    assert(calculerFactorielle(2) == 2);
    assert(calculerFactorielle(3) == 6);
    assert(calculerFactorielle(4) == 24);
    assert(calculerFactorielle(5) == 120);
    // Test sur une valeur plus élevée
    assert(calculerFactorielle(10) == 3628800ULL);

    printf("Tous les tests unitaires ont réussi.\n");
}

/*
 * Fonction principale en mode production ou test.
 * Permet à l'utilisateur de choisir d'exécuter le calcul de la factorielle
 * ou de lancer les tests unitaires.
 */
int main() {
    int mode;

    printf("Choisissez le mode :\n");
    printf("1. Calcul de la factorielle\n");
    printf("2. Lancer les tests unitaires\n");
    printf("Votre choix : ");

    if (scanf("%d", &mode) != 1) {
        printf("Erreur de saisie.\n");
        return EXIT_FAILURE;
    }

    if(mode == 2) {
        lancerTests();
        return EXIT_SUCCESS;
    } else if (mode == 1) {
        int n;
        printf("Entrez un entier positif : ");
        if (scanf("%d", &n) != 1 || n < 0) {
            printf("Entrée invalide.\n");
            return EXIT_FAILURE;
        }
        unsigned long long fact = calculerFactorielle(n);
        printf("La factorielle de %d est : %llu\n", n, fact);
    } else {
        printf("Mode invalide.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
