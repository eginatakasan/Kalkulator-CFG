#ifndef calc_H
#define calc_H

#include "boolean.h"

typedef char string[20];
char CC;
string equation;
double hasil;
int idx;
double result;

void start();
void NextDigit();
boolean IsNegative();
boolean IsAngka();
boolean IsFoundPlusMinus();
char NextOperator();
int CharToInt(char CC);

double PlusMinus();
double KaliBagi();
double Kurung();
double GetAngka();

#endif