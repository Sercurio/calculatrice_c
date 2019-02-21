#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "operations.h"

typedef double (*operation_t)(double, double);
typedef double (*fonctionSimple_t)(double);

void menuIntegrale(double*, double*, int*);
int menuFunSimple(int);
int calculatrice(int);
void rafraichir();
double saisi();

int main(int argc, char *argv[])
{
  int boucle = 1;

  while (boucle == 1)
    boucle = calculatrice(boucle);

  return 0;
}

int calculatrice(int boucle){
  int choix = 0;
  double result = 0;
  double a, b = 0;
  int n = 0;

  operation_t mapOpe[4] = {addition, soustraction, multiplication, division};
  fonctionSimple_t mapFun[9] = {idem, pow2, pow3, cos, sin, tan, inverse, log, exp};


  printf(" operation a effecuter\n1. + \n2. - \n3. x \n4. / \n5.Calcul d'une fonction \n6.Calcul integral \n>> ");
  scanf("%d", &choix);

  if(choix >= 1 && choix <= 4){
    result = mapOpe[choix - 1](saisi(), saisi());
  }
  else if(choix == 5){
    choix = menuFunSimple(choix);
    result = mapFun[choix - 1](saisi());
  }
  else if(choix == 6){
    choix = menuFunSimple(choix);
    menuIntegrale(&a, &b, &n);
    result = integral(a, b, n, mapFun[choix - 1]);
  }
  else{

  }
  rafraichir();
  printf("=%lf\n\n", result);
  printf("tapez 1 pour effectuer un calcul\ntapez 0 pour quitter\n");
  scanf("%d", &boucle);
  return boucle;
}

void rafraichir(){
  system("clear");
}

double saisi(){
        //fonction saisi des nombres a traiter.
        double          x = 0;
        printf("saisi nombre a traiter\n>> ");
        scanf("%lf", &x);
        return x;
}

int menuFunSimple(int choix){
  printf(" f(x)= \n1. x        2. x^2       3. x^3 ");
  printf("\n\n4. cos(x)   5. sin(x)   6. tan(x)");
  printf("\n\n7. 1/x      8. ln(x)    9. exp(x)\n>>");
  scanf("%d", &choix);
  return choix;
}

void menuIntegrale(double *a, double *b, int *n){
  int test = 0;
  while(test != 1){
    printf("saisir la borne inferieure\n>> ");
    scanf("%lf", a);
    printf("saisir la borne superieure\n>> ");
    scanf("%lf", b);
    printf("saisir le pas\n>> ");
    scanf("%d", n);
    if (*a > *b) {
            printf("veuillez saisir a plus petit que b\n\n");
    } else {
            test = 1;
    }
  }
}
