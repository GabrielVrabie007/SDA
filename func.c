#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "func.h"



void initialize_array(int *nr_of_elements, int *array) {
    srand(time(NULL) * getpid());
    for (int i = 0; i < *nr_of_elements; i++) {
        array[i] = (rand() % (*nr_of_elements)) + 1;
    }
}

void print_array(int nr_of_elements, int *array) {
    for (int i = 0; i < nr_of_elements; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void choice_to_print_array(int *array,int *nr_of_elements){
    int choice;
    printf("\nDo you want to print the array  0/1 ?\n");
    scanf_s("%d", &choice);
    if (choice == 1) {
        print_array(*nr_of_elements, array);
    }

}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}



void selection_sort(int *array, int *nr_of_elements) {
    int i, j, min_index;
    for (i = 0; i < *nr_of_elements - 1; i++) {
        min_index = i;
        for (j = i + 1; j < *nr_of_elements; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        swap(&array[i], &array[min_index]);
    }
}

void time_execution_selection_sort(int *array, int *nr_of_elements) {
    clock_t start = clock();

    selection_sort(array, nr_of_elements);

    clock_t end = clock();

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nCPU time used for Selection Sort: %f seconds\n", cpu_time_used);
}

void analyze_selection_sort_execution(int *array, int *nr_of_elements) {
    selection_sort(array, nr_of_elements);
    choice_to_print_array(array, nr_of_elements);
    time_execution_selection_sort(array, nr_of_elements);
}

int partition(int *arr, int start, int last) {

    int *pivot = &arr[start];
    int i = start;
    int j = last;

    while (i < j) {

        while (arr[i] <= *pivot && i <= last - 1) {
            i++;
        }
        while (arr[j] > *pivot && j >= start + 1) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[start], &arr[j]);
    return j;
}

void quick_sort(int *arr, int start, int last) {
    if (start < last) {

        int partitionIndex = partition(arr, start, last);

        quick_sort(arr, start, partitionIndex - 1);
        quick_sort(arr, partitionIndex + 1, last);
    }
}


void time_execution_quick_sort(int *array, int *nr_of_elements) {
    clock_t start = clock();

    quick_sort(array, 0, *nr_of_elements - 1);

    clock_t end = clock();

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nCPU time used: %f seconds\n", cpu_time_used);
}

void analyze_quick_sort_execution(int *array,int *nr_of_elements) {
    quick_sort(array, 0, *nr_of_elements - 1);
    choice_to_print_array(array, nr_of_elements);
    time_execution_quick_sort(array, nr_of_elements);

}

void liniar_search(int *array,int *nr_of_elements,int target){

    int found=0;
    for (int i = 0; i < *nr_of_elements; ++i) {
        if (array[i] == target) {
            printf("\nThe element %d was found at position %d\n", target, ++i);
            found=1;
            break;
        }
    }
    if (!found) {
        printf("\nThe element %d was not found\n", target);
    }

}

void time_execution_liniar_search(int *array,int *nr_of_elements,int target){
    clock_t start = clock();

    liniar_search(array,nr_of_elements,target);

    clock_t end = clock();

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nCPU time used: %f seconds\n", cpu_time_used);
}

void analyze_liniar_search_execution(int *array, int *nr_of_elements){
    int target;
    printf("\nPlease enter the target: ");
    scanf_s("%d", &target);
    choice_to_print_array(array, nr_of_elements);
    time_execution_liniar_search(array, nr_of_elements, target);

}
int binary_search(int *array,int *nr_of_elements,int left,int right,int target){
    if (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] == target) {
            return mid;
        } else if (array[mid] > target) {
            return binary_search(array, nr_of_elements, left, mid - 1,target);
        } else {
            return binary_search(array, nr_of_elements, mid + 1, right,target);
        }
    }
    return -1;
}

void time_execution_binary_search(int *array,int *nr_of_elements,int target){
    clock_t start = clock();

    binary_search(array, nr_of_elements, 0, *nr_of_elements - 1,target);

    clock_t end = clock();

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nCPU time used: %f seconds\n", cpu_time_used);
}

void analyze_binary_search_execution(int *array, int *nr_of_elements){
    int target;
    printf("\nPlease enter the target: ");
    scanf("%d", &target);
    choice_to_print_array(array, nr_of_elements);
    //binary_search(array, nr_of_elements, 0, *nr_of_elements - 1,target);
    time_execution_binary_search(array, nr_of_elements, target);
}

void add_array(int *a, int *b, int *result, int length) {
    int carry = 0;
    for (int i = length - 1; i >= 0; i--) {
        int sum = a[i] + b[i] + carry;
        result[i] = sum % 10;
        carry = sum / 10;
    }
}

void print_fibonacci(int result[], int length) {
    int i = 0;

    while (i < length && result[i] == 0) {
        i++;
    }
    if (i == length) {
        printf("0");
    } else {
        for (; i < length; i++) {
            printf("%d", result[i]);
        }
    }
    printf("\n");
}

void calculate_fibonacci(int n) {
    int maxLength = 200000;

    int *fib1 = calloc(maxLength, sizeof(int));
    int *fib2 = calloc(maxLength, sizeof(int));
    int *result = calloc(maxLength, sizeof(int));

    fib1[maxLength - 1] = 1;
    fib2[maxLength - 1] = 1;

    for (int i = 3; i <= n; i++) {
        add_array(fib1, fib2, result, maxLength);

        int *temp = fib2;
        fib2 = fib1;
        fib1 = result;
        result = temp;
    }

    print_fibonacci(fib1, maxLength);

    free(fib1);
    free(fib2);
    free(result);
}

void time_execution_fibbo_number(int n) {
    clock_t start = clock();

    calculate_fibonacci(n);

    clock_t end = clock();

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nCPU time used: %f seconds\n", cpu_time_used);
}


void switch_options() {
    int nr_of_elements;
    printf("Please enter the number of elements: ");
    scanf_s("%d", &nr_of_elements);
    int *array = (int *) malloc(sizeof(int) * nr_of_elements);
    initialize_array(&nr_of_elements, array);
    int choice;

    while (1) {
        printf("1. Selection sort\n");
        printf("2. Quick sort\n");
        printf("3. Liniar search\n");
        printf("4. Binary search\n");
        printf("5. Fibonacci\n");
        printf("Select option (0 to exit): ");
        scanf_s("%d", &choice);

        if (choice == 0) {
            free(array);
            printf("Exiting...\n");
            break;
        }

        switch (choice) {
            case 1: {
                analyze_selection_sort_execution(array,&nr_of_elements);
                break;
            }
            case 2: {
                analyze_quick_sort_execution(array,&nr_of_elements);
                break;
            }
            case 3: {
                analyze_liniar_search_execution(array, &nr_of_elements);
                break;
            }
            case 4: {
                analyze_binary_search_execution(array, &nr_of_elements);
                break;
            }
            case 5:{
                int number;
                printf("Enter number of searched fibbonacci element: ");
                scanf_s("%d", &number);
                printf("The %dth Fibonacci number is: ", number);
                time_execution_fibbo_number(number);
                break;
            }

            default:
                printf("Invalid option\n");
                break;
        }
    }
}
