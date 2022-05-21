#include<stdio.h>
#include<math.h>
#include<stdlib.h>
// exercise 3 and 4 start
double factorial(int itr){
  double factor = 1;
  for (int j = 1; j <= itr; j++){
    factor = factor * j;
  }
    return factor;
}
int main(){
  int itr = 0;
  double x = 0;
  double error = 0;
  double difference = 0;
  double answer = 0;
  char term;
  // Start asking for values
  printf("Please give me a value for x for the term e^: ");
  if(scanf("%lf%c", &x,&term) !=2 || term != '\n'){
    printf("This is not a valid input give me a positive number\n");
    return 0;
  }
  if(x <= 0){
    printf("Invalid input must be positive\n");
    return 0;
  }
  // Now lets get value for room for error
  printf("Please give me a number for the error in this series: ");
  if(scanf("%lf%c", &error,&term) !=2 || term != '\n'){
    printf("This is not a valid input give me a positive number\n");
    return 0;
  }
  if(error <= 0){
    printf("Give me a number that is positive");
    return 0;
    }
  double prev = 0;
  difference = error + 1;
  while(difference > error){
    prev = answer;
    answer = answer + (pow(x,itr) / factorial(itr));
    difference = fabs(answer - prev);
    itr++;
  }
  itr = itr - 1;
  printf("After %d terms in the series, exp(%lf) is approx. %lf with an error of %lf \n",itr,x,answer,error);
  return 0;
}
