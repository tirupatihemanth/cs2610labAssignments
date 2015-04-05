/*
 * Author: Shivam Srivastava
 * Big Integer data structure (Implementation)
 */

#include "BigInt.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int valid(char* str){


	if(str==NULL){
		return 0;
	}

	char* tempStr = str;

	if(tempStr[0]=='-')
		tempStr++;

	while(*tempStr!='\0'){
		if(*tempStr<'0' || *tempStr>'9'){
			return 0;
		}
		tempStr++;
	}
	return 1;
}

// Parse a string to make it a Big Integer
bigint make_bigint(char* str){

	if(!valid(str)){
		bigint flag_bigInt = make_bigint("-1");//'-1' is useful to indicate an invalid string for factorial
		flag_bigInt.length = -1;//A negative length is like a flag indicating an invalid string
		//So, flag_bigint flags invalid strings for both, main and factorial at the same time.
		return flag_bigInt;
	}

	//Assume that a valid string has been entered at this point
	
	bigint number;
	if(str[0]=='-')
		number.pos = 0;
	else
		number.pos = 1;//The first digit can be '+' also. Take care of that.

	//Find the length of the string first. Allocate the memory to the new string. Then fill the string.

	int length = 0;//Stores the meaningful length without the trailing zeros
	int trailingZeros = 0;//counts the number of trailing zeros

	char* tempStr = str;
	if(number.pos==0)
		tempStr++;//Start the string from the digits after skipping the negative sign '-'

	int flag = 0;//This flag is used to check the trailing zeros in the beginning of a number

	//Find length
	while(*tempStr!='\0'){
		if(flag==0 && *tempStr=='0')
			trailingZeros++;
		
		else if(*tempStr!='0' && flag==0){
			flag = 1;
			length++;
		}
		else
			length++;
		
		tempStr++;
	}

	if(length==0)//all were zeros
	{
		number.length = 1;
		number.value = (char*)malloc(2*sizeof(char));
		number.value[0] = '0';
		number.value[1] = '\0';
		return number;
	}

	//If the number was not zero, come here
	number.length = length;
	//Allocate memory dynamically
	number.value = (char*)malloc((length+1)*sizeof(char));//+1 for an extra null character at the end
	tempStr = str;
	if(number.pos==0)
		tempStr++;//Start the string from the digits after skipping the negative sign '-'


	int index=0;
	//Fill in the string for value
	while(index<length){
		number.value[index] = tempStr[index+trailingZeros];
		index++;
	}
	number.value[index] = '\0';
	return number;
}

// Prints a Big Integer
void print_bigint(bigint big_num){
	if(!big_num.pos)
		printf("-");
	printf("%s\n",big_num.value);
}

// Converts an integer to a bigint
bigint int_to_bigint(int num){

	if(num==0)
		return init_bigint();
	else{
		int length = 0;
		int tempNum = num;
		while(tempNum!=0){
			tempNum/=10;
			length++;
		}
		if(num<0)
			length++;
		char* value = (char*)malloc((length+1)*sizeof(char));

		value[length] = '\0';//Terminate the string with a NULL character

		if(num<0)
			value[0] = '-';

		int i = length-1;
		tempNum = num>0 ? num:-num;
		
		while(tempNum!=0){

			value[i] = (tempNum%10)+48;
			tempNum/=10;
			i--;

		}
		return make_bigint(value);
	}
}

// Initialize a bigint to zero
bigint init_bigint(){

	char* num = (char*)malloc(2*sizeof(char));
	num[0] = '0';
	num[1] = '\0';
	return make_bigint(num);
	
}

// Compares two bigints and returns 0 if equal, +1 if a > b and -1 if a < b
int compare_bigint(bigint a, bigint b){
	
	if(!a.pos&&b.pos||b.length>a.length&&b.pos||a.length>b.length&&!a.pos)
		return -1;
	else if(a.pos&&!b.pos||a.length>b.length&&a.pos||b.length>a.length&&!b.pos)
		return 1;
	
	//At this point both the numbers are of the same length

	int i = 0;
	for(i=0;i<a.length;i++){

		if(a.value[i]>b.value[i])
			if(a.pos)
				return 1;
			else
				return -1;
		else if(a.value[i]<b.value[i])
			if(a.pos)
				return -1;
			else
				return 1;
		else
			continue;
	}
	return 0;//Both are equal if the code reaches this point. Anyone can be returned.
	
}

// Zero justify a number. Makes -0 in the result to +0 if bigint's valuation is
// zero.
bigint zero_adjustment(bigint big_num){
	//This function assumes that the variable "value" always stores numbers with no zeroes trailing. If a zero is at the 1st pos then
	//the number stored is 0.
	if(big_num.value[0]=='0' && !big_num.pos)
		big_num.pos = 1;
	return big_num;
}

