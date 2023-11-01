// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// jwilcox//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void) : Base_Array<T>(N)
{
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr): Base_Array<T>(N)
{
    for(int i = 0; i < arr.size(); i++){
        this->set(i,arr[i]);
    }
}

//
// Fixed_Array
template <typename T, size_t N>
template <size_t M>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, M> & arr): Base_Array<T>(M)
{
    this = arr;
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill):Base_Array<T>(N,fill)
{
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
    int length = this->size();
	if(rhs.size() != length){
        throw std :: length_error("Arrays have different lengths");
    }
    for(int i = 0; i < length; i++){
        this->set(i,rhs[i]);
    }
    return *this;
}

//
// operator =
//

template <typename T, size_t N>
template <size_t M>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, M> & rhs)
{
    Fixed_Array<T,M> temp = Fixed_Array<T,M>();
    return *temp;

}
