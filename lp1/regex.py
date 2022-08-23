import re
from turtle import home

number1 = "(81)99999-9999"
number2 = "99999-9999"


def validatePhoneNumber(number):
    # Checar primeiro se a string tem o tamanho correto [14]
    if len(number) != 14:
        print("não tem o tamanho correto")
        return False

    # Checar se os 4 primeiros caracteres é o DDD entre parênteses
    for i in range(1, 3):
        if not number[i].isdecimal():
            print("o ddd contém um nan")
            return False
    if number[0] != "(" or number[3] != ")":
        print("não existe o parenteses ao redor do ddd")
        return False

    # Checar se existem 5 números após o ddd
    for i in range(4, 9):
        if not number[i].isdecimal():
            print("não existem 5 números após o ddd")
            return False

    # Checar se existe um - separando o número
    if number[9] != "-":
        print("não existe o - separando o número")
        return False

    # Checar se existem 4 números após o -
    for i in range(10, 14):
        if not number[i].isdecimal():
            print("não existem 4 números após o -")
            return False

    return True


def validatePhoneNumberRegex(number):
    phonePatern = re.compile(r"(\d\d\d\d\d)-(\d\d\d\d)")
    numbers = phonePatern.search(
        "Ligue para mim no número 99999-1010 amanhã. O número 99999-9999 é do meu escritório"
    )
    print(f"Telefone encontrado: {numbers.groups()}")


def orRegex():
    comRegex = re.compile(r"com(prado|patriota|promisso)")
    objetoCasado = comRegex.search("Tenho um compromisso logo mais")
    print(objetoCasado.group())


def opcionalRegex():
    comRegex = re.compile(r"compro(misso)?")
    objetoCasado = comRegex.search("Tenho um compromisso logo mais")
    objetoCasado1 = comRegex.search("Não sei que roupa eu compro")
    print(objetoCasado.group())
    print(objetoCasado1.group())


def fechoKleene():
    # fecho kleene padrão * retorna se existir nenhuma ou várias
    # fecho positivo + retorna apenas se existir pelo menos um
    # sendo r'refrão:(la){n} retorna a partir do limite n
    # sendo r'refrão:(la){n},{m} ele retorna se estiver entre n e m, retornando o limite superior
    musicaRegex = re.compile(r"refrão:(la)*")
    objetoCasado = musicaRegex.search(
        "Deve estar em todo refrão: a parte mais chiclete da música"
    )
    objetoCasado1 = musicaRegex.search(
        "Toda música do Jota Quest tem o refrão:lalalalala"
    )
    objetoCasado2 = musicaRegex.search("Ou o refrão:lalalalalala ouou")
    print(objetoCasado.group())
    print(objetoCasado1.group())
    print(objetoCasado2.group())


def encontrandoTodasAsOcorrencias():
    phonePatern = re.compile(r"(\d\d\d\d\d)-(\d\d\d\d)")
    mo = phonePatern.findall(
        "Ligue para mim no número 99999-1010 amanhã. O número 99999-9999 é do meu escritório"
    )
    print(f"Telefone encontrado: {mo}")


# Classe comum de caracteres \d \w \s \D \W \S
# \d - dígito | \D - tudo que não é digito
# \w - letra  | \W - tudo que não é letra
# \s - espaço | \S - tudo que não é um espaço


def betterRegex():
    feiraRegex = re.compile(r"\d+\s\w+")
    lista = feiraRegex.findall("12 bananas, 5 mangas, 3 abacaxis, 2 prea e 1 peba")
    print(lista)


# classes personalizadas [], com intervalos [-] e negativas [^]
def classespersonalizadas():
    regex = re.compile(r"[0-5a-zA-Z]")
    lista = regex.findall(
        "Ligue para mim no número 99999-1010 amanhã. O número 99999-9999 é do meu escritório"
    )
    print(lista)


# caracteres . ^ e $

### re.DOTALL == * ; re.IGNORECASE == para ignorar case sensitive / ;
### re.I e re.VERBOSE == para dividir um pattern em diversas linhas ;


def regexPhone():
    regex = re.compile(r"\(\d{2}\)\d{5}-\d{4}")
    mo = regex.findall(
        "Ligue para mim no número (81)99999-1010 amanhã. O número (81)99999-9999 é do meu escritório"
    )
    print(mo)


def regexPhoneChallenge():
    regex = re.compile(r"\(?\d{2}\)?\d{5}-\d{4}")
    mo = regex.findall(
        "Ligue para mim no número (81)99999-1010 amanhã. O número (81)99999-9999 é do meu escritório"
    )
    print(mo)


regexPhoneChallenge()
