#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
#include <iostream>
#include <iomanip>

class Produto {
private:
    int id;
    std::string nome;
    int quantidade;
    double preco;

public:
    Produto(int id, const std::string& nome, int quantidade, double preco);

    int getId() const;
    std::string getNome() const;
    int getQuantidade() const;
    double getPreco() const;

    void adicionarEstoque(int quantidade);
    void removerEstoque(int quantidade);
    void exibirDetalhes() const;
};

#endif