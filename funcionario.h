#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include <iostream>
#include <ctime>

class Funcionario {
private:
    int id;
    std::string nome;
    std::string funcao;
    std::string horarioEntrada;

public:
    Funcionario(int id, const std::string& nome, const std::string& funcao);

    int getId() const;
    std::string getNome() const;
    std::string getFuncao() const;
    std::string getHorarioEntrada() const;

    void registrarEntrada();
    void exibirDetalhes() const;
};

#endif