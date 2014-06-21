#include <stdio.h>
#include <string.h>

void write(char* str) {

	char content[50];
	FILE * fp;

   	strcpy( content, "File successfully written. ");
   	fp = fopen("data/test.txt", "r+");

   	fprintf(fp, "%s\n", content);
   	fprintf(fp, "%s\n", str);
   
   	fclose(fp);

}

int main ()
{
   char command[50], str1[50];

   strcpy( command, "cd data\n touch test.txt" );
   system(command);

   printf("Enter data to write: ");
   scanf("%s", str1);

   write(str1);

   return(0);
}