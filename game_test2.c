#include <stdio.h>

#define NBC 7
#define NBL 6
#define endgame_four 4

/*initialization of game functions*/

void init_scores();
void print_scores();
void game_board_display();
void choose();
void fill_bin();
void flushstdin();

/*game board design*/
char header_line[] =   "  1   2   3   4   5   6   7";
char board_body [] =  "|---|---|---|---|---|---|---|";
char game_board_scores[NBL][NBC];

// Variables globales:
int bin = 0;         // Colone entrée par le joueur
char token = 'X';    /* Jeton du joueur qui servira a definir le joueur 'X' ou 
                        le joueur 'O' defini a 'X' car le premier joueur joue les 'X' */
int check(char token); // verifie si un joueur à gagné

//Game fonctionnement//
int main(void) {
  init_scores();
  print_scores();
  game_board_display();

  while(1)
    {
      printf("player %c's turn!", token);
      choose();
      game_board_display();

      if(check('X') == 1)
      {
      printf("\n\nPlayer X wins!\n\n");
      break;
    }
    if(check('O') == 1)
      {
      printf("\n\nPlayer O wins!\n\n");
      break;
      }

    }

  return 0;
}
//------------------------------------------------------------------//


/*initialize game board cases */
void init_scores() {
  int l, c;

  for (l = 0; l < NBL; l++) {
    for (c = 0; c < NBC; c++) {
      game_board_scores[l][c] = ' ';
    }

  }
}

/*display the initialize cases on the game board*/
void print_scores() {
  int l, c;
  for (l = 0; l < NBL; l++) {
    for (c = 0; c < NBC; c++) {
      printf("%c", game_board_scores[l][c]);

    }
    printf("\n");
  }
}

/*diplay game board(without initialize)*/
void game_board_display() {

  printf("%s\n", header_line);

  int l, c;

  for (l = 0; l < NBL; l++) {
    printf("\n%s\n", board_body);
    for (c = 0; c < NBC; c++) {
      printf("  %c ", game_board_scores[l][c]);

    }

  }
  printf("\n%s\n", board_body);


}


void choose()
{

  // choisie la colonne
  int c;
  int nbmatch;

  do { // Boucle de saisie.
    printf("\nChoose column: ");
    nbmatch = scanf("%d", &c);
    
    if(nbmatch != 1){
      printf("\n enter only one NUMBER\n");
      flushstdin();
      continue;
    }
    bin = c - 1;

    if(bin < 0 || bin > NBC-1){
      printf("\nWrong number ! Try again.\n\n");
      game_board_display();
      continue;
    }

    if((bin >= 0 && bin <= NBC-1) && (game_board_scores[0][bin] == ' ')) {
      printf("\ngood column\n");
      fill_bin();
      token = (token == 'X') ? 'O' : 'X';
      break;
    }
    else if(game_board_scores[0][bin] != ' ') {
      printf("\ncolumn full try something else\n");
      break;
    }
  } while(1);
}




void fill_bin(){
  // remplis la case en fonction de ce qu'il y a dans bin
  int level; // niveau ou hauteur la plus basse
  
  for (level = NBL-1; level >=0; level--)
    {
      if (game_board_scores[level][bin] == ' ')
	{
	  game_board_scores[level][bin] = token;
	  break;
	}
    }
}

void flushstdin() {
  int c;
  while((c = getchar()) != '\n' && c != EOF){
  }
    }

int check(char token){
  int i,j,k;
  int c4;
  int pos = 4;

  for(i = 0; i < NBL; ++i){
    for(j = 0; j < pos; ++j){
      c4 = 0;
      for(k = 0; k < endgame_four; ++k){
	if(game_board_scores[i][j+k] == token){
	  ++c4;
	  if(c4 == endgame_four){
	    return 1;
	  }
	}
      }
    }
  }
}
