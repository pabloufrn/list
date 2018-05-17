#include <iostream>
/*TODO: remover coisas que forem desnecessarias*/

#include "list.h"

using namespace ls;
/// Implementa a infraestrutura para suportar um ponteiro bidirecional.
/// Construtor a partir de um ponteiro. 


// ####################### CONST_ITERATOR #######################


template <typename T>
inline my_const_iterator<T>::my_const_iterator(Node<my_const_iterator::value_type> * node): current(node)
{
}

/// Acessar o conteúdo o qual o ponteiro aponta.
template <typename T>
typename my_const_iterator<T>::const_reference & my_const_iterator<T>::operator*() const
{
    return this->current->data;
}

/// Operador de pré-incremento.
template <typename T>
my_const_iterator<T> & my_const_iterator<T>::operator++( )
{
    this->current = this->current->next;
    return list<T>::const_iterator(*this->current);
}

/// Operador de pós-incremento.
template <typename T>
my_const_iterator<T> my_const_iterator<T>::operator++( int )
{
    this->current = this->current->next;
    return list<T>::const_iterator(this->current->prev);
}

/// Operador de pré-decremento.
/* TODO: olhar se tudo está ok com a definição: http://en.cppreference.com/w/cpp/concept/BidirectionalIterator*/ 
template <typename T>
my_const_iterator<T> & my_const_iterator<T>::operator--()
{
    this->current = this->current->prev;
    return list<T>::const_iterator(this->current);
}
/**/
/// Operador de pós-decremento. 
template <typename T>
my_const_iterator<T> my_const_iterator<T>::operator--( int )
{
    this->current = this->current->prev;
    return list<T>::const_iterator(this->current->next);
}

/// Comparar dois iteradores se são iguais.
template <typename T>
bool my_const_iterator<T>::operator==( const my_const_iterator<T> & rhs ) const
{
    return this->current == rhs.current;
}
/**/
/// Comprar dois iteradores se são difentes.

template <typename T>
bool my_const_iterator<T>::operator!=( const my_const_iterator<T> & rhs ) const
{
    return this->current != rhs.current;
}




// ####################### ITERATOR #######################

template <typename T>
inline my_iterator<T>::my_iterator( Node<my_iterator::value_type> * node ): current(node) 
{
    /* empty */
}

template <typename T>
inline typename my_iterator<T>::reference my_iterator<T>::operator*() const
{
    return this->current->data;
}

template <typename T>
inline typename my_iterator<T>::reference my_iterator<T>::operator*()
{
    return this->current->data;
}

/// Operador de pré-incremento.
template <typename T>
my_iterator<T> & my_iterator<T>::operator++( )
{
    this->current = this->current->next;
    return *this;
}

/// Operador de pós-incremento.
template <typename T>
my_iterator<T> my_iterator<T>::operator++( int )
{
    auto old_current(this->current);
    this->current = this->current->next;
    
    return my_iterator<T>(old_current);
}

/// Operador de pré-decremento.
/* TODO: olhar se tudo está ok com a definição: http://en.cppreference.com/w/cpp/concept/BidirectionalIterator*/ 
template <typename T>
my_iterator<T> & my_iterator<T>::operator--()
{
    this->current = this->current->prev;
    return *this;
}

/// Operador de pós-decremento. 
template <typename T>
my_iterator<T> my_iterator<T>::operator--( int )
{
    auto old_current(this->current);
    this->current = this->current->prev;
    return list<T>::iterador(old_current);
}

template <typename T>
my_iterator<T> my_iterator<T>::operator+( int valor )
{
    
    auto i(0);
    while( i != valor){
        this->current = this->current->next;
        ++i;
    }

    return my_iterator<T>(this->current);
}

template <typename T>
bool my_iterator<T>::operator<(my_iterator<T>& rhs) const
{
    auto curr(this->current);
    while(curr != nullptr)
    {
        curr = curr->next;
        if(curr == rhs.current)
            return true;
    }
    return false;
}

template < typename T >
bool my_iterator<T>::operator==(my_iterator<T>& rhs) const{
    return this->current == rhs.current;
}

template < typename T >
bool my_iterator<T>::operator!=(my_iterator<T>& rhs) const{
    return this->current != rhs.current;
}

