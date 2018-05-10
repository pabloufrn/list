#include <iostream>
#include <memory>
#include <cassert>
#include "list.hpp"
#include <list>

using namespace std;
/*
bool cmp(sc::list& va, std::list& vb){
    auto size = va.size();
    if(size != vb.size())
        return false;
    for(auto i(0u); i < size; i++){
        if(va[i] != vb[i])
            return false;
    }
    return true;
}

std::ostream & operator<<( std::ostream& os_, const std::vector<int>& v_ ){
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
    
    unique_ptr< sc::vector<int> > av(new sc::vector<int>);
    unique_ptr< sc::vector<int> > bv(new sc::vector<int>);
    unique_ptr< std::vector<int> > a_v(new std::vector<int>);
    unique_ptr< std::vector<int> > b_v(new std::vector<int>);
    
    sc::vector<int>::iterator itc1;
    std::vector<int>::iterator itd1;
    sc::vector<int>::iterator itc2;
    std::vector<int>::iterator itd2;
    sc::vector<int>::iterator itc3;
    std::vector<int>::iterator itd3;
    // inserção três Elementos ordenado
    
    av->push_back(3);
    av->push_back(4);
    a_v->push_back(3);
    a_v->push_back(4);
    
    assert(cmp(*av, *a_v) && "Error at push_back methode");
    
    av->push_front(2);
    av->push_front(1);
    a_v->insert(a_v->begin(), 2);
    a_v->insert(a_v->begin(), 1);
    
    assert(cmp(*av, *a_v) && "Error at push_front methode.");
    
    bv = unique_ptr < sc::vector<int> > ( new sc::vector<int> ( *av ) );
    b_v = unique_ptr < std::vector<int> > ( new std::vector<int> ( *a_v ) );
    
    assert(cmp(*bv, *b_v) && "Error at copy construtor.");
    
    (*bv)[0] = 5;
    (*b_v)[0] = 5; 
    
    assert(cmp(*bv, *b_v) && "Error at [] operator.");
    
    assert(cmp(*av, *a_v) && "Error at copy construtor..");
    
    *av = std::move(*bv);
    *a_v = std::move(*b_v);
    
    assert(cmp(*av, *a_v) && cmp(*bv, *b_v) && "Error at move assignment.");
    
    bv = unique_ptr < sc::vector<int> >  ( new sc::vector<int> {6, 7, 8, 9, 10} );
    b_v = unique_ptr < std::vector<int> >  ( new std::vector<int> {6, 7, 8, 9, 10} );
    
    assert(cmp(*bv, *b_v) && "Error at initalizer list constructor.");
    
    av = unique_ptr < sc::vector<int> >  ( new sc::vector<int> (bv->begin()+1, bv->begin()+4) );
    a_v = unique_ptr < std::vector<int> >  ( new std::vector<int> (b_v->begin()+1, b_v->begin()+4) );
    
    assert(cmp(*av, *a_v) && "Error at ranges constructor.");
    
    sc::swap(*av, *bv); // o std::swap nao chamará sc::swap. Ao invés disso usará o move-constructor e move-assignment.
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
    
    /*
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
   


    unique_ptr < sc::vector<int> > bv1 ( new sc::vector<int> {23, 24, 25, 26, 27, 28, 29, 30} );
    unique_ptr < std::vector<int> > b_v1 ( new std::vector<int> {23, 24, 25, 26, 27, 28, 29, 30} );

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
