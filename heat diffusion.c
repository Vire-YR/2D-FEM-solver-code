#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

void main()
{
	int i,j,nx,ny,count=0;
	double err,dx,dy, dx2,dy2,L = 1.0, H = 2.0, w = 1.8;
    double T[200][200], GS[200][200], SOR[200][200], A[200][200];

    FILE *dirichlet_temp;
    dirichlet_temp=fopen("dirichlet_temp.xls","w");

    nx = 20;
    ny = 40;
    dx=L/nx;
    dy=H/ny;
    dx2=dx*dx;
    dy2=dy*dy;
    SOR[0][0]=0.0;

    printf("Initializing... \n");
	for(i=0;i<=nx;i++)
        for(j=0;j<=ny;j++)
            T[i][j]=0.0; //initial condition

    printf("Assigning boundary values... \n");
    // boundary conditions
    for(i=0;i<=nx;i++)
        for(j=0;j<=ny;j++)
        {
            T[i][0] = 373.0; //bottom
            T[0][j] = 273.0; //left
            T[nx][j] = 273.0;//right
            T[i][ny] = 273.0;//top
            GS[i][j] = T[i][j];
        }

    printf("Finding solution by FEM... \n");
    do
    {
    err=0.0;
        for(i=1;i<nx;i++)
            for(j=1;j<ny;j++)
        {
            SOR[i][j] = T[i][j]; // SOR
            GS[i][j] = (dx2*(T[i][j+1]+T[i][j-1])+dy2*(T[i+1][j]+T[i-1][j]))/(2*(dx2+dy2)); //GS
            T[i][j] = w*GS[i][j] + (1-w)*SOR[i][j]; // over-relaxation
            err+=fabs(T[i][j]-SOR[i][j]);
        }

    count++;

    } while(err>0.01);

    printf("No. of Iteration is %d\n", count);
    printf("Solution converged\n");

    printf("Finding solution by Analytical method... \n");

    double T1 = 100.0;
    double x,y,sum;
    int n;
    for(i=0;i<=nx;i++)
            for(j=0;j<=ny;j++)
                {
                    x = i*dx;
                    y = j*dy;
                    sum = 0.0;
                    for(n=1;n<=110;n++){
                        double a = n*M_PI/L;
                        sum = sum + ((1-pow(-1,n))/(n*M_PI))*(sinh(a*(H-y))/sinh(a*H))*sin(a*x);
                    }
                    A[i][j] = T1*2.0*sum + 273.0;
                }

    printf("Tabulating the results obtained\n\n");
    if(nx%2==0)
        i = (nx+2)/2;
    else
        i = (nx+1)/2;
    printf("i \t j \t T(GS) \t\t T(SOR) \t T(analytical)\n");
    fprintf(dirichlet_temp, "i \t j \t T(GS) \t T(SOR) \t T(analytical)\n");
    for(j=0;j<=ny;j++)
        {
            printf("%d \t %d \t %f \t %f \t %f\n",i, j, GS[i][j], T[i][j], A[i][j]);
            fprintf(dirichlet_temp,"%d \t %d \t %f \t %f \t %f\n",i, j, GS[i][j], T[i][j], A[i][j]);
        }
}
