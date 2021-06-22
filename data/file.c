#include <stdio.h>
int main() {
	FILE* pfile;
	char filename[20];
	int n = 1;
	printf("文件名：");
	scanf("%s", filename);
	pfile = fopen(filename, "rb+");
	fseek(pfile, 12, SEEK_CUR);
	fwrite(&n, 1, 1, pfile);
	fclose(pfile);
	printf("完成");
	return 0;
}
