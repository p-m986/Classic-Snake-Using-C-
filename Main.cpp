#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
using namespace std;
int score,highscore;
char retry='y';
int main()
{
    cout <<endl;
    cout <<endl;
    cout <<"  ***** *   *  ***  *   * *****\n";
    cout <<"  *     **  * *   * * *   *\n";
    cout <<"  ***** * * * ***** **    ***\n";
    cout <<"      * *  ** *   * * *   *\n";
    cout <<"  ***** *   * *   * *   * ******\n";
    cout <<endl;
    cout <<" Press Any Key to Continue"<<endl;
    getch();
    while (retry=='y' || retry == 'Y')
    {
    srand(time(NULL));
    score=0;
    //int point_2=(rand()-1)%18+1;
    int point_2=(rand()-1)%18+1;
    int x[100];
    int y[100];
    x[0]=10;
    y[0]=10;
    x[1]=9;
    y[1]=10;
    x[2]=8;
    y[2]=10;
    int b=3 ;
    string a[20][20];
    char ctr='d';
    
    while (x[0]!=0 && x[0]!=19 && y[0]!=0 && y[0]!=19)
    {
        for (int i=0;i<20;i++)
        {
            for (int j=0;j<20;j++)
            {
                if (i==0 || j==0 || i==19 || j==19)
                     a[i][j]="* ";
                else
                     a[i][j]="  ";
            }
        }
        a[point_2][point_2]="o ";
        
        for(int s=b;s>0;s--)
        {
            x[s]=x[s-1];
            y[s]=y[s-1];
        }
        for (int r=0;r<=b;r++)
        {
            a[y[r]][x[r]]="* ";
        }
        if (kbhit())
        {
            ctr=getch();
        }
        if(ctr=='w')
            y[0]--;
        if(ctr=='s')
            y[0]++;
        if(ctr=='a')
            x[0]--;
        if(ctr=='d')
            x[0]++;
        for(int m=0;m<20;m++)
        {
            for (int n=0;n<20;n++)
            {
                cout << a[m][n];
            }
        cout <<endl;
        }
        if (a[0][0]==a[point_2][point_2])
        {
            b++;
            point_2=rand()%19;
            if (point_2%19==0)
                point_2++;
            point_2=rand()%19;
            if (point_2%19==0)
                point_2++;
            score=score+1;
         }
        for (int c=1;c<b;c++)
        {
            if (x[0]==x[c] && y[0]==y[c] )
            {
                x[0]=0;
            }
        }
    Sleep(25);
    system("cls");
    }
    cout << "GAMEOVER!" <<endl;
    cout << "Score = " << score<<endl;
    if (score > highscore)
    {
        highscore=score;
    }
    cout << "High Score = "<<highscore<<endl;
    cout << "retry (y/n)"; cin >>retry;
    }
    return 0;
}
