# GL_Embedded_Test

TASK 1:

Download GL_Task1.c and execute command [gcc -o Task1 GL_Task1.c]

To start script you need two unsigned integer arguments.

For example: [./Task1 13 3]




TASK 2:

Download GL_Task2.c and execute command [gcc -o Task2 GL_Task2.c]

To start script you need two unsigned integer arguments.

For example: [./Task2 80 77]



TASK 3:

Download GL_Task3.c and execute command [gcc -o lss GL_Task3.c]

This program has different parameters.

    ./lss - show list of files and directories in currect directory
    
    ./lss [path] - show list of files and directories in directory of entered path. It might be absolute or ralative.
    
        For example: ./lss /usr/bin - show list of files and directories in /usr/bin
        
                     ./lss usr/bin - show list of files and directories in [current dir]/usr/bin
                     
    ./lss -a   - show list of all files and directories (even hidden)
    
    ./lss -l   - show data about files and directories 
    
        Output for example:
        
        permissions and if_dir  |    number of links | user_id of owner| group_id of owners |  size in bytes  | Date of last modification |  Time of last modification | File/dir  name
        
        drwxr-xrwx                    3                         1000        1000                 4096               04.03.2020                      5:12	                .jssc
        
    ./lss -la        - combination of -l and -a
    
    ./lss -l -a      - combination of -l and -a
    
    
Also you can combine parameters, like [./lss files/usr/mydir -l -a]
