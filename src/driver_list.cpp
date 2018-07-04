#include <iostream>
#include <memory>
#include <cassert>
#include "../include/list.h"
#include <list>

using namespace std;

template < typename T >
bool cmp(ls::list<T> & va, std::list<T> & vb){
    auto f(va.cbegin());
    auto size = va.size();
    if(size != vb.size())

        return false;


    for( auto & a : vb ){
        if(*(f) != a)
            return false;

        f++;
    }
    return true;
}

int main(){
#ifdef DEBUG


    /// =====================================    TESTS   ================================================  
    
    std::cout << "\n>>> GERANDO LISTA COM NUMERAÇÃO\n";
    std::list<int> v1_std(10);
    
    ls::list<int> v1(10);
    
    std::cout << v1 << std::endl;

    assert(cmp(v1, v1_std) && "Error at generate with a number");

    ls::list<int> valores;
    std::list<int> lista_auxiliar;
    std::cout << "\n>>>  TESTE DO push_front(), push_back()\n";
    lista_auxiliar.push_front(20);
    lista_auxiliar.push_front(10);
    lista_auxiliar.push_back(40);
    lista_auxiliar.push_back(30);
    valores.push_front(20);
    valores.push_front(10);
    valores.push_back(40);
    valores.push_back(30);

    assert( cmp(valores, lista_auxiliar) && "Error at push_front() and push_back");

    std::cout << "LISTA VALORES = " << valores;

    std::cout << "\n\n>>>  TESTE DO construtor a partir de outra lista\n";
    ls::list<int> valores_copia(valores);
    std::cout << "NOVA LISTA = ";

    std::cout << valores_copia << std::endl;

    assert( (valores_copia == valores) && "Error at generate from another list");

    std::list<int> std_list_b = {4, 5, 6, 7, 8}; 
 
    auto first_ = std_list_b.begin();
    auto last_ = std_list_b.end();

    std::cout << "\n>>> GERANDO LISTA COM PONTEIROS\n";
    ls::list<int> v2(first_, last_);
    std::list<int> v2_std(first_, last_);
    std::cout << v2 << std::endl;

    assert( cmp(v2, v2_std) && "Error at generate from pointers");

    std::cout << "\n>>> GERANDO LISTA COM LISTA INICIALIZADORA\n";
    ls::list<int> v3({2,3,4,5,6,7});
    std::list<int> v3_std({2,3,4,5,6,7});
    std::cout << v3 << std::endl;

    assert( cmp(v3, v3_std) && "Error at generate from initialization list");

    std::cout << "\n>>> GERANDO LISTA COM ATRIBUIÇÃO DE UMA LISTA INICIALIZADORA\n";
    ls::list<int> v4;
    std::list<int> v4_std;
    v4 = {5,10,15,20,25};
    v4_std = {5,10,15,20,25};
    std::cout << v4 << std::endl;

    assert( cmp(v4, v4_std) && "Error at generate assignment list from initialization list");

    std::cout << "\n\n>>>  TESTE DO operador de atribuição\n";
    std::cout << "LISTA1 = " << valores;
    std::cout << std::endl;
    ls::list<int> v5;
    std::list<int> v5_std;
    v5 = valores;
    v5_std = lista_auxiliar;

    std::cout << "LISTA ATRIBUIÇÃO = " << v5;
    std::cout << std::endl;

    assert( cmp(v5, v5_std) && "Error at assignment operator");

    std::cout << "\n\n>>>  TESTE DO SIZE(), EMPTY()\n";
    std::cout << " Quantidade: " << valores.size() << " Vazia? ";
    if(valores.empty())
        std::cout << "SIM" << std::endl;
    else
        std::cout << "NÃO" << std::endl; 


    assert( (valores.size() ==  lista_auxiliar.size()) && "Error at size()");
    assert( (valores.empty() ==  lista_auxiliar.empty()) && "Error at empty()");

    std::cout << "\n>>>  TESTE DO POP_FRONT(), POP_BACK()";
    std::cout << "\nLISTA VALORES: " << valores;
    std::cout << "\nPOP_FRONT():";
    valores.pop_front();
    lista_auxiliar.pop_front();
    std::cout << valores << "\nPOP_BACK():";
    valores.pop_back();
    lista_auxiliar.pop_back();
    std::cout << valores << std::endl;

    assert( cmp(valores, lista_auxiliar) && "Error at pop_front() and pop_back()");

    std::cout << "\n>>>  TESTE DO FRONT(), BACK()";
    std::cout << "\nLISTA VALORES: " << valores;
    std::cout << " Front = " << valores.front() << "    Back = " << valores.back() << std::endl;

    assert( (valores.front() == lista_auxiliar.front()) && "Error at front()");
    assert( (valores.back() == lista_auxiliar.back()) && "Error at back()");
    
    std::cout << "\n>>> TESTE DO INSERT() - RANGES";
    std::cout << "\nLISTA VALORES: " << valores;
    std::list<int> aux = {1,2,3,4};
    auto result = valores.insert(valores.begin(), aux.begin(), aux.end());
    auto result_std = lista_auxiliar.insert(lista_auxiliar.begin(), aux.begin(), aux.end());
    std::cout << "\nLISTA RESULTANTE: ";
    std::cout << valores << "\nRETORNO: " << *(result) << std::endl;

    assert( (*result == *result_std ) && "Error at insert() - ranges");


    // Não existe assign para os stl com essa assinatura.
    std::cout << "\n>>>  TESTE DO ASSIGN(const T & value)";
    std::cout << "\nLISTA ORIGINAL: " << valores;
    valores.assign(2);
    std::cout << "\nLISTA MODIFICADA: " << valores;
    std::cout << "\n";


    std::cout << "\n>>> TESTE DO CLEAR()";
    std::cout << "\nLISTA ORIGINAL: " << valores;
    valores.clear();
    lista_auxiliar.clear();
    std::cout << "\nLISTA DEPOIS DO CLEAR():\n";
    std::cout << valores << std::endl;

    assert( cmp(valores, lista_auxiliar) && "Error at clear!");

    std::cout << "\n>>> TESTE DO ERASE(ITERATOR POS)\n";
    std::cout << "Lista: ";
    ls::list<int> e_1 = {1,2,3,4,5};
    std::list<int> e_1_std = {1,2,3,4,5};

    std::cout << e_1 << "\nApós o erase();\n";
    auto valor = e_1.erase(e_1.begin());
    auto valor_std = e_1_std.erase(e_1_std.begin());
    std::cout << "O valor agora ficou " << *valor <<  "\n" << e_1;

    assert( (*valor == *valor_std) && "Error at erase()!");


    // A versão STL não possui esse método.    
    std::cout << "\n\n>>> Teste do find(value)\n";
    ls::list<int> f_1 = {5,10,15,20,25,30};
    auto pos = f_1.find(25);
    auto v = *pos;
    std::cout << "Valor: " << v;
    std::cout << std::endl;

    assert( (*pos == 20) && " Error at find()");

    // A versão STL não possui esse método.
    std::cout << "\n>>> Teste do find(ponteiro, value)\n";
    ls::list<int> f_2 = {5,10,15,20,25,30};
    auto pos2 = f_2.find(f_2.begin()+4, 30);
    std::cout << "Valor: " << *pos2;
    std::cout << std::endl;

    assert( (*pos2 == 25) && " Error at find()");


    std::cout << "\n>>> Teste do erase(ponteiro, ponteiro)\n";
    ls::list<int> e_2 = {2,3,4,5,6,7,8,9,10,11,12,13,14};
    std::list<int> e_2_std = {2,3,4,5,6,7,8,9,10,11,12,13,14};
    std::cout << "ANTES: " << e_2;
    e_2.erase(e_2.begin(),e_2.end());
    e_2_std.erase(e_2_std.begin(), e_2_std.end());
    std::cout << "\nDEPOIS: " << e_2;
    
    assert( cmp(e_2, e_2_std) && "Error at erase" );

    std::cout << "\n>>> Teste do assign(count, value)\n";
    ls::list<int> a_2_1 = {2,3,4,5,6,7,8,9,10,11,12,13,14};
    std::list<int> a_2_1_std = {2,3,4,5,6,7,8,9,10,11,12,13,14};
    std::cout << "ANTES: " << a_2_1;
    a_2_1.assign((size_t) 3, 9);
    a_2_1_std.assign((size_t) 3, 9);
    std::cout << "\nDEPOIS: " << a_2_1;

    assert( cmp(a_2_1, a_2_1_std) && "Error at assign");
    
    std::cout << "\n>>> Teste do assign(InItr, InItr)\n";
    ls::list<int> a_3 = {5,6,7,8,9,10,11,12,13,14};
    std::list<int> a_3_std = {5,6,7,8,9,10,11,12,13,14};
    std::cout << "ANTES: " << a_3;
    a_3.assign(lista_auxiliar.begin(), lista_auxiliar.end());
    a_3_std.assign(lista_auxiliar.begin(), lista_auxiliar.end());
    std::cout << "\nDEPOIS: " << a_3;
    
    assert( cmp(a_3, a_3_std) && "Error at assign");

    std::cout << "\n>>> Teste do assign(ilist)\n";
    ls::list<int> a_4 = {5,6,7,8};
    std::list<int> a_4_std = {5,6,7,8};
    std::cout << "ANTES: " << a_4;
    a_4.assign({9, 10, 11, 12});
    a_4_std.assign({9,10,11,12});
    std::cout << "\nDEPOIS: ";
    std::cout << a_4 << "\n\n>>> Everything okay!\n";

    assert( cmp(a_4, a_4_std) && "Error at assign" );

    std::cout << "\n>>> Teste do insert(pos, ilist)\n";
    std::cout << "ANTES: " << a_4;
    a_4.insert(++a_4.begin(), {13, 14, 15, 16});
    a_4_std.insert(++a_4_std.begin(), {13,14,15,16});
    std::cout << "\nDEPOIS: ";
    std::cout << a_4 << "\n\n>>> Everything okay!\n";

    assert( cmp(a_4, a_4_std) && "Error at insert(pos, ilist)");

    
    
    std::cout << "================== TESTE DO OPERADOR==(LIST1, LIST2) ======================\nTESTE 1 - Listas:\n";
    std::cout << v1 << std::endl;
    std::cout << v2 << "\nAs listas são ";
    if( v1 == v2 )
        std::cout << "iguais!\n";
    else
        std::cout << "diferentes!\n";

    ls::list<int> v1_1(v1);

    std::cout << "TESTE 2 - Listas:\n";
    std::cout << v1 << std::endl;
    std::cout << v1_1 << "\nAs listas são ";
    if( v1 == v1_1 )
        std::cout << "iguais!\n";
    else
        std::cout << "diferentes!\n";


    std::cout << "================== TESTE DO OPERADOR!=(LIST1, LIST2) ======================\nTESTE 1 - Listas:\n";
    std::cout << v1 << std::endl;
    std::cout << v2 << "\nAs listas são ";
    if( v1 != v2 )
        std::cout << "diferentes!\n";
    else
        std::cout << "iguais!\n";

    std::cout << "TESTE 2 - Listas:\n";
    std::cout << v1 << std::endl;
    std::cout << v1_1 << "\nAs listas são ";
    if( v1 != v1_1 )
        std::cout << "diferentes!\n";
    else
        std::cout << "iguais!\n";
    
    std::cout << "================== TESTE DO OPERADOR cbegin ======================\nTESTE 1 - Listas:\n";
   
    std::cout << "cbegin: " << *a_4.cbegin() << std::endl;

    std::cout << "================== TESTE DO USANDO std::next ======================\nTESTE 1 - Listas:\n";

    auto it = std::next(a_4.begin(), 2);

    std::cout << "next: " << *it << std::endl;



    
#endif
    
    return 0;
}
