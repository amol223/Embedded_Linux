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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

unsigned int Flag_ArraySort = 0;

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  
  /* Statistics and Printing Functions Go Here */
  printf("Unsorted Array: ");
  print_array(test, SIZE);
  printf("\n");
  sort_array(test, SIZE);
  printf("Sorted Array: ");
  print_array(test, SIZE);
  printf("\n");
  printf("Minimum: %u", find_minimum(test, SIZE));
  printf("\n");
  printf("Maximum: %u", find_maximum(test, SIZE)); 
  printf("\n");
  printf("Median: %u", find_median(test, SIZE)); 
  printf("\n");
  printf("Mean: %u", find_mean(test, SIZE));
  printf("\n");
}

/* Add other Implementation File Code Here */

void print_array(unsigned char * arrayPtr, unsigned int lenOfArray)
{
  for(int i = 0; i<lenOfArray; i++)
  {      
    printf("%u ",arrayPtr[i]);
    //arrayPtr++;
  }
}

void sort_array(unsigned char * arrayPtr, unsigned int lenOfArray)
{  
  if(Flag_ArraySort == 0)
  {
    unsigned int temp = 0;   
    for(int j = 0; j < lenOfArray - 1; j++)
    {
      for(int i = 0; i < lenOfArray - 1; i++)
      {
        if(arrayPtr[i+1] > arrayPtr[i])
        {
          temp = arrayPtr[i];
          arrayPtr[i] = arrayPtr[i+1];
          arrayPtr[i+1] = temp;	
        }  
      }
    }
    Flag_ArraySort = 1;
  }  
}

unsigned int find_minimum(unsigned char * arrayPtr, unsigned int lenOfArray)
{
  if(Flag_ArraySort == 0)  sort_array(arrayPtr, lenOfArray);
  return arrayPtr[lenOfArray-1];
}

unsigned int find_maximum(unsigned char * arrayPtr, unsigned int lenOfArray)
{
  if(Flag_ArraySort == 0)  sort_array(arrayPtr, lenOfArray);
  return arrayPtr[0];
}

unsigned int find_median(unsigned char * arrayPtr, unsigned int lenOfArray)
{
  if(Flag_ArraySort == 0)  sort_array(arrayPtr, lenOfArray);
  unsigned int index = 0;
  if(lenOfArray % 2 != 0)
  {
    index = lenOfArray / 2;
    return arrayPtr[index];
  }
  else
  {
    index = lenOfArray / 2;
    return (arrayPtr[index] + arrayPtr[index - 1]) / 2;
  }
}

unsigned int find_mean(unsigned char * arrayPtr, unsigned int lenOfArray)
{
  unsigned int sum = 0;
  for(int i = 0; i < lenOfArray; i++ )
    sum += arrayPtr[i];
  return sum / lenOfArray;
}
