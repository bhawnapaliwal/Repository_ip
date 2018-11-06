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

		filePointer = fopen("codes/images/mountain.ascii.pgm","r");
		filePointerOut = fopen("codes/images/rotated_mountain.ascii.pgm","w");
		fp=fopen("codes/images/test_image.pgm","w");

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
			printf("1 ");
			fgets (cArray,99, filePointer);
			fputs(cArray,filePointerOut);

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
			printf("2: cImage array made \n");
		    for(iRow=0; iRow<iHeight; iRow++)
		    {
		    	for(iCol=0; iCol<(iWidth/2); iCol++)
		    	{
		    		int temp=cImage[iRow][iCol];
		    		cImage[iRow][iCol]=cImage[iRow][iWidth-iCol-1];
		    		cImage[iRow][iWidth-iCol-1]=temp;
  		    	}
		    }
		    printf("3: Array swapped\n");
		    for(iRow=0;iRow<iHeight;iRow++)
		    {
		    	for(iCol=0;iCol<iWidth;iCol++)
		    	{
		    		cImage1[iCol][iRow]=cImage[iRow][iCol];
		    	}
		    }
		    printf("4: Array Transposed\n");
		    for(iRow=0; iRow<iHeight; iRow++)
		    {
		    	for(iCol=0; iCol<iWidth; iCol++)
		    	{
		    	    fprintf(filePointerOut,"%d ",cImage1[iRow][iCol]);
  		    	}
  		    	fputc('\n',filePointerOut);
		    }
		    fputc(EOF,filePointerOut);
		}
        fclose(fp);
		fclose(filePointer);
		fclose(filePointerOut);

}
