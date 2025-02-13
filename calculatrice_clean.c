#include <stdio.h>
#include <stdlib.h>

/*
 * Effectue l'opération arithmétique entre deux opérandes.
 *
 * @param operand1 Le premier opérande.
 * @param operand2 Le deuxième opérande.
 * @param operator L'opérateur arithmétique (+, -, *, /).
 * @return Le résultat de l'opération.
 * En cas d'erreur (division par zéro ou opérateur inconnu), le programme se termine.
 */
double performOperation(double operand1, double operand2, char operator) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                fprintf(stderr, "Erreur : Division par zéro impossible.\n");
                exit(EXIT_FAILURE);
            }
            return operand1 / operand2;
        default:
            fprintf(stderr, "Erreur : Opérateur '%c' non supporté.\n", operator);
            exit(EXIT_FAILURE);
    }
}

/*
 * Affiche l'invite à l'utilisateur pour saisir une opération.
 */
void displayPrompt(void) {
    printf("Veuillez entrer une opération (ex: 3.5 * 2) : ");
}

int main(void) {
    double operand1, operand2;
    char operator;

    displayPrompt();

    if (scanf("%lf %c %lf", &operand1, &operator, &operand2) != 3) {
        fprintf(stderr, "Erreur : Format d'entrée invalide.\n");
        return EXIT_FAILURE;
    }

    double result = performOperation(operand1, operand2, operator);
    printf("Résultat : %.2lf\n", result);

    return EXIT_SUCCESS;
}
