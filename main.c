#include "contact.h"

void menu()
{
	printf("*****************************************\n");
	printf("*******    1.Add       2.Del      *******\n");
	printf("*******    3.Search    4.Modify   *******\n");
	printf("*******    5.Show      6.Sort     *******\n");
	printf("*******    7.Save      0.Exit     *******\n");
	printf("*****************************************\n");
}


int main()
{
	int input = 0;
	struct Contact con;
	InitContact(&con); 

	do 
	{
		menu();
		printf("Choose:> ");
		scanf("%d", &input);

		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			//in progress
			SortContact(&con);
			break;
		case EXIT:
			SaveContact(&con);
			DestroyContact(&con);
			printf("\nExit sucessfully\n\n");
			break;
		case Save:
			SaveContact(&con);
			break;
		default:
			printf("\nWrong input\n\n");
			break;
		}
	}while (input);
}