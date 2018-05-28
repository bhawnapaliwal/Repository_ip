#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Following statements are for stegnography program
bool msg_bin[480]={0};
bool temp[8];
char sec_msg[60];


void dec_to_bin(int n)
{
 int index=7,i;
 for(i=0;i<7;i++)
      temp[i]=0; 
 while(n)
 {
      temp[index--]=n%2;
      n/=2;
 }
}

void inp_msg()
{
      printf("Please type your secret message :\n");
      printf("*****************************************************\n");
      printf("Please do not include any blank spaces but however you can use\nboth upper and lower case letters and any other special character \nlike underscore,full stop,comma etc :\n");
      printf("*****************************************************\n");
      scanf("%s",sec_msg);
}

void encode_msg()
{
      int i,k=0,t;

      for(i=0;sec_msg[i]!='\0';i++)
      {
            dec_to_bin(sec_msg[i]);
            for(t=0;t<8;t++)
                  msg_bin[k++]=temp[t];
      }
}

void decode_msg()
{
      int t=0,k,i;
      for(i=0;i<480;i+=8)
      {
            k=(msg_bin[i]*128+msg_bin[i+1]*64+msg_bin[i+2]*32+msg_bin[i+3]*16+msg_bin[i+4]*8+msg_bin[i+5]*4+msg_bin[i+6]*2+msg_bin[i+7]);
            if(k)
                sec_msg[t++]=k;
            else{
                  sec_msg[t]='\0';
                  break;
            }

      }
}

//all above functions are for stegnography

void Flip()
{
	return ;
}
void Rotate()
{
	return ;
}
void ColorInvert()
{
	return ;
}
void Rescaling()
{
	int choice;

	char cArray[100],ch;
	int iHeight,iWidth,iRow,iCol,r,c;
	char cPathInput[100],cPathOutput[100];
	FILE *filepointer = NULL, *filepointerout = NULL;

	printf("\n 1) Scale up\n 2) Scale down\nEnter your choice :\n");
	scanf("%d",&choice);

	if(choice==2)
	{
      printf("Enter File Path (eg B:\\Image\\img1.pgm) : \n");
      scanf("%s",cPathInput);
      filepointer=fopen(cPathInput,"r");
	  if(filepointer==NULL)
	     printf("Cannot open file");
	  else
	  {
      
       printf("Enter Output File Path along with outputfile name (eg B:\\Image\\img1Output.pgm) : \n");
       scanf("%s",cPathOutput);
       filepointerout=fopen(cPathOutput,"w");

       fgets(cArray,99,filepointer);
       fputs(cArray,filepointerout);
  
       fgets(cArray,99,filepointer);
       fputs(cArray,filepointerout);

       fscanf(filepointer,"%d %d\n",&iWidth,&iHeight);
       fprintf(filepointerout,"%d %d\n",iWidth/2,iHeight/2);
       unsigned char rImage[iHeight][iWidth],wImage[iHeight/2][iWidth/2];
      
       fgets(cArray,99,filepointer);
       fputs(cArray,filepointerout);
      
       for(iRow=0;iRow<iHeight;iRow++)
       {
       	for(iCol=0;iCol<iWidth;iCol++)
      	{
      		fscanf(filepointer,"%d ",&ch);
      		  if(c!=EOF)
      		 	rImage[iRow][iCol]=ch;
      	}
      }

      r=0;
       for(iRow=0;iRow<iHeight-1;iRow+=2)
       {
      	c=0;
      	for(iCol=0;iCol<iWidth-1;iCol+=2)
      	{
      		wImage[r][c]=(rImage[iRow][iCol]+rImage[iRow][iCol+1]
      			          +rImage[iRow+1][iCol]+rImage[iRow+1][iCol+1])/4;
      		c++;
      	}
      	r++;
      }

      for(iRow=0;iRow<iHeight;iRow++)
      {
      	for(iCol=0;iCol<iWidth/2;iCol++)
      	{
      		fprintf(filepointerout,"%d ",wImage[iRow][iCol]);      		
      	}
      	fputc('\n',filepointerout);
      }
      printf("New Image created succesfully !\n");
      fclose(filepointerout);
      fclose(filepointer);
	}
	}
	else if(choice == 2){
		return;
	}

	else{
		printf("Wrong choice\n");
	}
   return ;
}

void Border()
{
	return ;
}

