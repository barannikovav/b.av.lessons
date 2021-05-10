#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RET 0
#define MOV 1
#define ADD 2
#define SUB 3

//---------------------------------------------------------------------------------------------------------------------------------------

int* letter_switch (int* var, char s) {
	switch(s) {
				case 'a':
					return var;
					break;
				case 'b':
					return (var + 1);
					break;
				case 'c':
					return (var + 2);
					break;
				case 'd':
					return (var + 3);
					break;
				default:
					printf("Something wrong in letter switch\n");
					return 0;
					break;

			}
		}

//---------------------------------------------------------------------------------------------------------------------------------------

int func_op (char str[4]) {
	char  endword[4], mov[4], add[4], sub[4];

	strcpy(endword, "ret");
	strcpy(mov, "mov");
	strcpy(add, "add");
	strcpy(sub, "sub");

	if (strcmp(str, endword) == 0) {
		return 0;
	}

	else if (strcmp(str, mov) == 0) {
		return 1;
	}

	else if (strcmp(str, add) == 0) {
		return 2;
	}

	else if (strcmp(str, sub) == 0) {
		return 3;
	}

	else {
		printf("Operation func error\n");
		return -1;
	}


}

//---------------------------------------------------------------------------------------------------------------------------------------


int main() {
	int var[4];
	int a = 0, b = 0, c = 0, d = 0;
	int s_c = 0, i = 0, l = 0, num = 0;
	int *p;

	char str[4], sec[10], endword[4], mov[4], add[4], sub[4], f, s;

	strcpy(endword, "ret");
	strcpy(mov, "mov");
	strcpy(add, "add");
	strcpy(sub, "sub");

	while (1 != 0) {

		scanf("%s", str); //считывание операции

		if (func_op(str) == 0) {
			break;
		}

		getchar();//пропуск пробела
		getchar();//пропуск е

		f = getchar();//считывание регистра

		getchar();//пропуск х
		getchar();//пропуск запятой
		getchar();//пропуск пробела

		s = getchar();//считывание первого символа после запятой

		s_c = (int)s;//перевод первого символа после запятой в его ascii код

		if (s_c == 101) { //проверка, является ли символ буквой е
			
			s = getchar();//если проверка проходит, считываем следующую букву как тип регистра
			
			getchar();

			num = *letter_switch(var, s);

		}
		
		else if ((s_c > 47) && (s_c < 58)) {//проверка на число

			sec[0] = s;
			i++;
			
			while ((s = getchar()) != '\n') {
				sec[i] = s;
				i++;
			}

			num = atoi(sec);

		}

		else if (s_c == 45) {

			s = getchar();

			sec[0] = s;
			i++;
			
			while ((s = getchar()) != '\n') {
				sec[i] = s;
				i++;
			}

			num = -atoi(sec);


		}

		else {//если все проверки провалены, неверный ввод
			printf("Wrong second argument\n");
		}

		p = letter_switch(var, f);


		switch (func_op(str)) {
			case RET :
				break;
			case MOV :
				*p = num;
				break;
			case ADD :
				*p += num;
				break;
			case SUB :
				*p -= num;
				break;
			default :
				printf("Error in func switch\n");
				break;
		}

		printf("a = %d, b = %d, c = %d, d = %d\n", var[0], var[1], var[2], var[3]);

	}

	return 0;
}