// ####################### LIST #######################


/// [I] SPECIAL MEMBERS

template <typename T>
list<T>::list(){
    m_size = 0;
    Node<T> * h = new Node<T>();
    Node<T> * t = new Node<T>();
    
    h->next = t;
    h->prev = nullptr;
    this->m_head = h;

    t->prev = h;
    t->next = nullptr;
    this->m_tail = t;

}

template < typename T >
list<T>::list( list<T>::size_type count ){

    m_size = count;
    Node<T> * h = new Node<T>();
    Node<T> * t = new Node<T>();
    
    h->next = t;
    h->prev = nullptr;
    this->m_head = h;

    t->prev = h;
    t->next = nullptr;
    this->m_tail = t;

    auto i(0u);

    auto current(m_head);

    while( i != count ){

        // Cria o novo node
        Node<T> * new_node = new Node<T>();
        // Atribui o valor que se encontra no node da posição desejada que se encontra na outra lista.
        new_node->data = 0;

        // Conecta o novo node com os elementos de sua esquerda e direita.
        new_node->prev = current;
        new_node->next = m_tail;

        // Reatribui os locais (next e prev) para o novo node.
        current->next->prev = new_node;
        current->next = new_node;

        current = current->next;

        i++;

    }

}

template < typename T >
template < typename InputIt >
list<T>::list( InputIt first , InputIt last ){

    auto qnt = std::distance(first, last);

    m_size = qnt;
    Node<T> * h = new Node<T>();
    Node<T> * t = new Node<T>();
    
    h->next = t;
    h->prev = nullptr;
    this->m_head = h;

    t->prev = h;
    t->next = nullptr;
    this->m_tail = t;

    auto i(0u);

    auto current(m_head);

    while( i != qnt ){

        // Cria o novo node
        Node<T> * new_node = new Node<T>();
        // Atribui o valor que se encontra no node da posição desejada que se encontra na outra lista.
        new_node->data = *first;

        // Conecta o novo node com os elementos de sua esquerda e direita.
        new_node->prev = current;
        new_node->next = m_tail;

        // Reatribui os locais (next e prev) para o novo node.
        current->next->prev = new_node;
        current->next = new_node;

        current = current->next;

        i++;
        first++;

    }

}

template < typename T >
list<T>::list( std::initializer_list<T> ilist ){

    auto f = ilist.begin();

    auto dist = ilist.size();

    m_size = dist;

    Node<T> * h = new Node<T>();
    Node<T> * t = new Node<T>();
    
    h->next = t;
    h->prev = nullptr;
    this->m_head = h;

    t->prev = h;
    t->next = nullptr;
    this->m_tail = t;

    auto i(0u);

    auto current(m_head);

    while( i != dist ){

        // Cria o novo node
        Node<T> * new_node = new Node<T>();
        // Atribui o valor que se encontra no node da posição desejada que se encontra na outra lista.
        new_node->data = *f;

        // Conecta o novo node com os elementos de sua esquerda e direita.
        new_node->prev = current;
        new_node->next = m_tail;

        // Reatribui os locais (next e prev) para o novo node.
        current->next->prev = new_node;
        current->next = new_node;

        current = current->next;

        i++;
        f++;

    }

}

template <typename T>
list<T>::~list()
{
    clear();
    delete m_head;
    delete m_tail;
}

/// Criando nova lista a partir de outra.
/// Aqui foi feito desenho para entender o desenvolvimento.
template < typename T >
list<T>::list( const list<T> & other ){
    this->m_size = other.m_size;

    Node<T> * h = new Node<T>();
    Node<T> * t = new Node<T>();
    
    h->next = t;
    h->prev = nullptr;
    this->m_head = h;

    t->prev = h;
    t->next = nullptr;
    this->m_tail = t;

    auto current(m_head);

    auto current_other(other.m_head);
    current_other = current_other->next;

    for( auto i(0) ; i < this->m_size ; ++i ){
        // Cria o novo node
        Node<T> * new_node = new Node<T>();
        // Atribui o valor que se encontra no node da posição desejada que se encontra na outra lista.
        new_node->data = current_other->data;

        // Conecta o novo node com os elementos de sua esquerda e direita.
        new_node->prev = current;
        new_node->next = m_tail;

        // Reatribui os locais (next e prev) para o novo node.
        current->next->prev = new_node;
        current->next = new_node;

        // Avança em ambas as listas.
        current = current->next;
        current_other = current_other->next;

    }
}

