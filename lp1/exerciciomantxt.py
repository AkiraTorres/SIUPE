import os


def newItem(param):
    itemName = input("Digite o nome do item a ser adicionado no carrinho: ")
    itemPrice = input("Digite o preço do item a ser adicionado no carrinho: ")
    
    car = open('carrinho.txt', param)
    car.write("Preço: " + itemPrice + "| Nome do item: " + itemName + "\n")
    car.close()
    

def listItens():
    car = open('carrinho.txt', 'r')
    print(car.read())
    car.close()


def main():
    n = "9"
    print("Você pode apertar a qualquer momento:")
    print("1- Para salvar um novo item no carrinho de compras.")
    print("2- Para listar o carrinho de compras.")
    print("3- Para deletar esse carrinho e salvar um item em um novo carrinho de compras.")
    print("4- Para fechar o programa.")

    while(n):
        n = (input("Digite uma opção [1, 2, 3, 4]: ")) 
        match(n):
            case "1":
                os.system("clear")
                newItem('a+')
            case "2":
                os.system("clear")
                listItens()
            case "3":
                os.system("clear")
                newItem('w+')
            case "4":
                n = False
            case _:
                print("Digite uma opção válida.")


main()