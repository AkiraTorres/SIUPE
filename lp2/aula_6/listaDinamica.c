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

struct Music* newMusic();
void listPlaylist(struct Music** headPointer);
void getMusicFromPosition(struct Music** headPointer, int position);
int getPlaylistSize(struct Music** headPointer);
int isInPlaylist(struct Music** headPointer, char* searchString);
void pressToContinue();

void addMusic(struct Music** headPointer);
void removeMusic(struct Music** headPointer);

void addInBegging(struct Music* newMusic, struct Music** headPointer);
void addInEnding(struct Music* newMusic, struct Music** headPointer);
void addInPosition(struct Music* newMusic, struct Music** headPointer, int position);

void removeFromBegging(struct Music** headPointer);
void removeFromEnding(struct Music** headPointer);
void removeFromPosition(struct Music** headPointer, int position);

int main() {
    struct Music* headPointer = NULL;
    int opt = -1;

    while (opt != 0) {
        printf("Qual operação você deseja realizar?\n1- Listar a playlist.\n");
        printf("2- Adicionar música na playlist.\n3- Remover música da playlist.\n");
        printf("4- Recuperar música a partir da posição na lista.\n5- Calcular tamanho da playlist.\n");
        printf("6- Buscar música na playlist.\n7- Apagar playlist.\n");
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
                addMusic(&headPointer);
                pressToContinue();
                break;
            }
            case 3: {
                system("clear");
                removeMusic(&headPointer);
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

void addMusic(struct Music** headPointer) {
    int opt = -1;

    printf("Onde você deseja adicionar a música?\n1- Adicionar no começo.\n");
    printf("2- Adicionar em uma posição.\n3- Adicionar no final.\n--- ");

    scanf("%i", &opt);

    switch (opt) {
        case 1: {
            addInBegging(newMusic(), headPointer);
            break;
        }
        case 2: {
            printf("Digite a posição na playlist em que você deseja adicionar a música: ");
            int position;
            scanf("%i", &position);
            addInPosition(newMusic(), headPointer, position);
            break;
        }
        case 3: {
            addInEnding(newMusic(), headPointer);
            break;
        }
        default: {
            printf("Opção inválida.\n");
            break;
        }
    }
    system("clear");
}

void removeMusic(struct Music** headPointer) {
    int opt = -1;

    printf("De onde você deseja remover a música?\n1- Remover do começo.\n");
    printf("2- Remover em uma posição.\n3- Remover do final.\n--- ");

    scanf("%i", &opt);

    switch (opt) {
        case 1: {
            removeFromBegging(headPointer);
            break;
        }
        case 2: {
            printf("Digite a posição da playlist da qual você deseja remover a música: ");
            int position;
            scanf("%i", &position);
            removeFromPosition(headPointer, position);
            break;
        }
        case 3: {
            removeFromEnding(headPointer);
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

void removeFromBegging(struct Music** headPointer) {
    struct Music* currentMusic = NULL;
    currentMusic = *headPointer;

    if (*headPointer != NULL) {
        *headPointer = currentMusic->next;
        free(currentMusic);
    } else {
        printf("A playlist está vazia.\n");
    }
}

void removeFromEnding(struct Music** headPointer) {
    struct Music* currentMusic = NULL;
    struct Music* previousMusic = NULL;
    currentMusic = *headPointer;

    if (*headPointer != NULL) {
        while (currentMusic->next != NULL) {
            previousMusic = currentMusic;
            currentMusic = currentMusic->next;
        }

        previousMusic->next = NULL;
        free(currentMusic);
    } else {
        printf("A playlist está vazia.\n");
    }
}

void removeFromPosition(struct Music** headPointer, int position) {
    struct Music* currentMusic = NULL;
    currentMusic = *headPointer;

    if (*headPointer != NULL) {
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
            free(currentMusic);
            return;

        } else {
            printf("A posição passada (%i) é maior do que o tamanho total da playlist (%i).\n", position, playlistSize);
        }
    } else {
        printf("A playlist está vazia.\n");
    }
}