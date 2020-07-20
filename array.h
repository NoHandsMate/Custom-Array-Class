
/*
    Created by Lorenzo Cecchini, 
    inspired by The Cherno's video : https://www.youtube.com/watch?v=TzB5ZeKQIHM
*/

#pragma once
#include <iostream>
#include <initializer_list> //for initializer_list 

namespace custom {


    template<typename type, size_t size> //type: the type of the array. size : the size of the array
    class Array
    {
    private:
	    type a_Data[size];
	public:
        template<typename... T> 
        Array(T... ts) //variadic template constructor for array initialization
            :a_Data{ts...}
        {
        }

	    constexpr int Size() const {  //Returns the size of the array
		    return size;
	    }

	    type& operator[](size_t index) //define the [] operator
	    {
		    if(!(index > size)){
		        return a_Data[index];
		    } else {
		        std::cout<<"INDEX GREATER THAN ARRAY SIZE"<<'\n';
	            exit(4);	
		        }
	    }

	    constexpr const type& operator[](size_t index) const {  //const version for the [] operator
		    if(!(index > size)) { return a_Data[index]; }
		    else { std::cout<<"INDEX GREATER THAN ARRAY SIZE"<<'\n'; exit(4); }
	    }

	    constexpr void fill(const type& value) //Fill all the array with a specified value
	    {
		    for(size_t i = 0; i < Size(); ++i) {
		    a_Data[i] = value;
		    }
	    }

	    constexpr void swap(Array& other) //Swap the content of two array. they must be of the same size
	    {
		    for(size_t i = 0; i < Size(); ++i) {
		        auto temp = a_Data[i];
		        a_Data[i] = other[i];
		        other[i] = temp;
		        }
	    }

	    constexpr bool empty() const { //Checks if the size of array is 0
		    if(size > 0)
		    {
		        return false;
		    }
		    else
		        return true;
		}

	    constexpr type& at(size_t index) const //Returns the element at the specified index
	    {
            if(!(index > Size()))
                return a_Data[index];
            else
                std::cout<<"INDEX GREATER THAN ARRAY SIZE"<<'\n'; exit(4);
        }
   	    
	    constexpr type& front()  { return a_Data[0]; } //Returns the first element of the array
	    constexpr const type& front() const { return a_Data[0]; }
	    constexpr type& back()  { return a_Data[Size() - 1]; } //Returns the last element of the array
	    constexpr const type& back() const { return a_Data[Size() - 1]; }

	    constexpr type* data() { return a_Data;}      
        constexpr const type* data() const { return a_Data; } //Returns a pointer to the first element in the array object.
                                                              //Because elements in the array are stored in contiguous //storage locations, the pointer retrieved can be offset to //access any element in the array.
	    
	

    };
}