#include "Estoque.h"

void Estoque::adicionarProduto(const Produto& produto) {
    produtos.push_back(produto);
}

void Estoque::listarProdutos() const {
    std::cout << std::setw(5) << "ID" << std::setw(15) << "Nome"
              << std::setw(10) << "Qtd" << std::setw(10) << "Preco\n";
    std::cout << "---------------------------------------------\n";
    for (const auto& produto : produtos) {
        produto.exibirDetalhes();
    }
}

Produto* Estoque::buscarProduto(int id) {
    for (auto& produto : produtos) {
        if (produto.getId() == id)
            return &produto;
    }
    return nullptr;
}

bool Estoque::removerProduto(int id) {
    for (auto it = produtos.begin(); it != produtos.end(); ++it) {
        if (it->getId() == id) {
            produtos.erase(it);
            return true;
        }
    }
    return false;
}

void Estoque::adicionarFuncionario(const Funcionario& funcionario) {
    funcionarios.push_back(funcionario);
}

void Estoque::removerFuncionario(int id) {
    for (auto it = funcionarios.begin(); it != funcionarios.end(); ++it) {
        if (it->getId() == id) {
            funcionarios.erase(it);
            std::cout << "Funcionario removido com sucesso.\n";
            return;
        }
    }
    std::cout << "Funcionario nao encontrado!\n";
}

void Estoque::listarFuncionarios() const {
    std::cout << "\nLista de Funcionarios:\n";
    for (const auto& funcionario : funcionarios) {
        funcionario.exibirDetalhes();
    }
}

Funcionario* Estoque::buscarFuncionario(int id) {
    for (auto& funcionario : funcionarios) {
        if (funcionario.getId() == id)
            return &funcionario;
    }
    return nullptr;
}
bool Estoque::idProdutoExiste(int id) const {
    for (const auto& produto : produtos) {
        if (produto.getId() == id) {
            return true;
        }
    }
    return false;
}

bool Estoque::idFuncionarioExiste(int id) const {
    for (const auto& funcionario : funcionarios) {
        if (funcionario.getId() == id) {
            return true;
        }
    }
    return false;
}