#include <iostream>
#include <memory>
#include <cassert>
#include "../include/list.h"
#include <list>

using namespace std;
/*
bool cmp(ls::list& va, std::list& vb){
    auto size = va.size();
    if(size != vb.size())
        return false;
    for(auto i(0u); i < size; i++){
        if(va[i] != vb[i])
            return false;
    }
    return true;
}

std::ostream & operator<<( std::ostream& os_, const std::list<int>& v_ ){
    os_ << "Vetor = [ ";
    for( auto i(0u); i < v_.size(); i++ ){
        os_ << v_[i] << " ";
    }
    os_ << "]";
    
    return os_;
}
*/
int main(){
#ifdef DEBUG
    
    // DEBUG
    
    /*unique_ptr< ls::list<int> > list_a(new ls::list<int>);
    unique_ptr< ls::list<int> > list_b(new ls::list<int>);
    unique_ptr< std::list<int> > std_list_a(new std::list<int>);
    unique_ptr< std::list<int> > std_list_b(new std::list<int>);
    
    ls::list<int>::iterator it_ls_a;
    std::list<int>::iterator it_std_a;
    ls::list<int>::iterator it_ls_b;
    std::list<int>::iterator it_std_b;
    // inserção três Elementos ordenado
    
    list_a->push_front(1);
    list_a->print();
    std::cout << "\n";
    list_a->push_front(2);
    list_a->print();
    std::cout << "\n";
    list_a->push_front(3);
    list_a->print();
    std::cout << "\n";

    *std_list_b = {4, 5, 6}; 
 
    auto first = std_list_b->cbegin();
    auto last = std_list_b->cend();
   // ++last;
    std::cout << "first: " << *first << " last: " << *last << std::endl;
    auto result = list_a->insert(++list_a->begin(), first , last);
    list_a->print();
    std::cout << " result: " << *result << std::endl;
    std::cout << "begin : " << *list_a->begin() << std::endl;
    result = list_a->insert(++list_a->begin(), 7);
    list_a->print();
    std::cout << " result: " << *result << std::endl;*/


    /// =====================================    TESTES CORRETOS TODOS    ================================================  
    
    std::cout << "GERANDO LISTA COM NUMERAÇÃO\n";
    ls::list<int> v1(10);
    v1.print();
    std::cout << std::endl;


    ls::list<int> valores;
    std::cout << " ==============  TESTE DO push_front(), push_back()  =================  \n";
    valores.push_front(20);
    valores.push_front(10);
    valores.push_back(40);
    valores.push_back(30);

    std::cout << "LISTA VALORES = ";
    valores.print();

    std::cout << "\n==============  TESTE DO construtor a partir de outra lista  =================  \n";
    ls::list<int> valores_copia(valores);
    std::cout << "NOVA LISTA = ";
    valores_copia.print();

    std::cout << std::endl;

    std::list<int> std_list_b = {4, 5, 6, 7, 8}; 
 
    auto first_ = std_list_b.begin();
    auto last_ = std_list_b.end();

    std::cout << "GERANDO LISTA COM PONTEIROS\n";
    ls::list<int> v2(first_, last_);
    v2.print();
    std::cout << std::endl;

    std::cout << "GERANDO LISTA COM LISTA INICIALIZADORA\n";
    ls::list<int> v3({2,3,4,5,6,7});
    v3.print();
    std::cout << std::endl;

    std::cout << "GERANDO LISTA COM ATRIBUIÇÃO DE UMA LISTA INICIALIZADORA\n";
    ls::list<int> v4;
    v4 = {5,10,15,20,25};
    v4.print();
    std::cout << std::endl;

    std::cout << "\n==============  TESTE DO operador de atribuição  =================  \n";
    std::cout << "LISTA1 = ";
    valores.print();
    std::cout << std::endl;
    ls::list<int> valores_atr;
    valores_atr = valores;
    std::cout << "LISTA ATRIBUIÇÃO = ";
    valores_atr.print();
    std::cout << std::endl;

    std::cout << "\n====================  TESTE DO SIZE(), EMPTY()  ====================  \n";
    std::cout << " Quantidade: " << valores.size() << " Vazia? ";
    if(valores.empty())
        std::cout << "SIM" << std::endl;
    else
        std::cout << "NÃO" << std::endl; 

    std::cout << "================  TESTE DO POP_FRONT(), POP_BACK()  ================  ";
    std::cout << "\nLISTA VALORES: ";
    valores.print();
    std::cout << "\nPOP_FRONT():";
    valores.pop_front();
    valores.print();
    std::cout << "\nPOP_BACK():";
    valores.pop_back();
    valores.print();
    std::cout << std::endl;

    

    std::cout << "====================  TESTE DO FRONT(), BACK()  ====================  ";
    std::cout << "\nLISTA VALORES: ";
    valores.print();
    std::cout << " Front = " << valores.front() << "    Back = " << valores.back() << std::endl;

    std::cout << "==============  TESTE DO ASSIGN(const T & value)  ==================  ";
    std::cout << "\nLISTA ORIGINAL: ";
    valores.print();
    valores.assign(2);
    std::cout << "\nLISTA MODIFICADA: ";
    valores.print();
    std::cout << "\n";

    std::cout << "================== TESTE DO CLEAR() ======================";
    std::cout << "\nLISTA ORIGINAL: ";
    valores.print();
    valores.clear();
    std::cout << "\nLISTA DEPOIS DO CLEAR():";
    valores.print();
    std::cout << std::endl;

    
   // result = list_a->insert(++list_a->begin(), {8, 9});
   // list_a->print();
    //std::cout << " result: " << *result << std::endl;

    /*
    assert(cmp(*av, *a_v) && "Error at push_front methode");
    
    av->push_front(2);
    av->push_front(1);
    a_v->insert(a_v->begin(), 2);
    a_v->insert(a_v->begin(), 1);
    
    assert(cmp(*av, *a_v) && "Error at push_front methode.");
    
    bv = unique_ptr < ls::list<int> > ( new sc::vector<int> ( *av ) );
    b_v = unique_ptr < std::list<int> > ( new std::vector<int> ( *a_v ) );
    
    assert(cmp(*bv, *b_v) && "Error at copy construtor.");
    
    (*bv)[0] = 5;
    (*b_v)[0] = 5; 
    
    assert(cmp(*bv, *b_v) && "Error at [] operator.");
    
    assert(cmp(*av, *a_v) && "Error at copy construtor..");
    
    *av = std::move(*bv);
    *a_v = std::move(*b_v);
    
    assert(cmp(*av, *a_v) && cmp(*bv, *b_v) && "Error at move assignment.");
    
    bv = unique_ptr < ls::list<int> >  ( new sc::vector<int> {6, 7, 8, 9, 10} );
    b_v = unique_ptr < std::list<int> >  ( new std::vector<int> {6, 7, 8, 9, 10} );
    
    assert(cmp(*bv, *b_v) && "Error at initalizer list constructor.");
    
    av = unique_ptr < ls::list<int> >  ( new sc::vector<int> (bv->begin()+1, bv->begin()+4) );
    a_v = unique_ptr < std::list<int> >  ( new std::vector<int> (b_v->begin()+1, b_v->begin()+4) );
    
    assert(cmp(*av, *a_v) && "Error at ranges constructor.");
    
    ls::swap(*av, *bv); // o std::swap nao chamará sc::swap. Ao invés disso usará o move-constructor e move-assignment.
    std::swap(*a_v, *b_v);
    
    assert(cmp(*av, *a_v) && cmp(*bv, *b_v) && "Error at swap methode.");
    
    *av = *bv;
    *a_v = *b_v;
    
    assert(cmp(*av, *a_v) && cmp(*bv, *b_v) && "Error at copy assignment.");
    
    av->pop_front();
    a_v->erase(a_v->begin());
    
    assert(cmp(*av, *a_v) && "Error at pop_front function.");
    
    av->pop_back();
    a_v->pop_back();
    
    assert(cmp(*av, *a_v) && "Error at pop_back function.");
//     no começo
    std::cout << *av << "\n";
    std::cout << *a_v << "\n";
    itc1 = av->insert(av->begin(), 11);
    itd1 = a_v->insert(a_v->begin(), 11);
    std::cout << *av << "\n";
    std::cout << *a_v << "\n";
//     apos o ultimo válido
    itc2 = av->insert(av->end(), 12);
    itd2 = a_v->insert(a_v->end(), 12);
    std::cout << *av << " capacity: " << av->capacity() << std::endl;
    std::cout << *a_v << "\n";
    
//     no ultimo válido
    itc3 = av->insert(av->end()-1, 13);
    itd3 = a_v->insert(a_v->end()-1, 13);
    std::cout << *av << " capacity: " << av->capacity() << std::endl;
    std::cout << *a_v << "\n";
    assert(cmp(*av, *a_v) && "Error at insert element function.");
    
    
    //assert(*itc1 == *itd1 && *itc2 == *itd2 && *itc3 == *itd3 && "Error at return of insert element function.");

    // no começo
    itc1 = av->insert(av->begin(), bv->begin(), bv->end());
    itd1 = a_v->insert(a_v->begin(), b_v->begin(), b_v->end());

    // antes e apos o last
    itc2 = av->insert(av->end()-1, bv->begin(), bv->end());
    itd2 = a_v->insert(a_v->end()-1, b_v->begin(), b_v->end());

    // no last
    itc3 = av->insert(av->end(), bv->begin(), bv->end());
    itd3 = a_v->insert(a_v->end(), b_v->begin(), b_v->end());

    assert(cmp(*av, *a_v) && "Error at insert range function.");
    //assert(*itc1 == *itd1 && *itc2 == *itd2 && *itc3 == *itd3 && "Error at return of insert range function.");
    // no começo
    itc1 = av->insert(av->begin(), {14, 15, 16});
    itd1 = a_v->insert(a_v->begin(), {14, 15, 16});
    // antes e apos o last
    itc2 = av->insert(av->end()-1, {17, 18, 19});
    itd2 = a_v->insert(a_v->end()-1, {17, 18, 19});
    // no last
    itc3 = av->insert(av->end(), {20, 21, 22});
    itd3 = a_v->insert(a_v->end(), {20, 21, 22});
    
    assert(cmp(*av, *a_v) && "Error at insert initalizer list function.");
    //assert(*itc1 == *itd1 && *itc2 == *itd2 && *itc3 == *itd3 && "Error at return of insert initalizer list function.");
   


    unique_ptr < ls::list<int> > bv1 ( new sc::vector<int> {23, 24, 25, 26, 27, 28, 29, 30} );
    unique_ptr < std::list<int> > b_v1 ( new std::vector<int> {23, 24, 25, 26, 27, 28, 29, 30} );

    *bv = *bv1;
    *b_v =  *b_v1;
    *av = *bv; 
    *a_v = *b_v;
    
    itc1 = bv->erase(bv->begin(), bv->begin()+3);
    itd1 = b_v->erase(b_v->begin(), b_v->begin()+3);
    
    itc2 = bv->erase(bv->end()-2, bv->end());
    itd2 = b_v->erase(b_v->end()-2, b_v->end());
    
    assert(cmp(*bv, *b_v) && "Error at range erase function.");
    assert(*itc1 == *itd1 && *itc2 == *itd2 && "Error at return of range erase function.");
    
    *bv = *av; 
    *b_v = *a_v;
    
    
    itc1 = bv->erase(bv->begin()+2); 
    itd1 = b_v->erase(b_v->begin()+2);
    
    assert(cmp(*bv, *b_v) && "Error at range erase function.");
    assert(*itc1 == *itd1 && "Error at return of range erase function.");
    
    std::cout << *bv << std::endl;
    std::cout << *b_v << std::endl;

    unsigned x = 2;
    bv->assign( 5, x );
    b_v->assign( 5, x );

    std::cout << *bv << std::endl;
    std::cout << *b_v << std::endl;

    assert( cmp(*bv, *b_v) && "Error at assign in a element.");

    bv->assign(  {1,2,3,4} );
    b_v->assign( {1,2,3,4} );

    assert(cmp(*bv, *b_v) && "Error at assign in a initializer_list.");

    bv->assign(  av->begin(), av->end() );
    b_v->assign( a_v->begin(), a_v->end() );

    assert(cmp(*bv, *b_v) && "Error at assign in a range.");
    */
    
#endif
    
    return 0;
}
