#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#include "Compress.h"
#include "Extract.h"
// 大小获取函数
long get_file_size(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) return -1;
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fclose(fp);
    return size;
}

int main() 
{
	int flag;
	char c;
	char filename[100] , extractfilename[100];
	clock_t t1 , t2; 
	
	while (1)
	{
   		// ... (原有菜单省略)
	   	do
	   	{
	    	// ... (原有选择输入省略)
	   	}
		while ('C' != c && 'E' != c && 'Q' != c); 
		
		if ('C' == c)
		{
			// ... (输入文件名省略)
			t1 = clock();
			printf ("\t正在进行压缩...");
			flag = Compress(filename , extractfilename);
			t2 = clock();
			putchar('\n');
			
		   	if (-1 == flag)
		   	{
		   		printf ("\t文件操作失败!\n"); 
	   			exit(1); 
		   	}
		   	else
		   	{
		   		printf("\n\t压缩操作完成!\n\n");

		   		// 输出文件大小及压缩率
		   		long original_size = get_file_size(filename);
		   		long compressed_size = get_file_size(extractfilename);

		   		if (original_size == -1 || compressed_size == -1) {
		   			printf("\t文件大小获取失败！\n\n");
		   		} else {
		   			double ratio = 100.0 * compressed_size / original_size;
		   			printf("\t原文件大小: %ld 字节\n", original_size);
		   			printf("\t压缩后文件大小: %ld 字节\n", compressed_size);
		   			printf("\t压缩率: %.2f%%\n\n", ratio);
		   		}
		   	}
			
			printf("\t压缩的耗时: %g秒\n" , (t2 - t1) / 1000.0);
		}
	   
	}
	return 0;
}
