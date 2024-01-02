#include "contact.h"

static int FindByName(const struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
			break;
		}
	}
	return -1;
}

void CheckCapacity(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		PeoInfo *ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr == NULL)
		{
			printf("\nIncrease capacity fail\n\n");
		}
		else
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("\nIncrease capacity success\n\n");
		}
	}
}

void LoadContact(Contact* ps)
{
	PeoInfo tmp = { 0 };
	FILE* pfRead = fopen("contact.dat", "rb");
	if (pfRead == NULL)
	{
		printf("Loaf Contact: %s\n", strerror(errno));
		return;
	}
	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead))
	{
		CheckCapacity(ps);
		ps->data[ps->size] = tmp;
		ps->size++;
	}
	fclose(pfRead);
	pfRead = NULL;
}

void InitContact(struct Contact* ps)
{
	ps->data = (struct PeoInfo*)malloc(3 * sizeof(struct PeoInfo));
	if (ps->data == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
	LoadContact(ps);
}



void AddContact(struct Contact* ps)
{
	CheckCapacity(ps);
	printf("Enter your name:> ");
	scanf("%s", ps->data[ps->size].name);
	printf("Enter your age:> ");
	scanf("%d", &(ps->data[ps->size].age));
	printf("Enter your sex:> ");
	scanf("%s", ps->data[ps->size].sex);
	printf("Enter your telephone:> ");
	scanf("%s", ps->data[ps->size].tele);
	printf("Enter your address:> ");
	scanf("%s", ps->data[ps->size].addr);

	ps->size++;
	printf("\nAdd contact success\n\n");
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("\nEmpty contact\n\n");
	}
	else
	{
		int i = 0;
		printf("\n%-6s\t%-4s\t%-5s\t%-12s\t%-20s\n", "Name", "Age", "Sex", "Telephone", "Address");

		for (i = 0; i < ps->size; i++)
		{
			printf("%-6s\t%-4d\t%-5s\t%-12s\t%-20s\n\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}



void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("Enter the name you want to delete:> ");
	scanf("%s", name);
	int pos = 0;
	
	pos = FindByName(ps,name);

	if (pos == -1)
	{
		printf("\nName do not exist\n\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("\nDelete successful\n\n");
	}
}


void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("Enter the name you want to search:> ");
	scanf("%s", name);

	int pos = 0;
	pos = FindByName(ps, name);

	if (pos == -1)
	{
		printf("\nName do not exist\n\n");
	}
	else
	{
		printf("\n%-6s\t%-4s\t%-5s\t%-12s\t%-20s\n", "Name", "Age", "Sex", "Telephone", "Address");

		
		printf("%-6s\t%-4d\t%-5s\t%-12s\t%-20s\n\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}


void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("Enter the name you want to modify:> ");
	scanf("%s", name);

	int pos = 0;
	pos = FindByName(ps, name);

	if (pos == -1)
	{
		printf("\nName do not exist\n\n");
	}
	else
	{
		printf("Enter your name:> ");
		scanf("%s", ps->data[pos].name);
		printf("Enter your age:> ");
		scanf("%d", &(ps->data[pos].age));
		printf("Enter your sex:> ");
		scanf("%s", ps->data[pos].sex);
		printf("Enter your telephone:> ");
		scanf("%s", ps->data[pos].tele);
		printf("Enter your address:> ");
		scanf("%s", ps->data[pos].addr);

		printf("\nModify successful\n\n");
	}
}

void SortContact(struct Contact* ps)
{

}



void DestroyContact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}


void SaveContact(struct Contact* ps)
{
	FILE* pfWrite = fopen("contact.dat", "wb");
	if (pfWrite == NULL)
	{
		printf("Save Contact: %s\n", strerror(errno));
		return;
	}

	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]), sizeof(PeoInfo), 1, pfWrite);
	}

	fclose(pfWrite);
	pfWrite = NULL;
}