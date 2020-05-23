#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>



//Func print file or dir data
void printFileProperties(struct stat stats)
{
    struct tm dt;

    // File permissions and directory/file
	if (S_ISDIR(stats.st_mode)){ printf("d");} else printf("-");
	if (stats.st_mode & S_IRUSR){ printf("r");} else printf("-");
	if (stats.st_mode & S_IWUSR){ printf("w");} else printf("-");
	if (stats.st_mode & S_IXUSR){ printf("x");} else printf("-");
	if (stats.st_mode & S_IRGRP){ printf("r");} else printf("-");
	if (stats.st_mode & S_IWGRP){ printf("w");} else printf("-");
	if (stats.st_mode & S_IXGRP){ printf("x");} else printf("-");
	if (stats.st_mode & S_IROTH){ printf("r");} else printf("-");
	if (stats.st_mode & S_IROTH){ printf("w");} else printf("-");
	if (stats.st_mode & S_IROTH){ printf("x");} else printf("-");



	//Links,user_id of file owner, group_id of file owner, size in bytes
	printf(" %5ld", stats.st_nlink);
	printf(" %6d", stats.st_uid);
	printf(" %6d", stats.st_gid);
	printf(" %11ld", stats.st_size);

	//Time of last modifications
	dt = *(gmtime(&stats.st_mtime));
	printf(" %4.2d.%2.2d.%4d %4.2d:%2.2d",dt.tm_mday,dt.tm_mon,dt.tm_year + 1900,dt.tm_hour,dt.tm_min);

}


// Func get data about file/dr and print it
void Print_string_about_element(char* name,char* directory){
	
		struct stat stats;
		char fullpath[1000];
		
		strcpy(fullpath,directory);
		strcat(fullpath,"/");
		strcat(fullpath,name);
		stat(fullpath, &stats);
		printFileProperties(stats);
		
		
		printf("\t\t%s\n",name);
	
	
}

char working_directory[1000];
struct stat stats;
char if_size_show = 0;
char if_hidden_show = 0;

    int main(int argc,char **argv)
    {
    	struct dirent **namelist;
    	int n;

	//Analizing entered arguments
    	if(argc < 1){
    		exit(EXIT_FAILURE);
    	}
    	else if (argc == 1){
		getcwd(working_directory, sizeof(working_directory));
    	}
    	else if ((argc >= 2)&&(argc<=4)){	
		for (int i=1;i<argc;i++){
			if (strcmp(argv[i],"-la") == 0) {if_size_show = 1; if_hidden_show = 1;}
			else if (strcmp(argv[i],"-a") == 0) {if_hidden_show = 1;}
			else if (strcmp(argv[i],"-l") == 0) {if_size_show = 1;}
			else if (argv[i][0]=='/') strcat(working_directory,argv[1]);
			else {
				getcwd(working_directory, sizeof(working_directory)); 
				strcat(working_directory,"/");
				strcat(working_directory,argv[1]);
			}

    		}
		if (strlen(working_directory)==0) getcwd(working_directory, sizeof(working_directory)); 	
    	}
	else{	
		printf("Wrong number of arguments");
		exit(EXIT_FAILURE);
    	}


	n=scandir(working_directory,&namelist,NULL,alphasort);

    	if(n < 0)
    	{
    		perror("scandir");
    		exit(EXIT_FAILURE);
    	}
    	else
    	{	
		char current_element_name[300];

    		while (n--)
    		{	
			
			strcpy(current_element_name,namelist[n]->d_name);
			
			//Data output depends on entered arguments
			if ((if_size_show == 0)&&(if_hidden_show==1)){
				printf("%s\n",current_element_name);
			}
			else if ((if_size_show == 0)&&(if_hidden_show==0)){
				if(current_element_name[0]!='.') printf("%s\n",current_element_name);
			}
			else if ((if_size_show == 1)&&(if_hidden_show==1)){
				
				
				Print_string_about_element(current_element_name,working_directory);
				
				
			}
			else if ((if_size_show == 1)&&(if_hidden_show==0)){
				if(current_element_name[0]!='.') Print_string_about_element(current_element_name,working_directory);
			}
    			free(namelist[n]);
			
    		}
    		free(namelist);
    	}
    	exit(EXIT_SUCCESS);
    }
