#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void evaluate_lcs(char protein1[], char protein2[]){
	int lcs_arr[1200][1200] = {0}, i, j, k;
	char lcs[1200];
	for(i=0;i<strlen(protein2);i++){
		for(j=0;j<strlen(protein1);j++){
			if(protein1[j] == protein2[i])
				lcs_arr[i+1][j+1] = lcs_arr[i][j]+1;
			else{
				lcs_arr[i+1][j+1] = lcs_arr[i][j+1]>lcs_arr[i+1][j]?lcs_arr[i][j+1]:lcs_arr[i+1][j];
			}
		}
	}
	printf("%d ",lcs_arr[strlen(protein2)][strlen(protein1)]);

	i = strlen(protein2);
	j = strlen(protein1);
	k=0;
	while(i>0 && j>0){

		//printf("%d",lcs_arr[i][j]);
		if(lcs_arr[i][j] == lcs_arr[i-1][j])
			i--;
		else if(lcs_arr[i][j-1] == lcs_arr[i][j])
			j--;
		else{

			i--;
			j--;
			lcs[k] = protein2[i];
			k++;
		}

	}
	lcs[k] = '\0';
	for(i= strlen(lcs)-1;i>=0;i--)
		printf("%c",lcs[i]);
	printf("\n");

}

int main(){

	char protein1[1200], protein2[1200];

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

	evaluate_lcs(protein1, protein2);

	return 0;
}
