#include <stdio.h>
#define NBL 6
#define NBC 7

// Variables globales:
char tab[NBL][NBC]; // OK pour le compilateur car *tout est déterminé* au moment de compiler
int bin = 0;         // Colone entrée par le joueur
char token = 'X';    /* Jeton du joueur qui servira a definir le joueur 'X' ou 
                        le joueur 'O' defini a 'X' car le premier joueur joue les 'X' */ 
int check(char token); // verifie si un joueur à gagné 

  
void main(void) {
  tab_init();
  tab_test();
  tab_print();

  while(1)
    {
    printf("player %c's turn!", token);
    choose();
    tab_print();
    
    if(check('X'))
      {
      printf("\n\nPlayer X wins!\n\n");
      break;
    }
    if(check('O'))
      {
      printf("\n\nPlayer O wins!\n\n");
      break;
    }
      
  }

  return 0;
}



char tab_init()
{
  for(int l=0; l<NBL; l++){
    for(int c=0; c<NBC; c++){
      tab[l][c] = '.';
    }
  }
}

void boucle()
{

  while(!game_won && !game_full) {
    do {
      // Saisie joueur:
      int colonne, code_retour;
      code_retour = scanf("%d", &colonne); // ATTENTION: on passe &colonne et pas colonne

      // Tester code_retour (cf. =man 3 scanf=, section "RETURN VALUE").
      int saisie_ok =  ; // construire un test en utilisant code_retour et la valeur de colonne
    } while(!saisie_ok); // On recommence la saisie tant que ce n'est pas OK
  }
}

void choose()
{

  // choisiee la colonne 
  char c;
  
  printf("\nChoose column: ");
  scanf(" %c", &c);

  switch (c)
    {
  case 'A':
  case 'a':
  case '1':
    bin = 0;
    break;
  case 'B':
  case 'b':
  case '2':
    bin = 1;
    break;
  case 'C':
  case 'c':
  case '3':
    bin = 2;
    break;
  case 'D':
  case 'd':
  case '4':
    bin = 3;
    break;
  case 'E':
  case 'e':
  case '5':
    bin = 4;
    break;
  case 'F':
  case 'f':
  case '6':
    bin = 5;
    break;
  case 'G':
  case 'g':
  case '7':
    bin = 6;
    break;
    }
}
