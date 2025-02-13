#include <stdio.h>
#include <stdlib.h>

int main() {
    double a, b, res;
    char op;

    printf("Saisissez une opération (ex: 2 + 2) : ");
    if (scanf("%lf %c %lf", &a, &op, &b) != 3) {
        printf("Entrée invalide.\n");
        return 1;
    }

    if (op == '+')
        res = a + b;
    else if (op == '-')
        res = a - b;
    else if (op == '*')
        res = a * b;
    else if (op == '/') {
        if (b == 0) {
            printf("Division par zéro impossible.\n");
            return 1;
        }
        res = a / b;
    }
    else {
        printf("Opérateur non supporté.\n");
        return 1;
    }

    printf("Résultat: %lf\n", res);
    return 0;
}
