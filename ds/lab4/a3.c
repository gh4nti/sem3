// Interleave two lists

int n1, n2;

    printf("Enter number of elements in List 1: ");
    scanf("%d", &n1);
    Node *list1 = createList(n1);

    printf("Enter number of elements in List 2: ");
    scanf("%d", &n2);
    Node *list2 = createList(n2);

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    Node *list3 = interleaveLists(list1, list2);

    printf("Interleaved List: ");
    printList(list3);

    freeList(list3);
    return 0;
