#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd1;
 char * myfifo = "myfifo";

    // Creating the named file(FIFO)
    // mkfifo(<pathname>,<permission>)
    mkfifo(myfifo, 0666);
    
   
    char str1[80], str2[80];
    while (1)
    {
        
        fd1 = open(myfifo,O_WRONLY);
        fgets(str1, 80, stdin);
	write(fd1, str1, strlen(str1)+1);
	fgets(str2, 80, stdin);
        write(fd1, str2, strlen(str2)+1);
	strcat(str1,str2);
	printf("%s", str1);
        close(fd1);
    }
    return 0;
    }
