from typing import Dict


pedidos = []


def novoPedido():
    nome_pedido = input("Digite o seu pedido: ")
    try:
        numero = pedidos[-1].get("numero") + 1
    except IndexError:
        numero = 1
    pedido = {"numero": numero, "prato": nome_pedido}
    pedidos.append(pedido)
    return pedidos


def entregarPedido():
    pedido = pedidos[0]
    pedidos.pop(0)
    return pedido


def listarPedidos():
    for pedido in pedidos:
        print(pedido)


def menu():
    print("""
    1 - Novo pedido
    2 - Entregar pedido
    3 - Sair
    """)
    op = input("Digite a opção desejada: ")
    while op != "4":
        match(op):
            case "1":
                novoPedido()
            case "2":
                entregarPedido()
            case "3":
                listarPedidos()
            case _:
                print("Opção inválida")
        op = input("Digite a opção desejada: ")

menu()