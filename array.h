
/**
   * Created by Lorenzo Cecchini, 
   * inspired by The Cherno's video : https://www.youtube.com/watch?v=TzB5ZeKQIHM
   * 
   * @tparam type. type of the array.
   * @tparam size. size of the array.
	
*/

#pragma once
#include <iostream>
#include <initializer_list>
#include <iterator>

namespace custom {

    template<typename type, std::size_t size> //type: the type of the array. size : the size of the array
    class Array
    {
    public:
	    type a_Data[size];
	public:

		Array() = default;

        Array(std::initializer_list<type> t)
		{
			std::copy(t.begin(), t.end(), a_Data);
		}

	    constexpr std::size_t Size() const {  //Returns the size of the array
		    return size;
	    }

	    type& operator[](std::size_t index) //define the [] operator
	    {
		    if(!(index > size)) {
		        return a_Data[index];
		    } else {
		        std::cout<<"INDEX GREATER THAN ARRAY SIZE"<<'\n';
	            exit(4);	
		        }
	    }

	    constexpr const type& operator[](std::size_t index) const {  //const version for the [] operator
		    if(!(index > size)) { 
				return a_Data[index]; 
			}
		    else { 
				std::cout<<"INDEX GREATER THAN ARRAY SIZE"<<'\n'; 
				exit(4); 
			}
	    }

	    constexpr void fill(const type& value) //Fill all the array with a specified value
	    {
		    for(std::size_t i = 0; i < Size(); ++i) {
		    	a_Data[i] = value;
		    }
	    }
		constexpr const void fill(const type& value) const //Fill all the array with a specified value
	    {
		    for(std::size_t i = 0; i < Size(); ++i) {
		    	a_Data[i] = value;
		    }
	    }

	    constexpr void swap(const Array& other) //Swap the content of two array. they must be of the same size
	    {
		    for(std::size_t i = 0; i < Size(); ++i) {
		        auto temp = a_Data[i];
		        a_Data[i] = other[i];
		        other[i] = temp;
		        }
	    }
		constexpr const void swap(const Array& other) const //Swap the content of two array. they must be of the same size
	    {
		    for(std::size_t i = 0; i < Size(); ++i) {
		        auto temp = a_Data[i];
		        a_Data[i] = other[i];
		        other[i] = temp;
		        }
	    }


	    constexpr bool empty() const { //Checks if the size of array is 0		    
			return (size > 0) ? false : true;
		}

	    constexpr type& at(std::size_t index) //Returns the element at the specified index
	    {
            if(!(index > Size())) {
                return a_Data[index];
			}
            else
			{
				std::cout<<"INDEX GREATER THAN ARRAY SIZE"<<'\n'; exit(4);
			}   
        }

		constexpr const type& at(std::size_t index) const 
	    {
            if(!(index > Size())) {
                return a_Data[index];
			}
            else
			{
				std::cout<<"INDEX GREATER THAN ARRAY SIZE"<<'\n'; exit(4);
			}   
        }
   	    
	    constexpr type& front()  { return a_Data[0]; } //Returns the first element of the array
	    constexpr const type& front() const { return a_Data[0]; }
	    constexpr type& back()  { return a_Data[Size() - 1]; } //Returns the last element of the array
	    constexpr const type& back() const { return a_Data[Size() - 1]; }

		// data() => Returns a pointer to the first element in the array object.
        //Because elements in the array are stored in contiguous //storage locations, the pointer retrieved can be offset to 
		//access any element in the array

	    constexpr type* data() const { return const_cast<type*>(a_Data); }  //const_cast is necessary when the array is const => converts type* to const type*  

		//Iterators

		constexpr type* begin() { return data(); } //Returns an iterator that points to the first element of the array
		constexpr type* begin() const { return data(); } 

		constexpr type* end() { return &a_Data[size]; } //Returns an iterator that points to 'past-the-end' element of the array
		constexpr type* end() const { return const_cast<type*>(&a_Data[size]); }

		typedef std::reverse_iterator<type*> reverse_iterator; //Define the reverse iterator

		constexpr reverse_iterator rbegin() { return reverse_iterator(end()); } //Returns a reverse iterator that points to the element right before the last
		constexpr reverse_iterator rbegin() const { return reverse_iterator(end()); }

		constexpr reverse_iterator rend() { return reverse_iterator(begin()); } //Returns a reverse iterator pointing to the element preceding the first element in the array.
		constexpr reverse_iterator rend() const { return reverse_iterator(begin()); }

		constexpr const type* cbegin() const { return data(); } //Returns a const iterator that points to the first element of the array
		constexpr const type* cend() const { return &a_Data[size]; } //Returns a const iterator that points to 'past-the-end' element of the array

		constexpr const reverse_iterator crbegin() const { return reverse_iterator(end()); } //Returns a const iterator that points to the element right before the last
		constexpr const reverse_iterator crend() const { return reverse_iterator(begin()); } //Returns a const iterator that points to the element preceding the first element in the array


