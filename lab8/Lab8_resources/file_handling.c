 #include <stdio.h>
 #include <stdlib.h>
/*
* Author :  < >
* File Handling
* How to read from and write to file 
*/


 int main(int argc, char *argv[])
 {

		if(argc!=3){
			printf("Check input format\n");	
			printf("./<exec_file> <input_file> <output_file>\n"); // To run the example run 'make' 
																//and then ./file read.txt cs13b056_write.txt 
			return 0;
		}

		/*
		*	Reading from file
		*  	Steps:
		*  	1.Declare a file pointer
		*  	2.A character pointer which will store a line
		*   3.Use 'getline' or you can also check out 'fread','fscanf' as well
		*/
       	FILE * fr;
       	char * line = NULL;
		
		// Done bother much about size_t & ssize_t, but good to learn about it 
		// These data types are used to represent the sizes of blocks that can be read or written in a single operation.
       	size_t len = 0; 
       	ssize_t read;

	
		
		fr = fopen(argv[1], "r");
       	if (fr == NULL){
    		printf("Error opening file!\n");
    		exit(1);
	   	}
       	while ((read = getline(&line, &len, fr)) != -1) {
           printf("The length of the line is: %zu\n", read);
           printf("%s\n", line);
		}
		// Good practice to close file so you know where you stopped reading
		fclose(fr);	




		/*
		*	Writing to file
		*  	Steps:
		*  	1.Declare a file pointer with 'write' permissions
		*  	2.Declare char* which you want to write
		*   3.Use 'fprintf' or check out fwrite
		*/
       	
		FILE *fwr = fopen(argv[2], "w");
		if (fwr == NULL)
		{
    		printf("Error opening file!\n");
    		exit(1);
		}
		char *text = "I want to write this.\n";
		fprintf(fwr, "%s\n", text);  

		// Good practice to flush and close while writing
		fflush(fwr);
		fclose(fwr);

		return 0;
}
