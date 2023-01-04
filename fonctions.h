#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include "types.h"


int recuperationdonnes(char *nomfichier, int *nbclients);
void lecture_fichier();
void afficherClient(const Client* client);

#endif // FONCTIONS_H_INCLUDED
