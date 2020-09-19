#include<stdio.h>

#define MAX 10000
// 파일 입출력
// 파일에 어떤 데이터를 저장
// 파일에 저장된 데이터를 불러오기

int main()
{
	// fputs, fgets
	char str_line[MAX];
	//char line[10000]
	FILE* my_file = fopen("/workspace/C_STUDY/test1.txt", "wb");
	//r,w,a...t,b

	if (my_file == NULL)
	{
		printf("fail to open file\n");
		return 1;
	}

	else
	{
		fputs("fputs을 이용해 글을 적어보도록 하자.\n", my_file);
		fputs("잘 적히나요\n", my_file);
	}

	fclose(my_file);

	//파일을 열고 나서 닫지 않은 상태에서 어떤 프로그램에 문제가 생기면
	//데이터 손실이 난다. 그러므로 항상 파일은 종료시에 닫아주도록 하자.
	
	//파일 불러오기 fgets 
	FILE* my_file2 = fopen("/workspace/C_STUDY/test1.txt", "rb");
	while(fgets(str_line, MAX, my_file2) != NULL)
	{
		printf("%s", str_line);
	}
	fclose(my_file2);
	
	
	// fprintf, fscanf : 정형화된 포맷에 맞춰 쓰고 싶을 때 사용한다.
	
	int num[6] = {0,0,0,0,0,0};
	int bonus = 0;
	char str1[MAX];
	char str2[MAX];
	FILE* file = fopen("/workspace/C_STUDY/test2.txt", "wb");
	
	if (file == NULL)
	{
		printf("파일 열기 실패");
		return 1;
	}
	
	else
	{
		fprintf(file, "%s %d %d %d %d %d %d", "추첨번호", 1,2,3,4,5,6);
		fprintf(file, "%s %d\n", "보너스번호", 7);
	}
	
	fclose(file);
	
	//파일 읽기 fscanf
	FILE* file2 = fopen("/workspace/C_STUDY/test2.txt", "rb");
	fscanf(file2, "%s %d %d %d %d %d %d", str1, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
	printf("%s %d %d %d %d %d %d", str1, num[0], num[1], num[2], num[3], num[4], num[5]);
	
	fscanf(file2, "%s %d", str2, &bonus);
	printf("%s %d ", str2, bonus);
	
	fclose(file2);
	
	
	return 0;
}