		//Operators
		template<typename T, std::size_t S> 
		constexpr bool operator==(const Array<T, S>& r_operand) //This overload for all the operators is necessary when the arrays are of equal size. 
		{
			for(std::size_t i = 0; i < S; ++i)
			{
				if(a_Data[i] != r_operand[i])
				{
					return false;
				}
			}
			return true;
		}
		template<typename T, std::size_t S> 
		constexpr const bool operator==(const Array<T, S>& r_operand) const
		{
			for(std::size_t i = 0; i < S; ++i)
			{
				if(a_Data[i] != r_operand[i])
				{
					return false;
				}
			}
			return true;
		}
		constexpr bool operator==(const Array& r_operand) 
		{
			for(std::size_t i = 0; i < Size(); ++i)
			{
				if(a_Data[i] != r_operand[i])
				{
					
					return false;
				}
			}
			return true;
		}

		constexpr const bool operator==(const Array& r_operand) const
		{
			for(std::size_t i = 0; i < Size(); ++i)
			{
				if(a_Data[i] != r_operand[i])
				{
					return false;
				}
			}
			return true;
		}

		template<typename T, std::size_t S> 
		constexpr bool operator!=(const Array<T, S>& r_operand)
		{
			for(std::size_t i = 0; i < S; ++i)
			{
				if(a_Data[i] != r_operand[i])
				{
					return true;
				}
			}
			return false;
		}
		template<typename T, std::size_t S> 
		constexpr const bool operator!=(const Array<T, S>& r_operand) const
		{
			for(std::size_t i = 0; i < S; ++i)
			{
				if(a_Data[i] != r_operand[i])
				{
					return true;
				}
			}
			return false;
		}
		constexpr bool operator!=(const Array& r_operand)
		{
			for(std::size_t i = 0; i < Size(); ++i)
			{
				if(a_Data[i] != r_operand[i])
				{
					return false;
				}
			}
			return true;
		}

		constexpr const bool operator!=(const Array& r_operand) const
		{
			for(std::size_t i = 0; i < Size(); ++i)
			{
				if(a_Data[i] != r_operand[i])
				{
					return false;
				}
			}
			return true;
		}
		template<typename T, std::size_t S> 
		constexpr bool operator<(const Array<T, S>& r_operand)
		{

		    return (Size() < r_operand.Size()) ? true : false;
		}
		template<typename T, std::size_t S> 
		constexpr const bool operator<(const Array<T, S>& r_operand) const
		{
			return (Size() < r_operand.Size()) ? true : false;
		}
		constexpr bool operator<(const Array& r_operand)
		{
			return (Size() < r_operand.Size()) ? true : false;
		}
		
		constexpr const bool operator<(const Array& r_operand) const
		{
			return (Size() < r_operand.Size()) ? true : false;
		}

		template<typename T, std::size_t S> 
		constexpr bool operator<=(const Array<T, S>& r_operand)
		{
			return (Size() <= r_operand.Size()) ? true : false;
		}
		template<typename T, std::size_t S> 
		constexpr const bool operator<=(const Array<T, S>& r_operand) const
		{
			return (Size() <= r_operand.Size()) ? true : false;
		}

		constexpr bool operator<=(const Array& r_operand)
		{
			return (Size() <= r_operand.Size()) ? true : false;
		}


		constexpr const bool operator<=(const Array& r_operand) const
		{
			return (Size() <= r_operand.Size()) ? true : false;
		}

		template<typename T, std::size_t S>
		constexpr bool operator>(const Array<T, S>& r_operand)
		{
			return (Size() > r_operand.Size()) ? true : false;
		}
		template<typename T, std::size_t S>
		constexpr const bool operator>(const Array<T, S>& r_operand) const
		{
			return (Size() > r_operand.Size()) ? true : false;
		}

		constexpr bool operator>(const Array& r_operand)
		{
			return (Size() > r_operand.Size()) ? true : false;
		}


		constexpr const bool operator>(const Array& r_operand) const
		{
			return (Size() > r_operand.Size()) ? true : false;
		}

		template<typename T, std::size_t S>
		constexpr bool operator>=(const Array<T, S>& r_operand)
		{
			return (Size() >= r_operand.Size()) ? true : false;
		}

		template<typename T, std::size_t S>
		constexpr const bool operator>=(const Array<T, S>& r_operand) const
		{
			return (Size() >= r_operand.Size()) ? true : false;
		}

		constexpr bool operator>=(const Array& r_operand)
		{
			return (Size() >= r_operand.Size()) ? true : false;
		}
		constexpr const bool operator>=(const Array& r_operand) const
		{
			return (Size() >= r_operand.Size()) ? true : false;
		}
    };

	//other function

	//FUNCTION GET: EXTRACTS THE Ith ELEMENT FROM THE ARRAY
	template<std::size_t I, class T, std::size_t N>
	constexpr T& get(custom::Array<T, N>& arr)
	{
		return arr.a_Data[I];
	}

	template<std::size_t I, class T, std::size_t N>
	constexpr T&& get(custom::Array<T, N>&& arr)
	{
		return arr.a_Data[I];
	}

	template<std::size_t I, class T, std::size_t N>
	constexpr const T& get(const custom::Array<T, N>& arr)
	{
		return arr.a_Data[I];
	}

	template<std::size_t I, class T, std::size_t N>
	constexpr const T&& get(const custom::Array<T, N>&& arr)
	{
		return const_cast<T>(arr.a_Data[I]);
	}
}