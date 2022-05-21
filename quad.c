#include <math.h>
#include <stdio.h>

// start code here
int main() {
  long double a,b,c;
  long double d,root1,root2;

  // give me a set of values
  printf("Give me a, b, and c for the equation: \n");
  scanf("%Lf%Lf%Lf",&a,&b,&c);

  // Now lets set d equal to something
  d = b * b -4 * a * c;
  // case if d < 0 this is where i comes into play
  if (d < 0){
    printf("%.3Lf%+.3Lfi",-b/(2*a),sqrt(-d)/(2*a));
    printf(",%.3Lf%+.3Lfi\n",-b/(2*a),sqrt(-d)/(2*a));
    return 0;
  }
  // Case when d = 0 so both roots are the exact same
  else if(d == 0){
    root1 = -b/(2 * a);
    root2 = root1;
    printf("%.3Lf", root1);
    printf(", %.3Lf\n", root2);
    return 0;
  }
  // This is a case when we see both roots being a positive number
  else{
    root1 = ( -b + sqrt(d)) / (2 * a);
    root2 = ( -b - sqrt(d)) / (2 * a);
    printf("%.3Lf , %.3Lf\n", root1, root2);
    return 0;
  }
  return 0;
}
