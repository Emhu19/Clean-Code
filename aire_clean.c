#include <stdio.h>
#include <stdlib.h>

/*
 * Demande une dimension (largeur ou hauteur) à l'utilisateur
 * et vérifie si l'entrée est valide.
 * @param prompt Le message à afficher (ex : "Entrez la largeur : ").
 * @return La dimension saisie par l'utilisateur.
 */
double demanderDimension(const char* prompt) {
    double dimension;
    printf("%s", prompt);
    while (scanf("%lf", &dimension) != 1 || dimension <= 0) {
        printf("Entrée invalide. Veuillez entrer un nombre positif : ");
        while (getchar() != '\n'); // Vider le buffer
    }
    return dimension;
}

/*
 * Calcule l'aire d'un rectangle.
 * @param largeur La largeur du rectangle.
 * @param hauteur La hauteur du rectangle.
 * @return L'aire calculée.
 */
double calculerAire(double largeur, double hauteur) {
    return largeur * hauteur;
}

/*
 * Point d'entrée du programme.
 * Demande les dimensions du rectangle, calcule et affiche l'aire.
 */
int main() {
    double largeur = demanderDimension("Entrez la largeur du rectangle : ");
    double hauteur = demanderDimension("Entrez la hauteur du rectangle : ");
    double aire = calculerAire(largeur, hauteur);

    printf("L'aire du rectangle est : %.2lf\n", aire);
    return EXIT_SUCCESS;
}
