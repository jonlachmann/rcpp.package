#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
double addition(double a, double b) {
  double c = a + b;
  return c;
}