template < typename T >
list<T> & list<T>::operator=( const list<T> & other ){

    this->m_size = other.m_size;

    auto current(m_head);


    auto current_other(other.m_head);
    current_other = current_other->next;

    for( auto i(0) ; i < this->m_size ; ++i ){

        // Cria o novo node
        Node<T> * new_node = new Node<T>();
        // Atribui o valor que se encontra no node da posição desejada que se encontra na outra lista.
        new_node->data = current_other->data;

        // Conecta o novo node com os elementos de sua esquerda e direita.
        new_node->prev = current;
        new_node->next = m_tail;

        // Reatribui os locais (next e prev) para o novo node.
        m_tail->prev->next = new_node;
        m_tail->prev = new_node;

        // Avança em ambas as listas.
        current = current->next;
        current_other = current_other->next;

    }

    return *this;
}

template < typename T >
list<T> & list<T>::operator=( std::initializer_list<T> ilist ){

    auto f(ilist.begin());
    this->m_size = ilist.size();

    auto current(m_head);

    for( auto i(0) ; i < this->m_size ; ++i ){

        // Cria o novo node
        Node<T> * new_node = new Node<T>();
        // Atribui o valor que se encontra no node da posição desejada que se encontra na outra lista.
        new_node->data = *f;

        // Conecta o novo node com os elementos de sua esquerda e direita.
        new_node->prev = current;
        new_node->next = m_tail;

        // Reatribui os locais (next e prev) para o novo node.
        m_tail->prev->next = new_node;
        m_tail->prev = new_node;

        // Avança em ambas as listas.
        current = current->next;

        f++;

    }

    return *this;

}

/// [III] CAPACITY

// returns true if the container contains no elements, and false otherwise.i*/
template < typename T >
bool list<T>::empty(){
    return m_size == 0;
}

/// Common operations to all list implementations
// return the number of elements in the container.
template < typename T >
typename list<T>::size_type list<T>::size() const{
    return m_size;
}

// remove (either logically or physically) all elements from the container.
template < typename T >
void list<T>::clear(){
    auto current(m_head->next);

    while(current != m_tail){

        auto last (current);
        current = current->next;

        last->prev->next = current;
        last->next->prev = last->prev;
        last->next = nullptr;
        last->prev = nullptr;
  
        delete last;


    }

}

template <typename T>
void list<T>::push_back( const T & value ) 
{
    Node<T> * new_node = new Node<T>();
    new_node->data = value;

    // Se ainda não estiver nenhum elemento inserido.
    if( m_tail->prev == m_head ){
        // Faz link do elemento com o head e o tail.
        new_node->next = m_tail;
        new_node->prev = m_head;

        // Link do head e do tail com o elemento.
        m_head->next = new_node;
        m_tail->prev = new_node;
    }
    else{
        // Link do elemento com o head e o primeiro elemento da lista.
        new_node->prev = m_tail->prev;
        new_node->next = m_tail;

        m_tail->prev->next = new_node;
        m_tail->prev = new_node;
    }
    // Incrementa o tamanho.
    m_size++;  
}

template <typename T>
void list<T>::push_front( const T & value )
{
    Node<T> * new_node = new Node<T>();
    new_node->data = value;

    // Se ainda não estiver nenhum elemento inserido.
    if( m_head->next == m_tail ){
        // Faz link do elemento com o head e o tail.
        new_node->next = m_tail;
        new_node->prev = m_head;

        // Link do head e do tail com o elemento.
        m_head->next = new_node;
        m_tail->prev = new_node;
    }
    else{
        // Link do elemento com o head e o primeiro elemento da lista.
        new_node->next = m_head->next;
        new_node->prev = m_head;

        m_head->next->prev = new_node;
        m_head->next = new_node;
    }
    // Incrementa o tamanho.
    m_size++;

}

