# Conversor de Bases

Projeto desenvolvido em C++ para conversão entre diferentes sistemas numéricos:

- Binário
- Decimal
- Octal
- Hexadecimal

## Funcionalidades

O programa realiza conversões entre diferentes bases numéricas utilizando funções separadas em múltiplos arquivos.

## Estrutura do Projeto

```bash
.
├── main.cpp
├── conversoes/
│   ├── BinarioDecimal.cpp
│   ├── BinarioDecimal.h
│   ├── BinarioOctal.cpp
│   ├── BinarioOctal.h
│   ├── BinarioHexadecimal.cpp
│   └── BinarioHexadecimal.h
└── README.md
```

## Como executar

### Linux / Git Bash

Compile o projeto:

```bash
g++ main.cpp conversoes/*.cpp -o programa
```

Execute:

```bash
./programa
```

### Windows (MinGW)

Compile:

```bash
g++ main.cpp conversoes/*.cpp -o programa.exe
```

Execute:

```bash
programa.exe
```

## Tecnologias utilizadas

- Linguagem C++
- Programação modular
- Arquivos `.h` e `.cpp`

## Objetivo

Praticar:

- modularização
- separação de responsabilidades
- organização de projetos em C++
- conversão entre bases numéricas

## Autores

Pedro Duarte e Kaick