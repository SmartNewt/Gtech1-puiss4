#include <stdio.h>
#define NBC 7
#define NBL 6

char game_board_scores[NBL][NBC];
void init_scores();
void print_scores();

/*game board design*/
char header_line[] =   "  A   B   C   D   E   F   G";
char board_body [] =  "|---|---|---|---|---|---|---|";


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

  printf("%s", header_line);
  //printf("%s", board_body);


  int l, c;

  for (l = 0; l < NBL; l++) {
    for (c = 0; c < NBC; c++) {
      printf("%c", game_board_scores[l][c]);

    }
    printf("\n%s\n", board_body);

  }


}

int main() {
  init_scores();
  print_scores();
  game_board_display();

  return 0;

}
