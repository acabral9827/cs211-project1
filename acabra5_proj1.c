#include <stdio.h>
#include <stdlib.h>

// copies the values from the source array onto the destination array
void makeArrayCopy( int *sourceArray, int *destArray, int sizeOfArray )
{
	int k;
	for ( k = 0; k < sizeOfArray; k++ )
	{
		destArray[k] = sourceArray[k];
	}
}

// swap variables
void swap( int *theArray, int q, int r )
{
	int temp = theArray[q];
	theArray[q] = theArray[r];
	theArray[r] = temp;
}

// Selection sort
void myFavoriteSort( int *arrayToBeSorted, int sizeOfArray )
{
	int indexOfSmallest = 0;
	int currIndex;
	int nextIndex;

	for ( currIndex = 0; currIndex < sizeOfArray - 1; currIndex++ )
	{
		indexOfSmallest = currIndex;
		// look for smallest value from the indices to be sorted
		for ( nextIndex = currIndex + 1; nextIndex < sizeOfArray; nextIndex++ )
		{
			if ( arrayToBeSorted[nextIndex] < arrayToBeSorted[indexOfSmallest])
			{
				// store the index of the smallest value
				indexOfSmallest = nextIndex;
			}
		}
		// swap the smallest value into the correct position
		if ( indexOfSmallest != currIndex )
		{
			swap( arrayToBeSorted, currIndex, indexOfSmallest);
		}
	}
}

int linSearch( int array[], int sizeOfArray, int target, int *numComparisons)
{
	int index = 0;
	int notFound = -1;
	(*numComparisons) = 0;
	//printf("Target is: %d\n", target);
	while ( index < sizeOfArray && array[index] != target )
	{
		// printf("Index is: %d\n", index);
		// printf("Value is: %d\n", array[index]);
		++index;
	}
	
	if ( array[index] == target)
	{
		(*numComparisons) = index + 1;
		// printf("Index is: %d\n", index);
		return index;
	}
	else
	{
		(*numComparisons) = index;
		return notFound;
	}

}

int binSearch( int array[], int sizeOfArray, int target, int *numComparisons )
{
    int start = 0;
    int end = sizeOfArray - 1;
    int midPoint = start + ( end - start ) / 2;
    while( target != array[midPoint] )
	{
        *numComparisons = *numComparisons + 1;
        
        // get the middle value
        midPoint = start + ( end - start ) / 2;

		// if target is the midpoint then return
        if ( target == array[midPoint] )
		{
            return midPoint;
        }
        
        if ( target < array[midPoint] )
		{
            end = midPoint - 1;
        }
        
        if ( target > array[midPoint] )
		{
            start = midPoint + 1;
        }
        
        if ( end < start )
		{
            return -1;
        }
	}
}


