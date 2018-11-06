#include <stdio.h>
#include <stdlib.h>

#define MaxWidth 1000
#define MaxHeight 1000
void main()
{

		char cArray[100];
		int iWidth, iHeight, iRow, iCol;
		unsigned int cTemp;
		unsigned char cImage [MaxWidth][MaxHeight];
		unsigned char cImage1 [MaxWidth][MaxHeight];
		FILE *filePointer = NULL,  *filePointerOut = NULL,*fp=NULL;

		filePointer = fopen("codes/images/x31_f18.ascii.pgm","r");
		filePointerOut = fopen("codes/images/bordered_x31_f18.ascii.ascii.pgm","w");
		//fp=fopen("codes/images/test_image.pgm","w");

		if (filePointer == NULL)
		{
			printf("cannot open file");

		}else
		{  
			fgets (cArray, 99, filePointer);
			fputs(cArray, filePointerOut);

			fgets (cArray, 99, filePointer);
			fputs(cArray, filePointerOut);

			fscanf(filePointer,"%d %d\n", &iWidth, &iHeight);
			fprintf(filePointerOut,"%d %d\n", iWidth, iHeight);
			printf("\niWidth=%d iHeight=%d\n",iWidth,iHeight);
			printf("1 ");
			fgets (cArray,99, filePointer);
			fputs(cArray,filePointerOut);
            printf("2 ");

			for (iRow = 0; iRow< iHeight; iRow++)
			{
				for (iCol = 0; iCol< iWidth; iCol++)
				{
					fscanf(filePointer, "%d ", &cTemp);

					if (cTemp != EOF)
					{
						cImage [iRow][iCol] = cTemp;
					}

				}

			}
			printf("3: cImage array made \n");
		    
		   /* for(iRow=0;iRow<iHeight;iRow++)
		    {
		    	for(iCol=0;iCol<iWidth;iCol++)
		    	{
		    		cImage1[iCol][iRow]=cImage[iRow][iCol];
		    	}
		    }
		    printf("3: Array Transposed\n");*/
		    for(iRow=5; iRow<(iHeight-5); iRow++)
		    {
		    	for(iCol=5; iCol<10; iCol++)
		    	{ printf("4 ");
		    		cImage[iRow][iCol]=255;
  		    	}
  		    	printf("5 ");
		    }
		    for(iRow=5; iRow<(iHeight-5); iRow++)
		    {
		    	for(iCol=(iWidth-5); iCol>(iWidth-10); iCol--)
		    	{ printf("6 ");
		    		cImage[iRow][iCol]=255;
  		    	}
  		    	printf("7 ");
		    }
		    for(iCol=10; iCol<(iWidth-10); iCol++)
		    {
		    	for(iRow=5; iRow<10; iRow++)
		    	{   printf("8 ");
		    		cImage[iRow][iCol]=255;
  		    	}
  		    	printf("9 ");
		    }
		    for(iCol=10; iCol<(iWidth-10); iCol++)
		    {
		    	for(iRow=(iHeight-5); iRow>(iHeight-10); iRow--)
		    	{   printf("10 ");
		    		cImage[iRow][iCol]=255;
  		    	}
  		    	printf("11 ");
		    }

		    printf("4: Array swapped\n");
		    for(iRow=0; iRow<iHeight; iRow++)
		    {
		    	for(iCol=0; iCol<iWidth; iCol++)
		    	{
		    	    fprintf(filePointerOut,"%d ",cImage[iRow][iCol]);
  		    	}
  		    	fputc('\n',filePointerOut);
		    }
		    fputc(EOF,filePointerOut);
		}
        fclose(fp);
		fclose(filePointer);
		fclose(filePointerOut);

}
