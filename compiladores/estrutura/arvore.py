def inserirNumero(aux, num):
    if aux == {}:
        aux = {"num": num, "esq": {}, "dir": {}}
    elif num < aux["num"]:
        aux["esq"] = inserirNumero(aux["esq"], num)
    elif num > aux["num"]:
        aux["dir"] = inserirNumero(aux["dir"], num)
    return aux






def main():
    opt = -1
    raiz = {}

    while opt != 0:
        opt = int(input())
        match(opt):
            case 1:
                raiz = inserirNumero(raiz, int(input()))
            case 2:
                print(raiz)
            

main()