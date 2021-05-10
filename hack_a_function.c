#include <stdio.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>

void honest_func_1 () {
	printf("It's over, Anakin! I have the high ground!\n");

	return;
}

void honest_func_2 () {
	printf("You underestimate my power!\n");

	return;
}

void * func_1_adr_to_base (void * adr) {
	void * base = (void *)adr - (void *)(((long long)adr) % 0x1000);
	return base;
}

int reserv (void * adr_1) {
	 size_t PageSize;


	 PageSize = sysconf(_SC_PAGE_SIZE);

	 if (PageSize == -1) {
	 	printf("Error in pagesize\n");
	 return -1;
	 }

	 if (mprotect(adr_1, PageSize, PROT_READ | PROT_WRITE | PROT_EXEC) == -1) {
	 	printf("Error in mprotect\n");
	 	return -2;
	 }

	 return 0;
}

long changed_code () {
	long a = &honest_func_2 - &honest_func_1 - 2;
	return (0x000000EB + a*0x00000100);
} 

void final (long * adr, long change) {
	*adr = change; 
}


int main () {
	long * AIM_OF_HACK;
	long HACK_CODE;

	honest_func_1();
	honest_func_2();


	AIM_OF_HACK = (long *)&honest_func_1;
	
	if (reserv (func_1_adr_to_base(&honest_func_1)) != 0) {
		printf("Error in reserv\n");
		return 0;
	}

	printf("From this moment on, the program is hacked \n");

	HACK_CODE = changed_code();

	final (AIM_OF_HACK, HACK_CODE);

	honest_func_1();
	honest_func_2();


	return 0;
}
