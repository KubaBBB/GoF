#ifndef GAME
#define GAME


void near(int ***, char ***, int,  int);
int **neartab(int row, int col);
void deleteint(int **tab, int row);
void blankint(int ***tabint,int row, int col);
void simulation(char **newtab, char ***tab ,int **otoczenie, int row, int col);

#endif
