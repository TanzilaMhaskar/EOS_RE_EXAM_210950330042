/*WAP to create a child process, send 2 float values from parent process to child process, child process will do the addition and send back to the parent , print result in parent process (use suitable IPC Mechanism).*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 
#include <unistd.h>
#include <sys/types.h>

int main(int argc , char const *argv[])
{
    
int pipe1[2];
int pipe2[2];
float arr[2];
pid_t id;
pipe(pipe1);
pipe(pipe2);
float sum;
id = fork();


if(id==0)
{
    
    read(pipe1[0],&arr,8);//read parent 
    printf("Child Process\n");
    printf("Receive integer = %.2f %.2f\n",arr[0],arr[1]);
    close(pipe1[0]);
    sum=arr[0]+arr[1];//adding two float
    write(pipe2[1],&sum,4);
    close(pipe2[1]);
}
else
{
    printf("Parent Process\n");
    printf("Enter the 2 Integer :"); //send
    scanf("%f %f",&arr[0],&arr[1]);
    write(pipe1[1],&arr,8);
    close(pipe1[1]);
    read(pipe2[0],&sum,4);
    printf("Result in parent process = %.2f\n",sum); //get the result of integer
    close(pipe1[0]);


}
}
