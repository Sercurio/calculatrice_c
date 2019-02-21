#ifndef OPERATIONS
#define OPERATIONS

double addition(double,double);
double soustraction(double,double);
double multiplication(double,double);
double division(double,double);
double idem(double);
double inverse(double);
double pow2(double);
double pow3(double);
double cos(double);
double sin(double);
double tan(double);
double log(double);
double exp(double);

double addition(double x, double y){
  return x + y;
}

double soustraction(double x, double y){
  return x - y;
}

double multiplication(double x, double y){
  return x * y;
}

double division(double x, double y){
  return x / y;
}

double idem(double x){
   return  x;
}

double inverse(double x){
   return  1 / x;
}

double pow2(double x){
  return pow(x,2);
}

double pow3(double x){
  return pow(x,3);
}

double integral(double a, double b, int n, double (*f)(double)){
  int             i = 0;
  double          s = 0, s1 = 0, s2 = 0, dx = 0, d2 = 0;
  double          x = 0;


  x = a - dx;
  dx = (b - a) / n;
  s = f(a) + f(b);
  d2 = 2 * dx;
  s1 = 0;

  for (i = 1; i <= n - 1; i = i + 2) {
          x = x + d2;
          s1 = s1 + f(x);
          //printf("%lf\n", s1);
  }
  x = a;
  s2 = 0;

   for (i = 2; i <= n - 2; i = i + 2) {
          x = x + d2;
          s2 = s2 + f(x);
          //printf("%lf\n", s2);
  }
  s = dx * (s + 4 * s1 + 2 * s2) / 3;
  return s;
}

#endif /* shield */
