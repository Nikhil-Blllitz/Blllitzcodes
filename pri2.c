/*To determine the shortest travel time from a designated source city to all other cities in a network of roads with specific travel times, we can use Dijkstra's algorithm. This algorithm is well-suited for finding the shortest paths in a graph with non-negative weights.

### Implementation

1. *Define the graph structure* using an adjacency list.
2. *Implement Dijkstra's algorithm* to find the shortest paths from the source city.
3. *Print the shortest travel times* from the source city to all other cities.

### Code Implementation in C

c*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CITIES 100

typedef struct {
    int destination;
    int travel_time;
} Road;

typedef struct {
    Road roads[MAX_CITIES];
    int road_count;
} City;

City cities[MAX_CITIES];
int num_cities;

void addRoad(int src, int dest, int travel_time) {
    cities[src].roads[cities[src].road_count].destination = dest;
    cities[src].roads[cities[src].road_count].travel_time = travel_time;
    cities[src].road_count++;
}

int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < num_cities; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int src) {
    int dist[MAX_CITIES];
    int sptSet[MAX_CITIES];

    for (int i = 0; i < num_cities; i++) {
        dist[i] = INT_MAX, sptSet[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < num_cities - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        for (int i = 0; i < cities[u].road_count; i++) {
            int v = cities[u].roads[i].destination;
            int weight = cities[u].roads[i].travel_time;
            if (!sptSet[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    printf("City\tShortest Travel Time from City %d\n", src);
    for (int i = 0; i < num_cities; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    for (int i = 0; i < num_cities; i++) {
        cities[i].road_count = 0;
    }

    int num_roads;
    printf("Enter the number of roads: ");
    scanf("%d", &num_roads);

    printf("Enter the roads (source destination travel_time):\n");
    for (int i = 0; i < num_roads; i++) {
        int src, dest, travel_time;
        scanf("%d %d %d", &src, &dest, &travel_time);
        addRoad(src, dest, travel_time);
    }

    int source_city;
    printf("Enter the source city: ");
    scanf("%d", &source_city);

    dijkstra(source_city);

    return 0;
}
/*

### Explanation

1. *Data Structures*:
   - Road struct represents a road between two cities with a travel time.
   - City struct represents a city with a list of roads (adjacency list).
   - cities array stores all cities and their connected roads.
   - num_cities stores the total number of cities.

2. *Functions*:
   - addRoad: Adds a road to the adjacency list of a city.
   - minDistance: Finds the city with the minimum distance that has not been processed yet.
   - dijkstra: Implements Dijkstra's algorithm to find the shortest travel times from the source city.

3. *Main Function*:
   - Reads the number of cities and roads.
   - Reads the roads and builds the adjacency list.
   - Reads the source city and calls Dijkstra's algorithm to find and print the shortest travel times.

### Running the Program

1. Compile the code using a C compiler:
   bash
   gcc -o optimal_routes optimal_routes.c
   

2. Run the executable:
   bash
   ./optimal_routes
   

3. Input the number of cities, number of roads, details of each road (source, destination, travel time), and the source city.

4. The program will output the shortest travel times from the source city to all other cities.

### Example Input

Enter the number of cities: 5
Enter the number of roads: 6
Enter the roads (source destination travel_time):
0 1 10
0 2 3
1 2 1
2 1 4
1 3 2
2 3 8
Enter the source city: 0


### Example Output

City    Shortest Travel Time from City 0
0       0
1       7
2       3
3       9
4       2147483647


In this example, the shortest travel time from city 0 to city 4 is 2147483647 (INT_MAX), indicating that city 4 is not reachable from city 0. The program will print the shortest travel times for all cities connected to the source city.*/