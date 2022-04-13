// This side writes first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	// FIFO file path
    char * myfifo = "myfifo";

    // Creating the named file(FIFO)
    // mkfifo(<pathname>, <permission>)
    mkfifo(myfifo, 0666);

    int fd;   
    char arr1[80], arr2[80];
    char arr3[80],arr4[80];
    while (1)
    {
        
        fd = open(myfifo, O_WRONLY);

        
        fgets(arr2, 80, stdin);
		fgets(arr4,80,stdin);
        
        write(fd, arr2, strlen(arr2)+1);
		write(fd ,arr4,strlen(arr4)+1);
        close(fd);

        // Open FIFO for Read only
        fd = open(myfifo, O_RDONLY);

        // Read from FIFO
        read(fd, arr1, sizeof(arr1));
		read(fd, arr3, sizeof(arr3));
        // Print the read message
        printf("User2: %s\n", arr1);
	printf(" User 2: %s\n",arr3);
        close(fd);
    }
    return 0;
}

