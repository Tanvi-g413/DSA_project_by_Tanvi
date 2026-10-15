# Flowchart – Lab Equipment Return Tracker Using Doubly Linked List, Stack, and Queue
'''mermaid
flowchart TD
    A([START]) --> B[Initialize Head = NULL and Tail = NULL, Stack and Queue]
    B --> C[/Display Menu/]
    C --> D[/Enter Choice/]
    D --> E{Choice?}

    E -->|1. Add Equipment| F[/Enter Equipment ID, Name and Quantity/]
    F --> G{Quantity Positive?}
    G -->|No| H[/Display Invalid Quantity/]
    H --> C
    G -->|Yes| I[Create New Node]
    I --> J[Insert Node into Doubly Linked List]
    J --> K[Update Previous and Next Pointers]
    K --> L[Push Add Action into Stack]
    L --> C

    E -->|2. Display Equipment| M{List Empty?}
    M -->|Yes| N[/Display No Records/]
    M -->|No| O[Traverse Doubly Linked List from Head to Tail]
    O --> P[/Display All Equipment Records/]
    N --> C
    P --> C

    E -->|3. Search Equipment| Q[/Enter Equipment ID/]
    Q --> R[Search Doubly Linked List]
    R --> S{Equipment Found?}
    S -->|Yes| T[/Display Equipment Details/]
    S -->|No| U[/Display Equipment Not Found/]
    T --> C
    U --> C

    E -->|4. Delete Equipment| V[/Enter Equipment ID/]
    V --> W[Search Node and Update Previous and Next Links]
    W --> X{Equipment Found?}
    X -->|Yes| Y[Delete Node and Update Head or Tail]
    Y --> Z[Push Delete Action into Stack]
    Z --> C
    X -->|No| AA[/Display Equipment Not Found/]
    AA --> C

    E -->|5. Add Return Request| AB[/Enter Equipment ID/]
    AB --> AC[Add Request to Queue]
    AC --> C

    E -->|6. Process Return Request| AD{Queue Empty?}
    AD -->|Yes| AE[/Display No Pending Requests/]
    AD -->|No| AF[Remove Oldest Request]
    AF --> AG[Push Processing Action into Stack]
    AG --> C
    AE --> C

    E -->|7. Display Return Requests| AH[Copy Queue and Display Pending Requests]
    AH --> C

    E -->|8. Display Activity History| AI[Copy Stack and Display Recent History]
    AI --> C

    E -->|9. Display Equipment Backward| AJ{List Empty?}
    AJ -->|Yes| AK[/Display No Records/]
    AJ -->|No| AL[Traverse Doubly Linked List from Tail to Head]
    AL --> AM[/Display Equipment in Reverse Order/]
    AK --> C
    AM --> C

    E -->|10. Exit| AN[Release Allocated Nodes]
    AN --> AO([STOP])

    E -->|Invalid Choice| AP[/Display Invalid Choice/]
    AP --> C
    '''
