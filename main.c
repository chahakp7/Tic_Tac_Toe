#include <stdio.h>

void InitializeBoard (int m, int n, char board[][n]){
    int c = 1;
    
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n ; j++)
        {
            board[i][j] = c +'0';
            c++;
        }
    }
}

void PrintBoard (int m, int n, char board[][n]){
    printf("\n");
    for (int i=0 ; i<m ; i++)
    {
        printf("\t|\t|\t");
        printf("\n");
        for (int j=0; j<n;j++)
        {
            printf("   %c\t", board[i][j]);
            if (j!=2)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i!=2)
        {
            printf("________|_______|________");
        }
        if (i==2)
        {
            printf("        |       |");
        }
        printf("\n");
    }
}



void CreateBoard(int m, int n, char board[][n])
{
    int c;
    printf("\n\n");
    while(1)
    {
        printf("Enter the number of the cell where you want to insert X or O or enter -1 to exit : ");
        scanf("%d",&c);
        if(c==-1)
        { return;}
        else if(c>=1 && c<=9)
        {
            c--;
            int r=c/3;
            int co=c%3;
            char ch;
            printf("Type X or O : ");
            scanf("%c",&ch);
            scanf("%c",&ch);
            if(ch=='x'|| ch=='X')
            {
                ch='X';
            }
            else if (ch=='o'|| ch=='O')
            {
                ch='O';
            }
            else
            {
                printf("Enter a valid character X or O\n");
                continue;
            }
            board[r][co]=ch;
            PrintBoard(m,n,board);
        }
        
    }
}


int IsValidBoard(int m, int n, char board[][n])
{
    int player1=0,player2=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]=='X')
                player1++;       //player1 stands for player x
            else
                if(board[i][j]=='O')
                    player2++;      //player2 stands for player O
        }
    }
    if(player1-player2==0 || player1-player2==1)
    {
        PrintBoard(n,m,board);
        printf("\n\nValid Board\n\n");
    }
    else if (player2-player1==0 || player2-player1==1)
    {
        PrintBoard(n,m,board);
        printf("\n\nvalid Board\n\n");return 1;
    }
    else
    {
        PrintBoard(n,m,board);
        printf("\n\nInvalid Board\n\n"); return 0;
    }
}

char ListWinningCells(int m, int n, char board[][n])
{
    
    int RX[3]={0}, CX[3]={0}, RO[3]={0}, CO[3]={0};  // RX & CX :row of x & columns of X && RO & CO : row of o and columns o
    int dX1=0, dX2=0, dO1=0, dO2=0;       // dX1 & dX2 : diagonals of X && dO1 & dO2 : diagonals for O
    if(IsValidBoard(m,n,board))
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='X')
                    RX[i]++;
                if(board[j][i]=='X')
                    CX[i]++;
                if(i==j && board[i][j]=='X')
                    dX1++;
                if((i+j)==(n-1) && board[i][j]=='X')
                    dX2++;
                if(board[i][j]=='O')
                    RO[i]++;
                if(board[j][i]=='O')
                    CO[i]++;
                if(i==j && board[i][j]=='O')
                    dO1++;
                if((i+j)==(n-1) && board[i][j]=='O')
                    dO2++;
                
            }
            
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(RX[i]==2 && board[i][j]!='X' && board[i][j]!='O')
                    printf("#%cis the winnig cell for player X.\n",board[i][j]);
                
                if(CX[i]==2 && board[j][i]!='X' && board[j][i]!='O')
                    printf("#%c is the winnig cell for player X.\n",board[j][i]);
                
                if(i==j && board[i][j]!='X'&& dX1==2 && board[i][j]!='O')
                    printf("#%c is the winnig cell for player X.\n",board[i][j]);
                
                if((i+j)==(n-1) && board[i][j]!='X' && dX2==2 && board[i][j]!='O')
                    printf("#%c is the winnig cell for player X.\n",board[i][j]);
                
                if(RO[i]==2 && board[i][j]!='X' && board[i][j]!='O')
                    printf("#%c is the winnig cell for player O.\n",board[i][j]);
                if(CO[i]==2 && board[j][i]!='X' && board[j][i]!='O')
                    printf("#%c is the winnig cell for player O.\n",board[j][i]);
                if(i==j && board[i][j]!='X'&& dO1==2 && board[i][j]!='O')
                    printf("#%c is the winnig cell for player O.\n",board[i][j]);
                if((i+j)==(n-1) && board[i][j]!='X' && dO2==2 && board[i][j]!='O')
                    printf("#%c is the winnig cell for player O.\n",board[i][j]);
            }
            
            
            {
                printf("no Winnig cell...\n");
                break;
                
            }
        }
        
    }
    else
        printf("Cannot Predict the winnig cell...\n");
    return 0;
}

int main()
{
    int p,q;
    char ticTacToe[3][3],choice;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d",&p,&q);
    InitializeBoard(q,p,ticTacToe);
top:
    printf("press 'p' to print the tic-tac-toe board.\n");
    printf("press 'c' to create a tic-tac-toe board with some X or O cells.\n");
    printf("press 't' to test if a tic-tac-toe board is valid or invalid board.\n");
    printf("press 'w' to predict winning cell for player X or O.\n");
    printf("press 'e' to Exit.\n");
    if(choice!='e')
    {
        printf("Enter your choice : ");
        scanf(" %c",&choice);
        
        switch(choice)
        {
            case 'p':
            {
                PrintBoard(q,p,ticTacToe);
                goto top;
                break;
            }
            case 'c':
            {
                CreateBoard(q,p,ticTacToe);
                goto top;
                break;
            }
            case 't':
            {
                IsValidBoard(q,p,ticTacToe);
                goto top;
                break;
            }
            case 'w':
            {
                ListWinningCells(q,p,ticTacToe);
                goto top;
                break;
            }
        }
    }
    return 0;
}
