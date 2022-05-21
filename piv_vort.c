// Lab 10
//Include
#include<stdio.h>
#include<stdlib.h>
// Chars and Ints
char line[256];
int numlines = 22361;
int i;
//Doubles
double *xpos;
double *ypos;
double *xvel;
double *yvel;
// Double max and mins
double xmin;
double xmax;
double ymin;
double ymax;
// Double u and v
double Uvel[130][172];
double Vvel[130][172];
//Files
FILE *fp;
FILE *Xvelfile;
FILE *Yvelfile;
FILE *Vortfile;

int main(int argc, char*argv[]){
  //Positions for x and y as well as velocity
  xpos=malloc(sizeof(double)*numlines);
  ypos=malloc(sizeof(double)*numlines);
  xvel=malloc(sizeof(double)*numlines);
  yvel=malloc(sizeof(double)*numlines);
  //Error exit
  fp=fopen(argv[1],"r");
  if(fp==NULL){
    printf("There is not a file found\n");
    return 0;
  }

  fgets(line,sizeof(line),fp);
  for(int i = 0; i<numlines; i++){
    fgets(line,sizeof(line), fp);
    sscanf(line, "%lf %lf %lf %lf [^/n]",&xpos[i],&ypos[i],&xvel[i],&yvel[i]);
    xpos[i] /= 1000;
    ypos[i] /= 1000;
  }
  fclose(fp);
  // Reset values
  xmin=xpos[0];
  xmax=xpos[0];
  ymin=ypos[0];
  ymax=ypos[0];

  for(i=0; i<numlines; i++){
    if(xpos[i]<xmin){
      xmin=xpos[i];
    }
    if(xpos[i]>xmax){
      xmax=xpos[i];
    }
    if(ypos[i]<ymin){
      ymin=ypos[i];
    }
    if(ypos[i]>ymax){
      ymax=ypos[i];
    }
  }
  int count = 0;
  for(int i=0; i<130; i++){
    for(int j=0; j<172; j++){
      Uvel[i][j] = xvel[count];
      Vvel[i][j] = yvel[count];
      count++;
    }
  }
  //Print to Text X velocity
  Xvelfile=fopen("Xvel.txt", "w");
  for(int i=0; i<130; i++){
    for(int j=0; j<172; j++){
      fprintf(Xvelfile, "%*lf ",10,Uvel[i][j]);
    }
    fprintf(Xvelfile, "\n");
  }
  fclose(Xvelfile);
  // Repeat for Y velocity
  Yvelfile=fopen("Yvel.txt", "w");
  for(int i=0; i<130; i++){
    for(int j=0; j<172; j++){
      fprintf(Yvelfile, "%*lf ",9,Vvel[i][j]);
    }
    fprintf(Yvelfile, "\n");
  }
  fclose(Yvelfile);
 
  //Vortex
  double xspacing = 12*((xmax-xmin)/171);
  double yspacing = 12*((ymax-ymin)/129);
  double w[200][200];
  double X,Y;
  for(int i=2; i<168; i++){
    for(int j=2; j<128; j++){
      X = (-Vvel[j][i+2]+8*Vvel[j][i+1]-8*Vvel[j][i-1]+Vvel[j][i-2])/xspacing;
      Y = (-Uvel[j+2][i]+8*Uvel[j+1][i]-8*Uvel[j-1][i]+Uvel[j-2][i])/yspacing;
      w[j-2][i-2]=(X-Y);
    }
  }
  //Vortex print
  Vortfile=fopen("Vort.txt","w");
  for(int i=0; i<126; i++){
    for(int j=0; j<166; j++){
      fprintf(Vortfile, "%*lf ",12,w[i][j]);
    }
    fprintf(Vortfile, "\n");
  }
  //Close all
  fclose(Vortfile);
}
