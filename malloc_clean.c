#include <stdio.h>
#include <stdlib.h>
//Objectif : faire la Somme et Moyenne d’un Tableau Dynamique

/*
 * Demande un entier positif à l'utilisateur.
 * @param prompt Le message à afficher pour demander l'entrée.
 * @return Un entier strictement positif.
 */
int demanderEntierPositif(const char *prompt) {
    int valeur;
    printf("%s", prompt);
    while (scanf("%d", &valeur) != 1 || valeur <= 0) {
        printf("Entrée invalide. Veuillez entrer un entier positif : ");
        while (getchar() != '\n'); // Vider le buffer
    }
    return valeur;
}

/*
 * Remplit un tableau d'entiers avec des valeurs saisies par l'utilisateur.
 * @param tableau Pointeur vers le tableau d'entiers.
 * @param taille Nombre d'éléments dans le tableau.
 */
void remplirTableau(int *tableau, int taille) {
    for (int i = 0; i < taille; i++) {
        printf("Entrez la valeur %d : ", i + 1);
        while (scanf("%d", &tableau[i]) != 1) {
            printf("Entrée invalide. Veuillez entrer un nombre entier : ");
            while (getchar() != '\n'); // Vider le buffer
        }
    }
}

/*
 * Calcule la somme des éléments d'un tableau.
 * @param tableau Pointeur vers le tableau d'entiers.
 * @param taille Nombre d'éléments dans le tableau.
 * @return La somme des éléments.
 */
int calculerSomme(const int *tableau, int taille) {
    int somme = 0;
    for (int i = 0; i < taille; i++) {
        somme += tableau[i];
    }
    return somme;
}

/*
 * Point d'entrée principal du programme.
 * Gère la saisie, les calculs, et l'affichage des résultats.
 */
int main() {
    int taille = demanderEntierPositif("Entrez le nombre de valeurs : ");
    int *tableau = (int *)malloc(taille * sizeof(int));

    if (tableau == NULL) {
        printf("Erreur : impossible d'allouer la mémoire.\n");
        return EXIT_FAILURE;
    }

    remplirTableau(tableau, taille);

    int somme = calculerSomme(tableau, taille);
    double moyenne = somme / (double)taille;

    printf("\nRésultats :\n");
    printf("Somme = %d\n", somme);
    printf("Moyenne = %.2f\n", moyenne);

    free(tableau);
    return EXIT_SUCCESS;
}
