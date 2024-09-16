#include <stdio.h>
#include <stdlib.h>

struct Town {
    int src, dest, length;
};

struct Network {
    int V, E;
    struct Town* towns;
};

struct Network* createNetwork(int V, int E) {
    struct Network* network = (struct Network*) malloc(sizeof(struct Network));
    network->V = V;
    network->E = E;
    network->towns = (struct Town*) malloc(network->E * sizeof(struct Town));
    return network;
}


struct subset {
    int parent;
    int rank;
};


int find(struct subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}


void Union(struct subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}


int compareTowns(const void* a, const void* b) {
    struct Town* a1 = (struct Town*) a;
    struct Town* b1 = (struct Town*) b;
    return a1->length > b1->length;
}


void Kruskal(struct Network* network) {
    int V = network->V;
    struct Town result[V];
    int e = 0; 
    int i = 0;  

    qsort(network->towns, network->E, sizeof(network->towns[0]), compareTowns);


    struct subset *subsets = (struct subset*) malloc(V * sizeof(struct subset));


    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < network->E) {
        struct Town next_town = network->towns[i++];

        int x = find(subsets, next_town.src);
        int y = find(subsets, next_town.dest);

        if (x != y) {
            result[e++] = next_town;
            Union(subsets, x, y);
        }
    }

    printf("The Network are as follows: \n");
    int minimumCost = 0;
    for (i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].length);
        minimumCost += result[i].length;
    }
    printf("Total length : : %d\n", minimumCost);

    free(subsets);
}

int main() {
    int V, E;
    printf("Enter number of towns: ");
    scanf("%d", &V);
    printf("Enter number of roads: ");
    scanf("%d", &E);

    struct Network* network = createNetwork(V, E);

    for (int i = 0; i < E; ++i) {
        printf("Enter src, dest, length %d: ", i + 1);
        scanf("%d %d %d", &network->towns[i].src, &network->towns[i].dest, &network->towns[i].length);
    }

    Kruskal(network);
    return 0;
}
