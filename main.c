#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAXV 100

typedef struct {
    int source, destination, weight, index;
} Edge;

void printPath(int path[], int len, int cost, const char *label) {
    printf("%s", label);
    for (int i = 0; i < len; i++) {
        printf("%d", path[i]);
        if (i < len - 1) printf(" -> ");
    }
    printf(" (Cost: %d)\n", cost);
}

void dijkstra(int n, int graph[MAXV][MAXV], int src, int dst, const char *label) {
    // Dijkstra: dist[] = best known cost from source, visited[] = finished vertices
    int dist[MAXV], parent[MAXV];
    bool visited[MAXV];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = false;
    }
    dist[src] = 0;

    for (int i = 0; i < n; i++) {
        // pick the unvisited vertex with the smallest distance
        int u = -1, best = INT_MAX;
        for (int j = 0; j < n; j++)
            if (!visited[j] && dist[j] < best) { best = dist[j]; u = j; }
        if (u == -1) break;
        visited[u] = true;

        // relax all edges going out of u
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !visited[v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // destination unreachable
    if (dist[dst] == INT_MAX) {
        printf("%sNot Possible\n", label);
        return;
    }

    // build the path backwards using parent[], then reverse it
    int path[MAXV], len = 0;
    for (int v = dst; v != -1; v = parent[v]) path[len++] = v;
    for (int i = 0; i < len / 2; i++) {
        int t = path[i]; path[i] = path[len - 1 - i]; path[len - 1 - i] = t;
    }
    printPath(path, len, dist[dst], label);
}

bool dfs(int n, int tree[MAXV][MAXV], int u, int dst, bool seen[], int path[], int *len) {
    seen[u] = true;
    path[(*len)++] = u;
    if (u == dst) return true;
    for (int v = 0; v < n; v++) {
        if (tree[u][v] != 0 && !seen[v])
            if (dfs(n, tree, v, dst, seen, path, len)) return true;
    }
    (*len)--;
    return false;
}

void printTreePath(int n, int tree[MAXV][MAXV], int src, int dst, const char *label) {
    bool seen[MAXV] = {false};
    int path[MAXV], len = 0;

    if (!dfs(n, tree, src, dst, seen, path, &len)) {
        printf("%sNot Possible\n", label);
        return;
    }
    int cost = 0;
    for (int i = 0; i + 1 < len; i++) cost += tree[path[i]][path[i + 1]];
    printPath(path, len, cost, label);
}

void primMST(int n, int graph[MAXV][MAXV], int tree[MAXV][MAXV]) {
    // Prim: minCost[] = cheapest edge connecting a vertex to the tree
    int parent[MAXV], minCost[MAXV];
    bool included[MAXV];

    for (int i = 0; i < n; i++) {
        parent[i] = -1;
        minCost[i] = INT_MAX;
        included[i] = false;
        for (int j = 0; j < n; j++) tree[i][j] = 0;
    }
    minCost[0] = 0;

    for (int i = 0; i < n; i++) {
        // pick the vertex outside the tree with the smallest minCost
        int u = -1, best = INT_MAX;
        for (int j = 0; j < n; j++)
            if (!included[j] && minCost[j] < best) { best = minCost[j]; u = j; }
        if (u == -1) break;              // graph is disconnected
        included[u] = true;

        // update cheapest edge for the neighbors of u
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !included[v] && graph[u][v] < minCost[v]) {
                minCost[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // store the chosen edges in the tree matrix
    for (int v = 1; v < n; v++) {
        if (parent[v] != -1) {
            tree[v][parent[v]] = graph[v][parent[v]];
            tree[parent[v]][v] = graph[v][parent[v]];
        }
    }
}

// Kruskal uses Union-Find to detect cycles
int findRoot(int parent[], int v) {
    if (parent[v] != v) parent[v] = findRoot(parent, parent[v]);
    return parent[v];
}

void unionSets(int parent[], int rank[], int a, int b) {
    int ra = findRoot(parent, a), rb = findRoot(parent, b);
    if (ra == rb) return;
    if (rank[ra] < rank[rb]) parent[ra] = rb;
    else if (rank[ra] > rank[rb]) parent[rb] = ra;
    else { parent[rb] = ra; rank[ra]++; }
}

int compareEdges(const void *a, const void *b) {
    const Edge *e1 = a, *e2 = b;
    if (e1->weight != e2->weight) return e1->weight - e2->weight;
    return e1->index - e2->index;        // keep input order on ties
}

void kruskalMST(int n, int m, Edge edges[], int tree[MAXV][MAXV]) {
    int parent[MAXV], rank[MAXV];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
        for (int j = 0; j < n; j++) tree[i][j] = 0;
    }

    // sort edges by weight
    qsort(edges, m, sizeof(Edge), compareEdges);

    int selected = 0;
    for (int i = 0; i < m && selected < n - 1; i++) {
        Edge e = edges[i];
        // take the edge only if it does not form a cycle
        if (findRoot(parent, e.source) != findRoot(parent, e.destination)) {
            tree[e.source][e.destination] = e.weight;
            tree[e.destination][e.source] = e.weight;
            unionSets(parent, rank, e.source, e.destination);
            selected++;
        }
    }
}

void runAll(int n, int m, Edge edges[], int graph[MAXV][MAXV], int src, int dst, bool updated) {
    int tree[MAXV][MAXV];

    dijkstra(n, graph, src, dst, updated ? "Updated Shortest Path: " : "Shortest Path: ");

    kruskalMST(n, m, edges, tree);
    printTreePath(n, tree, src, dst, updated ? "Updated Kruskal Path: " : "Kruskal Path: ");

    primMST(n, graph, tree);
    printTreePath(n, tree, src, dst, updated ? "Updated Prim Path: " : "Prim Path: ");
}

int main(void) {
    FILE *file = fopen("graph.txt", "r");
    if (file == NULL) {
        printf("Could not open graph.txt\n");
        return 1;
    }

    int n, m;
    fscanf(file, "%d %d", &n, &m);

    Edge *edges = malloc(m * sizeof(Edge));
    static int graph[MAXV][MAXV];

    for (int i = 0; i < m; i++) {
        fscanf(file, "%d %d %d", &edges[i].source, &edges[i].destination, &edges[i].weight);
        edges[i].index = i;
        graph[edges[i].source][edges[i].destination] = edges[i].weight;
        graph[edges[i].destination][edges[i].source] = edges[i].weight;
    }

    int src, dst, remU, remV;
    fscanf(file, "%d %d", &src, &dst);
    fscanf(file, "%d %d", &remU, &remV);
    fclose(file);

    runAll(n, m, edges, graph, src, dst, false);

    // Edge removal: delete the edge in both directions from the matrix
    printf("After Removing Edge (%d,%d):\n", remU, remV);
    graph[remU][remV] = 0;
    graph[remV][remU] = 0;

    // also remove it from the edge list used by Kruskal
    int newM = 0;
    Edge *newEdges = malloc(m * sizeof(Edge));
    for (int i = 0; i < m; i++) {
        bool removed = (edges[i].source == remU && edges[i].destination == remV) ||
                       (edges[i].source == remV && edges[i].destination == remU);
        if (!removed) newEdges[newM++] = edges[i];
    }
    for (int i = 0; i < newM; i++) newEdges[i].index = i;

    runAll(n, newM, newEdges, graph, src, dst, true);

    free(edges);
    free(newEdges);
    return 0;
}
