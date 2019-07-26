#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	if(argc!=3){
		printf("Usage: %s <orig file> <dest file\n", argv[0]);
		return 0;
	}

	int fd_orig, fd_dest;
	
	char *buf;

	if((fd_orig = open(argv[1], O_RDONLY))!=-1)
	{
		int cnt;
		buf = malloc(4096);
		if(fd_dest = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0644)){

			do{
			cnt = read(fd_orig, buf, 4096);
			if(cnt==write(fd_dest, buf, cnt))
				continue;
			}while(cnt);
		}
		else{
			printf("Failed to open %s\n", argv[2]);
			close(fd_orig);
			return -1;
		}
		free(buf);
		close(fd_dest);
	}
	else{
		printf("Fail to open %s\n", argv[1]);
	}
	close(fd_orig);
	
	return 0;
}

