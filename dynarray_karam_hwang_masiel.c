//libraries included
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//dynamic array struct definition
struct dynArray {

    void** data;
    int size;
    int capacity;

};

//student struct definition
struct student {

    char* name;
    int points;

};

//global variable for dynamic array
struct dynArray* D;

//function prototypes
void add(void*);
void* get(int);
void set(void*, int);
void insert(void*, int);
void delete(int);
void init(int);
void cleanup();
void _resize(int);
void test();
void disp();

//main function
int main() {

    D = malloc(sizeof(struct dynArray)); //allocate dynamic memory
    assert(D);
    init(4);
    test();
    cleanup();
    disp();
    free(D);

    return 0;

}

void add(void* new_student) {

    if (D->size == D->capacity) {
        _resize(D->capacity*2); //if there is no more room in array, double it's capacity
    }
    
    D->data[D->size] = new_student; //in last element of array, insert new student
    D->size++; //increment size of array

}

void* get(int index) {

    assert(index >= 0); //make sure index of array exists
    assert(index < D->size);
    
    return D->data[index]; //return specified element of array

}
void set(void* new_student, int index) {

    assert(index >= 0); //make sure index of array exists
    assert(index < D->size);
    D->data[index] = new_student; //set specified element of array

}

void insert(void* new_student, int index) {

    assert(index >= 0); //make sure index of array exists
    assert(index < D->size);

    int i = 0;

    if (D->size == D->capacity) {
        _resize(D->capacity*2); //if there is no more room in array, double it's capacity
    }

    for (i = D->size; i > index; i--) {
        D->data[i] = D->data[i - 1]; //for all elements after the element inserted, shift to the right one spot to make room for new student
    }

    D->data[index] = new_student; //insert new student in appropriate position
    D->size++; //increment size of array

}

void delete(int index) {

    assert(index >= 0); //make sure index of array exists
    assert(index < D->size);

    int i = 0;

    for (i = index + 1; i < D->size; i++) {
        D->data[i - 1] = D->data[i]; //for all elements after the element deleted, shift to the left one spot to fill in space created by deleted element
    }

    D->size--; //decrement size of array

}

void init(int c) {

    assert(c);
    D->capacity = c; //change capacity of array
    D->size = 0;
    D->data = malloc(D->capacity * sizeof(void*)); //allocate dynamic memory

}

void cleanup() { //deletes all data and sets size and capacity of array to zero

    assert(D->data);
    free(D->data);
    D->data = NULL;
    D->size = 0;
    D->capacity = 0;

}

void _resize(int c) {

    int i = 0;

    void** newdata = malloc(c * sizeof(void*)); //allocate dynamic memory
    assert(newdata);
    D->capacity = c; //change capacity of array

    for (i = 0; i < D->size; i++) {
        newdata[i] = D->data[i]; //move values from old array into new array
    }

    free(D->data); //free old array
    D->data = newdata;

}

void test() {

    disp();

    //create students to be added into array
    struct student student0;
    struct student student1;
    struct student student2;
    struct student student3;
    struct student student4;
    struct student student5;
    struct student student6;
    struct student student7;
    struct student student8;
    struct student student9;
    struct student student10;
    student0.name = "Joseph";
    student0.points = 100;
    student1.name = "Bob";
    student1.points = 50;
    student2.name = "Sam";
    student2.points = 0;
    student3.name = "Sally";
    student3.points = 80;
    student4.name = "George";
    student4.points = 75;
    student5.name = "Riley";
    student5.points = 105;
    student6.name = "William";
    student6.points = 99;
    student7.name = "Paul";
    student7.points = 80;
    student8.name = "Brad";
    student8.points = 75;
    student9.name = "Doug";
    student9.points = 60;

    //test various functions
    add(&student0);
    add(&student1);
    add(&student2);
    disp();

    add(&student3);
    disp();

    add(&student4);
    add(&student5);
    disp();

    insert(&student6, 1);
    disp();

    insert(&student7, 3);
    disp();

    insert(&student8, 5);
    disp();

    add(&student9);
    disp();

    delete(0);
    disp();

}

void disp() {

    int i = 0;

    for (i = 0; i < D->size; i++) {
        struct student* temp = D->data[i]; //create temporary student struct and fill it with data from current element
        printf("Name: %s\n", temp->name); //print student's name
        printf("Points: %d\n", temp->points); //print student's points
    }

    printf("Capacity = %d, Size = %d\n", D->capacity, D->size); //print current capacity and size of array

}