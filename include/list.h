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
    class const_interator{

    public:

        using value_type = T;
        /// Ponteiro para o valor do tipo.
        using pointer = value_type *;
        /// Referência para o valor do tipo.
        using reference = value_type &;
        /// Referência para o valor constante do tipo.
        using const_reference = const value_type &;  
        /// Tipo de diferência para calcular a distância entre dois ponteiros.
        using difference_type = std::ptrdiff_t;

        const_iterator();
        const reference & operator* () const;
        const_iterator & operator++(); // ++it;
        const_iterator operator++( int ); // it++;
        const_iterator & operator--(); // --it;
        const_iterator operator--(); //it--;
        bool operator==( const const_iterator & rhs ) const;
        bool operator!=( const const_iterator & rhs ) const;

    protected:
        Node<T> *current;
        const_iterator( Node *p );
        friend class List<reference>;
    }

    /// Implementa a infraestrutura para suportar um ponteiro bidirecional.
    template < typename T>
        class iterator : public const_iterator {

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

                iterator( ) : const_iterator(){ /* Empty */}
                const reference & operator*() const;
                reference & operator* ();

                iterator & operator++();
                iterator operator++( int );
                iterator & operator--();
                iterator operator--( int );

            protected:
                iterator( Node *p );
                friend class List<reference>;

        };


    template<typename T>
        class list{
            public:
                /// ALIASES
                using size_type = size_t;
                using iterator = MyIterator<T>;
                using const_iterator = MyIterator<const T>;
                using difference_type = std::ptrdiff_t;
                using reference = T&;

                /// [I] Special Members
                list();
                ~list();
                list( const list& other );
                list& operator=( const list& other );
                
                /// [II] Iterators
                /// Getting an iterator
                iterator begin(); // returns an iterator pointing to the first item in the list (see Figure 1).
                const_iterator cbegin() const; // returns a constant iterator pointing to the first item in the list.
                iterator end();// : returns an iterator pointing to the end mark in the list, i.e. the position just after the last element of the list.
                const_iterator cend() const; // returns a constant iterator pointing to the end mark in the list, i.e. the position just after the last element of the list.


                /// [III] Capacity
                int size(); // return the number of elements in the container.
                bool empty(); // returns true if the container contains no elements, and false otherwise.


                /// [IV] Modifies
                void clear(); // remove (either logically or physically) all elements from the container.
                T & front();
                const T & front();// const : returns the object at the beginning of the list.
                T & back();
                const T & back(); // const : returns the object at the end of the list.
                void push_front( const T & value ); // : adds value to the front of the list.
                void push_back( const T & value ); //: adds value to the end of the list.
                void pop_front(); // : removes the object at the front of the list.
                void pop_back(); //: removes the object at the end of the list.
                void assign( const T & value ); // replaces the content of the list with copies of value value.

                /// [IV-a] Modifies with iterators
                template < typename InItr>
                void assign( InItr first, InItr last );/* : replaces the contents of the list with
                                                              copies of the elements in the range [first; last) .
                                                              */
                template < typename InItr>
                void assign( std::initializer_list<T> ilist );/*replaces the contents of
                                                                    the list with the elements from the initializer list ilist .
                                                                    We may call, for instance, myList.assign( {1, 2, 3, 4} ) , to replace the elements
                                                                    of the list with the elements 1, 2, 3, and 4, assuming that myList is a list of int .
                                                                    */
                iterator insert( const_iterator pos, std::initializer_list<T>);/* ilistinserts elements from the initializer list ilist before pos . Initializer list supports the user
                                                                                  of insert as in myList.insert( pos, {1, 2, 3, 4} ) , which would insert the ele-
                                                                                  ments 1, 2, 3, and 4 in the list before pos , assuming that myList is a list of int .*/
                iterator erase( const_iterator itr );
                iterator erase( iterator first, iterator last );/* : removes elements in the
                                                                   range [first; last) . The entire list may be erased by calling a.erase(a.begin(), a.end());
                                                                   */ 
                const_iterator find( const T & value ) const;

                // TODO: Apenas para depuração
                void print()
                {
                    auto current( head );
                    std::cout << "[ ";

                    // caso especial de lista vazia.
                    if ( current == nullptr ) std::cout << "empty";
                    else
                    {
                        // caso regular, lista com 1 ou mais elementos.
                        while( current != nullptr )
                        {
                            std::cout << current->value << " ";
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
    template<typename T>
        bool operator==( const list<T>& lhs, const list<T>& rhs );  /*Checks if
                                                                      the contents of lhs and rhs are equal, that is, whether lhs.size() == rhs.size()
                                                                      and each element in lhs compares equal with the element in rhs at the same position.*/
    template<typename T>
        bool operator!=( const list<T>& lhs, const list<T>& rhs ); /*Similar to the
                                                                     previous operator, but the opposite result.*/
}

#include "list.inl"

#endif
