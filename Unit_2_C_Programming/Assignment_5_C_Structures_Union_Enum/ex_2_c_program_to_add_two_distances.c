/*
 ==================================================================
 Name        : EX2: c_program_to_add_two_distances (in inch - feet) ststem using structure
 Author      : Mohamed Belal
 Created on  : 8/3/2023
 Description : Unit 2 C-Programming => Assignment 5 C Structure union Enum => EX 2
 ==================================================================
 */
#include <stdio.h>

struct SDistances {
	int m_Feet;
	float m_Inch;
};

int main(void)
{
	struct SDistances distance_1;
	struct SDistances distance_2;
	struct SDistances totalSum;
	// ========================= 1st =========================
	printf("Enter information for 1st distance: \n");

	printf("Enter feet: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &distance_1.m_Feet);

	printf("Enter inch: ");
	fflush(stdout); fflush(stdin);
	scanf("%f", &distance_1.m_Inch);
	// ========================= 2nd =========================
	printf("\nEnter information for 2nd distance: \n");

	printf("Enter feet: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &distance_2.m_Feet);

	printf("Enter inch: ");
	fflush(stdout); fflush(stdin);
	scanf("%f", &distance_2.m_Inch);
	// ========================= calculating sum =========================
	totalSum.m_Feet = distance_1.m_Feet + distance_2.m_Feet;
	totalSum.m_Inch = distance_1.m_Inch + distance_2.m_Inch;

	while(totalSum.m_Inch >= 12.0)
	{
		totalSum.m_Feet++;
		totalSum.m_Inch = totalSum.m_Inch - 12.0;
	}
	printf("\nSum of distances = %d\'-%.1f\"",totalSum.m_Feet, totalSum.m_Inch);
	return 0;
}

