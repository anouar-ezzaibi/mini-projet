#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define EMAIL_LENGTH 50

// Définition de la structure Contact
typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char email[EMAIL_LENGTH];
} Contact;

// Déclaration de la liste des contacts et du nombre de contacts
Contact contacts[MAX_CONTACTS];
int contactCount = 0;

// Fonction pour ajouter un contact
void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Le carnet de contacts est plein.\n");
        return;
    }
    printf("Entrez le nom: ");
    scanf("%s", contacts[contactCount].name);
    printf("Entrez le numéro de téléphone: ");
    scanf("%s", contacts[contactCount].phone);
    printf("Entrez l'adresse e-mail: ");
    scanf("%s", contacts[contactCount].email);
    contactCount++;
    printf("Contact ajouté avec succès.\n");
}

// Fonction pour afficher tous les contacts
void displayContacts() {
    if (contactCount == 0) {
        printf("Aucun contact à afficher.\n");
        return;
    }
    for (int i = 0; i < contactCount; i++) {
        printf("Contact %d:\n", i + 1);
        printf("Nom: %s\n", contacts[i].name);
        printf("Téléphone: %s\n", contacts[i].phone);
        printf("E-mail: %s\n\n", contacts[i].email);
    }
}

// Fonction pour rechercher un contact
void searchContact() {
    char name[NAME_LENGTH];
    printf("Entrez le nom du contact à rechercher: ");
    scanf("%s", name);
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact trouvé:\n");
            printf("Nom: %s\n", contacts[i].name);
            printf("Téléphone: %s\n", contacts[i].phone);
            printf("E-mail: %s\n", contacts[i].email);
            return;
        }
    }
    printf("Contact non trouvé.\n");
}

// Fonction pour modifier un contact
void modifyContact() {
    char name[NAME_LENGTH];
    printf("Entrez le nom du contact à modifier: ");
    scanf("%s", name);
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Modifier le numéro de téléphone (actuel: %s): ", contacts[i].phone);
            scanf("%s", contacts[i].phone);
            printf("Modifier l'adresse e-mail (actuel: %s): ", contacts[i].email);
            scanf("%s", contacts[i].email);
            printf("Contact modifié avec succès.\n");
            return;
        }
    }
    printf("Contact non trouvé.\n");
}

// Fonction pour supprimer un contact
void deleteContact() {
    char name[NAME_LENGTH];
    printf("Entrez le nom du contact à supprimer: ");
    scanf("%s", name);
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            contactCount--;
            printf("Contact supprimé avec succès.\n");
            return;
        }
    }
    printf("Contact non trouvé.\n");
}

// Fonction principale
int main() {
    int choice;
    while (1) {
        printf("\n--- Système de Gestion de Contacts ---\n");
        printf("1. Ajouter un contact\n");
        printf("2. Afficher tous les contacts\n");
        printf("3. Rechercher un contact\n");
        printf("4. Modifier un contact\n");
        printf("5. Supprimer un contact\n");
        printf("6. Quitter\n");
        printf("Choisissez une option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: modifyContact(); break;
            case 5: deleteContact(); break;
            case 6: return 0;
            default: printf("Option invalide, essayez à nouveau.\n");
        }
    }
    return 0;
}
