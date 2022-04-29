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
 * @file <stats.h> 
 * @brief <header file>
 *
 * <Add Extended Description Here>
 *
 * @author <Rim Msalmi>
 * @date <29-04-2022>
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Function that prints out the statistics of an array
 *
 * Printing the statistics of an array : minimum, maximum, mean and median
 *
 * @param Array: pointer to the array
 * @param size:  size of the array
 * @return void
 */
void print_statistics(unsigned char* Array, unsigned char size);

/**
 * @brief Function that prints an array to the screen
 *
 * Printing the given array content on the screen
 *
 * @param Array: pointer to the array
 * @param size:  size of the array
 *
 * @return void
 */
void print_array(unsigned char* Array, unsigned int size);

/**
 * @brief Function that returns the median of a table
 *
 * Given an array of data and a length, returns the median value
 *
 * @param Table: pointer to the array
 * @param size:  size of the array
 *
 * @return unsigned char median
 */
unsigned char find_median(unsigned char* Table, unsigned int size);

/**
 * @brief Function that finds the mean value of an array
 *
 * Given an array of data and a length, returns the mean
 *
 * @param Table: pointer to the array
 * @param size:  size of the array
 *
 * @return unsigned char mean
 */
unsigned char find_mean(unsigned char* Table, unsigned int size);

/**
 * @brief Function that finds the maximum value in an array
 *
 *  Given an array of data and a length, returns the maximum
 *
 * @param Table: pointer to the array
 * @param size:  size of the array
 *
 * @return unsigned char maximum
 */
unsigned char find_maximum(unsigned char* Table, unsigned int size);

/**
 * @brief Function that the minimum value in an array
 *
 * Given an array of data and a length, returns the minimum
 *
 * @param Table: pointer to the array
 * @param size:  size of the array
 *
 * @return unsigned char minimum
 */
unsigned char find_minimum(unsigned char* Table, unsigned int size);

/**
 * @brief Function that sorts the values in an array in a decreasing way
 *
 * Given an array of data and a length, sorts the array from largest to smallest.
 * (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value.)
 *
 * @param Table: pointer to the array
 * @param size:  size of the array
 *
 * @return void
 */
void sort_array(unsigned char* Table, unsigned int size);

#endif /* __STATS_H__ */
