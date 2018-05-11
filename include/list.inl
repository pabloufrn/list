#include <iostream>
/*TODO: remover coisas que forem desnecessarias*/

#include "list.h"

using namespace ls;
/// Implementa a infraestrutura para suportar um ponteiro bidirecional.
/// Construtor a partir de um ponteiro. 


// ####################### CONST_ITERATOR #######################


template <typename T>
inline const_iterator<T>::const_iterator<T>( Node<T> *p ): current(p)
{
}

inline const_iterator<T>::const_iterator<T>( ) {
    this->current = nullptr;
}

/// Acessar o conteúdo o qual o ponteiro aponta.
template <typename T>
inline const_iterator<T> & const_iterator<T>::operator*() const
{
    return this->current->value;
}

/// Operador de pré-incremento.
template <typename T>
const_iterator<T> & const_iterator<T>::operator++( )
{
    this->current = this->current->next;
    return list<T>::iterator(*this->current);
}

/// Operador de pós-incremento.
template <typename T>
const_iterator<T> const_iterator<T>::operator++( int )
{
    this->current = this->current->next;
    return MyIterator(this->current->prev);
}

/// Operador de pré-decremento.
/* TODO: olhar se tudo está ok com a definição: http://en.cppreference.com/w/cpp/concept/BidirectionalIterator*/ 
template <typename T>
const_iterator<T> & const_iterator<T>::operator--()
{
    this->current = this->current->prev;
    return this->current;
}
/**/
/// Operador de pós-decremento. 
template <typename T>
const_iterator<T> const_iterator<T>::operator--( int )
{
    this->current = this->current->prev;
    return this->current->next;
}

/// Comparar dois iteradores se são iguais.
template <typename T>
bool const_iterator<T>::operator==( const const_iterator<T> & rhs ) const
{
    return this->current == rhs.current;
}
/**/
/// Comprar dois iteradores se são difentes.

template <typename T>
bool const_iterator<T>::operator!=( const const_iterator<T> & rhs ) const
{
    return this->current != rhs.current;
}




// ####################### ITERATOR #######################




template <typename T>
inline iterator<T>::iterator<T>( Node<T> *p ): const_iterator( p )
{
    /* empty */
}

inline iterator<T>::iterator<T>( ) : const_iterator( ) { /* empty */}

/// Acessar o conteúdo o qual o ponteiro aponta.
/// TODO: VERIFICAR SE ESTÁ IMPLEMENTAÇÃO ESTÁ CORRETA <--------------------
template <typename T>
inline iterator<T> & iterator<T>::operator*() const
{
    return iterator<T>();
}

/// Operador de pré-incremento.
template <typename T>
iterator<T> & iterator<T>::operator++( )
{
    return iterator<T>(this);
}

/// Operador de pós-incremento.
template <typename T>
const_iterator<T> const_iterator<T>::operator++( int )
{
    return iterator<T>(this);
}

/// Operador de pré-decremento.
/* TODO: olhar se tudo está ok com a definição: http://en.cppreference.com/w/cpp/concept/BidirectionalIterator*/ 
template <typename T>
const_iterator<T> & const_iterator<T>::operator--()
{
    return iterator<T>(this);
}
/**/
/// Operador de pós-decremento. 
template <typename T>
const_iterator<T> const_iterator<T>::operator--( int )
{
    return iterador<T>(this);
}





// ####################### LIST #######################





/// [I] SPECIAL MEMBERS

template <typename T>
list<T>::list(): m_head(nullptr), m_tail(nullptr), m_size(0) {}

template <typename T>
list<T>::~list()
{
    auto curr(m_head);
    auto end_curr(m_tail);
    
    if(curr == nullptr && end_curr == nullptr)
        return;

    while(curr->next != nullptr)
    {
        curr = curr->next;
        delete(curr->prev);
    }

    // É necessário fazer o do end_curr? Já que o curr percorre todo a lista?

    while(end_curr != nullptr){
        end_curr = end_curr->prev;
        delete(end_curr->next);
    }
}

