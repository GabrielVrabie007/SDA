#define Algorithms_ANALISIS
#ifdef Algorithms_ANALISIS

/**
 * Initialize with random number generator
 * @param nr_of_elements
 * @param array
 */
void initialize_array(int *nr_of_elements, int *array);

/**
 * Print the random number array
 * @param nr_of_elements
 * @param array
 */
void print_array(int nr_of_elements, int *array);

/**
 * Give choice to print the random number array
 * @param array
 * @param nr_of_elements
 */
void choice_to_print_array(int *array,int *nr_of_elements);

/**
 * Swap two values
 * @param a
 * @param b
 */
void swap(int *a, int *b);
/**
 * Implement algorithm Selection Sort
 * @param array
 * @param nr_of_elements
 */
void selection_sort(int *array, int *nr_of_elements);
/**
 * Measure time execution of Selection Sort
 * @param array
 * @param nr_of_elements
 */
void time_execution_selection_sort(int *array, int *nr_of_elements);
/**
 * Main function where is analyzing selection sort
 * @param array
 * @param nr_of_elements
 */
void analyze_selection_sort_execution(int *array, int *nr_of_elements);

/**
 * Devide array using method of pivot and swap elements
 * @param arr
 * @param start
 * @param last
 * @return
 */
int partition(int *arr, int start, int last);

/**
 * Implement Quick Sort Algorithm
 * @param arr
 * @param start
 * @param last
 */
void quick_sort(int *arr, int start, int last);
/**
 * Measure time execution in seconds of the algorithm quick sort
 * @param array
 * @param nr_of_elements
 */
void time_execution_quick_sort(int *array, int *nr_of_elements);
/**
 * Main function where is analyzing quick sort
 * @param array
 * @param nr_of_elements
 */
void analyze_quick_sort_execution(int *array,int *nr_of_elements);
/**
 * Implement algorithm Liniar Search
 * @param array
 * @param nr_of_elements
 * @param target
 */
void liniar_search(int *array,int *nr_of_elements,int target);
/**
 * Measure time execution of algorithm Liniar Search
 * @param array
 * @param nr_of_elements
 * @param target
 */
void time_execution_liniar_search(int *array,int *nr_of_elements,int target);
/**
 * Main function that analyze performance linear search
 * @param array
 * @param nr_of_elements
 */
void analyze_liniar_search_execution(int *array, int *nr_of_elements);
/**
 * Implementation of algorithm Binary Search
 * @param array
 * @param nr_of_elements
 * @param left
 * @param right
 * @param target
 * @return
 */
/**
 * Binary search algorithm.
 *
 * @param array Pointer to the sorted array.
 * @param nr_of_elements Pointer to the number of elements in the array.
 * @param left Index of the left boundary of the search interval.
 * @param right Index of the right boundary of the search interval.
 * @param target The value to search for.
 * @return Index of the target element if found, -1 otherwise.
 */
int binary_search(int *array, int *nr_of_elements, int left, int right, int target);

/**
 * Measure the execution time of the binary search algorithm.
 *
 * @param array Pointer to the sorted array.
 * @param nr_of_elements Pointer to the number of elements in the array.
 * @param target The value to search for.
 */
void time_execution_binary_search(int *array, int *nr_of_elements, int target);

/**
 * Analyze the performance of the binary search algorithm.
 *
 * @param array Pointer to the sorted array.
 * @param nr_of_elements Pointer to the number of elements in the array.
 */
void analyze_binary_search_execution(int *array, int *nr_of_elements);

/**
 * Add two arrays element-wise.
 *
 * @param a First array.
 * @param b Second array.
 * @param result Array to store the result.
 * @param length Length of the arrays.
 */
void add_array(int *a, int *b, int *result, int length);

/**
 * Print the elements of an array representing a large Fibonacci number.
 *
 * @param result Array representing the Fibonacci number.
 * @param length Length of the array.
 */
void print_fibonacci(int result[], int length);

/**
 * Calculate the nth Fibonacci number.
 *
 * @param n The index of the Fibonacci number to calculate.
 */
void calculate_fibonacci(int n);

/**
 * Measure the execution time of calculating the nth Fibonacci number.
 *
 * @param n The index of the Fibonacci number to calculate.
 */
void time_execution_fibbo_number(int n);

/**
 * Main function to switch between options.
 */
void switch_options();


#endif


