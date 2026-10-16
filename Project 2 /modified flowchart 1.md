flowchart TD

    A([START]) --> B[Create expression tree for A+B times C]
    B --> C[Call preorder root]
    C --> D{Is root NULL?}
    D -- No --> E[Print root data]
    E --> F[Traverse left subtree]
    F --> G[Traverse right subtree]
    D -- Yes --> H[Return]
    G --> H

    H --> I[Call inorder root]
    I --> J{Is root NULL?}
    J -- No --> K[Traverse left subtree]
    K --> L[Print root data]
    L --> M[Traverse right subtree]
    J -- Yes --> N[Return]
    M --> N

    N --> O[Call postorder root]
    O --> P{Is root NULL?}
    P -- No --> Q[Traverse left subtree]
    Q --> R[Traverse right subtree]
    R --> S[Print root data]
    P -- Yes --> T[Return]
    S --> T

    T --> U[Display all traversal results]
    U --> V[Delete tree and free memory]
    V --> W([STOP])
