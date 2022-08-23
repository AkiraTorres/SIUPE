def validateInt(valor):
    try:
        valor = int(valor)
        return valor
    except ValueError:
        print("Só é válido números inteiros")


def criarPilha():
    pilha = []
    return pilha


def adicionarValor(valor, pilha):
    pilha.append(valor)
    print("Valor adicionado: ", valor)
    return True


def removerValor(pilha):
    valor = pilha[-1]
    pilha.pop(-1)
    print("Valor removido: ", valor)
    return valor


pilha1 = criarPilha()
adicionarValor(1, pilha1)
adicionarValor(12, pilha1)
adicionarValor(37, pilha1)

print(pilha1)

removerValor(pilha1)
print(pilha1)
