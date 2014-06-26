#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *get_line (char* query) {

	int bytes_read, len, nbytes = 100;
	char *input;

	printf("%s", query);

	input = (char *) malloc (nbytes + 1);
	bytes_read = getline (&input, &nbytes, stdin);

	if (bytes_read == -1) {
		printf("ERROR\n");
	}
	
	len = strlen(input);
	if( input[len-1] == '\n' ) { 
		input[len-1] = 0;
	}
	return input;
}

void make_file (char* query){
	char filename[20],ext[10], name[30], line[100], carrot[5], test[5];
	strcpy(test, "end");
	FILE * fp;
	strcpy(ext, ".txt");
	strcpy(filename, get_line(query));
	strcpy(name, filename);
	strcat(filename, ext);
	fp = fopen(filename, "w+");
	strcpy(carrot, ">");
	while(1) {
		strcpy(line, get_line(carrot));
		if(strcmp(line, test) == 0) {
			break;
		}
		fprintf(fp, "%s\n", line);
	}
	fclose(fp);
}

int main () {

	char query[50], name[50];

	strcpy(query, "Name of this note: ");
	make_file(query);
	return 0;
}