/// Criando nova lista a partir de outra.
/// Aqui foi feito desenho para entender o desenvolvimento.
template < typename T >
list<T>::list( const list<T> & other ){
    this->m_size = other.m_size;

    this->m_head = new Node<T>();
    m_head->data = other.m_head->data;      // ou other.(m_head->data) ?
    m_head->prev = nullptr;

    current(this->m_head);
    other_perr(other);

    for( auto i(0) ; i < this->m_size ; ++i ){

        Node<T> *new_node = new Node<T>();
        new_node->data = other_perr->next->data;
        
        new_node->prev = current;

        current->next = new_node;
        
        current = current->next;
        other_perr = other_perr->next;
    }

    m_prev = current;
}

/// Seria no caso uma cópia do construtor da classe List?
list<T>::list & operator=( const list<T> & other ){

    this->m_size = other.m_size;

    this->m_head = new Node<T>();
    m_head->data = other.m_head->data;      // ou other.(m_head->data) ?
    m_head->prev = nullptr;

    current(this->m_head);
    other_perr(other);

    for( auto i(0) ; i < this->m_size ; ++i ){

        Node<T> *new_node = new Node<T>();
        new_node->data = other_perr->next->data;
        
        new_node->prev = current;

        current->next = new_node;
        
        current = current->next;
        other_perr = other_perr->next;
    }

    m_prev = current;

    return m_head;

}

/// [III] CAPACITY

// returns true if the container contains no elements, and false otherwise.i*/
bool list<T>::empty(){
    return m_size == 0;
}

/// Common operations to all list implementations
// return the number of elements in the container.
size_type list<T>::size() const{
    return m_size;
}

void clear(); // remove (either logically or physically) all elements from the container.

template <typename T>
void list<T>::push_back( const T & value ) 
{
    Node<T>* nd = new Node<T>();
    nd->value = value;
    nd->next = this->head;
    nd->prev = nullptr;

    if(this->head)
        this->head->prev = nd;

    this->head = nd;
}

template <typename T>
void list<T>::push_front( const T & value )
{
    Node<T>* nd = new Node<T>();
    nd->value = value;
    nd->next = nullptr;

    if(this->head != nullptr)
    {
        Node<T>* curr = this->head;
        while(curr->next != nullptr)
        {
            curr = curr->next;
        }
        nd->prev = curr;
        curr->next = nd;
    }
    else {
        nd->prev = nullptr;
        this->head = nd;
    }
}
/*
   void pop_back(); //: removes the object at the end of the list.
   void pop_front(); // : removes the object at the front of the list.
   const T & back(); // const : returns the object at the end of the list.
   const T & front();// const : returns the object at the beginning of the list.
   void assign( const T & value ); // replaces the content of the list with copies of value value.
   */

    template <typename T>
T& list<T>::at(list<T>::size_type index)
{
    Node<T>* curr = this->head;

    if(curr == nullptr)
        throw std::out_of_range("Index provided is outside the array range.");

    for(int i = 0; i < index; ++i)
    {
        if(curr == nullptr)
            throw std::out_of_range("Index provided is outside the array range.");
        curr = curr->next;
    }
    return *curr;
}
/*
/// Getting an iterator
*/

template <typename T>
typename list<T>::iterator list<T>::begin()
{
    return list<T>::iterator(*head);

}
/*
const_iterator begin() const; // returns a constant iterator pointing to the first item in the list.
iterator end();// : returns an iterator pointing to the end mark in the list, i.e. the position just after the last element of the list.
const_iterator end() const; // returns a constant iterator pointing to the end mark in the list, i.e. the position just after the last element of the list.
*/
///
// List container operations that require iterators
//TODO: fazer para const iterator
//iterator insert( iterator pos, const T & value );
/* : adds value into the
   list before the position given by the iterator pos . The method returns an iterator to the
   position of the inserted item.*/

