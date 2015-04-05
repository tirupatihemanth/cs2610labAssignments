
/*
*
* Longest Common Subsequence
* Name: Tirupati Hemanth Kumar
* Roll Number: cs13b027
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char protein1[1200], protein2[1200], lcs[1200];

void evaluate_lcs(char str1[], char str2[], int next1, int next2){

	//printf("next1: %d\t next2: %d\n", next1, next2);

	if(strlen(str2)>strlen(str1))
		return;
	
	if(strstr(str1,str2)!= NULL && (strlen(str2)>strlen(lcs)))
		strcpy(lcs, str2);
	
	//printf("str1: %s\tstr2: %s\tlcs: %s\n", str1, str2, lcs);
	char newstr1[strlen(str1)+1];
	char newstr2[strlen(str2)+1];

	if(next1<strlen(protein1)){

		strcpy(newstr1,str1);
		newstr1[strlen(str1)] = protein1[next1];
		newstr1[strlen(str1)+1] = '\0';
		evaluate_lcs(newstr1,str2, next1+1, next2);

	}

	if(next2<strlen(protein2)){

		strcpy(newstr2, str2);		
		newstr2[strlen(str2)] = protein2[next2];
		newstr2[strlen(str2)+1] = '\0';
		evaluate_lcs(str1, newstr2, next1, next2+1);

	}

	if(next1<strlen(protein1) && next2<strlen(protein2))
		evaluate_lcs(newstr1, newstr2, next1+1, next2+1);

	return;

}

int main(){

	//char protein1[1200], protein2[1200];
	char var;
	int i=0,j;
	while(1){
		var = getchar();
		if(var == '$'){
			protein1[i] = '\0';
			break;
		}
		else if(var == ' ' || var == '\t' || var == '\n')
			continue;
		protein1[i] = var;
		i++;
	}
	i=0;
	while(1){
		var = getchar();
		if(var == '$'){
			protein2[i] = '\0';
			break;
		}
		else if(var == ' ' || var == '\t' || var == '\n')
			continue;
		protein2[i] = var;
		i++;
	}

	
	printf("%s %d\n",protein1, strlen(protein1));
	printf("%s %d\n",protein2, strlen(protein2));

	evaluate_lcs("", "", 0, 0);	
	printf("%d %s\n",strlen(lcs), lcs);

	return 0;
}