void Collage()
{
	char cArray[100],ch;
	int iHeight,iWidth,iRow,iCol,r,c;
	char cPathInput1[100],cPathInput2[100],cPathInput3[100],cPathInput4[100],cPathOutput[100];
	FILE *fout = NULL, *fin1 = NULL,*fin2 = NULL,*fin3 = NULL,*fin4 = NULL;	

	printf("Enter File 1 Path (eg B:\\Image\\img1.pgm) : \n");
    scanf("%s",cPathInput1);
    printf("Enter File 2 Path (eg B:\\Image\\img1.pgm) : \n");
    scanf("%s",cPathInput2);
    printf("Enter File 3 Path (eg B:\\Image\\img1.pgm) : \n");
    scanf("%s",cPathInput3);
    printf("Enter File 4 Path (eg B:\\Image\\img1.pgm) : \n");
    scanf("%s",cPathInput4);
    
    fin1=fopen(cPathInput1,"r");
    fin2=fopen(cPathInput2,"r");
    fin3=fopen(cPathInput3,"r");
    fin4=fopen(cPathInput4,"r");

    if(fin1==NULL||fin2==NULL||fin3==NULL||fin4==NULL)
	 printf("Cannot open file");
	else
	{
      printf("Enter Output File Path along with outputfile name (eg B:\\Image\\img1Output.pgm) : \n");
      scanf("%s",cPathOutput);
      fout=fopen(cPathOutput,"w");

      fgets(cArray,99,fin1);
      fgets(cArray,99,fin1);
      fscanf(fin1,"%d %d\n",&iWidth,&iHeight);
      fgets(cArray,99,fin1);

      fgets(cArray,99,fin2);
      fgets(cArray,99,fin2);
      fgets(cArray,99,fin2);
      fgets(cArray,99,fin2);

      fgets(cArray,99,fin3);
      fgets(cArray,99,fin3);
      fgets(cArray,99,fin3);
      fgets(cArray,99,fin3);

      fgets(cArray,99,fin4);
      fgets(cArray,99,fin4);
      fgets(cArray,99,fin4);
      fgets(cArray,99,fin4);

      fputs("P2\n",fout);
      fputs("#Created by Harshit\n",fout);
      fprintf(fout,"%d %d\n",iWidth+12,iHeight+12);
      fputs("255\n",fout);

      unsigned char rImage1[iHeight][iWidth],rImage2[iHeight][iWidth],rImage3[iHeight][iWidth],rImage4[iHeight][iWidth];
      unsigned char wImage1[iHeight/2][iWidth/2],wImage2[iHeight/2][iWidth/2],wImage3[iHeight/2][iWidth/2],wImage4[iHeight/2][iWidth/2];
      unsigned char wImage[iHeight+12][iWidth+12];

      for(iRow=0;iRow<iHeight;iRow++)
      {
      	for(iCol=0;iCol<iWidth;iCol++)
      	{
      		fscanf(fin1,"%d ",&ch);
      		  if(ch!=EOF)
      		 	rImage1[iRow][iCol]=ch;
                   fscanf(fin2,"%d ",&ch);
                    if(ch!=EOF)
                        rImage2[iRow][iCol]=ch;
                  fscanf(fin3,"%d ",&ch);
                    if(ch!=EOF)
                        rImage3[iRow][iCol]=ch;
                  fscanf(fin4,"%d ",&ch);
                    if(ch!=EOF)
                        rImage4[iRow][iCol]=ch;
      	}
      }

     r=0;
      for(iRow=0;iRow<iHeight-1;iRow+=2)
      {
      	c=0;
      	for(iCol=0;iCol<iWidth-1;iCol+=2)
      	{
      		wImage1[r][c]=(rImage1[iRow][iCol]+rImage1[iRow][iCol+1]+rImage1[iRow+1][iCol]+rImage1[iRow+1][iCol+1])/4;
                  wImage2[r][c]=(rImage2[iRow][iCol]+rImage2[iRow][iCol+1]+rImage2[iRow+1][iCol]+rImage2[iRow+1][iCol+1])/4;
                  wImage3[r][c]=(rImage3[iRow][iCol]+rImage3[iRow][iCol+1]+rImage3[iRow+1][iCol]+rImage3[iRow+1][iCol+1])/4;
                  wImage4[r][c]=(rImage4[iRow][iCol]+rImage4[iRow][iCol+1]+rImage4[iRow+1][iCol]+rImage4[iRow+1][iCol+1])/4;
      		c++;
      	}
      	r++;
      }
      
       for(iRow=0;iRow<iHeight+12;iRow++)
      {
            for(iCol=0;iCol<iWidth+12;iCol++)    
              wImage[iRow][iCol]=0;
      }

       for(iRow=4;iRow<(iHeight/2+4);iRow++)
      {
            for(iCol=4;iCol<(iWidth/2+4);iCol++)
            {
              wImage[iRow][iCol]=wImage1[iRow-4][iCol-4];
              wImage[iRow+iHeight/2+4][iCol]=wImage2[iRow-4][iCol-4];
              wImage[iRow][iCol+iWidth/2+4]=wImage3[iRow-4][iCol-4];
              wImage[iRow+iHeight/2+4][iCol+iWidth/2+4]=wImage4[iRow-4][iCol-4];
            }
      }
             
      
      for(iRow=0;iRow<iHeight+12;iRow++)
      {
      	for(iCol=0;iCol<iWidth+12;iCol++)
      	{
      		fprintf(fout,"%d ",wImage[iRow][iCol]);      		
      	}
      	fputc('\n',fout);
      }
      printf("collage created succesfully !\n");
      fclose(fin1);
      fclose(fin2);
      fclose(fin3);
      fclose(fin4);
      fclose(fout);
	}
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
	int i,choice;
    char cArray[100],ch;
    char cPathInput[100],cPathOutput[100];
    unsigned char cImage[480][640],cImage2[480][640];
    int iHeight,iWidth,iRow,iCol;
    FILE *filepointer = NULL, *filepointerout = NULL;
    
    printf("\n******* Steganography *******");
    printf("\n Enter your choice : \n");
    printf("1) Encode Message into image\n2) Decode Message from image\n");
    scanf("%d",&choice);
     if(choice==1)
      {

        printf("Enter Input file name (eg B:\\Image\\img.pgm) : \n");
        scanf("%s",cPathInput);
        filepointer=fopen(cPathInput,"r");
        
        if(filepointer==NULL)
          printf("Cannot open file");
        else
        {
          printf("Enter Output File Path along with outputfile name (eg B:\\Image\\img1Output.pgm) : \n");
          scanf("%s",cPathOutput);
     
          filepointerout=fopen(cPathOutput,"w"); 
          fgets(cArray,99,filepointer);
          fputs(cArray,filepointerout);
  
          fgets(cArray,99,filepointer);
          fputs(cArray,filepointerout);

          fscanf(filepointer,"%d %d\n",&iWidth,&iHeight);
          fprintf(filepointerout,"%d %d\n",iWidth,iHeight);
      
          fgets(cArray,99,filepointer);
          fputs(cArray,filepointerout);
      
          for(iRow=0;iRow<iHeight;iRow++)
          {
            for(iCol=0;iCol<iWidth;iCol++)
            {
                  fscanf(filepointer,"%d ",&ch);
                    if(ch!=EOF)
                        cImage[iRow][iCol]=ch;
            }
           }
           inp_msg();
           encode_msg();
          for(iRow=0;iRow<iHeight;iRow++)
          {     
            if(msg_bin[iRow]==0)
              cImage[iRow][0]=(cImage[iRow][0]&(0xfe));
            else
               cImage[iRow][0]=(cImage[iRow][0]|0x01);  
           }
          for(iRow=0;iRow<iHeight;iRow++)
           {
             for(iCol=0;iCol<iWidth;iCol++)
                  fprintf(filepointerout,"%d ",cImage[iRow][iCol]);                 
             fputc('\n',filepointerout);
           }
        printf("Secret message encoded into image succesfully !\n");
        fclose(filepointerout);
        fclose(filepointer);
       }
      }
      else if(choice==2)
      {
        printf("Enter Input file name (eg B:\\Image\\img.pgm) : \n");
        scanf("%s",cPathInput);
        filepointer=fopen(cPathInput,"r");

        if(filepointer==NULL)
          printf("Cannot open file");
        else
        {

         fgets(cArray,99,filepointer);
         fgets(cArray,99,filepointer);
         fscanf(filepointer,"%d %d\n",&iWidth,&iHeight);      
         fgets(cArray,99,filepointer);
      
        for(iRow=0;iRow<iHeight;iRow++)
        {
           for(iCol=0;iCol<iWidth;iCol++)
            {
                  fscanf(filepointer,"%d ",&ch);
                    if(ch!=EOF)
                        cImage[iRow][iCol]=ch;
            }
        }

        for(iRow=0;iRow<iHeight;iRow++)
        {     
              msg_bin[iRow]=(cImage[iRow][0]&0x01)  ; 
        }
      decode_msg();
      printf("Message decoded succesfully !\n");
      printf("\nDecode message : \n%s\n",sec_msg);
      fclose(filepointer);
      }
      }
      else
            printf("Wrong Choice");

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
}
