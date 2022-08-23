def empty(aux):
    if aux == {}:
        return True
    else:
        return False


# def insertTree(aux, val):


def notacaoInfixada(aux):
    if not empty(aux):
        notacaoInfixada(aux["left"])
        print(aux["val"], end="")
        notacaoInfixada(aux["right"])


def notacaoPrefixada(aux):
    if not empty(aux):
        print(aux["val"], end="")
        notacaoPrefixada(aux["left"])
        notacaoPrefixada(aux["right"])


tree = {
    "val": "-",
    "left": {"val": 9, "left": {}, "right": {}},
    "right": {
        "val": 5,
        "left": {},
        "right": {"val": "+", "left": {}, "right": {"val": 2, "left": {}, "right": {}}},
    },
}


notacaoInfixada(tree)
print()
notacaoPrefixada(tree)
print()
