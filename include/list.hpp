#ifndef SC_LIST_H 
#define SC_LIST_H 
#include <iostream>
/*TODO: remover coisas que forem desnecessarias no header*/

namespace sc {

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
            T* next;
            T* prev;
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
                explicit MyIterator( pointer pt = nullptr );

                /// Construtor a partir de uma referência a outra classe MyIterator<T>.
                MyIterator( const MyIterator<T> &);

                /// Acessar o conteúdo o qual o ponteiro aponta.
                reference operator*( ) const;

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
                Node<T> *current;

        };


    template<typename T>
        class list{
            /// ALIASES
            using size_type = size_t;

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
