/**
 * Purpose of the program is to use to the PhysVec class and implement the functions that are given
 * @author Jamal Rasool, Gese Rocha, John Daloni, Fredy Martinez
 * @version 1.1
 * @date 1/25/18
 * @
 */



#include <iostream>
#include <vector>
#include "PhysVec.h"

/**
 * Function Name: PhysVec
 * Declaring the default constructor, typically will be empty.
 */
PhysVec::PhysVec(){
}

/**
 * Function Name: PhyscVec [With parameters]
 * Declaring the default constructor, typically will be empty.
 * @param input_vec this parameter is designed to allow for the program to pass through vectors in order to place it
 * into the PhysVec Object.
 */
PhysVec::PhysVec(const std::vector<int> & input_vec) : a_vec_(input_vec) {
}

/**
 * Function Name: PhysVec (passing through a PhysVec Object)
 * overload the copy constructor
 * @param rhs this parameter is designed to pass through a PhysVec object and to go through and copy it over to a new
 * PhyscVec object.
 */

PhysVec::PhysVec(const PhysVec & rhs)  {
    try {
        this->a_vec_ = rhs.a_vec_; // setting the temporary "this" to the rhs object that was passed through.
    }catch  (int k){
        throw "Program has critically failed.";
    }
}

/**
 * Function Name: operator+
 * Designed to go through and handle the addition between two vectors together with the two vectors generating a third
 * vector.
 * @param rhs is designed to pass through a PhysVec Object
 * @return the operator+ function will return the temporary third vector back to be read using the printVecs() function
 * call.
 */
PhysVec PhysVec :: operator+ (const PhysVec  & rhs) const {

    std:: vector <int> :: const_iterator a; // Setting up the default constant iterator that can't be modified
    std :: vector <int> :: const_iterator b;
    std :: vector <int> :: iterator c;

    a = rhs.a_vec_.begin();
    b = this->a_vec_.begin();

    std :: vector<int> t;

    int size = this->a_vec_.size();

    t.resize(size);
    c = t.begin();

    for(c; c!= t.end(); ++c) {
        *c = *a + *b;

        ++b;
        ++a;
    }

    PhysVec temporary_object(t);
    return temporary_object;
}
/**
 * Function Name: setPhysVec
 * This function is to act as a setter for a PhysVec. It is used with the default constructor which creates a non
 * const PhysVec Object.
 * @param input_vec this parameter is designed to allow for the program to pass through vectors in order to place it
 * into the PhysVec Object.
 */

void PhysVec::setPhysVec(const std::vector<int> & input_vec) {
    a_vec_ = input_vec; // setting the private member variable of PhysVec to the passed through vector.
}

/**
 * Function Name: get_a_vec()
 * This function is designed to go through and return the vector that is currently being referenced.
 * @return will return a vector.
 */

std::vector<int> &PhysVec :: get_a_vec_() {
    return a_vec_;
}

/**
 * Function Name: calculateDotProduct()
 * This function is designed to calculate the dot product of the two Physvecs, by first setting a product or total
 * variable that will hold the total of multiplying each of the indexes of the vectors together and holding it in the
 * product variable.
 * @param rhs This parameter is designed to pass through the PhysVec object to be broken down into the vector to be used
 * for calculating the dot product.
 * @return This function was designed to return the total product of what the dot multiplication would be.
 */

int PhysVec::calculateDotProduct(const PhysVec & rhs) const {
    int product = 0;

    /*  Working Solution Before 2:32 PM on Friday, January 26
     *  1 2 5 4 2 1 5 4 6
     *  Dot product is 34
     *  Dot product is -55
     *  for (int i = 0; i <= rhs.a_vec_.size() -1;i ++) {
        product += rhs.a_vec_[i] * this->a_vec_[i];
    }
     */

    std :: vector<int> :: const_iterator DefaultIterator;
    std :: vector<int> :: const_iterator b;

    b = this->a_vec_.begin();


    // this is the {4,2,1}
    // rhs is the {5,4,6}

    for(DefaultIterator = rhs.a_vec_.begin(); DefaultIterator != rhs.a_vec_.end(); ++DefaultIterator) {

        product += *DefaultIterator * *b;
        ++b;


    }

    return product;
}

/**
 * Function Name: printVecs
 * This function was designed to print out the vectors content all in one line. This process is accomplished by
 * iterating between the vector list and returning said elements that were apart of it.
 */

void PhysVec::printVecs() const {

    for(auto lhs = this->a_vec_.begin(); lhs != this->a_vec_.end(); ++lhs)
    {
        std :: cout.flush() << " " << *lhs;
    }}

/**
 * Function Name: operator=
 * This function was designed ot handle the = sign operator by going through and iterating through the vector equation
 * then going through and setting the temporary iterator lhs to be increased each time, to essentially return the final
 * value of what the vector addition would be equivalent to.
 * @param rhs this parameter is designed to pass through a PhysVec object and to go through and copy it over to a new
 * PhyscVec object.
 * @return returns the value that the vector arithmetic would have.
 */

PhysVec &PhysVec::operator=(const PhysVec &rhs) {
    if(this != &rhs) {
        std :: vector<int> :: const_iterator defaultiterator;
        std :: vector<int> :: iterator lhs;

        lhs = this->a_vec_.begin();

        for(defaultiterator = rhs.a_vec_.begin(); defaultiterator != rhs.a_vec_.end(); ++defaultiterator) {
            *lhs = *defaultiterator;
            lhs++;
        }
        /*
         * Original function
         * copy(rhs.a_vec_.begin(), rhs.a_vec_.end(), this->a_vec_.begin());
         */
    }
    return *this;
}





