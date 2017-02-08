#ifndef GRA
#define GRA
char **create(int , int);
void delete(char***, int);
char **resize(char ***,int, int, int, int);
void insert(char **, int, int );
void cleartab(char **tab, int row, int col);
char **filltab(char ***tab, int row, int col);
void saveData(char **tab, char *arg , int row, int col);
void readData(char ***tab , char *arg , int row, int col);	
#endif 
