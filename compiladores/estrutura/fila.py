def validateInt(valor):
    try:
        valor = int(valor)
        return valor
    except ValueError:
        print("Só é válido números inteiros")


def criarFila():
    fila = []
    return fila


def adicionarValor(valor, fila):
    fila.append(valor)
    print("Valor adicionado: ", valor)
    return True


def removerValor(fila):
    valor = fila[0]
    fila.pop(0)
    print("Valor removido: ", valor)
    return valor


fila1 = criarFila()
adicionarValor(1, fila1)
adicionarValor(12, fila1)
adicionarValor(37, fila1)

print(fila1)

removerValor(fila1)
print(fila1)
