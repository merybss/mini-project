#include <stdio.h>
#include <stdlib.h>

#define MAX_ETUDIANTS 50
#define MAX_COURS 20

// Définir les structures
struct Etudiant {
    int ID;
    char nom[50];
    char prenom[50];
    int age;
    float moyenne;
};

struct Cours {
    int code;
    char nom[50];
    int credit;
    float note;
};

// Variables globales
struct Etudiant liste_etudiants[MAX_ETUDIANTS];
int nombre_etudiants = 0;

struct Cours liste_cours[MAX_COURS];
int nombre_cours = 0;

// Ajouter un étudiant
void ajouter_etudiant() {
        struct Etudiant a;
    if (nombre_etudiants >= MAX_ETUDIANTS) {
        printf("Vous avez atteint le maximum d'etudiants\n");
        return;
    }


    printf("ID: ");
    scanf("%d", &a.ID);
    printf("Nom: ");
    scanf("%s", a.nom);
    printf("Prenom: ");
    scanf("%s", a.prenom);
    printf("Age: ");
    scanf("%d", &a.age);
    printf("Moyenne: ");
    scanf("%f", &a.moyenne);

    liste_etudiants[nombre_etudiants++] = a;
    printf("Vous avez ajouté l'etudiant avec succès\n");
}

// Afficher les étudiants
void afficher_etudiants() {
    int i;
    if (nombre_etudiants == 0) {
        printf("Aucun étudiant n'est enregistré\n");
        return;
    }

    for ( i = 0; i < nombre_etudiants; i++) {
        printf("\n----- Etudiant %d -----\n", i + 1);
        printf("ID = %d\n", liste_etudiants[i].ID);
        printf("Nom = %s\n", liste_etudiants[i].nom);
        printf("Prenom = %s\n", liste_etudiants[i].prenom);
        printf("Age = %d\n", liste_etudiants[i].age);
        printf("Moyenne = %.2f\n", liste_etudiants[i].moyenne);
    }
}

// Ajouter un cours
void ajouter_cours() {
    struct Cours x;
    if (nombre_cours >= MAX_COURS) {
        printf("Vous avez atteint le nombre maximum de cours.\n");
        return;
    }


    printf("Code: ");
    scanf("%d", &x.code);
    printf("Nom: ");
    scanf("%s", x.nom);
    printf("Crédit: ");
    scanf("%d", &x.credit);
    printf("Note: ");
    scanf("%f", &x.note);

    liste_cours[nombre_cours++] = x;
    printf("Ajout du cours avec succès\n");
}

// Afficher les cours
void afficher_cours() {
    int i;
    if (nombre_cours == 0) {
        printf("Aucun cours n'est enregistré\n");
        return;
    }

    for ( i = 0; i < nombre_cours; i++) {
        printf("\n----- Cours %d -----\n", i + 1);
        printf("Code = %d\n", liste_cours[i].code);
        printf("Nom = %s\n", liste_cours[i].nom);
        printf("Credit = %d\n", liste_cours[i].credit);
        printf("Note = %.2f\n", liste_cours[i].note);
    }
}

// Menu principal
int main() {
    int choix;

    do {
        printf("\n===== Menu Principal =====\n");
        printf("1. Ajouter un étudiant\n");
        printf("2. Ajouter un cours\n");
        printf("3. Afficher la liste des étudiants\n");
        printf("4. Afficher la liste des cours\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter_etudiant();
                break;
            case 2:
                ajouter_cours();
                break;
            case 3:
                afficher_etudiants();
                break;
            case 4:
                afficher_cours();
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}
