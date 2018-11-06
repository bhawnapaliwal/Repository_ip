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
		filePointerOut = fopen("codes/images/rescaled_x31_f18.ascii.ascii.pgm","w");
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
			fprintf(filePointerOut,"%d %d\n", 2*iWidth, 2*iHeight);
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
		    
		   for(iRow=0;iRow<iHeight;iRow++)
		    {
		    	for(iCol=0;iCol<iWidth;iCol++)
		    	{
		    		cImage1[2*iRow][2*iCol]=cImage[iRow][iCol];
		    		cImage1[2*iRow+1][2*iCol+1]=cImage[iRow][iCol];
		    		cImage1[2*iRow][2*iCol+1]=cImage[iRow][iCol];
		    		cImage1[2*iRow+1][2*iCol]=cImage[iRow][iCol];
		    	}
		    }

		    for(iRow=0; iRow<2*iHeight; iRow++)
		    {
		    	for(iCol=0; iCol<2*iWidth; iCol++)
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
