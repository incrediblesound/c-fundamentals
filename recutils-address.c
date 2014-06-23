#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *get_line (char* query) {

	int bytes_read, nbytes;
	char *input;

	printf(query);

	input = (char *) malloc (nbytes + 1);
	bytes_read = getline (&input, &nbytes, stdin);

	if (bytes_read == -1) {
		printf("ERROR\n");
	}
	return input;
}

int main () {

	char query[50], *response;

	strcpy(query, "Type your full name: ");
	
	response = get_line(query);
	printf("%s\n", response);
	return 0;
}