#include <iostream>
/*TODO: remover coisas que forem desnecessarias*/

#include "list.hpp"

using namespace ls;
/// Implementa a infraestrutura para suportar um ponteiro bidirecional.
/// Construtor a partir de um ponteiro. 
template <typename T>
inline MyIterator<T>::MyIterator( Node<T> pt ): current(pt)
{
}
/**/
/// Construtor copia.
    template <typename T>
inline MyIterator<T>::MyIterator( const MyIterator<T> & itr): current(itr->current)
{}
/**/
/// Acessar o conteúdo o qual o ponteiro aponta.
template <typename T>
inline T& MyIterator<T>::operator*() const
{
    return this->current->value;
}
/**/
/// Destrutor da classe.
    template <typename T>
inline MyIterator<T>::~MyIterator()
{
    this->current->~Node<T>();
}
/**/
/// Operador de pré-incremento.
    template <typename T>
MyIterator<T> & MyIterator<T>::operator++( )
{
    this->current = this->current->next;
    return list<T>::iterator(*this->current);
}
/**/
/// Operador de pós-incremento.
    template <typename T>
MyIterator<T> MyIterator<T>::operator++( int )
{
    this->current = this->current->next;
    return MyIterator(this->current->prev);
}
/**/
/// Operador de pré-decremento.
/* TODO: olhar se tudo está ok com a definição: http://en.cppreference.com/w/cpp/concept/BidirectionalIterator*/ 
    template <typename T>
MyIterator<T> & MyIterator<T>::operator--()
{
    this->current = this->current->prev;
    return this->current;
}
/**/
/// Operador de pós-decremento. 
    template <typename T>
MyIterator<T> MyIterator<T>::operator--( int )
{
    this->current = this->current->prev;
    return this->current->next;
}

template <typename T>
bool MyIterator<T>::operator>=( const MyIterator<T> & rhs ) const
{
    auto curr(this->current);
    while(curr != nullptr)
    {
        if(curr == rhs)
            return true;
        curr = curr->prev;
    }
    return false;
}
/**/
/// Operador de comparação se é >=.

template <typename T>
bool MyIterator<T>::operator>( const MyIterator<T> & rhs ) const
{
    auto curr(this->current);
    while(curr != nullptr)
    {
        if(curr == rhs)
            return false;
        curr = curr->next;
    }
    return true;
}
/**/
/// Operador de comparação se é <
template <typename T>
bool MyIterator<T>::operator<( const MyIterator<T> & rhs ) const
{
    auto curr(this->current);
    while(curr != nullptr)
    {
        curr = curr->next;
        if(curr == rhs)
            return true;
    }
    return false;
}
/**/
/// Operador de comparação se é >
template <typename T>
bool MyIterator<T>::operator<=( const MyIterator<T> & rhs ) const
{
    auto curr(this->current);
    while(curr != nullptr)
    {
        if(curr == rhs)
            return true;
        curr = curr->next;
    }
    return false;
}
/// Comparar dois iteradores se são iguais.
template <typename T>
bool MyIterator<T>::operator==( const MyIterator<T> & rhs ) const
{
    return this->current == rhs.current;
}
/**/
/// Comprar dois iteradores se são difentes.

template <typename T>
bool MyIterator<T>::operator!=( const MyIterator<T> & rhs ) const
{
    return this->current != rhs.current;
}
/**/
/// Operador de atribuição.

    template <typename T>
MyIterator<T> & MyIterator<T>::operator=( const MyIterator<T> & rhs )
{
    this->current = rhs->current;
}















template <typename T>
/// Constructors, Destructors, and Assignment
list<T>::list(): head(nullptr) {}
/*
  explicit list( size_type count );
  template< typename InputIt >
  list( InputIt first, InputIt last );
  list( const list& other );
  list( std::initializer_list<T> ilist );
  */
template <typename T>
list<T>::~list()
{
    auto curr(head);
    if(curr == nullptr)
        return;
    while(curr->next != nullptr)
    {
        curr = curr->next;
        delete(curr->prev);
    }
}
  /*
  list& operator=( const list& other );
  list& operator=( std::initializer_list<T> ilist );

/// Common operations to all list implementations
size_type size(); // return the number of elements in the container.
void clear(); // remove (either logically or physically) all elements from the container.
bool empty(); // returns true if the container contains no elements, and false otherwise.i*/
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
