#ifndef LS_LIST_H 
#define LS_LIST_H 
#include <iostream>

namespace ls {

    template<typename T>
    class list;

    template<typename T>
    std::ostream & operator<<(std::ostream & , const list<T> &);

    /// Structure to each element in the list.
    template<typename T>
        struct Node{
            /// The informations to be stored.
            T data;
            /// Previous node.
            Node<T> *prev;
            /// Next node.
            Node<T> *next;

            /// Node's constructor default.
            Node<T>( const T & d = T( ), Node * p = nullptr, Node * n = nullptr ) : data( d ), prev( p ), next( n ) { /* empty */}
        };

    /// Constant iterator implementation.
    template< typename T >
    class my_const_iterator {

    public:
        
        /// Alias to the constant data type.
        using value_type = T;
        /// Pointer to the constant data type.
        using pointer = value_type *;
        /// Referece to the constant data type.
        using const_reference = value_type &;
       /// Difference type to calculate the distance between two pointers.
        using difference_type = std::ptrdiff_t;

        /// Returns a const reference to the value stored in the iterator.
        const_reference & operator* () const;
        /// Advances iterator to the next location within the list. Example: ++i;
        my_const_iterator & operator++();
        /// Advances iterator to the next location within the list. Example: i++;
        my_const_iterator operator++( int );
        /// Advances iterator to the prev location within the list. Example: --i;
        my_const_iterator & operator--();
        /// Advances iterator to the prev location within the list. Example: i--;
        my_const_iterator operator--( int );
        /// Advances iterator to a specific position (walking throught the nodes).
        my_const_iterator operator+( int );
        /// As in it1 == it2 : returns true if both iterators refer to the same location within the list, and false otherwise.
        bool operator==( const my_const_iterator & rhs ) const;
        /// As in it1 != it2 : returns true if both iterators refer to a different location within the list, and false otherwise.
        bool operator!=( const my_const_iterator & rhs ) const;

    protected:
        /// Current node.
        Node<T> *current;
        /// Constructor.
        my_const_iterator( Node<value_type> * node = nullptr );
        friend class list<value_type>;
    };

    /// Implements the infrastructure to support the bidirectional pointer.
    template < typename T>
        class my_iterator : public my_const_iterator<T> 
    {
        
            public:
                /// Alias to the data type.
                using value_type = T;
                /// Pointer to the data type.
                using pointer = value_type *;
                /// Referece to the data type.
                using reference = value_type &;
                /// Reference to the constant data type.
                using const_reference = const value_type &;  
                /// Difference type to calculate the distance between two pointers.
                using difference_type = std::ptrdiff_t;

                /// Constructor default.
                my_iterator(); 
                /// Return the constant data in that position.
                const_reference & operator*() const;
                /// Return the data in that position.
                reference & operator*();

                /// Advances iterator to the next location within the list. Example: ++i;
                my_iterator & operator++();
                /// Advances iterator to the next location within the list. Example: i++;
                my_iterator operator++( int );
                /// Advances iterator to the prev location within the list. Example: --i;
                my_iterator & operator--();
                /// Advances iterator to the prev location within the list. Example: i--;
                my_iterator operator--( int );
                /// Advances iterator to a specific position (walking throught the nodes).
                my_iterator operator+( int );
                
                /// Verifies if a element is less then another. 
                bool operator<(my_iterator& ) const;
                /// As in it1 == it2 : returns true if both iterators refer to the same location within the list, and false otherwise.
                bool operator==( my_iterator & rhs ) const;
                /// As in it1 != it2 : returns true if both iterators refer to a different location within the list, and false otherwise.
                bool operator!=(  my_iterator & rhs ) const;
            private:
                Node<T> *current; 
                my_iterator( Node<T> *p );
                friend class list<value_type>;
        };

    /// List implementation.
    /*! 
     * This class is an Abstract Data Type that implements a double linked list storing some type of type of data internally.
     */
    template<typename T>
        class list{
            public:
                /// Alias to type stored in container
                using value_type = T;
                /// Alias to size type
                using size_type = size_t;
                /// Alias to bidirectional iterator used
                using iterator = my_iterator<value_type>;
                /// Alias to const type of bidirectional iterator used
                using const_iterator = my_const_iterator<value_type>;
                /// Alias to data reference
                using reference = T&;

                // [I] Special Members

                /// Default constructor that creates an empty list.
                list();
                /// Constructs the list with count default-inserted instances of T.
                explicit list(size_type count);
                /// Constructs the list with the contents of the range [first, last).
                template < typename InputIt >
                list( InputIt first , InputIt last );
                /// Copy constructor. Constructs the list with the deep copy of the contents of other.
                list( const list& other );
                /// Constructs the list with the contents of the initializer list init.
                list( std::initializer_list<T> ilist );
                /// Destructs the list. The destructors of the elements are called and the used storage is deallocated.
                ~list();
                /// Copy assignment operator. Replaces the contents with a copy of the contents of other.
                list<T> & operator=( const list<T> & other );
                /// Replaces the contents with those identified by initializer list ilist.
                list<T> & operator=( std::initializer_list<T> ilist );

                
                // [II] Iterators
                // Getting an iterator

