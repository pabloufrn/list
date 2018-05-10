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
            T value;
            Node* next;
            Node* prev;
        };

    /// Implementa a infraestrutura para suportar um ponteiro bidirecional.
    template < typename T>
        class MyIterator {

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

                /// Construtor a partir de um ponteiro. 
                explicit MyIterator( Node<value_type> pt = nullptr );

                /// Construtor cópia
                MyIterator( const MyIterator<T> &);

                /// Acessar o conteúdo o qual o ponteiro aponta.
                reference operator*() const;

                /// Destrutor da classe.
                ~MyIterator();

                /// Operador de pré-incremento.
                MyIterator & operator++( );

                /// Operador de pós-incremento.
                MyIterator operator++( int );

                /// Operador de pré-decremento.
                MyIterator & operator--( );

                /// Operador de pós-decremento.
                MyIterator operator--( int ); 

                /// Operador de soma.
                MyIterator operator+( int );

                /// Operador de subtração.
                MyIterator operator-( int );

                /// Sobrecarga do operador ->.
                MyIterator * operator->( void ) const;

                /// Operador de comparação se é <=.
                bool operator<=( const MyIterator<T> & rhs ) const;

                /// Operador de comparação se é >=.
                bool operator>( const MyIterator<T> & rhs ) const;

                /// Operador de comparação se é <
                bool operator<( const MyIterator<T> & rhs ) const;

                /// Operador de comparação se é >
                bool operator>=( const MyIterator<T> & rhs ) const;

                /// Comparar dois iteradores se são iguais.
                bool operator==( const MyIterator<T> & rhs ) const;

                /// Comprar dois iteradores se são difentes.
                bool operator!=( const MyIterator<T> & rhs ) const;

                /// Operador de atribuição.
                MyIterator & operator=( const MyIterator<T> & rhs );

                // Operador de diferença entre ponteiros.
                difference_type operator-( const MyIterator & rhs ) const;

            private:
                /// O ponteiro.
                Node<value_type> *current;

        };


    template<typename T>
        class list{
            public:
                /// ALIASES
                using size_type = size_t;
                using iterator = MyIterator<T>;
                using const_iterator = MyIterator<const T>;
                using reference = T&;
                /// Constructors, Destructors, and Assignment
                list();
                explicit list( size_type count );
                template< typename InputIt >
                    list( InputIt first, InputIt last );
                list( const list& other );
                list( std::initializer_list<T> ilist );
                ~list();
                list& operator=( const list& other );
                list& operator=( std::initializer_list<T> ilist );

                /// Common operations to all list implementations
                size_type size(); // return the number of elements in the container.
                void clear(); // remove (either logically or physically) all elements from the container.
                bool empty(); // returns true if the container contains no elements, and false otherwise.
                void push_front( const T & value ); // : adds value to the front of the list.
                void push_back( const T & value ); //: adds value to the end of the list.
                void pop_back(); //: removes the object at the end of the list.
                void pop_front(); // : removes the object at the front of the list.
                const T & back(); // const : returns the object at the end of the list.
                const T & front();// const : returns the object at the beginning of the list.
                void assign( const T & value ); // replaces the content of the list with copies of value value.
                reference at(size_type index);

                /// Getting an iterator
                iterator begin(); // returns an iterator pointing to the first item in the list (see Figure 1).
                const_iterator begin() const; // returns a constant iterator pointing to the first item in the list.
                iterator end();// : returns an iterator pointing to the end mark in the list, i.e. the position just after the last element of the list.
                const_iterator end() const; // returns a constant iterator pointing to the end mark in the list, i.e. the position just after the last element of the list.

                ///
                // List container operations that require iterators
                //TODO: fazer para const iterator
                iterator insert( iterator pos, const T & value );/* : adds value into the
                                                                    list before the position given by the iterator pos . The method returns an iterator to the
                                                                    position of the inserted item.*/
                template < typename InItr>
                    iterator insert( iterator pos, InItr first, InItr last );// inserts elements from the range [first; last) before pos .
                iterator insert( const_iterator pos, std::initializer_list<T>);/* ilistinserts elements from the initializer list ilist before pos . Initializer list supports the user
                                                                                  of insert as in myList.insert( pos, {1, 2, 3, 4} ) , which would insert the ele-
                                                                                  ments 1, 2, 3, and 4 in the list before pos , assuming that myList is a list of int .*/
                iterator erase( iterator pos );/* : removes the object at position pos . The
                                                  method returns an iterator to the element that follows pos before the call. This opera-
                                                  tion invalidates pos , since the item it pointed to was removed from the list.
                                                  */
                iterator erase( iterator first, iterator last );/* : removes elements in the
                                                                   range [first; last) . The entire list may be erased by calling a.erase(a.begin(), a.end());
                                                                   */ 
                void assign( size_type count, const T& value );/* : Replaces the contents
                */
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
                Node<T> *head;


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
