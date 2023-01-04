#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED
#define TAILLE_MAX 500

typedef struct {
  char nom_p[TAILLE_MAX];
  char prenom_p[TAILLE_MAX];
  char codepostal_p[6];
  char ville_p[TAILLE_MAX];
  char telephone_p[TAILLE_MAX];
  char mel_p[TAILLE_MAX];
  char profession_p[TAILLE_MAX];
} Client;

#endif // TYPES_H_INCLUDED
