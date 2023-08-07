// program to sort an array of integers in ascending or descending order

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Declare Functions
void getInput (void);
void sortArray (void);
void printOutput (void);

// Declare Global Variables
int gNumElements;
int *gArray;
int gIsAscending;


// Main Function
int main(void) {

  getInput ();

  sortArray ();

  printOutput ();
  
  return 0;
}

void getInput (void) {
  printf ("Enter the number of elements to sort: ");
  scanf ("%d", &gNumElements);

  gArray = malloc (gNumElements * sizeof(int));
  printf ("Enter elements: ");
  for (int i = 0; i < gNumElements; i++) {
    scanf ("%d", &gArray[i]);
  }

  printf ("Ascending = 1 - Descending = 0: ");
  scanf ("%d", &gIsAscending);
}

void sortArray (void) {
  int i, j, temp;

  // Sort array (ascending)
  if (gIsAscending) {
    for (i = 0; i < gNumElements - 1; i++) {
      for (j = i + 1; j < gNumElements; j++) {
        if (gArray[i] > gArray[j]) {
          temp = gArray[i];
          gArray[i] = gArray[j];
          gArray[j] = temp;
        }
      }
    }
  }
  else {
    // Sort array (descending)
    // sort ascending
    for (i = 0; i < gNumElements - 1; i++) {
      for (j = i + 1; j < gNumElements; j++) {
        if (gArray[i] > gArray[j]) {
          temp = gArray[i];
          gArray[i] = gArray[j];
          gArray[j] = temp;
        }
      }
    }
    // Reverse
    for (int i = 0, j = gNumElements - 1; i <= j; i++, j--) {
      int t = gArray[i];
      gArray[i] = gArray[j];
      gArray[j] = t;
    }
  }
}

void printOutput (void) {
  printf ("After sort\n");
  for (int i = 0; i < gNumElements; i++) {
    printf ("%d ", gArray[i]);
  }
}