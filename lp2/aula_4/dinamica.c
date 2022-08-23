#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, *arr;
    printf("Size of the array: ");
    scanf("%i", &n);
    arr = calloc(n, sizeof(int));
    if (arr = NULL)
    {
        printf("Unable to locate memory.\n");
        return -1;
    }
    printf("Enter the elements (space/newline separated): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &arr[i]);
    }

    // printf("");
}