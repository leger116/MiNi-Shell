#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char ** argv){
	if (argc == 1){
		fprintf(stderr, "minsh: At least one argument required\n");
		return 1;
	}
	int i = 1;	
	for ( i = 1 ; i < argc ; i++ ){
		// 打开最后一个参数，看看是目录还是文件
		struct stat dirstat;
		if (stat(argv[i], &dirstat) < 0 ){	
			fprintf(stderr, "error\n", argv[i]);
			continue;
		}
		if ( unlink(argv[i]) < 0 ){
			fprintf(stderr, "minsh: %s - ", argv[i]);
			perror("");
		}

	}
	return 0;
}

