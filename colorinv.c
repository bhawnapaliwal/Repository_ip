#include <stdio.h>
void main()
{
	char cArray[100];
	int height,width;
	unsigned int cTemp;
	FILE *fpr=NULL,*fpw=NULL;
	int i,j;
	fpr=fopen("codes/images/mountain.ascii.pgm","r");
	fpw=fopen("codes/images/newfile2.pgm","w");
	if(fpr==NULL)
	{
		printf("Cannot open file\n");
	}
else
	{
	  fgets(cArray,99,fpr);
	  fputs(cArray,fpw);

  	  fgets(cArray,99,fpr);
	  fputs("#Created by Bhawna Paliwal\n",fpw);

  	  fscanf(fpr,"%d %d\n",&width,&height);
  	  fprintf(fpw,"%d %d\n",width,height);
  	  fgets(cArray,99,fpr);
  	  fputs(cArray,fpw);
  	  for(i=0;i<height;i++)
	  	{
	  	   for(j=0;j<width;j++)
	  		{
	  			//printf("2 ");
	  			fscanf(fpr,"%d ",&cTemp);
	  			//cTemp*=1.5;
	  	         if(cTemp>255)
	  	         	fprintf(fpw,"%d ",255);
	  	         else
	  	    	  fprintf(fpw,"%d ",(255-cTemp));
	  	    }
	  	    //fputc('\n',fpw);

	 }
	 fputc(EOF,fpw);
fclose(fpr);
fclose(fpw);
}
}