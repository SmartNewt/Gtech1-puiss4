#include <stdio.h>
#define NBC 7
#define NBL 6


char tab[NBL][NBC];

char board_head[] = "  A   B   C   D   E   F   G";

char board_l[]    = "|---|---|---|---|---|---|---|";

void game_board(){
  printf("%s\n", board_head);  //display game board column
  printf("%s\n", board_l); //display game board line

  int l,c;
    for (l=0; l<NBL; l++){
      for (c=0; c<NBC; c++){

        printf("%c", tab[NBL][NBC]);
      }
      // printf("|\n");
      printf("\n%s\n", board_l);
      
    }

}





    int main(){
      game_board();

      return 0;
    }
