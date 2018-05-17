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
    
    std::cout << "\n>>> GERANDO LISTA COM NUMERAÇÃO\n";
    ls::list<int> v1(10);
    v1.print();
    std::cout << std::endl;


    ls::list<int> valores;
    std::list<int> lista_auxiliar = {1, 2, 3, 4};
    std::cout << "\n>>>  TESTE DO push_front(), push_back()\n";
    valores.push_front(20);
    valores.push_front(10);
    valores.push_back(40);
    valores.push_back(30);

    std::cout << "LISTA VALORES = ";
    valores.print();

    std::cout << "\n\n>>>  TESTE DO construtor a partir de outra lista\n";
    ls::list<int> valores_copia(valores);
    std::cout << "NOVA LISTA = ";
    valores_copia.print();

    std::cout << std::endl;

    std::list<int> std_list_b = {4, 5, 6, 7, 8}; 
 
    auto first_ = std_list_b.begin();
    auto last_ = std_list_b.end();

    std::cout << "\n>>> GERANDO LISTA COM PONTEIROS\n";
    ls::list<int> v2(first_, last_);
    v2.print();
    std::cout << std::endl;

    std::cout << "\n>>> GERANDO LISTA COM LISTA INICIALIZADORA\n";
    ls::list<int> v3({2,3,4,5,6,7});
    v3.print();
    std::cout << std::endl;

    std::cout << "\n>>> GERANDO LISTA COM ATRIBUIÇÃO DE UMA LISTA INICIALIZADORA\n";
    ls::list<int> v4;
    v4 = {5,10,15,20,25};
    v4.print();
    std::cout << std::endl;

    std::cout << "\n\n>>>  TESTE DO operador de atribuição\n";
    std::cout << "LISTA1 = ";
    valores.print();
    std::cout << std::endl;
    ls::list<int> valores_atr;
    valores_atr = valores;
    std::cout << "LISTA ATRIBUIÇÃO = ";
    valores_atr.print();
    std::cout << std::endl;

    std::cout << "\n\n>>>  TESTE DO SIZE(), EMPTY()\n";
    std::cout << " Quantidade: " << valores.size() << " Vazia? ";
    if(valores.empty())
        std::cout << "SIM" << std::endl;
    else
        std::cout << "NÃO" << std::endl; 

    std::cout << "\n>>>  TESTE DO POP_FRONT(), POP_BACK()";
    std::cout << "\nLISTA VALORES: ";
    valores.print();
    std::cout << "\nPOP_FRONT():";
    valores.pop_front();
    valores.print();
    std::cout << "\nPOP_BACK():";
    valores.pop_back();
    valores.print();
    std::cout << std::endl;

    std::cout << "\n>>>  TESTE DO FRONT(), BACK()";
    std::cout << "\nLISTA VALORES: ";
    valores.print();
    std::cout << " Front = " << valores.front() << "    Back = " << valores.back() << std::endl;
    
    std::cout << "\n>>> TESTE DO INSERT() - RANGES";
    std::cout << "\nLISTA VALORES: ";
    valores.print();
    auto result = valores.insert(valores.begin(), lista_auxiliar.begin(), lista_auxiliar.end());
    std::cout << "\nLISTA RESULTANTE: ";
    valores.print();
    std::cout << "\nRETORNO: " << *(result) << std::endl;

    std::cout << "\n>>>  TESTE DO ASSIGN(const T & value)";
    std::cout << "\nLISTA ORIGINAL: ";
    valores.print();
    valores.assign(2);
    std::cout << "\nLISTA MODIFICADA: ";
    valores.print();
    std::cout << "\n";

    std::cout << "\n>>> TESTE DO CLEAR()";
    std::cout << "\nLISTA ORIGINAL: ";
    valores.print();
    valores.clear();
    std::cout << "\nLISTA DEPOIS DO CLEAR():";
    valores.print();
    std::cout << std::endl;

    std::cout << "\n>>> TESTE DO ERASE(ITERATOR POS)\n";
    std::cout << "Lista: ";
    ls::list<int> e_1 = {1,2,3,4,5};
    e_1.print();

    std::cout << "\nApós o erase();\n";
    auto valor = e_1.erase(e_1.begin()+3);
    std::cout << "O valor agora ficou " << *valor <<  "\n";
    e_1.print();

    
    std::cout << "\n\n>>> Teste do find(value)\n";
    ls::list<int> f_1 = {5,10,15,20,25,30};
    auto pos = f_1.find(25);
    auto v = *pos;
    std::cout << "Valor: " << v;
    std::cout << std::endl;

    std::cout << "\n>>> Teste do find(ponteiro, value)\n";
    ls::list<int> f_2 = {5,10,15,20,25,30};
    auto pos2 = f_2.find(f_2.begin() +4, 30);
    std::cout << "Valor: " << *pos2;
    std::cout << std::endl;


    std::cout << "\n>>> Teste do erase(ponteiro, ponteiro)\n";
    ls::list<int> e_2 = {2,3,4,5,6,7,8,9,10,11,12,13,14};
    std::cout << "ANTES: ";
    e_2.print();
    e_2.erase(e_2.begin()+5,e_2.begin()+8);
    std::cout << "\nDEPOIS: ";
    e_2.print();
    
    
    std::cout << "\n>>> Teste do assign(count, value)\n";
    ls::list<int> a_2 = {2,3,4,5,6,7,8,9,10,11,12,13,14};
    std::cout << "ANTES: ";
    a_2.print();
    a_2.assign((size_t) 3, 9);
    std::cout << "\nDEPOIS: ";
    a_2.print();
    
    std::cout << "\n>>> Teste do assign(InItr, InItr)\n";
    ls::list<int> a_3 = {5,6,7,8,9,10,11,12,13,14};
    std::cout << "ANTES: ";
    a_3.print();
    a_3.assign(lista_auxiliar.begin(), lista_auxiliar.end());
    std::cout << "\nDEPOIS: ";
    a_3.print();
    
    std::cout << "\n>>> Teste do assign(ilist)\n";
    ls::list<int> a_4 = {5,6,7,8};
    std::cout << "ANTES: ";
    a_4.print();
    a_4.assign({9, 10, 11, 12});
    std::cout << "\nDEPOIS: ";
    a_4.print();
    std::cout << "\n\n>>> Everything okay!\n";

    std::cout << "\n>>> Teste do insert(ilist)\n";
    std::cout << "ANTES: ";
    a_4.print();
    a_4.insert(a_4.begin(), {13, 14, 15, 16});
    std::cout << "\nDEPOIS: ";
    a_4.print();
    std::cout << "\n\n>>> Everything okay!\n";

    

    /* ----------------------------------------------------------------------------------------------------- CRIAR OS PONTEIROS CONST

    std::cout << "================== TESTE DO OPERADOR==(LIST1, LIST2) ======================\nTESTE 1 - Listas:\n";
    v1.print();
    v2.print();
    std::cout << "As listas são ";
    if( v1 == v2 )
        std::cout << "iguais!\n";
    else
        std::cout << "diferentes!\n";
    ls::list<int> v1_1(v1);
    std::cout << "TESTE 2 - Listas:\n";
    v1.print();
    v1_1.print();
    std::cout << "As listas são ";
    if( v1 == v1_1 )
        std::cout << "iguais!\n";
    else
        std::cout << "diferentes!\n";

    std::cout << "================== TESTE DO OPERADOR!=(LIST1, LIST2) ======================\nTESTE 1 - Listas:\n";
    v1.print();
    v2.print();
    std::cout << "As listas são ";
    if( v1 != v2 )
        std::cout << "diferentes!\n";
    else
        std::cout << "iguais!\n";
    std::cout << "TESTE 2 - Listas:\n";
    v1.print();
    v1_1.print();
    std::cout << "As listas são ";
    if( v1 != v1_1 )
        std::cout << "diferentes!\n";
    else
        std::cout << "iguais!\n";
    
   */
    
#endif
    
    return 0;
}
