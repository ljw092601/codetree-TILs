#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int* arr;
    int num;
    int size=1;
    arr = malloc(sizeof(int)*1);
    scanf("%d", &num);
    for (int i=0;i<num;i++){
        char str[10];
        scanf("%s", str);
        if (strcmp(str,"push_back")==0){
            int digit;
            scanf("%d", &digit);
            arr[size-1]=digit;
            arr = realloc(arr,size+1);
            size++;
        }
        else if (strcmp(str, "pop_back")==0){
            arr[size-1] = 0;
            arr = realloc(arr, size-1);
            size--;
        }
        else if (strcmp(str, "size")==0){
            printf("%d", size);
        }
        else {
            int numnum;
            scanf("%s", &numnum);
            printf("%d", arr[numnum-1]);
        }
    }

    return 0;
}