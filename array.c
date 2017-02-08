#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "array.h"
void cleartab(char **tab, int row, int col);
void delete(char ***,int);

//funkcja create() tworz¹ca tablicê o defaultowym rozmiarze

char **create(int row, int col)
{
    char **tab;
    tab=(char**)malloc(row*sizeof(char*));
    if(tab==NULL)
	{free(*tab);
	return NULL;
	}
    int k;
    for( k=0 ; k<row ; k++)
	{tab[k]=(char*)malloc(col*sizeof(char));
	if(tab[k]==NULL)
		{delete(&tab,row);
		
		return NULL;
		}
	}
    cleartab(tab, row,col);
    return tab;
}

//delete() usuwaj¹ca tablicê dynamiczn¹

void delete(char ***ptab, int row)
{
	int l;
	for( l=0 ; l<row ; l++)
		{free((*ptab)[l]);
		(*ptab)[l]=NULL;
		}
	free(*ptab);
	*ptab=NULL;
	
}

//at() podaj¹ca wartoœæ i-tego elementu tablicy

void at(char **tab, int row, int col)
	{	
	int x,y;
	printf("\nPodaj wspolrzedne x - ( 0 - %3d)\n",row);
	scanf("%d",&x);
	printf("\nPodaj wspolrzedne y - ( 0 - %3d)\n",col);
	scanf("%d",&y);
	putchar('\n');
	
	if(x > row || y>col)
		{printf("Blad, tablica nie jest tak wielka\n");
		return;
		}
	printf("Dla x=%d i y=%d, wartosc komorki to:%c",x,y,tab[x][y]);
	return;		
	}

//insert() wk³adaj¹ca element na dan¹ pozycjê w tablicy

void insert(char **tab, int row, int col)
	{
	
	int x,y,logic;
	printf("\nPodaj wspolrzedne x - ( 0 - %3d)\n",row);
	scanf("%d",&x);
	printf("\nPodaj wspolrzedne y - ( 0 - %3d)\n",col);
	scanf("%d",&y);
	putchar('\n');
	if(x > row || y>col)
		{printf("Blad, tablica nie jest tak wielka\n");
		return;
		}
	printf("\n1.Zywa \n2.niezywa\n");
	scanf("%d",&logic);
	if(logic==1)
		{if(tab[x][y]='0')
			{printf("\nTa komorka jest juz zywa\n");
			return;
			}
		tab[x][y]='0';
		}
	else
		{if(tab[x][y]!=' ')
			{printf("\nTa komorka jest juz niezywa\n");
			return;
			}
		tab[x][y]=' ';
		}
		
	printf("\nPomyslnie wpisano wartosc ");
	return;
	}
	
//resize() powiêkszaj¹ca rozmiar tablicy

char **resize(char ***tab,int nrow, int ncol, int orow, int ocol)
	{if(ncol<ocol || nrow<ncol)
		return (*tab);
		
	char **newtab;
	newtab=create(nrow, ncol);
	if(newtab==NULL)
		return NULL;
		
	int x,y;
	cleartab(newtab,nrow,  ncol);
	for(x=1 ; x<orow ; x++)
		for(y=1 ; y<ocol ; y++)
			newtab[x][y]=(*tab)[x-1][y-1];
	return newtab;
	}


void cleartab(char **tab, int row, int col)
	{ int x, y;
	for( x=0 ; x<row ; x++)
		for(y=0 ; y<col ; y++)
			tab[x][y]=' ';
	return;
	}

char **filltab(char ***tab, int row, int col)
	{ int x, y; char **newtab;
	newtab=create(row,col);
	cleartab(newtab,row,col);
	for(x=0 ; x<row ; x++)
		for( y=0 ; y<col ; y++)
			newtab[x][y]=(*tab)[x][y];
	return newtab;
	}


void readData(char ***tab , char *arg , int row, int col)
	{int x; int y;
	FILE* file;
	file = fopen(arg, "r");
	if(!file)
		{printf("nie mozna otworzyc pliku");
		fclose(file);
		return;
		}
	while(feof(file)==0)
		{fscanf(file,"%d",&x);
		fscanf(file,"%d",&y);
		if(x>row || y>col)
			{printf("Poza obszarem tabeli");
			fclose(file);			
			return;
			}
		(*tab)[x][y]='0';
		
		}
	fclose(file);	
	return;
	}

void saveData(char **tab, char *arg , int row, int col)
	{
	int x, y;	
	FILE *file;
	file=fopen(arg, "w");
	for(x=0 ; x<row ; x++)
		for(y=0 ; y<col; y++)
			if(tab[x][y]=='0')
				fprintf(file,"%d %d\n",x,y);

	return ;
	}




	
