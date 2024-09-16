#include <stdio.h>
#include <stdlib.h>

struct Expense {
    char name[50];
    int cost;
    int quality;
};

int compare(const void* a, const void* b) {
    struct Expense* expenseA = (struct Expense*)a;
    struct Expense* expenseB = (struct Expense*)b;
    double ratioA = (double)expenseA->quality / expenseA->cost;
    double ratioB = (double)expenseB->quality / expenseB->cost;
    if (ratioA > ratioB)
        return -1;
    else if (ratioA < ratioB)
        return 1;
    else
        return 0;
}

void allocateBudget(struct Expense expenses[], int n, int budget) {
    qsort(expenses, n, sizeof(struct Expense), compare);

    int totalQuality = 0;
    int remainingBudget = budget;

    printf("Selected expenses:\n");
    for (int i = 0; i < n; ++i) {
        if (expenses[i].cost <= remainingBudget) {
            printf("%s - Cost: %d, Quality: %d\n", expenses[i].name, expenses[i].cost, expenses[i].quality);
            totalQuality += expenses[i].quality;
            remainingBudget -= expenses[i].cost;
        }
    }

    printf("\nTotal quality with the given budget: %d\n", totalQuality);
}

int main() {
    int budget = 8000;
    int n = 5;

    struct Expense expenses[] = {
        {"Venue Rental", 5000, 300},
        {"Catering", 2000, 200},
        {"Keynote Speaker", 3000, 400},
        {"Marketing", 1500, 150},
        {"Audio/Visual Equipment", 1000, 100}
    };

    allocateBudget(expenses, n, budget);

    return 0;
}
