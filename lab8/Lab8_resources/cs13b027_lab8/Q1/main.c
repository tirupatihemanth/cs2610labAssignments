#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *input, *output;
int count,last;

void writetooutput(char *token){
	fputs(token,output);
	if(last!=1)
		fputc(' ',output);
}

char * convertolower(char *str){

	char *smallstr = (char *) malloc(sizeof(char)*(strlen(str)+1));
	int i;
	for(i=0;i<strlen(str);i++){
		smallstr[i] = tolower(str[i]);
	}
		smallstr[i] = '\0';
		//printf("%s \n",smallstr);
	return smallstr;
}

void replace(char *token, char *oldtoken, char *newtoken, char *casesense){
	
	char *suffix,*suffix1;
	int start,i,j;

	if(!strcmp(casesense,"1")){
		if(strstr(token, oldtoken) == NULL){
			//token-=depth;
			//writetooutput(token); 	 
			return;
		}
		else{
			suffix = token+strlen(token)-strlen(strstr(token, oldtoken));
			suffix1 = (char *) malloc(sizeof(char)*strlen(suffix));
			//start = strlen(token)-strlen(suffix);
			strcpy(suffix1,suffix);
			for(i=0;i<strlen(newtoken);i++){
				suffix[i] = newtoken[i];
			}
			for(j=strlen(oldtoken);j<strlen(suffix1);j++){
				suffix[i] = suffix1[j];
				i++; 
			}
			suffix[i] = '\0';
			//start += strlen(newtoken);
			suffix += strlen(newtoken);
			free(suffix1);
			if(strstr(token, oldtoken) == NULL){
				//writetooutput(token);
				return;
			}
			else{

				replace(suffix, oldtoken, newtoken, casesense);
			}
		}
	}
	else{

		char *smalltoken, *smalloldtoken;

		smalltoken = convertolower(token);
		smalloldtoken = convertolower(oldtoken);
		//printf("small token: %s\n",smalltoken);
		//printf("small oldtoken: %s\n",smalloldtoken);
		if(strstr(smalltoken,smalloldtoken) == NULL){
			//writetooutput(token);
			free(smalltoken);
			return;
		}
		else{

			suffix = token+strlen(token)-strlen(strstr(smalltoken,smalloldtoken));
			suffix1 = (char *) malloc(sizeof(char)*strlen(suffix));
			strcpy(suffix1, suffix);

			for(i=0;i<strlen(newtoken);i++){
				suffix[i] = newtoken[i];
			}
			for(j=strlen(oldtoken);j<strlen(suffix1);j++){
				suffix[i] = suffix1[j];
				i++;
			}
			suffix[i] = '\0';

			suffix += strlen(newtoken);
			smalltoken = convertolower(suffix);
			free(suffix1);
			if(strstr(smalltoken,smalloldtoken) == NULL){
				//writetooutput(token);
				free(smalltoken);
				return;
			}
			else{
				replace(suffix, oldtoken, newtoken, casesense);
			}

		}
	}
}



int main(int argc, char* argv[]){

	if(argc!=6){
		printf("Please Recheck Your Input Format\n");
		printf("./<executible> <flags 1 or 0> <input_file> <old_word> <new_word> <output_file>\n");
		return 0;
	}

	input = fopen(argv[2],"r");
	output = fopen(argv[5],"w");
	char line[500],var;
	char *token, *tokencopy = (char *) malloc(sizeof(char)*200);
	int i,tokencount=0;

	while(!feof(input)){

		i=0;
		while(1){
			var = fgetc(input);
			if(var == '\n' || var == EOF )
				break;
			else{

				line[i] = var;
				i++;

			}
		}
		count = 0;
		line[i] = '\0';
		if(line[0] == '\0')
			continue;
		for(i=0;i<strlen(line);i++){
			if(line[i] == ' ')
				count++;
		}
		//printf("line: %s\n",line);
		token = strtok(line," ");
		tokencount = 1;
		while(token != NULL){
		//	printf("token: %s %d\n",token, strlen(token));
			strcpy(tokencopy,token);
			if(tokencount == count+1)
				last = 1;
			else
				last = 0;
			replace(tokencopy, argv[3], argv[4], argv[1]);
			writetooutput(tokencopy);
			token = strtok(NULL, " ");
			tokencount++;
		}
		fputc('\n',output);
	}
	free(tokencopy);
	fclose(input);
	fclose(output);
}