// Multiply a big int with 10^d. 'd' is positive.
bigint shift_by_power_of_10(bigint big_num, int d){

	char* newValue = (char*)malloc((big_num.length+d+1)*sizeof(char));//Terminating with NULL. Hence, the +1 in size.
	
	int i = 0;
	for(i = 0;i<big_num.length;i++){
		newValue[i] = big_num.value[i];
	}
	for(i = big_num.length; i<(big_num.length+d);i++){
		newValue[i] = '0';
	}

	newValue[i] = '\0';//Terminating the string with NULL

	return make_bigint(newValue);
}


void addValues(bigint bigger_num, bigint smaller_num, char* result, int result_length){
	//Here, bigger_num has the character array with bigger absolute value and smaller_num the smaller absolute value.
	//No negative or positive sign exists in the strings. If the numbers are negative, the result[0] has a '-' sign stored already.
	//All the strings are non-null strings.
	//'result_length' stores the size of the result character array which stores the digits.
	//An additional space is already created for a possible carry in the result.
	//In case of negative numbers, a negative sign has already been stored in the [0] index of the result array.
	//The result_length doesn't include the [0] index in case of the negative numbers

	int i, j, k, carry = 0;

	for(i=bigger_num.length-1, j=smaller_num.length-1, k=result_length-1; i>=0 && j>=0 && k>=0; i--,j--,k--){
		int num1 = (int)bigger_num.value[i] - 48;// 48 is the ASCII of 0
		int num2 = (int)smaller_num.value[j] - 48;

		if(bigger_num.pos)
			result[k] = ((num1+num2+carry)%10) + 48;
		else
			result[k+1] = ((num1+num2+carry)%10) + 48;

		carry = (num1+num2+carry)/10;
	}
	//At this point, either the bigger_num is exhausted or still remains. Check.


	while(i>=0){
		int num1 = (int)bigger_num.value[i] - 48;// 48 is the ASCII of 0

		if(bigger_num.pos)
			result[k] = ((num1+carry)%10) + 48;

		else
			result[k+1] = ((num1+carry)%10) + 48;

		carry = (num1+carry)/10;
		i--;k--;
	}

	//If a carry remains, assign the value 1. Else, assign 0.
	if(carry==1){
		if(bigger_num.pos)
			result[k] = 49;
		else
			result[k+1] = 49;
	}
	else{
		if(bigger_num.pos)
			result[k] = 48;
		else
			result[k+1] = 48;
	}

}



// Adds two bigints and returns the result which is a bigint
bigint bigint_add(bigint a, bigint b){

	//If they are of the opposite signs, then send them for subtraction
	if(a.pos==0&&b.pos==1||a.pos==1&&b.pos==0){

		if(a.pos==0){
			a.pos = 1;//Make it positive and send it for subtraction.
			return bigint_sub(b,a);//Returns (b-a)
		}

		else{
			b.pos = 1;//Make it positive and send it for subtraction.
			return bigint_sub(a,b);//Returns (a-b)
		}
	}
	//If of the same sign, then add.
	else{
		bigint bigger_num, smaller_num;// Here the bigger number is in terms of the absolute quantity.

		if(!a.pos){
			if(compare_bigint(a,b)==1){
				bigger_num = b; smaller_num = a;
			}
			else if(compare_bigint(a,b)==-1){
				bigger_num = a; smaller_num = b;
			}
			else{
				//Both are equal. Assign any number to any variable.
				bigger_num = a; smaller_num = b;
			}
		}
		else{
			if(compare_bigint(a,b)==1){
				bigger_num = a; smaller_num = b;
			}
			else if(compare_bigint(a,b)==-1){
				bigger_num = b; smaller_num = a;
			}
			else{
				//Both are equal. Assign any number to any variable.
				bigger_num = b; smaller_num = a;
			}
		}

		//At this point, bigger_num has the larger number in absolute terms. The 'smaller_num' contains the other.
		//Now, create a new character array which can hold the sum of the two terms and pass that array to make_bigint
		//For the new character array, assign memory 1 greater than the length of the bigger_num.
		//In case the left hand most field doesn't get filled up, then assign 0 to it. make_bigint takes care of that.

		int new_length = bigger_num.length+1;//This length excludes the negative sign.
		char* new_value;
		if(bigger_num.pos==0){
		 	new_value = (char*)malloc((new_length+1+1)*sizeof(char));//+1 for the negative sign and +1 for terminating it with NULL
			new_value[0] = '-';
			new_value[new_length+1] = '\0';//Terminating with a null character
		}
		else{
		 	new_value = (char*)malloc((new_length+1)*sizeof(char));//+1 for terminating it with null.
			new_value[new_length] = '\0';//Terminating with a null character
		}

		addValues(bigger_num, smaller_num, new_value, new_length);//Does string addition and stores the result in new_value
 		return make_bigint(new_value);
	}//Else ends
}

