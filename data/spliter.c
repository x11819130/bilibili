#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
void FilePartition(FILE *sfp, FILE *dfp, int size) {
	int s = size;
	char ch;
	while (s != 0) {
		ch = fgetc(sfp);
		if (ch == EOF)
			break;
		fputc(ch, dfp);
		s--;
	}
	fclose(dfp);
}
int main() {
	/*�û������Ҫ�ָ���ļ���*/
	char sfilename[20];
	/*�û�����ָ��Ҫ���浽���ļ���*/
	char dfilename[20];
	/*����Ҫ�ָ���ֽ���*/
	int size;
	FILE *sfp, *dfp;
	printf("Please input filename to be partitioned:\n");
	/*�õ�Ҫ�ָ���ļ���*/
	gets(sfilename);
	/*��ֻ����ʽ��Ҫ�ָ���ļ�*/
	if ((sfp = fopen(sfilename, "rb")) == 0) {
		printf("Can't open the file :%s\n", sfilename);
		getch();
		exit(0);
	}
	while (!feof(sfp)) {
		/*ȡ����һ��Ҫ�ļ���*/
		printf("input filename to save the partitioned file:\n");
		scanf("%s", dfilename);
		if ((dfp = fopen(dfilename, "wb")) == 0) {
			printf("Can't open or create the file :%s\n", dfilename);
			getch();
			exit(0);
		}
		/*����˴ηָ���ֽ���*/
		printf("Please input the size of partition:\n");
		scanf("%d", &size);
		/*���ζ���ָ���ֽ������ļ����ݣ������뵽��Ӧ�ļ���*/
		FilePartition(sfp, dfp, size);
	}
	printf ( "Partition the file %s successfully!", sfilename);
	getch();
	return 0;
}
