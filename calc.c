#include <stdio.h>
#include <string.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <math.h>
=======
>>>>>>> d5bb3138921fe441be89c62ee4b46f54a68e231e
#include "boolean.h"
#include "calc.h"

//KAMUS
char equation[50];
int idx;
char CC;
<<<<<<< HEAD
boolean syntaxerror;
boolean matherror;
=======
boolean syntax;
>>>>>>> d5bb3138921fe441be89c62ee4b46f54a68e231e

//FUNGSI DAN PROSEDUR
void Start()
{
	idx=0;
	CC = equation[idx];
}

void Next()
{
	if(idx<strlen(equation))
	{
		idx++;
		CC = equation[idx];
	}
}

int CharToInt(char CC)
{
	return ((int) (CC -'0'));
}


boolean NextIsAngka()
{
	int temp;
	temp=equation[idx+1];
	return (temp=='0' || temp=='1' || temp=='2' || temp=='3' || temp=='4' || temp=='5' || temp=='6' || temp=='7' || temp=='8' || temp=='9');
}


boolean IsAngka()
{
	return (CC=='0' || CC=='1' || CC=='2' || CC=='3' || CC=='4' || CC=='5' ||CC=='6' || CC=='7' || CC=='8' || CC=='9');
}

double GetAngka()
{
	int i,j;
	double temp,Bilangan,FPengali;
	Bilangan = 0;
	while (IsAngka()){
		temp = CharToInt(CC);
		Bilangan = Bilangan*10 + temp;
		Next();
	}
	if (CC == '.')
	{
		Next();
		i = 0;
		if(!IsAngka())
		{
			syntaxerror = true;
		}
		while(IsAngka())
		{
			temp = CharToInt(CC);
			FPengali = 0.1;
			for(j=1;j<=i;j++)
			{
				FPengali = FPengali*(0.1);
			}
			Bilangan = Bilangan + (FPengali * temp);
			i++;
			Next();
		}
	}
	idx-=1;
	return Bilangan;
}


double PlusMinus()
{	
	boolean min;
	double value, HasilKaliBagi;
	char operator;
<<<<<<< HEAD
=======


	if (CC=='-')
	{
		min = true;
		Next();
	}
>>>>>>> d5bb3138921fe441be89c62ee4b46f54a68e231e
	
	value = KaliBagi();

	while (equation[idx+1]=='+' || equation[idx+1]=='-')
	{
		Next();
		operator = CC;
		HasilKaliBagi = KaliBagi();
		if (operator == '+')
		{
			value = value + HasilKaliBagi;
		}
		else if (operator == '-')
		{
			value = value - HasilKaliBagi;
		}
	}
	return value;
}


double KaliBagi()
{
	char operator;
<<<<<<< HEAD
	double value, HasilProsesPangkat;
	boolean min;

	value = Pangkat();
	
=======
	double value, HasilProsesKurung;
	boolean min;
	value = ProsesKurung();
>>>>>>> d5bb3138921fe441be89c62ee4b46f54a68e231e
	while (equation[idx+1]=='*' || equation[idx+1]=='/')
	{
		Next();
		operator = CC;
<<<<<<< HEAD
=======
		printf("%c\n",operator);
>>>>>>> d5bb3138921fe441be89c62ee4b46f54a68e231e
		if (equation[idx+1]=='-')
		{
			min = true;
			Next();
		}
<<<<<<< HEAD

		HasilProsesPangkat = Pangkat();
		if (min)
		{
			HasilProsesPangkat*=-1;
		}
		if (operator == '/')
		{
			if (HasilProsesPangkat==0)
			{
				matherror = true;
			}
			else
			{
				value = value/HasilProsesPangkat;
=======
		HasilProsesKurung = ProsesKurung();
		if (min)
		{
			HasilProsesKurung*=-1;
		}
		printf("%f\n", HasilProsesKurung);
		if (operator == '/')
		{
			if (HasilProsesKurung==0)
			{
				printf("MATH ERROR");
				exit(0);
			}
			else
			{
				value = value/HasilProsesKurung;
>>>>>>> d5bb3138921fe441be89c62ee4b46f54a68e231e
			}
		}
		else if (operator=='*')
		{
			value = value*HasilProsesPangkat;
		}
	}
	return value;
}

double Pangkat()
{
	char operator;
	double value,temp, HasilProsesKurung;
	boolean min, angkaMinus;
	int i;

	value = ProsesKurung();

	while (equation[idx+1]=='^')
	{
		Next();
		operator = CC;
		if (equation[idx+1]=='-')
		{
			min = true;
			Next();
		}
		HasilProsesKurung = ProsesKurung();
		if (min)
		{
			HasilProsesKurung*=-1;
		}
		if ((value<0)&&(HasilProsesKurung-((int)(HasilProsesKurung))!=0))
			matherror = true;

		value = pow(value,HasilProsesKurung);
	}
	return value;
}

double ProsesKurung()
{
	int X;
	double angka, value;

	X =1;
	if (idx==0) 
	{
		if (CC == '-'){
			X = -1;
			Next();
		}

		if (IsAngka())
		{
			angka = GetAngka();
			return angka*X;
		}
	}
	else 
	{
		if(equation[idx-1]=='(' || equation[idx-1]=='-')
		{
			if (CC == '-'){
				Next();
				X = -1;
			}

			if (IsAngka())
			{
				angka = GetAngka();
				return angka*X;
			}	
		}
		if (NextIsAngka())
		{
			Next();
			angka = GetAngka();
			return angka;
		}
	}

	if (idx==0)
	{
		if (equation[idx]!='(' && equation[idx]!='-')
		{
			syntaxerror = true;
		}	
	}
	else 
	{
		if(idx==strlen(equation))
		{
			if (equation[idx-1]=='*' || equation[idx-1]=='+' || equation[idx-1]=='-' || equation[idx-1]=='/' || equation[idx-1]=='^')
			{
				printf("SYNTAX ERROR\n");
				exit(0);
			}
		}

		if (equation[idx+1]!='(' && equation[idx+1]!='-')
		{
			syntaxerror = true;
		}
	}
	


	Next();
	value = PlusMinus();
	if (equation[idx+1]!=')' && equation[idx+1]!='-' && (idx!=(strlen(equation)-1)))
	{
		syntaxerror = true;
	}
	Next();


	return value;
} 

//ALGORITMA
int main()
{
	int i;
	double result, angka;
	printf("Masukkan ekspresi matematika : \n");
	scanf("%s", &equation);
	Start();
	result = PlusMinus();
	if (matherror)
	{
		printf("MATH ERROR\n");
	}
	else if (syntaxerror)
	{
		printf("SYNTAX ERROR\n");
	}
	else
	{
		printf("%.3f\n", result);
	}
}