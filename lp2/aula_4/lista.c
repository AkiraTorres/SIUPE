// Importa as bibliotecas
#include <stdio.h>
#include <stdlib.h>

// Funções de utilidade
int listSize(int* flagPointer, int* arr);
void printList(int* flagPointer, int* arr);
int* resetList(int* flagPointer, int* arr);
int inputValidate(int input, int* validOptions);
int* resizeArray(int* arr, int arraySize);

// Funções dos sub-menus de adição e remoção
int* addNumber(int* flagPointer, int* arr);
int* remNumber(int* flagPointer, int* arr);

// Funções para adicionar números na lista
int* addInBeginning(int* flagPointer, int num, int* arr);
int* addInEnding(int* flagPointer, int num);
int* addInPosition(int* flagPointer, int num, int* arr, int position);

// Funções para remover números na lista
int* removeInBeginning(int* flagPointer, int* arr);
int* removeInEnding(int* flagPointer);
int* removeInPosition(int* flagPointer, int* arr, int position);

int main() {
  // inicialização das variáveis
  int opt = -1, arraySize = 0, *arr, *flagPointer, *tempArr;

  printf("Digite o tamanho desejado para o array: ");
  scanf("%i", &arraySize);

  arr = calloc(arraySize, sizeof(int));
  flagPointer = arr;

  while (opt != 0) {
    // validação para conferir se o vetor está cheio, se sim, chama a função
    // para redirecionamento do array
    if (arr[arraySize] == *flagPointer) {
      tempArr = arr;
      arr = resizeArray(tempArr, arraySize);
      free(tempArr);
      arraySize *= 2;
    }

    printf("Digite:\n1- Para imprimir a lista.\n");
    printf("2- Para adicionar um número.\n");
    printf("3- Para remover um número.\n");
    printf("4- Para descartar a lista e iniciar uma nova.\n");
    printf("0- Para encerrar a execução do programa.\n--- ");

    // faz a validação das entradas possíveis pro menu
    int validOptions[] = {0, 1, 2, 3, 4};
    opt = inputValidate(opt, validOptions);

    switch (opt) {
      case 1: {
        system("clear");
        printList(flagPointer, arr);
        break;
      }
      case 2: {
        system("clear");
        flagPointer = addNumber(arr, flagPointer);
        break;
      }
      case 3: {
        system("clear");
        if (listSize(flagPointer, arr) == 0) {
          printf("Lista vazia!\n");
        } else {
          flagPointer = remNumber(arr, flagPointer);
        }
        break;
      }
      case 4: {
        system("clear");
        flagPointer = resetList(flagPointer, arr);
        break;
      }
      case 0: {
        system("clear");
        return 0;
        break;
      }
      default: {
        printf("Opção inválida.");
      }
    }
  }
}

// submenu para chamar as funções para adicionar números na lista
int* addNumber(int* arr, int* flagPointer) {
  int opt = -1, num, position;
  printf(
      "Digite:\n1- Para adicionar um número no começo da lista.\n2- Para "
      "adicionar um número ao final da lista.\n");
  printf(
      "3- Para adicionar um número numa posição determinada.\n0- Para "
      "retornar ao menu anterior.\n--- ");

  int validOptions[] = {0, 1, 2, 3};
  opt = inputValidate(opt, validOptions);

  if (opt != 0) {
    system("clear");
    printf("Digite o número que você deseja adicionar na lista: ");
    scanf("%i", &num);
  }
  switch (opt) {
    case 1: {
      flagPointer = addInBeginning(flagPointer, num, arr);
      break;
    }
    case 2: {
      flagPointer = addInEnding(flagPointer, num);
      break;
    }
    case 3: {
      printf(
          "Agora digite a posição da lista na qual você deseja adicionar o "
          "número: ");
      scanf("%i", &position);
      flagPointer = addInPosition(flagPointer, num, arr, position);
      break;
    }
    case 0: {
      system("clear");
      return flagPointer;
      break;
    }
    default: {
      printf("Posição inválida.\n");
      break;
    }
  }

  system("clear");
  return flagPointer;
}

