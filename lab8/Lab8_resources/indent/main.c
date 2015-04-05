#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){

	if(argc!=3){
		printf("Please specify the input in the below format\n<./<executible> <input_file> <output_file>");
		return 0;
	}
	
	int num, indent =0,i;
	char forv[3],var;
	FILE *input, *output;
	input = fopen(argv[1],"r");
	output = fopen(argv[2],"w");
	while(!feof(input)){

		var = fgetc(input);

		if(var == 'f'){
			fputc('f',output);
			forv[0] = fgetc(input);
			forv[1] = fgetc(input);
			forv[2] = '\0';
			if(forv[0] == 'o' && forv[1] == 'r'){
				fputs("or", output);
				num = 0;
				while(1){
					var = fgetc(input);
					fputc(var,output);
					if(var == ';')
						num++;
					if(num == 2)
						break;
				}
			}
			else{
				fseek(input, -2, SEEK_CUR);
			}
		}

		else if(var == '{'){
			while(1){
				var =  fgetc(input);
				if(var!= '\t'){
					fseek(input, -1, SEEK_CUR);
					break;
				}
			}

			fputc('\n', output);
			for(i=0;i<indent;i++)
				fputc('\t',output);
			fputc('{',output);
			fputc('\n',output);
			indent+=1;
			for(i=0;i<indent;i++)
				fputc('\t',output);
		}
		else if(var == ';'){

			fputc(';',output);
			while(1){
				var =  fgetc(input);
				if(var!='\n' && var!= '\t' && var!= ' '){
					fseek(input, -1, SEEK_CUR);
					break;
				}
			}

			if(fgetc(input) == '}')
				fseek(input, -1, SEEK_CUR);
			else{
				fseek(input, -1, SEEK_CUR);
				fputc('\n',output);
				for(i=0;i<indent;i++){
			 		fputc('\t',output);
				}
			}
		}
		else if(var == '}'){

			fputc('\n',output);
			indent -= 1;
			//printf("indent:%d\n",indent);
			for(i=0;i<indent;i++)
				fputc('\t',output);
			fputc('}',output);

			while(1){
				var =  fgetc(input);
				if(var!= '\t'){
					fseek(input, -1, SEEK_CUR);
					break;
				}
			}
			var = fgetc(input);
			if(var == '}'){
				fseek(input,-1,SEEK_CUR);
				continue;
			}
			else if(var == EOF){
				fputc('\n',output);
				continue;
			}
			else{
					fseek(input, -1, SEEK_CUR);
					fputc('\n',output);
					//fputc('\n',output);
					for(i=0;i<indent;i++)
						fputc('\t',output);
			}

		}
		else if(var == ')'){
			while(1){
				var =  fgetc(input);
				if(var!= '\t'){
					fseek(input, -1, SEEK_CUR);
					break;
				}
			}
			fputc(')',output);
		}
		else if(var == '#'){
			while(var != '\n'){
				fputc(var,output);
				var = fgetc(input);
			}
			fputc('\n',output);
			var = fgetc(input);
			while(1){
				if(var != '\t'){
					//fputc('\n',output);
					if(var == '\n'){
						fputc('\n',output);
						fseek(input,1,SEEK_CUR);
					}
					else if(var == ' ')
						fputc(' ',output);
					else{
						fseek(input,-1,SEEK_CUR);
						break;
					}
				}
				// else if(var == '\n'){
				// 	fputc('\n',output);
				// 	fseek(input,1,SEEK_CUR);
				// }
				// else if(var == ' ')
				// 	fputc(' ',output);
				// else break;
				var = fgetc(input);
			}
		}
		else if(var == '\t')
			continue;
		else if(var == '\n')
			continue;
		else{
			if(feof(input))
				return 0;
			fputc(var, output);
		}

	}

	return 0;
}