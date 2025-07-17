#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_MAP_SIZE 10

// Forward declaration for the struct to allow self-referential function pointer
typedef struct MyObject MyObject;

// Define the object type with three methods
struct MyObject {
    char name[32];
    const char* (*get_name)(MyObject* self);  // method to return object name
};


// Function to return the object's name
const char* get_object_name(MyObject* self) {
    return self->name;
}

// Define a simple hashmap entry
typedef struct {
    char key[32];
    MyObject* value;
} HashEntry;

// Define the hashmap
HashEntry hashmap[MAX_MAP_SIZE];
int hashmap_size = 0;

// Function to insert into hashmap
void put_in_map(const char* key, MyObject* value) {
    if (hashmap_size >= MAX_MAP_SIZE) {
        printf("Hashmap full!\n");
        return;
    }
    strcpy(hashmap[hashmap_size].key, key);
    hashmap[hashmap_size].value = value;
    hashmap_size++;
}

// Function to retrieve from hashmap
MyObject* get_from_map(const char* key) {
    for (int i = 0; i < hashmap_size; i++) {
        if (strcmp(hashmap[i].key, key) == 0) {
            return hashmap[i].value;
        }
    }
    return NULL;
}

int main() {
    // Seed the random number generator
    srand((unsigned int) time(NULL));

    // Create 3 objects and assign function pointers
    MyObject obj1 = {"Object1", get_object_name};
    MyObject obj2 = {"Object2", get_object_name};
    MyObject obj3 = {"Object3", get_object_name};

    // Store them in the hashmap
    put_in_map("one", &obj1);
    put_in_map("two", &obj2);
    put_in_map("three", &obj3);

    // Try to retrieve an existing entry
    MyObject* found = get_from_map("two");

    printf("Found object: %s\n", found->get_name(found));

    // Try to retrieve a non-existing entry
    MyObject* not_found = get_from_map("four");

    printf("Found object: %s\n", not_found->get_name(not_found));

    return 0;
}
