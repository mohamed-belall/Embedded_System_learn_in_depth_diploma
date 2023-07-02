
/**
 *****************************************************************************
 * @project        : linkedlist student database
 * @file           : main.c
 * @author         : mohamed belal
 * @Created on     : Jun 25, 2023
 ******************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define DPRINTF(...)	{fflush(stdout);	 \
						fflush(stdin); 		 \
						printf(__VA_ARGS__); \
						fflush(stdout); 	 \
						fflush(stdin); }


typedef struct{
	int ID;
	char name[40];
	float height;
}Sdata;

struct SStudent{
	Sdata Student;
	struct SStudent* PNextStudent;
};

struct SStudent* gpFirstStudent = NULL;


void add_student()
{
	struct SStudent* pLastStudent;
	struct SStudent* pNewStudent;

	/* ============ create a new record ============ */
	pNewStudent = (struct SStudent*)malloc(sizeof(struct SStudent));


	if(gpFirstStudent ==NULL) /* ===== database is empty ================ */
	{

		/* ======== assign gpfirstStudent to it ==== */
		gpFirstStudent = pNewStudent;

	}else                     /* ===== if the list contain a record ===== */
	{
		pLastStudent = gpFirstStudent;

		while(pLastStudent->PNextStudent != NULL)
			pLastStudent = pLastStudent->PNextStudent;

		pLastStudent->PNextStudent = pNewStudent;
	}

	/* ============== fill the record ============== */
	char temp_text[40];
	DPRINTF("\n ================================================");
	DPRINTF("\n Enter the ID : ");
	gets(temp_text);
	pNewStudent->Student.ID = atoi(temp_text);

	DPRINTF("\n Enter the student name : ");
	gets(pNewStudent->Student.name);

	DPRINTF("\n Enter the student height : ");
	gets(temp_text);
	DPRINTF("\n ================================================");
	pNewStudent->Student.height = atof(temp_text);

	/* ======= set the next record to null ======== */
	pNewStudent->PNextStudent = NULL;

}

int delete_student()
{
	char entered_ID[40];
	int selected_ID ;

	/* ======= get selected record ID from user ======== */
	DPRINTF("\n enter ID of the student that you want to delete : ");
	gets(entered_ID);
	selected_ID = atoi(entered_ID);

	struct SStudent* pPreviousStudent = NULL;
	struct SStudent* pSelectedStudent = gpFirstStudent;


	if(gpFirstStudent) /* ===== list have a record ================ */
	{

		/* ======= loop on all record starting from gpFirstStudent ======== */
		while(pSelectedStudent)
		{
			/* ================ compare the entered ID with the recorded ID ================ */
			if(selected_ID==pSelectedStudent->Student.ID)
			{
				/* ================ there are 3 case ================ */
				if(!pPreviousStudent) /* ======= 1- selected ID is the first  ID ======= */
				{
					gpFirstStudent = pSelectedStudent->PNextStudent;
				}
				else			      /* ======= 2&3- selected ID in the middle | lasts ID ======= */
				{
					pPreviousStudent->PNextStudent = pSelectedStudent->PNextStudent;
				}
				DPRINTF("\n ================================================");
				DPRINTF("\n ID number (%d) deleted successfully " , selected_ID);
				DPRINTF("\n ================================================");
				free(pSelectedStudent);
				return 1; // find it
			}
			/* ======= traverse pointer ======== */
			pPreviousStudent = pSelectedStudent;
			pSelectedStudent = pSelectedStudent->PNextStudent;
		}
	}
	DPRINTF("\n ================================================");
	DPRINTF("\n can't find student ID. ");
	DPRINTF("\n ================================================");
	return 0; // can't find it
}


void delete_all()
{
	struct SStudent* pSelectedStudent = gpFirstStudent;
	if(gpFirstStudent==NULL)
		DPRINTF("\n Empty list");

	while(pSelectedStudent)
	{
		struct SStudent* pTempStudent = pSelectedStudent;
		pSelectedStudent = pSelectedStudent->PNextStudent;
		free(pTempStudent);
	}
	gpFirstStudent = NULL;
}
void display_database()
{
	int counter =0;
	struct SStudent* pSelectedStudent = gpFirstStudent;

	if(gpFirstStudent==NULL)
		DPRINTF("\n Empty list");

	while(pSelectedStudent)
	{
		DPRINTF("\n ================================================");
		DPRINTF("\n Record Number : %d" , counter+1);
		DPRINTF("\n\t ID : %d" , pSelectedStudent->Student.ID);
		DPRINTF("\n\t Name : %s" , pSelectedStudent->Student.name);
		DPRINTF("\n\t Height : %f" , pSelectedStudent->Student.height);
		DPRINTF("\n ================================================");
		pSelectedStudent = pSelectedStudent->PNextStudent;
		counter++;
	}

}


/* ================ linkedList interview tricks ================ */
void get_index_of_student()
{
	struct SStudent* pCurrentStudent = gpFirstStudent;
	int count =0 , index;

	DPRINTF("\n ================================================");
	/* ======= get selected record ID from user ======== */
		DPRINTF("\n enter index : ");
		scanf("%d" , &index);

	while(count != index)
	{
		pCurrentStudent = pCurrentStudent->PNextStudent;
		count++;
	}


	DPRINTF("\n student at index %d is :" , index);
	DPRINTF("\n\t ID : %d" , pCurrentStudent->Student.ID);
	DPRINTF("\n\t Name : %s" , pCurrentStudent->Student.name);
	DPRINTF("\n\t Height : %f" , pCurrentStudent->Student.height);
	DPRINTF("\n ================================================");

}

