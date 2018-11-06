#include<stdio.h>
#define MaxWidth 1000
#define MaxHeight 1000
void Flip()
{
	char cArray[100];
		int iWidth, iHeight, iRow, iCol;
		unsigned int cTemp;
		unsigned char cImage [MaxWidth][MaxHeight];
		FILE *filePointer = NULL,  *filePointerOut = NULL,*fp=NULL;

		filePointer = fopen("codes/images/mountain.ascii.pgm","r");
		filePointerOut = fopen("codes/images/mountain.ascii.pgm","w");
		fp=fopen("codes/images/test_image.pgm","w");

		if (filePointer == NULL)
		{
			printf("cannot open file");

		}else
		{  
			fgets (cArray, 99, filePointer);
			fputs(cArray, filePointerOut);
			//printf("%s\n", cArray);

			fgets (cArray, 99, filePointer);
			fputs(cArray, filePointerOut);
			//printf("%s\n", cArray);

			fscanf(filePointer,"%d %d\n", &iWidth, &iHeight);
			fprintf(filePointerOut,"%d %d\n", iWidth, iHeight);
			//printf("%d %d \n", iWidth, iHeight);
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
		    	for(iCol=0; iCol<iWidth; iCol++)
		    	{
		    	    fprintf(fp,"%d ",cImage[iRow][iCol]);
  		    	}
  		    	fputc('\n',fp);
		    }
		    fputc(EOF,fp);
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
		    for(iRow=0; iRow<iHeight; iRow++)
		    {
		    	for(iCol=0; iCol<iWidth; iCol++)
		    	{
		    	    fprintf(filePointerOut,"%d ",cImage[iRow][iCol]);
  		    	}
  		    	fputc('\n',filePointerOut);
		    }
		    fputc(EOF,filePointerOut);
		   /*for(iRow=0; iRow<iHeight; iRow++)
		    {
		    	for(iCol=0; iCol<iWidth; iCol++)
		    	{ printf("4 ");
		    		fprintf(filePointerOut,"%d ",cImage[iRow][iWidth]);
		    	}
		    	fputc('\n',filePointerOut);
		    	printf("5 ");
		    }
		    fputc(EOF,filePointerOut);*/
		}
        fclose(fp);
		fclose(filePointer);
		fclose(filePointerOut);

	return ;
}
void Rotate()
{

		char cArray[100];
		int iWidth, iHeight, iRow, iCol;
		unsigned int cTemp;
		unsigned char cImage [MaxWidth][MaxHeight];
		unsigned char cImage1 [MaxWidth][MaxHeight];
		FILE *filePointer = NULL,  *filePointerOut = NULL,*fp=NULL;

		filePointer = fopen("codes/images/mountain.ascii.pgm","r");
		filePointerOut = fopen("codes/images/rotatedclock_mountain.ascii.pgm","w");
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
		    
		    for(iRow=0;iRow<iHeight;iRow++)
		    {
		    	for(iCol=0;iCol<iWidth;iCol++)
		    	{
		    		cImage1[iCol][iRow]=cImage[iRow][iCol];
		    	}
		    }
		    printf("3: Array Transposed\n");
		    for(iRow=0; iRow<iHeight; iRow++)
		    {
		    	for(iCol=0; iCol<(iWidth/2); iCol++)
		    	{
		    		int temp=cImage[iRow][iCol];
		    		cImage[iRow][iCol]=cImage[iRow][iWidth-iCol-1];
		    		cImage[iRow][iWidth-iCol-1]=temp;
  		    	}
		    }
		    printf("4: Array swapped\n");
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
return;
}


void ColorInvert()
{
	return ;
}
void Rescaling()
{
	return ;
}
void Border()
{
	return ;
}
void Collage()
{
	return ;
}
void Bright()
{
	return ;
}
void Morphing()
{
	return ;
}
void Stegnography()
{
	return ;
}

void main()
{
	int iChoice;
	printf("\n*** Welcome To Basic Image Processing Program ***\n\n");
	printf(" 1) Flipping\n");
	printf(" 2) Rotating\n");
	printf(" 3) Colour inverting\n");
	printf(" 4) Change Brightness\n");
	printf(" 5) Rescaling\n");
	printf(" 6) Adding Border\n");
	printf(" 7) Make Collage\n");
	printf(" 8) Image Morphing\n");
	printf(" 9) stegnography\n");
	printf("\nSelect your choice\n");
	scanf("%d",&iChoice);
	switch(iChoice)
	{
		case 1 : Flip();
		         break;
		case 2 : Rotate();
		         break;
		case 3 : ColorInvert();
		         break;
		case 4 : Bright();
		         break;
		case 5 : Rescaling();
		         break;
		case 6 : Border();
		         break;
		case 7 : Collage();
		         break;
		case 8 : Morphing();
		         break;
		case 9 : Stegnography();
		         break;
		default : printf("You have entered wrong choice.\n");
		          break;
	}
return;
}