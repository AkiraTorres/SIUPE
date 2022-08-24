#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Music {
    char title[30];
    char artist[30];
    char album[30];
    char bug[30];
    struct Music* next;
};

struct Action {
    int action;
    int position;
    struct Music* music;
    struct Action* next;
    struct Action* previous;
};

struct Music* newMusic();
void listPlaylist(struct Music** headPointer);
void getMusicFromPosition(struct Music** headPointer, int position);
int getPlaylistSize(struct Music** headPointer);
int isInPlaylist(struct Music** headPointer, char* searchString);
void pressToContinue();

void addMusic(struct Music** headPointer, struct Action** actionTailPointer);
void removeMusic(struct Music** headPointer, struct Action** actionTailPointer);

void addInBegging(struct Music* newMusic, struct Music** headPointer);
void addInEnding(struct Music* newMusic, struct Music** headPointer);
void addInPosition(struct Music* newMusic, struct Music** headPointer, int position);

struct Music* removeFromBegging(struct Music** headPointer);
struct Music* removeFromEnding(struct Music** headPointer);
struct Music* removeFromPosition(struct Music** headPointer, int position);

struct Action* newAction(int action, int position, struct Music* music);
void registerLastAction(struct Action** actionsTailPointer, struct Action* newAction);
void undoLastAction(struct Action** actionsTailPointer, struct Music** headPointer);

int main() {
    struct Music* headPointer = NULL;
    struct Action* actionTailPointer = NULL;

    int opt = -1;

    while (opt != 0) {
        printf("Qual operação você deseja realizar?\n1- Listar a playlist.\n");
        printf("2- Adicionar música na playlist.\n3- Remover música da playlist.\n");
        printf("4- Recuperar música a partir da posição na lista.\n5- Calcular tamanho da playlist.\n");
        printf("6- Buscar música na playlist.\n7- Apagar playlist.\n");
        printf("8- Refazer última ação.\n");
        printf("0- Para encerrar o programa.\n--- ");
        scanf("%i", &opt);
        switch (opt) {
            case 1: {
                system("clear");
                listPlaylist(&headPointer);
                pressToContinue();
                break;
            }
            case 2: {
                system("clear");
                addMusic(&headPointer, &actionTailPointer);
                pressToContinue();
                break;
            }
            case 3: {
                system("clear");
                removeMusic(&headPointer, &actionTailPointer);
                pressToContinue();
                break;
            }
            case 4: {
                system("clear");
                printf("Digite a posição na playlist que você deseja recuperar a música: ");
                int position;
                scanf("%i", &position);
                getMusicFromPosition(&headPointer, position);
                pressToContinue();
                break;
            }
            case 5: {
                system("clear");
                int playlistSize = getPlaylistSize(&headPointer);
                printf("O tamanho da playlist é de %i música(s).\n", playlistSize);
                pressToContinue();
                break;
            }
            case 6: {
                system("clear");
                while (getchar() != '\n')
                    ;
                char searchString[30];
                printf("Digite o nome da música que você deseja procurar: ");
                fgets(searchString, 30, stdin);
                searchString[strcspn(searchString, "\n")] = 0;
                isInPlaylist(&headPointer, searchString);
                pressToContinue();
                break;
            }
            case 8: {
                system("clear");
                while (getchar() != '\n')
                    ;
                undoLastAction(&actionTailPointer, &headPointer);
                pressToContinue();
                break;
            }
            case 0: {
                system("clear");
                break;
            }
            default: {
                printf("Opção inválida.\n");
                pressToContinue();
                break;
            }
        }
    }

    return 0;
}

struct Music* newMusic() {
    struct Music* music = malloc(sizeof(struct Music));

    while (getchar() != '\n')
        ;

    if (music != NULL) {
        printf("Digite o nome da musica: ");
        fgets(music->title, 30, stdin);
        music->title[strcspn(music->title, "\n")] = 0;

        printf("Digite o nome do artista: ");
        fgets(music->artist, 30, stdin);
        music->artist[strcspn(music->artist, "\n")] = 0;

        printf("Digite o nome do album: ");
        fgets(music->album, 30, stdin);
        music->album[strcspn(music->album, "\n")] = 0;

        music->next = NULL;
    }
    return music;
}

void listPlaylist(struct Music** headPointer) {
    while (getchar() != '\n')
        ;

    if (*headPointer != NULL) {
        struct Music* currentMusic = NULL;
        currentMusic = *headPointer;

        while (currentMusic != NULL) {
            printf("Música: %s | Artista: %s | Álbum: %s\n", currentMusic->title, currentMusic->artist, currentMusic->album);
            currentMusic = currentMusic->next;
        }
    } else {
        printf("A playlist está vazia!\n");
    }
}

