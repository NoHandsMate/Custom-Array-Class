
/*
    Created by Lorenzo Cecchini, 
    inspired by The Cherno's video : https://www.youtube.com/watch?v=TzB5ZeKQIHM
*/

#pragma once
#include <iostream>
#include <initializer_list>
#include <iterator>

namespace custom {

    template<typename type, std::size_t size> //type: the type of the array. size : the size of the array
    class Array
    {
    private:
	    type a_Data[size];
	public:

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

	    constexpr type* data() { return a_Data;}      
        constexpr const type* data() const { return a_Data; }
	    
		//Iterators

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
}