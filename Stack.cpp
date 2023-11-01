// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// jwilcox
//
// Stack
//
template <typename T>
Stack <T>::Stack (void) : array_(Array<T>())
{
}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack) : array_(Array<T>())
{
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{

}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    

    array_.resize(array_.size() + 1);

    for(int i = array_.size() - 1; i >= 1; i--){
       array_[i] = array_[i -1];
    }

    array_[0] = element;
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    if(is_empty()){
        throw std :: length_error("Can not pop off an empty stack");
    }else if(array_.size() == 1){
        return;
    }
    
    for(int i = 0; i <= (array_.size() - 2); i++){
        array_[i] = array_[i+1];
    }

    if(array_.size() >= 10){
        //remove empty array_ spot if array_ is bigger than 10 to save memory
        array_.resize(array_.size());
    }
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    if(rhs.is_empty()){
        clear();
    }else{
        if(rhs.size() > array_.max_size()){
            array_.resize(rhs.size());
        }
        array_ = rhs.array_;
    }
    return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    if(!is_empty()){
       array_.resize(0);
    }
}
