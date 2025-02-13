/*
 * Gestionnaire de Contacts - Version Clean Code
 *
 * Ce programme permet de gérer une liste de contacts avec des fonctionnalités
 * d'ajout, de listage et de recherche de contacts par nom.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

Contact contacts[MAX_CONTACTS];
int contactCount = 0;

void displayMenu(void);
void addContact(void);
void listContacts(void);
void searchContact(void);

/*
 * Affiche le menu principal du gestionnaire de contacts.
 */
void displayMenu(void) {
    printf("==== Gestionnaire de Contacts ====\n");
    printf("1. Ajouter un contact\n");
    printf("2. Lister les contacts\n");
    printf("3. Rechercher un contact\n");
    printf("4. Quitter\n");
    printf("Votre choix : ");
}

/*
 * Ajoute un nouveau contact dans le tableau des contacts.
 */
void addContact(void) {
    if (contactCount >= MAX_CONTACTS) {
        printf("Limite de contacts atteinte.\n");
        return;
    }

    Contact newContact;
    printf("Entrez le nom : ");
    if (fgets(newContact.name, NAME_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Erreur lors de la lecture du nom.\n");
        return;
    }
    newContact.name[strcspn(newContact.name, "\n")] = '\0';

    printf("Entrez le numéro de téléphone : ");
    if (fgets(newContact.phone, PHONE_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Erreur lors de la lecture du numéro de téléphone.\n");
        return;
    }
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0';

    contacts[contactCount++] = newContact;
    printf("Contact ajouté avec succès !\n");
}

/*
 * Affiche la liste de tous les contacts enregistrés.
 */
void listContacts(void) {
    if (contactCount == 0) {
        printf("Aucun contact disponible.\n");
        return;
    }

    printf("Liste des contacts :\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. Nom : %s | Téléphone : %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

/*
 * Recherche et affiche les contacts dont le nom contient la chaîne recherchée.
 */
void searchContact(void) {
    char searchTerm[NAME_LENGTH];
    printf("Entrez le nom à rechercher : ");
    if (fgets(searchTerm, NAME_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Erreur lors de la lecture de la recherche.\n");
        return;
    }
    searchTerm[strcspn(searchTerm, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strstr(contacts[i].name, searchTerm) != NULL) {
            if (!found) {
                printf("Contacts trouvés :\n");
            }
            printf("%d. Nom : %s | Téléphone : %s\n", i + 1, contacts[i].name, contacts[i].phone);
            found = 1;
        }
    }
    if (!found) {
        printf("Aucun contact trouvé correspondant à '%s'.\n", searchTerm);
    }
}

/*
 * Point d'entrée du programme.
 */
int main(void) {
    int choice = 0;

    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Entrée invalide. Veuillez entrer un nombre.\n");
            while (getchar() != '\n'); // Vider le buffer d'entrée
            continue;
        }
        while (getchar() != '\n'); // Nettoyer le buffer après scanf

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                listContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                printf("Au revoir !\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Option non valide. Veuillez réessayer.\n");
                break;
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}
