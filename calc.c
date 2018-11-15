#include "calc.h"
#include <string.h>
#include <stdio.h>

void Start()
{
	idx = 0;
	CC = equation[idx];
}

void NextDigit()
//CC berisi nilai dari equation indeks +1 
{
	idx++;
	// printf("\nnow at idx %d from %d",idx,strlen(equation));
	
	if ( idx <= (strlen(equation)) )
		CC = equation[idx];
}

boolean IsNegative()
//return true apabila CC berisi tanda -
{
	return (CC == '-');
}

boolean NextIsAngka()
{
	/*kamus lokal*/
	char temp,itemp,X;

	/*algoritma*/
	itemp = idx+1;
	temp = equation[itemp];
	X = CharToInt(temp);

	if ((X>=0) && (X<=9)){
		// printf("\nNextIsAngka");
		return true;
	}
	else
		return false;
}

boolean IsAngka()
{
	switch (CC){
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return true;
			break;

		default:
			return false;
			break;
	}
		
}

boolean IsFoundPlusMinus(char* X)
//return true apabila ada operator + atau - setelah karakter CC dalam equation
{
	/*kamus lokal*/
	int itemp, temp;
	boolean found;

	/*algoritma*/
	itemp = idx;
	found = false;
	while( (itemp < (strlen(equation))) && (!found) ){
		temp = equation[itemp];
		if (( temp == '+')||( temp =='-')){
			found = true;
			*X = temp;
		}
		else
			itemp++;
	}
	if (!found){
		*X = 'F';
		// printf("\nPlusMin not found");
		return false;
		
	}
	else{
		// printf("\nPlusMin found");
		return true;
	}
}

boolean IsFoundKaliBagi(char* X)
{
	/*kamus lokal*/
	int itemp, temp;
	boolean found;

	/*algoritma*/
	itemp = idx;
	found = false;
	while( (itemp < (strlen(equation))) && (!found) ){
		temp = equation[itemp];
		if (( temp == '*')||( temp =='/')){
			found = true;
			*X = temp;
		}
		else
			itemp++;
	}
	if (!found){
		*X = 'F';
		// printf("\nKaliBagi not found");
		return false;
	}
	else{
		// printf("\nKaliBagi found");
		return true;
	}
}

double FactorValue()
{
	/*kamus lokal*/
	double angka,value;

	/*algoritma*/
	// printf("\nCC:%c at idx: %d",CC,idx);
	if (IsAngka())
	{
		// printf("idx %d IsAngka",idx);
		angka = GetAngka();
		// printf("\nFactorValue1:%f",angka);
		return angka;
	}

	if (CC != '(')
		printf("\nExpecting Real number or '(' in expression");
	NextDigit();
	value = PlusMinus();

	if (CC != ')')
		printf("\nExpecting ')' in expression");
	NextDigit();
	// printf("\nFactorValue2:%f\nidx:%d",value,idx);
	return value;
}

double PlusMinus()
//Mengecek apakah digit equation diawali dengan - dan/atau melakukan operasi + dan - 
{
	/*kamus lokal*/
	char X,operator;
	double value,HasilKaliBagi;
	boolean Min;

	/*algoritma*/
	if(IsNegative()){
		Min = true;
		NextDigit();
	}
	else
		Min = false;
	value = KaliBagi();
	if (Min)
		value = -1 * value;

	while(IsFoundPlusMinus(&X)){
		operator = X;
		HasilKaliBagi = KaliBagi();
		if (operator == '+')
			value = value + HasilKaliBagi;
		else if (operator == '-')
			value = value - HasilKaliBagi;
	}
	// printf("\nPlusMinus:%f\nidx:%d",value,idx);
	return value;
}

double KaliBagi()
{
	/*kamus lokal*/
	char operator;
	double value,HasilFactor;

	/*algoritma*/
	value = FactorValue();
	while(IsFoundKaliBagi(&operator))
	{
		HasilFactor = FactorValue();
		if (operator == '*')
			value = value * HasilFactor;
		else if (operator == '/')
			value = value / HasilFactor;
	}
	// printf("\nKaliBagi:%f\nidx:%d",value,idx);
	return value;
}


double GetAngka()
//menggabungkan semua karakter digit angka menjadi 1 angka
{
	/* kamus lokal*/
	int i,j;
	double temp,Bilangan,FPengali;
	/*algoritma*/

	Bilangan = 0;
	while (IsAngka()){
		temp = CharToInt(CC);
		Bilangan = Bilangan*10 + temp;
		NextDigit();
	}
	if (CC == '.'){ //kalau bilangan desimal
		NextDigit();
		i = 0;
		while(IsAngka()){
			temp = CharToInt(CC);
			FPengali = 0.1;
			for(j=1;j<=i;j++)
				FPengali = FPengali*(0.1);
			Bilangan = Bilangan + (FPengali * temp);
			i++;
			NextDigit();
		}
		NextDigit();
	}
	// printf("\nGetAngka:%f\nidx:%d",Bilangan,idx);
	return Bilangan;
}

int CharToInt(char CC)
{
	return ( (int)(CC -'0'));
}

void calculate(double* result)
{
	*result = PlusMinus();
}

int main(){
		Z =0;
		scanf("%s", &equation);
		Start();
		calculate(&result);
		printf("\n%f",result);
}