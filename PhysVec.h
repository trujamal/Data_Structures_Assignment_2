//
// Created by Greg LaKomski on 1/12/18.
//

#ifndef PHYSVEC_PHYSVEC_H
#define PHYSVEC_PHYSVEC_H

#include<iostream>
#include<vector>
// could have put using std::vector; but better to just practice being explicit!

// Class PhysVec creates a physical vector and provides a true physical add
// overload as well as a function to calculate a dot product

class PhysVec {

public:

    PhysVec(); // default constructor

    // Constructor that takes a vector to be turned into a PhysVec
    PhysVec(const std::vector<int> & input_vec);

    // setter for a PhysVec - turns a normal vec into a PhysVec
    void setPhysVec(const std::vector<int> & input_vec) ;

  // getters for a PhysVec - turns a PhysVec into a normal vec
    std::vector<int> &get_a_vec_();

    // calculate the dot product of the two Physvecs
    int calculateDotProduct(const PhysVec & rhs) const;

    // overload the copy assignment operator
    PhysVec &operator= (const PhysVec  & rhs);

    // overload the copy constructor
    PhysVec(const PhysVec & rhs);

    // overload the "+" operator for the two PhysVecs adds two PhysVecs correctly - returns temp PhysVec
    PhysVec operator+ (const PhysVec  & rhs) const;


    // utility functions for a PhysVec
    void printVecs() const ;

private:
    std::vector<int>  a_vec_;


};

#endif //PHYSVEC_PHYSVEC_H