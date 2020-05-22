#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


void Error_Handler(int case_num){
	if (case_num == 1) printf("Wrong number of arguments\n");
 	if (case_num == 2) printf("Arguments must be consisted of digits\n");
	if (case_num == 3) printf("Spans and distance must be more than zero\n");
	exit(1);
}

_Bool Check_str_for_digits(char* str){
	unsigned int len = strlen(str);
	for (int i=0; i<len; i++){
		if ((str[i]<'0')||(str[i]>'9')) return false;
	}
	return true;
}

int main(int argc, char** argv) 
{ 	
	if (argc !=3) Error_Handler(1);
	if ((Check_str_for_digits(argv[1])==false)||(Check_str_for_digits(argv[2])==false))  Error_Handler(2);
	
	unsigned long spans_quantity = atoi(argv[1]);
	unsigned long distance = atoi(argv[2]);
	
	if ((spans_quantity==0)||(distance==0)) Error_Handler(3);

	/*Cable length = D + 2*D + 3*D + .. + n*D
	Cable length = D(1 + 2 + 3 + .. + n)
	1 + 2 + 3 + .. + n = n(n+1)/2 
	Cable length = D*n*(n+1)/2*/

	unsigned long cable_length = distance*spans_quantity*(spans_quantity+1)/2;
	printf("%ld",cable_length);
  
    return 0; 
} 
