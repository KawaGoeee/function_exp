#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

int* half( const int array[], unsigned int cols, unsigned int rows ) {
  //allocate enough memory size for the new image array called newImg
  unsigned int c = cols%2==0 ? cols/2 : (cols-1)/2;
  unsigned int r = rows%2==0 ? rows/2 : (rows-1)/2;
  int* newImg;
  newImg = (int *)malloc(c*r*sizeof(int));


  if(newImg != NULL) {
    //clear the new image array by calling the zero function
    zero(newImg, c, r);


    for(int y=0; y<r; y++) {
      for(int x=0; x<c; x++) {
        // printf("%d ", newImg[x+y*c]);
        // printf("%d ", x+y*c);
        // printf("%02d ", array[2*x+2*y*cols]);
        // printf("%02d ", array[2*x+(2*y+1)*cols]);
        // printf("%02d ", array[2*x+1+2*y*cols]);
        // printf("%02d ", array[2*x+1+(2*y+1)*cols]);
        int e1 = array[2*x+2*y*cols];
        int e2 = array[2*x+(2*y+1)*cols];
        int e3 = array[2*x+1+2*y*cols];
        int e4 = array[2*x+1+(2*y+1)*cols];
        int total = e1 + e2 + e3 + e4;
        // printf("total/4=%f\n", total/4.0);
        newImg[x+y*c] = (int)(round(total/4.0)+0.5);
      }
      // printf("\n");
    }
  }

  return newImg;
}

// /* TASK 8 */
// int* half( const int array[],
// 	       unsigned int cols,
// 	       unsigned int rows )
// {
//   //allocate enough memory size for the new image array called newImg
//   unsigned int c = cols%2==0 ? cols/2 : (cols-1)/2;
//   unsigned int r = rows%2==0 ? rows/2 : (rows-1)/2;
//   int* newImg;
//   newImg = (int *)malloc(c*r*sizeof(int));


//   if(newImg != NULL) {
//     //clear the new image array by calling the zero function
//     zero(newImg, c, r);


//     for(unsigned int y=0; y<r; y++) {
//       for(unsigned int x=0; x<c; x++) {
//         int e1 = array[2*x+2*y*cols];
//         int e2 = array[2*x+(2*y+1)*cols];
//         int e3 = array[2*x+1+2*y*cols];
//         int e4 = array[2*x+1+(2*y+1)*cols];
//         int total = e1 + e2 + e3 + e4;
//         newImg[x+y*c] = (int)(round(total/4.0)+0.5);
//       }
//     }
//   }

//   return newImg;
// }