template < class InItr>
typename list<typename InItr::value_type>::iterator insert(typename list<typename InItr::value_type>::iterator pos, InItr first, InItr last )
{
    using T = typename InItr::value_type;
    auto range_size = last - first; 
    auto replace(pos + range_size);
    auto new_node = MyIterator<T>();
    *(first).prev = pos->prev;
    (*pos).prev->next = *first;
    (*pos).prev = last;
    (*last).next = pos;

}
//iterator insert( const_iterator pos, std::initializer_list<T>);/* ilistinserts elements from the initializer list ilist before pos . Initializer list supports the user
//                                                                  of insert as in myList.insert( pos, {1, 2, 3, 4} ) , which would insert the ele-
//                                                                  ments 1, 2, 3, and 4 in the list before pos , assuming that myList is a list of int .*/
//iterator erase( iterator pos );/* : removes the object at position pos . The
//                                  method returns an iterator to the element that follows pos before the call. This opera-
//                                  tion invalidates pos , since the item it pointed to was removed from the list.
//                                  */
//iterator erase( iterator first, iterator last );/* : removes elements in the
//                                                   range [first; last) . The entire list may be erased by calling a.erase(a.begin(), a.end());
//                                                   */ 
//void assign( size_type count, const T& value );/* : Replaces the contents
//*/
//template < typename InItr>
//
//void assign( InItr first, InItr last );/* : replaces the contents of the list with
//                                          copies of the elements in the range [first; last) .
//                                          */
//template < typename InItr>
//void assign( std::initializer_list<T> ilist );/*replaces the contents of
//                                                the list with the elements from the initializer list ilist .
//                                                We may call, for instance, myList.assign( {1, 2, 3, 4} ) , to replace the elements
//                                                of the list with the elements 1, 2, 3, and 4, assuming that myList is a list of int .
//                                                */
//
///// Operator overloading — non-member functions
//template<typename T>
//bool operator==( const list<T>& lhs, const list<T>& rhs );  /*Checks if
//                                                              the contents of lhs and rhs are equal, that is, whether lhs.size() == rhs.size()
//                                                              and each element in lhs compares equal with the element in rhs at the same position.*/
//template<typename T>
//bool operator!=( const list<T>& lhs, const list<T>& rhs ); /*Similar to the
//                                                             previous operator, but the opposite result.*/
//
//
//
//
//
//
//
//
//
///**/
//// Operador de diferença entre ponteiros.
///*
//   difference_type operator-( const MyIterator & rhs ) const;
///**/


/*



   node* head;

   list()
   {
   head = nullptr;
   }

   void push_front(T value)
   {
   node* nd = new node;
   nd->value = value;
   nd->next = this->head;
   nd->prev = nullptr;

   if(this->head)
   this->head->prev = nd;

   this->head = nd;

   }

   void push_back(T value)
   {
   node* nd = new node;
   nd->value = value;
   nd->next = nullptr;

   if(this->head)
   {
   node* curr = this->head;
   while(curr->next != nullptr)
   {
   curr = curr->next;
   }
   nd->prev = curr;
   curr->next = nd;
   }
   else {
   nd->prev = nullptr;
   this->head = nd;
   }
   }
   node & int index)
   {
   node* curr = this->head;

   if(curr == nullptr)
   throw std::out_of_range("Index provided is outside the array range.");

   for(int i = 0; i < index; ++i)
   {
   if(curr == nullptr)
   throw std::out_of_range("Index provided is outside the array range.");
   curr = curr->next;
   }
   return *curr;
   }
   void print(){
   node* curr = this->head;

   while(curr != nullptr)
   {
   cout << curr->value << " ";
   curr = curr->next;
   }
   cout << "\n";
   }

};


int main()
{
    list<int> mylist;

    mylist.push_front(2);
    mylist.push_front(1);
    mylist.push_back(3);
    cout << "pos 1: " << mylist.1).value << "\n";
    mylist.print();
}



*/
