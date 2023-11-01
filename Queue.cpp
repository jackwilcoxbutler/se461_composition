// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// jwilcox
//
// Queue
//
template <typename T>
Queue <T>::Queue (void): array_(Array<T>())
{
}

//
// Queue
//
template <typename T>
Queue <T>::Queue (const Queue & queue) : array_(Array<T>())
{
    array_ = queue.array_;
    if(!is_empty()){
        head_ = array_[array_.size() - 1];
        tail_ = array_[0];
    }
}

//
// ~Queue
//
template <typename T>
Queue <T>::~Queue (void)
{

}

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue (T element)
{
    array_.resize(array_.size() + 1);

    array_[array_.size() - 1] = element;

    if(!is_empty()){
        head_ = array_[array_.size() - 1];
        tail_ = array_[0];
    }
}

//
// dequeue
//
template <typename T>
T Queue <T>::dequeue (void)
{
    if(is_empty()){
        throw std :: length_error("Can not pop off an empty stack");        
    }
    T temp = array_[0];
    for(int i = 0; i < array_.size() - 1; i++){
        array_[i] = array_[i + 1];
    }

    //resize array 
    array_.resize(array_.size() - 1);

    if(!is_empty()){
        head_ = array_[array_.size() - 1];
        tail_ = array_[0];
    }
    
    return temp;
}

//
// operator =
//
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{    
    array_ = rhs.array_;
    if(!is_empty()){
        head_ = array_[array_.size() - 1];
        tail_ = array_[0];
    }
    return * this;
}

//
// clear
//
template <typename T>
void Queue <T>::clear (void)
{
    array_.resize(0);
        head_ = array_[0];
        tail_ = array_[0];
    
}
