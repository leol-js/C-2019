
#include <stdlib.h>

struct array_list {
    size_t size;
    void ** data;
};

struct array_list * array_list_create() {
    struct array_list *list = malloc(sizeof *list);
    if (list == NULL) {
        return NULL;
    }

    list->size = 0;
    list->data = calloc(4, sizeof(void *));
    if (list->data == NULL) {
        free(list);
        return NULL;
    }

    return list;
}

size_t array_list_getsizeof(struct array_list *list) {
    /* Returns the size of the internal array in memory */
    return sizeof(*list->data);
}

size_t array_list_getsize(struct array_list *list) {
    /* Returns the number of elements in the array_list */
    return list->size;
}

void array_list_clear(struct array_list *list) {
    /* Clears the internal array */
    list->size = 0;
    free(list->data);
    list->data = NULL;
}

void array_list_setdata(struct array_list *list, void ** data, int max, int clear_data) {
    /* Sets the internal array of the array_list */
    clear_data ? array_list_clear(list) : NULL;
    list->data = data;
    list->size = max;
}

void array_list_add(struct array_list *list, void *elem) {
    /* Adds one element of generic pointer type to the internal array */
    void ** new_data = realloc(list->data, array_list_getsizeof(list));
    if (list == NULL) {
        return NULL;
    }
    new_data[list->size] = elem;
    array_list_setdata(list, new_data, list->size + 1, 0);
}

void *array_list_get(struct array_list *list, int index) {
    /* Gets an member of the array at an index */
    return list->data[index];
}

void array_list_remove(struct array_list *list, int index, int freeit) {
    /* Removes one element at and index */
    if (index > list->size - 1)
        return;
    if (list->size == 1) {
        array_list_clear(list);
        return;
    }
    if (freeit)
        free(array_list_get(list, index));
    for ( int i = index; i < list->size; ++i ) {
        if (i == list->size - 1)
            list->data[i] = NULL;
        else
            list->data[i] = list->data[i + 1];
    }
    void ** new_data = realloc(list->data, array_list_getsizeof(list));
    --list->size;
    if (list == NULL) {
        return NULL;
    }
    array_list_setdata(list, new_data, list->size, 0);
}

void array_list_deallocate(struct array_list *list) {
    /* De-allocates the array_list from memory
    No usage of the array_list is allowed after this function call */
    if (list->data != NULL)
        free(list->data);
    free(list);
}

int array_list_getindex(struct array_list *list, void *elem) {
    /* Looks for elem in list and returns the index or -1 if not found */
    for(int i = 0; i < list->size; ++i)
        if (elem == array_list_get(list, i))
            return i;
    return -1;
}
