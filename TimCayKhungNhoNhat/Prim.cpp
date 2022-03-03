void primMST(int graph[V][V]) {
       int parent[V]; // Lưu đỉnh cha của đỉnh V trong cây bao trùm nhỏ nhất
       int key[V];   
       bool mstSet[V];  // Đánh dấu các đỉnh đã được thêm vào tập các đỉnh đã xét

   for (int i = 0; i < V; i++)
      key[i] = INT_MAX, mstSet[i] = false;

   key[0] = 0; 
   parent[0] = -1;

   for (int count = 0; count < V-1; count++) {
      int u = minKey(key, mstSet);

      mstSet[u] = true;

    for (int v = 0; v < V; v++)
        if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
           parent[v]  = u, key[v] = graph[u][v];

    }
 }