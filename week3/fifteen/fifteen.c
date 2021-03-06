/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(int d);
void draw(int d);
void printChar(int d);
bool move(int tile, int d);
bool won(int d);

int main(int argc, string argv[]) {
  // ensure proper usage
  if (argc != 2) {
    printf("Usage: fifteen d\n");
    return 1;
  }

  // ensure valid dimensions
  d = atoi(argv[1]);
  if (d < DIM_MIN || d > DIM_MAX) {
    printf("Board must be between %i x %i and %i x %i, inclusive.\n",
      DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
    return 2;
  }

  // open log
  FILE *file = fopen("log.txt", "w");
  if (file == NULL) {
    return 3;
  }

  // greet user with instructions
  greet();

  // initialize the board
  init(d);

  // accept moves until game is won
  while (true) {
    // clear the screen
    clear();

    // draw the current state of the board
    draw(d);

    // log the current state of the board (for testing)
    for (int i = 0; i < d; i++) {
      for (int j = 0; j < d; j++) {
        fprintf(file, "%i", board[i][j]);
        if (j < d - 1) {
          fprintf(file, "|");
        }
      }
      fprintf(file, "\n");
    }
    fflush(file);

    // check for win
    if (won(d)) {
      printf("ftw!\n");
      break;
    }

    // prompt for move
    printf("Tile to move: ");
    int tile = GetInt();

    // quit if user inputs 0 (for testing)
    if (tile == 0) {
      break;
    }

    // log move (for testing)
    fprintf(file, "%i\n", tile);
    fflush(file);

    // move if possible, else report illegality
    if (!move(tile, d)) {
      printf("\nIllegal move.\n");
      usleep(500000);
    }

      // sleep thread for animation's sake
      usleep(500000);
  }

  // close log
  fclose(file);

  // success
  return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void) {
  printf("\033[2J");
  printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void) {
  clear();
  printf("WELCOME TO GAME OF FIFTEEN\n");
  usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(int d) {
  int max = (d * d) - 1;
  bool odd;

  if (d % 2 == 0) {
    odd = true;
    printf("odd\n");
  } else {
    odd = false;
    printf("even\n");
  }

  for (int i = 0; i < d; i++) {
    for (int j = 0; j < d; j++) {
      if (odd) {
        // If there is an odd number of tiles, swap 1 and 2
        if (max == 2) {
          board[i][j] = 1;
          max -= 1;
        } else if (max == 1) {
          board[i][j] = 2;
          max -= 1;
        } else {
          board[i][j] = max;
          max -= 1;
        }
      } else {
        // Otherwise leave 1 and 2 in order
        board[i][j] = max;
        max -= 1;
      }
    }
  }
}

/**
 * Prints the board in its current state.
 */
void draw(int d) {
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < d; j++)
    if (board[i][j] > 9) {
      if (j == d - 1) {
        printChar(board[i][j]);
        printf("\n\n");
      } else {
        printChar(board[i][j]);
      }
    } else if (j == d - 1) {
      printChar(board[i][j]);
      printf("\n\n");
    } else {
      printChar(board[i][j]);
    }
  }
}

// Help with proper grid formatting.
void printChar(int d) {
  if (d < 10) {
    if (d == 0) {
      printf("  _");
    } else {
      printf("  %i", d);
    }
  } else {
    printf(" %i", d);
  }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile, int d) {
  // TODO
  int x, y;
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < d; j++) {
      if (board[i][j] == tile) {
        x = j;
        y = i;
      }
    }
  }

  if (board[y + 1][x] == 0) {
    board[y][x] = 0;
    board[y + 1][x] = tile;
    // printf("0 is at board[%d][%d]", y + 1, x);
    return true;
  } else if (board[y - 1][x] == 0) {
    board[y][x] = 0;
    board[y - 1][x] = tile;
    return true;
  }

  return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(int d) {
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < d; j++) {
      if (i == d-1 && j == d-2) {
        break;
      } else if (j == d-1) {
        if (board[i+1][0] - board[i][j] != 1) {
          return false;
        }
      } else if (board[i][j+1] - board[i][j] != 1) {
        return false;
      }
    }
  }
  return true;
}
