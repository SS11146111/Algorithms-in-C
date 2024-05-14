#include<stdio.h>
#define inf 99999
#define nil -1
int n,n1,n2,w[100][100],p[100][100],d[100][100];
void fw()
{
    int i,j,k;
    n1=n;
    for(i=1;i<=n1;i++)
    {
        for(j=1;j<=n1;j++)
        {
            d[i][j]=w[i][j];
        }
    }
    for(i=1;i<=n1;i++)
    {
        for(j=1;j<=n1;j++)
        {
            if((w[i][j]==0)||(w[i][j]==inf))
            {
                p[i][j]=nil;

            }
            else
            {
               p[i][j]=i;
            }
        }
    }

    for(k=1;k<=n1;k++)
    {
        for(i=1;i<=n1;i++)
        {
            for(j=1;j<=n1;j++)
            {
                if(d[i][j]<=(d[i][k]+d[k][j]))
                {
                    d[i][j]=d[i][j];
                    p[i][j]=p[i][j];
                }
                else
                {
                    d[i][j]=d[i][k]+d[k][j];
                    p[i][j]=p[k][j];
                }
            }
        }
    }

}
void prindp()
{
      int i,j;
      printf ("Following matrix shows the shortest distance between every pair of vertices \n");
     for (i = 1; i <= n1; i++)
     {
        for ( j = 1; j <=n1; j++)
        {
            if (d[i][j] == inf)
                printf("%7s", "INF");
            else
                printf ("%7d", d[i][j]);
        }
        printf("\n");
     }
      printf ("Following matrix shows the preceding nodes\n");
     for (i = 1; i <= n1; i++)
     {
        for ( j = 1; j <=n1; j++)
        {
            if (p[i][j] == nil)
                printf("%7s", "nil");
            else
                printf ("%7d", p[i][j]);
        }
        printf("\n");
     }
}
void prints(int i,int j)
{
    if(i==j)
    printf("%d-->",i);
    else
    {
      if(p[i][j]==nil)
      printf("NO path from %d to %d\n",i,j);
      else
      {
          prints(i,p[i][j]);
          printf("%d-->",j);
      }

    }
}
void main()
{
    int i ,j,k,a,b,c;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    n1=n;
    printf("Enter the adjacency matrix:\n");
     for (i = 1; i <= n1; i++)
     {
        for ( j = 1; j <=n1; j++)
        {
            scanf("%d",&w[i][j]);
            if(i==j)
            w[i][j]=0;
            if(w[i][j]==0&&i!=j)
            {
                w[i][j]=inf;
            }
        }
     }
     fw();
     prindp();
     do
     {
       printf("Enter two vertices to print the path:\n");
       scanf("%d %d",&a,&b);
       prints(a,b);
       printf("\n cost=%d",d[a][b]);
       printf("\nPress 1 to continue\n");
       scanf("%d",&c);
    }while(c==1);
}
