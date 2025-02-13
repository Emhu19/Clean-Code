#include <stdio.h>

// Ceci est un programme qui calcule l'aire d'un rectangle
int main() {
    double x, y; // x est la largeur, y est la hauteur
    double a; // a sera l'aire
    printf("Entrez la largeur du rectangle : "); // Demande la largeur
    scanf("%lf", &x); // Lecture de x
    printf("Entrez la hauteur du rectangle : "); // Demande la hauteur
    scanf("%lf", &y); // Lecture de y
    a = x * y; // Calcul de l'aire
    printf("L'aire du rectangle est : %lf\n", a); // Affiche l'aire
    return 0; // Fin du programme
}
