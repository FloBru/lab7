#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void funct(double* const f,const double* const y, const double eta);

int main()
{
 const double eta=0.5;
 double tstart= 0, tend=100, dx=0.001;
 int N=(tend-tstart)/dx+1;
 double y[2];
 double ytemp[2], ytemp1[2];
 y[0] = 1e-5;
 y[1] = sqrt(eta)*y[0];
 
 double k1[2],k2[2],k3[2];
 
 ofstream out("out1.txt");
 out<<tstart<<"\t"<<y[0]<<"\t"<<y[1]<<endl;
 
 for (int i=1; i<(N-1); i++)
 {
 funct(k1,y,eta);
 
 ytemp[0] = y[0] + dx * 0.5 * k1[0];
 ytemp[1] = y[1] + dx * 0.5 * k1[1];
 
 funct(k2, ytemp, eta);
 
 ytemp1[0]= y[0]+dx*(-1*k1[0]+2*k2[0]);
 ytemp1[1]= y[1]+dx*(-1*k1[1]+2*k2[1]);

 
 funct(k3, ytemp1, eta);
 
 y[0] += dx/6*(k1[0]+4*k2[0]+k3[0]);
 y[1] += dx/6*(k1[1]+4*k2[1]+k3[1]);
 
 
  out<<tstart+i*dx<<"\t"<<y[0]<<"\t"<<y[1]<<endl;
 }
 
 out.close();
 return 0;
 
}

void funct(  double* const f, const double* const y, const double eta)
{ 
 f[0] = y[1]; 
 f[1] = (eta - y[0]*y[0])*y[0]; 
} 