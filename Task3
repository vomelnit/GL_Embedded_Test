    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<dirent.h>
#include <sys/stat.h>
#include <unistd.h>


void printFileProperties(struct stat stats)
{
    //struct tm dt;

    // File permissions
    //printf("File access: ");
    if (stats.st_mode & R_OK){ printf("r");} else printf("-");
    if (stats.st_mode & W_OK){ printf("w");} else printf("-");
    if (stats.st_mode & X_OK){ printf("x");} else printf("-");

    // File size
    printf(" %ld", stats.st_size);

    // Get file creation time in seconds and 
    // convert seconds to date and time format
    /*dt = *(gmtime(&stats.st_ctime));
    printf("\nCreated on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900, 
                                              dt.tm_hour, dt.tm_min, dt.tm_sec);

    // File modification time
    dt = *(gmtime(&stats.st_mtime));
    printf("\nModified on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900, 
                                              dt.tm_hour, dt.tm_min, dt.tm_sec);
	*/
}
char cwd[1000];
struct stat stats;
char file[100];
char if_size_show = 0;
char if_hidden_show =0;

    int main(int argc,char **argv)
    {
    	struct dirent **namelist;
    	int n;
    	if(argc < 1)
    	{
    		exit(EXIT_FAILURE);
    	}
    	else if (argc == 1)
    	{
    		n=scandir(".",&namelist,NULL,alphasort);
		getcwd(cwd, sizeof(cwd));
    	}
    	else if (argc == 2)
    	{	
		if (strcmp(argv[1],"-la")==0) {if_size_show = 1; if_hidden_show = 1;}
		if (strcmp(argv[1],"-a")==0) {if_hidden_show = 1;}
		if (strcmp(argv[1],"-l")==0) {if_size_show = 1;}
		
    		n = scandir(".", &namelist, NULL, alphasort);
    	}
    	if(n < 0)
    	{
    		perror("scandir");
    		exit(EXIT_FAILURE);
    	}
    	else
    	{
    		while (n--)
    		{	
			//printf("%s\n",argv[1]);			
			//printf("%d %d\n",if_hidden_show,if_size_show);
			if ((if_size_show == 1)&&(if_hidden_show==1)){
				
				char *file_path=(char*)malloc(sizeof(char)*500);	
						
				strcat(file_path,cwd);
				strcat(file_path,"/");
	    			
				strcat(file_path,namelist[n]->d_name);
				//printf("File:%s\n",file_path);
				
				stat(file_path, &stats);
				
				/*printf("\nFile access: ");
	   			 if (stats.st_mode & R_OK) printf("read ");*/
				printFileProperties(stats);
				printf("   %s \n",namelist[n]->d_name);
				free(file_path);
			}
			else if ((if_size_show == 0)&&(if_hidden_show==1)){
				printf("\n%s",namelist[n]->d_name);
			}
			else if ((if_size_show == 0)&&(if_hidden_show==0)){
				char *file=(char*)malloc(sizeof(char)*100);
				strcat(file,namelist[n]->d_name);
				char first_sym = file[0];
				if(first_sym!='.') printf("\n%s",namelist[n]->d_name);
				free(file);
			}
			else if ((if_size_show == 1)&&(if_hidden_show==0)){
				char *file_path=(char*)malloc(sizeof(char)*500);	
						
				strcat(file_path,cwd);
				strcat(file_path,"/");
	    			
				strcat(file_path,namelist[n]->d_name);
				//printf("File:%s\n",file_path);
				
				stat(file_path, &stats);
				
				/*printf("\nFile access: ");
	   			 if (stats.st_mode & R_OK) printf("read ");*/
				char *file=(char*)malloc(sizeof(char)*100);
				strcat(file,namelist[n]->d_name);
				char first_sym = file[0];
				if(first_sym!='.') {printFileProperties(stats); 
					printf("  %s \n",namelist[n]->d_name);
				}
				free(file);
				
				free(file_path);
			}
			//else printf("\n%s",namelist[n]->d_name);
    			free(namelist[n]);
			
    		}
    		free(namelist);
    	}
    	exit(EXIT_SUCCESS);
    }
