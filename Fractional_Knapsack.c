#include <stdio.h>
#include <stdlib.h>

struct Item{
    int value;
    int weight;
};

int compare(const void* a, const void* b){
    struct Item* item1 = (struct Item*)a;
    struct Item* item2 = (struct Item*)b;

    double ratio1 = (double)item1->value / item1->weight;
    double ratio2 = (double)item2->value / item2->weight;

    if(ratio1 > ratio2){
        return -1;
    } else if(ratio1 < ratio2){
        return 1;
    } else {
        return 0;
    }
}

void fractionalKnapsack(int W, struct Item arr[], int n){
    qsort(arr, n, sizeof(struct Item), compare);

    int i;
    double totalValue = 0;
    double frac;

    for(i = 0; i < n; i++){
        if(W == 0){
            break;
        }

        if(arr[i].weight <= W){
            totalValue += arr[i].value;
            W -= arr[i].weight;
        } else {
            frac = (double)W / arr[i].weight;
            totalValue += arr[i].value * frac;
            W = 0;
        }
    }

    printf("Maximum possible value = %lf\n", totalValue);
}

int main(){
    int n, W, i;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item arr[n];

    printf("Enter the weight and value of each item:\n");
    for(i = 0; i < n; i++){
        scanf("%d %d", &arr[i].weight, &arr[i].value);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    fractionalKnapsack(W, arr, n);

    return 0;
}
