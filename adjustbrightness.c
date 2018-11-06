#include <stdio.h>
#include <stdbool.h>
void main()
{
   char cArray[100];
   int i,j;
   unsigned int cTemp;
   int width,height;
	FILE *fpr=NULL,*fpw=NULL;
	fpr=fopen("codes/images/mountain.ascii.pgm","r");
	fpw=fopen("codes/images/newfile1.pgm","w");
	if(fpr==NULL)
		printf("Cannot open file");
	else
	{
		printf("Enter how many times do you wish your image to be brightened?{Eg: 2,3,10etc.}\n");
		int n;
		scanf("%d",&n);
	  fgets(cArray,99,fpr);
	  fputs(cArray,fpw);

  	  fgets(cArray,99,fpr);
	  fputs("#Created by Bhawna Paliwal\n",fpw);

  	  fscanf(fpr,"%d %d\n",&width,&height);
  	  fprintf(fpw,"%d %d\n",width,height);
  	  for(i=0;i<height;i++)
	  	{
	  	   for(j=0;j<width;j++)
	  		{
	  			//printf("2 ");
	  			fscanf(fpr,"%d ",&cTemp);
	  			cTemp*=n;
	  	         if(cTemp>255)
	  	         	fprintf(fpw,"%d ",255);
	  	         else
	  	    	  fprintf(fpw,"%d ",cTemp);
	  	    }
	  	    //fputc('\n',fpw);

	 }
	 fputc(EOF,fpw);
fclose(fpr);
fclose(fpw);
}
}