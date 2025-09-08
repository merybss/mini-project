#include <stdio.h>
#include <string.h>

int main() {
    char mot[] = "wice";
    char mot_cacher[] = {'_', '_', '_', '_','\0'};
    char lettre;
    int i;
    int taille = strlen(mot);
    int trouve;
    int lettres_restantes = taille;
    int tentatives = 5;
    int erreurs = 0;

    printf("Le mot caché : %s\n", mot_cacher);


    while (lettres_restantes > 0 && erreurs < tentatives) {
        printf("\nEntrer une lettre : ");
        scanf(" %c", &lettre);

        trouve = 0;


        for (i = 0; i < taille; i++) {
            if (mot[i] == lettre && mot_cacher[i] == '_') {
                mot_cacher[i] = lettre;
                lettres_restantes--;
                trouve = 1;
            }
        }


        printf("Mot caché : %s\n", mot_cacher);

        if (trouve == 1) {
            printf("Bravo ! Entrer la lettre suivante.\n");
        } else {
            erreurs++;
            printf("Oops ! Lettre incorrecte. Tentatives restantes : %d\n", tentatives - erreurs);
        }
    }


    if (lettres_restantes == 0) {
        printf("\nFélicitations ! Vous avez trouvé le mot : %s\n", mot);
    } else {
        printf("\nGame Over ! Le mot était : %s\n", mot);
    }

    return 0;
}
