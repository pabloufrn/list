#ifndef LS_LIST_H 
#define LS_LIST_H 
#include <iostream>
/*TODO: remover coisas que forem desnecessarias no header*/

namespace ls {

    template<typename T>
        class list;

    template<typename T>
        void swap(list<T>& first_, list<T>& second_);

    template<typename T>
        std::ostream & operator<<(std::ostream & os_, const list<T>& v_ );

    /// Estrutura de cada elemento da lista
    template<typename T>
        struct Node{
            T data;
            Node<T> *prev;
            Node<T> *next;

            Node<T>( const T & d = T( ), Node * p = nullptr, Node * n = nullptr ) : data( d ), prev( p ), next( n ) { /* empty */}
        };

    /// Implementação do Iterador constante

    template< typename T >
    class my_const_iterator {

    public:

        using value_type = const T;
        /// Ponteiro para o valor do tipo.
        using pointer = value_type *;
        /// Referência para o valor do tipo.
        using const_reference = value_type &;
        /// Tipo de diferência para calcular a distância entre dois ponteiros.
        using difference_type = std::ptrdiff_t;

        //const_iterator(Node<value_type> * node = nullptr);
        const_reference & operator* () const;
        my_const_iterator & operator++(); // ++it;
        my_const_iterator operator++( int ); // it++;
        my_const_iterator & operator--(); // --it;
        my_const_iterator operator--( int ); //it--;
        bool operator==( const my_const_iterator & rhs ) const;
        bool operator!=( const my_const_iterator & rhs ) const;

    protected:
        Node<value_type> *current;
        my_const_iterator( Node<value_type> * node = nullptr );
        friend class list<value_type>;
    };

    /// Implementa a infraestrutura para suportar um ponteiro bidirecional.
    template < typename T>
        class my_iterator : public my_const_iterator<T> 
    {

            public:

                /// Alias
                /// Alias para o tipo de dado utilizado no programa.
                using value_type = T;
                /// Ponteiro para o valor do tipo.
                using pointer = value_type *;
                /// Referência para o valor do tipo.
                using reference = value_type &;
                /// Referência para o valor constante do tipo.
                using const_reference = const value_type &;  
                /// Tipo de diferência para calcular a distância entre dois ponteiros.
                using difference_type = std::ptrdiff_t;

                my_iterator( Node<value_type> * = nullptr ); 
                reference & operator*() const;
                reference & operator* ();

                my_iterator & operator++();
                my_iterator operator++( int );
                my_iterator & operator--();
                my_iterator operator--( int );

                my_iterator operator+( int );
                
                bool operator<(my_iterator& ) const;
                bool operator==( my_iterator & rhs ) const;
                bool operator!=(  my_iterator & rhs ) const;
            private:
                Node<T> *current; 
                friend class list<value_type>;
        };


    template<typename T>
        class list{
            public:
                /// ALIASES
                using value_type = T;
                using size_type = size_t;
                using iterator = my_iterator<value_type>;
                using const_iterator = my_const_iterator<value_type>;
                using difference_type = std::ptrdiff_t;
                using reference = T&;

                /// [I] Special Members
                list();
                explicit list( size_type count );
                template < typename InputIt >
                list( InputIt first , InputIt last );
                list( const list& other );
                list( std::initializer_list<T> ilist );
                ~list();
                list<T> & operator=( const list<T> & other );
                list<T> & operator=( std::initializer_list<T> ilist );

                
                /// [II] Iterators
                /// Getting an iterator
                iterator begin(); // returns an iterator pointing to the first item in the list (see Figure 1).
                const_iterator cbegin() const; // returns a constant iterator pointing to the first item in the list.
                iterator end();// : returns an iterator pointing to the end mark in the list, i.e. the position just after the last element of the list.
                const_iterator cend() const; // returns a constant iterator pointing to the end mark in the list, i.e. the position just after the last element of the list.


                /// [III] Capacity
                size_type size() const; // return the number of elements in the container.
                bool empty(); // returns true if the container contains no elements, and false otherwise.


                /// [IV] Modifies
                void clear(); // remove (either logically or physically) all elements from the container.
                const T & front() const;// const : returns the object at the beginning of the list.
                T & front();
                T & back();
                const T & back() const; // const : returns the object at the end of the list.
                void push_front( const T & value ); // : adds value to the front of the list.
                void push_back( const T & value ); //: adds value to the end of the list.
                void pop_front(); // : removes the object at the front of the list.
                void pop_back(); //: removes the object at the end of the list.
                void assign( const T & value ); // replaces the content of the list with copies of value value.
                void assign( size_type count, const T& value ); //  Replaces the contents with count copies of value value.
                /// [IV-a] Modifies with iterators
                template < typename InItr>
                void assign( InItr first, InItr last );/* : replaces the contents of the list with
                                                              copies of the elements in the range [first; last) .
                                                              */
                void assign( std::initializer_list<T> ilist );/*replaces the contents of
                                                                    the list with the elements from the initializer list ilist .
                                                                    We may call, for instance, myList.assign( {1, 2, 3, 4} ) , to replace the elements
                                                                    of the list with the elements 1, 2, 3, and 4, assuming that myList is a list of int .

                                                                                */
                iterator insert(iterator pos,   const T & value);
                template < typename InItr >
                iterator insert( iterator pos, InItr first, InItr last);
                iterator insert( iterator pos, std::initializer_list<T>);/* ilistinserts elements from the initializer list ilist before pos . Initializer list supports the user
                                                                                  of insert as in myList.insert( pos, {1, 2, 3, 4} ) , which would insert the ele-
                                                                                  ments 1, 2, 3, and 4 in the list before pos , assuming that myList is a list of int .*/
                iterator erase( iterator pos );
                iterator erase( iterator first, iterator last );/* : removes elements in the
                                                                   range [first; last) . The entire list may be erased by calling a.erase(a.begin(), a.end());
                                                                   */ 
                iterator find( const T & value ) const;
                iterator find( iterator pos, const T & value ) const;

                // [V] Acess Operators
                reference at(size_type & index);

                // TODO: Apenas para depuração
                void print()
                {
                    auto current( this->m_head->next );
                    std::cout << "[ ";

                    // caso especial de lista vazia.
                    if ( current == this->m_tail ) std::cout << "empty";
                    else
                    {
                        // caso regular, lista com 1 ou mais elementos.
                        while( current != this->m_tail )
                        {
                            std::cout << current->data << " ";
                            current = current->next;
                        }
                    }
                    std::cout << "]";
                }

            private:
                int m_size;
                Node<T> *m_head;
                Node<T> *m_tail;


        }; 

    /// Operator overloading — non-member functions

    /*Checks if the contents of lhs and rhs are equal, that is, whether lhs.size() == rhs.size() 
    and each element in lhs compares equal with the element in rhs at the same position.*/

    template < typename T >
    bool operator==( const list<T>& lhs, const list<T>& rhs ){

        if( lhs.size() != rhs.size() )
            return false;

        auto l = lhs.begin();
        auto r = rhs.begin();

        for( auto i(0u); i < lhs.size() ; ++i){

            if(*l != *r)
                return false;

            l++;
            r++;

        }

        return true;

    }

    /*Similar to the previous operator, but the opposite result.*/
    template < typename T >
    bool operator!=( const list<T>& lhs, const list<T>& rhs ){
    if( lhs.size() != rhs.size() )
            return true;

        auto l = lhs.begin();
        auto r = rhs.begin();

        for( auto i(0u); i < lhs.size() ; ++i){

            if(*l != *r)
                return true;

            l++;
            r++;

        }

        return false;

    }
}

#include "list.inl"

#endif
