#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "game.h"


void near(int ***itab, char ***ctab, int row,  int col)

	{int sum=0, i1,i2, a,b;
	for(i1=1 ; i1 < row ; i1++)
		for( i2=1 ; i2<col ; i2++)
			{for( a=-1 ; a<2 ; a++)
				for( b=-1 ; b<2 ; b++)
					if((*ctab)[i1+a][i2+b]=='0')
						++sum;
			
			if((*ctab)[i1][i2]=='0')
				--sum;
			(*itab)[i1][i2]=sum;   //wpisywanie ilosci otoczenia
			sum=0;
			}
	
	}

int **neartab(int row, int col)
	{int x,y;
	int **tab;
	tab=(int**)malloc((row+2)*sizeof(int*));
	if(tab==NULL)
		{
		free(tab);
		return NULL;
		}
	for(x=0 ; x<row+2 ; x++)
		{tab[x]=(int*)malloc((col+2)*sizeof(int));
		if(tab[x]==NULL)	
			deleteint(tab,row);
		}
	blankint(&tab,row+2,col+2);
	return tab;
	}


void deleteint(int **tab, int row)
	{int x,y;
	for( x=0 ; x<row+2 ; x++)	
		{free(tab[x]);
		tab[x]=NULL;
		}
	
	free(tab);
	tab=NULL;	

	}
void blankint(int ***tabint,int row, int col)
	{int x,y;
	for( x=0 ; x<row ; x++)
		for( y=0 ; y<col ; y++)
			(*tabint)[x][y]=0;
	return;


	}

void simulation(char **newtab, char ***tab ,int **otoczenie, int row, int col)
{
	int x,y;
	for( x=0 ; x<row ; x++)							
		for( y=0 ; y<col ; y++)
			{
				if(newtab[x+1][y+1]=='0')			
					if(otoczenie[x+1][y+1]==2 || otoczenie[x+1][y+1]==3 )
						(*tab)[x][y]='0';
					else
						(*tab)[x][y]=' ';
				if(newtab[x+1][y+1]==' ')
					if(otoczenie[x+1][y+1]==3)
						(*tab)[x][y]='0';
					else
						(*tab)[x][y]=' ';			
			}
		

	for( x=0 ; x<row ; x++)
		{for( y=0 ; y<col ; y++)
			printf("%c",(*tab)[x][y]);
	
				
		putchar('\n');
		}	
return ;
}
	
