
#include <sys/types.h>		// open
#include <sys/stat.h>		// open
#include <fcntl.h>			// open
#include <unistd.h>			// read, write, close
#include <errno.h>			// errno
#include <stdio.h>			// printf
#include <stdlib.h>			// malloc
#include <string.h>

int main (int argc, char **argv) {
const char str_hello[12] = "Hello world!";
const char str_sapere[12] = "Sapere aude!";

FILE * fd = fopen(argv[1], "r+b");

if (fd == NULL) {
	printf("Cannot open file.\n");
	return 0;
}

int STRING_MATCH_COUNTER = 0;

char ch;
ch = fgetc(fd);

while ((STRING_MATCH_COUNTER < 10)) {
	if (ch == str_hello[STRING_MATCH_COUNTER]) {
		STRING_MATCH_COUNTER ++;
		
	}
	ch = fgetc(fd);
}	

if (STRING_MATCH_COUNTER == 10) {
	printf("Match found successfully!\n");
}	
else {
	printf("No matches found\n");
	return 0;
}



if (fseek(fd, -11, SEEK_CUR) != 0 ) {
	printf("Error in fseek");
	return 0;
}

/*
ch = fgetc(fd);
printf("%c\n", ch);

ch = fgetc(fd);
printf("%c\n", ch);

ch = fgetc(fd);
printf("%c\n", ch);

ch = fgetc(fd);
printf("%c\n", ch);

fputs(str_sapere, fd);
*/


int i = 0;

for (i = 0; i < 12; i++) {
	fputc(str_sapere[i], fd);
} 

if (fclose(fd) != 0) {
	printf("Error in fclose");
	return 0;
}

printf("Mischief Managed!\n");

	return 0;

}