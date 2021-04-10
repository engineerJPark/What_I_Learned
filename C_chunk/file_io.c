//fileio


//include
#include<stdio.h>
#include<stdlib.h>
#include<errono.h>

//fileio
int main(int argc, char *argv[]){
	int i;
	
	for(i = 1; i < argc; i++){
		FILE *fp = fopen(argv[i], "r");
		if(fp == NULL){
			fprintf(stderr, "%s : can't open '%s' (%s)\n", argv[0], argv[i], strerror(errno));
			return EXIT_FAILURE;
		}
		else{
			//do something
			fclose(fp);
		}
	}
	if(argc == 1){/*do something*/}
	return EXIT_SUCCESS;
}

// 참고자료
// https://modoocode.com/64
// https://modoocode.com/105
// https://modoocode.com/33
// https://mystyle1057.tistory.com/entry/C%EC%96%B8%EC%96%B4-%EA%B0%95%EC%A2%8C-%EC%98%A4%EB%A5%98%EC%B2%98%EB%A6%AC-errno-strerror-strerrorr
// https://m.blog.naver.com/sharonichoya/
// argv[0]는 프로그램 실행 경로를 담는다. 그 다음 오프셋 부터는 그냥 main함수가 받는 정보
// argc는 argv에 담긴 경로의 개수