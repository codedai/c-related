/*
* [l, r] 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef int data_t;

int     randData(data_t *, const int);                      // generate random int array
int     printArray(data_t *, const int, const char *);      // print array
void    timeTest(int, int);                                 // Test the algorithm's time complexity
int     correctionTest(int, int);

int     _assertEqualArray(const data_t *, const data_t *, const int);
void    _swap(data_t *, int, int);

void    quickSort (data_t *, const int);
void    mergeSort (data_t *, const int);
void    insertSort(data_t *, const int);
void    bubbleSort(data_t *, const int);
void    selectSort(data_t *, const int);
void    qSort(data_t *, const int);

void (*sortFuncList[])(data_t *, const int) = {
    qSort,
    quickSort,
    mergeSort,
    insertSort,
    bubbleSort,
    selectSort,
};

char *sortFuncName[] = {
    "Q Sort",
    "Quick Sort",
    "Merge Sort",
    "Insert Sort",
    "Bubble Sort",
    "Select Sort",
};

// ============================================= Sort algorithms ===========================================================================

// --------------------------------------------------------------- Selection Sort ----------------------------------------------------------

void selectSort(data_t * nums, const int numsSize) {
    int i, j;
    for (i = 0; i < numsSize; i++) {
        data_t tmp_min = i;
        for (j = i; j < numsSize; j++) {
            if (nums[tmp_min] > nums[j]) {
                tmp_min = j;
            }
        }
        _swap(nums, tmp_min, i);
    }
}

// ---------------------------------------------------------------- Bubble Sort ------------------------------------------------------------

void bubbleSort(data_t * nums, const int numsSize) {
    int i = 0, j = 0;
    for (i = 0; i < numsSize - 1; i++) {
        for(j = 0; j < numsSize - 1 - i; j++) {
            if (nums[j] > nums[j + 1]) {
                _swap(nums, j, j+1);
            }
        }
    }
}

// ---------------------------------------------------------------- Insertion Sort ---------------------------------------------------------

void insertSort(data_t * nums, const int numsSize) {
    int i, j;
    for (i = 1; i < numsSize; i++) { 
        for (j = i - 1; j >= 0; j--) {
            if (nums[j] > nums[j + 1])
                _swap(nums, j, j + 1);
            else
                break;
        }
    }
}

// -------------------------------------------------------------- Merge Sort ---------------------------------------------------------------

void _mergeSortHelper(data_t* nums, int start, int end, data_t * helperList) {
    if (start >= end) return;
    int mid = start + (end - start) / 2;
    _mergeSortHelper(nums, start, mid, helperList);
    _mergeSortHelper(nums, mid+1, end, helperList);

    int i = start, j = mid+1, x = start;
    while (i <= mid && j <= end) {

        if (nums[i] < nums[j]) helperList[x++] = nums[i++];
        else helperList[x++] = nums[j++];
    }

    if (i == mid+1)
        while (j <= end) 
            helperList[x++] = nums[j++];
    else
        while (i <= mid)
            helperList[x++] = nums[i++];

    memcpy(nums+start, helperList+start, (end - start + 1) * sizeof(data_t));
}

void mergeSort(data_t * nums, const int numsSize) {
    data_t * helperList = malloc(sizeof(data_t) * numsSize);
    _mergeSortHelper(nums, 0, numsSize-1, helperList);
    free(helperList);
}

// -------------------------------------------------------------------- Quick Sort ---------------------------------------------------------

void _swap(data_t * nums, int i, int j) {
    data_t tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

void _quickSortHelper(data_t * nums, int start, int end) {

    if (end <= start) return;

    // _swap(nums, start, start + (end - start) / 2);

    data_t p = nums[start];
    int l = start + 1, r = end;

    while (r >= l) {
        if (nums[l] < p) l++;
        else if (nums[r] >= p) r--;
        
        else _swap(nums, l++, r--);

    }

    _swap(nums, start, r);

    _quickSortHelper(nums, start, r-1);
    _quickSortHelper(nums, r+1, end);

}


void quickSort(data_t * nums, const int numsSize) {
    _quickSortHelper(nums, 0, numsSize-1);
}


// ========================================= Q sort (using qsort for c standard library) ==============================================

int cmp (const void * a, const void * b) {
    data_t arg1 = *(const data_t *)a;
    data_t arg2 = *(const data_t *)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

void qSort(data_t * array, const int aSize) {
    qsort(array, aSize, sizeof(data_t), cmp);
}

// ========================================== main =====================================================================================

int main(int argc, char *argv[]) {

    int arraySize = 10000;    // Array size
    int sortTime = 1;         // Sort time

    if (1 == argc) {
        timeTest(arraySize, sortTime);
    } else if (2 == argc) {
        arraySize = atoi(argv[1]);
        printf("Sorting %d numbers....\n", arraySize);
        timeTest(arraySize, 1);
    } else if (3 == argc) {
        arraySize = atoi(argv[1]);
        sortTime = atoi(argv[2]);
        printf("Sorting %d numbers for %d times....\n", arraySize, sortTime);
        correctionTest(arraySize, sortTime);
    } else if (4 == argc) {
        arraySize = atoi(argv[1]);
        sortTime = atoi(argv[2]);
        printf("Sorting %d numbers for %d times....\n", arraySize, sortTime);
        timeTest(arraySize, sortTime);
    }

    printf(" * * * * * * * * * * * * \n");
    return putchar(10) && 0; 
}

// ----------------------------------------------- Generate random data and fill in the array ----------------------------------------------

int randData(data_t * array, const int aSize) {
    // srand(clock());
    int i = 0;

    for (i = 0; i < aSize; i++)
        array[i] = rand() % aSize;

    // printArray(array, aSize, "Generated array");
    return 0;
}

// ------------------------------------------------ Print out the array --------------------------------------------------------------------

int printArray(data_t * array, const int aSize, const char * text) {
    if (aSize > 100) {
        return -1;
    }

    printf("\n * %s\n *", text);
    int i;
    for (i = 0; i < aSize; i++) {
        printf("%4d ", array[i]);
        if (19 == i % 20) printf("\n *");
    }

    printf("\n * ================ %p =================\n * \n * ", array);
    return 0;
}

// ----------------------------------------------------------- Run the sort algo and test the time complexity ------------------------------

void timeTest(int arraySize, int sortTime) {
    int start, end, timeQ;
    int i, j;
    data_t * arr = (data_t *)malloc(sizeof(data_t) * arraySize);     // Where we store the data, but we don't sort this array.
    randData(arr, arraySize);   // Fill the array with random number.
    printf("Array length: %d; Array memory size: %d\n", arraySize, sizeof(data_t) * arraySize);

    data_t * arr1 = (data_t *)malloc(sizeof(data_t) * arraySize);    // Sort this array;
    
    for (i = 0; i < sizeof(sortFuncList) / sizeof(int *); i++) {
        start = clock();
        j = 0;
        while (j < sortTime) {
            memcpy(arr1, arr, arraySize * sizeof(data_t));
            sortFuncList[i](arr1, arraySize);
            j++;
        }
        end = clock();
        printf("----------\n");
        printf(" * %p: %s             Time cost: %9d. Start: %9d, End: %9d \n", sortFuncList[i], sortFuncName[i], end - start, start, end);
    }

    free(arr1);
    free(arr);

    return;
}

// ---------------------------------------- Run the sort algo and test the correction of the algorithm -------------------------------------

int _assertEqualArray(const data_t * arr_sol, const data_t * arr_ans, const int arraySize) {
    int i;
    for (i = 0; i < arraySize; i++) {
        if (arr_sol[i] != arr_ans[i]) return 0;
    }

    return 1;
}

int correctionTest(int arraySize, int sortTime) {
    int i, j;

    data_t * arr_base = (data_t *) malloc(sizeof(data_t) * arraySize);
    data_t * arr_ans = (data_t *) malloc(sizeof(data_t) * arraySize);
    data_t * arr_sol = (data_t *) malloc(sizeof(data_t) * arraySize);

    for (i = 0; i < sortTime; i++) {
        printf(" * sort the %d-th time\n * ", i);
        randData(arr_base, arraySize);
        memcpy(arr_ans, arr_base, arraySize * sizeof(data_t));
        qSort(arr_ans, arraySize);
        for (j = 0; j < sizeof(sortFuncList) / sizeof(int *); j++) {
            memcpy(arr_sol, arr_base, arraySize * sizeof(data_t));
            sortFuncList[j](arr_sol, arraySize);
            if (_assertEqualArray(arr_ans, arr_sol, arraySize) == 0) {
                printf("----------\n");
                printf(" * %p: %s  is not correct\n * ------------->>>----------->>>------------", sortFuncList[j], sortFuncName[j]);
                printArray(arr_base, arraySize, "Orignal array");
                printArray(arr_ans, arraySize, "Answer array");
                printArray(arr_sol, arraySize, "Sorted array");
                return 0;
            }
        }
    }

    free(arr_base);
    free(arr_sol);
    free(arr_ans);
    printf("All test for has been finished! Great Job\n");

    return 1;
}
