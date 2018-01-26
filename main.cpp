#include <iostream>
#include "PhysVec.h"
#include <vector>
using std::cout;
using std::endl;

// This main is used to test the physvec class.  It will provide
// vectors for the class to use in its calculation's.
//

int main() {

 // create some vectors - Note c++ 11 uniform initilization!
 std::vector<int> lhs = {3,2,1};
 std::vector<int> rhs = {1,2,3};
 std::vector<int> newrhs = {4,2,1};
 std::vector<int> newlhs = {1,2,5};
 std::vector<int> emptyvec = {0,0,0};

 // use simple constructor and set
 PhysVec myphysvec;
 myphysvec.setPhysVec(newlhs);
 myphysvec.printVecs();

 // use regular constructor
 PhysVec myphysvec2(newrhs);
 myphysvec2.printVecs();

 PhysVec myphysvec3(emptyvec);

 // test the overloading of the addition and the = operators
 myphysvec3 =  myphysvec2 + myphysvec;
 myphysvec3.printVecs();

 //test dot product
 int dotProduct = myphysvec2.calculateDotProduct(myphysvec3);
 cout << endl;
 cout << "Dot product is " << dotProduct << endl;

 //test copy constructor
 PhysVec myphysvec4(myphysvec2);
 cout << "myphysvec4 from copy constructor " << endl;
 myphysvec4.printVecs();

// try bigger vecs than 3
 std::vector<int> biggervec1 = {1,2,3,4,5};

 std::vector<int> biggervec2 = {-1,-2,-3,-4,-5};

 PhysVec mybigvec1(biggervec1);

 PhysVec mybigvec2(biggervec2);

 mybigvec1.printVecs();
 mybigvec2.printVecs();

 dotProduct = mybigvec2.calculateDotProduct(mybigvec1);
 cout << endl;
 cout << "Dot product is " << dotProduct << endl;

// try unequal vectors in dot product
 dotProduct = myphysvec2.calculateDotProduct(mybigvec1);

  return 0;
}