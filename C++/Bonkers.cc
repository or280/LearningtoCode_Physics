// Bonkers.cc
//   bonkers bonking in a one-dimensional box
//   usage:
//      Bonkers N dt

#include <iostream>
#include <fstream> 
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <string.h>

using namespace std;
 
struct particle {
  double x    ; // (x,y) coordinates
  double p    ; // momentum
  double im   ; // inverse mass
  double v    ; // velocity
  double T    ; // kinetic energy
  double a    ; // radius of particle
} ;

#define ranf() \
  ((double)rand()/(1.0+RAND_MAX)) // Returns a random value between 0 and 1.

// Implement     x += v dt for one particle
void PositionStep ( particle &a , double dt )
{ 
  a.x += dt * a.v ; 
}

void v2p( particle &a )
  // convert velocity into momentum
{
  a.p =  a.v / a.im ;
}

void p2v ( particle &a ) {
  // convert momentum into velocity
  a.v  = a.p * a.im ;
}

void pv2T ( particle &a ) {
  a.T = 0.5*a.v * a.p ; 
}

void collide ( particle & a , particle & b  )
  // two particles collide elastically
{
  // find the relative velocity 
  double velocity_along_line =  a.v - b.v;
  // find mass fractions
  double af = a.im / ( a.im + b.im ) ; 
  double bf = b.im / ( a.im + b.im ) ; 
  // reverse the c.o.m. velocity of each along the line of collision
  a.v -= 2.0 * af * velocity_along_line ;
  b.v += 2.0 * bf * velocity_along_line ;
  a.v = 0.8*a.v ; 
  b.v = 0.8*b.v ; 
  v2p( a ) ; 
  v2p( b ) ; 
}

// find next collision time 
double nct( particle *a , int NN , int &whichn ) {
  double dt = 0.03 ; 
  // examine all adjacent pairs from 0,1   to  NN-2,NN-1
  for ( int n = 0 ; n < NN-1 ; n ++ ) {
    double relative_velocity = a[n].v - a[n+1].v ;
    if(relative_velocity > 0.0) {
      double collision_time =  ((a[n+1].x-a[n+1].a) - (a[n].x+a[n].a))
	                        /relative_velocity ;
      if ( collision_time < dt ) {
	dt = collision_time ;
	whichn = n ;
      }
    }
  }
  return dt ;
}


void leapForward(  particle *a , int NN , double dt ) {
  for( int n = 0 ; n < NN ; n ++ ) 
    PositionStep( a[n] , dt ) ; 
}


double kineticEnergy ( particle *a , int NN )
{
  double E = 0.0 ; 
  for( int n=0 ; n < NN ; n ++ ) {
      if ( a[n].im > 0.0 ) // avoid infinitely massive objects
	E+=0.5*a[n].v*a[n].v/a[n].im;
  }
  return E ;
}


void showState ( particle *a , int n0 ,  int NN , double t )
{
  cout << "\t" << t;
  cout << "\t" << kineticEnergy(a,NN);
  for( int n = n0 ; n < NN ; n ++ ) {
    cout << "\t" << a[n].x;
    //cout << "\t" << a[n].v;
  }
  cout << endl;
}


void  simulateBonkers( particle *a , int NN , double &t , double dt , double T) {
  
  double next_print_dt = 0.0, next_collision_dt ;
  int whichn ;
  int we_are_printing_this_time = 1 ; 
  for(;t<=T;) {
    if( we_are_printing_this_time ) {
      showState ( a , 0 , NN , t) ;
      next_print_dt = dt ;
    }
    // find the next event
    next_collision_dt = nct( a , NN , whichn ) ;
    // ^^ this returns the time, and sets 'whichn'
    if ( next_collision_dt < next_print_dt ) {
      // advance time to that event, have a collision
      leapForward( a ,  NN , next_collision_dt ) ;
      t += next_collision_dt ;
      next_print_dt -= next_collision_dt ;
      collide( a[whichn] , a[whichn+1] ) ;
      we_are_printing_this_time = 0 ; 
    } else {
      leapForward( a , NN , next_print_dt ) ;
      t += next_print_dt ;
      we_are_printing_this_time = 1 ; 
    }
  }
}

int main(int argc, char* argv[])
{
  int N = 8    ; // number of particles
  double T = 50.0  ; // run time
  particle   *a ;
  double dt = 0.03 ;
  double t = 0.0 ;

  // read in any command-line arguments
  if(argc>1)   {
    sscanf( argv[1], "%d", &N ) ; // put the first command-line argument in N
  }
  if(argc>2) {
    sscanf( argv[2], "%lf", &dt ) ; // put the 2nd argument in dt
  }
  
 a = new particle[N+2] ; //The two walls, one on each side
  for ( int n=0 ; n <= N+1 ; n += N+1 ) {
    a[n].im = 0.0 ; 
    a[n].v  = 0.0 ;
    a[n].x  = 1.0*n ;
    a[n].a  = 0.0   ;
  }
  // define some masses, positions, and velocities
  for ( int n=1 ; n <= N ; n ++ ) {
    a[n].im    = 1.0/(10*ranf()) ; 
    a[n].v     = 2*ranf() ;
    a[n].x     = (n-0.5)*1.0 + ranf() ;
    a[n].a     = 0.0   ;
    //cout << "mass: " << 1.0/a[n].im << endl;
  }
  
  for ( int n=0 ; n <= N+1 ; n ++ ) {
    v2p(a[n]);
  }
  simulateBonkers( a , N+2 , t , dt , T) ; 
  
  return 0;
}
