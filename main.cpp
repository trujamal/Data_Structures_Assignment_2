/**
 * @author Jamal Rasool
 * @version 1.1
 * @brief This program is designed to go through and test all of the constructors / functions that are available in the
 * PhysVec header file and driver file.
 */

#include <iostream>
#include "PhysVec.h"

/**
 * Function Name: TestingPrintVecs()
 * Designed to test the printing of functions inside of the
 */

void TestingPrintVecs() {
    std :: cout << "Test One:" << std :: endl;
    std :: vector<int> MyVectorA {4,2,1,8,9,10};
    std :: vector<int> MyVectorB {1,2,5,24,19};
    try {
        PhysVec MyVectorObject;
        MyVectorObject.setPhysVec(MyVectorA);
        MyVectorObject.printVecs();
    }catch(std::exception e) {
        throw  e;
    }
    std :: cout << "\nTest One is Complete!" << std :: endl;
}

/**
 * Function Name: TestingConstructor
 *
 */

void TestingConstructor() {
    // use regular constructor
    std::vector<int> TestVector = {42,112,421};
    std :: cout << "\nTest Two:" << std :: endl;
    try {
        PhysVec myphysvec2(TestVector);
        myphysvec2.printVecs();
    }catch (std::exception e) {
        throw e;
    }
    std :: cout << "\nTest Two Complete!" << std :: endl;
}

/**
 *
 */

void TestingAddition() {

    std :: cout << "\nTest Three:" << std :: endl;

    std::vector<int> Vec {0,0,0,0,0};
    std::vector<int> Veca {1,1,1,1,1};
    std::vector<int> Vecb {2,2,2,2,2};
    std::vector<int> Vecc {3,3,3,3,3,3}; // Designed to check and see what it throws when the array size is out of bounds

    PhysVec BaseObject(Vec);
    PhysVec BaseOne(Veca);
    PhysVec BaseTwo(Vecb);
    PhysVec BaseThree(Vecc);

    // testing the overloading of the addition and the = operators with both vectors being the same size.
    BaseObject =  BaseOne + BaseTwo;
    BaseObject.printVecs();

    // Testing the overloading of addition when both of the vectors are not the same size;
    try {
        BaseObject = BaseOne + BaseThree;
        BaseObject.printVecs();
    }catch (std::exception e) {
        throw e;
    }
    std :: cout << "\nTest Three Complete!" << std :: endl;
}

/**
 * Function Name: TestingSimpleDotProduct
 *
 */

void TestingSimpleDotProduct() {
    std :: cout << "\nTest Four:" << std :: endl;

    std::vector<int> Set1 {5,8,13,16,21};
    std::vector<int> Set2 {4,11,15,24,28};
    PhysVec ObjectSet1(Set1);
    PhysVec ObjectSet2(Set2);

    //Testing Simple Dot Product
    try {
        int dotProduct = ObjectSet1.calculateDotProduct(ObjectSet2);
        std :: cout << "Dot product is " << dotProduct << std :: endl;
    }catch (std::exception e) {
        throw e;
    }

    std :: cout << "Test Four Complete!" << std :: endl;
}

/**
 * Function Name: TestingComplexDotProduct
 *
 */

void TestingComplexDotProduct() {
    std :: cout << "\nTest Five:" << std :: endl;

    std::vector<int> biggervec1 = {1,2,3,4,5};
    std::vector<int> biggervec2 = {-1,-2,-3,-4,-5};
    std::vector<int> biggervec3 {5,6,7,8,9,19,11,12};

    PhysVec mybigvec1(biggervec1);
    PhysVec mybigvec2(biggervec2);
    PhysVec mybigvec3(biggervec3);

    std :: cout << "Vector Values" << std :: endl;
    mybigvec1.printVecs();
    std :: cout << " | ";
    mybigvec2.printVecs();
    std :: cout << " | ";
    mybigvec3.printVecs();

// Testing original case where it will multiple the vector sizes that are the exact same size.
    int dotProduct = mybigvec2.calculateDotProduct(mybigvec1);
    std :: cout << std :: endl;
    std :: cout << "Dot product w/ same size is " << dotProduct;
// try unequal vectors in dot product
    try {
        dotProduct = mybigvec3.calculateDotProduct(mybigvec2);
        std :: cout << std :: endl;
        std :: cout << "Dot product w/o same size is " << dotProduct;
    }catch (std::invalid_argument e) {
        throw e;
    }
    std :: cout << "\nTest Five Complete!" << std :: endl;
}

/**
 * Function Name: TestingCopyConstructor
 *
 */

void TestingCopyConstructor() {
    std :: cout << "\nTest Six:" << std :: endl;
    //test copy constructor
    std::vector<int> biggervec2 = {-1,-2,-3,-4,-5};
    PhysVec sad(biggervec2);

    PhysVec happy(sad);
    std :: cout << "Expected: -1,-2,-3,-4,-5" << std :: endl;
    std :: cout << "Actual: ";
    happy.printVecs();

    std :: cout << "\nTest Six Complete!" << std :: endl;
}

/**
 * Funciton Name: main
 *
 * @return
 */

int main() {

    // Testing the PrintVecs Function
    TestingPrintVecs();
    // Default Constructor Test
    TestingConstructor();
    // Testing Addition
    TestingAddition();
    // Testing Simple Dot Product Without Negative Values
    TestingSimpleDotProduct();
    // Testing Dot Matrix with both Negative and Positive values
    TestingComplexDotProduct();
    // Testing Copy Constructor
    TestingCopyConstructor();

  return 0;
}
