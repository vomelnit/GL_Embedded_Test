#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void Error_Handler(int case_num){
	if (case_num == 1) printf("Wrong number of arguments\n");
 	if (case_num == 2) printf("Arguments must be consisted of digits\n");
	if (case_num == 3) printf("Stairs quantity must be more than zero\n");
	exit(1);
}

//Func check if entered string consist of only digits
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
	
	unsigned long current_stair=0;
	unsigned long steps_ctr=0;
	unsigned long n = atoi(argv[1]);
	unsigned long k = atoi(argv[2]);

	if (n==0) Error_Handler(3);

	

  	while(current_stair<n)
	{
		current_stair=current_stair+k+1;
		steps_ctr++;
	}
	printf("%ld\n",steps_ctr);
  
    return 0; 
} 