void getMusicFromPosition(struct Music** headPointer, int position) {
    if (*headPointer != NULL) {
        int playlistSize = getPlaylistSize(headPointer);
        if (playlistSize >= position) {
            int counter = 0;
            struct Music* currentMusic = NULL;
            currentMusic = *headPointer;

            while (currentMusic != NULL) {
                if (counter == position) {
                    printf("Música: %s | Artista: %s | Álbum: %s\n",
                           currentMusic->title, currentMusic->artist,
                           currentMusic->album);
                    return;
                }
                counter++;
                currentMusic = currentMusic->next;
            }

        } else {
            printf("A posição passada (%i) é maior do que o tamanho total da playlist (%i).\n", position, playlistSize);
        }
    } else {
        printf("A playlist está vazia!\n");
    }
}

int getPlaylistSize(struct Music** headPointer) {
    if (*headPointer != NULL) {
        int counter = 0;
        struct Music* currentMusic = NULL;
        currentMusic = *headPointer;

        while (currentMusic != NULL) {
            counter++;
            currentMusic = currentMusic->next;
        }
        return counter;
    } else {
        printf("A playlist está vazia!\n");
        return 0;
    }
}

int isInPlaylist(struct Music** headPointer, char* searchString) {
    struct Music* currentMusic = NULL;
    struct Music* previousMusic = NULL;
    currentMusic = *headPointer;

    if (*headPointer != NULL) {
        while (strcasestr(currentMusic->title, searchString) != NULL) {
            if (currentMusic->next == NULL) {
                printf("A música não está presente na playlist.\n");
            } else {
                previousMusic = currentMusic;
                currentMusic = currentMusic->next;
            }
        }
        printf("Música: %s | Artista: %s | Álbum: %s\n", previousMusic->title, previousMusic->artist, previousMusic->album);
    } else {
        printf("A playlist está vazia.\n");
    }
}

void pressToContinue() {
    printf("Aperte ENTER para continuar.\n");
    getchar();
    system("clear");
}

void addMusic(struct Music** headPointer, struct Action** actionTailPointer) {
    int opt = -1;

    printf("Onde você deseja adicionar a música?\n1- Adicionar no começo.\n");
    printf("2- Adicionar em uma posição.\n3- Adicionar no final.\n--- ");

    scanf("%i", &opt);

    struct Music* music = newMusic();
    struct Action* action = NULL;

    switch (opt) {
        case 1: {
            addInBegging(music, headPointer);
            action = newAction(1, 0, music);
            registerLastAction(actionTailPointer, action);
            break;
        }
        case 2: {
            printf("Digite a posição na playlist em que você deseja adicionar a música: ");
            int position;
            scanf("%i", &position);
            addInPosition(music, headPointer, position);
            registerLastAction(actionTailPointer, newAction(1, position, music));
            break;
        }
        case 3: {
            addInEnding(music, headPointer);
            action = newAction(1, -1, music);
            registerLastAction(actionTailPointer, action);
            break;
        }
        default: {
            printf("Opção inválida.\n");
            break;
        }
    }
    system("clear");
}

void removeMusic(struct Music** headPointer, struct Action** actionTailPointer) {
    int opt = -1;

    printf("De onde você deseja remover a música?\n1- Remover do começo.\n");
    printf("2- Remover em uma posição.\n3- Remover do final.\n--- ");

    scanf("%i", &opt);

    struct Music* removedMusic = NULL;

    switch (opt) {
        case 1: {
            removedMusic = removeFromBegging(headPointer);
            struct Action* action = newAction(2, 0, removedMusic);
            registerLastAction(actionTailPointer, action);
            break;
        }
        case 2: {
            printf("Digite a posição da playlist da qual você deseja remover a música: ");
            int position;
            scanf("%i", &position);
            removedMusic = removeFromPosition(headPointer, position);
            struct Action* action = newAction(2, position, removedMusic);
            registerLastAction(actionTailPointer, action);
            break;
        }
        case 3: {
            removedMusic = removeFromEnding(headPointer);
            struct Action* action = newAction(2, -1, removedMusic);
            registerLastAction(actionTailPointer, action);
            break;
        }
        default: {
            printf("Opção inválida.\n");
            break;
        }
    }
    system("clear");
}

void addInBegging(struct Music* newMusic, struct Music** headPointer) {
    struct Music* currentFirstMusic = NULL;
    currentFirstMusic = *headPointer;

    if (*headPointer == NULL) {
        *headPointer = newMusic;
    } else {
        newMusic->next = currentFirstMusic;
        *headPointer = newMusic;
    }
}

void addInEnding(struct Music* newMusic, struct Music** headPointer) {
    struct Music* currentMusic = NULL;
    currentMusic = *headPointer;

    if (*headPointer == NULL) {
        *headPointer = newMusic;
    } else {
        while (currentMusic->next != NULL) {
            currentMusic = currentMusic->next;
        }

        currentMusic->next = newMusic;
    }
}

