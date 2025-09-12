#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TEXTE 100
#define MAX_HISTORIQUE 50

char *rep_salutation[3] = {
    "Bonjour !",
    "Salut !",
    "Je suis content de vous parler."
};

char *rep_heureuse[3] = {
    "Je suis content pour toi.",
    "C’est génial d’être heureux.",
    "Le bonheur est contagieux, bravo !"
};

char *rep_joie[3] = {
    "J’adore entendre ça !",
    "Qu’est-ce qui t’apporte de la joie ?",
    "Ça a l’air merveilleux."
};

char *rep_triste[3] = {
    "Je suis désolé que tu te sentes mal. Veux-tu en parler ?",
    "C’est normal de se sentir triste parfois.",
    "Je suis là si tu veux discuter."
};

char *rep_peur[3] = {
    "Ça a l’air effrayant.",
    "Veux-tu partager tes peurs ?",
    "Tu n’es pas seul."
};

char *rep_colere[3] = {
    "Ça doit être frustrant.",
    "Veux-tu te défouler un peu ?",
    "Je suis là pour t’aider à te calmer."
};

char *rep_anxiete[3] = {
    "Je comprends que tu sois anxieux.",
    "Respire profondément, ça peut aider.",
    "Tu n’es pas seul dans ce que tu ressens."
};

char *rep_neutre[3] = {
    "Tu devrais te reposer un peu.",
    "Un bon sommeil aide toujours.",
    "Prends soin de toi."
};

// Tableau regroupant toutes les réponses
char **tous_les_reponse[7] = {
    rep_heureuse,
    rep_joie,
    rep_triste,
    rep_peur,
    rep_colere,
    rep_anxiete,
    rep_neutre
};

// Tableau des mots-clés associés
char *mot_cle[7] = {
    "heureuse","joie","triste",
    "peur","colère","anxiete","neutre"
};

int main() {
    int i, r, trouve, compteur = 0;
    char saisie[MAX_TEXTE];
    char *pntr;
    char historique[MAX_HISTORIQUE][MAX_TEXTE];

    srand(time(NULL));

    printf(" Tapez vos messages (ecrivez 'stop' pour arreter)\n");

    while (1) {
        printf("Vous: ");
        fgets(saisie, sizeof(saisie), stdin);
        saisie[strcspn(saisie, "\n")] = '\0'; // enlever le \n

        if (strcmp(saisie, "stop") == 0) {
            break;
        }


        snprintf(historique[compteur], MAX_TEXTE, "Vous: %s", saisie);
        compteur++;


        if (compteur >= MAX_HISTORIQUE) {
            printf(" Vous avez atteint le maximum de l’historique.\n");
            break;
        }

        // Chercher un mot clé
        trouve = 0;
        for (i = 0; i < 7; i++) {
            pntr = strstr(saisie, mot_cle[i]);
            if (pntr != NULL) {
                r = rand() % 3;
                printf("Bot: %s\n", tous_les_reponse[i][r]);
                trouve = 1;
                break;
            }
        }

        if (!trouve) {
            printf("Bot: Peux-tu préciser ?\n");
        }
    }


    printf("\nHistorique des messages:\n");
    for (i = 0; i < compteur; i++) {
        printf("%d. %s\n", i + 1, historique[i]);
    }

    return 0;
}
