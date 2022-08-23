def vazio(aux):
    if aux == {}:
        return True
    else:
        return False


def inserirArvore(aux, num):
    if vazio(aux):
        aux = {"num": num, "esq": {}, "dir": {}}
    elif num < aux["num"]:
        aux["esq"] = inserirArvore(aux["esq"], num)
    elif num > aux["num"]:
        aux["dir"] = inserirArvore(aux["dir"], num)
    return aux


def mostrarEmOrdem(aux):
    if not vazio(aux):
        mostrarEmOrdem(aux["esq"])
        print(aux["num"], end=" ")
        mostrarEmOrdem(aux["dir"])


def mostrarPreOrdem(aux):
    if not vazio(aux):
        print(aux["num"], end=" ")
        mostrarPreOrdem(aux["esq"])
        mostrarPreOrdem(aux["dir"])


def mostrarPosOrdem(aux):
    if not vazio(aux):
        mostrarPosOrdem(aux["esq"])
        mostrarPosOrdem(aux["dir"])
        print(aux["num"], end=" ")


def mostrarPares(aux):
    if not vazio(aux):
        mostrarPares(aux["esq"])
        if aux["num"] % 2 == 0:
            print(aux["num"], end="")
        mostrarPares(aux["dir"])


def esvaziarArvore(aux):
    return {}


def menu():
    raiz = {}
    opt = -1

    print("MENU DE OPÇÕES - ÁRVORE BINÁRIA")
    print("1 - Inserir número")
    print("2 - Consultar números pares")
    print("3 - Consultar toda a árvore em ordem")
    print("4 - Consultar toda a árvore em pré-ordem")
    print("5 - Consultar toda a árvore em pós-ordem")
    print("7 - Esvaziar a árvore")
    print("0 - Sair")

    while opt != 0:
        opt = int(input("Digite a sua opção: "))
        if 1 < opt > 7:
            print("Opção inválida")
        elif opt == 1:
            raiz = inserirArvore(raiz, int(input()))
        elif opt == 2:
            if vazio(raiz):
                print("Árvore Vazia")
            else:
                mostrarPares(raiz)
                print()
        elif opt == 3:
            if vazio(raiz):
                print("Árvore Vazia")
            else:
                mostrarEmOrdem(raiz)
                print()
        elif opt == 4:
            if vazio(raiz):
                print("Árvore Vazia")
            else:
                mostrarPreOrdem(raiz)
                print()
        elif opt == 5:
            if vazio(raiz):
                print("Árvore Vazia")
            else:
                mostrarPosOrdem(raiz)
                print()
        elif opt == 7:
            if vazio(raiz):
                print("Árvore Vazia")
            else:
                raiz = esvaziarArvore(raiz)


menu()
