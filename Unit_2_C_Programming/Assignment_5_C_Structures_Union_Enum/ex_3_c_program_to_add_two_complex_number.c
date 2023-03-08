/*
 ==================================================================
 Name        : EX3: c_program_to_add_two_complex_number by passing structure to a function
 Author      : Mohamed Belal
 Created on  : 8/3/2023
 Description : Unit 2 C-Programming => Assignment 5 C Structure union Enum => EX 3
 ==================================================================
 */
#include <stdio.h>

struct SComplex {
	float m_Real;
	float m_Imaginary;
};
struct SComplex addTwoCNum(struct SComplex c1 , struct SComplex c2);
int main(void)
{
	struct SComplex c1;
	struct SComplex c2;
	struct SComplex c3;
	// ========================= 1st =========================
	printf("for 1st complex number\n");

	printf("Enter real and imaginary respectively: ");
	fflush(stdout); fflush(stdin);
	scanf("%f %f", &c1.m_Real , &c1.m_Imaginary);

	// ========================= 2nd =========================
	printf("\nfor 2nd complex number\n");

	printf("Enter real and imaginary respectively: ");
	fflush(stdout); fflush(stdin);
	scanf("%f %f", &c2.m_Real , &c2.m_Imaginary);

	// ========================= print sum =========================
	c3 = addTwoCNum(c1,c2);
	printf("\nSum  = %.1f+%.1fi",c3.m_Real, c3.m_Imaginary);
	return 0;
}
struct SComplex addTwoCNum(struct SComplex c1 , struct SComplex c2)
{
	struct SComplex c3;
	c3.m_Real = c1.m_Real + c2.m_Real;
	c3.m_Imaginary = c1.m_Imaginary + c2.m_Imaginary;
	return c3;
}
