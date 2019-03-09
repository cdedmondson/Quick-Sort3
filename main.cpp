#include <iostream>
#include <cmath>


//#####################################Partition Begin################################################
/*
 * Partition
 */
int Partition(int *array, int start, int end) {

    // Set pivot to last element in array
    int pivot = array[end];

    // Start partition index at index 0
    int partitionIndex = start;

    // Declare temporary variables for swapping values
    int swapArray_i, swapPartitionIndex;

    /*
     * Start at index array[i] and compare each element to pivot.
     * If element at index "i" is less than or equal to pivot,
     * swap the partition index and array[i] index values.
     */
    for (int i = start; i < end; i++) {
        if (array[i] <= pivot) {
            swapArray_i = array[i];
            swapPartitionIndex = array[partitionIndex];
            array[i] = swapPartitionIndex;
            array[partitionIndex] = swapArray_i;
            partitionIndex++;
        }
    }

    // After array is sorted swap end of array "pivot" with partition index
    swapArray_i = array[partitionIndex];
    swapPartitionIndex = array[end];
    array[end] = swapArray_i;
    array[partitionIndex] = swapPartitionIndex;

    return partitionIndex;
} // End Partition function
//#####################################Partition End#################################################


//#####################################RandomizePartition Begin######################################
int RandomizePartition(int *array, int start, int end) {

    int randomIndex;

    // Pick random index between beginning and and end of array
    randomIndex = start + rand() % (end - start + 1);
    int temp1 = array[randomIndex];
    int temp2 = array[end];
    // Swap end of array(pivot) with value located at randomIndex
    array[randomIndex] = temp2;
    array[end] = temp1;

    return Partition(array, start, end);
}
//#####################################RandomizePartition End########################################


//#####################################QuickSort Begin###############################################
/*
 * QuickSort
 */
void QuickSort(int *array, int start, int end) {

    int partitionIndex;

    // If there exists more than one element in the array divide and conquer
    if (start < end) {
        if((end+1)-start > 16) {
            partitionIndex = RandomizePartition(array, start, end);
            QuickSort(array, start, partitionIndex - 1);
            QuickSort(array, partitionIndex + 1, end);
        }
        else{
            partitionIndex = Partition(array, start, end);
            QuickSort(array, start, partitionIndex - 1);
            QuickSort(array, partitionIndex + 1, end);
        }
    }


} // End QuickSort function
//#####################################QuickSort End#################################################


//#####################################Begin Main Method#############################################
int main() {

    clock_t tStart = clock();

    int start, end;

    start = 0;
    end = pow(2,14);

    int array[end];

   /* for (int i = start; i < end; i++) {
        array[i] = start + rand() % (end - start + 1);
    }

    QuickSort(array, start, end - 1);

    for (int i = 0; i < end; i++) {
        std::cout << i << ' ';
    }*/

    for(int i = 0; i < end; i++) {
        array[i] = i;
    }

    QuickSort(array, start, end - 1);

    for (int i : array) {
        std::cout << i << ' ';
    }

    printf("\nTime taken: %.9fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}
//#####################################End Main Method###############################################