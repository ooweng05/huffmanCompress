#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "Compress.h"
#include "Extract.h"

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
   		printf ("\t _______________________________________________\n");
   		printf ("\t|                                               |\n");   
   		printf ("\t| C-compress                                    |\n");   
   		printf ("\t| E-decompress                                  |\n");   
   		printf ("\t| Q-exit                                        |\n");
   		printf ("\t|_______________________________________________|\n");
   		printf ("\n");
	   	do
	   	{
	    	printf ("\n\tPlease select the function:"); 
	    	scanf (" %c", &c);
	    	c = toupper(c);
	    	putchar('\n');
	    	if ('C' != c && 'E' != c && 'Q' != c)
	    	{ 
	     		printf ("\tFunction error,please select again!\n");
	    	}
	   	}
		while ('C' != c && 'E' != c && 'Q' != c); 
		
		if ('C' == c)
		{
			printf ("\tPlease enter the file that needs to be compressed:");
			fflush(stdin);
 	 	    gets (filename);
	 	    putchar('\n');
			 
			printf ("\tPlease enter the compressed file:");
			fflush(stdin);
	   	    gets (extractfilename);
	   	    putchar('\n');
	   	    
			t1 = clock();
			printf ("\tCompressing...");
			flag = Compress(filename , extractfilename);
			t2 = clock();
			putchar('\n');
			
		   	if (-1 == flag)
		   	{
		   		printf ("\tFailed to open the file!\n"); 
	   			exit(1); 
		   	}
		   	else
		   	{
		   		printf("\n\tCompression completed!\n\n");
				// 获取文件大小
    long original_size = get_file_size(filename);
    long compressed_size = get_file_size(extractfilename);
    if (original_size == -1 || compressed_size == -1) {
        printf("\tFailed to obtain the file size！\n\n");
    } else {
        // 计算压缩率
        double ratio = 100.0 * compressed_size / original_size;
        printf("\tOriginal size: %ld Byte\n", original_size);
        printf("\tCompressed size: %ld Byte\n", compressed_size);
        printf("\tCompression ratio: %.2f%%\n\n", ratio);
    }

		   	}
			
			printf("\tCompression time consumption: %gseconds\n" , (t2 - t1) / 1000.0);
		}
	   	else if ('E' == c)
		{ 
			printf ("\tPlease enter the file that needs to be decompressed:");
			fflush(stdin);
	   		gets (extractfilename);
	   		putchar('\n');
	   	    
	   	    printf ("\tPlease enter the decompressed file:");
			fflush(stdin);
	 	    gets (filename);
	 	    putchar('\n');
			
			t1 = clock();
			printf ("\tDecompressing...");
			flag = Extract(extractfilename , filename);
			t2 = clock();
			putchar('\n');
			
		   	if (-1 == flag)
		   	{
		   		printf ("\tFailed to open the file!\n"); 
	   			exit(1); 
		   	}
		   	else
		   	{
		   		printf("\n\tDecompression completed!\n\n");
		   	}
			
			printf("\tDecompression time consumption: %gseconds\n" , (t2 - t1) / 1000.0);
		}
	   	else 
	   	{
	    	printf ("\tGoodbye!\n"); 
	    	exit(0);
	   	}  
	}
	return 0;
}
