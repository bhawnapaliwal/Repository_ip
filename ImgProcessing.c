#include<stdio.h>

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
}
