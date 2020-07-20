# Custom Array Class
i'm creating a custom array class to replace the std::array class just for fun.  
Header-only


# How to use this custom class

First include the header in your file

Then create an array using this syntax:

> ```c++
> custom::Array<type, size> name_of_array;
> ```

You can also initialize the array using an initialization list:

> ```c++
> custom::Array<int, 3> array {1, 2 , 3};
> ```

# TODO

## Member functions

### Element access
- [x] at
- [x] operator[]
- [x] front
- [x] back
- [x] data

### Iterators

- [ ] begin and cbegin
- [ ] end and cend
- [ ] rbegin and crbegin
- [ ] rend and crend

### Capacity
- [x] empty
- [x] size and max_size

### Operations
- [x] fill
- [x] swap

## Non-member functions

### Operators
 - [ ] operator==
 - [ ] operator!=
 - [ ] operator<
 - [ ] operator<=
 - [ ] operator>
 - [ ] operator>=
 - [ ] operator<=>

### Other functions
- [ ] std::get
- [ ] std::swap
- [ ] std::to_array


# Documentation
I'm using the std::array definition that can be found here : https://en.cppreference.com/w/cpp/container/array
Also a special thanks to The Cherno's video : https://www.youtube.com/watch?v=TzB5ZeKQIHM
