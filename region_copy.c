#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

int* region_copy( const int array[], 
              unsigned int cols, 
              unsigned int rows,
              unsigned int left,
              unsigned int top,
              unsigned int right,
              unsigned int bottom )
{
  unsigned int newCols = right - left;
  unsigned int newRows = bottom - bottom;

  int* newImg;
  newImg = (int *)malloc(newCols*newRows*sizeof(int));


  if(newImg != NULL) {
    if((left!=right) && (top!=bottom)) {

      for(unsigned int i=left; i<right; i++) {
        for(unsigned int j=top; j<bottom; j++) {
          newImg[i-left+(j-top)*newCols] = array[i+j*cols];
        }
      }
    }else {
      return NULL;
    }
  }
  return newImg;

}



// /* TASK 11 */
// int* region_copy( const int array[], 
//               unsigned int cols, 
//               unsigned int rows,
//               unsigned int left,
//               unsigned int top,
//               unsigned int right,
//               unsigned int bottom )
// {
//   unsigned int newCols = right - left;
//   unsigned int newRows = bottom - bottom;

//   int* newImg;
//   newImg = (int *)malloc(newCols*newRows*sizeof(int));


//   if(newImg != NULL) {
//     if((left!=right) && (top!=bottom)) {

//       for(unsigned int i=left; i<right; i++) {
//         for(unsigned int j=top; j<bottom; j++) {
//           newImg[i-left+(j-top)*newCols] = array[i+j*cols];
//         }
//       }
//     }else {
//       return NULL;
//     }
//   }
//   return newImg;

// }

