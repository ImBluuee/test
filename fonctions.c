#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#define TAILLE_MAX 500
#define SEPARATEUR ","
#include "types.h"
#include "fonctions.h"


int recuperationdonnes(char *nomfichier, int *nbclients)
{
    Client* clients = malloc(sizeof(Client));
    if (clients == NULL)
    {
        printf("Erreur lors de la réservation de mémoire\n");
        return NULL;
    }
    FILE* fp = fopen("annuaire.csv", "r");
    if (fp == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        return 1;
    }

    char ligne[TAILLE_MAX];
    while (fgets(ligne, TAILLE_MAX, fp) != NULL)
    {
        Client client;
        char* champ = strtok(ligne, SEPARATEUR); // Réinitialise le pointeur de délimitation
        int i = 0;
        while (champ != NULL)
        {
            switch (i)
            { // Vérifie le numéro de champ
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
            i++;  // Récupère le champ suivant
            champ = strtok(NULL, SEPARATEUR);
        }


        if (strlen(client.mel_p) == 0) // Vérifie que l'adresse e-mail n'est pas vide
        {
            printf("Erreur: champ adresse e-mail manquant\n");
            continue;
        }
        clients[*nbclients] = client;
        (*nbclients)++;
    }
    fclose(fp);
    return nbclients;
}

