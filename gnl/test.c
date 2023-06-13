#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

// // fd 확인
// int main(void)
// {
// 	int fd;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd < 1)
// 	{
// 		printf("open() error");
// 		exit(1);
// 	}
// 	printf("FD : %d\n", fd);
// 	close(fd);
// 	return (0);
// }

// fd 변경 
// int main(void)
// {
// 	int fd;
// 	int fd2;

// 	fd = open("test.txt", O_RDONLY);
// 	fd2 = open("test.txt", O_RDONLY);
// 	if (fd < 1 || fd2 < 1)
// 	{
// 		printf("open() error");
// 		exit(1);
// 	}
// 	printf("fd\t: %d\n", fd);
// 	printf("fd2\t: %d\n", fd2);

// 	printf("fd2 = dup(fd)\n");
// 	fd2 = dup(fd); //dup() : 파일 디스크립터 복제 함수.

// 	printf("fd\t: %d\n", fd);
// 	printf("fd2\t: %d\n", fd2);

// 	close(fd);
// 	close(fd2);
// 	return (0);
// }

// read
// int main(void)
// {
// 	int fd;
// 	char buf[100];
	
// 	fd = open("./test.txt", O_RDONLY);
// 	if (fd == -1)
// 		printf("file open error");
// 	else
// 	{
// 		read(fd, buf, sizeof(buf));
// 		printf("%s", buf);
// 		close(fd);
// 	}
// 	return(0);
// }

// // //read_smallbuf.c
// #include <unistd.h>
// #include <fcntl.h>
// #include <stdio.h>
// #include <string.h>
// #define BUFFER_SIZE 1

// int main(void)
// {
// 	char buf[BUFFER_SIZE + 1];
// 	int fd;
// 	int temp_read_size = 0;

// 	fd = open("./test.txt", O_RDONLY);
// 	printf("%d\n", fd);
// 	if (fd == -1)
// 		printf("file open error");
// 	else
// 	{
// 		while ((temp_read_size = read(fd, buf, BUFFER_SIZE)) > 0)
// 		{
// 			printf("%s\n", buf);
// 			memset(buf, 0, BUFFER_SIZE);
// 		}
// 		close(fd);
// 	}
// 	return(0);
// }

// //read_save.c
// #include <unistd.h>
// #include <fcntl.h>
// #include <stdio.h>
// #include <string.h>
// #define BUFFER_SIZE 1

// int main(void)
// {
// 	char buf[BUFFER_SIZE + 1];
// 	char *save;
// 	int fd;
// 	int temp_read_size = 0;

// 	fd = open("./test.txt", O_RDONLY);
// 	if (fd == -1)
// 		printf("file open error");
// 	else
// 	{
// 		while ((temp_read_size = read(fd, buf, BUFFER_SIZE)) > 0)
// 		{
// 			printf("%d\n", temp_read_size);
// 			buf[temp_read_size] = '\0';
// 			if(save == NULL)
// 				save = strdup(buf);
// 			else
// 				strcat(save, buf);
// 		}
// 		printf("%s\n", save);
// 		close(fd);
// 	}
// 	return(0);
// }

#include <stdio.h>

