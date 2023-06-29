#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char** argv) {
	FILE* fp1;
	FILE* fp2;
	uint32_t  num1, num2;
	char a,b;
	
	//argc!=3 -> exit 1
	if(argc!=3){
		printf("command : ./add-nbo 'file1' 'file2'");
		return 1;
	}

	//fopen (binary)
	fp1 = fopen(argv[1], "rb");
	fp2 = fopen(argv[2], "rb");

	//file is null -> exit 1
	if (fp1==NULL || fp2==NULL){
		printf("Error: file is NULL");
		return 1;
	}

	//file read
	fread(&num1, sizeof(uint32_t), 1, fp1);
	fread(&num2, sizeof(uint32_t), 1, fp2);

	//nbo to hbo
	num1 = ntohl(num1);
	num2 = ntohl(num2);

	//print result
	uint32_t result = num1 + num2;
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", num1, num1, num2, num2, result, result);

	//close file pointer
	fclose(fp1);
	fclose(fp2);

	return 0;
}
