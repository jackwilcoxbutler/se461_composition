
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// jwilcox
#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array <T>::Array (void): Base_Array<T>()
{
}

//
//Array (size_t length)
//
template <typename T>
Array <T>::Array (size_t length): Base_Array<T>(length)
{
    
}

//
//Array (size_t length, T fill)
//
template <typename T>
Array <T>::Array (size_t length, T fill): Base_Array<T>(length, fill)
{
   
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array):Base_Array<T>(array)
{
    
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
        resize(rhs.max_size());
        for(int i = 0; i < rhs.max_size();i++){
            this->data_[i] = rhs.data_[i];
        }
		// Dr. R: We still need to copy over ALL the attributes of rhs into this!
        //FIXED: resize to rhs max size and then copy through all elements
        return *this;
}


//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
    if(new_size < this->max_size_){
        this->cur_size_ = new_size;
    }else if(new_size > this->max_size_){//case 3
        T * temp = new T[new_size];
        for(int i = 0; i < this->cur_size_; i++){
            temp[i] = this->data_[i];
        }

        //delete the old data array and create a new one with the new size
        delete [] this->data_;
        this->data_ = new T[new_size];
        //fill new array up to index of size of old array
        for(int i = 0; i < this->cur_size_; i++){
            this->data_[i] = temp[i];
        }

        this->cur_size_ = new_size;
        this->max_size_ = new_size;

        delete [] temp;
    }
}