void addInPosition(struct Music* newMusic, struct Music** headPointer, int position) {
    struct Music* currentMusic = NULL;
    currentMusic = *headPointer;

    if (*headPointer == NULL) {
        *headPointer = newMusic;
    } else {
        int playlistSize = getPlaylistSize(headPointer);
        if (playlistSize >= position) {
            struct Music* currentMusic = NULL;
            struct Music* previousMusic = NULL;
            currentMusic = *headPointer;

            while (currentMusic != NULL) {
                for (int i = 0; i < position; i++) {
                    previousMusic = currentMusic;
                    currentMusic = currentMusic->next;
                }

                newMusic->next = currentMusic;
                previousMusic->next = newMusic;
                return;
            }

        } else {
            printf("A posição passada (%i) é maior do que o tamanho total da playlist (%i).\n", position, playlistSize);
        }
    }
}

struct Music* removeFromBegging(struct Music** headPointer) {
    struct Music* currentMusic = NULL;
    currentMusic = *headPointer;

    if (getPlaylistSize(headPointer) == 1) {
        *headPointer = NULL;
    } else if (*headPointer != NULL) {
        *headPointer = currentMusic->next;
        // free(currentMusic);
    } else {
        printf("A playlist está vazia.\n");
        return NULL;
    }
    return currentMusic;
}

struct Music* removeFromEnding(struct Music** headPointer) {
    struct Music* currentMusic = NULL;
    struct Music* previousMusic = NULL;
    currentMusic = *headPointer;

    if (getPlaylistSize(headPointer) == 1) {
        *headPointer = NULL;
    } else if (*headPointer != NULL) {
        while (currentMusic->next != NULL) {
            previousMusic = currentMusic;
            currentMusic = currentMusic->next;
        }

        previousMusic->next = NULL;
        // free(currentMusic);
    } else {
        printf("A playlist está vazia.\n");
        return NULL;
    }
    return currentMusic;
}

struct Music* removeFromPosition(struct Music** headPointer, int position) {
    struct Music* currentMusic = NULL;
    currentMusic = *headPointer;

    if (getPlaylistSize(headPointer) == 1) {
        *headPointer = NULL;
    } else if (*headPointer != NULL) {
        int playlistSize = getPlaylistSize(headPointer);
        if (playlistSize >= position) {
            struct Music* currentMusic = NULL;
            struct Music* previousMusic = NULL;
            currentMusic = *headPointer;

            for (int i = 0; i < position; i++) {
                previousMusic = currentMusic;
                currentMusic = currentMusic->next;
            }

            previousMusic->next = currentMusic->next;
            // free(currentMusic);

        } else {
            printf("A posição passada (%i) é maior do que o tamanho total da playlist (%i).\n", position, playlistSize);
            return NULL;
        }
    } else {
        printf("A playlist está vazia.\n");
        return;
    }
    return currentMusic;
}

// register the new action in a struct and return it
struct Action* newAction(int action, int position, struct Music* music) {
    struct Action* newActionRegistered = malloc(sizeof(struct Action));

    newActionRegistered->action = action;
    newActionRegistered->position = position;
    newActionRegistered->music = music;
    newActionRegistered->next = NULL;
    newActionRegistered->previous = NULL;

    return newActionRegistered;
}

// register the new actin to a stack
void registerLastAction(struct Action** actionsTailPointer, struct Action* newAction) {
    if (*actionsTailPointer == NULL) {
        *actionsTailPointer = newAction;
    } else {
        struct Action* lastAction = *actionsTailPointer;

        newAction->previous = lastAction;
        lastAction->next = newAction;
        *actionsTailPointer = newAction;
    }
}

// undo the last action in the actions stack and removes it from the stack
void undoLastAction(struct Action** actionsTailPointer, struct Music** headPointer) {
    if (*actionsTailPointer != NULL) {
        struct Action* lastAction = *actionsTailPointer;

        int position = lastAction->position;
        int action = lastAction->action;
        struct Music* music = lastAction->music;

        // action == 1 means it was a add function, action == 2 means a remove function
        if (position == 0) {
            action == 1 ? removeFromBegging(headPointer) : addInBegging(music, headPointer);
        } else if (position == -1) {
            action == 1 ? removeFromEnding(headPointer) : addInEnding(music, headPointer);
        } else {
            action == 1 ? removeFromPosition(headPointer, position) : addInPosition(music, headPointer, position);
        }

        if (action == 1) {
            free(music);
        }

        if (lastAction->previous != NULL) {
            struct Action* previousAction = lastAction->previous;
            *actionsTailPointer = lastAction->previous;
            previousAction->next = NULL;
        } else {
            *actionsTailPointer = NULL;
        }
        free(lastAction);
    } else {
        printf("Não existe nenhuma ação para desfazer!\n");
    }
}