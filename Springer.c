#include <stdio.h>
#include <stdlib.h>

enum {N=50};
typedef int Feld[N][N];
int geloest=0;
int weiter =0;

typedef struct
{
    int i;
    int j;
}Index;

void ausgeben(Feld feld, int n)
{
    printf("\n\n");
    for(int i=0; i<n; i++)
   {
        for(int j=0; j<n;)
            printf("%5d", feld[i][j++]);

       printf("\n\n");
   }
}



void backtracking(Feld feld, int i, int j, int n, int zugfolge, Index anf)
{
    if(i>=0 && i<n && j>=0 && j<n)
    {
        if(feld[i][j]==0 && geloest==0)
        {
            feld[i][j]=++zugfolge;
            //else
                //backtracking(feld, anf.i, anf.j, n, zugfolge, anf);
            if(zugfolge==n*n)
            {   geloest=1;
                    return;
            }
            else
            {
                backtracking(feld, i-2, j+1, n, zugfolge, anf);//zwei Felder nach vorn und ein Feld nach rechts

                backtracking(feld, i-2, j-1, n, zugfolge, anf);//zwei Felder nach vorn und ein Feld nach links

                backtracking(feld, i+2, j+1, n, zugfolge, anf);//zwei Felder nach hinten und ein Feld nach rechts

                backtracking(feld, i+2, j-1, n, zugfolge, anf);//zwei Felder nach hinten und ein Feld nach links

                backtracking(feld, i-1, j+2, n, zugfolge, anf);//zwei Felder nach rechts und ein Feld nach vorne

                backtracking(feld, i+1, j+2, n, zugfolge, anf);//zwei Felder nach rechts und ein Feld nach hinten

                backtracking(feld, i-1, j-2, n, zugfolge, anf);//zwei Felder nach links und ein Feld nach vorne

                backtracking(feld, i+1, j-2, n, zugfolge, anf);//zwei Felder nach links und ein Feld nach hinten

                if (geloest==0)
                    feld[i][j]=0;//back
            }
            if (geloest==0)
                    feld[i][j]=0;//back
        }

    }



}
int main()
{
    Feld feld;
    int n=0, zugfolge=0;
    Index anf;
    printf("Groesse des Bretts bitte eingeben groesser als 4 und kleiner als 7:\t");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            feld[i][j]=0;

    printf("\nStartfeld bitte eingeben mit einer Komma getrennt(zB: 1,1):\t");
    scanf("%d,%d", &anf.i, &anf.j);

    backtracking(feld, anf.i, anf.j, n, zugfolge, anf);

    putchar('\n');
    ausgeben(feld,n);

    return 0;
}
