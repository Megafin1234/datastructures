int dlist_move_to_index(dlist_t *l, int from_index, int to_index) {
    if (from_index < 0 || to_index < 0)
        return 0;

    // Find the node at the from_index
    node_t *from_node = l->right;
    int i;
    for (i = 0; i < from_index; i++) {
        from_node = from_node->right;
        if (from_node == l) {
            return 0;
        }
    }

    // Remove the node from the list
    from_node->left->right = from_node->right;
    from_node->right->left = from_node->left;

    // Insert the node at the to_index
    node_t *to_node = l->right;
    for (i = 0; i < to_index; i++) {
        to_node = to_node->right;
        if (to_node == l) {
            return 0;
        }
    }
    from_node->left = to_node->left;
    from_node->right = to_node;
    to_node->left->right = from_node;
    to_node->left = from_node;

    return 1;
}
int dlist_update_value(dlist_t *l, int index, void *new_value) {
    if (index < 0)
        return 0;

    node_t *current_node = l->right;
    int i;
    for (i = 0; i < index; i++) {
        current_node = current_node->right;
        if (current_node == l) {
            return 0;
        }
    }

    memcpy(current_node->element, new_value, *((int *)l->element));
    return 1;
}
int dlist_swap(dlist_t *l, int index1, int index2) {
    if (index1 < 0 || index2 < 0)
        return 0;

    // Find the nodes at the given indexes
    node_t *node1 = l->right;
    int i;
    for (i = 0; i < index1; i++) {
        node1 = node1->right;
        if (node1 == l) {
            return 0;
        }
    }
    node_t *node2 = l->right;
    for (i = 0; i < index2; i++) {
        node2 = node2->right;
        if (node2 == l) {
            return 0;
        }
    }

    // Swap the elements
    void *temp_element = node1->element;
    node1->element = node2->element;
    node2->element = temp_element;

    return 1;
}
