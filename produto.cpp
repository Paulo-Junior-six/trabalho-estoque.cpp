#include "Produto.h"

Produto::Produto(int id, const std::string& nome, int quantidade, double preco)
    : id(id), nome(nome), quantidade(quantidade), preco(preco) {}

int Produto::getId() const { return id; }
std::string Produto::getNome() const { return nome; }
int Produto::getQuantidade() const { return quantidade; }
double Produto::getPreco() const { return preco; }

void Produto::adicionarEstoque(int qtd) {
    quantidade += qtd;
}

void Produto::removerEstoque(int qtd) {
    if (qtd <= quantidade) {
        quantidade -= qtd;
    } else {
        std::cout << "Quantidade insuficiente no estoque!\n";
    }
}

void Produto::exibirDetalhes() const {
    std::cout << std::setw(5) << id << std::setw(15) << nome
              << std::setw(10) << quantidade << std::setw(10) << preco << "\n";
}