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
	if ( idx <= (strlen(equation)) )
		CC = equation[idx];
}

boolean IsNegative()
//return true apabila CC berisi tanda -
{
	return (CC == '-');
}

boolean IsAngka()
{
	/*kamus lokal*/
	char temp,itemp,X;

	/*algoritma*/
	itemp = idx;
	temp = equation[itemp];
	X = CharToInt(temp);

	if ((X>=0) && (X<=9))
		return true;
	else
		return false;
}

// char NextOperator()
// {
// 	/*kamus lokal*/
// 	char temp, itemp;

// 	/*algoritma*/
// 	itemp =idx;
// 	while( itemp < (strlen(equation)) ){
// 		temp = equation[itemp];
// 		switch(temp){
// 			case '+':
// 			case '-':
// 			case '/':
// 			case '*':
// 				return temp;
// 				break;
// 			default:
// 				itemp++;
// 				break;
// 		}
// 	}
// 	// if not found
// 	return 'F';
// }

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
		return false;
	}
	else
		return true;
}

double PlusMinus()
//Mengecek apakah digit equation diawali dengan - dan/atau melakukan operasi + dan - 
{
	/*kamus lokal*/
	char X,operator;
	double HasilKaliBagi;


	/*algoritma*/
	if(IsNegative()){
		NextDigit();
		result = -1 * result;
	}
	while(IsFoundPlusMinus(&X)){
		operator = X;
		HasilKaliBagi = KaliBagi();
		if (operator == '+')
			result = result + HasilKaliBagi;
		else if (operator == '-')
			result = result - HasilKaliBagi;
	}
	return result;
}

double KaliBagi()
{
	/*kamus lokal*/

	/*algoritma*/
}

double GetAngka()
//menggabungkan semua karakter digit angka menjadi 1 angka
{
	/* kamus lokal*/
	int i,j;
	double temp,Bilangan,FPengali;
	/*algoritma*/

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
	}
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
	scanf("%s", &equation);
	Start();
	// calculate(&result);
	result = GetAngka();
	printf("\n%f",result);

}