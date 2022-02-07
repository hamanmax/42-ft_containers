#ifndef ITERATOR_HPP
#define ITERATOR_HPP

struct InputIteratorTag{};

struct OutputIteratorTag{};

struct ForwardIteratorTag : public InputIteratorTag {};

struct BidirectionalIteratorTag : public ForwardIteratorTag {};

struct RandomAccessIteratorTag : public BidirectionalIteratorTag {};

template<	class Category,
			class T,
			class Distance = ptrdiff_t,
			class Pointer = T*,
			class Reference = T&
		>
class Iterator{
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
};

template<	class Category,
			class T,
			class Distance = ptrdiff_t,
			class Pointer = T*,
			class Reference = T&
		>
class VectorIterator : public Iterator<Category,T>
{
	public:
	typedef typename T::value_type		value_type;
	typedef typename T::pointer			pointer;
	typedef typename T::reference		reference;
	typedef typename T::const_reference	const_reference;
	private:
		pointer _mptr;
	protected:
		/*Arg*/
	public:
		VectorIterator(pointer ptr):_mptr(ptr){};
		VectorIterator():_mptr(0){};
		VectorIterator(VectorIterator const & copy){_mptr = copy._mptr;}
		VectorIterator & operator=(VectorIterator const & op){_mptr = op._mptr; return this;};
		~VectorIterator(){};
		reference operator*(){
			return *_mptr;}

		pointer operator->(){
			return &(operator*());}

		bool operator!=(const VectorIterator& Other) const{
			return !(this->_mptr == Other._mptr);}

		bool operator==(const VectorIterator& Other) const{
			return this->_mptr == Other._mptr;}

		reference operator[](const ssize_t n)const {
			return(_mptr[n]);}

		VectorIterator&	operator++(){
			++_mptr;
			return(*this);}

		VectorIterator&	operator++(int){
			_mptr++;
			return(*this);}

		VectorIterator &operator+=(const ssize_t n){
			_mptr += n;
			return *this;}

		VectorIterator operator+(const ssize_t n)const {
			VectorIterator it(*this);
			if (n < 0)
				for (ssize_t i = 0; i > n; i--)
					it--;
			else
				for (ssize_t i = 0; i < n; i++)
					it++;
			return (it);}

		VectorIterator&	operator--(){
			--_mptr;
			return(*this);}

		VectorIterator&	operator--(int){
			_mptr--;
			return(*this);}

		VectorIterator &operator-=(const ssize_t n){
			_mptr -= n;
			return *this;}

		VectorIterator operator-(ssize_t n)const {
			VectorIterator it(*this);
			if (n > 0)
				for (ssize_t i = 0; i < n; i++)
					it--;
			else
				for (ssize_t i = 0; i > n; i--)
					it++;
			return (it);}

		Distance	operator-(VectorIterator it)const {
			return (this->_mptr - it._mptr);
		}
};

#endif