// submenu para chamar as funções para adicionar números na lista
int* remNumber(int* arr, int* flagPointer) {
  int opt = -1, num, position;
  printf(
      "Digite:\n1- Para remover um número no começo da lista.\n2- Para "
      "remover um número ao final da lista.\n");
  printf(
      "3- Para remover um número numa posição determinada.\n0- Para "
      "retornar ao menu anterior.\n--- ");

  int validOptions[] = {0, 1, 2, 3};
  opt = inputValidate(opt, validOptions);

  system("clear");
  switch (opt) {
    case 1: {
      flagPointer = removeInBeginning(flagPointer, arr);
      break;
    }
    case 2: {
      flagPointer = removeInEnding(flagPointer);
      break;
    }
    case 3: {
      printf(
          "Agora digite a posição da lista na qual você deseja remover o "
          "número: ");
      scanf("%i", &position);
      flagPointer = removeInPosition(flagPointer, arr, position);
      break;
    }
    case 0: {
      system("clear");
      return flagPointer;
      break;
    }
    default: {
      printf("Posição inválida.\n");
      break;
    }
  }

  system("clear");
  return flagPointer;
}

// adiciona o número passado como parâmetro no começo da lista
int* addInBeginning(int* flagPointer, int num, int* arr) {
  int i, n = listSize(arr, flagPointer);
  for (i = n; i > 0; i--) {
    arr[i] = arr[i - 1];
  }
  arr[0] = num;
  return flagPointer + 1;
}

// adiciona o número passado como parâmetro na posição também passada
int* addInPosition(int* flagPointer, int num, int* arr, int position) {
  int i, n = listSize(arr, flagPointer);
  for (i = n; i > position; i--) {
    arr[i] = arr[i - 1];
  }
  arr[position] = num;
  return flagPointer + 1;
}

// adiciona o número passado como parâmetro no final da lista
int* addInEnding(int* flagPointer, int num) {
  *flagPointer = num;
  return flagPointer + 1;
}

// remove o número passado como parâmetro do começo da lista
int* removeInBeginning(int* flagPointer, int* arr) {
  int i, n = listSize(arr, flagPointer);
  for (i = 0; i < n; i++) {
    arr[i] = arr[i + 1];
  }
  return flagPointer - 1;
}

// remove o número passado como parâmetro na posição também passada
int* removeInPosition(int* flagPointer, int* arr, int position) {
  int i, n = listSize(arr, flagPointer);
  for (i = position; i < n; i++) {
    arr[i] = arr[i + 1];
  }
  return flagPointer - 1;
}

// remove o número passado como parâmetro do final da lista
int* removeInEnding(int* flagPointer) {
  return flagPointer - 1;
}

// retorna o tamanho atual da lista, utilizando o flagPointer como flag do final
int listSize(int* flagPointer, int* arr) {
  int arraySize = sizeof(arr);
  for (int i = 0; i < arraySize; i++) {
    if (flagPointer == &arr[i]) {
      return i;
    }
  }
}

// imprime a lista
void printList(int* flagPointer, int* arr) {
  if (listSize(flagPointer, arr) == 0) {
    printf("Lista vazia!");
  } else {
    for (int i = 0; i < listSize(flagPointer, arr); i++) {
      printf("| %i ", arr[i]);
    }
  }
  printf("\n");
}

// reinicia a lista, anulando todas as posições e colocando o ponteiro de volta
// ao começo dela
int* resetList(int* flagPointer, int* arr) {
  for (int i = 0; i < listSize(flagPointer, arr); i++) {
    arr[i] == 0;
  }
  flagPointer = arr;
  return flagPointer;
}

// função para realizar a validação das entradas enviadas pelo usuário
// enquanto o input passado não estiver dentro do vetor validOptions o loop
// continuará sendo executado requerendo um novo input
int inputValidate(int input, int* validOptions) {
  scanf("%i", &input);
  for (;;) {
    for (int i = 0; i < sizeof(validOptions); i++) {
      if (validOptions[i] == input) {
        return input;
      }
    }
    printf("Opção inválida.\nDigite uma nova opção: ");
    scanf("%i", &input);
  }
}

// redimensiona o vetor, duplicando o seu tamanho e copiando todos os valores
// para esse novo vetor
int* resizeArray(int* arr, int arraySize) {
  int* newArr = calloc(arraySize * 2, sizeof(int));

  for (int i = 0; i < arraySize; i++) {
    newArr[i] = arr[i];
  }

  return newArr;
}
