#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_MAX 500
#define SEPARATEUR ","
#include "types.h"
#include "fonctions.h"
#include <assert.h>

int ifflush(FILE* stream)
{
    assert(stream != NULL);

    char buf[BUFSIZ];

    while (fgets(buf, sizeof buf, stream) != NULL)
    {
        if (strchr(buf, '\n') != NULL)
        {
            return 0;
        }
    }

    return EOF;
}

int recuperationdonnes(const char *nom_annuaire, int *nbclients)
{
    Client* clients = malloc(sizeof(Client));
    if (clients == NULL)
    {
        printf("Erreur lors de la r�servation de m�moire\n");
        return -2;
    }
    FILE* fp = fopen(nom_annuaire, "r");
    if (fp == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        return 1;
    }

    char ligne[TAILLE_MAX];
    while (fgets(ligne, TAILLE_MAX, fp) != NULL)
    {
        Client client;
        char* champ = strtok(ligne, SEPARATEUR); // R�initialise le pointeur de d�limitation
        int i = 0;
        while (champ != NULL)
        {
            switch (i)
            { // V�rifie le num�ro de champ
                case 0:
                strcpy(client.nom_p, champ);
                break;
                case 1:
                strcpy(client.prenom_p, champ);
                break;
                case 2:
                strcpy(client.codepostal_p, champ);
                break;
                case 3:
                strcpy(client.ville_p, champ);
                break;
                case 4:
                strcpy(client.telephone_p, champ);
                break;
                case 5:
                strcpy(client.mel_p, champ);
                break;
                case 6:
                strcpy(client.profession_p, champ);
                break;
            }
            i++;  // R�cup�re le champ suivant
            champ = strtok(NULL, SEPARATEUR);
        }


        if (strlen(client.mel_p) == 0) // V�rifie que l'adresse e-mail n'est pas vide
        {
            printf("Erreur: champ adresse e-mail manquant\n");
            continue;
        }
        clients = realloc(clients, (*nbclients + 1) * sizeof(Client));
        if (clients == NULL)
        {
            printf("Erreur lors de la r�allocation de m�moire\n");
            return -2;
        }

        clients[*nbclients] = client;
        (*nbclients)++;
    }
    fclose(fp);
    return clients;
}

int ajouterClient(const char *nom_annuaire, Client* clients, int* nbClients)
{
    char *p; //pointeur pour effacer les sauts de ligne des fgets
    Client nouveauClient; // Cr�ation d'un nouveau client

    // Saisie des informations du nouveau client
    printf("Saisissez le nom du client :\n");
    fgets(nouveauClient.nom_p, TAILLE_MAX, stdin);
    if ((p = strchr(nouveauClient.nom_p, '\n')) != NULL)
            *p = '\0';

    printf("Saisissez le pr�nom du client :\n");
    fgets(nouveauClient.prenom_p, TAILLE_MAX, stdin);
    if ((p = strchr(nouveauClient.prenom_p, '\n')) != NULL)
            *p = '\0';

    printf("Saisissez le code postal du client :\n");
    fgets(nouveauClient.codepostal_p, TAILLE_MAX, stdin);
    if ((p = strchr(nouveauClient.codepostal_p, '\n')) != NULL)
            *p = '\0';

    printf("Saisissez la ville du client :\n");
    fgets(nouveauClient.ville_p, TAILLE_MAX, stdin);
    if ((p = strchr(nouveauClient.ville_p, '\n')) != NULL)
            *p = '\0';

    printf("Saisissez le num�ro de t�l�phone du client :\n");
    fgets(nouveauClient.telephone_p, TAILLE_MAX, stdin);
    if ((p = strchr(nouveauClient.telephone_p, '\n')) != NULL)
            *p = '\0';

    printf("Saisissez l'adresse e-mail du client :\n");
    fgets(nouveauClient.mel_p, TAILLE_MAX, stdin);
    if ((p = strchr(nouveauClient.mel_p, '\n')) != NULL)
            *p = '\0';

    printf("Saisissez la profession du client :\n");
    fgets(nouveauClient.profession_p, TAILLE_MAX, stdin);
    if ((p = strchr(nouveauClient.profession_p, '\n')) != NULL)
            *p = '\0';


    // V�rifie que l'adresse e-mail du nouveau client n'est pas vide
    if (strlen(nouveauClient.mel_p) == 0)
    {
        printf("Erreur: l'adresse e-mail du client ne peut pas �tre vide\n");
        return -1;
    }

    // V�rifie que l'adresse e-mail du nouveau client n'est pas d�j� utilis�e par un autre client
    for (int i = 0; i < *nbClients; i++)
    {
        if (strcmp(clients[i].mel_p, nouveauClient.mel_p) == 0)
        {
            printf("Erreur: l'adresse e-mail du client est d�j� utilis�e par un autre client");
            return -3;
        }
    }

    // Ajoute le client � la liste
    clients = realloc(clients, (*nbClients + 1) * sizeof(Client));
    if (clients == NULL)
    {
        printf("Erreur lors de la r�allocation de m�moire\n");
        return -2;
    }

    clients[*nbClients] = nouveauClient;
    (*nbClients)++;

    FILE* fichier = fopen(nom_annuaire, "a");
    if (fichier == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        return 1;
    }
    fprintf(fichier, "%s,%s,%s,%s,%s,%s,%s\n", nouveauClient.nom_p, nouveauClient.prenom_p, nouveauClient.codepostal_p, nouveauClient.ville_p, nouveauClient.telephone_p, nouveauClient.mel_p, nouveauClient.profession_p);
    fclose(fichier);

    return 4;
}
