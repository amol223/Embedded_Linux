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
 * @file stats.h
 * @brief This file contains all functions needed for assignment 1 in coursera m * odule 1.
 *
 * 
 *
 * @author Amol More
 * @date October 14th, 2017
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Prints an array of given length
 *
 * Prints an array of given length.
 *
 * @param arrayPtr Pointer to an array to be printed
 * @param sizeOfArray Length of array to be printed 
 *
 * @return None
 */
void print_array(unsigned char * arrayPtr, unsigned int lenOfArray);

/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */
void sort_array(unsigned char * arrayPtr, unsigned int lenOfArray);

/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */
unsigned int find_median(unsigned char * arrayPtr, unsigned int lenOfArray);
unsigned int find_mean(unsigned char * arrayPtr, unsigned int lenOfArray);
unsigned int find_minimum(unsigned char * arrayPtr, unsigned int lenOfArray);
unsigned int find_maximum(unsigned char * arrayPtr, unsigned int lenOfArray);
void print_statistics(void);

#endif /* __STATS_H__ */
