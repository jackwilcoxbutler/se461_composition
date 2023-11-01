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
size_t Stack <T>::size (void) const
{
return array_.size();
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
    if(is_empty()){
        throw std :: length_error("Stack is empty ");
    }else{
		// Dr. R: Just to be safe we should do: return array_[array_.size() - 1];
        return array_[0];
    }
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
    if(array_.size() > 0)
    {
        return false;
    }
    else
    { 
        return true;
    }
}
