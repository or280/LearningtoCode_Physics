// Program to determine the trjectory of a planet given inital conditions.

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

#define D 2
#define A -1

struct particle
{
  double x[D];
  double v[D];
  double f[D];
  double m;
};

void Show_State(particle &a);
double Squared_Distance(particle &a);
void Force(particle &a);
void Position_Step(particle &a);
void Velocity_Step(particle &a);
void Eulers_Method(particle &a, double dt, double &t, int N);
void Eulers_Switched(particle &a, double dt, double &t, int N);
void Leapfrog_Method(particle &a, double dt, double &t, int N);


int main()
{
  double t = 0.0, dt = 0.01;
  int N =4000;
  
  particle a;
  a.v[0] = 1.5;
  a.v[1] = -0.5;
  a.x[0] = 0.0;
  a.x[1] = 1.0;
  a.m = 1.0;

  //particle b;
  //a.v[0] = 0.0;
  //a.v[1] = 0.0;
  //a.x[0] = 0.0;
  //a.x[1] = 0.0;

  //Eulers_Method(a, dt, t, N);
  //Eulers_Switched(a, dt, t, N);
  Leapfrog_Method(a, dt, t, N);

  
  return 0;

}


void Show_State(particle &a)
{
  cout << "Position = (";
  for (int i = 0; i<D; i++)
    {
      cout << a.x[i] << ",";
    }
  cout << "). ";
  cout << "Velocity = (";
  for (int i = 0; i<D; i++)
    {
      cout << a.v[i] << ",";
    }
  cout << ")" << endl;
}


double Squared_Distance(particle &a)
{
  double squared_distance = 0.0;
  for (int i = 0; i<D; i++)
    {
      squared_distance += pow(a.x[i],2);
    }
  return squared_distance;		      
}


void Force(particle &a)
{
  for (int i = 0; i<D; i++)
    {
      a.f[i] = (A*a.x[i]*a.m)/pow(Squared_Distance(a),1.5);
    }			      
}
  

void Position_Step(particle &a, double dt)
{
  for (int i = 0; i<D; i++)
    {
      a.x[i] += a.v[i] * dt;
    }		      
}


void Velocity_Step(particle &a, double dt)
{
  for (int i = 0; i<D; i++)
    {
      a.v[i] += (a.f[i] * dt)/(a.m);
    }		      
}
  

void Eulers_Method(particle &a, double dt, double &t, int N)
{
  for (int i = 0; i<N; i++)
  {
    Force(a);
    Position_Step(a,dt);
    Velocity_Step(a,dt);
    t += dt;
    for (int i = 0; i<D; i++)
    {
      cout << a.x[i] << "    ";
    }
    cout << endl;
  }
}


void Eulers_Switched(particle &a, double dt, double &t, int N)
{
  Force(a);
  for (int i = 0; i<N; i++)
  {
    Position_Step(a,dt);
    Force(a);
    Velocity_Step(a,dt);
    t += dt;
    for (int i = 0; i<D; i++)
    {
      cout << a.x[i] << "    ";
    }
    cout << endl;
  }
}


void Leapfrog_Method(particle &a, double dt, double &t, int N)
{
  Force(a);
  for (int i = 0; i<N; i++)
  {
    Position_Step(a,dt/2);
    t += dt/2;
    Force(a);
    Velocity_Step(a,dt);
    Position_Step(a,dt/2);
    t += dt/2;
    for (int i = 0; i<D; i++)
    {
      cout << a.x[i] << "    ";
    }
    cout << endl;
  }
}


//'PlanetLM' u 1:2 with lines lt rgb "violet", 'PlanetLMy' u 1:2 with lines lt rgb "green", 'PlanetLMxy' u 1:2 with lines lt rgb "blue", 'PlanetLMx' u 1:2 with lines lt rgb "yellow", 'PlanetLMx-y' u 1:2 with lines lt rgb "orange", 'PlanetLM-y' u 1:2 with lines lt rgb "pink", 'PlanetLM-x-y' u 1:2 with lines lt rgb "red", 'PlanetLM-x' u 1:2 with lines lt rgb "black", 'PlanetLM-xy' u 1:2 with lines lt rgb "grey",
