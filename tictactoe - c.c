#include <stdio.h>
#include <stdlib.h>


int main() {



  /*Functions*/


  int print_board(int N, char* board) {

    int H = (N*4) + 1;

    int i;
    int j;
    for(j=0; j<N; j++){
      int p;
      for(p=0; p<H; p++){
        printf("-");
      }
      printf("\n");

      for(i=0; i<N; i++){
        printf("| %c ", board[(j*N)+i]);

      }
      printf("|\n");
    }

    int b;
    for(b=0; b<H; b++){
      printf("-");
    }
    printf("\n");

    return 0;

  }
  int print_win(int player, int N, char* board){
    printf("Player %d is the winner.\n", player);
    print_board(N, board);
    free(board);
    exit(0);
  }
int check_for_win(int player, int N, char* board){
    char piece = ' ';
    if (player == 1){
      piece = 'O';
    }
    if (player == 2){
      piece = 'X';
    }

    int i;
    int A=0;
    for (i=0; i<N; i++){

      if (board[(N*i)+i]==piece){
        A = A+1;
      }
    }

    if (A==N){
      print_win(player, N, board);
      return 0;
    }

    int j;
    int B = 0;
    for (j=0; j<N; j++){

      int C=(N-j)-1;
      if (board[(N*j)+C]==piece){
        B = B+1;
      }
    }
     if (B==N){
      print_win(player, N, board);
      return 0;
    }
 int k;
    int l;
    int D=0;
    int E=0;
    for (k=0; k<N; k++){
      D=0;
      E=0;
      for (l=0; l<N; l++){
        if (board[(k*N)+l]==piece){
          D = D +1;
        }

        if (board[(l*N)+k]==piece){
          E = E + 1;
        }


        if (E==N){
          print_win(player, N, board);
          return 0;
        }
        if (D==N){
          print_win(player, N, board);
          return 0;
        }


      }


    }


    return 0;
  }

 int turn(int player, char output, char* board, int N){
    int row;
    int column;
    int used = 0;
    while (used == 0){

    printf("Player %d:\n", player);
    scanf("%d", &column);
    scanf("%d", &row);

    if (board[(N*column)+row]!='X' && board[(N*column)+row]!='O'){
      used = 1;
    }

    if (row > (N-1)){
      used = 0;
    }
    if (column > (N-1)){
      used = 0;
    }

    if (used == 0){
      printf("Incorrect value, try again.\n");
    }

    }

    printf("Player %d entered %d %d.\n", player, column, row);

      if (player==1){
        board[(N*column)+row]= 'O';
      }
      if (player==2){
        board[(N*column)+row]= 'X';
      }



    if (output == 'y'){
      print_board(N, board);
    }
    check_for_win(player, N, board);

  }
 int N;
  char Z;
  printf("Board Size (3..N):\n");
  scanf(" %d", &N);

   if (N<0){
    printf("Inappropriate value. Goodbye.\n");
    return 0;
  }

  printf("Output Play (y/n):\n");
  scanf(" %c", &Z);

 if (Z!='y' && Z!='n'){
    printf("Inappropriate value. Goodbye.\n");
    return 0;
  }



  printf("You entered %d %c.\n", N, Z);
  printf("Starting game with %d x %d board.\n", N, N);
  printf("Each player should enter\n");
  printf("a row and col num (eg: 2 0).\n");


  char* board;
  board = malloc(sizeof(char)*(N*N));


  int i;
  int M = N * N;
  for(i=0; i<M; i++){
    board[i] = ' ';
  }
 int player_1 = 1;
  int player_2 = 2;

  int num_turns = N*N;

  while (num_turns > 0){
turn(player_1, Z, board, N);
    num_turns = num_turns - 1;

    if (num_turns > 0){
      turn(player_2, Z, board, N);
      num_turns = num_turns - 1;
    }
  }

  printf("Who wins?? Nobody!\n");
  print_board(N, board);

  free(board);
  return 0;
}