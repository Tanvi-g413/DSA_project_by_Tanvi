# Flowchart – Lab Equipment Return Tracker

```mermaid
flowchart TD
    A([START]) --> B[Initialize Head = NULL]
    B --> C[/Display Menu/]
    C --> D[/Enter Choice/]
    D --> E{Choice?}

    E -->|1. Add Equipment| F[/Enter Equipment Details/]
    F --> G[Create New Node]
    G --> H[Insert Node]
    H --> C

    E -->|2. Display Equipment| I[Traverse Linked List]
    I --> J[/Display All Records/]
    J --> C

    E -->|3. Search Equipment| K[/Enter Equipment ID/]
    K --> L[Search Linked List]
    L --> M[/Display Search Result/]
    M --> C

    E -->|4. Update Status| N[/Enter Equipment ID/]
    N --> O[Search Equipment]
    O --> P[Change Status to Returned]
    P --> C

    E -->|5. Delete Equipment| Q[/Enter Equipment ID/]
    Q --> R[Search Equipment]
    R --> S[Delete Node]
    S --> C

    E -->|6. Exit| T([STOP])
