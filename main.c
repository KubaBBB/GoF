#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "array.h"
#include "game.h"

#define ROW 80
#define COL 22


main(int argc,char *arg[])
{
if(argc!=4)
	{
	printf("\nBlad!\nNapisz w takim formacie:\n1../nazwa_programu 3 plik_wejscia.txt plik_wyjscia.txt\n\n");
	return -1;
	}
else printf("Plik wejsciowy i wejsciowy zaladowany\n");

int x=0,y=0;  int p;
int row=ROW,col=COL;
char **tab, **newtab;				//deklaracja char**
tab=create(ROW,COL); 
newtab=create(ROW,COL);         		//alokacja char**

readData(&tab,arg[2],ROW-1,COL-1);				

newtab=resize(&tab,row+2,col+2,row,col);


int **otoczenie;				// deklaracja int **

otoczenie=neartab(row,col);
printf("Poczatkowe polozenie - dane z pliku");
for(x=0;x<ROW;x++)
	{for(y=0;y<COL;y++)
		printf("%c",tab[x][y]);
	putchar('\n');	
	}

int sum=0; char check_char;
printf("Rozpocznij symulacje gry w zycie\n");
printf("Zeby wyjsc nacisnij podczas gry k lub K\nCokolwiek innego - kolejne pokolenie\n");	
getchar();
putchar('\n');

int result=1;
while(result!=0)			//while
	{near(&otoczenie,&newtab,row,col);
	
	simulation(newtab,&tab,otoczenie,row,col);	
	newtab=resize(&tab,row+2,col+2,row,col);
	
	saveData(tab,arg[3],row, col);
	cleartab(tab,row,col);
	
	
	printf("-----------------------------------");
	scanf("%s",&check_char);putchar('\n');
	if(check_char=='k' || check_char=='K')	
		--result;
	}
printf("\nDzieki za uwage\n");
	
		
deleteint(otoczenie,row);
delete(&newtab,row+2);
delete(&tab,row);


getchar();
return 0;
}
