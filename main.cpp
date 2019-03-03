#include <iostream>


//#####################################Insertionsort Begin############################################
/*
 * Insertion Sort
 */
int InsertionSort(int *array, int arraySize) {

    for (int i = 1; i < arraySize; i++) {

        // Assume first element is the smallest value
        int smallestValue = array[i];

        // Declare counter to control while loop
        int counter = i;

        /*
         * While counter is greater than zero and the element to
         * the left of the next value is greater swap positions
         */
        while (counter > 0 && array[counter - 1] > smallestValue) {
            array[counter] = array[counter - 1];
            counter = counter - 1;
        } // End while loop

        array[counter] = smallestValue;  // Assign smallest value to index 0

    } // End for loop

} // End insertion sort function
//#####################################Insertionsort End##############################################


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

    // Pick array random index between beginning and and end of array
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

    // If there exists more than one element in the array divide and conquer
    if (start < end) {
        if ((end + 1) - start > 16) {
            RandomizePartition(array, start, end);
        }
        InsertionSort(array, (end + 1) - start);
    }

} // End QuickSort function
//#####################################QuickSort End#################################################


//#####################################Begin Main Method#############################################
int main() {

    int start, end;

    start = 0;
    end = 65536;

    int array[end];

    for(int i = start; i < end; i++) {
        array[i] = start + rand() % (end - start + 1);
    }

    QuickSort(array, start, end - 1);

    for (int i : array) {
        std::cout << i << ' ';
    }


    std::cout << '\n';


    for(int i = 1; i < end; i++) {
        array[i] = i*2;
    }

    QuickSort(array, start, end - 1);

    for (int i : array) {
        std::cout << i << ' ';
    }

    return 0;
}
//#####################################End Main Method###############################################