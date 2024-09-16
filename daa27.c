#include <stdio.h>
#include <stdlib.h>

struct WaterPipeline {
    int src, dest, length;
};

struct Network {
    int V, E;
    struct WaterPipeline* pipelines;
};

struct Network* createNetwork(int V, int E) {
    struct Network* network = (struct Network*) malloc(sizeof(struct Network));
    network->V = V;
    network->E = E;
    network->pipelines = (struct WaterPipeline*) malloc(network->E * sizeof(struct WaterPipeline));
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

int comparePipelines(const void* a, const void* b) {
    struct WaterPipeline* a1 = (struct WaterPipeline*) a;
    struct WaterPipeline* b1 = (struct WaterPipeline*) b;
    return a1->length > b1->length;
}

void Kruskal(struct Network* network) {
    int V = network->V;
    struct WaterPipeline result[V];
    int e = 0; 
    int i = 0;  

    qsort(network->pipelines, network->E, sizeof(network->pipelines[0]), comparePipelines);

    struct subset *subsets = (struct subset*) malloc(V * sizeof(struct subset));

    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < network->E) {
        struct WaterPipeline next_pipeline = network->pipelines[i++];

        int x = find(subsets, next_pipeline.src);
        int y = find(subsets, next_pipeline.dest);

        if (x != y) {
            result[e++] = next_pipeline;
            Union(subsets, x, y);
        }
    }

    printf("The water pipelines in the network are as follows: \n");
    int minimumCost = 0;
    for (i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].length);
        minimumCost += result[i].length;
    }
    printf("Total length of the water pipeline network: %d\n", minimumCost);

    free(subsets);
}

void main() {
    int V, E;
    printf("Enter number of areas: ");
    scanf("%d", &V);
    printf("Enter number of water pipelines: ");
    scanf("%d", &E);

    struct Network* network = createNetwork(V, E);

    for (int i = 0; i < E; ++i) {
        printf("Enter source, destination and length of water pipeline %d: ", i + 1);
        scanf("%d %d %d", &network->pipelines[i].src, &network->pipelines[i].dest, &network->pipelines[i].length);
    }

    Kruskal(network);
}
