#include <iostream>
#include "Estoque.h"

void menu() {
    Estoque estoque;

    estoque.adicionarProduto(Produto(1, "Camiseta", 50, 25.99));
    estoque.adicionarProduto(Produto(2, "Calca", 30, 99.90));
    estoque.adicionarProduto(Produto(3, "Tenis", 20, 249.90));

    estoque.adicionarFuncionario(Funcionario(1, "Jonatan", "Gerente"));
    estoque.adicionarFuncionario(Funcionario(2, "Patricia", "Caixa"));

    int opcao;
    do {
        std::cout << "\n========== Menu ==========\n";
        std::cout << "1. Listar produtos\n";
        std::cout << "2. Adicionar estoque\n";
        std::cout << "3. Remover estoque\n";
        std::cout << "4. Adicionar produto\n";
        std::cout << "5. Remover produto\n";
        std::cout << "6. Listar funcionarios\n";
        std::cout << "7. Adicionar funcionario\n";
        std::cout << "8. Remover funcionario\n";
        std::cout << "9. Registrar entrada de funcionario\n";
        std::cout << "10. Sair\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                estoque.listarProdutos();
                break;
            case 2: {
                int id, qtd;
                std::cout << "Digite o ID do produto: ";
                std::cin >> id;
                Produto* produto = estoque.buscarProduto(id);
                if (produto) {
                    std::cout << "Digite a quantidade para adicionar: ";
                    std::cin >> qtd;
                    produto->adicionarEstoque(qtd);
                    std::cout << "Estoque atualizado com sucesso!\n";
                } else {
                    std::cout << "Produto nao encontrado!\n";
                }
                break;
            }
            case 3: {
                int id, qtd;
                std::cout << "Digite o ID do produto: ";
                std::cin >> id;
                Produto* produto = estoque.buscarProduto(id);
                if (produto) {
                    std::cout << "Digite a quantidade para remover: ";
                    std::cin >> qtd;
                    produto->removerEstoque(qtd);
                    std::cout << "Estoque atualizado com sucesso!\n";
                } else {
                    std::cout << "Produto nao encontrado!\n";
                }
                break;
            }
            case 4: {
                int id, quantidade;
                std::string nome;
                double preco;
                std::cout << "Digite o ID do novo produto: ";
                std::cin >> id;
                if (estoque.idProdutoExiste(id)) {
                    std::cout << "Erro: Produto com o ID " << id << " ja existe!\n";
                    break;
                }
                std::cin.ignore();
                std::cout << "Digite o nome do produto: ";
                std::getline(std::cin, nome);
                std::cout << "Digite a quantidade inicial: ";
                std::cin >> quantidade;
                std::cout << "Digite o preco do produto: ";
                std::cin >> preco;
                Produto novoProduto(id, nome, quantidade, preco);
                estoque.adicionarProduto(novoProduto);
                std::cout << "Produto adicionado com sucesso!\n";
                break;
            }
            case 5: {
                int id;
                std::cout << "Digite o ID do produto a ser removido: ";
                std::cin >> id;

                if (estoque.removerProduto(id)) {
                    std::cout << "Produto removido com sucesso!\n";
                } else {
                    std::cout << "Produto nao encontrado!\n";
                }
                break;
            }
            case 6:
                estoque.listarFuncionarios();
                break;
            case 7: {
                int id;
                std::string nome, funcao;

                std::cout << "Digite o ID do funcionario: ";
                std::cin >> id;
                if (estoque.idFuncionarioExiste(id)) {
                    std::cout << "Erro: Funcionario com o ID " << id << " ja existe!\n";
                    break;
                }

                std::cin.ignore();
                std::cout << "Digite o nome do funcionario: ";
                std::getline(std::cin, nome);
                std::cout << "Digite a funcao do funcionario: ";
                std::getline(std::cin, funcao);

                Funcionario novoFuncionario(id, nome, funcao);
                estoque.adicionarFuncionario(novoFuncionario);
                std::cout << "Funcionario adicionado com sucesso.\n";
                break;
            }
            case 8: {
                int id;
                std::cout << "Digite o ID do funcionario a ser removido: ";
                std::cin >> id;
                estoque.removerFuncionario(id);
                break;
            }
            case 9: {
                int id;
                std::cout << "Digite o ID do funcionario: ";
                std::cin >> id;
                Funcionario* funcionario = estoque.buscarFuncionario(id);
                if (funcionario) {
                    funcionario->registrarEntrada();
                } else {
                    std::cout << "Funcionario nao encontrado!\n";
                }
                break;
            }
            case 10:
                std::cout << "Saindo do sistema...\n";
                break;
            default:
                std::cout << "Opcao invalida! Tente novamente.\n";
                break;
        }
    } while (opcao != 10);
}

int main() {
    menu();
    return 0;
}