//Here, 'a' and 'b' are both positive.
//'a' is greater than 'b'
//Do simple subtraction using borrowing.
//Just do a string subtraction. Pass the string to make_bigint. Return the result obtained from that.
bigint borrow_subtraction(bigint a, bigint b){

	char* result_str = (char*)malloc((a.length+1)*sizeof(char));
	result_str[a.length] = '\0';

	int i = a.length-1, j = b.length-1;
	
	while(i>=0 && j>=0){

		if((a.value[i]-b.value[j])>=0){
			result_str[i] = a.value[i] - b.value[j] + 48;
		}
		
		else{
			result_str[i] = a.value[i] - b.value[j] + 10 + 48;
			
			//Get the borrow from the nearest non-zero number and make the in between numbers as 99..
			int k = i-1;
			while(a.value[k]=='0'){
				a.value[k] = '9';
				k--;
			}
			a.value[k]-=1;
		}

		i--; j--;
	}

	//At this point, 'j' has exhausted. Just copy the rest of the digits to the result_str.
	while(i>=0){
		result_str[i] = a.value[i];
		i--;
	}

	return make_bigint(result_str);
}


// Subtracts two bigints and returns the result which is a bigint
// Returns a-b
bigint bigint_sub(bigint a, bigint b){

	if(a.pos==0&&b.pos==1){
		b.pos = 0;
		return bigint_add(a,b);
	}
	else if(a.pos==1&&b.pos==0){
		b.pos = 1;
		return bigint_add(a,b);
	}

	//At this point, both the numbers are of the same sign. So, a normal subtraction will work.
	else{
		int max_num = compare_bigint(a,b);

		//Case: a>b and both are negative. Example: a = -20 ; b = -30
		//a-b = (-x) - (-y) = y-x. 'y' and 'x' are positive. And 'y' is greater than 'x'.
		if(a.pos==0 && max_num==1){
			b.pos = 1;
			a.pos = 1;
			return bigint_sub(b,a);//Returns (y-x). 'y' and 'x' are positive.
		}

		//Case: b>a and both are negative
		//a-b = (-x) - (-y) = y-x. 'y' and 'x' are positive. 'x' is greater than 'y'.
		//So, do x-y and then change the sign to negative. Then return.
		else if(a.pos==0 && max_num==-1){
			
			a.pos = 1;
			b.pos = 1;
			bigint tempNo = bigint_sub(a,b);
			tempNo.pos = 0;
			return tempNo;
		}


		// Case: b>a and both are positive
		// a-b = x-y. 'x' and 'y' are positive
		// Do y-x and change the sign, then return.
		else if(a.pos==1 && max_num==-1){
			bigint tempNo = bigint_sub(b,a);
			tempNo.pos = 0;
			return tempNo;
		}

		//Case: a>b and both are positive
		else if(a.pos==1 && max_num==1){
			return borrow_subtraction(a,b);
		}

		//Case: Both are equal. Return 0.
		else{
			return init_bigint();
		}

	}
}