template < typename T >
void list<T>::assign( const T & value ){ // replaces the content of the list with copies of values.

    auto current(m_head->next);

    if(m_head->next == m_tail ){
        std::cout << "A lista está vazia.\n";
    } else{

        while( current != m_tail){

            current->data = value;

            current = current->next;
        }

    }
} 

template < typename T >
const T & list<T>::back() const{
    return m_tail->prev->data;
}

template < typename T >
T & list<T>::back(){
    return m_tail->prev->data;
}

template < typename T >
const T & list<T>::front() const{
    return m_head->next->data;
}

template < typename T > 
T & list<T>::front(){
    return m_head->next->data;
}

template < typename T >
void list<T>::pop_front(){
    // obtem o m_head que é o primeiro elemento.
    auto curr(m_head->next);

    // obtem o segundo elemento da lista.
    auto next(curr->next);

    // Liga o head com o segundo valor.
    m_head->next = next;
    // Liga o segundo valor com o next.
    next->prev = m_head;

    // deleta o antigo primeiro elemento.
    delete curr;

    m_size--;


}

template < typename T >
void list<T>::pop_back(){

    // obtém o penultimo valor que deverá ser o novo m_tail.

    auto penultimo(this->m_tail->prev->prev);

    // obtém o valor atual para m_tail.
    auto ultimo(this->m_tail->prev);

    // liga o penultimo valor ao tail.
    penultimo->next = m_tail;
    // liga o tail com o penultimo valor.
    m_tail->prev = penultimo;

    // exclui o antigo último elemento.
    delete ultimo;

    m_size--;

}


template <typename T>
T& list<T>::at(list<T>::size_type & index)
{
    Node<T>* curr = this->m_head;

    if(curr == nullptr)
        throw std::out_of_range("Index provided is outside the array range.");

    for(auto i(0u); i < index; ++i)
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
    return list<T>::iterator(this->m_head->next);

}

template < typename T >
typename list<T>::const_iterator list<T>::cbegin() const{
    return list<T>::const_iterator(this->m_head->next);
}


template < typename T >
typename list<T>::iterator list<T>::end(){
    return list<T>::iterator(this->m_tail);
}


template < typename T >
typename list<T>::const_iterator list<T>::cend() const{
    return list<T>::const_iterator(this->m_tail);
}


// List container operations that require iterators
template < typename T >
template < typename InItr >
typename list<T>::iterator list<T>::insert(list<T>::iterator pos, InItr first, InItr last )
{
   /* O iterador 'InItr' é um iterador qualquer que desconhecemos o comportamento.
     * O que temos que fazer é que os valores armazenados no itervalo possam ser acessiveis
     * pela nossa list. Sabendo que o node usado dentro do intervalo pode ser incompativel
     * com nosso node.
     */

    /* guarda uma posição antes da posição a ser inserida, pois no futuro o next dela será o primeiro
     * elemento a ser inserido*/
    auto inserted_pos_before(list<T>::iterator(pos.current->prev));
    inserted_pos_before.current->next = pos.current->next;

    // percorremos o range
    Node<T> *new_node;

    auto size = std::distance(first, last);
    /* não foi usado o while diretamente com ranges pois o iterator da lista do STL não tem
     * o operador '<', e mesmo que existisse causaria perda de desempenho, visto que é necessário
     * percorrer a lista inteira para encontrar um dos iteratores e determina se a posição é menor.
     * Por um problema equivalente, não vale a pena usar o operador [], mesmo sabendo as posições.*/
     
    auto current_node(pos.current->prev);
   
    for(auto i(0); i < size; i++)
    {
        new_node = new Node<T>(*first, current_node);
        current_node->next = new_node;
        current_node = new_node;
        first++;
    }
    
    current_node->next = pos.current;
    pos.current->prev = current_node;

    return inserted_pos_before.current->next;
}

template < typename T >
typename list<T>::iterator list<T>::insert(list<T>::iterator pos, const T & value)
{
    // cria o no a ser inserido
    Node<T>* new_node = new Node<T>(value, pos.current->prev, pos.current);
    // caso especial da lista vazia
    if(pos.current == nullptr)
    {
        m_head = new_node;
        m_tail = new_node;
    }

    // Adiciona a quantidade de novos elementos no vetor.
    m_size++;

    // caso especial: inicio da lista
    if(pos.current->prev == nullptr)
    {
        pos.current->prev = new_node;
        m_head = new_node;
    }
    else if( pos.current->next == nullptr ){            // !< caso em que o elemento a ser inserido é no final da lista.
        pos.current->next = new_node;
        m_tail = new_node;
    }
    else
    {
        pos.current->prev->next = new_node;
        pos.current->prev = new_node;
    }

    return new_node->next;
}



