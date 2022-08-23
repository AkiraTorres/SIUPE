# Imports
import sys
from Lexical_Analyzer.analyzer import analyze


def main():
    print('ANALISADOR LÉXICO: ')
    print('\n(Insira o path absoluto do programa fonte)')

    absolute_path = input('>>> ')  # Get the path from the user

    status = analyze(absolute_path)  # Get the status of the analyser from path

    print('\n\n' + status[1]) 


if __name__ == "__main__":
    if len(sys.argv) > 1:
        status = analyze(sys.argv[1])
        print('\n\n' + status[1]) 
    else:
        main()