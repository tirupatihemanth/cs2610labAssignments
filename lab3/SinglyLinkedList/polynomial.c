/*
 * Author: Tirupati Hemanth Kumar
 * Roll No.: cs13b027
 * Polynomial data structure (Implementation)
 */

#include "polynomial.h"
//#include "LList.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int getcoefficient(int);
int getdegree(int);
int encodeit(int,int);

// Implementation to construct a polynomial with coefficients and powers

polynomial polynomial_construct(){
	int a,d,encode;
	polynomial new_polynomial;
	LList* lst = llist_new();
	while(1){
		a=0;
		d=0;
		scanf("%d %d",&a,&d);
		if(d>999 || d<0 || a>999 || a < -999){
			printf("OVERFLOW");
			exit(1);
		}
		if(a==0 && d==0)
			break;
		if(a==0)
			continue;
		if(a!=0 && d==0){
			encode = encodeit(a,d);
			lst = llist_append(lst,encode);
			break;
		}
		encode = encodeit(a,d);
		
		lst = llist_append(lst,encode);
	}

	new_polynomial.pHead = lst;
	return new_polynomial;
}

//Implementation to print the polynomial in the given format

void print_polynomial(polynomial expression){
	int size = llist_size(expression.pHead);
	int idx,element;
	for(idx=0;idx<size;idx++){
		element = llist_get(expression.pHead,idx);
		printf("%d %d\n", getcoefficient(element), getdegree(element));
	}
}

//Private function to encode given coefficient and degree

int encodeit(int coefficient, int degree){
	int encode;
	if(coefficient<0)
		encode = (1000-coefficient)*1000+degree;
	else if(coefficient>0)
		encode = coefficient*1000+degree;
	return encode;
}

//Private function to get the coefficent from the encoded number num

int getcoefficient(int num){
	if(num/1000000>0)
		return -(num/1000)%1000;
	else
		return num/1000;
}

//Private function to get the degree from the encoded number num

int getdegree(int num){
	return num%1000;
}

//Implementation to evaluate a polynomail the value of a polynomial at a given x

double polynomial_evaluate(polynomial expression, double x){

	int size = llist_size(expression.pHead);
	int idx=0,element;
	double ans = 0;
	for(idx=0;idx<size;idx++){
		element = llist_get(expression.pHead,idx);
		ans+= getcoefficient(element)*pow(x,getdegree(element));
	}
	return ans;
}

//Implementation to add two polynomials and returning the resultant

polynomial add_polynomial(polynomial expression1, polynomial expression2){
	int i,idx1=0,idx2=0,deg,n,coefficient;
	polynomial result;
	result.pHead = llist_new();
	
	n = getdegree(llist_get(expression1.pHead,0));
	if(getdegree(llist_get(expression1.pHead,0)) < getdegree(llist_get(expression2.pHead,0)))
		n=getdegree(llist_get(expression2.pHead,0));
	for(i=n;i>=0;i--){
		coefficient =0;
		
		if(i<=getdegree(llist_get(expression1.pHead,0)) && idx1 < llist_size(expression1.pHead)){
			if(i==getdegree(llist_get(expression1.pHead,idx1))){
				coefficient+=getcoefficient(llist_get(expression1.pHead,idx1));
				idx1++;
			}
		}

		if(i <= getdegree(llist_get(expression2.pHead,0)) && idx2 < llist_size(expression2.pHead)){
			if(i==getdegree(llist_get(expression2.pHead,idx2))){
				coefficient+=getcoefficient(llist_get(expression2.pHead,idx2));
				idx2++;
			}
		}

		if(coefficient > 999 || coefficient < -999){
			printf("OVERFLOW");
			exit(1);
		}
		if(coefficient == 0)
			continue;
		result.pHead = llist_append(result.pHead,encodeit(coefficient,i));
	}
	return result;
}

//Implementation to substract two polynomials and returning the resultant

polynomial subtract_polynomial(polynomial expression1, polynomial expression2){

	int i,idx1=0,idx2=0,deg,n,coefficient;
	polynomial result;
	result.pHead = llist_new();
	
	n = getdegree(llist_get(expression1.pHead,0));

	if(getdegree(llist_get(expression1.pHead,0)) < getdegree(llist_get(expression2.pHead,0)))
		n=getdegree(llist_get(expression2.pHead,0));

	for(i=n;i>=0;i--){
		coefficient =0;
		
		if(i<=getdegree(llist_get(expression1.pHead,0)) && idx1 < llist_size(expression1.pHead)){
			if(i==getdegree(llist_get(expression1.pHead,idx1))){
				coefficient+=getcoefficient(llist_get(expression1.pHead,idx1));
				idx1++;
			}
		}

		if(i <= getdegree(llist_get(expression2.pHead,0)) && idx2 < llist_size(expression2.pHead)){
			if(i==getdegree(llist_get(expression2.pHead,idx2))){
				coefficient-=getcoefficient(llist_get(expression2.pHead,idx2));
				idx2++;
			}
		}

		if(coefficient > 999 || coefficient < -999){
			printf("OVERFLOW");
			exit(1);
		}
		if(coefficient == 0)
			continue;
		result.pHead = llist_append(result.pHead,encodeit(coefficient,i));
	}
	return result;	
}

//Implementation for the differentiation of a polynomial

polynomial differentiate(polynomial expression){

	LList* flist = llist_new();
	polynomial final;
	int idx,size = llist_size(expression.pHead),element,coefficient,degree;
	for(idx = 0; idx<size;idx++){
		element = llist_get(expression.pHead,idx);
		degree = getdegree(element);
		coefficient = getcoefficient(element)*degree;
		if(coefficient==0)
			continue;
		if(coefficient > 999 || coefficient < -999){
			printf("OVERFLOW");
			exit(1);
		}
		element = encodeit(coefficient, degree-1);
		flist = llist_append(flist,element);

	}

	final.pHead = flist;
	return final;
}

//Implementation for the integration of a polynomial

polynomial integrate(polynomial expression){
	
	LList* flist = llist_new();
	polynomial final;
	int idx, size = llist_size(expression.pHead),element,coefficient,degree;

	for(idx = 0; idx<size; idx++){
		element = llist_get(expression.pHead,idx);
		degree = getdegree(element);
		coefficient = getcoefficient(element)/(degree+1);
		//printf("coefficients %d\n",coefficient);
		if(coefficient ==0 )
			continue;
		element = encodeit(coefficient,degree+1);
		flist = llist_append(flist, element);
	}

	expression.pHead = flist;
	final.pHead = flist;
	return expression;
}
