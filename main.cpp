/**
* @author Jamal Rasool
* @version 1.1
* @brief This program is designed to go through and test all of the constructors / functions that are available in the
* PhysVec header file and driver file.
* @date January 28th, 2017
*/

#include <iostream>
#include "PhysVec.h"

/**
 * Function Name: TestingPrintVecs()
 * Designed to test the printing of functions inside of the PhysVec.cpp file; also by doing this we are also testing to
 * see if the setPhysVec function works as properly.
 */

void TestingPrintVecs() {
    std::cout << "Test One (Testing Printing Vectors):" << std::endl;
    std::vector<int> MyVectorA{4, 2, 1, 8, 9, 10};
    std::vector<int> MyVectorB{1, 2, 5, 24, 19};
    try {
        PhysVec MyVectorObject;
        MyVectorObject.setPhysVec(MyVectorA);
        MyVectorObject.printVecs();
    } catch (std::exception e) {
        throw e;
    }
    std::cout << "\nTest One is Complete!" << std::endl;
}

/**
 * Function Name: TestingConstructor
 * This function is designed to go through and test with a direct call to the constructor to place that vector within a
 * Physvec object without needing to call the setPhysVec function call.
 */

void TestingConstructor() {
    // use regular constructor
    std::vector<int> TestVector = {42, 112, 421};
    std::cout << "\nTest Two (Testing Constructor):" << std::endl;
    try {
        PhysVec myphysvec2(TestVector);
        myphysvec2.printVecs();
    } catch (std::exception e) {
        throw e;
    }
    std::cout << "\nTest Two Complete!" << std::endl;
}

/**
 * Function name: TestingAddition
 * Designed to go through and test the addition constructors within the PhysVec class, as designed it will scale down
 * the bigger vector size down to the smallest of what is being added together. This is to stop overflow / overloading
 * of the program.
 */

void TestingAddition() {

    std::cout << "\nTest Three (Testing Addition):" << std::endl;

    std::vector<int> Vec{0, 0, 0, 0, 0};
    std::vector<int> Veca{1, 1, 1, 1, 1};
    std::vector<int> Vecb{2, 2, 2, 2, 2};
    std::vector<int> Vecc{3, 3, 3, 3, 3,
                          3}; // Designed to check and see what it throws when the array size is out of bounds

    PhysVec BaseObject(Vec);
    PhysVec BaseOne(Veca);
    PhysVec BaseTwo(Vecb);
    PhysVec BaseThree(Vecc);

    // testing the overloading of the addition and the = operators with both vectors being the same size.
    BaseObject = BaseOne + BaseTwo;
    BaseObject.printVecs();

    // Testing the overloading of addition when both of the vectors are not the same size;
    try {
        BaseObject = BaseOne + BaseThree;
        BaseObject.printVecs();
    } catch (std::exception e) {
        throw e;
    }
    std::cout << "\nTest Three Complete!" << std::endl;
}

/**
 * Function Name: TestingSimpleDotProduct
 * Designed to go through and perform a simple dot product without the use of negative integers.
 */

void TestingSimpleDotProduct() {
    std::cout << "\nTest Four (Testing Simple Dot Product):" << std::endl;

    std::vector<int> Set1{5, 8, 13, 16, 21};
    std::vector<int> Set2{4, 11, 15, 24, 28};
    PhysVec ObjectSet1(Set1);
    PhysVec ObjectSet2(Set2);

    //Testing Simple Dot Product
    try {
        int dotProduct = ObjectSet1.calculateDotProduct(ObjectSet2); // Calculation
        std::cout << "Dot product is " << dotProduct << std::endl; // Returning values
    } catch (std::exception e) {
        throw e;
    }

    std::cout << "Test Four Complete!" << std::endl;
}

/**
 * Function Name: TestingComplexDotProduct
 * Function is designed to go through with positive and negative integers and first display the numbers that we will use
 * in the dot matrix then return the values of the Dot multiplication.
 */

void TestingComplexDotProduct() {
    std::cout << "\nTest Five (Testing Complex Dot Product):" << std::endl;

    std::vector<int> biggervec1 = {1, 2, 3, 4, 5};
    std::vector<int> biggervec2 = {-1, -2, -3, -4, -5};
    std::vector<int> biggervec3{5, 6, 7, 8, 9, 19, 11, 12};

    PhysVec mybigvec1(biggervec1);
    PhysVec mybigvec2(biggervec2);
    PhysVec mybigvec3(biggervec3);

    // Displaying the information inside of the vectors
    std::cout << "Vector Values" << std::endl;
    mybigvec1.printVecs();
    std::cout << " | ";
    mybigvec2.printVecs();
    std::cout << " | ";
    mybigvec3.printVecs();

    // Testing original case where it will multiple the vector sizes that are the exact same size.
    int dotProduct = mybigvec2.calculateDotProduct(mybigvec1);
    std::cout << std::endl;
    std::cout << "Dot product w/ same size is " << dotProduct;

    // try unequal vectors in dot product
    try {
        dotProduct = mybigvec3.calculateDotProduct(mybigvec1);
        std::cout << std::endl;
        std::cout << "Dot product w/o same size is " << dotProduct;
    } catch (std::invalid_argument e) {
        throw e;
    }
    std::cout << "\nTest Five Complete!" << std::endl;
}

/**
 * Function Name: TestingCopyConstructor
 * Designed to test and see if the copyconstructor copies the information from vector another. But first displaying the
 * information that is in the original vector, and then displaying the information that is in the new temporary vector
 * that we have created.
 */

void TestingCopyConstructor() {
    std::cout << "\nTest Six (Testing Copy Constructor):" << std::endl;
    //test copy constructor
    std::vector<int> biggervec2 = {-1, -2, -3, -4, -5};
    PhysVec sad(biggervec2);

    PhysVec happy(sad);
    std::cout << "Expected: -1,-2,-3,-4,-5" << std::endl;
    std::cout << "Actual: ";
    happy.printVecs();
    std::cout << "\nTest Six Complete!" << std::endl;
}
/**
 * Function Name: TestingGetVecConstructor
 * This function is designed to return a specific vector and also asign it to a temproary value, similar to the copy
 * constructor due to it returning an a_vec object.
 */
void TestingGetVecConstructor() {
    std::cout << "\nTest Seven (Testing Get Constructor):" << std::endl;
    std::vector<int> SampleVector = {2,1,3};
    try {
        PhysVec Test2(SampleVector);
        PhysVec CopyOfTest2 = PhysVec(Test2.get_a_vec_());

        std :: cout << "Original: ";
        Test2.printVecs();
        std :: cout << "\nResult: ";
        CopyOfTest2.printVecs();

    } catch (std :: exception e) {
        throw e;
    }

    std::cout << "\nTest Seven Complete!" << std::endl;
}

/**
 * Function Name: main
 * Designed to go through and run all of the functions of the program.
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
    // Testing get_vec Constructor
    TestingGetVecConstructor();

    return 0;
}
