#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
#include "types.h"

int main()
{
    int choix;
    do
{   printf("****************************\n");
    printf("1--> Ajouter un client\n");
    printf("2--> Modifier le mail d'un client\n");
    printf("3--> Modifier les autres cordonnées d'un client\n");
    printf("4--> Supprimer un client\n");
    printf("5--> Trier les clients par nom\n");
    printf("6--> Lister les clients avec données manquantes\n");
    printf("7--> Filtrer les clients (1 champ)\n");
    printf("8--> Filter les clients (2 champs)\n");
    printf("9--> Quitter\n");
    printf("*****************************\n");
    printf("Entrez votre choix\n");
    scanf("%d",&choix);

    switch(choix)
    {
        case 1: ;
                int nbClients = 0;
                Client* clients = recuperationdonnes("annuaire.csv", &nbClients);
                if (clients == NULL)
                {
                    printf("Erreur lors de la lecture de l'annuaire\n");
                    return 1;
                }

                break;
        case 2:
                break;
        case 3:
                break;
        case 4:
                break;
        case 5:
                break;
        case 6:
                break;
        case 7:
                break;
        case 8:
                break;
        default:printf("Merci et au revoir!\n");
    }
}
    while(choix!=9);
    return 0;
}

