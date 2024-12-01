#include "Funcionario.h"

Funcionario::Funcionario(int id, const std::string& nome, const std::string& funcao)
    : id(id), nome(nome), funcao(funcao), horarioEntrada("N/A") {}

int Funcionario::getId() const { return id; }
std::string Funcionario::getNome() const { return nome; }
std::string Funcionario::getFuncao() const { return funcao; }
std::string Funcionario::getHorarioEntrada() const { return horarioEntrada; }

void Funcionario::registrarEntrada() {
    time_t now = time(0);
    horarioEntrada = ctime(&now);
    if (!horarioEntrada.empty() && horarioEntrada.back() == '\n') {
        horarioEntrada.pop_back();
    }
    std::cout << "Horario de entrada registrado para " << nome << ": " << horarioEntrada << "\n";
}

void Funcionario::exibirDetalhes() const {
    std::cout << "ID: " << id << ", Nome: " << nome 
              << ", Funcao: " << funcao 
              << ", Ultima Entrada: " << horarioEntrada << "\n";
}