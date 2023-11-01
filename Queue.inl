// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// jwilcox
//
// size
//
template <typename T>
inline
size_t Queue <T>::size (void) const
{
    return array_.size();
}

//
// is_empty
//
template <typename T>
inline
bool Queue <T>::is_empty (void) const
{
    return (array_.size() > 0) ? false : true ;
}

//
// head
//
template <typename T>
inline
T Queue <T>::head (void) const
{
    if(is_empty()){
        throw std :: length_error("Can not pop off an empty stack");        
    }

    return array_[size() - 1];
}

//
// tail
//
template <typename T>
inline
T Queue <T>::tail (void) const
{
     if(is_empty()){
        throw std :: length_error("Can not pop off an empty stack");        
    }

    return array_[0];
}