#include <stdio.h>

int main(int argc, char** argv) 
{ 
	int spans_quantity = atoi(argv[1]);
	int distance = atoi(argv[2]);
	
	int cable_length = distance*spans_quantity*(spans_quantity+1)/2;
	printf("%d",cable_length);
  
    return 0; 
} 
