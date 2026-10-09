# Flowchart – Lab Equipment Return Tracker

```mermaid
flowchart TD
    A([START]) --> B[Initialize Head = NULL, Stack and Queue]
    B --> C[Display Menu]
    C --> D[Enter Choice]
    D --> E{Choice?}

    E -->|1| F[Enter Equipment Details]
    F --> G[Create New Node]
    G --> H{Duplicate ID?}
    H -->|Yes| I[Display ID Already Exists]
    I --> C
    H -->|No| J[Insert Node into Circular Doubly Linked List]
    J --> K[Push Add Action into Stack]
    K --> C

    E -->|2| L{List Empty?}
    L -->|Yes| M[Display No Records Found]
    L -->|No| N[Traverse List and Display Records]
    M --> C
    N --> C

    E -->|3| O[Enter Equipment ID]
    O --> P[Search Circular Doubly Linked List]
    P --> Q{Equipment Found?}
    Q -->|Yes| R[Display Equipment Details]
    Q -->|No| S[Display Equipment Not Found]
    R --> C
    S --> C

    E -->|4| T[Enter Equipment ID for Return]
    T --> U[Search Equipment]
    U --> V{Found and Not Returned?}
    V -->|Yes| W[Add ID to Return Queue]
    V -->|No| X[Display Error Message]
    W --> C
    X --> C

    E -->|5| Y{Queue Empty?}
    Y -->|Yes| Z[Display No Pending Requests]
    Y -->|No| AA[Remove First Request from Queue]
    AA --> AB[Search Equipment]
    AB --> AC{Equipment Available?}
    AC -->|No| AD[Cancel or Skip Request]
    AC -->|Yes| AE[Update Status to Returned]
    AE --> AF[Push Return Action into Stack]
    AD --> C
    AF --> C
    Z --> C

    E -->|6| AG[Enter Equipment ID to Delete]
    AG --> AH[Search Equipment]
    AH --> AI{Equipment Found?}
    AI -->|No| AJ[Display Equipment Not Found]
    AI -->|Yes| AK[Update Next and Previous Links]
    AK --> AL[Delete Node and Push Action into Stack]
    AJ --> C
    AL --> C

    E -->|7| AM[Copy Stack]
    AM --> AN{Stack Empty?}
    AN -->|Yes| AO[Display No Action History]
    AN -->|No| AP[Display Actions Latest First]
    AO --> C
    AP --> C

    E -->|8| AQ[Copy Queue]
    AQ --> AR{Queue Empty?}
    AR -->|Yes| AS[Display Queue Empty]
    AR -->|No| AT[Display Pending Return Requests]
    AS --> C
    AT --> C

    E -->|9| AU[Free Linked List Memory]
    AU --> AV([STOP])

    E -->|Invalid| AW[Display Invalid Choice]
    AW --> C
```
