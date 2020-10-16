#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

// Set every pixel to 0 (black) 
void zero( int array[], unsigned int cols, unsigned int rows )
{
  memset( array, 0, cols*rows*sizeof(int));
  // your code here.
}