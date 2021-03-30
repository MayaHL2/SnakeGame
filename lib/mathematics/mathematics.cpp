#include "Mathematics.h"

int power(int x, int n){
  int pow_x = 1;
  for(int i=0; i<n; i++){
    pow_x=x*pow_x;
  }
  return pow_x;
}
 