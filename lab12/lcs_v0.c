
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

int main(int argc, char** argv){

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

	//printf("%s\n",protein1);
	//printf("%s\n",protein2);

	char lcs[1200];
	int maxlength, start;
	for(maxlength = strlen(protein2);maxlength>=0;maxlength--){
		for(start = 0; start<= strlen(protein2) - maxlength; start++){
			for(i=start;i-start<maxlength;i++){
				lcs[i-start] = protein2[i];
			}
			lcs[i-start] = '\0';
			//printf("lcs: %s %d %d\n",lcs, start, maxlength);

			if(strstr(protein1, lcs) != NULL){
				printf("%d %s\n",strlen(lcs),lcs);
				exit(0);
			}
			else
				continue;

		}
	}	
	return 0;
}
