#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define LEN 50
#define TEL 20

typedef struct {
    char n[LEN];
    char t[TEL];
} C;

C cs[MAX];
int cnt = 0;

int main() {
    int o;
    while (1) {
        printf("1: Ajouter un contact, 2: Lister, 3: Chercher, 4: Quitter\n");
        if (scanf("%d", &o) != 1) {
            printf("Erreur d'entrée\n");
            exit(1);
        }
        while(getchar()!='\n');  // vider le buffer

        if(o == 1) {
            if (cnt >= MAX) {
                printf("Limite atteinte\n");
                continue;
            }
            C temp;
            printf("Nom : ");
            fgets(temp.n, LEN, stdin);
            temp.n[strcspn(temp.n, "\n")] = '\0';
            printf("Téléphone : ");
            fgets(temp.t, TEL, stdin);
            temp.t[strcspn(temp.t, "\n")] = '\0';
            cs[cnt++] = temp;
            printf("Contact ajouté !\n");
        } else if(o == 2) {
            int i;
            if(cnt == 0) {
                printf("Aucun contact\n");
            }
            for(i = 0; i < cnt; i++) {
                printf("%d. %s - %s\n", i+1, cs[i].n, cs[i].t);
            }
        } else if(o == 3) {
            char s[LEN];
            int i, f = 0;
            printf("Recherche (nom) : ");
            fgets(s, LEN, stdin);
            s[strcspn(s, "\n")] = '\0';
            for(i = 0; i < cnt; i++) {
                if (strstr(cs[i].n, s) != NULL) {
                    printf("%d. %s - %s\n", i+1, cs[i].n, cs[i].t);
                    f = 1;
                }
            }
            if(!f) printf("Aucun contact trouvé\n");
        } else if(o == 4) {
            break;
        } else {
            printf("Option invalide\n");
        }
        printf("\n");
    }
    return 0;
}
