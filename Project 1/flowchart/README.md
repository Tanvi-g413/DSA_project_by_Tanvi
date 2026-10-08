# Flowchart – Lab Equipment Return Tracker

```mermaid
flowchart TD
    A([START]) --> B[Initialize Head = NULL]
    B --> C[Display Menu]
    C --> D[Enter Choice]
    D --> E{Choice?}

    E -->|1| F[Enter Equipment Details]
    F --> G[Create New Node]
    G --> H[Insert Node]
    H --> C

    E -->|2| I[Traverse Linked List]
    I --> J[Display All Records]
    J --> C

    E -->|3| K[Enter Equipment ID]
    K --> L[Search Linked List]
    L --> M[Display Search Result]
    M --> C

    E -->|4| N[Enter Equipment ID]
    N --> O[Search Equipment]
    O --> P[Change Status to Returned]
    P --> C

    E -->|5| Q[Enter Equipment ID]
    Q --> R[Search Equipment]
    R --> S[Delete Node]
    S --> C

    E -->|6| T([STOP])
```
