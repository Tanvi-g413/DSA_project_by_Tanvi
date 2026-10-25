# Flowchart - Kruskal's Algorithm

```mermaid
flowchart TD
    A([Start]) --> B[/Input number of villages and roads/]
    B --> C[/Enter road details with costs/]
    C --> D[Sort roads by ascending cost]
    D --> E[Initialize parent array and total cost]
    E --> F{More roads available?}
    F -- Yes --> G[Select minimum cost road]
    G --> H{Forms a cycle?}
    H -- Yes --> F
    H -- No --> I[Add road to MST]
    I --> J[Update total cost and selected count]
    J --> K{Selected V-1 roads?}
    K -- Yes --> L[Display selected roads and total cost]
    K -- No --> F
    F -- No --> L
    L --> M{Are V-1 roads selected?}
    M -- Yes --> N[All villages connected]
    M -- No --> O[Graph disconnected]
    N --> P([End])
    O --> P
