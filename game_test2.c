#include <stdio.h>

#define NBC 7
#define NBL 6

/*initialization of game functions*/

void init_scores();
void print_scores();
void game_board_display();
void choose();
void fill_bin();


/*game board design*/
char header_line[] =   "  A   B   C   D   E   F   G";
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

      /*if(check('X'))
      {
      printf("\n\nPlayer X wins!\n\n");
      break;
    }
    if(check('O'))
      {
      printf("\n\nPlayer O wins!\n\n");
      break;
      }*/

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

  // choisiee la colonne
  char c;

  while(1){
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
      default:
	bin = 9000;
	printf("\nWrong letter or number ! Try again.\n\n");
	game_board_display();
      }

    if((bin >= 0 && bin <= 6) && (game_board_scores[0][bin] == ' '))
      {
	fill_bin();
	token = (token == 'X') ? 'O' : 'X';
	break;
      }
    else if(game_board_scores[0][bin] != ' '){
      printf("\nThis column is full ! Try again. \n\n");
      fill_bin();
    }

  }
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
