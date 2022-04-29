/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Rim Msalmi>
 * @date <29-04-2022>
 *
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

/* Functions declarations */


void print_statistics(unsigned char* Table, unsigned char size)
{
	printf("The median value in the table is %u \n", find_median(Table, size));
	printf("The minuimum value in the table is %u \n", find_minimum(Table, size));
	printf("The maximum value in the table is %u \n", find_maximum(Table, size));
	printf("The average value in the table is %u \n", find_mean(Table, size));

}

void print_array(unsigned char* Array, unsigned int size)
{
	printf("***************Array Display*************** \n");
	for (int i = 0; i < size; i++)
	{
		printf("Array[%d] = %u \n", i, Array[i]);
	}

}

unsigned char find_median(unsigned char* Table, unsigned int size)
{
	unsigned char median;
	
	if ((size % 2) == 1)
	{
		return Table[size/2];
	}
	else
	{
		return 0,5 * (Table[(size - 1)/2] + Table[size/2]);
	}
	
}

unsigned char find_mean(unsigned char* Table, unsigned int size)
{
	int som = 0;
	
	for (int i = 0; i < size; i++)
	{
		som = som + Table[i];
	}
	
	return som/size;
	
}

unsigned char find_maximum(unsigned char* Table, unsigned int size)
{
	unsigned char max = Table[0];
	for (int i = 0; i < size; i++)
	{
		if(Table[i] > max)
		{
			max = Table[i];
		}
	}
	
	return max;
	
}

unsigned char find_minimum(unsigned char* Table, unsigned int size)
{
	unsigned char min = Table[0];
	for (int i = 0; i < size; i++)
	{
		if(Table[i] < min)
		{
			min = Table[i];
		}
	}
	
	return min;
}

void sort_array(unsigned char* Table, unsigned int size)
{
	int n = 0;
	int j = 0;
	int val = 0;
	int pos;
	while (n < size)
	{
		n = n * 3 + 1;
	}

	while(n!=0)
	{
		n = n/3;
		for (int i = n; i < size; i++)
		{
			val = Table[i];
			j = i;
			while((j > (n-1)) && (Table[j-n]<val))
			{
				Table[j] = Table[j-n];
				j = j-n;  
			}
			Table[j] = val;
			
		}
	}
	
}

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  print_array (test, SIZE);
  sort_array (test, SIZE);
  printf("***************Sorted Array***************\n");
  print_array (test, SIZE);
  print_statistics (test, SIZE);

}

/* Add other Implementation File Code Here */
