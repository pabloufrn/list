# LIST

# Compilação

Compilar Se estiver em um ambiente GNU/Linux com o make file disponível, você poderá usar os comandos
make debug: para compilar o arquivo em modo de depuração; e

make: para compilar o arquivo normalmente.

caso não esteja com o comando make disponivel, você poderá usar o g++ so comandos:
g++ -Wall -std=c++11 -g -D DEBUG src/driver_list.cpp -I include -o exec, para executar em modo de depuração; e
g++ -Wall -std=c++11 src/driver_list.cpp -I include -o exec, para executar normalmente.

# Executar
Com o passo de compilação já realizado, você poderá executar o código com o comando ./exec no linux ou exec no windows.

# Implementação:


# Distribuição de pastas e arquivos

pasta doc: ficarão todos os arquivos de documentação gerados pelo Doxygen.

pasta src: ficarão os códigos-fonte do projeto em c++ que conterá um arquivo:

driver_list.cpp: arquivo responsável pela implementação do código do cliente.
pasta bin: ficarão os executáveis gerados pelo Makefile (Essa pasta é criada após usar o comando make).

pasta build: ficarão os arquivos de código objeto gerados pelo Makefile (Essa pasta é criada após usar o comando make).

pasta include: ficarão os dois arquivos que contém a implementação do list, que são:

list.h: armazena todas as assinaturas e definições que serão usadas pela nossa TAD.

list.inl: arquivo que implementa tudo que está descrito no list.h.

arquivo exec: link simbólico para executável gerado pelo comando make.

arquivo Makefile: arquivo usado pelo comando make para gerar o arquivo binário do projeto.

# Documentação
Acesse a [documentação](https://pabloufrn.github.io/list/html/index.html) sem precisar baixar.

# Authorship
Program developed by Henrique David de Medeiros (henriquemed101@gmail.com) and Pablo Emanuell L. Targino (pabloemanuell@academico.ufrn.br).
