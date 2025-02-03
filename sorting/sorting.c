#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This Program will demonstrate 5 popular sorting algorithms: 
// Bubble Sort, Insertion Sort, Mergesort, Quicksort and Selection Sort. 
// By Andrew Colbeck 2017





//-------------------------------------------------------------	//
//					** MAIN PROGRAM **							//
//-------------------------------------------------------------	//

void print_array(int a[], int array_size)
{
        int i;
        for (i = 0; i < array_size; i++)
                printf("%i ", a[i]);
        printf("\n");
}

void randomize_array(int a[], int array_size)
{
        int i;
        srand(time(NULL));
        printf("-------------------------\n");
        printf("Reset the Array to:\n");
        for (i = 0; i < array_size; i++)
                a[i] = (rand()%9+1);
                //a[i] = 10-i;
        print_array(a, array_size);
}

void bubble_sort(int a[], int array_size)
{
	int i, j, temp, local_n=0;
	for (i = 0; i < (array_size - 1); i++)
	{
		//Bubble Sort Loop:
		//array - 1 (saves the process of checking array[0] with array[0]

		for (j = 0; j < array_size - 1 - i; j++)
		{
			//- 1 - i is in place to save time; no need to search
			//the last element (after second sort, no need to search
			//last 2 elements, etc, incrementally)
			if (a[j] > a[j+1])
			{
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
				local_n++;
				print_array(a, array_size);
			}
		}
	}

	printf("Final Array:\n");
	print_array(a, array_size);
}

void insertion_sort (int a[], int array_size)
{
	int i, index, j, local_n=0;

		for (i = 1; i < array_size; i++)
	{
		index = a[i];
		//Index [i] is sampled for comparision at [j] and [j-1]

		for (j = i; j > 0 && a[j-1] > index; j--)
		{
			//If [j] = 0, inner loop ends
			//else check if a[j-1] is greater than index
			//If true, a[j] becomes a[j-1]
			a[j] = a[j-1];
			local_n++;
			print_array(a, array_size);
		}

		a[j] = index;
			//if [j] was not bigger than index,
			//index is inserted at [j]
	}

	printf("Final Array:\n");
	print_array(a, array_size);

	printf("\n");
}


void merge(int a[], int start, int size)
{
    int mid, Li, Ri, *temparray, k=0;

    mid = (start+size)/2;
    	// Find the middle (index) element
    Li = start;
    Ri = mid+1;
    	// Set scope for new array
    	// i.e. on initial run, Li counter = 0, and Ri counter = 6
    temparray = (int*)malloc(sizeof((size-start+1)));

    while ( Li <= mid && Ri <= size )
    {
    	// While Li & Ri are within scope of the array,
    	// establish lowest value and populate new array in asc.
        if ( a[Li] > a[Ri] )
	        {
	            temparray[k] = a[Ri];
	            k++;
	            Ri++;
	        }
    	else
        	{
            	temparray[k] = a[Li];
            	k++;
            	Li++;
			}
    }

    while ( Li <= mid )
    {
        // If Li didn't reach mid in the last while loop,
        // Attach any left over elements to end of array.
        temparray[k] = a[Li];
        k++;
        Li++;
	}

    while ( Ri <= size )
    {
        // See note in previous while loop, applies to Ri.
        temparray[k] = a[Ri];
        k++;
        Ri++;
    }

    for ( Li = 0; Li < (size-start+1); Li++ )
    {
    	// Copy the temp array (now ordered) into a[]
        a[start+Li] = temparray[Li];
    }

    print_array(a, size+1);
}

void merge_sort(int a[], int i, int j)
{
    int mid = (i+j) / 2;

    if (i >= j)
    {
    	print_array(a, j+1);
    	return;
    }
    merge_sort(a, i, mid);
    merge_sort(a, mid+1, j);
    merge(a, i, j);
    return;
}

int partition(int a[], int L, int R)
{
 	// This loop will re-arrange elements < or > than pivot
	// so that if they are less they'll be on the left, and greater will
	// be on the right.  On the final call, the pivot will be placed in
	// the middle, and it's position (marked by pindex) will be returned.

    int pivot = a[R];
    int pindex = L-1;
    // Initialise pindex so that left most element will be
    // included in calculation
    int hold;
    int i;

    for (i = L; i <= R; i++)
    {
        if (a[i] <= pivot)
        {
        	// If element a[i] <= pivot, swap with element
        	// at pindex location
	        pindex++;
	        // pindex = element in question's position in array
	        hold = a[pindex];
	        a[pindex] = a[i];
	        a[i] = hold;
	        print_array(a, R+1);
        }
    }
	return(pindex);
}

void quick_sort(int a[], int L, int R)
{
	int pindex;
	// pindex will mark the final location of pivot
	// after each recursive call

	if ( L < R )
	{
		pindex = partition(a, L, R);
			// All elements < pivot will now be on left,
			// All elements > pivot will now be on right.
		quick_sort(a, L, pindex-1);
			// Recursively quicksort elements left of new pivot point
		quick_sort(a, pindex+1, R);
			// Recursively quicksort elements right of the new pivot point
	}
}

void selection_sort(int a[], int array_size)
{
	int i, j, min, temp, local_n=0;

	for (i = 0; i < array_size - 1; i++)
	{
		//array_size - 1 is in place to save time, see above note
		min = i;
		//min is the array element number that holds the minimum value

		for (j = i+1; j < array_size; j++)
		{
			//start j at element 1, because currently a[min] = a[0],
			//thus it is optimal not to compare two identical values
			if (a[j] < a[min])
				min = j;
			//min will inevitably hold address of lowest value
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
			//a[i] will now hold the minimum value.
		local_n++;
		print_array(a, array_size);

	}
	printf("Final Array:\n");
	print_array(a, array_size);
}

int main()
{
	int a[10], array_size=10, i;
	randomize_array(a, array_size);
	
	printf("Bubble Sort iterations:\n");
	bubble_sort(a, array_size);
	printf("\n");

	printf("Selection Sort iterations:\n");
	randomize_array(a, array_size);
	selection_sort(a, array_size);
	printf("\n");

	printf("Insertion Sort iterations:\n");
	randomize_array(a, array_size);
	insertion_sort(a, array_size);
	printf("\n");
	
	printf("Merge Sort iterations:\n");
	randomize_array(a, array_size);
	merge_sort(a, 0, (array_size-1));
	printf("Final Array:\n");
	print_array(a, array_size);
	printf("\n");

	printf("Quick Sort iterations:\n");
	randomize_array(a, array_size);
	quick_sort(a, 0, (array_size-1));
	printf("Final Array:\n");
	print_array(a, array_size);
	printf("\n");
	
}
