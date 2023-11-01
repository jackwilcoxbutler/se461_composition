#include "Base_Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Base_Array
//
template <typename T>
Base_Array <T>::Base_Array (void): cur_size_(0), max_size_(10), data_(nullptr)
{
    data_ = new T [max_size_];
}

//
// Array (size_t)
//
template <typename T>
Base_Array <T>::Base_Array (size_t length): cur_size_(length),max_size_(10), data_(nullptr)
{
    if(length > 0){
        if(length > 10){
            max_size_ = length;
        }
        cur_size_ = length;
        data_ = new T [max_size_];
    }
}

//
// Base_Array (size_t, char)
//
template <typename T>
Base_Array <T>::Base_Array (size_t length, T fill): cur_size_(length), max_size_(10), data_(nullptr)
{
    if(length > 0){
        if(length > 10){
            max_size_ = length;
        }
	    cur_size_ = length;
        data_ = new T [max_size_];
	
        this->fill(fill);
    }
}

//
// Base_Array (const Base_Array &)
//
template <typename T>
Base_Array <T>::Base_Array (const Base_Array & array)
{
    max_size_ = array.max_size_;
    cur_size_ = array.cur_size_;
    data_ = new T[max_size_];
	
	// Dr. R: Don't we need to "initialize" the size of this->data_ here first?
    //FIXED: initialize data to the max size of the first array
    for(int i=0; i< array.cur_size_; i++){
        data_[i] = array.data_[i];
    }
}

//
// ~Array
//
template <typename T>
Base_Array <T>::~Base_Array (void)
{
    if(data_ != nullptr){
        delete [] data_;
    }
}

//
// operator []
//
template <typename T>
T & Base_Array <T>::operator [] (size_t index)
{
    if(index >= max_size_){
        throw std :: out_of_range("index is out of range - []");
    }else{
        return data_[index];
    }
}

//
// operator [] 
//
template <typename T>
const T & Base_Array <T>::operator [] (size_t index) const
{
    if(index >= max_size_){
        throw std :: out_of_range("index is out of range - const []");
    }else{
    return data_[index];
    }
}

//
// get
//
template <typename T>
T Base_Array <T>::get (size_t index) const
{
    if(index >= max_size_){
        throw std :: out_of_range("index is out of range - get");
    }
    return data_[index];
}

//
// set
//
template <typename T>
void Base_Array <T>::set (size_t index, T value)
{
    if(index >= cur_size_){
        throw std :: out_of_range("index is out of range - set");
    }
    data_[index] = value;
}

//
// find (char)
//
template  <typename T>
int Base_Array <T>::find (T value) const
{
    return find(value, 0);
}

//
// find (char, size_t) 
//
template <typename T>
int Base_Array <T>::find (T val, size_t start) const
{
    if(start >= cur_size_ || start < 0){
        return -1;
    }
    for(int i = start; i < cur_size_; i++){
        if(data_[i] == val){
            return i;
        }
    }
    return -1;
}

//
// operator ==
//
template <typename T>
bool Base_Array <T>::operator == (const Base_Array & rhs) const
{
    if(rhs.cur_size_ != cur_size_){
        return false;
    }
    for(int i = 0; i < cur_size_; i++){
        if(data_[i] != rhs.data_[i]){
            return false;
        }
    }
    return true;
}

//
// operator !=
//
template <typename T>
bool Base_Array <T>::operator != (const Base_Array & rhs) const
{
    return !(*this == rhs);
}

//
// fill
//
template <typename T>
void Base_Array <T>::fill (T value)
{
    for(int i = 0; i < max_size_; i++){
        data_[i] = value;
    }
}