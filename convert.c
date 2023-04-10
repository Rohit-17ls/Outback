#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>

#define log_inline(x) { printf("%s", x); }
#define log(x) { printf("%s\n", x); }

void* conversion_routine(void* args){
	char* input = (char*)(args);

	char file_name[40];
	char new_file_format[40];

	sscanf(input, "%s %s", file_name, new_file_format);

	printf("\nConverting %s to %s format\n", file_name, new_file_format);

	// exec code;

}


void multi_file_conversion(){
	char ch;
	log_inline("Do you want to proceed with multi file conversion [Y/n] : ");
	scanf("%c", &ch);

	if(ch != 'Y') exit(0);

	int num_files = 0;	
	log_inline("Enter the number of files : ");
	scanf("%d", &num_files);

	log("\nEnter file names for conversion :  <filename> <extn>  \n");	
	char file_names[num_files][40];
	char new_file_formats[num_files][40];


	for(int i=0; i<num_files; i++){
		printf("Filename %d : ", i);
		scanf("%s %s", file_names[i], new_file_formats[i]);
//		log_inline(file_names[i]);
//		log(new_file_names[i]);	
	}

	printf("Converting %d files\n", num_files);

	pthread_t conversion_threads[num_files];
	char conversion_args[num_files][80];

	for(int i = 0; i < num_files; i++){
		sprintf(conversion_args[i], "%s %s", file_names[i], new_file_formats[i]);
		pthread_create(&conversion_threads[i], NULL, &conversion_routine, (void*)(conversion_args[i]));
	}

	for(int i=0; i < num_files; i++){
		pthread_join(conversion_threads[i], NULL);
	}


}



int main(int argc, char* argv[]){

	if(argc < 2){
		printf("Too few arguments for conversion\n");
		exit(1);
	}

	switch(argc){
		case 2:

			// Multiple File conversion
			if(strcmp(argv[1], "--multi") == 0){
				multi_file_conversion();
			}
			break;

		case 3:
			printf("Converting %s to %s\n", argv[1], argv[2]);
			break;
	}




	return 0;
}
