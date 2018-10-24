#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(){
    char * pathname = "./file.txt";
    char * m = "college apps suck\n";
    char * buffer = malloc(256);
    //printf("%ld\n", strlen(m));

    int test = open(pathname, O_CREAT | O_RDWR, 0777);

    printf("write = %ld\n", write(test, m, strlen(m)));
    printf("error %d\n", errno);
    perror("error");
    
    char * content = malloc( strlen(m) * sizeof(char));
    int end = read(test, content, 5);
    printf("read = %d\n", end);
    content[end] = '\0';
    printf("content: %s\n", content);

    printf("error %d\n", errno);
    perror("error");

    //int r = read(test, 0, 17);
    //printf("test: %d\n", test);

    printf("close = %d\n", close(test));
    return 0;
}
