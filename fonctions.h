#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include "types.h"


int recuperationdonnes(const char *nom_annuaire, int *nbclients);
int ajouterClient(const char *nom_annuaire, Client* clients, int *nbClients);
int ifflush(FILE* stream);

#endif // FONCTIONS_H_INCLUDED