// Multiplies two big ints and returns a bigint
bigint bigint_mul(bigint a, bigint b){
	// Idea: Multiply the bigger number by a digit of the smaller number. Then shift by the digit's 10's place. Add this newly found
	// multiplication to the already calculated result. Keep adding until all the digits of the smaller number exhaust.

	bigint multiplicand_table[9];// [0] stores the multiplicand. [1] stores multiplicand*2. [2] stores multiplicand*3 and so on.
	int positive = 0;//Stores whether the multiplication is positive or negative. 0 means negative. 1 means positive.

	if((a.pos==0 && b.pos==0)||(a.pos==1 && b.pos==1))
		positive = 1;
	else
		positive = 0;

	a.pos = 1; b.pos = 1;//Make both the numbers positive for multiplication.

	int compare =  compare_bigint(a,b);
	bigint bigger_num, smaller_num;

	//If 'a' is greater than or equal to 'b' then do this.
	if(compare==1||compare==0){
		bigger_num = a; smaller_num = b;
	}
	//If 'b' is greater than 'a' then do this.
	else{
		bigger_num = b; smaller_num = a;
	}

	
	//Now fill the multiplicand table from 1 to 9.

	multiplicand_table[0] = bigger_num;// bigger_num*1
	multiplicand_table[1] = bigint_add(bigger_num,bigger_num);// bigger_num*2
	multiplicand_table[2] = bigint_add(multiplicand_table[1],multiplicand_table[0]);//bigger_num*3
	multiplicand_table[3] = bigint_add(multiplicand_table[2], multiplicand_table[0]);//bigger_num*4
	multiplicand_table[4] = bigint_add(multiplicand_table[3], multiplicand_table[0]);//bigger_num*5
	multiplicand_table[5] = bigint_add(multiplicand_table[4], multiplicand_table[0]);//bigger_num*6
	multiplicand_table[6] = bigint_add(multiplicand_table[5], multiplicand_table[0]);//bigger_num*7
	multiplicand_table[7] = bigint_add(multiplicand_table[6], multiplicand_table[0]);//bigger_num*8
	multiplicand_table[8] = bigint_add(multiplicand_table[7], multiplicand_table[0]);//bigger_num*9

	bigint result = init_bigint();


	int i = 0;//iterator
	for(i = smaller_num.length-1;i>=0;i--){

		if((smaller_num.value[i]-48)>=1){//Only if the digit is non zero will it add to the result.
			bigint tempNum = shift_by_power_of_10(multiplicand_table[smaller_num.value[i]-48-1],(smaller_num.length-1-i));
			result = bigint_add(result, tempNum);
		}

	}
	result.pos = positive;

	return result;
}


//Uses subtraction repeatedly to find the remainder and the quotient.
//Stores the remainder in a new bigint and uses 'pos' to store the quotient.
//returns this new bigint
bigint get_remainder_quotient(bigint dividend, bigint divisor){

	int quotient = 0;

	while(compare_bigint(dividend, divisor)>=0){
		dividend = bigint_sub(dividend,divisor);
		quotient+=1;
	}

	dividend.pos = quotient;//Will be 1 anyway, but to ensure it. Not very crucial.
	return dividend;
}



//TODO: Define the division for negative numbers. Define it simply as the truncation of the fractional part.
// Divides two bigints and returns a bigint similar to 9/4 = 2
// Long division method.
bigint bigint_div(bigint a, bigint b){

	if(compare_bigint(b, make_bigint("0"))==0){
		printf("Divide by ZERO error.\n");
		return make_bigint("0");
	}

	//Take care of the sign first
	int positivity = ((a.pos==1&&b.pos==1)||(a.pos==0&&b.pos==0))?1:0;
	a.pos = 1; b.pos = 1;

	//Now check if we really need to divide in the first place.
	int max_flag = compare_bigint(a,b);

	if(max_flag<0)
		return init_bigint();//No need to divide as the dividend is lesser in magnitude than the divisor.
	
	else if(max_flag==0){
		bigint tempBigInt = make_bigint("1");
		tempBigInt.pos = positivity;
		return tempBigInt;
	}

	else{

		char toAppend[2];
		toAppend[1] = '\0';

		//Quotient stores the final answer we need to return. For every character seen in the dividend, a number
		//gets added to the quotient.
		char* quotient = (char*)malloc((a.length+1)*sizeof(char));
		quotient[0] = '\0';

		//The current dividend can be at most the divisor's length +1. The extra +1 is for '\0'.
		char* current_dividend_str = (char*)malloc((b.length+1+1)*sizeof(char));
		current_dividend_str[0] = '\0';
		//Long division

		int dividend_index = 0;//This stores the current dividend index and acts as the iterator in the long division method

		//Take character by character from the dividend and perform long division
		while(dividend_index<a.length){
	
			toAppend[0] = a.value[dividend_index];
			strcat(current_dividend_str, toAppend);
			bigint current_dividend_bigint = make_bigint(current_dividend_str);

			int compare_division_state = compare_bigint(current_dividend_bigint, b);
			if(compare_division_state==-1){
				quotient[dividend_index] = '0';
			}
			else{

				//remainder is indeed positive. So the 'pos' field is redundant. So, we use the 'pos' field to store the quotient.
				//The value field stores the remainder. Length stores the length of the remainder.
				//The quotient will only be a single digit.
				bigint remainder = get_remainder_quotient(current_dividend_bigint, b);
				quotient[dividend_index] = remainder.pos+48;// 'pos' stores the remainder. 48 is the ASCII value of 0.
				strcpy(current_dividend_str,remainder.value);

			}
			dividend_index++;
		}
		bigint tempBigInt = make_bigint(quotient);
		tempBigInt.pos = positivity;
		return tempBigInt;
	}
}