int main(int argc, char** argv)
{
	int val;
    int *fromArray;		// original array
	int *newArray;		// new array created from the sorted values in original array
	int *searchArray;	// array used to store the values of the search
    int size = 100;
	int newSize = 0;
	int searchSize = 10;
	int i = 0;
	int j = 0;
	int tempVal = 0;
	int numComparisons;
	int linPos = 0;
	int binPos = 0;

	// allocate a defualt amount of memory to the array
	fromArray = (int*) malloc (size * sizeof(int));

	/* prompt the user for input */
	printf("Enter in a list of numbers ito be stored in a dynamic array.\n");
	printf("End the list with the terminal value of -999\n");

	/* loop until the user enters -999 */
	scanf("%d", &tempVal);
	if ( tempVal != -999 )
	{
		fromArray[i] = tempVal;
	}
	//scanf("%d", &fromArray);
	while (tempVal != -999)
	{
		++i;
		// check that the current index is not greater than the size
		if ( i == size )
		{
			// create an empty pointer
			int *tmp;
			// set the pointer equal to the array, to copy the values
			tmp = fromArray;
			// double the allocated memory for the array
			fromArray = (int*) malloc (2 * size * sizeof(int));

			// put the values back from the tmp into the array
			for ( int x = 0; x < size; x++ )
			{
				fromArray[x] = tmp[x];
			}

			// delete tmp to free memory
			free(tmp);

			// update size to be doubled
			size = size * 2;
		}

		/* store the value into an array */
		scanf("%d", &tempVal);

		// Check that tempVal isnt -999
		if ( tempVal != -999 )
		{
			// store tempVal into array since it does NOT equal -999
			fromArray[i] = tempVal;
		}
		// break out of loop once -999 is encountered
		else
		{
			break;
		}

	}
	// Debug: display the values to check what is inside the array
		printf("The values in fromArray are: ");
		for ( int g = 0; g < i; g++ )
		{
			printf("%d", *(fromArray+g));
			if ( g+1 == i )
			{
				printf("\n");
			}
			else
			{
				printf("-");
			}
		}

	// using the counter from the read & store while loop
	// set the newSize equal to that of the counter
	newSize = i;

	// set the exact size of variables to the size of the new copied array
	newArray = (int*) malloc (newSize * sizeof(int));

	/* call function to make a copy of the array of values */
	makeArrayCopy( fromArray, newArray, newSize );

	// Debug: check if the copied values match the original array
	printf("The values in newArray are: ");
	for ( int g = 0; g < i; g++ )
	{
		printf("%d", *(newArray+g));
		if ( g+1 == i )
		{
			printf("\n");
		}
		else
		{
			printf("-");
		}
	}

	/* call function to sort one of the arrays */
	myFavoriteSort( newArray, newSize );
	printf("The values in newArray sorted are: ");
	for ( int g = 0; g < i; g++ )
	{
		printf("%d", *(newArray+g));
		if ( g+1 == i )
		{
			printf("\n");
		}
		else
		{
			printf("-");
		}
	}

	/* loop until the user enters -999 */
	printf("Enter in a list of numbers to use for searching.  \n");
	printf("End the list with a terminal value of -999\n");
	searchArray = (int*) malloc (searchSize * sizeof(int));
	scanf("%d", &tempVal);
	if ( tempVal != -999 )
	{
		searchArray[j] = tempVal;
	}
	while ( tempVal != -999 )
	{
		++j;
		if ( j == searchSize )
		{
			// create an empty pointer
			int *tmp2;
			// set the pointer equal to the array, to copy the values
			tmp2 = searchArray;
			// double the allocated memory for the array
			searchArray = (int*) malloc (2 * searchSize * sizeof(int));

			// put the values back from the tmp2 into the array
			for ( int x = 0; x < searchSize; x++ )
			{
				searchArray[x] = tmp2[x];
			}

			// delete tmp to free memory
			free(tmp2);

			// update size to be doubled
			searchSize = searchSize * 2;
		}
		int counter = 0;
		// store the values into the search array
		scanf("%d", &tempVal);
		// Check that tempVal isnt -999
		if ( tempVal != -999 )
		{
			// store tempVal into array since it does NOT equal -999
			searchArray[j] = tempVal;
			counter++;
		}
		// break out of loop once -999 is encountered
		
		for ( int y = 0; y < j; y++ )
		{
			printf("The values in searchArray are: ");
			for ( int g = 0; g < j; g++ )
			{
				printf("%d", *(searchArray+g));
				if ( g+1 == j )
				{
					printf("\n");
				}
				else
				{
					printf("-");
				}
			}

			/* call function to use the value in a linear search on the unsorted array */
			printf("Linear searching for: %d\n", searchArray[y]);
			/* print out info about the linear search results  */
			linPos = linSearch( newArray, newSize, searchArray[y], &numComparisons);
			if ( linPos != -1 )
			{
				printf("Found at position: %d\n", linPos);
				printf("Number of comparisons: %d\n\n", numComparisons);
			}
			else
			{
				printf("Not found at position: %d\n", linPos);
				printf("Number of comparisons: %d\n", numComparisons);
			}
			/* call function to use the value in a binary search on the sorted array */
			printf("Binary searching for: %d\n", searchArray[y]);
			/* print out info about the binary search results  */
			binPos = binSearch( newArray, newSize, searchArray[y], &numComparisons);
			if ( binPos != -1 )
			{
				printf("Found at position: %d\n", binPos);
				printf("Number of comparisons: %d\n", numComparisons);
			}
			else
			{
				printf("Not found at position: %d\n", binPos);
				printf("Number of comparisons: %d\n", numComparisons);
			}
		}

		printf("Good bye\n");
	}
	
	return 0;
}