                /// Returns an iterator pointing to the first item in the list.
                iterator begin();
                /// Returns a constant iterator pointing to the first item in the list.
                const_iterator cbegin() const;
                /// Returns an iterator pointing to the end mark in the list, i.e. the position just after the last element of the list. 
                iterator end();
                /// Returns a constant iterator pointing to the end mark in the list, i.e. the position just after the last element of the list.
                const_iterator cend() const;


                // [III] Capacity

                /// Return the number of elements in the container.
                size_type size() const;
                /// Returns true if the container contains no elements, and false otherwise.
                bool empty();


                // [IV] Modifies

                /// Remove (either logically or physically) all elements from the container.
                void clear();
                /// Returns the object at the beginning of the list.
                const T & front() const;
                ///  Returns the object at the beginning of the list.
                T & front();
                /// Returns the object at the end of the list.
                T & back();
                /// Returns the object at the end of the list.
                const T & back() const;
                /// Adds value to the front of the list.
                void push_front( const T & value );
                /// Adds value to the end of the list.
                void push_back( const T & value );
                /// Removes the object at the front of the list.
                void pop_front();
                /// Removes the object at the end of the list.
                void pop_back();
                /// Replaces the content of the list with copies of value.
                void assign( const T & value );
                /// Clear list and insert count copies of value.
                void assign( size_type count, const T& value ); 

                // [IV-a] Modifies with iterators

                /*! \brief
                 *   Replaces the contents with count copies of value value.
                 */
                template < typename InItr>
                void assign( InItr first, InItr last );
                /*! \brief
                  Replaces the contents of the list with the elements from the initializer list ilist. We may call, for instance,
                  myList.assign( {1, 2, 3, 4} ), to replace the elements of the list with the elements 1, 2, 3, and 4, assuming that myList is a list of int.
                 */
                void assign( std::initializer_list<T> ilist );
                /*! \brief
                 * Adds value into the list before the position given by the iterator pos . 
                 *   The method returns an iterator to the position of the inserted item.
                 */
                iterator insert(iterator pos, const T & value);
                /*! \brief
                 * Adds value into the list before the position given by the iterator pos . 
                 *   The method returns an iterator to the position of the inserted item.
                 */
                iterator insert(const_iterator pos, const T & value);
                /*! \brief
                 *   Inserts elements from the range [first; last) before pos .
                 */
                template < typename InItr >
                iterator insert( iterator pos, InItr first, InItr last);
                /*! \brief
                 *   Inserts elements from the range [first; last) before pos .
                 */
                template < typename InItr >
                iterator insert( const_iterator pos, InItr first, InItr last);
                /*! \brief
                 * Inserts elements from the initializer list ilist before pos . Initializer list supports the user
                 * of insert as in myList.insert( pos, {1, 2, 3, 4} ) , which would insert the elements 1, 2, 3, and 4
                 * in the list before pos , assuming that myList is a list of int.
                 */
                iterator insert( iterator pos, std::initializer_list<T>);
                /*! \brief
                 * Inserts elements from the initializer list ilist before pos . Initializer list supports the user
                 * of insert as in myList.insert( pos, {1, 2, 3, 4} ) , which would insert the elements 1, 2, 3, and 4
                 * in the list before pos , assuming that myList is a list of int.
                 */
                iterator insert( const_iterator pos, std::initializer_list<T>);
                /*! \brief
                 *   Removes the object at position pos . The method returns an iterator to the element that follows pos before the call.
                 *   This operation invalidates pos , since the item it pointed to was removed from the list.
                 */
                iterator erase( iterator pos );
                /*! \brief
                 *   Removes the object at position pos . The method returns an iterator to the element that follows pos before the call.
                 *   This operation invalidates pos , since the item it pointed to was removed from the list.
                 */
                iterator erase( const_iterator pos );
                /*! \brief
                 *   Removes elements in the range [first; last) . The entire list may be erased by calling a.erase(a.begin(), a.end());
                 */
                iterator erase( iterator first, iterator last );
                /*! \brief
                 *   Removes elements in the range [first; last) . The entire list may be erased by calling a.erase(a.begin(), a.end());
                 */
                iterator erase( const_iterator first, const_iterator last );
                /// Search a specific value in a list and return a pointer to the previous element before the element found.
                iterator find( const T & value ) const;
                /// Finds a specific value in a position and return a pointer to the previous element before the element found.
                iterator find( iterator pos, const T & value ) const;

                // [V] Acess Operators
                /*! \brief
                 * Acess an element at index or throw a out_of_range exception if the index does not exist
                 */
                reference at(size_type & index);

                /// Prints the values in the list.
                friend std::ostream & operator<< <T>(std::ostream & , const list& );

            private:
                /// List's size.
                int m_size;
                /// List's head.
                Node<T> *m_head;
                /// List's tail.
                Node<T> *m_tail;


        }; 

    // Operator overloading — non-member functions


    /*! \brief
     * Checks if the contents of lhs and rhs are equal, that is, whether lhs.size() == rhs.size()
     * and each element in lhs compares equal with the element in rhs at the same position.
     */
    template < typename T >
    bool operator==( const list<T>& lhs, const list<T>& rhs );

    /*! \brief
     * Checks if the contents of lhs and rhs are differents, that is, whether lhs.size() != rhs.size()
     * and each element in lhs compares different with the element in rhs at the same position.
     */
    template < typename T >
    bool operator!=( const list<T>& lhs, const list<T>& rhs );

    /// Prints the values in the list.
    
}

#include "list.inl"

#endif
