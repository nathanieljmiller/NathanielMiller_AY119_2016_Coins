//Caltech AY119 2916 ex coin solver
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

int count_ways(float &amount, int &num_ways);

using namespace std;

int main(int argc, char* argv[])
{
  //cout<<"Starting Program"<<endl;

  float amount = atof(argv[1]);
  int num_ways = 0;
  
  count_ways(amount, num_ways);

  return 0;
}

int count_ways(float &amount, int &num_ways)
{
  int n_q = 0;

  //cout<<"loop through quarters"<<endl;
  while((float)(n_q*.25) <= amount)
    {
      int n_d = 0;
      //cout<<"loop through dimes"<<endl;
      while((float)(n_q*.25 + n_d*.10) <= amount)
	{
	  int n_n = 0;
	  //cout<<"loop through nickles"<<endl;
	  while((float)(n_q*.25 + n_d*.10 + n_n*.05) <= amount)
	    {
	      int n_p = 0;
	      //cout<<"loop through pennies"<<endl;
	      while((float)(n_q*.25 + n_d*.10 + n_n*.05 + .01*n_p) <= amount)
		{
		  //cout<<"check value "<<n_q*.25 + n_d*.10 + n_n*.05 + .01*n_p<<endl;
		  if((float)(n_q*.25 + n_d*.10 + n_n*.05 + .01*n_p) == amount)
		    {
		      num_ways += 1;
		      //cout<<"increment "<<num_ways<<endl;
		    }
		  n_p++;
		  //cout<<n_p<<endl;
		  //cout<<"Value is now "<<n_q*.25 + n_d*.10 + n_n*.05 + .01*n_p<<endl;
		}
	      n_p = 0;
	      n_n++;
	    }
	  n_n = 0;
	  n_d++;
	}
      n_d = 0;
      n_q++;
    }
  cout<<"The total number of ways to split $"<<amount<<" is "<<num_ways<<endl;
}
