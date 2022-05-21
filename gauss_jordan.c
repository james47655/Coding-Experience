/*This is an example template for the Gauss-Jordan exercise. You are not required to use it. 
It simply provides an example structure to get you started.

This code does not compile and run on its own. That task falls to you. In order to get this
program working, you need to add in lines of code where we have placed comments. Keep in mind,
one comment != one line of code. The comment discussing "where the magic happens" will have
several lines in order to perform its function*/

/*The functionality of the program is up to you, and you can use whichever method you're most
comfortable with to write it. You may need more packages, or there may be other various things
you'll need in each of the steps. It depends on how you structure the program.*/

#include <stdio.h>
#include <stdlib.h>

struct matrix{
  int r,c;
  double **matf;
};
int allocateMatrix(int row, int column, struct matrix *mw){
  mw->r = row;
  mw->c = column;
  int i = 0;
  mw->matf = malloc(sizeof(double *) * row);
  for(i = 0; i<row; ++i){
      mw->matf[i] = malloc(sizeof(double) * column);
  }
  return 0;
}
int main(void) {
    /* Declare Variables */
    int i,j,k,n; /*iterators*/
    /* You'll need a few more variables, including a matrix! */
    float c;
    double x[100];
    struct matrix mw;
    /* Request System Order (Number of Equations) */
    printf("\nHow many equations: ");
    scanf("%d", &n);

    /* Allocate Dynamic Variables
       (psst... malloc is pretty good at this) */
    
    allocateMatrix(n,n+1,&mw);
    
    /* Request Augmented Matrix Values. */
    printf("\nEnter the elements of augmented matrix row-wise:\n");
    for (i = 0; i < n; i++) {
      for (j = 0; j < (n+1); j++) {
            printf(" Matrix[%d][%d]:", i, j);
            scanf("%lf", mw.matf[i] + j);
        } /*end for*/
    } /*end for*/

    /* Diagonalize the matrix. */
    for (j = 0; j < n; j++){
      for (i = 0; i < n; i++){
	if (i != j){
	  c = mw.matf[i][j] / mw.matf[j][j];
	  // There is a useful intermediate value you can compute here.
	  for (k = 0; k < (n+1); k++){
	    /*This is where the magic happens ... */
	    mw.matf[i][k] -= c*mw.matf[j][k];
	  }  /*end for*/
	} /*end if*/
      } /*end for*/
    } /*end for*/

    printf("\nThe solution is:\n");
    for (i = 0; i < n; i++){
      // One last bit of math - compute the unknown from the diagonal and constant
      x[i] = mw.matf[i][n]/mw.matf[i][i];
      printf("\n x%d=%lf\n", i, x[i]);
    } /*end for*/
    
    return 0; /*exit normally*/
} /*end main*/
