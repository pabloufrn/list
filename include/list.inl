#include <iostream>
/*TODO: remover coisas que forem desnecessarias*/

/// Implementa a infraestrutura para suportar um ponteiro bidirecional.
/*
/// Construtor a partir de um ponteiro. 
explicit MyIterator( pointer pt = nullptr );
/**/
/// Construtor a partir de uma referência a outra classe MyIterator<T>.
/*
MyIterator( const MyIterator<T> &);
/**/
/// Acessar o conteúdo o qual o ponteiro aponta.
/*
reference operator*( ) const;
/**/
/**/
/// Destrutor da classe.
/*
~MyIterator();
/**/
/// Operador de pré-incremento.
/*
MyIterator & operator++( );
/**/
/// Operador de pós-incremento.
/*
MyIterator operator++( int );
/**/
/// Operador de pré-decremento.
/*
MyIterator & operator--( );
/**/
/// Operador de pós-decremento.
/*
MyIterator operator--( int ); 
/**/
/// Operador de soma.
/*
MyIterator operator+( int );
/**/
/// Operador de subtração.
/*
MyIterator operator-( int );
/**/
/// Sobrecarga do operador ->.
/*
MyIterator * operator->( void ) const;
/**/
/// Operador de comparação se é <=.
/*
bool operator<=( const MyIterator<T> & rhs ) const;
/**/
/// Operador de comparação se é >=.
/*
bool operator>( const MyIterator<T> & rhs ) const;
/**/
/// Operador de comparação se é <
/*
bool operator<( const MyIterator<T> & rhs ) const;
/**/
/// Operador de comparação se é >
/*
bool operator>=( const MyIterator<T> & rhs ) const;
/**/
/// Comparar dois iteradores se são iguais.
/*
bool operator==( const MyIterator<T> & rhs ) const;
/**/
/// Comprar dois iteradores se são difentes.
/*
bool operator!=( const MyIterator<T> & rhs ) const;
/**/
/// Operador de atribuição.
/*
MyIterator & operator=( const MyIterator<T> & rhs );
/**/
// Operador de diferença entre ponteiros.
/*
difference_type operator-( const MyIterator & rhs ) const;
/**/




    /*
#include <iostream>

using namespace std;

template <typename T>
struct list
{
struct node
{
T value;
node* next;
node* prev;
};

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
node & at(int index)
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
    cout << "pos 1: " << mylist.at(1).value << "\n";
    mylist.print();
}



*/
