#include <stdio.h>

int main(int argc, char** argv) 
{ 
	int n = atoi(argv[1]);
	int k = atoi(argv[2]);
	int current_stair=0;
	int steps_ctr=0;
    	int i;
  	while(current_stair<n)
	{
		current_stair=current_stair+k+1;
		steps_ctr++;
	}
	printf("%d",steps_ctr);
  
    return 0; 
} 
