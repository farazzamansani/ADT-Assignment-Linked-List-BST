
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "bst.h"
#include "list.h"


main()
{
	long taxynumby = 1;	
	List taxlist = create_list();
	BST tree = create_bst();

	FILE *filePtr;
	filePtr = fopen("welfare.txt", "r");
	int num_records = 0;
	fscanf(filePtr, "%d", &num_records);
	int i = 0;
	char *name;
	long taxy = 0;
	int yearcount = 0;
	int j = 0;
	long years = 0;
	while (i < num_records)
	{
		TaxRecordPtr new_rec = malloc(sizeof *new_rec);
		List welfarelistyears = create_list();
		List taxlistyears = create_list();
		fscanf(filePtr, "%s", &name);
		char* newstr = (char*)malloc(strlen(&name) + 1);;
		strcpy(newstr, &name);
		new_rec->name = newstr;
		
		fscanf(filePtr, "%ld", &taxy);
		new_rec->tfn = taxy;
		int inserty = taxy;

		fscanf(filePtr, "%d", &yearcount);
		while (j < yearcount)
		{
			fscanf(filePtr, "%ld", &years);
			insert_at_front(&welfarelistyears, years);
			j++;
		}
		j = 0;
		
		FILE *filePtr;
		filePtr = fopen("tax.txt", "r");
		int num_records2 = 0;
		fscanf(filePtr, "%d", &num_records2);
		long taxy2 = 0;
		int p = 0;
		while (p < num_records2)
		{
			fscanf(filePtr, "%ld", &taxy2);
			if (taxy2 == taxy)
			{
				fscanf(filePtr, "%d", &yearcount);
				while (j < yearcount)
				{
					fscanf(filePtr, "%ld", &years);
					insert_at_front(&taxlistyears, years);
					j++;
				}
			}
			else
			{
				fscanf(filePtr, "%d", &yearcount);
				while (j < yearcount)
				{
					fscanf(filePtr, "%ld", &years);

					j++;
				}
				j = 0;
			}
			p++;
		}

		new_rec->welfare = welfarelistyears;
		new_rec->tax = taxlistyears;
		insert_bst(&tree, new_rec);
		i++;
	}

	
	while (taxynumby != 0)
	{
		long input = 1;
		printf("Please input a Tax Number \n");
		scanf("%ld", &input);
		printf("you entered %ld \n",input);
	
		if (input == 0)
		{
			taxynumby = 0;
		}
		else
		{
			if (find_bst(&tree, input) == NULL)
				printf("No Entry for Tax Number %ld exists \n", input);
			else {
				long namey = find_bst(&tree, input)->data->tfn;
				char *namey2 = find_bst(&tree, input)->data->name;
				
				printf("Name: %s \n", namey2);
				printf("TFN: %ld \n", namey);

				List newy=merge_lists((&find_bst(&tree, input)->data->welfare), (&find_bst(&tree, input)->data->tax));
				printf("Years %s has both received Welfare and Lodged Tax Return \n", namey2);
				print_list(&newy);
			}
			
		}

	}
	exit(0);
		
}



