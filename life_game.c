#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<unistd.h>
#define ROW 50
#define COL 22

void ClrScr()
{
  printf("\033[2J"); // Czyści ekran
  printf("\033[0;0f"); // Ustawia kursor w lewym, górnym rogu
}

void deleteMatrix(char ***ptab, int source_row)
{
    int row;
    for(row=0; row<source_row; row++)
    {
        free((*ptab)[row]);
        (*ptab)[row]=NULL;
    }
    free(*ptab);
    *ptab=NULL;
}

char **createMatrix(int row, int col)
{
    char **matrix=(char**)malloc(row*sizeof(char*));
    if(matrix==NULL) return NULL;

    int i;
    for(i=0; i<row; i++)
    {
        matrix[i]=(char*)malloc(col*sizeof(char));
        if(matrix[i]==NULL)
        {
          deleteMatrix(&matrix, i);
          return NULL;
        }
    }

    for(i=0; i<row; i++) //wypelnianie zerami
    {
        int j;
        for(j=0; j<col; j++)
        {
            matrix[i][j]=' ';
        }
    }
    return matrix;
}

void writeMatrix(char **matrix,int n, int m)
{
	int i,j;
	printf("\n\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%c ",matrix[i][j]);
		}
		printf("\n");
	}
}

int fillMatrix(char **tab, int row, int col)
{
    int x=0; int y=0;
    FILE* fp;
    fp=fopen("init.txt", "r");
    if(fp==NULL) printf("Nie mozna otworzyc pliku");
    while(feof(fp)==0)
    {
       fscanf(fp,"%i",&x);
       fscanf(fp,"%i",&y);
       if(x>ROW || y>COL)
       {
           printf("Wspolrzedne poza zakresem dostepnego pola");
           return -1;
       }
       tab[x][y]='*'; //wypelnianie odpowiednich pol
    }
    fclose(fp);

    printf("Ustawienie poczatkowe to:\n");
    writeMatrix(tab, ROW, COL);

    Sleep(2000);
    //system("clear");
    ClrScr();

return 0;}

void generation(char ***dest, char **src, int source_row, int source_col) //generowanie nowego pokolenia
{

    int row;
    for(row=1; row<source_row-1; row++) //1 i -1 zeby pominac krawedzie
    {
        int col;
        for(col=1; col<source_col-1; col++)
        {
            int flag=0;
            int check_row;
            for(check_row=row-1; check_row<=row+1; check_row++)
            {
                int check_col;
                for(check_col=col-1; check_col<=col+1;check_col++)
                {
                    if(check_row!=row|| check_col!=col)
                        if(src[check_row][check_col]=='*') flag++;
                }
            }
            if(src[row][col]=='*')
            {
                if(flag==2 || flag==3) (*dest)[row][col]='*';
                else (*dest)[row][col]=' ';
            }
            if(src[row][col]==' ')
            {
                if(flag==3) (*dest)[row][col]='*';
                else (*dest)[row][col]=' ';
            }
        }
    }
}

void copyMatrix(char ***dest, char **src, int source_row, int source_col)
{
    int row;
    for(row=0; row<source_row; row++)
    {
        int col;
        for(col=0; col<source_col; col++)
        {
            (*dest)[row][col]=src[row][col];
        }
    }
}


int main()
{
    char** matrix_old=createMatrix(ROW, COL);
    if(matrix_old==NULL) return -1;
    if(fillMatrix(matrix_old, ROW, COL)==-1) return -1;
    char** matrix_new;
    matrix_new=createMatrix(ROW, COL);
    if(matrix_new==NULL) return -1;

    char opr;
    do
    {
        printf( "1.Wykonaj 10 ruchow Gry w zycie\n"
                "2.Zamknij program\n");
        scanf(" %c",&opr);
        system("clear");
        if(opr=='1')
        {
            writeMatrix(matrix_old, ROW, COL);
            Sleep(1000);
            //system("cls");
            ClrScr();
            int spr=10;
            while(spr)
            {

                generation(&matrix_new, matrix_old, ROW, COL);
                writeMatrix(matrix_new, ROW, COL);
                copyMatrix(&matrix_old, matrix_new, ROW, COL);
                Sleep(1000);
                //system("cls");
                ClrScr();

                spr--;
            }
        }
        else if(opr!='1' && opr!='2') printf("Wpisz prawidlowe polecenie\n");

    }while(opr!='2');

    deleteMatrix(&matrix_old, ROW);
    deleteMatrix(&matrix_new, ROW);

return 0;}
