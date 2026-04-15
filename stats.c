// Final version update
#include "stats.h"

// Test dataset (given in most Coursera versions)
#define SIZE (40)

unsigned char test[SIZE] = {
  34,201,190,154,8,194,2,6,114,88,
  45,76,123,87,25,23,200,122,150,90,
  92,87,177,244,201,6,12,60,8,2,
  5,67,7,87,250,230,99,3,100,90
};

int main() {
    print_array(test, SIZE);
    print_statistics(test, SIZE);
    return 0;
}

void print_statistics(unsigned char *array, unsigned int length) {
    printf("Mean: %d\n", find_mean(array, length));
    printf("Median: %d\n", find_median(array, length));
    printf("Maximum: %d\n", find_maximum(array, length));
    printf("Minimum: %d\n", find_minimum(array, length));
}

void print_array(unsigned char *array, unsigned int length) {
    printf("Array:\n");
    for(int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void sort_array(unsigned char *array, unsigned int length) {
    for(int i = 0; i < length - 1; i++) {
        for(int j = 0; j < length - i - 1; j++) {
            if(array[j] < array[j + 1]) {
                unsigned char temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

unsigned char find_median(unsigned char *array, unsigned int length) {
    sort_array(array, length);

    if(length % 2 == 0) {
        return (array[length/2] + array[length/2 - 1]) / 2;
    } else {
        return array[length/2];
    }
}

unsigned char find_mean(unsigned char *array, unsigned int length) {
    unsigned int sum = 0;
    for(int i = 0; i < length; i++) {
        sum += array[i];
    }
    return sum / length;
}

unsigned char find_maximum(unsigned char *array, unsigned int length) {
    unsigned char max = array[0];
    for(int i = 1; i < length; i++) {
        if(array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

unsigned char find_minimum(unsigned char *array, unsigned int length) {
    unsigned char min = array[0];
    for(int i = 1; i < length; i++) {
        if(array[i] < min) {
            min = array[i];
        }
    }
    return min;
}