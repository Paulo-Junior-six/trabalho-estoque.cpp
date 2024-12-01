#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <vector>
#include "Produto.h"
#include "Funcionario.h"

class Estoque {
private:
    std::vector<Produto> produtos;
    std::vector<Funcionario> funcionarios;

public:
    void adicionarProduto(const Produto& produto);
    void listarProdutos() const;
    Produto* buscarProduto(int id);
    bool removerProduto(int id);
    bool idProdutoExiste(int id) const;



    void adicionarFuncionario(const Funcionario& funcionario);
    void removerFuncionario(int id);
    void listarFuncionarios() const;
    bool idFuncionarioExiste(int id) const;
    Funcionario* buscarFuncionario(int id);
};

#endif