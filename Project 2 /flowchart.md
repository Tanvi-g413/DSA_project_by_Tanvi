flowchart TD
    A([START]) --> B[Create expression tree for A+B times C]
    B --> C[Call postorder root]
    C --> D{Is root NULL?}
    D -- Yes --> E[Return to caller]
    D -- No --> F[Traverse left subtree]
    F --> G[Traverse right subtree]
    G --> H[Print root data]
    H --> E
    E -. Recursive calls complete .-> I[Display A B + C *]
    I --> J[Delete tree and free memory]
    J --> K([STOP])