void length_of_linkedList()  // iterative or recursive
{
	struct SStudent* pCurrentStudent = gpFirstStudent;
	int length=0;
	while(pCurrentStudent != NULL)
	{
		pCurrentStudent = pCurrentStudent->PNextStudent;
		length++;
	}
	DPRINTF("\n ================================================");
	DPRINTF("\n length of the linkedList is :%d" , length );
	DPRINTF("\n ================================================");

}

void find_Nth_index_form_the_end()
{
	int n , count=0;
	struct SStudent* mainPtr = gpFirstStudent;
	struct SStudent* refPtr = gpFirstStudent;

	DPRINTF("\n ================================================");
	/* ======= get selected record ID from user ======== */
		DPRINTF("\n enter n'th node from the end : ");
		scanf("%d" , &n);

	while(count<n)
	{
		count++;
		refPtr = refPtr->PNextStudent;
	}

	while(refPtr != NULL)
	{
		refPtr = refPtr->PNextStudent;
		mainPtr = mainPtr->PNextStudent;
	}
	DPRINTF("\n %d'th node from the end is :" , n);
	DPRINTF("\n\t ID : %d" , mainPtr->Student.ID);
	DPRINTF("\n\t Name : %s" , mainPtr->Student.name);
	DPRINTF("\n\t Height : %f" , mainPtr->Student.height);
	DPRINTF("\n ================================================");
}

void find_the_Middle_of_linkedList()
{
	int count=1;
	struct SStudent* slowPtr = gpFirstStudent;
	struct SStudent* fastPtr = gpFirstStudent;


	while((fastPtr != NULL) && (fastPtr->PNextStudent != NULL))
	{
		fastPtr = fastPtr->PNextStudent;
		fastPtr = fastPtr->PNextStudent;

		slowPtr = slowPtr->PNextStudent;
		count++;
	}

	DPRINTF("\n ================================================");
	DPRINTF("\n the middle of the linkedList is : %d " , count);
	DPRINTF("\n\t ID : %d" , slowPtr->Student.ID);
	DPRINTF("\n\t Name : %s" , slowPtr->Student.name);
	DPRINTF("\n\t Height : %f" , slowPtr->Student.height);
	DPRINTF("\n ================================================");

}

void detect_loop_of_the_LinkedList()
{
		struct SStudent* slowPtr = gpFirstStudent;
		struct SStudent* fastPtr = gpFirstStudent;


		while((fastPtr != NULL)&& (slowPtr != NULL)&&(fastPtr->PNextStudent != NULL))
		{
			fastPtr = fastPtr->PNextStudent;
			fastPtr = fastPtr->PNextStudent;

			slowPtr = slowPtr->PNextStudent;

		}

		if(slowPtr == fastPtr)
		{
			DPRINTF("\n ================================================");
			DPRINTF("\n Found Loop");
			DPRINTF("\n ================================================");
		}else
		{
			DPRINTF("\n ================================================");
			DPRINTF("\n Loop not Found");
			DPRINTF("\n ================================================");
		}
}

void reverse_LinkedList()
{
	struct SStudent* prevPtr = NULL;
	struct SStudent* currentPtr = gpFirstStudent;
	struct SStudent* nextPtr = NULL;

	while(currentPtr != NULL)
	{
		nextPtr = currentPtr->PNextStudent;
		currentPtr->PNextStudent = prevPtr;
		prevPtr = currentPtr;
		currentPtr = nextPtr;
	}
	gpFirstStudent = prevPtr;
}


int main()
{
	DPRINTF("\n ================================================ \n");
	DPRINTF(" ========= Welcome To My Student Database ========");
	DPRINTF("\n ================================================ \n");
	char temp[40];


	while(1)
	{
		DPRINTF("\n\n\n##################################################### \n");
		DPRINTF("######## choose one of the following Options ########");
		DPRINTF("\n##################################################### \n");
		DPRINTF("\n 1: Add Student.");
		DPRINTF("\n 2: delete Student.");
		DPRINTF("\n 3: view Students.");
		DPRINTF("\n 4: delete All.");
		DPRINTF("\n 5: get_index_of_student.");
		DPRINTF("\n 6: length_of_linkedList.");
		DPRINTF("\n 7: find_Nth_index_form_the_end.");
		DPRINTF("\n 8: find_the_Middle_of_linkedList.");
		DPRINTF("\n 9: reverse_LinkedList.");
		DPRINTF("\n Enter Option Number: ");
		gets(temp);
		DPRINTF("\n#####################################################");
		DPRINTF("\n##################################################### \n\n\n");



		switch(atoi(temp))
		{
		case 1:
			add_student();
			break;
		case 2:
			delete_student();
			break;
		case 3:
			display_database();
			break;
		case 4:
			delete_all();
			break;
		case 5:
			get_index_of_student();
			break;
		case 6:
			length_of_linkedList();
			break;
		case 7:
			find_Nth_index_form_the_end();
			break;
		case 8:
			find_the_Middle_of_linkedList();
			break;
		case 9:
			reverse_LinkedList();
			break;
		default:
			DPRINTF("\n wrong option ");
			break;
		}
	}

	return 0;
}
