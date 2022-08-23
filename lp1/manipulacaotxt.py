import os

"""
os.getcwd()
os.chdir('path')
os.makedirs('path')
os.removedirs('path')
os.path.basename('path')
os.path.dirname('path')
dirname + basename == absolute path
"""


# path = os.path.join("home", "akira", "Downloads", "aKIRAtORRES.ovpn")
# print(os.path.join(path))
# print(os.getcwd())
# print(os.chdir(path))
# print(os.path.dirname(path))


## manipulando arquivos txt
"""
ABRIR - MANIPULAR - FECHAR
leitura r
escrita w
modificacao a

open('path','modo')
read(n)
readline(n)
readlines(n)
close()
write()
writeLine()
writeLines()
append()
"""

arquivo = open("teste.txt", "a")
arquivo.append("desgraça")
conteudo = arquivo.read()
print(conteudo)
arquivo.close()