template < typename T >
typename list<T>::iterator list<T>::insert(list<T>::iterator pos,  std::initializer_list<T> ilist)
{
    /* guarda uma posição antes da posição a ser inserida, pois no futuro o next dela será o primeiro
     * elemento a ser inserido*/
    auto inserted_pos_before(list<T>::iterator(pos.current->prev));
    inserted_pos_before.current->next = pos.current->next;

    // percorremos o range
    Node<T> *new_node;
    
    auto first = ilist.begin();

    auto size = std::distance(first, ilist.end());
     
    auto current_node(pos.current->prev);
   
    for(auto i(0); i < size; i++)
    {
        new_node = new Node<T>(*first, current_node);
        current_node->next = new_node;
        current_node = new_node;
        first++;
    }
    
    current_node->next = pos.current;
    pos.current->prev = current_node;

    return list<T>::iterator(inserted_pos_before.current->next);
}

template < typename T >
typename list<T>::iterator list<T>::erase( list<T>::iterator pos ){

    auto antes(pos.current->prev);
    auto depois(pos.current->next);

    pos.current->next = nullptr;
    pos.current->prev = nullptr;

    antes->next = depois;
    depois->prev = antes;

    delete pos.current;

    return depois;

}

template < typename T >
typename list<T>::iterator list<T>::erase( list<T>::iterator first, list<T>::iterator last ){

    auto f(first.current);
    auto pos(f->prev);

    auto l(last.current);

    while(f != l){

        auto next_ = f->next;

        f->prev->next = f->next;
        f->next->prev = f->prev;

        f->next = nullptr;
        f->prev = nullptr;

        delete f;

        f = next_;

    }

    return pos->next;

}

template < typename T >
void list<T>::assign( list<T>::size_type count, const T& value )
{
    this->clear();
    m_size = count;
    
    Node<T>* new_node; 
    Node<T>* prev_node = m_head;
    
    for(auto i(0u); i < count; ++i)
    {
        new_node = new Node<T>(value, prev_node, nullptr);
        prev_node->next = new_node;
        prev_node = new_node;
    }
    new_node->next = m_tail;
    m_tail->prev = new_node;
    return;
    
}

template < typename T>
template < typename InItr>
void list<T>::assign( InItr first, InItr last )
{
    this->clear();
    
    Node<T> *new_node;
    m_size = std::distance(first, last);
    auto current_node(m_head);
   
    for(auto i(0); i < m_size; i++)
    {
        new_node = new Node<T>(*first, current_node);
        current_node->next = new_node;
        current_node = new_node;
        first++;
    }
    
    current_node->next = m_tail;
    m_tail->prev = current_node;

    return;
}

template < typename T>
void list<T>::assign( std::initializer_list<T> ilist ) 
{
    this->clear();
    
    Node<T> *new_node;
    auto first = ilist.begin();
    m_size = std::distance(first, ilist.end());
    auto current_node(m_head);
   
    for(auto i(0); i < m_size; i++)
    {
        new_node = new Node<T>(*first, current_node);
        current_node->next = new_node;
        current_node = new_node;
        first++;
    }
    
    current_node->next = m_tail;
    m_tail->prev = current_node;

    return;
}

template < typename T >
typename list<T>::iterator list<T>::find( list<T>::iterator pos, const T & target ) const{

    auto prev( pos.current->prev );
    auto current( pos.current );

    if( current != m_tail ){
        while( current != m_tail and current->data != target ){
            prev = current;
            current = current->next;
        }
    }


    return list<T>::iterator(prev);

}

template < typename T >
typename list<T>::iterator list<T>::find( const T & target ) const{

    auto prev( m_head );
    auto current( m_head->next );

    if( current != m_tail ){
        while( current != m_tail and current->data != target ){
            prev = current;
            current = current->next;
        }
    }

    return list<T>::iterator(prev);

}
